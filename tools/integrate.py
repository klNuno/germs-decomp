#!/usr/bin/env python3
"""Move a matched function from a scratch C file into its unit in src/, then prove the whole build.

  tools/integrate.py FUNC FILE.c [--no-check]

FILE.c holds `#include "common.h"`, then top-level declarations (externs, prototypes,
typedefs, structs), then the definition of FUNC. The declarations missing from the unit
go to the declaration block at the top of the unit, and the function replaces
`INCLUDE_ASM(..., FUNC);`. `tools/integrate.py --normalize` only rewrites every unit that way. Then `make check`
runs; on any failure the unit is restored and the exit code is 1. One integration at a time.
"""
import glob
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def find_unit(func):
    pat = re.compile(r'^INCLUDE_ASM\("[^"]+",\s*' + re.escape(func) + r'\);\s*$', re.M)
    for path in sorted(glob.glob(f"{ROOT}/src/**/*.c", recursive=True)):
        text = open(path, encoding="utf-8").read()
        m = pat.search(text)
        if m:
            return path, text, m
    sys.exit(f"{func}: no INCLUDE_ASM line in src/ (already integrated?)")


def rodata_syms(func):
    """D_ symbols that FUNC's original asm references and that have an INCLUDE_RODATA file."""
    hits = glob.glob(f"{ROOT}/asm/nonmatchings/**/{func}.s", recursive=True)
    if not hits:
        return []
    names = set(re.findall(r"%(?:hi|lo)\((D_[0-9A-F]{8})\)", open(hits[0], encoding="utf-8").read()))
    return sorted(n for n in names if glob.glob(f"{ROOT}/asm/nonmatchings/**/{n}.s", recursive=True))


def split_candidate(func, text):
    """(declarations, definition) of FILE.c, without the common.h include."""
    text = re.sub(r'^\s*#include\s+"common\.h"\s*\n', "", text, flags=re.M)
    m = re.search(r"^[^\n;{}]*\b" + re.escape(func) + r"\s*\([^;{]*\)\s*\{", text, re.M)
    if not m:
        sys.exit(f"{func}: no definition found in the candidate")
    return text[:m.start()].strip(), text[m.start():].strip()


def top_level_items(decls):
    """Split declarations into items (a line, or a braced block ending with ';')."""
    items, buf, depth = [], [], 0
    for line in decls.splitlines():
        if not line.strip() or line.strip().startswith("//"):
            continue
        buf.append(line.rstrip())
        code = code_of(line)
        depth += code.count("{") - code.count("}")
        if depth == 0 and (code.endswith(";") or not code.strip()) or line.lstrip().startswith("#"):
            items.append("\n".join(buf))
            buf = []
    if buf:
        items.append("\n".join(buf))
    return items


def code_of(line):
    """The line without /* */ and // comments, for deciding where an item ends."""
    return re.sub(r"//.*", "", re.sub(r"/\*.*?\*/", "", line)).rstrip()


KR_HEAD = re.compile(r"^[A-Za-z_][\w \t*]*\b\w+\s*\([\w\s,]*\)\s*$")


def is_kr_head(line):
    """The first line of a K&R definition, `s32 f(a, b)`: a function head with bare parameter
    names, no ';' and no '{'. Its parameter declarations and body follow on the next lines."""
    code = code_of(line).strip()
    return bool(KR_HEAD.match(code)) and not code.startswith(("typedef", "extern", "return", "else", "if", "while", "for", "switch"))


def is_function_start(item):
    """A function definition: the code before its first '{' ends with ')', or the item opens
    with a K&R head. A struct, union or enum body has no parenthesis right before its brace."""
    if "{" not in item:
        return False
    if is_kr_head(item.splitlines()[0]):
        return True
    head = " ".join(code_of(l) for l in item.split("{", 1)[0].splitlines()).strip()
    return head.endswith(")") and not head.startswith(("typedef", "extern"))


def is_initialized_data(item):
    """A top-level definition with an initializer (`T D_x = { ... };`): a unit that owns .sdata
    (config/splat.yaml) defines it after every INCLUDE_RODATA, because maspsx stays in its .sdata
    state until a .text line and fails on the `.section .rodata` that would follow."""
    code = " ".join(code_of(l) for l in item.splitlines()).strip()
    return bool(re.match(r"^(?!typedef\b|extern\b)[\w\s*]+\b[A-Za-z_]\w*(\[[^\]]*\])*\s*=", code))


def normalize(unit):
    """Rewrite a unit as: includes, every top-level declaration, then functions and
    INCLUDE_ASM lines in their original order, then initialized data definitions.
    A declaration never sits below a user (initialized data has an extern at the top)."""
    includes, decls, bodies, tail, buf, depth = [], [], [], [], [], 0
    for line in unit.splitlines():
        if not buf and not line.strip():
            continue
        if not buf and line.startswith("#include"):
            includes.append(line)
            continue
        if not buf and line.startswith(("INCLUDE_ASM", "INCLUDE_RODATA")):
            bodies.append(line)
            continue
        buf.append(line)
        code = code_of(line)
        depth += code.count("{") - code.count("}")
        kr_open = is_kr_head(buf[0]) and "{" not in "".join(code_of(l) for l in buf)
        if depth == 0 and not kr_open and (code.endswith((";", "}")) or not code.strip()):
            item = "\n".join(buf)
            buf = []
            if is_function_start(item) and not item.rstrip().endswith(";"):
                bodies.append(item)
            elif is_initialized_data(item):
                tail.append(item)
            else:
                decls.append(item)
    if buf:
        bodies.append("\n".join(buf))
    seen, uniq = set(), []
    for d in decls:
        key = re.sub(r"\s+", " ", d).strip()
        if key not in seen:
            seen.add(key)
            uniq.append(d)
    # A forward `typedef struct X X;` beside the full `typedef struct X {...} X;` is a
    # redefinition for cc1: the full one stays.
    full = {type_name(d) for d in uniq if re.match(r"\s*typedef\s+struct\s+\w+\s*\{", d)}
    uniq = [d for d in uniq if forward_typedef(d) not in full]
    uniq = order_types(uniq)
    out = "\n".join(includes) + "\n\n"
    if uniq:
        out += "\n".join(uniq) + "\n\n"
    out += "\n\n".join(bodies) + "\n"
    if tail:
        out += "\n" + "\n".join(tail) + "\n"
    return out


def forward_typedef(item):
    """X for `typedef struct X X;`, else None."""
    m = re.fullmatch(r"\s*typedef\s+struct\s+(\w+)\s+\1\s*;\s*", item)
    return m.group(1) if m else None


def order_types(decls):
    """Keep the order, except that a type definition moves above the first item that names it
    (a candidate may refine a unit type in place with a field of a type it adds further down)."""
    defs = {}
    for d in decls:
        name = type_name(d)
        if name and name not in defs:
            defs[name] = d
    out, done, busy = [], set(), set()

    def visit(d):
        if id(d) in done or id(d) in busy:
            return
        busy.add(id(d))
        for word in re.findall(r"\b\w+\b", " ".join(code_of(l) for l in d.splitlines())):
            dep = defs.get(word)
            if dep is not None and dep is not d:
                visit(dep)
        busy.discard(id(d))
        done.add(id(d))
        out.append(d)

    for d in decls:
        visit(d)
    return out


def type_name(item):
    """The struct/union tag or typedef name an item defines, else None."""
    code = " ".join(code_of(l) for l in item.splitlines())
    if "{" not in code:
        return None
    m = re.search(r"\}\s*(\w+)\s*;\s*$", code) if code.lstrip().startswith("typedef") else None
    if m:
        return m.group(1)
    m = re.match(r"\s*(?:typedef\s+)?(?:struct|union|enum)\s+(\w+)\s*\{", code)
    return m.group(1) if m else None


SIZES = {"u8": 1, "s8": 1, "char": 1, "u16": 2, "s16": 2, "short": 2,
         "u32": 4, "s32": 4, "int": 4, "long": 4, "float": 4, "unsigned": 4}
DECLARATOR = re.compile(r"^(\**)\s*(unk|pad)([0-9A-Fa-f]+)\s*(?:\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\])?$")


def struct_fields(item):
    """(head, tail, fields) of a struct whose members are all named unkXX or padXX (XX = the
    offset), None for any other shape. A field is [offset, size or None, text, kind]: kind "pad"
    for padXX, "soft" for a byte array (an unknown area), else "hard"."""
    code = re.sub(r"/\*.*?\*/", "", item, flags=re.S)
    code = re.sub(r"//[^\n]*", "", code)
    if "{" not in code or "}" not in code:
        return None
    lo, hi = code.index("{"), code.rindex("}")
    head, tail, body = code[:lo + 1].strip(), code[hi:].strip(), code[lo + 1:hi]
    members, depth, buf = [], 0, ""
    for ch in body:
        buf += ch
        depth += (ch == "{") - (ch == "}")
        if ch == ";" and depth == 0:
            members.append(buf.strip())
            buf = ""
    if buf.strip() or not members:
        return None
    fields = []
    for mem in members:
        mem = mem[:-1].strip()
        if "{" in mem:  # a nested struct or union: one member named after its closing brace
            text, decls = mem[:mem.rindex("}") + 1], [mem[mem.rindex("}") + 1:].strip()]
            base = None
        else:
            m = re.match(r"^((?:const\s+|volatile\s+|struct\s+|union\s+|unsigned\s+|signed\s+)*\w+)\s+(.+)$", mem, re.S)
            if not m or "(" in mem or ":" in mem:
                return None
            text, decls, base = m.group(1), m.group(2).split(","), m.group(1).split()[-1]
        for decl in decls:
            d = DECLARATOR.match(decl.strip())
            if not d:
                return None
            ptr, kind, off, count = d.groups()
            elem = 4 if ptr else SIZES.get(base)
            n = int(count, 0) if count else 1
            name = f"{ptr}{kind}{off}" + (f"[{count}]" if count else "")
            if "\n" in text:
                line = "    " + "\n    ".join(l.strip() if i in (0, text.count("\n")) else "    " + l.strip()
                                             for i, l in enumerate(text.splitlines())) + f" {name};"
            else:
                line = f"    {' '.join(text.split())} {name};"
            soft = not ptr and count and base in ("u8", "s8", "char")
            fields.append([int(off, 16), elem * n if elem else None, line,
                           "pad" if kind == "pad" else "soft" if soft else "hard"])
    fields.sort(key=lambda f: f[0])
    for x, y in zip(fields, fields[1:]):  # a struct-typed member spans up to the next member
        if x[1] is None:
            x[1] = y[0] - x[0]
    return head, tail, fields


def merge_struct(old, new):
    """One struct from two layouts of it, or None when they disagree. Every member of both is
    kept; a finer member replaces a coarser one only when finer ones cover it exactly (an s32
    split into two s16); at the same offset and size the new member wins; a byte array is cut
    short at the next member; gaps become padding."""
    a, b = struct_fields(old), struct_fields(new)
    if not a or not b or a[0] != b[0] or a[1] != b[1]:
        return None
    sizes = {(f[0], f[2]): f[1] for f in a[2] + b[2] if f[1] is not None}
    for f in a[2] + b[2]:
        if f[1] is None:
            f[1] = sizes.get((f[0], f[2]))
    hard = {}
    for f in a[2] + b[2]:
        if f[3] == "hard":
            hard[(f[0], f[1])] = f
    fields = list(hard.values())
    keep = []
    for f in fields:
        inner = [g for g in fields if g is not f and None not in (f[1], g[1]) and g[1] < f[1]
                 and f[0] <= g[0] and g[0] + g[1] <= f[0] + f[1]]
        if not inner:
            keep.append(f)
            continue
        covered = set()
        for g in inner:
            covered |= set(range(g[0], g[0] + g[1]))
        if covered != set(range(f[0], f[0] + f[1])):
            return None
    starts = {f[0] for f in keep}
    soft = {}
    for f in a[2] + b[2]:
        if f[3] == "soft" and f[0] not in starts and (f[0] not in soft or f[1] < soft[f[0]][1]):
            soft[f[0]] = f
    keep += soft.values()
    keep.sort(key=lambda f: f[0])
    for i, f in enumerate(keep):
        nxt = keep[i + 1][0] if i + 1 < len(keep) else None
        if f[3] == "soft" and nxt is not None and f[0] + f[1] > nxt:
            f[1] = nxt - f[0]
            f[2] = re.sub(r"\[[^\]]*\];$", f"[0x{f[1]:X}];", f[2])
        if nxt is not None and (f[1] is None or f[0] + f[1] > nxt):
            return None
    end = max(f[0] + (f[1] or 0) for f in a[2] + b[2])
    out, pos = [a[0]], 0
    for f in keep:
        if f[0] > pos:
            out.append(f"    u8 pad{pos:X}[0x{f[0] - pos:X}];")
        out.append(f[2])
        pos = f[0] + (f[1] or 0)
    if keep and keep[-1][1] is not None and end > pos:
        out.append(f"    u8 pad{pos:X}[0x{end - pos:X}];")
    out.append(a[1])
    return "\n".join(out)


def replace_types(unit, items):
    """Items that redefine a type the unit already defines replace that definition in place
    (the new function's file extended a sibling's struct); make check then judges every user of it.
    Returns the patched unit and the items still to insert."""
    rest = []
    for item in items:
        name = type_name(item)
        old = None
        if name:
            for cand in top_level_items(unit):
                if type_name(cand) == name:
                    old = cand
                    break
        if old and old in unit:
            unit = unit.replace(old, merge_struct(old, item) or item, 1)
        else:
            rest.append(item)
    return unit, rest


def main():
    if sys.argv[1:2] == ["--normalize"]:
        for path in sorted(glob.glob(f"{ROOT}/src/**/*.c", recursive=True)):
            text = open(path, encoding="utf-8").read()
            new = normalize(text)
            if new != text:
                open(path, "w", encoding="utf-8").write(new)
                print("normalized", os.path.relpath(path, ROOT))
        return
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    func, cfile = sys.argv[1], sys.argv[2]
    path, unit, m = find_unit(func)
    decls, body = split_candidate(func, open(cfile, encoding="utf-8").read())
    norm = lambda s: re.sub(r"\s+", " ", s).strip()
    have = norm(unit)
    new = [d for d in top_level_items(decls) if norm(d) not in have]
    head, new = replace_types(unit[:m.start()], new)
    # Earlier one-line declarations of FUNC in the unit (often `extern void FUNC();` written by a
    # caller) must agree with its definition: replace them with the definition's own prototype.
    proto = re.sub(r"\s+", " ", body.split("{", 1)[0]).strip() + ";"
    # Only top-level lines (column 0, a type before the name): an indented `FUNC(a);` is a call.
    old_decl = re.compile(r"^(?:extern\s+)?[A-Za-z_][\w \t*]*[\s*]" + re.escape(func)
                          + r"\s*\([^;{}]*\)\s*;[ \t]*$", re.M)
    first = old_decl.search(head)
    if first:
        # The prototype replaces the first old declaration in place, so every type it names
        # (and the types those use) must be defined above it: candidate types go there, and
        # unit types defined further down move up.
        later = [d for d in top_level_items(head[first.end():]) if type_name(d)]
        pool = [d for d in new if type_name(d)] + later
        names, early = set(re.findall(r"\b\w+\b", proto)), []
        while True:
            more = [d for d in pool if type_name(d) in names and d not in early]
            if not more:
                break
            early += more
            for d in more:
                names |= set(re.findall(r"\b\w+\b", d))
        early = [d for d in pool if d in early]
        new = [d for d in new if d not in early]
        rest = head[first.end():]
        for d in early:
            if d in later:
                rest = rest.replace(d + "\n", "", 1) if d + "\n" in rest else rest.replace(d, "", 1)
        head = head[:first.start()] + "\n".join(early + [proto]) + rest
        head = old_decl.sub(lambda _: proto, head)
    block = ("\n".join(new) + "\n\n" if new else "") + body + "\n"
    patched = head + block + unit[m.end():]
    # The function's own strings and constants now come from its C literals, emitted at its
    # position: drop the INCLUDE_RODATA lines of every D_ symbol its asm references and the
    # candidate does not name (an `extern` use keeps the line).
    for sym in rodata_syms(func):
        if not re.search(r"\b" + sym + r"\b", decls + body):
            patched = re.sub(r'^INCLUDE_RODATA\("[^"]+",\s*' + sym + r'\);\n\n?', "", patched, flags=re.M)
    patched = normalize(patched)
    with open(path, "w", encoding="utf-8") as f:
        f.write(patched)
    if "--no-check" in sys.argv:
        print(f"{func}: written to {os.path.relpath(path, ROOT)} (not checked)")
        return
    r = subprocess.run(["make", "-s", "check"], cwd=ROOT, capture_output=True, text=True)
    if r.returncode or ": OK" not in r.stdout:
        with open(path, "w", encoding="utf-8") as f:
            f.write(unit)
        subprocess.run(["make", "-s"], cwd=ROOT, capture_output=True)
        tail = (r.stdout + r.stderr).strip().splitlines()[-12:]
        print(f"{func}: make check FAILED, {os.path.relpath(path, ROOT)} restored\n" + "\n".join(tail))
        sys.exit(1)
    print(f"{func}: integrated into {os.path.relpath(path, ROOT)}, make check OK")


if __name__ == "__main__":
    main()
