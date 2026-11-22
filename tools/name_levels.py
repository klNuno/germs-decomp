#!/usr/bin/env python3
# Licence: MIT for the code written for this project only; game-derived data and Sony names in it are excluded (LICENSING.md).
"""Confidence levels of our names, from the name audit.

    tools/name_levels.py merge OUT.tsv IN.tsv [IN.tsv ...]
    tools/name_levels.py check LEVELS.tsv
    tools/name_levels.py selftest

An audit TSV has a header line and the columns NAME KIND FILE LEVEL NEW EVIDENCE (tab separated).
KIND is func, global, type or field (FILE is then include/game/x.h:Type); LEVEL is game (seen in
the emulator), code (the code proves it), guess (plausible, unproven) or wrong (contradicted, NEW
holds the fix).

merge: one row per name; when two inputs rate the same name, the lower level wins (wrong, guess,
code, game) and the disagreement is printed. Writes OUT with the columns NAME KIND FILE LEVEL EVIDENCE and prints the counts.


check: every func and global row names a symbol of config/symbol_addrs.txt, every type row a type
defined in its FILE, every field row a member declared in the body of its struct in its FILE; every name of ours in
config/symbol_addrs.txt has a row. Exits 1 and lists what is off.
"""
import argparse
import collections
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
SYMS = ROOT / "config" / "symbol_addrs.txt"
ORDER = {"wrong": 0, "guess": 1, "code": 2, "game": 3}
KINDS = ("func", "global", "type", "field")


def read_rows(path):
    lines = pathlib.Path(path).read_text(encoding="utf-8").splitlines()
    if not lines or lines[0].split("\t")[:4] != ["NAME", "KIND", "FILE", "LEVEL"]:
        sys.exit(f"{path}: the first line must be the header NAME KIND FILE LEVEL ...")
    cols = lines[0].split("\t")
    for n, line in enumerate(lines[1:], 2):
        if not line.strip():
            continue
        row = dict(zip(cols, (c.strip() for c in line.split("\t"))))
        if row.get("KIND") not in KINDS or row.get("LEVEL") not in ORDER or not row.get("NAME"):
            sys.exit(f"{path}:{n}: bad KIND or LEVEL: {line[:120]}")
        yield row


def merge(out, inputs):
    best, clashes = {}, 0
    for path in inputs:
        for row in read_rows(path):
            key = (row["KIND"], row["NAME"], row["FILE"] if row["KIND"] in ("type", "field") else "")
            old = best.get(key)
            if old and old["LEVEL"] != row["LEVEL"]:
                clashes += 1
                print(f"clash {key[0]} {key[1]}: {old['LEVEL']} ({old['src']}) vs {row['LEVEL']} ({path})")
            if not old or ORDER[row["LEVEL"]] < ORDER[old["LEVEL"]]:
                best[key] = dict(row, src=path)
    rows = sorted(best.values(), key=lambda r: (KINDS.index(r["KIND"]), r["FILE"], r["NAME"]))
    with open(out, "w", encoding="utf-8") as f:
        f.write("NAME\tKIND\tFILE\tLEVEL\tEVIDENCE\n")
        for r in rows:
            f.write("\t".join((r["NAME"], r["KIND"], r["FILE"], r["LEVEL"], r.get("EVIDENCE", ""))) + "\n")
    count = collections.Counter((r["KIND"], r["LEVEL"]) for r in rows)
    for kind in KINDS:
        if any(k == kind for k, _ in count):
            print(kind, " ".join(f"{lv} {count[(kind, lv)]}" for lv in ORDER), sep="\t")
    print(f"{len(rows)} names, {clashes} clashes -> {out}")


def struct_bodies():
    """(file, type name) -> list of bodies (comments stripped) of the struct, union or enum it names,
    file relative to the repo root. Typedefs without a body map to an empty list."""
    out = collections.defaultdict(list)
    for path in list((ROOT / "include").rglob("*.h")) + list((ROOT / "src").rglob("*.c")):
        rel = path.relative_to(ROOT).as_posix()
        text = re.sub(r"/\*.*?\*/|//[^\n]*", " ", path.read_text(encoding="utf-8", errors="replace"), flags=re.S)
        for m in re.finditer(r"\b(?:struct|union|enum)\s*(\w*)\s*\{", text):
            depth, i = 0, m.end() - 1
            while i < len(text):
                depth += {"{": 1, "}": -1}.get(text[i], 0)
                if depth == 0:
                    break
                i += 1
            body = text[m.end():i]
            tail = re.match(r"\s*(\w+)\s*;", text[i + 1:])
            names = {m.group(1)}
            if tail and re.search(r"typedef\s+$", text[max(0, m.start() - 40):m.start()]):
                names.add(tail.group(1))
            for name in names - {""}:
                out[(rel, name)].append(body)
        for m in re.finditer(r"typedef\s+[^;{}()]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*;", text):
            out.setdefault((rel, m.group(1)), [])
        for m in re.finditer(r"typedef\s+[^;{}]*\(\s*\*\s*(\w+)\s*\)", text):
            out.setdefault((rel, m.group(1)), [])
    return out


def members(body):
    """Member names declared in a struct or union body (nested bodies included), or enumerators."""
    names = set()
    flat = body.replace("{", ";").replace("}", "; __nested ")  # "} cell;" declares the member cell
    if ";" not in flat.strip() and "," in flat:  # an enum: NAME [= value], ...
        return {m.group(1) for m in re.finditer(r"(?:^|,)\s*(\w+)", flat)}
    for decl in flat.split(";"):
        decl = re.sub(r":\s*\w+\s*$", "", decl.strip())  # bit-field width
        if not decl or decl.startswith(("struct", "union")) and "," not in decl and decl.count(" ") < 1:
            continue
        fp = re.search(r"\(\s*\*\s*(\w+)\s*\)", decl)
        if fp:
            names.add(fp.group(1))
            continue
        decl = re.sub(r"\[[^\]]*\]", "", decl)
        parts = decl.split(",")
        head = re.findall(r"\w+", parts[0])
        if len(head) >= 2:
            names.add(head[-1])
        for p in parts[1:]:
            w = re.findall(r"\w+", p)
            if w:
                names.add(w[-1])
    return names


def check(levels):
    ours = {m.group(1) for m in re.finditer(r"^(\w+) = 0x", SYMS.read_text(encoding="utf-8"), re.M)
            if not re.match(r"^(func|D|jtbl)_[0-9A-F]{8}$", m.group(1))}
    bodies, bad, seen = struct_bodies(), [], set()
    for r in read_rows(levels):
        kind, name = r["KIND"], r["NAME"]
        if kind in ("func", "global"):
            seen.add(name)
            if name not in ours:
                bad.append(f"{kind} {name}: not in config/symbol_addrs.txt")
        elif kind == "type" and (r["FILE"], name) not in bodies:
            bad.append(f"type {name}: no definition in {r['FILE']}")
        elif kind == "field":
            path, _, st = r["FILE"].rpartition(":")
            if (path, st) not in bodies:
                bad.append(f"field {st}.{name}: no type {st} in {path}")
            elif not any(name in members(b) for b in bodies[(path, st)]):
                bad.append(f"field {st}.{name}: not a member of {st} in {path}")
    bad += [f"no row for {n}" for n in sorted(ours - seen)]
    print("\n".join(bad) if bad else "every row matches the code")
    sys.exit(1 if bad else 0)


def selftest():
    """members() on the shapes the review found: nested union members, a type token, function pointers."""
    body = "s32 x; union { struct { s32 width; } cell; u16 raw[2]; } dims; void (*on_done)(void *); u8 a, *b; u32 f : 3;"
    got = members(body)
    want = {"x", "width", "cell", "raw", "dims", "on_done", "a", "b", "f"}
    ok = got == want and "u16" not in got and "s32" not in got
    print("selftest " + ("ok" if ok else "FAILED: %s" % sorted(got ^ want)))
    sys.exit(0 if ok else 1)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    m = sub.add_parser("merge")
    m.add_argument("out")
    m.add_argument("inputs", nargs="+")
    sub.add_parser("selftest")
    k = sub.add_parser("check")
    k.add_argument("levels")
    args = ap.parse_args()
    if args.cmd == "merge":
        merge(args.out, args.inputs)
    elif args.cmd == "selftest":
        selftest()
    else:
        check(args.levels)


if __name__ == "__main__":
    main()
