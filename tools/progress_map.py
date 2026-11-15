#!/usr/bin/env python3
"""Progress map: one rectangle per function of the executable, sized by its bytes.

  tools/progress_map.py [--output docs/progress]

Writes treemap.svg and progress.json. Run it after a green `make check`: it reads
build/germs.map and build/germs.elf, and refuses a build whose sha1 is not the original.

Each function of the game (src/game) and of the developer's library (src/kaj) gets one level:
- asm: its unit still includes it as assembly (INCLUDE_ASM);
- in C: matching C, but its body still carries a name we did not choose: the func_8XXXXXXX name
  itself, a field called unk_XX, a local or parameter named by m2c (arg0, temp_s0, var_v0, sp10),
  an Unk_ type or a D_ global;
- read: matching C and every name in its body is ours.
Sony's PSY-Q libraries (linked as asm, never decompiled) get one bar below the map that shows their
share of the executable.
"""
import argparse
import datetime
import hashlib
import html
import json
import os
import pathlib
import re
import subprocess

ROOT = pathlib.Path(__file__).resolve().parent.parent
EXE = "SLPS_021.07"
LEVELS = [  # key, label, fill (one-hue ordinal ramp on the dark surface, asm the darkest)
    ("asm", "Assembly", "#34362f"),
    ("c", "In C, unknowns inside", "#3fa35a"),
    ("read", "Read: every name ours", "#8fe0a0"),
]
SONY = ("sony", "Sony library, linked as is", "#5c5b57")
SURFACE, INK, INK2, INK3 = "#1a1a19", "#f0efec", "#c3c2b7", "#8f8d84"
UNKNOWN = {
    "unk_fields": re.compile(r"(?:->|\.)\s*unk_?[0-9A-Fa-f]+\b"),
    "m2c_names": re.compile(r"\b(?:arg[0-9]+|temp_[a-z0-9_]+|var_[a-z0-9_]+|sp[0-9A-F]+)\b"),
    "unk_types": re.compile(r"\bUnk_[0-9A-F]{8}\w*"),
    "d_globals": re.compile(r"\bD_[0-9A-F]{8}\b"),
}
INCLUDE_ASM = re.compile(r'INCLUDE_ASM\("[^"]+",\s*(\w+)\)')


def sh(*cmd, env=None):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, check=True, env=env).stdout


def strip_comments(src):
    """Blank out comments and string literals, keeping offsets and newlines."""
    out = list(src)
    for m in re.finditer(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', src, re.S):
        for i in range(m.start(), m.end()):
            if out[i] != "\n":
                out[i] = " "
    return "".join(out)


def c_functions(path):
    """Map function name -> body text (comments blanked) for every definition of a C unit.

    The declarator is the last line of the text before a top-level brace that holds a parenthesis
    and does not end with a semicolon; prototypes, struct bodies and initializers are not taken."""
    code = strip_comments(path.read_text(encoding="utf-8", errors="surrogateescape"))
    funcs, depth, start, last, head = {}, 0, 0, 0, ""
    for i, ch in enumerate(code):
        if ch == "{":
            if depth == 0:
                head, start = code[last:i], i
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                tail = head.rstrip().split("\n")[-1]
                cands = [l for l in head.split("\n") if l[:1].strip() and "(" in l
                         and not l.rstrip().endswith(";") and "=" not in l.split("(")[0]]
                t = tail.rstrip()
                if cands and (t.endswith(")") or t.endswith(";")) and "=" not in t.split("(")[0]:
                    m = re.search(r"(\w+)\s*\(", cands[-1])
                    if m:
                        funcs[m.group(1)] = code[start:i + 1]
                last = i + 1
        elif ch == ";" and depth == 0:
            last = i + 1
    return funcs


def text_sections():
    """(address, size, object path) of every .text input section of the link."""
    secs = []
    for line in (ROOT / "build/germs.map").read_text().splitlines():
        m = re.match(r"^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+build/(\S+?)(?:\.c)?\.o$", line)
        if m and int(m.group(2), 16) and m.group(1).startswith("80"):
            secs.append((int(m.group(1), 16), int(m.group(2), 16), m.group(3)))
    return secs


def symbols():
    nm = next((ROOT / "tools/binutils").rglob("mipsel-linux-gnu-nm"))
    lib = next((ROOT / "tools/binutils").rglob("libopcodes-*-mipsel.so"), None)
    env = dict(os.environ)
    if lib:
        env["LD_LIBRARY_PATH"] = str(lib.parent) + os.pathsep + env.get("LD_LIBRARY_PATH", "")
    syms = {}
    for line in sh(str(nm), "-n", "--defined-only", "build/germs.elf", env=env).splitlines():
        a, t, name = line.split()[:3]
        # gcc2_compiled. and __gnu_compiled_c mark the start of each C object; local labels hold a dot
        if t in "Tt" and "." not in name and not name.startswith("__gnu_compiled"):
            syms.setdefault(int(a, 16), name)
    return syms


def sony_libraries():
    """psyq/<addr> -> its libraries, from the comments of config/splat.yaml."""
    libs = {}
    for line in (ROOT / "config/splat.yaml").read_text().splitlines():
        m = re.search(r"asm, (psyq/[0-9A-F]{8})\]\s*#\s*([A-Z0-9,]+)", line)
        if m:
            libs[m.group(1)] = m.group(2).replace(",", ", ")
    return libs


def squarify(items, x, y, w, h):
    """Squarified treemap (Bruls, Huizing, van Wijk). items: [(weight, payload)], weights > 0."""
    items = sorted(items, key=lambda it: -it[0])
    total = sum(it[0] for it in items)
    out = []
    if not items or w <= 0 or h <= 0:
        return out
    scale = w * h / total
    rest = [(wt * scale, p) for wt, p in items]

    def worst(row, side):
        s = sum(r[0] for r in row)
        return max(max(side * side * r[0] / (s * s), s * s / (side * side * r[0])) for r in row)

    while rest:
        side = min(w, h)
        row = [rest.pop(0)]
        while rest and worst(row + [rest[0]], side) <= worst(row, side):
            row.append(rest.pop(0))
        s = sum(r[0] for r in row)
        if w >= h:  # lay the row as a column on the left
            cw = s / h
            cy = y
            for a, p in row:
                ch = a / cw
                out.append((x, cy, cw, ch, p))
                cy += ch
            x, w = x + cw, w - cw
        else:
            rh = s / w
            cx = x
            for a, p in row:
                cw2 = a / rh
                out.append((cx, y, cw2, rh, p))
                cx += cw2
            y, h = y + rh, h - rh
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--output", default="docs/progress")
    args = ap.parse_args()

    want = (ROOT / f"config/{EXE}.sha1").read_text().split()[0]
    got = hashlib.sha1((ROOT / f"build/{EXE}").read_bytes()).hexdigest()
    if got != want:
        raise SystemExit(f"build/{EXE} is not the original ({got}): run make check first")
    commit = sh("git", "rev-parse", "--short", "HEAD").strip()
    dirty = bool(sh("git", "status", "--porcelain", "--untracked-files=no", "src", "include", "config").strip())

    syms = symbols()
    addrs = sorted(syms)
    bodies, in_asm = {}, set()
    for p in sorted((ROOT / "src").rglob("*.c")):
        for name, body in c_functions(p).items():
            bodies[name] = body
        in_asm |= set(INCLUDE_ASM.findall(p.read_text(encoding="utf-8", errors="surrogateescape")))

    libs = sony_libraries()
    units = []
    for start, size, obj in text_sections():
        own = obj.startswith("src/")
        inside = [a for a in addrs if start <= a < start + size]
        funcs = []
        for k, a in enumerate(inside):
            end = inside[k + 1] if k + 1 < len(inside) else start + size
            name = syms[a]
            f = {"name": name, "address": f"0x{a:08X}", "bytes": end - a}
            if own:
                if name in in_asm:
                    f["level"] = "asm"
                elif name in bodies:
                    for key, rx in UNKNOWN.items():
                        f[key] = len(set(rx.findall(bodies[name])))
                    unknowns = sum(f[key] for key in UNKNOWN)
                    f["level"] = "c" if unknowns or name.startswith("func_") else "read"
                else:
                    raise SystemExit(f"{obj}: no C definition or INCLUDE_ASM found for {name}")
            else:
                f["level"] = "sony"
            funcs.append(f)
        unit = {"unit": obj + ".c" if own else obj.replace("asm/", "") + ".s", "game": own,
                "library": obj.split("/")[1] if own else "psyq", "bytes": size, "functions": funcs}
        if not own:
            unit["libraries"] = libs.get(obj.replace("asm/", ""), "")
        units.append(unit)

    own_units = [u for u in units if u["game"]]
    gfuncs = [f for u in own_units for f in u["functions"]]
    gbytes = sum(f["bytes"] for f in gfuncs)
    sony_bytes = sum(u["bytes"] for u in units if not u["game"])
    sony_funcs = sum(len(u["functions"]) for u in units if not u["game"])
    by_level = {k: {"functions": sum(1 for f in gfuncs if f["level"] == k),
                    "bytes": sum(f["bytes"] for f in gfuncs if f["level"] == k)} for k, _, _ in LEVELS}
    by_library = {lib: {"functions": sum(len(u["functions"]) for u in own_units if u["library"] == lib),
                        "bytes": sum(u["bytes"] for u in own_units if u["library"] == lib)}
                  for lib in sorted({u["library"] for u in own_units})}
    in_c = by_level["c"]["bytes"] + by_level["read"]["bytes"]
    totals = {
        "functions": len(gfuncs), "bytes": gbytes, "bytes_in_c": in_c,
        "functions_in_c": by_level["c"]["functions"] + by_level["read"]["functions"],
        "levels": by_level, "libraries": by_library,
        "unknowns": {k: sum(f.get(k, 0) for f in gfuncs) for k in UNKNOWN},
        "sony_symbols": sony_funcs, "sony_bytes": sony_bytes,
    }
    report = {
        "schema_version": 1, "commit": commit, "tracked_tree_dirty": dirty, "exe_sha1": got,
        "metric": "Code bytes of each function (.text of the link map). asm: still INCLUDE_ASM; c: matching C "
                  "whose body still carries names we did not choose; read: matching C with only our names.",
        "totals": totals, "units": units,
    }
    out = ROOT / args.output
    out.mkdir(parents=True, exist_ok=True)
    (out / "progress.json").write_text(json.dumps(report, indent=1) + "\n")
    (out / "treemap.svg").write_text(svg(report))
    print(f"{len(gfuncs)} functions, {gbytes} bytes: in C {totals['functions_in_c']} "
          f"({100 * in_c / gbytes:.2f} % of bytes), read {by_level['read']['functions']}, "
          f"asm {by_level['asm']['functions']}; {sony_funcs} Sony symbols, {sony_bytes} bytes; "
          f"written to {args.output}/")


def svg(r):
    """The map of the game and KAJ library code, then a bar that places it in the whole executable.

    Sony's PSY-Q libraries are not drawn as rectangles: they are the SDK every PS1 game of the
    time linked, not code of this game."""
    W, H, top, pad = 1200, 820, 124, 28
    # A map regenerated for a commit cannot name that commit: an edited tree shows the date.
    stamp = datetime.date.today().isoformat() if r["tracked_tree_dirty"] else html.escape(r["commit"])
    t = r["totals"]
    lv = t["levels"]
    g = t["bytes"]
    sony = t["sony_bytes"]
    pct = lambda k: 100 * lv[k]["bytes"] / g
    in_c = 100 * t["bytes_in_c"] / g
    fill = {k: c for k, _, c in LEVELS}
    e = html.escape
    parts = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}" viewBox="0 0 {W} {H}" role="img">',
        "<title>Germs: Nerawareta Machi decompilation progress map</title>",
        "<desc>Rectangle area is code bytes. Dark: still assembly. Mid green: matching C with unknown names "
        "inside. Light green: matching C where every name is ours. The bar below places this code in the whole "
        "executable, beside Sony's libraries. Open the file to hover each function.</desc>",
        "<defs><pattern id=\"hatch\" width=\"6\" height=\"6\" patternUnits=\"userSpaceOnUse\" "
        f"patternTransform=\"rotate(45)\"><rect width=\"6\" height=\"6\" fill=\"{SONY[2]}\"/>"
        "<line x1=\"0\" y1=\"0\" x2=\"0\" y2=\"6\" stroke=\"#4a4946\" stroke-width=\"2\"/></pattern></defs>",
        f'<rect width="{W}" height="{H}" rx="16" fill="{SURFACE}"/>',
        '<g font-family="system-ui, -apple-system, Segoe UI, sans-serif">',
        f'<text x="{pad}" y="44" font-size="25" font-weight="700" fill="{INK}">Germs: Nerawareta Machi · decompilation</text>',
        f'<text x="{pad}" y="72" font-size="14" fill="{INK2}">{EXE} rebuilt byte for byte · {stamp} · {t["functions"]:,} functions, '
        f'{g:,} code bytes</text>',
        f'<text x="{W - pad}" y="44" text-anchor="end" font-size="30" font-weight="700" fill="{INK}">'
        f'{in_c:.1f}% in C</text>',
        f'<text x="{W - pad}" y="72" text-anchor="end" font-size="14" fill="{INK2}">'
        f'{t["functions_in_c"]:,} of {t["functions"]:,} functions match from C</text>',
    ]
    lx = pad
    for k, lab, c in LEVELS:
        lab = f"{lab} {pct(k):.1f}%"
        parts.append(f'<rect x="{lx}" y="92" width="12" height="12" rx="2" fill="{c}" stroke="{INK3}" stroke-width="0.5"/>')
        parts.append(f'<text x="{lx + 19}" y="103" font-size="14" fill="{INK}">{e(lab)}</text>')
        lx += 19 + 7.6 * len(lab) + 26
    bar_h, foot = 30, 64
    bx, by, bw = pad, top, W - 2 * pad
    bh = H - top - foot - bar_h - 34
    placed = squarify([(u["bytes"], u) for u in r["units"] if u["game"]], bx, by, bw, bh)
    labels = []
    names = dict((k, l) for k, l, _ in LEVELS)
    for ux, uy, uw, uh, u in placed:
        inner = [(f["bytes"], f) for f in u["functions"] if f["bytes"] > 0]
        ulab = "/".join(pathlib.Path(u["unit"]).parts[-2:])
        for fx, fy, fw, fh, f in squarify(inner, ux, uy, uw, uh):
            tip = f'{f["name"]} · {f["address"]} · {f["bytes"]} bytes · {ulab} · {names[f["level"]]}'
            if f["level"] != "asm":
                tip += (f' · unknown fields {f["unk_fields"]}, m2c names {f["m2c_names"]},'
                        f' Unk_ types {f["unk_types"]}, D_ globals {f["d_globals"]}')
            parts.append(f'<rect x="{fx:.2f}" y="{fy:.2f}" width="{fw:.2f}" height="{fh:.2f}" fill="{fill[f["level"]]}" '
                         f'stroke="{SURFACE}" stroke-width="0.6"><title>{e(tip)}</title></rect>')
        parts.append(f'<rect x="{ux:.2f}" y="{uy:.2f}" width="{uw:.2f}" height="{uh:.2f}" fill="none" '
                     f'stroke="{SURFACE}" stroke-width="2.5"><title>{e(u["unit"])}</title></rect>')
        for lab in (ulab, pathlib.Path(ulab).name, pathlib.Path(ulab).stem):
            if uw > 7.2 * len(lab) + 18 and uh > 30:
                labels.append((ux, uy, lab))
                break
    for ux, uy, ulab in labels:
        tw = 7.2 * len(ulab) + 14
        parts.append(f'<rect x="{ux + 5:.2f}" y="{uy + 5:.2f}" width="{tw:.0f}" height="21" rx="4" '
                     f'fill="{SURFACE}" fill-opacity="0.82"/>')
        parts.append(f'<text x="{ux + 12:.2f}" y="{uy + 20:.2f}" font-size="12.5" fill="{INK}">{e(ulab)}</text>')
    # the whole executable: the code drawn above, then Sony's libraries
    yb = by + bh + 34
    gw = bw * g / (g + sony)
    cw = gw * t["bytes_in_c"] / g
    libs = sorted({l.strip() for u in r["units"] if not u["game"] for l in u.get("libraries", "").split(",") if l.strip()})
    parts.append(f'<text x="{pad}" y="{yb - 9}" font-size="13" fill="{INK2}">The whole executable\'s code</text>')
    parts.append(f'<rect x="{bx}" y="{yb}" width="{gw - 2:.2f}" height="{bar_h}" rx="4" fill="{fill["asm"]}" '
                 f'stroke="{INK3}" stroke-width="0.5"/>')
    parts.append(f'<rect x="{bx}" y="{yb}" width="{cw:.2f}" height="{bar_h}" rx="4" fill="{fill["c"]}"/>')
    parts.append(f'<text x="{bx + 12}" y="{yb + 20}" font-size="13.5" font-weight="600" fill="{INK}">'
                 f'Game and KAJ library {100 * g / (g + sony):.0f}%: {in_c:.0f}% of it in C, mapped above</text>')
    parts.append(f'<rect x="{bx + gw + 2:.2f}" y="{yb}" width="{bw - gw - 2:.2f}" height="{bar_h}" rx="4" fill="url(#hatch)">'
                 f'<title>Sony libraries linked as is: {e(", ".join(libs))}</title></rect>')
    parts.append(f'<rect x="{bx + gw + 8:.2f}" y="{yb + 5}" width="{bw - gw - 14:.2f}" height="{bar_h - 10}" rx="3" '
                 f'fill="{SURFACE}" fill-opacity="0.82"/>')
    parts.append(f'<text x="{bx + gw + 16:.2f}" y="{yb + 20}" font-size="13" fill="{INK}">Sony PSY-Q '
                 f'{100 * sony / (g + sony):.0f}%: stock libraries</text>')
    u = t["unknowns"]
    parts.append(f'<text x="{pad}" y="{H - 34}" font-size="13" fill="{INK2}">Area = code bytes · open the file to hover '
                 f'a function · still to name: {u["unk_fields"]} unknown fields, '
                 f'{u["m2c_names"]} m2c locals, {u["unk_types"]} Unk_ types, {u["d_globals"]} D_ globals</text>')
    parts.append(f'<text x="{pad}" y="{H - 15}" font-size="12" fill="{INK3}">Every byte already rebuilds; dark '
                 f'rectangles still come from assembly. Sony\'s libraries are shared by every PS1 game of the '
                 f'time and stay as Sony shipped them.</text>')
    parts.append("</g></svg>")
    return "\n".join(parts) + "\n"


if __name__ == "__main__":
    main()
