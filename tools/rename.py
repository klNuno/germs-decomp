#!/usr/bin/env python3
# Licence: MIT for klNuno's own code only; game-derived data and Sony names in it are excluded (LICENSING.md).
"""Give symbols their names: config/symbol_addrs.txt plus every use in src/, include/ and work/.

  tools/rename.py NAMES_FILE [--dry-run] [--check]

NAMES_FILE holds one rename per line, `OLD NEW`, and the evidence on `#` lines just above it; the evidence
becomes the `//` comment over the new line in config/symbol_addrs.txt (a name needs evidence, so a rename
with no `#` line is refused). OLD is a splat name (func_X, D_X) or a name given earlier, or a struct type
(`Unk_X` or a type named earlier, prefixed `type:` as in `type:Unk_801E0368 TimeBlock`): a type exists only in the
sources, so it is renamed there and its evidence stays in the names file. --check runs
`make split` then `make check` afterwards. Reads build/xref.json (tools/xref.py --json build/xref.json)
for addresses and kinds; writes it again when the split ran.
"""
import argparse
import glob
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SYMS = os.path.join(ROOT, "config/symbol_addrs.txt")
XREF = os.path.join(ROOT, "build/xref.json")
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
LITERAL = re.compile(r'"(?:[^"\\\n]|\\.)*"|\'(?:[^\'\\\n]|\\.)*\'')
C_KEYWORDS = set("""auto break case char const continue default do double else enum extern float for goto if inline
int long register return short signed sizeof static struct switch typedef union unsigned void volatile while
asm""".split())
TYPES = set()  # OLD names given as `type:OLD`: source-only renames
RESERVED = re.compile(r"^(func|D|jtbl|Unk|unk|pad|sub|lbl|L)_[0-9A-Fa-f]+$")


def load_names(path):
    renames, evidence = [], []
    for n, line in enumerate(open(path, encoding="utf-8"), 1):
        line = line.strip()
        if not line:
            evidence = []
            continue
        if line.startswith("#"):
            evidence.append(line[1:].strip())
            continue
        parts = line.split()
        if len(parts) == 2 and parts[0].startswith("type:"):
            parts[0] = parts[0][5:]
            if not parts[0]:
                sys.exit(f"{path}:{n}: empty type name")
            TYPES.add(parts[0])
        if len(parts) != 2:
            sys.exit(f"{path}:{n}: expected `OLD NEW`, got {line!r}")
        if not evidence:
            sys.exit(f"{path}:{n}: {parts[0]} -> {parts[1]} has no evidence line above it")
        renames.append((parts[0], parts[1], " ".join(evidence)))
        evidence = []
    return renames


def source_identifiers():
    """Every identifier the C sources and headers use outside literals: types, macros, locals, fields."""
    ids = set()
    for pat in ("src/**/*.c", "src/**/*.h", "include/**/*.h"):
        for path in glob.glob(os.path.join(ROOT, pat), recursive=True):
            body = LITERAL.sub("", open(path, encoding="utf-8", errors="surrogateescape").read())
            ids.update(re.findall(r"\b[A-Za-z_]\w*\b", body))
    return ids


def validate(renames, xref):
    ids = source_identifiers()
    taken = set(xref) | ids
    seen_old, seen_new = set(), set()
    for old, new, ev in renames:
        if old in TYPES:
            if old not in ids:
                sys.exit(f"{old}: type not found in src/ or include/")
        elif old not in xref:
            sys.exit(f"{old}: unknown symbol (stale build/xref.json? run tools/xref.py --json build/xref.json)")
        if not IDENT.match(new) or RESERVED.match(new) or new in C_KEYWORDS:
            sys.exit(f"{new}: not a C identifier or looks like a placeholder name")
        if new in taken or new in seen_new:
            sys.exit(f"{new}: name already used")
        if old in seen_old:
            sys.exit(f"{old}: renamed twice")
        if old not in TYPES and xref[old]["addr"] is None:
            sys.exit(f"{old}: no address in xref")
        seen_old.add(old)
        seen_new.add(new)


def update_config(renames, xref, dry):
    text = open(SYMS, encoding="utf-8").read()
    added = []
    for old, new, ev in renames:
        if old in TYPES:
            continue
        line_re = re.compile(rf"^((?://.*\n)*){re.escape(old)}(\s*=)", re.M)
        if line_re.search(text):
            # a given name: its old evidence goes with it; a bare splat split keeps its comments
            keep = (lambda m: "") if not RESERVED.match(old) else (lambda m: m.group(1))
            text = line_re.sub(lambda m: f"{keep(m)}// {ev}\n{new}{m.group(2)}", text, count=1)
            continue
        s = xref[old]
        attrs = "type:func" if s["kind"] == "func" else ""
        if s["kind"] == "func" and s.get("size"):
            attrs += f" size:0x{s['size']:X}"
        tail = f" // {attrs}" if attrs else ""
        added.append(f"// {ev}\n{new} = 0x{s['addr']:08X};{tail}")
    if added:
        if not text.endswith("\n"):
            text += "\n"
        text += "\n".join(added) + "\n"
    if not dry:
        open(SYMS, "w", encoding="utf-8").write(text)


def update_sources(renames, dry):
    files = []
    # RENAME_EXTRA_GLOBS: more globs to rename in, separated by spaces (private notes kept outside git)
    extra = tuple(os.environ.get("RENAME_EXTRA_GLOBS", "").split())
    for pat in ("src/**/*.c", "src/**/*.h", "include/**/*.h", "work/*.wip.c", "work/*.wip.gte",
                "docs/**/*.md", "README.md") + extra:
        files += glob.glob(os.path.join(ROOT, pat), recursive=True)
    table = {old: new for old, new, _ in renames}
    word = re.compile(r"\b(" + "|".join(map(re.escape, table)) + r")\b")
    # in C, a comment is renamed inside, a string or char literal is kept as it is; prose renames everywhere
    c_word = re.compile(r"(/\*.*?\*/|//[^\n]*)|" + LITERAL.pattern + r"|" + word.pattern.replace("(", "(?P<w>", 1),
                        re.S)
    changed = 0
    for path in files:
        body = open(path, encoding="utf-8", errors="surrogateescape").read()
        if path.endswith(".md") or path.endswith(".txt"):
            new_body = word.sub(lambda m: table[m.group(1)], body)
        else:
            new_body = c_word.sub(lambda m: table[m.group("w")] if m.group("w") else
                                  word.sub(lambda w: table[w.group(1)], m.group(1)) if m.group(1) else m.group(0), body)
        if new_body != body:
            changed += 1
            if not dry:
                open(path, "w", encoding="utf-8", errors="surrogateescape").write(new_body)
    return changed


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args()
    xref = json.load(open(XREF, encoding="utf-8"))
    renames = load_names(a.names)
    validate(renames, xref)
    update_config(renames, xref, a.dry_run)
    n = update_sources(renames, a.dry_run)
    print(f"{len(renames)} renames, {n} source files {'would change' if a.dry_run else 'changed'}")
    if a.check and not a.dry_run:
        py = os.path.join(ROOT, ".venv/bin/python")
        for cmd in (["make", "split"], ["make", "check"]):
            r = subprocess.run(cmd, cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            if r.returncode:
                sys.stdout.write(r.stdout[-3000:])
                sys.exit(f"{' '.join(cmd)} failed")
        print(r.stdout.strip().splitlines()[-1])
        subprocess.run([py, "tools/xref.py", "--json", XREF], cwd=ROOT, stdout=subprocess.DEVNULL, check=True)


if __name__ == "__main__":
    main()
