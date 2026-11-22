#!/usr/bin/env python3
# Licence: MIT for the code written for this project only; game-derived data and Sony names in it are excluded (LICENSING.md).
"""Rename struct fields with evidence, everywhere the compiler says they are used.

    tools/field_rename.py FIELDS.tsv [--dry-run] [--units src/game/X.c ...]

FIELDS.tsv: one rename per line, tab separated: FILE, STRUCT, OLD, NEW, evidence.
FILE is the header or unit that defines `typedef struct STRUCT { ... } STRUCT;` (or `struct STRUCT {`).
Blank lines and lines starting with # are skipped.

How it works: it renames the member in the struct's definition, then compiles every C unit of
src/ with the game's own toolchain (make print-* gives the exact commands) and reads cc1's
"structure has no member named `OLD'" errors: each one names a file and a line that accesses the
renamed member, and only that line's `->OLD` / `.OLD` is rewritten. It repeats until no such
error is left. A line where OLD appears more than once is searched by subsets of its accesses
until it compiles, unless NEW is already a member of some struct (then a wrong subset could
compile, so it stops). An error it cannot place stops it with a report, leaving the tree as it was. Field names never change the code, so after it:
tools/unit_check.sh on every unit, then make check.

--units limits the compiles to the units given, for types defined in those units only (a struct
local to a .c file cannot be reached from another unit), so several workers can rename local
types in different units at once. A FILE outside the units given is refused.
"""
import argparse
import pathlib
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = pathlib.Path(__file__).resolve().parent.parent
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
ERR = re.compile(r"^(?P<file>[^:]+):(?P<line>\d+): (?:structure|union) has no member named `(?P<name>\w+)'")


def make_var(name):
    return subprocess.run(["make", "-s", f"print-{name}"], cwd=ROOT, capture_output=True, text=True, check=True).stdout.strip()


def struct_block(text, struct):
    """Return (start, end) of the braces body of struct STRUCT in text: `struct STRUCT {`, or an
    anonymous `typedef struct { ... } STRUCT;`."""
    def close(open_end):
        depth, i = 0, open_end - 1
        while i < len(text):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    return i
            i += 1
        return None

    m = re.search(r"(?:typedef\s+)?struct\s+" + re.escape(struct) + r"\s*\{", text)
    if m:
        end = close(m.end())
        return (m.end(), end) if end is not None else None
    tail = re.compile(r"\}\s*" + re.escape(struct) + r"\s*;")
    for m in re.finditer(r"typedef\s+struct\s*\{", text):
        end = close(m.end())
        if end is not None and tail.match(text, end):
            return m.end(), end
    return None


def member_names(names):
    """Return the subset of names that appear as a word in some struct or union body in src/ or
    include/ (comments stripped): a member of any declarator form, or a type name used there."""
    found = set()
    for path in list((ROOT / "src").rglob("*.[ch]")) + list((ROOT / "include").rglob("*.h")):
        text = re.sub(r"/\*.*?\*/|//[^\n]*", " ", path.read_text(errors="surrogateescape"), flags=re.S)
        for m in re.finditer(r"\b(?:struct|union)\b[^;{}()]*\{", text):
            depth, i = 1, m.end()
            while i < len(text) and depth:
                depth += {"{": 1, "}": -1}.get(text[i], 0)
                i += 1
            body = text[m.end():i - 1]
            for n in names - found:
                # any whole-word use in a struct body counts (plain members, arrays, bit-fields,
                # function pointers): a false collision only asks for a hand fix, a missed one
                # would let a wrong rewrite compile
                if re.search(r"\b" + re.escape(n) + r"\b", body):
                    found.add(n)
    return found


def compile_errors(units, cmds):
    cpp, cppflags, cc1, cflags = cmds
    errs = []
    for u in units:
        # both stages must succeed: pipefail makes a cpp failure count, and an exit code with no
        # message this tool understands is reported, never taken as a clean compile
        p = subprocess.run(["bash", "-c", f"set -o pipefail; {cpp} {cppflags} {u} | {cc1} {cflags} -quiet -o /dev/null"],
                           cwd=ROOT, capture_output=True, text=True)
        found = 0
        for line in p.stderr.splitlines():
            m = ERR.match(line)
            if m:
                errs.append((m.group("file"), int(m.group("line")), m.group("name")))
                found += 1
            elif re.match(r"^[^:]+:\d+: ", line) and "warning" not in line:
                errs.append((u, 0, "OTHER " + line))
                found += 1
        if p.returncode != 0 and not found:
            tail = " | ".join(p.stderr.strip().splitlines()[-3:]) or "no message"
            errs.append((u, 0, f"OTHER exit {p.returncode}: {tail}"))
    return errs


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("fields")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--units", nargs="+", metavar="UNIT", help="compile only these .c units (local types)")
    args = ap.parse_args()

    rows = []
    for n, line in enumerate(pathlib.Path(args.fields).read_text().splitlines(), 1):
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        cols = [c.strip() for c in line.split("\t")]
        if len(cols) < 5 or not cols[4]:
            sys.exit(f"{args.fields}:{n}: need FILE STRUCT OLD NEW evidence (tabs)")
        f, st, old, new, ev = cols[:5]
        if not all(IDENT.match(x) for x in (st, old, new)):
            sys.exit(f"{args.fields}:{n}: not an identifier")
        rows.append((f, st, old, new, ev))

    units = sorted(str(p.relative_to(ROOT)) for p in (ROOT / "src").rglob("*.c"))
    if args.units:
        given = sorted({str((ROOT / u).resolve().relative_to(ROOT)) for u in args.units})
        if not set(given) <= set(units):
            sys.exit(f"--units: not a C unit of src/: {sorted(set(given) - set(units))}")
        outside = sorted({r[0] for r in rows} - set(given))
        if outside:
            sys.exit(f"--units: a FILE of the batch is not among the units given: {outside}")
        units = given
    cmds = (make_var("CPP"), make_var("CPPFLAGS"), make_var("CC1"), make_var("CFLAGS"))
    before = compile_errors(units, cmds)
    if before:
        sys.exit("the tree does not compile cleanly before the renames:\n" + "\n".join(map(str, before[:10])))

    backup = pathlib.Path(tempfile.mkdtemp(prefix="field_rename."))
    touched = set()

    def save(path):
        if path not in touched:
            dst = backup / path
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / path, dst)
            touched.add(path)

    def restore():
        for path in touched:
            shutil.copy2(backup / path, ROOT / path)

    # NEW names that some struct already has (before the renames): a line with several accesses of
    # OLD cannot be told apart by compiling (a->old + b->old -> a->new + b->new compiles when b's
    # struct has both), so such a line is refused instead of searched
    taken = member_names({r[3] for r in rows})

    # 1. definitions
    renamed = {}  # old name -> set of new names (to map errors back)
    for f, st, old, new, ev in rows:
        path = ROOT / f
        text = path.read_text(errors="surrogateescape")
        blk = struct_block(text, st)
        if blk is None:
            restore()
            sys.exit(f"{f}: struct {st} not found")
        body = text[blk[0]:blk[1]]
        code = re.sub(r"/\*.*?\*/|//[^\n]*", " ", body, flags=re.S)  # a comment may say the new name
        if re.search(r"\b" + re.escape(new) + r"\b", code):
            restore()
            sys.exit(f"{f}: struct {st} already has a member {new}")
        # rename the member in code only: comments of the struct may mention the old name
        parts = re.split(r"(/\*.*?\*/|//[^\n]*)", body, flags=re.S)
        k = 0
        for i in range(0, len(parts), 2):
            parts[i], n = re.subn(r"\b" + re.escape(old) + r"\b", new, parts[i])
            k += n
        nb = "".join(parts)
        if k != 1:
            restore()
            sys.exit(f"{f}: struct {st}: member {old} found {k} times")
        save(f)
        path.write_text(text[:blk[0]] + nb + text[blk[1]:], errors="surrogateescape")
        renamed.setdefault(old, []).append(new)
    print(f"{len(rows)} member definitions renamed")

    # 2. accesses, driven by the compiler
    fixed = 0
    multi = {}
    for rnd in range(200):
        errs = compile_errors(units, cmds)
        retried = set()
        for file, ln, name in errs:
            rel = str(pathlib.Path(file).resolve().relative_to(ROOT)) if file.startswith("/") else file
            if (rel, ln) in multi and (rel, ln) not in retried and name in multi[(rel, ln)][1:3]:
                # a line with several accesses: try the next subset of them to rename
                orig, oname, onew, mask, n = multi[(rel, ln)]
                if mask <= 1:
                    restore()
                    sys.exit(f"{rel}:{ln}: several accesses on this line, no subset compiles: fix it by hand")
                mask -= 1
                multi[(rel, ln)] = (orig, oname, onew, mask, n)
                k = iter(range(n))
                line = re.sub(r"((?:->|\.)\s*)" + re.escape(oname) + r"\b",
                              lambda m: m.group(1) + (onew if (mask >> next(k)) & 1 else oname), orig)
                path = ROOT / rel
                lines = path.read_text(errors="surrogateescape").split("\n")
                lines[ln - 1] = line
                path.write_text("\n".join(lines), errors="surrogateescape")
                retried.add((rel, ln))
        if retried:
            continue
        other = [e for e in errs if e[2].startswith("OTHER")]
        miss = [e for e in errs if not e[2].startswith("OTHER")]
        if other and not miss:
            restore()
            sys.exit("compile errors that are not renamed members:\n" + "\n".join(e[2] for e in other[:10]))
        if not miss:
            break
        for file, ln, name in sorted(set(miss)):
            if name not in renamed or len(renamed[name]) != 1:
                restore()
                sys.exit(f"{file}:{ln}: `{name}' is renamed in several structs of this batch, or not in it: split the batch")
            new = renamed[name][0]
            rel = str(pathlib.Path(file).resolve().relative_to(ROOT)) if file.startswith("/") else file
            path = ROOT / rel
            lines = path.read_text(errors="surrogateescape").split("\n")
            src = lines[ln - 1]
            hits = re.findall(r"(?:->|\.)\s*" + re.escape(name) + r"\b", src)
            if not hits:
                restore()
                sys.exit(f"{rel}:{ln}: no access of {name} found on the line cc1 names:\n  {src.strip()}")
            if len(hits) > 1 and new in taken:
                restore()
                sys.exit(f"{rel}:{ln}: several accesses of {name} on this line and `{new}' is already a member "
                         f"of another struct, so a wrong subset could compile: fix it by hand\n  {src.strip()}")
            if len(hits) > 1:
                # all of them are rewritten first; if one belonged to another struct, the next round
                # reports an error on this line and the next subset is tried
                multi[(rel, ln)] = (src, name, new, (1 << len(hits)) - 1, len(hits))
            save(rel)
            lines[ln - 1] = re.sub(r"((?:->|\.)\s*)" + re.escape(name) + r"\b", r"\g<1>" + new, src)
            path.write_text("\n".join(lines), errors="surrogateescape")
            fixed += 1
    else:
        restore()
        sys.exit("still failing after 200 rounds")
    print(f"{fixed} accesses rewritten in {len(touched)} files")
    if args.dry_run:
        restore()
        print("dry run: tree restored")
    else:
        print("now run tools/unit_check.sh on every unit, then make check")
    shutil.rmtree(backup, ignore_errors=True)


if __name__ == "__main__":
    main()
