#!/usr/bin/env python3
"""Index the base game's CfgAmmo lethality figures.

    python tools/gen_vanilla_ammo.py [--a3 "D:/Dropbox/Documents/Arma 3 Projects/a3"]

Writes work/vanilla_ammo.json: {class: {hit, indirectHit, indirectHitRange,
caliber}} for every base game ammo class, resolved through its inheritance
chain so a class that inherits `hit` still reports the number it actually has.

WHY THIS EXISTS. The tier rule is that a tier 2 round must never be worse than
base game ammunition, and until now there was no way to check that outside a
running mission - the engine's config is not a file this repo could read. The
unpacked A3 tree is, and it is the same data.

RESOLVED, NOT DECLARED. Vanilla ammo inherits heavily: B_556x45_Ball_Tracer_Red
declares a tracer colour and gets its hit from B_556x45_Ball. Reporting only
declared values would say the tracer round has no lethality at all.
"""
import argparse
import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "work", "vanilla_ammo.json")

# The four the tier generator scales...
SCALED = ("hit", "indirectHit", "indirectHitRange", "caliber")

# ...and the rest of what makes a round what it is, for the reference table.
# Speed and drag are the ballistics; explosive and warheadName say what happens
# on arrival. Together with SCALED that is enough to compare any two rounds
# without opening the game.
EXTRA = ("typicalSpeed", "airFriction", "explosive", "deflecting",
         # Guided rounds carry their own reach; a bullet does not.
         "maxControlRange", "missileLockMaxDistance", "maxSpeed")
# THE PENETRATION OF AN AT ROUND IS NOT ON THE AT ROUND. A HEAT warhead spawns
# a penetrator submunition and THAT carries the caliber that defeats armour -
# the parent's own caliber describes the shell body. Following the reference is
# the difference between "caliber 4" and the 200-odd the jet actually punches.
TEXT_PROPS = ("warheadName", "submunitionAmmo")
ALL_PROPS = SCALED + EXTRA

CLASS_OPEN = re.compile(r"^([ \t]*)class\s+(\w+)\s*:\s*(\w+)\s*$", re.M)
CLASS_OPEN_BRACE = re.compile(r"^([ \t]*)class\s+(\w+)\s*:\s*(\w+)\s*\{", re.M)
PROP = re.compile(r"^\s*(\w+)\s*=\s*(-?[0-9.eE+]+)\s*;", re.M)
TEXT = re.compile(r'^\s*(\w+)\s*=\s*"([^"]*)"\s*;', re.M)


def body_of(text, start):
    """Text between the brace that opens at/after `start` and its match."""
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


def scan(text, out_decl, out_base):
    """Collect ammo classes from one CfgAmmo block."""
    m = re.search(r"^\s*class CfgAmmo\s*$|^\s*class CfgAmmo\s*\{", text, re.M)
    if not m:
        return
    block = body_of(text, m.start())

    for pat in (CLASS_OPEN_BRACE, CLASS_OPEN):
        for cm in pat.finditer(block):
            name, base = cm.group(2), cm.group(3)
            body = body_of(block, cm.end() - 1 if pat is CLASS_OPEN_BRACE else cm.end())
            flat = re.sub(r"\{[^{}]*\}", "", body)
            props = {}
            for k, v in PROP.findall(flat):
                if k in ALL_PROPS:
                    try:
                        props[k] = float(v)
                    except ValueError:
                        pass
            for k, v in TEXT.findall(flat):
                if k in TEXT_PROPS:
                    props[k] = v
            # ACCUMULATE, DO NOT FIRST-WIN. A class is defined in one addon and
            # patched in others - sounds_f re-opens M_Titan_AT to attach a firing
            # sound and declares no lethality at all. Taking the first definition
            # seen recorded that empty patch and threw away the real numbers in
            # weapons_f, which is how the Titan came out of the index with no hit.
            out_decl.setdefault(name, {})
            out_decl[name].update(props)
            out_base.setdefault(name, base)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--a3", default=r"D:\Dropbox\Documents\Arma 3 Projects\a3")
    args = ap.parse_args()

    if not os.path.isdir(args.a3):
        print("no %s" % args.a3)
        return 1

    decl, base = {}, {}
    files = 0
    with os.scandir(args.a3) as it:
        for e in it:
            if not e.is_dir():
                continue
            p = os.path.join(e.path, "config.cpp")
            if not os.path.isfile(p):
                continue
            try:
                text = io.open(p, encoding="utf-8", errors="replace").read()
            except OSError:
                continue
            if "CfgAmmo" not in text:
                continue
            scan(text, decl, base)
            files += 1

    # Resolve up the chain, so an inherited hit is still a hit.
    def resolve(name, seen=None):
        seen = seen or set()
        if name in seen or name not in decl:
            return {}
        seen.add(name)
        out = dict(resolve(base.get(name, ""), seen))
        out.update(decl[name])
        return out

    final = {}
    for name in decl:
        r = resolve(name)
        if r:
            final[name] = r

    if not os.path.isdir(os.path.dirname(OUT)):
        os.makedirs(os.path.dirname(OUT))
    io.open(OUT, "w", encoding="utf-8").write(json.dumps(final, indent=0, sort_keys=True))

    print("%d config.cpp file(s) carried CfgAmmo" % files)
    print("%d ammo class(es) indexed, %d with a lethality figure" % (len(decl), len(final)))
    print("-> %s" % OUT)
    return 0


if __name__ == "__main__":
    sys.exit(main())
