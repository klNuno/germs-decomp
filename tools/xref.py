#!/usr/bin/env python3
"""Cross-references of every symbol in asm/ (functions and data), the evidence base for naming.

  tools/xref.py NAME_OR_ADDR ...     card per symbol: unit, size, strings, callees, callers, data, users
  tools/xref.py --unit game/80185380 cards of every function in a unit
  tools/xref.py --json build/xref.json   dump the whole index
  tools/xref.py --unnamed [--unit U] list functions still called func_X with their evidence counts

Reads asm/ as splat wrote it (run `make split` first): asm/{matchings,nonmatchings}/<unit>/*.s,
asm/psyq/*.s and asm/data/**/*.s. A reference is any label token on a symbol's lines; `jal`/`j` to a
function is a call, any other function token (la, .word) is a pointer. Strings are the .asciz text of a
data label, followed one level through pointer tables.
"""
import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LABEL = re.compile(r"^\s*(glabel|dlabel)\s+(\w+)")
SIZE = re.compile(r"^\s*nonmatching\s+(\w+),\s*(0x[0-9A-Fa-f]+)")
VRAM = re.compile(r"/\*\s*(?:[0-9A-F]+\s+)?(8[0-9A-F]{7})\b")
TOKEN = re.compile(r"\b([A-Za-z_]\w*)\b")
CALL = re.compile(r"^\s*/\*.*?\*/\s*(jal|j)\s+(\w+)")
ASCIZ = re.compile(r'\.asciz\s+"((?:[^"\\]|\\.)*)"')
STRLIT = re.compile(r'"(?:[^"\\]|\\.)*"')
END = re.compile(r"^\s*(endlabel|enddlabel)\s+(\w+)")


def unit_of(path):
    rel = os.path.relpath(path, ROOT).split(os.sep)
    if rel[1] in ("matchings", "nonmatchings"):
        return "/".join(rel[2:4])
    if rel[1] == "psyq":
        return "psyq"
    if rel[1] == "data":
        return "data/" + "/".join(rel[2:])[:-2]
    return rel[1]


def parse():
    files = [p for p in glob.glob(f"{ROOT}/asm/**/*.s", recursive=True) if not p.endswith("header.s")]
    syms, lines_of = {}, {}
    for path in sorted(files):
        unit = unit_of(path)
        matched = "/matchings/" in path
        cur = None
        for line in open(path, encoding="utf-8", errors="replace"):
            m = SIZE.match(line)
            if m:
                syms.setdefault(m.group(1), {})["size"] = int(m.group(2), 16)
                continue
            m = LABEL.match(line)
            if m:
                kind, name = m.groups()
                s = syms.setdefault(name, {})
                s.update(name=name, kind="func" if kind == "glabel" else "data", unit=unit,
                         matched=matched if kind == "glabel" else None, addr=None)
                if name.startswith("jtbl_"):
                    s["kind"] = "jtbl"
                cur = name
                lines_of.setdefault(name, [])
                continue
            m = END.match(line)
            if m:
                cur = None
                continue
            if cur is None:
                continue
            if syms[cur]["addr"] is None:
                v = VRAM.search(line)
                if v:
                    syms[cur]["addr"] = int(v.group(1), 16)
            lines_of[cur].append(line)
    for name, s in syms.items():
        s.setdefault("size", None)
        calls, refs, strings = set(), set(), []
        for line in lines_of.get(name, []):
            code = line.split("*/", 1)[-1] if "*/" in line else line
            m = CALL.match(line)
            if m and m.group(2) in syms:
                calls.add(m.group(2))
            for t in TOKEN.findall(STRLIT.sub('""', code)):
                if t != name and t in syms:
                    refs.add(t)
            for a in ASCIZ.findall(code):
                if a not in strings:
                    strings.append(a)
        s["calls"] = sorted(calls)
        s["refs"] = sorted(r for r in refs if r not in calls or syms[r]["kind"] != "func")
        s["text"] = strings
    for s in syms.values():
        s["callers"], s["users"] = [], []
    for name, s in syms.items():
        for c in s["calls"]:
            syms[c]["callers"].append(name)
        for r in s["refs"]:
            syms[r]["users"].append(name)
    return syms


def strings_of(syms, s, depth=1):
    """Text the symbol reaches: its own .asciz, its data refs' text, and one level of pointer tables."""
    out = []
    for r in s["refs"]:
        d = syms[r]
        if d["kind"] != "data":
            continue
        if d["text"]:
            out.append((r, " | ".join(d["text"])))
        elif depth:
            for r2 in d["refs"]:
                d2 = syms[r2]
                if d2["kind"] == "data" and d2["text"]:
                    out.append((f"{r}->{r2}", " | ".join(d2["text"])))
    return out


def card(syms, name):
    s = syms[name]
    addr = f"0x{s['addr']:08X}" if s["addr"] else "?"
    size = f"0x{s['size']:X}" if s["size"] else "?"
    state = {True: "C", False: "asm", None: ""}[s["matched"]]
    out = [f"{name}  {addr}  {s['kind']} {size}  {s['unit']} {state}".rstrip()]
    if s["kind"] == "data" and s["text"]:
        out.append(f"  text: {' | '.join(s['text'])}")
    for r, t in strings_of(syms, s):
        out.append(f"  str {r}: {t}")
    if s["calls"]:
        out.append("  calls: " + " ".join(s["calls"]))
    fptr = [r for r in s["refs"] if syms[r]["kind"] == "func"]
    if fptr:
        out.append("  fptr: " + " ".join(fptr))
    data = [r for r in s["refs"] if syms[r]["kind"] == "data" and not syms[r]["text"]]
    if data:
        out.append("  data: " + " ".join(data))
    if s["callers"]:
        out.append(f"  callers ({len(s['callers'])}): " + " ".join(sorted(s["callers"])[:40]))
    users = [u for u in s["users"] if u not in s["callers"]]
    if users:
        out.append(f"  users ({len(users)}): " + " ".join(sorted(users)[:40]))
    return "\n".join(out)


def find(syms, key):
    if key in syms:
        return key
    try:
        a = int(key, 16)
    except ValueError:
        return None
    for n, s in syms.items():
        if s["addr"] == a and s["kind"] != "jtbl":
            return n
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*")
    ap.add_argument("--unit")
    ap.add_argument("--json")
    ap.add_argument("--unnamed", action="store_true")
    a = ap.parse_args()
    syms = parse()
    if a.json:
        with open(a.json, "w", encoding="utf-8") as f:
            json.dump(syms, f, indent=1, ensure_ascii=False)
    if a.unnamed:
        for n, s in sorted(syms.items(), key=lambda kv: kv[1]["addr"] or 0):
            if s["kind"] == "func" and n.startswith("func_") and (not a.unit or s["unit"] == a.unit):
                named = [c for c in s["calls"] if not c.startswith("func_")]
                print(f"{n} {s['unit']} size=0x{s['size'] or 0:X} strings={len(strings_of(syms, s))} "
                      f"named_calls={len(named)} callers={len(s['callers'])}")
    if a.unit:
        if not a.unnamed:
            for n, s in sorted(syms.items(), key=lambda kv: kv[1]["addr"] or 0):
                if s["kind"] == "func" and s["unit"] == a.unit:
                    print(card(syms, n))
    for key in a.names:
        n = find(syms, key)
        print(card(syms, n) if n else f"{key}: not found", file=sys.stdout if n else sys.stderr)


if __name__ == "__main__":
    main()
