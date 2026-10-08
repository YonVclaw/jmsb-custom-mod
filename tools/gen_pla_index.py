#!/usr/bin/env python3
"""Index the PLA mod's vehicles from its unpacked configs.

    python tools/gen_pla_index.py [--pla D:\\work\\pla]

Writes work/pla_vehicles.json: every scope-2 CfgVehicles class the PLA mod
(Lurker1011's "PLA Armored Force", addons *_LK) declares, with the properties
tools/gen_us_factions.py needs, resolved through the mod's own inheritance -
displayName (stringtable-resolved), faction, side, crew, vehicleClass,
editorSubcategory, hiddenSelections, hiddenSelectionsTextures and the
TextureSources (name -> textures) each vehicle offers.

WHY A SEPARATE INDEX. gen_us_factions builds a faction from the in-game
ORBAT dump, and the dump on hand (2026-08-27) was taken without the PLA mod
loaded. Its vehicles are read here from the configs instead and merged into
the dump's tables as if they had been dumped (see gen_us_factions.PLA_INDEX),
so ROSTER_ADD, crews, camo and CfgPatches work exactly as for anything else.
The parse is deliberately narrow: class blocks, `key = value;` scalars,
`key[] = {...}` arrays, and the TextureSources subclass. Anything else in
those configs (weapons, turrets, damage) is neither needed nor read.
"""
import io
import json
import os
import re
import sys
import xml.etree.ElementTree as ET

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "work", "pla_vehicles.json")
DEFAULT_PLA = r"D:\work\pla"

SCALARS = ("displayName", "faction", "side", "scope", "scopeCurator", "crew",
           "vehicleClass", "editorSubcategory", "author")
ARRAYS = ("hiddenSelections", "hiddenSelectionsTextures", "textureList")


def block_end(s, i):
    """Index just past the '}' that closes the block opened before i."""
    depth, j = 1, i
    while depth and j < len(s):
        depth += (s[j] == "{") - (s[j] == "}")
        j += 1
    return j


def strip_comments(s):
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    return re.sub(r"//[^\n]*", "", s)


def top_classes(body):
    """(name, parent, inner) for every class directly inside body."""
    out, i = [], 0
    while True:
        m = re.compile(r"class\s+(\w+)\s*(?::\s*(\w+))?\s*\{").search(body, i)
        if not m:
            return out
        e = block_end(body, m.end())
        out.append((m.group(1), m.group(2), body[m.end():e - 1]))
        i = e


def parse_props(inner):
    """Scalars, arrays and TextureSources of one class body (own values only)."""
    # own body without nested classes
    flat, i = [], 0
    for m in re.finditer(r"class\s+\w+\s*(?::\s*\w+)?\s*\{", inner):
        if m.start() < i:
            continue
        flat.append(inner[i:m.start()])
        i = block_end(inner, m.end())
    flat.append(inner[i:])
    flat = "".join(flat)
    p = {}
    for k in SCALARS:
        m = re.search(r'\b%s\s*=\s*"?([^";]*)"?\s*;' % k, flat)
        if m:
            p[k] = m.group(1).strip()
    for k in ARRAYS:
        m = re.search(r"\b%s\[\]\s*=\s*\{([^}]*)\}" % k, flat)
        if m:
            p[k] = re.findall(r'"([^"]+)"', m.group(1))
    m = re.search(r"class\s+TextureSources\s*\{", inner)
    if m:
        e = block_end(inner, m.end())
        srcs = {}
        for name, _par, sinner in top_classes(inner[m.end():e - 1]):
            t = re.search(r"textures\[\]\s*=\s*\{([^}]*)\}", sinner)
            if t:
                srcs[name] = re.findall(r'"([^"]+)"', t.group(1))
        if srcs:
            p["textureSources"] = srcs
    return p


def main():
    pla = DEFAULT_PLA
    if "--pla" in sys.argv:
        pla = sys.argv[sys.argv.index("--pla") + 1]
    if not os.path.isdir(pla):
        print("!! no PLA tree at %s" % pla)
        return 2

    strings = {}
    for dp, _dn, fns in os.walk(pla):
        for fn in fns:
            if fn.lower() == "stringtable.xml":
                try:
                    for key in ET.parse(os.path.join(dp, fn)).getroot().iter("Key"):
                        en = key.find("English")
                        if en is None:
                            en = key.find("Original")
                        if en is not None and en.text:
                            strings[key.get("ID")] = en.text.strip()
                except ET.ParseError:
                    pass

    classes, order = {}, []
    for dp, _dn, fns in os.walk(pla):
        for fn in fns:
            if fn.lower() != "config.cpp":
                continue
            s = strip_comments(io.open(os.path.join(dp, fn), encoding="utf-8", errors="replace").read())
            m = re.search(r"class\s+CfgVehicles\s*\{", s)
            if not m:
                continue
            e = block_end(s, m.end())
            for name, par, inner in top_classes(s[m.end():e - 1]):
                if name in classes:
                    continue
                classes[name] = (par, parse_props(inner))
                order.append(name)

    def resolve(name, key, seen=None):
        seen = seen or set()
        if name not in classes or name in seen:
            return None
        seen.add(name)
        par, p = classes[name]
        if key in p:
            return p[key]
        return resolve(par, key, seen) if par else None

    out = {}
    for name in order:
        if resolve(name, "scope") != "2":
            continue
        rec = {"parent": classes[name][0]}
        for k in SCALARS + ARRAYS + ("textureSources",):
            v = resolve(name, k)
            if v is not None:
                rec[k] = v
        # The mod leaves vehicleClass to vanilla parents it never declares in
        # its own tree; the editor category is what the generator sorts by.
        if "vehicleClass" not in rec:
            rec["vehicleClass"] = "Air" if name.startswith(("Z", "PLAAF")) else "Armored"
            rec["vehicleClass_guessed"] = True
        dn = rec.get("displayName", "")
        if dn.startswith("$STR_"):
            rec["displayName"] = strings.get(dn[1:], dn)
        out[name] = rec

    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    io.open(OUT, "w", encoding="utf-8").write(json.dumps(out, indent=1, sort_keys=True))
    print("wrote %s: %d vehicle(s) from %d class(es), %d string(s)" % (os.path.relpath(OUT, ROOT), len(out), len(classes), len(strings)))
    for name, rec in sorted(out.items()):
        print("  %-28s %-14s fac=%-18s crew=%-16s vc=%-10s tex=%s" % (
            name, rec.get("displayName", "")[:14], rec.get("faction", "-"), rec.get("crew", "-"),
            rec.get("vehicleClass", "-"), ",".join(sorted(rec.get("textureSources", {}))) or "-"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
