#!/usr/bin/env python3
"""Replace the string literals of a candidate file with the D_ symbols that hold them.

  tools/lit2extern.py FUNC FILE.c

While other functions of the unit are still asm, a string emitted by C lands in .rodata at
the place of the C function and can break the order the INCLUDE_RODATA lines keep. Code is
the same for `"text"` and `extern char D_x[];` (lui, addiu), so the candidate uses the
extern and the string stays in its INCLUDE_RODATA file. Strings are matched by content in
the .rodata symbols of the function's unit; ASCII only (escapes as in C).
"""
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    func, path = sys.argv[1], sys.argv[2]
    asm = glob.glob(f"{ROOT}/asm/nonmatchings/**/{func}.s", recursive=True)
    if not asm:
        sys.exit(f"{func}: no asm")
    unit = os.path.dirname(asm[0])
    table = {}
    for s in glob.glob(f"{unit}/D_*.s"):
        m = re.search(r'dlabel (D_[0-9A-F]{8})\s+(?:/\*.*?\*/\s*)?\.asciz "((?:[^"\\]|\\.)*)"', open(s, encoding="utf-8").read())
        if m:
            table.setdefault(m.group(2), m.group(1))
    src = open(path, encoding="utf-8").read()
    head, sep, body = src.partition('#include "common.h"\n')
    used = []

    def sub(m):
        sym = table.get(m.group(1))
        if not sym:
            return m.group(0)
        used.append(sym)
        return sym

    out = re.sub(r'(?<![\w\'])"((?:[^"\\\n]|\\.)*)"', lambda m: m.group(0) if m.start() < 0 else sub(m), body)
    if not used:
        print(f"{func}: no literal found in the unit's rodata")
        return
    decl = "".join(f"extern char {s}[];\n" for s in dict.fromkeys(used) if f"{s}[]" not in out)
    open(path, "w", encoding="utf-8").write(head + sep + decl + out)
    print(f"{func}: {', '.join(dict.fromkeys(used))}")


if __name__ == "__main__":
    main()
