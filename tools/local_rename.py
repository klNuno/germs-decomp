#!/usr/bin/env python3
# Licence: MIT for klNuno's own code only; game-derived data and Sony names in it are excluded (LICENSING.md).
"""Rename parameters and locals of one function, with evidence.

    tools/local_rename.py LOCALS.tsv [--dry-run]

LOCALS.tsv: one rename per line, tab separated: FILE, FUNCTION, OLD, NEW, evidence (more columns are
ignored). Blank lines and lines starting with # are skipped. FILE may be a bare name (pad.c); it is
looked up under src/.

Each rename rewrites OLD as a whole word inside the definition of FUNCTION only: its parameter list,
its K&R declarations and its body, comments included, but never inside a string or character literal
or in a member access (`->OLD`, `.OLD`, spaces allowed): a field may share the name. It refuses a
rename when FUNCTION is not defined once in FILE, when OLD does not appear in it, or when NEW is
already a word of it outside member accesses (a local, a global, a call). Local names never change the code, so after it: tools/unit_check.sh on every file
touched, then make check.
"""
import argparse
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


LITERAL = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'')
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)


def blank(text, comments):
    """text with string and character literals (and comments if asked) replaced by spaces, same length."""
    keep_nl = lambda m: re.sub(r"[^\n]", " ", m.group(0))
    if comments:
        pat = re.compile(COMMENT.pattern + "|" + LITERAL.pattern, re.S)
    else:
        pat = re.compile(LITERAL.pattern + "|" + COMMENT.pattern, re.S)
        # comments are matched so a quote inside one starts no literal, then put back below
        out, last = [], 0
        for m in pat.finditer(text):
            out.append(text[last:m.start()])
            out.append(m.group(0) if m.group(0).startswith("/") else keep_nl(m))
            last = m.end()
        out.append(text[last:])
        return "".join(out)
    return pat.sub(keep_nl, text)


def function_span(text, func):
    """(start, end) of FUNCTION's definition: from its declarator line to its closing brace. Braces in
    comments and literals are not counted."""
    code = blank(text, comments=True)
    spans = []
    for m in re.finditer(r"^[A-Za-z_][^;{}\n]*\b" + re.escape(func) + r"\s*\(", code, re.M):
        i = code.find("{", m.end())
        head = code[m.end():i]
        if i < 0 or re.search(r";\s*$", head.split("\n")[0]) or ";" in head.split(")")[0]:
            continue  # a prototype, not a definition
        depth, j = 0, i
        while j < len(code):
            if code[j] == "{":
                depth += 1
            elif code[j] == "}":
                depth -= 1
                if depth == 0:
                    spans.append((m.start(), j + 1))
                    break
            j += 1
    return spans


def uses(body, w):
    """Start offsets of w as a whole word in body, outside literals and member accesses
    (`->w`, `.w`, with or without spaces); comments count."""
    code = blank(body, comments=False)
    out = []
    for m in re.finditer(r"(?<![\w])" + re.escape(w) + r"\b", code):
        before = code[:m.start()].rstrip()
        if before.endswith("->") or before.endswith("."):
            continue
        out.append(m.start())
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("tsv")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    rows = []
    for n, line in enumerate(pathlib.Path(args.tsv).read_text().splitlines(), 1):
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        cols = [c.strip() for c in line.split("\t")]
        if len(cols) < 5 or not cols[4]:
            sys.exit(f"{args.tsv}:{n}: need FILE FUNCTION OLD NEW evidence (tabs)")
        f, func, old, new = cols[:4]
        if not all(IDENT.match(x) for x in (func, old, new)):
            sys.exit(f"{args.tsv}:{n}: not an identifier")
        path = ROOT / f if "/" in f else next(iter(sorted((ROOT / "src").rglob(f))), None)
        if path is None or not path.exists():
            sys.exit(f"{args.tsv}:{n}: no file {f}")
        rows.append((n, path, func, old, new))

    texts, touched, done = {}, set(), 0
    for n, path, func, old, new in rows:
        text = texts.setdefault(path, path.read_text(encoding="utf-8", errors="surrogateescape"))
        spans = function_span(text, func)
        if len(spans) != 1:
            sys.exit(f"{args.tsv}:{n}: {func} defined {len(spans)} times in {path.relative_to(ROOT)}")
        a, b = spans[0]
        body = text[a:b]
        hits = uses(body, old)
        if not hits:
            sys.exit(f"{args.tsv}:{n}: {old} does not appear in {func}")
        if uses(body, new):
            sys.exit(f"{args.tsv}:{n}: {new} is already used in {func}")
        for h in reversed(hits):
            body = body[:h] + new + body[h + len(old):]
        texts[path] = text[:a] + body + text[b:]
        touched.add(path)
        done += 1
    if not args.dry_run:
        for path in touched:
            path.write_text(texts[path], encoding="utf-8", errors="surrogateescape")
    print(f"{done} renames in {len(touched)} files" + (" (dry run, nothing written)" if args.dry_run else
          "; now tools/unit_check.sh on: " + " ".join(str(p.relative_to(ROOT)) for p in sorted(touched))))


if __name__ == "__main__":
    main()
