#!/usr/bin/env python3
"""Index the base game's CfgVehicles.

    python tools/gen_vanilla_vehicles.py [path-to-a3-tree]

Writes work/vanilla_vehicles.json: every class the base game defines under
CfgVehicles, with its parent, scope, faction, vehicleClass and display name.

WHY. Group work needs to know whether a unit class exists before a group is
written around it, and the ORBAT dump that produced work/factions.json only
recorded scope 2 - the units you can place in the editor. Squads are built out
of scope 1 men (`B_soldier_AR_F` is scope 1 and is in every NATO rifle squad),
so a scope-2 roster cannot answer "is this group valid".

TWO MISTAKES THIS AVOIDS, both made here first:

  * Only reading the FIRST `class CfgVehicles` block in a file. Several base
    game configs open the root more than once; taking the first drops the rest.
  * Constraining the class indent to a fixed depth. Indentation in the unpacked
    tree is not uniform, and a fixed depth silently matched a fraction.

Both are handled by counting braces from each root opening, the same way
tools/gen_fa_tiers.py reads futureAmmo.
"""
import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "work", "vanilla_vehicles.json")
DEFAULT_A3 = r"D:\Dropbox\Documents\Arma 3 Projects\a3"

NUM = ("scope", "side")
TXT = ("faction", "vehicleClass", "displayName", "editorSubcategory",
       "uniformClass", "backpack")


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    return re.sub(r"//[^\n]*", "", t)


def root_bodies(text, root):
    """Every `class <root> { ... }` body in a file. ALL of them, not the first."""
    out = []
    for m in re.finditer(r"^[ \t]*class\s+" + root + r"\s*\{", text, re.M):
        depth, j = 1, m.end()
        while j < len(text) and depth:
            if text[j] == "{":
                depth += 1
            elif text[j] == "}":
                depth -= 1
            j += 1
        out.append(text[m.end():j - 1])
    return out


def top_classes(body):
    """(name, parent, body) for classes at the shallowest depth in this block.

    Depth is measured by brace counting from the start of the block, not by
    indentation: the unpacked tree is not consistently indented.
    """
    out = []
    depth = 0
    i = 0
    n = len(body)
    while i < n:
        c = body[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        elif depth == 0 and body.startswith("class", i) and (i == 0 or not body[i - 1].isalnum()):
            m = re.match(r"class\s+(\w+)\s*(?::\s*(\w+)\s*)?([{;])", body[i:])
            if m:
                if m.group(3) == ";":
                    i += m.end()
                    continue
                start = i + m.end()
                d, j = 1, start
                while j < n and d:
                    if body[j] == "{":
                        d += 1
                    elif body[j] == "}":
                        d -= 1
                    j += 1
                out.append((m.group(1), m.group(2) or "", body[start:j - 1]))
                i = j
                continue
        i += 1
    return out


def props(body):
    """Declared properties. Nested blocks removed so a Turret's scope is not
    mistaken for the vehicle's."""
    flat = body
    for _ in range(12):
        new = re.sub(r"\{[^{}]*\}", "", flat)
        if new == flat:
            break
        flat = new
    out = {}
    for k, v in re.findall(r"^\s*(\w+)\s*=\s*(-?[0-9.]+)\s*;", flat, re.M):
        if k in NUM:
            try:
                out[k] = int(float(v))
            except ValueError:
                pass
    for k, v in re.findall(r'^\s*(\w+)\s*=\s*"([^"]*)"\s*;', flat, re.M):
        if k in TXT:
            out[k] = v
    return out


def main():
    a3 = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_A3
    if not os.path.isdir(a3):
        print("no %s" % a3)
        return 1

    data = {}
    files = 0
    for dirpath, _, names in os.walk(a3):
        for nm in names:
            if nm.lower() != "config.cpp":
                continue
            p = os.path.join(dirpath, nm)
            try:
                text = strip_comments(io.open(p, encoding="utf-8", errors="replace").read())
            except OSError:
                continue
            bodies = root_bodies(text, "CfgVehicles")
            if not bodies:
                continue
            files += 1
            for body in bodies:
                for name, parent, cbody in top_classes(body):
                    rec = data.setdefault(name, {})
                    # ACCUMULATE, never first-wins. One addon patches a class
                    # another defines - taking the first entry recorded an empty
                    # patch and threw away the real numbers. That bug cost a day
                    # on the ammo index.
                    if parent and not rec.get("parent"):
                        rec["parent"] = parent
                    rec.update(props(cbody))

    # RESOLVE THROUGH INHERITANCE. Almost nothing declares its own
    # vehicleClass or faction - B_T_Soldier_AR_F declares neither and gets both
    # from B_Soldier_base_F. An index of DECLARED properties answers "what does
    # this class say" when the question is always "what does this class have".
    INHERIT = ("scope", "side", "faction", "vehicleClass", "editorSubcategory",
               "uniformClass", "backpack")

    def resolved(name, seen=None):
        seen = seen or set()
        if name in seen or name not in data:
            return {}
        seen.add(name)
        out = resolved(data[name].get("parent", ""), seen)
        for k, v in data[name].items():
            if k in INHERIT or k == "displayName":
                out[k] = v
        return out

    for name in list(data):
        r = resolved(name)
        r["parent"] = data[name].get("parent", "")
        data[name] = r

    outdir = os.path.dirname(OUT)
    if not os.path.isdir(outdir):
        os.makedirs(outdir)
    io.open(OUT, "w", encoding="utf-8").write(json.dumps(data, indent=0, sort_keys=True))

    men = sum(1 for v in data.values() if v.get("vehicleClass") == "Men")
    faced = sum(1 for v in data.values() if v.get("faction"))
    print("%d config.cpp file(s) carried CfgVehicles" % files)
    print("%d class(es) indexed" % len(data))
    print("   %d with a faction, %d men" % (faced, men))
    for probe in ("B_soldier_AR_F", "B_APC_Wheeled_01_cannon_F", "B_UAV_02_F",
                  "B_T_Soldier_AR_F", "B_W_Soldier_AR_F"):
        print("   %-30s %s" % (probe, "yes" if probe in data else "NO"))
    print("-> %s" % OUT)
    return 0


if __name__ == "__main__":
    sys.exit(main())
