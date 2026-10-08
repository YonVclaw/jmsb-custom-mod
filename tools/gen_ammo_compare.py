#!/usr/bin/env python3
"""Write docs/AMMO_COMPARE.md - every futureAmmo round against the base game.

    python tools/gen_ammo_compare.py

Reads the FA configs in addons/fa_*/CfgAmmo.hpp and work/vanilla_ammo.json, and
puts each FA round next to the base game round it descends from.

WHY IT MATTERS. The tier rule says a tier 2 round must never be worse than base
game ammunition. That is only checkable if you know what the base game round
does - and it turns out FA frequently sits BELOW vanilla on raw `hit` by design,
because it differentiates through penetration, drag and special natures instead.
This table is what makes that visible per round rather than as a hunch.

RESOLVED ON BOTH SIDES. An FA round inherits from other FA rounds and finally
from a vanilla one; a vanilla round inherits too. Both chains are walked, so a
tracer variant compares on the numbers it actually has rather than the colour
it declares.

THE ANCESTOR IS THE FIRST NON-FA CLASS. That is the round the whole family is
built on, and the only fair thing to measure against.
"""
import io
import json
import math
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
VAN = os.path.join(ROOT, "work", "vanilla_ammo.json")
OUT = os.path.join(ROOT, "docs", "AMMO_COMPARE.md")

NUM = ("hit", "indirectHit", "indirectHitRange", "explosive", "caliber",
       "typicalSpeed", "airFriction")
TXT = ("warheadName", "submunitionAmmo")

CLASS_OPEN = re.compile(r"^([ \t]*)class\s+(\w+)\s*:\s*(\w+)\s*\{", re.M)
PROP = re.compile(r"^\s*(\w+)\s*=\s*(-?[0-9.eE+]+)\s*;", re.M)
TEXT = re.compile(r'^\s*(\w+)\s*=\s*"([^"]*)"\s*;', re.M)

# Compared, in this order. (key, header, higher_is_better)
COMPARE = [
    ("hit", "hit", True),
    ("indirectHit", "indHit", True),
    ("indirectHitRange", "indRange", True),
    ("explosive", "blast", True),
    ("caliber", "caliber", True),
    ("_pen", "pen", True),
    ("typicalSpeed", "speed", True),
    ("_eff", "effRange", True),
]


def body_of(text, start):
    i = text.find("{", start)
    if i < 0:
        return ""
    depth, j = 1, i + 1
    while j < len(text) and depth:
        if text[j] == "{":
            depth += 1
        elif text[j] == "}":
            depth -= 1
        j += 1
    return text[i + 1:j - 1]


def parse_fa():
    decl, base = {}, {}
    for d in sorted(os.listdir(ADDONS)):
        if not d.startswith("fa_") or d == "fa_tiers":
            continue
        p = os.path.join(ADDONS, d, "CfgAmmo.hpp")
        if not os.path.isfile(p):
            continue
        text = io.open(p, encoding="utf-8", errors="replace").read()
        for m in CLASS_OPEN.finditer(text):
            if len(m.group(1)) == 0:
                continue
            name, b = m.group(2), m.group(3)
            body = body_of(text, m.end() - 1)
            flat = re.sub(r"\{[^{}]*\}", "", body)
            props = {}
            for k, v in PROP.findall(flat):
                if k in NUM:
                    try:
                        props[k] = float(v)
                    except ValueError:
                        pass
            for k, v in TEXT.findall(flat):
                if k in TXT:
                    props[k] = v
            decl.setdefault(name, {})
            decl[name].update(props)
            base.setdefault(name, b)
    return decl, base


def eff(vals):
    for k in ("maxControlRange", "missileLockMaxDistance"):
        if vals.get(k):
            return round(float(vals[k]))
    drag = vals.get("airFriction")
    if not drag or float(drag) >= 0:
        return None
    return round(math.log(0.5) / float(drag))


def pen(vals, fa, van):
    sub = vals.get("submunitionAmmo")
    if not sub:
        return None
    if sub in fa:
        return fa[sub].get("caliber")
    if sub in van:
        return van[sub].get("caliber")
    return None


def fmt(v):
    if v is None:
        return ""
    if isinstance(v, str):
        return v
    r = round(float(v), 4)
    return str(int(r)) if r == int(r) else ("%g" % r)


def main():
    if not os.path.isfile(VAN):
        print("no %s - run tools/gen_vanilla_ammo.py first" % VAN)
        return 1
    van = json.load(io.open(VAN, encoding="utf-8"))
    decl, base = parse_fa()

    def resolve(name, seen=None):
        """FA chain first, with the vanilla ancestor's values underneath."""
        seen = seen or set()
        if name in seen:
            return {}
        seen.add(name)
        if name not in decl:
            return dict(van.get(name, {}))
        out = resolve(base.get(name, ""), seen)
        out.update(decl[name])
        return out

    def ancestor(name):
        while name in base:
            name = base[name]
        return name

    fa_res = dict((n, resolve(n)) for n in decl)

    rows = []
    stats = dict((k, {"better": 0, "worse": 0, "same": 0}) for k, _, _ in COMPARE)
    no_base = 0

    for name in sorted(decl, key=str.lower):
        a = ancestor(name)
        if a not in van:
            no_base += 1
            continue
        mine = dict(fa_res[name])
        theirs = dict(van[a])
        mine["_eff"] = eff(mine)
        mine["_pen"] = pen(mine, fa_res, van)
        theirs["_eff"] = eff(theirs)
        theirs["_pen"] = pen(theirs, fa_res, van)

        cells, any_diff = [], False
        for k, _, higher in COMPARE:
            m, t = mine.get(k), theirs.get(k)
            if m is None and t is None:
                cells.append("")
                continue
            if m is None or t is None:
                cells.append("%s / %s" % (fmt(m), fmt(t)))
                continue
            m, t = float(m), float(t)
            if abs(m - t) < 1e-6:
                stats[k]["same"] += 1
                cells.append(fmt(m))
                continue
            any_diff = True
            better = (m > t) if higher else (m < t)
            stats[k]["better" if better else "worse"] += 1
            cells.append("%s **/%s**" % (fmt(m), fmt(t)))
        if any_diff:
            rows.append((name, a, cells))

    out = [
        "# futureAmmo against the base game",
        "",
        "Every FA round that differs from the base game round it descends from.",
        "Cells read **FA / vanilla** where the two differ, and a single number",
        "where they match.",
        "",
        "Generated by `tools/gen_ammo_compare.py`. Do not hand-edit.",
        "",
        "## What this says",
        "",
        "| Property | FA higher | FA lower | same |",
        "|---|---:|---:|---:|",
    ]
    for k, h, _ in COMPARE:
        s = stats[k]
        out.append("| %s | %d | %d | %d |" % (h, s["better"], s["worse"], s["same"]))
    out += [
        "",
        "%d FA round(s) have no base game ancestor - they descend from another" % no_base,
        "mod's ammunition, and \"better or worse than base game\" has no meaning",
        "for them.",
        "",
        "**Read the `hit` row before deciding what a tier floor should be.** FA",
        "sits below vanilla on raw damage for much of the small-arms range - that",
        "is a deliberate model, not an oversight: it differentiates rounds through",
        "penetration, drag and special natures instead. Clamping a tier 2 round up",
        "to the vanilla `hit` would make it hit harder than the tier 3 round it is",
        "supposed to be a downgrade of.",
        "",
        "## Round by round (%d)" % len(rows),
        "",
        "| FA round | base game | " + " | ".join(h for _, h, _ in COMPARE) + " |",
        "|---|---|" + "---:|" * (len(COMPARE) - 1) + "---:|",
    ]
    for name, a, cells in rows:
        out.append("| `%s` | `%s` | %s |" % (name, a, " | ".join(cells)))

    io.open(OUT, "w", encoding="utf-8", newline="\r\n").write("\n".join(out) + "\n")

    print("%d FA round(s) compared, %d differ, %d had no vanilla ancestor"
          % (len(decl), len(rows), no_base))
    for k, h, _ in COMPARE:
        s = stats[k]
        print("  %-10s FA higher %4d   FA lower %4d   same %4d" % (h, s["better"], s["worse"], s["same"]))
    print("-> %s" % OUT)
    return 0


if __name__ == "__main__":
    sys.exit(main())
