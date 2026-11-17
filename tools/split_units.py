#!/usr/bin/env python3
"""Split the address-named game and kaj units into the source files of config/layout.tsv.

  tools/split_units.py apply [--rev REV]   split src/{game,kaj}/<addr>.c into the files of the plan
  tools/split_units.py cite [--dry-run]    rewrite citations of old units in docs/, config/ and tools/
  tools/split_units.py docs                write docs/layout.md from config/layout.tsv

Ported from lsd-decomp. apply reads each old unit from src/<dir>/<addr>.c, or from git REV when the
file is gone (default 4efff08, the last commit with address units), so the split can be replayed.
Function addresses come from build/germs.elf: run it after a green `make check` of the address-unit
tree. It writes the new C files, rewrites the game and kaj entries of config/splat.yaml and removes
the old units. Then run `make split` twice (INCLUDE_ASM and INCLUDE_RODATA paths name the new files)
and `make check`.

Files are keyed by `dir/name` (game/event and kaj/event are two files). Each new file gets, in the
order of the old unit: its functions and INCLUDE_ASM lines (address range of the plan), its
INCLUDE_RODATA lines (rodata range of its splat entry), and every other declaration whose name its
code uses, directly or through another kept declaration. A `static inline` helper that emits nothing
counts as a declaration, so each file gets a copy of the helpers it calls. Declarations keep their
exact text: unprototyped forms and tentative gp definitions matter to the bytes.
"""
import argparse, os, re, subprocess, sys
from collections import OrderedDict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PLAN = os.path.join(ROOT, 'config/layout.tsv')
SPLAT = os.path.join(ROOT, 'config/splat.yaml')
ELF = os.path.join(ROOT, 'build/germs.elf')
NM = os.path.join(ROOT, 'tools/bin/mipsel-linux-gnu-nm')
SRC = os.path.join(ROOT, 'src')
ROM_BASE = 0x8016F800  # vram - rom offset of the main segment
DEFAULT_REV = '4efff08'

# .rodata entries after the split: rom offset -> file (dir/name). The Sony entries end the range of
# the file before them; RODATA_END (the start of .text) ends map.c. menu.c, npc.c and heap.c own no
# rodata. New cuts: building 0xB08, dialog 0xCF0, main 0x1268, shop 0x1848, town 0x2228, misc 0x34A8.
RODATA = OrderedDict([
    (0x800, 'game/action'), (0x93C, 'game/actor'), (0x9F4, 'game/ai'), (0xA50, 'game/block'),
    (0xB08, 'game/building'), (0xC1C, 'game/card'), (0xCF0, 'game/dialog'), (0xD04, 'game/door'),
    (0xD44, 'game/effect'), (0x1080, 'game/event'), (0x122C, 'game/mail'), (0x1268, 'game/main'),
    (0x1280, 'game/mod'), (0x1358, 'game/object'), (0x16DC, 'game/player'), (0x1820, 'game/roadmap'),
    (0x1848, 'game/shop'), (0x1EEC, 'game/sound'), (0x1FF4, 'game/sprite'), (0x21BC, 'game/thing'),
    (0x2228, 'game/town'), (0x2278, 'game/vehicle'), (0x2334, 'psyq/801AC9D0'), (0x3334, 'kaj/event'),
    (0x3374, 'kaj/kaj'), (0x3398, 'kaj/ll'), (0x34A8, 'kaj/misc'), (0x3588, 'psyq/801CD850'),
    (0x3688, 'kaj/tim'), (0x36D8, 'kaj/timer'), (0x3750, 'kaj/tod'), (0x3774, 'kaj/tss'),
    (0x3794, 'kaj/view'), (0x37D0, 'kaj/cdmgr'), (0x37F8, 'kaj/map'),
])
RODATA_START = 0x800
RODATA_END = 0x3854
# Comments of the c entries in config/splat.yaml: confidence, then the evidence in short (docs/layout.md).
TEXT_COMMENTS = {
    'game/action': 'start of .text; assert in action_load_set',
    'game/actor': 'no assert: jtbl cut (npc jump tables at 4 mod 8)',
    'game/ai': 'no assert: gp cut (ai_door_noise is lui before, gp from ai_find_target)',
    'game/block': 'block.c asserts; ends where block_area_flames stops being read through gp',
    'game/building': 'no assert: starts after block.c; card strings follow its jump table',
    'game/card': 'no assert: jtbl cut; its end is a guess',
    'game/dialog': 'no assert: a string after card.c\'s jump tables; its start is a guess',
    'game/door': 'door.c asserts; door_list through gp from door_refresh_all',
    'game/effect': 'effect.c asserts',
    'game/event': 'event.c asserts',
    'game/mail': 'mail.c asserts; its end is a guess',
    'game/main': 'main, a file only by its name',
    'game/menu': 'no assert: a normal function after main.c\'s deferred inline tail',
    'game/mod': 'mod.c asserts',
    'game/npc': 'no assert: a normal function after mod.c\'s deferred inline tail',
    'game/object': 'object.c asserts',
    'game/player': 'no assert: gp users of player_area_leave_pending and player_pick_trigger_hook',
    'game/roadmap': 'roadmap.c asserts',
    'game/shop': 'no assert: a normal function after roadmap.c\'s deferred inline tail',
    'game/sound': 'sound.c asserts',
    'game/sprite': 'sprite.c asserts',
    'game/thing': 'thing.c asserts; thing_list through gp from sprite_thing_refresh_all',
    'game/town': 'no assert: a string after thing.c\'s jump table; its end is a guess',
    'game/vehicle': 'vehicle.c asserts; its start is a guess',
    'kaj/event': 'Sony code on both sides; event.c asserts',
    'kaj/kaj': 'Sony code on both sides; kaj.c asserts',
    'kaj/ll': 'Sony code before; ll.c asserts',
    'kaj/misc': 'misc.c asserts; Sony code after',
    'kaj/tim': 'Sony code on both sides; tim.c asserts',
    'kaj/timer': 'Sony code on both sides; timer.c asserts',
    'kaj/tod': 'Sony code on both sides; no assert, TOD animation packets',
    'kaj/tss': 'Sony code before; tss.c asserts',
    'kaj/view': 'view.c asserts; Sony code after',
    'kaj/cdmgr': 'Sony code before; cdmgr.c asserts; its end is a guess',
    'kaj/heap': 'no assert: kaj_heap_unused_* are read only here',
    'kaj/map': 'no assert: a normal function after cdmgr.c\'s deferred inline tail; end of .text after',
}
SPLAT_HEAD_OLD = re.compile(r'# Text units: game/<addr>.*?so the bytes agree\)\.\n', re.S)
SPLAT_HEAD_NEW = """\
# Text units: game/<name> and kaj/<name> are the original source files, rebuilt from the evidence in
# docs/layout.md (config/layout.tsv, tools/split_units.py); psyq/<addr> are Sony library runs found by
# tools/psyq/match.py (asm, never decompiled). The kaj files (the developer's own library, assert strings
# kaj.c, ll.c, misc.c, tim.c, timer.c, tss.c, view.c, cdmgr.c) are linked among Sony's. Each c entry's
# comment gives the confidence of the file's boundaries and their evidence in short.
# Jtbl cuts: GCC 2.8.1 puts every jump table at .align 3 inside its object and the link keeps 4-byte
# alignment, so a jump table at 4 mod 8 from its file's .rodata start proves that a new object starts
# before it.
"""

KEYWORDS = set('''auto break case char const continue default do double else enum extern float for goto if
int long register return short signed sizeof static struct switch typedef union unsigned void volatile
while asm'''.split())


def read_plan():
    rows = []
    with open(PLAN) as f:
        head = f.readline().rstrip('\n').split('\t')
        for line in f:
            if line.strip():
                rows.append(dict(zip(head, line.rstrip('\n').split('\t'))))
    return rows


def file_rows(rows):
    """The game and kaj files of the plan (the Sony rows only name the runs between them)."""
    return [r for r in rows if r['FILE'].endswith('.c')]


# ---------------------------------------------------------------- C items

class Item:
    def __init__(self, kind, text, lead):
        self.kind = kind      # include, define, func, decl, rodata, comment
        self.text = text      # code text without leading comments
        self.lead = lead      # comments and blank lines before it (kept with it)
        self.names = set()    # names it declares
        self.uses = set()     # identifiers in its code
        self.func = None      # function name
        self.init = False     # initialized definition


# K&R definition head: name(a, b) followed by the parameter declarations
KR = re.compile(r'\w+\s*(\(\s*[A-Za-z_]\w*(?:\s*,\s*[A-Za-z_]\w*)*\s*\))\s*[A-Za-z_]')


def strip_code(text):
    """Remove comments, strings and char literals."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith('/*', i):
            j = text.index('*/', i + 2) + 2
            out.append(' '); i = j
        elif text.startswith('//', i):
            j = text.find('\n', i); j = n if j < 0 else j
            i = j
        elif c in '"\'':
            j = i + 1
            while text[j] != c:
                j += 2 if text[j] == '\\' else 1
            out.append(' 0 '); i = j + 1
        else:
            out.append(c); i += 1
    return ''.join(out)


def idents(code):
    return set(re.findall(r'[A-Za-z_]\w*', code)) - KEYWORDS


def drop_braces(code):
    out, depth = [], 0
    for c in code:
        if c == '{':
            depth += 1
            continue
        if c == '}':
            depth -= 1
            continue
        if depth == 0:
            out.append(c)
    return ''.join(out)


def top_split(code, sep):
    parts, depth, cur = [], 0, []
    for c in code:
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        if c == sep and depth == 0:
            parts.append(''.join(cur)); cur = []
        else:
            cur.append(c)
    parts.append(''.join(cur))
    return parts


def declared_names(code):
    """Names declared by one top-level declaration (code without comments)."""
    names = set()
    body = code.strip().rstrip(';')
    m = re.match(r'(typedef\s+)?(struct|union|enum)\s+(\w+)\s*\{', body)
    if m:
        names.add(m.group(3))
    if re.match(r'(typedef\s+)?enum\b', body):
        inner = body[body.index('{') + 1:body.rindex('}')] if '{' in body else ''
        for part in top_split(inner, ','):
            m = re.match(r'\s*(\w+)', part)
            if m:
                names.add(m.group(1))
    flat = drop_braces(body)
    # an initializer is not part of the declarator
    flat = top_split(flat, '=')[0] if '=' in flat else flat
    m = re.match(r'\s*(typedef\s+)?(extern\s+)?((const|volatile|unsigned|signed|struct|union|enum)\s+)*\w+', flat)
    rest = flat[m.end():] if m else flat
    for decl in top_split(rest, ','):
        m = re.search(r'(\w*)\s*\(\s*(\*+\s*(\w+))?', decl)
        if m and m.group(1) and m.group(1) not in KEYWORDS:  # a function: its name before the first '('
            names.add(m.group(1)); continue
        if m and m.group(3):  # a pointer to function: (*name)
            names.add(m.group(3)); continue
        decl = re.sub(r'\[[^\]]*\]', '', decl)
        ids = re.findall(r'[A-Za-z_]\w*', decl)
        ids = [i for i in ids if i not in KEYWORDS]
        if ids:
            names.add(ids[-1])
    if not names:  # `struct X;` or a bare type
        ids = [i for i in re.findall(r'[A-Za-z_]\w*', flat) if i not in KEYWORDS]
        if ids:
            names.add(ids[-1])
    return names


def parse_c(text):
    """Top-level items of a C unit. Comments and blank lines lead the next item."""
    items, i, n = [], 0, len(text)
    lead_start = 0
    while True:
        # skip whitespace and comments: they lead the next item
        j = i
        while j < n:
            if text[j].isspace():
                j += 1
            elif text.startswith('/*', j):
                j = text.index('*/', j + 2) + 2
            elif text.startswith('//', j):
                k = text.find('\n', j); j = n if k < 0 else k
            else:
                break
        if j >= n:
            if text[lead_start:].strip():
                items.append(Item('comment', '', text[lead_start:]))
            break
        lead = text[lead_start:j]
        start = j
        if text[j] == '#':
            k = j
            while True:
                e = text.find('\n', k)
                e = n if e < 0 else e
                if text[e - 1] == '\\':
                    k = e + 1; continue
                break
            code = text[start:e]
            kind = ('include' if re.match(r'#\s*include', code) else
                    'define' if re.match(r'#\s*define', code) else 'pp')
            it = Item(kind, code, lead)
            if kind == 'define':
                it.names = {re.match(r'#\s*define\s+(\w+)', code).group(1)}
                it.uses = idents(strip_code(code)) - it.names
            items.append(it)
            i = lead_start = e
            continue
        # scan to ';' at depth 0, or to the '}' closing a function body
        depth, k = 0, j
        kind = None
        while k < n:
            c = text[k]
            if text.startswith('/*', k):
                k = text.index('*/', k + 2) + 2; continue
            if text.startswith('//', k):
                e = text.find('\n', k); k = n if e < 0 else e; continue
            if c in '"\'':
                q = k + 1
                while text[q] != c:
                    q += 2 if text[q] == '\\' else 1
                k = q + 1; continue
            if c in '([{':
                if c == '{' and depth == 0:
                    head = strip_code(text[start:k]).strip()
                    if (head.endswith(')') or KR.search(head)) and '=' not in drop_braces(head):
                        kind = 'func'
                depth += 1
            elif c in ')]}':
                depth -= 1
                if c == '}' and depth == 0 and kind == 'func':
                    k += 1; break
            elif c == ';' and depth == 0:
                if not KR.search(strip_code(text[start:k])):
                    k += 1; kind = kind or 'decl'; break
            k += 1
        m = re.match(r'[ \t]*(/\*[^\n]*?\*/|//[^\n]*)[ \t]*(?=\n|$)', text[k:])
        if m:  # a comment on the same line closes the item
            k += m.end()
        code = text[start:k]
        it = Item(kind, code, lead)
        sc = strip_code(code)
        if kind == 'func' and re.match(r'static\s+inline\b', sc):
            # a static inline helper emits nothing: a declaration, copied to each file that calls it
            kind = it.kind = 'inline'
        if kind in ('func', 'inline'):
            head = sc[:sc.index('{')]
            # the name is the identifier before the parameter list of the declarator
            h = head.rstrip()
            m = KR.search(h)
            if m:  # K&R definition: the parameter declarations follow the identifier list
                h = h[:m.start(1) + len(m.group(1))]
            depth, q = 0, len(h) - 1
            while True:
                depth += {')': 1, '(': -1}.get(h[q], 0)
                if depth == 0:
                    break
                q -= 1
            it.func = re.search(r'(\w+)\s*$', h[:q]).group(1)
            it.names = {it.func}
            it.uses = idents(sc) - ({it.func} if kind == 'inline' else set())
            if kind == 'inline':
                it.func = None
        elif re.match(r'INCLUDE_ASM\s*\(', code):
            it.kind = 'func'
            it.func = re.search(r',\s*(\w+)\s*\)', code).group(1)
            it.names = {it.func}
            it.uses = set()
        elif re.match(r'INCLUDE_RODATA\s*\(', code):
            it.kind = 'rodata'
            it.names = {re.search(r',\s*(\w+)\s*\)', code).group(1)}
            it.uses = set()
        else:
            it.names = declared_names(sc)
            it.uses = idents(sc) - it.names
            flat = drop_braces(sc)
            it.init = ('=' in top_split(flat, ';')[0] and not re.match(r'\s*(extern|typedef)\b', sc))
        items.append(it)
        i = lead_start = k
    return items


# ---------------------------------------------------------------- split

def elf_funcs():
    out = subprocess.run([NM, ELF], capture_output=True, text=True, check=True).stdout
    addr = {}
    for line in out.splitlines():
        p = line.split()
        if len(p) == 3:
            addr.setdefault(p[2], int(p[0], 16))
    return addr


def old_unit_text(unit, rev):
    path = os.path.join(SRC, unit + '.c')
    if os.path.exists(path):
        return open(path, encoding='utf-8').read()
    return subprocess.run(['git', '-C', ROOT, 'show', '%s:src/%s.c' % (rev, unit)],
                          capture_output=True, text=True, check=True).stdout


def header_types():
    """Names each project header declares (types, macros, functions), with the headers it includes.
    common.h is kept in every file; the others only where the file uses one of their names."""
    out = {}
    inc = os.path.join(ROOT, 'include')
    for d, _, fs in os.walk(inc):
        for name in sorted(fs):
            if not name.endswith('.h'):
                continue
            path = os.path.join(d, name)
            text = open(path, encoding='utf-8').read()
            names, incs = set(), re.findall(r'#include\s+"([^"]+)"', text)
            for it in parse_c(text):
                if it.kind in ('decl', 'define', 'inline', 'func'):
                    names |= it.names
            out[os.path.relpath(path, inc)] = (names, incs)
    return out


def split_header(lead):
    """(header comment, rest of lead): the unit comment is the first block comment of the unit that
    stands alone (a blank line after it)."""
    m = re.search(r'/\*.*?\*/\n\s*\n', lead, re.S)
    if not m:
        return None, lead
    return m.group(0).rstrip() + '\n', lead[:m.start()] + lead[m.end():]


def rodata_file(addr):
    rom = addr - ROM_BASE
    keys = list(RODATA)
    for i, k in enumerate(keys):
        end = keys[i + 1] if i + 1 < len(keys) else RODATA_END
        if k <= rom < end:
            if RODATA[k].startswith('psyq/'):
                raise SystemExit('rodata 0x%X falls in Sony rodata %s' % (addr, RODATA[k]))
            return RODATA[k]
    raise SystemExit('no rodata file for 0x%X' % addr)


def build_files(rows, rev):
    faddr = elf_funcs()
    htypes = header_types()
    # file ranges
    ranges = []
    for r in rows:
        ranges.append((faddr[r['FIRST_FUNC']], faddr[r['LAST_FUNC']], r['FILE'][:-2], r))
    ranges.sort()

    def file_of(fn):
        a = faddr[fn]
        for lo, hi, name, _ in ranges:
            if lo <= a <= hi:
                return name
        raise SystemExit('function %s at 0x%X is in no file' % (fn, a))

    units = []
    for r in rows:
        for u in r['UNIT'].split('+'):
            if u not in units:
                units.append(u)
    files = OrderedDict((name, {'items': [], 'units': [], 'row': r}) for _, _, name, r in ranges)
    unit_headers = {}
    for unit in units:
        items = parse_c(old_unit_text(unit, rev))
        incs = [it.text for it in items if it.kind == 'include']
        body = [it for it in items if it.kind != 'include']
        # the unit comment block
        hdr = None
        for it in body:
            if it.kind == 'func':
                break
            h, rest = split_header(it.lead)
            if h:
                hdr, it.lead = h, rest
                break
        unit_headers[unit] = hdr
        owners = {}  # item index -> set of files
        extra = {}   # function item index -> files that get a prototype of it
        for idx, it in enumerate(body):
            if it.kind == 'func':
                owners[idx] = {file_of(it.func)}
            elif it.kind == 'rodata':
                owners[idx] = {rodata_file(faddr[next(iter(it.names))])}
        unit_files = []
        for idx in sorted(owners):
            for f in owners[idx]:
                if f not in unit_files:
                    unit_files.append(f)
        for f in unit_files:
            files[f]['units'].append(unit)
        # initialized records go to the one file that uses them
        uses_by_file = {f: set() for f in unit_files}
        for idx, own in owners.items():
            for f in own:
                uses_by_file[f] |= body[idx].uses
        for idx, it in enumerate(body):
            if it.kind == 'decl' and it.init:
                users = [f for f in unit_files if it.names & uses_by_file[f]]
                if len(users) != 1:
                    raise SystemExit('%s: initialized %s used by %s' % (unit, sorted(it.names), users))
                owners[idx] = {users[0]}
                uses_by_file[users[0]] |= it.uses
        # every other declaration: closure over the names each file uses
        fixed = set(owners)
        declared = set()
        for it in body:
            if it.kind in ('decl', 'inline'):
                declared |= it.names
        defs = {it.func: idx for idx, it in enumerate(body) if it.kind == 'func' and '{' in it.text}
        for f in unit_files:
            need = set(uses_by_file[f])
            kept, protos = set(), set()
            changed = True
            while changed:
                changed = False
                for idx, it in enumerate(body):
                    if idx in kept or idx in fixed or it.kind not in ('decl', 'define', 'inline'):
                        continue
                    if it.names & need:
                        kept.add(idx); need |= it.uses; changed = True
                # a function of another file that the old unit defined above its first use here and
                # never declared: its calls were compiled against the definition, so this file gets
                # a prototype written from the definition, at the definition's place
                mine = [i for i in owners if f in owners[i] and body[i].kind == 'func']
                for name in sorted(need - declared):
                    idx = defs.get(name)
                    if idx is None or f in owners[idx] or idx in protos:
                        continue
                    first = min((i for i in mine if name in body[i].uses), default=None)
                    if first is None or first < idx:
                        continue  # the old unit called it before its definition: implicit, as before
                    protos.add(idx)
                    need |= prototype(body[idx]).uses; changed = True
            for idx in kept:
                owners.setdefault(idx, set()).add(f)
            for idx in protos:
                extra.setdefault(idx, set()).add(f)
                print('%s: prototype of %s added to %s' % (unit, body[idx].func, f), file=sys.stderr)
            # includes: those whose types (or their includes' types) the file uses
            files[f].setdefault('need', set()).update(need)
            for inc in incs:
                if inc not in files[f].setdefault('incs', []):
                    files[f]['incs'].append(inc)
        # a type or static inline helper no file uses stays with the file of the next item that has one
        for idx, it in enumerate(body):
            if idx in owners or not (it.kind == 'inline' or it.kind == 'decl' and
                                     re.match(r'\s*(typedef|struct|union|enum)\b', strip_code(it.text))):
                continue
            nxt = [i for i in sorted(owners) if i > idx] or [i for i in sorted(owners) if i < idx][-1:]
            owners[idx] = {sorted(owners[nxt[0]])[0]}
            print('%s: unused %s kept in %s' % (unit, sorted(it.names), owners[idx]), file=sys.stderr)
        for idx, it in enumerate(body):
            for f in sorted(extra.get(idx, ())):
                files[f]['items'].append((unit, prototype(it)))
            for f in owners.get(idx, ()):
                files[f]['items'].append((unit, it))
            if idx not in owners and it.kind != 'comment':
                print('dropped from %s: %s' % (unit, it.text.splitlines()[0][:90]), file=sys.stderr)
    return files, unit_headers, htypes


def prototype(it):
    """A declaration item made from a function definition's head."""
    head = it.text[:it.text.index('{')].rstrip()
    head = re.sub(r'^\s*inline\s+', '', head)
    if KR.search(strip_code(head)):
        raise SystemExit('K&R definition %s: write its prototype by hand' % it.func)
    p = Item('decl', head + ';', '\n')
    sc = strip_code(p.text)
    p.names = {it.func}
    p.uses = idents(sc) - p.names
    return p


def header_closure(h, htypes, seen=None):
    seen = set() if seen is None else seen
    if h in seen or h not in htypes:
        return set()
    seen.add(h)
    names = set(htypes[h][0])
    for inc in htypes[h][1]:
        names |= header_closure(inc, htypes, seen)
    return names


HEADER_NOTE = ' * File boundaries: %s (docs/layout.md)\n'


def render(name, f, headers, htypes):
    out = []
    need = set(f['need'])
    for _, it in f['items']:
        need |= it.uses
    hname = {inc: re.search(r'"([^"]+)"', inc).group(1) for inc in f['incs']}
    cands = [i for i in f['incs'] if hname[i] != 'common.h']
    # a header whose own types the file uses, then any other one still needed for a used type
    keep = [i for i in cands if htypes.get(hname[i], ((), ()))[0] & need]
    given = set()
    for i in keep:
        given |= header_closure(hname[i], htypes)
    for i in cands:
        if i not in keep and header_closure(hname[i], htypes) & need - given:
            keep.append(i); given |= header_closure(hname[i], htypes)
    cands = keep
    for inc in f['incs']:
        if hname[inc] == 'common.h' or inc in cands:
            out.append(inc)
    text = '\n'.join(out) + '\n\n'
    conf = f['row']['CONFIDENCE']
    hdr = headers.get(name)
    if hdr:
        text += hdr.rstrip()[:-2].rstrip() + '\n *\n' + HEADER_NOTE % conf + ' */\n'
    else:
        text += '/*\n' + HEADER_NOTE % conf + ' */\n'
    first = True
    for unit, it in f['items']:
        lead = it.lead
        if first:
            lead = '\n' + lead.lstrip('\n')
            if not lead.strip():
                lead = '\n'
            first = False
        code = it.text
        if it.kind in ('rodata', 'func'):
            code = re.sub(r'asm/nonmatchings/(game|kaj)/\w+', 'asm/nonmatchings/' + name, code)
        text += lead + code
    return text.rstrip() + '\n'


# ---------------------------------------------------------------- splat

def rewrite_splat(rows, faddr):
    lines = open(SPLAT, encoding='utf-8').read().split('\n')
    entry = re.compile(r'\s*- \[(0x[0-9A-Fa-f]+),\s*(\.?\w+),\s*([\w/]+)\]\s*(#.*)?$')
    try:
        s = next(i for i, l in enumerate(lines) if l.strip() == 'subsegments:')
        e = next(i for i, l in enumerate(lines) if i > s and 'type: bss' in l)
    except StopIteration:
        raise SystemExit('splat.yaml: no subsegments block')
    old = lines[s + 1:e]
    keep = []   # (offset, order, [lines])
    pending = []
    for l in old:
        m = entry.match(l)
        if not m:
            pending.append(l); continue
        off, kind, name = int(m.group(1), 16), m.group(2), m.group(3)
        if name.startswith(('game/', 'kaj/')):
            if pending:
                keep.append((off, len(keep), pending)); pending = []
            continue
        keep.append((off, len(keep), pending + [l])); pending = []
    if pending:
        keep.append((1 << 40, len(keep), pending))
    ind = '      '
    for off, name in RODATA.items():
        if not name.startswith('psyq/'):
            keep.append((off, len(keep), ['%s- [0x%X, .rodata, %s]' % (ind, off, name)]))
    for r in rows:
        off = faddr[r['FIRST_FUNC']] - ROM_BASE
        name = r['FILE'][:-2]
        keep.append((off, len(keep), ['%s- [0x%X, c, %s]  # %s; %s' % (
            ind, off, name, r['CONFIDENCE'], TEXT_COMMENTS[name])]))
    keep.sort()
    body = [l for _, _, ls in keep for l in ls]
    text = '\n'.join(lines[:s + 1] + body + lines[e:])
    text, n = SPLAT_HEAD_OLD.subn(SPLAT_HEAD_NEW, text)
    text = text.replace('# .rodata per text unit, in the same order as .text (each start is the first symbol the unit\'s\n'
                        '      # code references). Game and kaj units use the dot form so splat pairs them with their c unit\n',
                        '# .rodata per source file, in the same order as .text (each start is the first symbol the file\'s\n'
                        '      # code references). Game and kaj files use the dot form so splat pairs them with their c file\n')
    open(SPLAT, 'w', encoding='utf-8').write(text)


# ---------------------------------------------------------------- citations

CITE_PATHS = ['config/symbol_addrs.txt', 'docs/discoveries.md', 'docs/naming.md', 'docs/engine/README.md',
              'docs/engine/scenes-and-scripts.md', 'docs/engine/boot-and-loop.md', 'docs/engine/files-and-cd.md',
              'docs/engine/rendering.md', 'docs/engine/town-and-vehicles.md', 'docs/engine/sound-and-music.md',
              'docs/engine/menus-text-and-save.md', 'tools/xref.py', 'tools/unit_check.sh']
CITE = re.compile(r'(src/(game|kaj)/)?\b(8[0-9A-F]{7})\.c\b( line [0-9]+)?|\b(game|kaj)/(8[0-9A-F]{7})\b')
LEVELS = 'config/name_levels.tsv'
# Citations the line alone does not settle: (file, old unit, words of the line) -> new file or files.
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from split_units_cites import CITE_OVERRIDES  # noqa: E402


def cite_tables(rows):
    unit_files = OrderedDict()
    for r in rows:
        for u in r['UNIT'].split('+'):
            unit_files.setdefault(u, []).append(r['FILE'][:-2])
    texts = {}
    for r in rows:
        name = r['FILE'][:-2]
        path = os.path.join(SRC, name + '.c')
        texts[name] = open(path, encoding='utf-8').read() if os.path.exists(path) else ''
    items = {name: parse_c(t) for name, t in texts.items()}
    defined = {name: {it.func for it in its if it.kind == 'func'} for name, its in items.items()}
    types = {name: set().union(*[it.names for it in its if it.kind == 'decl' and
                                 re.match(r'\s*(typedef|struct|union|enum)\b', strip_code(it.text))] or [set()])
             for name, its in items.items()}
    used = {name: idents(strip_code(t)) for name, t in texts.items()}
    return unit_files, defined, used, types


def unit_key(addr, tables):
    for d in ('game', 'kaj'):
        if '%s/%s' % (d, addr) in tables[0]:
            return '%s/%s' % (d, addr)
    return None


def cite_one(path, line, unit, tables, why, near=''):
    """near: the text of the line between the previous citation and this one, tried first."""
    unit_files = tables[0]
    cands = unit_files[unit]
    if len(cands) == 1:
        return cands[0]
    for (p, u, words), f in CITE_OVERRIDES.items():
        if p == path and u == unit and words in line:
            why.append('override')
            return f
    # the file named just before the citation: `[block.c](../../src/game/80179848.c)`, `ll.c (kaj/801CCAF4)`
    m = re.search(r'(?:\[|^|\s)([a-z_]+)\.c(?:\]\(|\s\()[./]*$', near)
    if m and [f for f in cands if f.split('/')[1] == m.group(1)]:
        why.append('named')
        return [f for f in cands if f.split('/')[1] == m.group(1)][0]
    if near and path != 'config/symbol_addrs.txt':
        f = cite_ids(near, cands, tables, why)
        if f:
            return f
    f = cite_ids(line, cands, tables, why, path == 'config/symbol_addrs.txt')
    if f:
        return f
    why.append('UNRESOLVED')
    return unit


def cite_ids(text, cands, tables, why, first_only=False):
    defined, used = tables[1], tables[2]
    ids = [i for i in re.findall(r'[A-Za-z_]\w*', text) if '_' in i or i[:1].isupper()]
    if first_only:
        ids = ids[:1]  # the symbol the line describes
    d = [f for f in cands if any(i in defined[f] for i in ids)]
    if len(d) == 1:
        why.append('defines')
        return d[0]
    score = {f: sum(1 for i in ids if i in used[f]) for f in (d or cands)}
    best = max(score.values())
    top = [f for f in score if score[f] == best]
    if best and len(top) == 1:
        why.append('uses')
        return top[0]
    return None


def cite_text(m, f, dir_before=False):
    """The new citation for match m of CITE: f is a file key (dir/name) or a tuple of them."""
    fs = f if isinstance(f, tuple) else (f,)
    if m.group(5):  # game/<addr>: the segment name
        out = [x for x in fs]
    elif m.group(1):  # src/<dir>/<addr>.c
        out = ['src/%s.c' % x for x in fs]
    elif dir_before:  # kaj/<addr>.c: the directory is already written
        out = [x.split('/')[1] + '.c' for x in fs]
    else:  # <addr>.c: the bare name, kaj/event.c told apart from game/event.c
        out = [('kaj/event' if x == 'kaj/event' else x.split('/')[1]) + '.c' for x in fs]
    return ' and '.join(out) if len(out) < 3 else ', '.join(out[:-1]) + ' and ' + out[-1]


def rewrite_cites(text, path, tables, log=None):
    out = []
    for line in text.split('\n'):
        prev = [0]

        def sub(m):
            unit = unit_key(m.group(3) or m.group(6), tables)
            if unit is None:
                return m.group(0)
            why = []
            near = line[prev[0]:m.start()]
            prev[0] = m.end()
            f = cite_one(path, line, unit, tables, why, near)
            if log is not None:
                log.append('%s\t%s\t%s\t%s\t%s' % (path, unit, f, ','.join(why), line.strip()[:140]))
            if f == unit:
                return m.group(0)
            before = line[:m.start()]
            return cite_text(m, f, before.endswith(('kaj/', 'game/')))
        out.append(CITE.sub(sub, line))
    return '\n'.join(out)


def rewrite_levels(tables, log):
    """config/name_levels.tsv: FILE of a func is the file that defines it, of a global the first file
    of its old unit that names it, of a type or field the first file of its old unit that declares the
    type. Rows whose FILE is not an old unit stay."""
    unit_files, defined, used, types = tables
    faddr = elf_funcs()
    syms = {m.group(1): int(m.group(2), 16) for m in re.finditer(
        r'^(\w+) = 0x([0-9A-Fa-f]+);', open(os.path.join(ROOT, 'config/symbol_addrs.txt'), encoding='utf-8').read(), re.M)}
    asm_users = {}
    for kind in ('matchings', 'nonmatchings'):
        for d in ('game', 'kaj'):
            top = os.path.join(ROOT, 'asm', kind, d)
            for f in (os.listdir(top) if os.path.isdir(top) else ()):
                for fn in os.listdir(os.path.join(top, f)):
                    for w in set(re.findall(r'[A-Za-z_]\w*', open(os.path.join(top, f, fn), encoding='utf-8').read())):
                        asm_users.setdefault(w, set()).add('%s/%s' % (d, f))
    full = os.path.join(ROOT, LEVELS)
    lines = open(full, encoding='utf-8').read().split('\n')
    head = lines[0].split('\t')
    ci, ki, ni = head.index('FILE'), head.index('KIND'), head.index('NAME')
    for n, line in enumerate(lines[1:], 1):
        if not line.strip():
            continue
        c = line.split('\t')
        m = re.match(r'src/((game|kaj)/8[0-9A-F]{7})\.c(:(\w+))?$', c[ci])
        if not m:
            continue
        unit, kind, name = m.group(1), c[ki], c[ni]
        cands = unit_files.get(unit)
        if not cands:
            continue
        if kind == 'func':
            hit = [f for f in cands if name in defined[f]]
        elif kind == 'global':
            hit = [f for f in cands if name in used[f]]
            a = faddr.get(name, syms.get(name))
            if not hit and a is not None and RODATA_START <= a - ROM_BASE < RODATA_END:
                hit = [rodata_file(a)]  # a string only C literals read: the file of its .rodata
            if not hit:  # read only through a field in C: the files whose asm names it
                hit = [f for f in cands if asm_users.get(name, set()) & {f}]
            if not hit:
                hit = [f for f in used if name in used[f]]  # no longer declared in its old unit's files
        else:
            hit = [f for f in cands if (name if kind == 'type' else m.group(4)) in types[f]]
        if not hit:
            log.append('%s\t%s\t%s\tUNRESOLVED\t%s %s' % (LEVELS, unit, unit, kind, name))
            continue
        c[ci] = 'src/%s.c%s' % (hit[0], m.group(3) or '')
        lines[n] = '\t'.join(c)
    return '\n'.join(lines)


def cmd_cite(args):
    tables = cite_tables(file_rows(read_plan()))
    log = []
    news = {}
    for p in CITE_PATHS:
        full = os.path.join(ROOT, p)
        text = open(full, encoding='utf-8').read()
        news[p] = (text, rewrite_cites(text, p, tables, log))
    text = open(os.path.join(ROOT, LEVELS), encoding='utf-8').read()
    news[LEVELS] = (text, rewrite_levels(tables, log))
    print('\n'.join(log))
    bad = [l for l in log if 'UNRESOLVED' in l]
    if bad:
        print('%d unresolved citations: add them to tools/split_units_cites.py; nothing written' % len(bad))
        return 1
    if not args.dry_run:
        for p, (old, new) in news.items():
            if new != old:
                open(os.path.join(ROOT, p), 'w', encoding='utf-8').write(new)
    print('%d citations, %d files changed' % (len(log), sum(1 for o, n in news.values() if o != n)))
    return 0


# ---------------------------------------------------------------- docs

DOC_HEAD = """# Source file layout

The executable links the game's own source files first, then the Sony libraries with the developer's own small
library (the `kaj_` functions) placed between Sony objects. The code is split into the %d source files the
original programmers most likely had: %d in `src/game` and %d in `src/kaj`, with %d runs of Sony code between
them (asm, never decompiled). Each file holds its functions in address order; the files sit in link order. The
plan is `config/layout.tsv`; `tools/split_units.py docs` writes this page from it, and
`tools/split_units.py apply` replays the split from the address units of commit %s.

Confidence, for the two ends of a file: **proven** means a Sony object sits on both sides, so no other cut is
possible; **likely** means each end rests on an assert, a jump-table alignment, a change in `gp` use, the .rodata
order or a deferred inline tail (below); **guess** means the binary allows another cut, and the row says which.

%d files: %d proven, %d likely, %d guess.

## Files in link order

| File | Functions | Confidence | Evidence |
| --- | --- | --- | --- |
"""

DOC_RODATA = """
## Rodata

A C file emits its strings and constants first and its jump tables after the function bodies;
`INCLUDE_RODATA` lines place the symbols that are not migrated into a function. Each `.rodata` entry of
`config/splat.yaml` starts at the first symbol the file's code uses and names that file. menu.c, npc.c and
heap.c have none.

| ROM offset | Address | File |
| --- | --- | --- |
"""

DOC_TAIL = """
## How the boundaries were found

| Source | What it shows | Strength |
| --- | --- | --- |
| Sony objects between kaj code in .text | A file boundary on each side | Proven |
| Asserts | A function passes its source file name to `kaj_abend` (with a line number), so it belongs to that file. The 13 asserted game names and the 9 asserted kaj names are kept. | Proven for the function, not for the file's ends |
| Jump-table parity | GCC 2.8.1 aligns every jump table to 8 bytes inside its object and the link keeps 4-byte alignment, so a jump table at 4 mod 8 from its file's .rodata start proves that a new object starts before it. | Proven where it applies |
| Rodata order | Within a file, strings come before jump tables, so a string after a jump table starts a new file. | Proven where it applies |
| gp access | maspsx reaches through gp only the small globals a file defines. An initialized .sdata symbol is reached through gp only in its one defining file, and a file never mixes gp and `lui` access to the same symbol. | Proven for .sdata; for .sbss it assumes no shared `.comm` |
| Deferred inline tails | GCC 2.8.1 emits a non-static inline function at the end of its file, so a normal function after a deferred one starts a new file. | Proven where it applies |
| Equal literals | cc1 merges identical string literals in one file: two stored copies mean two files. | Proven |
| Names | The asserted names run in alphabetical order (action, block, door, effect, event, mail, mod, object, roadmap, sound, sprite, thing, vehicle; event, kaj, ll, misc, tim, timer, tss, view, then cdmgr), so a file without an assert gets a name that sorts between its neighbours'. | Convention |

`work/layout/check.py` tests the plan against these rules (gp users, gp and `lui` mixes, .rodata ownership and
order, pointer-table users, strings after jump tables, .data and .sdata order, duplicate literals, jump-table
parity) and reports no violation over 206 rodata symbols. `make check` cannot judge a layout by itself: any cut
matches as long as each file declares the gp symbols it uses (rule 1 below).

## Open doubts

1. card/dialog: the cut after `menu_card_run` is a guess, and the pause menu (`menu_list_page` on) might be
   card.c's tail or a file of its own. menu.c and text.c would sort after door, so the text windows were named
   dialog.c to keep the order.
2. mail/main: main.c is a file only because of its name. `mail_main_restarted`, main's .sdata flag, sits after
   mail.c's file name string, which fits but does not prove it.
3. effect.c is large (50 functions): the weapon and item part (`effect_weapon_unequip` on) could be a file of its
   own sorting between effect and event; no cut shows it.
4. event.c's HUD part (`event_drain_gauge` on) could be hud.c, between event and mail; no cut shows it.
5. object.c's office loop (`object_room_*`) could be office.c, between object and player; no cut shows it.
6. sprite.c holds the title, station and phone screens. station.c would sort between sprite and thing; title.c
   and phone.c would break the order.
7. town/vehicle: the .rodata allows any cut up to `vehicle_create`. The cut at `thing_train_calc_stops` follows
   the gp users of `thing_car_exit_prompt_on` and `thing_car_speed_div`, which are .sbss and so not proof.
8. heap.c may be cdmgr.c's tail: its functions are called only from cdmgr.c, and its .sdata is read only by itself.
9. actor.c against npc.c: both hold NPC code. The first must sort between action and ai, so it cannot be npc.c.
10. `text_type_step` has no visible reference (no caller, no table); its file follows only from its position.

## Headers

- Every file has a header, `include/game/<file>.h` or `include/kaj/<file>.h`, that declares what other files call
  or a data table names. A prototype is the definition line of its function, parameter names included.
- A type used by five files or fewer lives in the header of the file that owns its records, or in the one `.c`
  file that uses it. `include/game/types.h` keeps the 29 types used by six files or more. `GsDobj2` stays in
  src/game/block.c, the only file that reads it, because its `tmd` field is the game's `TmdObject` view.
  `TmdObject` and `TmdTri` sit in include/game/block.h because mod.c reads `TmdObject` too.
- Sony functions are declared in `include/psyq/<lib>.h`: libapi, libc (LIBC2 and LIBC), libcd, libetc, libgpu,
  libgs, libgte, libmcrd and libsnd. The Sony layouts the game reads keep our names there: `GsCoordinate2` in
  libgs.h, `SVector` in libgte.h, `Rect` in libgpu.h and `CdLoc` in libcd.h. A parameter that only a game view
  describes is `void *`. block.c declares `__nedf2` itself because it calls it by hand.
- A file includes `common.h`, then its own header, then the headers of the files it uses. The prototypes left in
  a `.c` file are forward declarations of its own helpers, plus the exceptions below. The `extern` declarations
  of data stay in each file that reads them, because the data lives in asm.
- 29 functions are not in their header and stay declared in each calling file. For 27 of them the callers
  declare other argument or return widths, and one shared prototype changed their bytes. Each function was tried
  on its own with `tools/unit_check.sh`. Those 27 are action_run_npc_event, action_run_trigger_enter,
  action_run_trigger_leave, effect_inventory_has_room, effect_item_add, effect_item_remove, effect_weapon_add,
  effect_weapon_input, kaj_ll_at_tail, kaj_map_city_ready, kaj_map_load_city_dir, kaj_map_load_place_dir,
  mail_angle_to_dir8, mail_check_schedule, mail_goto_building, mail_take_scene_change, mod_set_anim_by_id,
  player_set_item, player_set_weapon, player_take_hit, roadmap_get_state, sprite_copy_cell,
  sprite_phone_save_exit, text_show, text_show_profile, text_show_timed and thing_run_script. The other two,
  kaj_tim_load and kaj_tim_free, name a `TimHandle` that two files define differently. Each header lists its own
  exceptions in a closing comment.
- A function that no other file references by symbol is `static` (205 of them). That includes the eight
  primitive handlers roadmap_draw_f3 to roadmap_draw_gt4: roadmap_init_draw stores them in
  `roadmap_prim_handlers` at run time, and Sony's `GsSortObject4J` calls them through that table, never by
  name. A function that nothing references stays global too: cc1 could drop a
  `static` copy of an inline function.
- The Makefile does not track headers. After editing one, run `rm -rf build/src` and then `make check`.

## Rules for contributors

1. **A small global (8 bytes or less) reached through gp is declared without `extern` in every file that uses
   it**, as a tentative definition (`s16 action_blink_count;`). cc1 emits `.comm`, maspsx reaches it through gp,
   and the linker merges it with the asm data. An `extern` gives `lui` accesses and shifts the whole executable.
   Never move such a declaration into a header with `extern`.
2. **No `static` variable while the data lives in asm**: it would allocate bytes in the C object and duplicate
   the data. A function is `static` when no other file names it and no data points to it. `static` keeps the
   bytes but changes the relocations, so `tools/unit_check.sh --save` must run again after one is added or
   removed.
3. A file with rodata keeps its `.rodata` entry in `config/splat.yaml` (dot form, same name); an
   `INCLUDE_RODATA` or `INCLUDE_ASM` path names `asm/nonmatchings/<dir>/<file>`. After renaming a file, run
   `make split` twice: splat writes the `.s` only once the C file names it.
4. Keep functions in address order inside a file: cc1 emits in source order, apart from the deferred inline
   tails.
5. Two files may declare the same function with different parameter types on purpose (a caller that needs
   promoted arguments): a shared prototype must keep each caller's code, and `make check` decides (Headers).
6. **The build stays shiftable**: after `make check`, `.venv/bin/python -I tools/rawscan.py --max 0` must print
   `# 0 raw words`.
"""


def write_docs(rows):
    faddr = elf_funcs()
    frows = file_rows(rows)
    byfile = {r['FILE']: r for r in rows}
    conf = [r['CONFIDENCE'] for r in frows]
    ng = sum(1 for r in frows if r['FILE'].startswith('game/'))
    out = DOC_HEAD % (len(frows), ng, len(frows) - ng, len(rows) - len(frows), DEFAULT_REV, len(frows),
                      conf.count('proven'), conf.count('likely'), conf.count('guess'))
    for r in rows:
        funcs = r['FIRST_FUNC'] if r['FIRST_FUNC'] == r['LAST_FUNC'] else '%s..%s' % (r['FIRST_FUNC'], r['LAST_FUNC'])
        if not r['FILE'].endswith('.c'):
            out += '| *%s* | `%s` | | %s |\n' % (r['FILE'], funcs, r['EVIDENCE'])
            continue
        out += '| [`%s`](../src/%s) | `%s` @0x%08X (%s) | %s | %s |\n' % (
            r['FILE'], r['FILE'], funcs, faddr[r['FIRST_FUNC']], r['COUNT'], r['CONFIDENCE'], r['EVIDENCE'])
    out += DOC_RODATA
    for off, name in RODATA.items():
        if name + '.c' in byfile:
            out += '| 0x%X | 0x%08X | `%s.c` |\n' % (off, off + ROM_BASE, name)
    out += DOC_TAIL
    open(os.path.join(ROOT, 'docs/layout.md'), 'w', encoding='utf-8').write(out)
    print('wrote docs/layout.md')


def cmd_apply(args):
    rows = file_rows(read_plan())
    files, unit_headers, htypes = build_files(rows, args.rev)
    if args.dump_headers:
        for u, h in unit_headers.items():
            print('=== %s -> %s' % (u, [n for n, f in files.items() if u in f['units']]))
            print(h)
        return 0
    from split_units_headers import HEADERS
    headers = {}
    for name in files:
        if name in HEADERS:
            headers[name] = HEADERS[name]
        elif all(unit_headers[u] is None for u in files[name]['units']):
            headers[name] = None
        elif len(files[name]['units']) == 1 and sum(1 for g in files.values() if g['units'] == files[name]['units']) == 1:
            headers[name] = unit_headers[files[name]['units'][0]]
        else:
            raise SystemExit('no header text for %s.c (tools/split_units_headers.py)' % name)
    faddr = elf_funcs()
    for name, f in files.items():
        open(os.path.join(SRC, name + '.c'), 'w', encoding='utf-8').write(render(name, f, headers, htypes))
    # hand reconciliations of declarations, if any, kept as a patch so the split can be replayed
    fix = os.path.join(ROOT, 'tools/split_units.fixups.patch')
    if os.path.exists(fix) and not args.no_fixups:
        subprocess.run(['patch', '-p1', '-s', '--no-backup-if-mismatch', '-d', ROOT, '-i', fix], check=True)
    olds = sorted({u for r in rows for u in r['UNIT'].split('+')})
    for u in olds:
        p = os.path.join(SRC, u + '.c')
        if os.path.exists(p):
            os.remove(p)
    rewrite_splat(rows, faddr)
    print('wrote %d files, removed %d units' % (len(files), len(olds)))
    return 0


def main():
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    a = sub.add_parser('apply')
    a.add_argument('--rev', default=DEFAULT_REV)
    a.add_argument('--dump-headers', action='store_true')
    a.add_argument('--no-fixups', action='store_true', help='skip the hand reconciliation patch')
    sub.add_parser('docs')
    c = sub.add_parser('cite')
    c.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    if args.cmd == 'apply':
        return cmd_apply(args)
    if args.cmd == 'cite':
        return cmd_cite(args)
    write_docs(read_plan())
    return 0


if __name__ == '__main__':
    sys.exit(main())
