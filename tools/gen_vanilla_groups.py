#!/usr/bin/env python3
"""Index the base game's CfgGroups.

    python tools/gen_vanilla_groups.py

Writes work/vanilla_groups.json and docs/GROUPS_VANILLA.md: every group the base
game defines, which faction it belongs to, and the units in it.

WHY. Every group-level task in this repo has been stalled on not knowing what
groups exist - the ORBAT dump that produced work/factions.json walked
CfgVehicles and never touched CfgGroups. For the vanilla factions that question
is answerable from the unpacked A3 tree, the same way the ammo was.

WHAT IT DOES NOT COVER. Groups belonging to mod factions - Aegis, lxWS, EF and
the rest - are not in this tree. BLU_F is here; BLU_T_F, BLU_W_F,
BLU_NATO_lxWS and the MJTF factions are not, and still need an in-game dump.
"""
import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT_JSON = os.path.join(ROOT, "work", "vanilla_groups.json")
OUT_DOC = os.path.join(ROOT, "docs", "GROUPS_VANILLA.md")

SIDES = {"West": "WEST", "East": "EAST", "Guerrilla": "GUER", "Civilian": "CIV"}


def body_of(text, start):
    i = text.find("{", start)
    if i < 0:
        return "", len(text)
    depth, j = 1, i + 1
    while j < len(text) and depth:
        if text[j] == "{":
            depth += 1
        elif text[j] == "}":
            depth -= 1
        j += 1
    return text[i + 1:j - 1], j


def children(text):
    """(name, body) for every class one level down."""
    out = []
    for m in re.finditer(r"^([ \t]*)class\s+(\w+)\s*$|^([ \t]*)class\s+(\w+)\s*\{", text, re.M):
        name = m.group(2) or m.group(4)
        body, _ = body_of(text, m.end() - 1)
        out.append((name, body))
    # keep only the shallowest indent level present
    if not out:
        return out
    return out


def top_children(text):
    """Only the classes at the shallowest indentation in this block."""
    found = []
    for m in re.finditer(r"^([ \t]*)class\s+(\w+)", text, re.M):
        found.append((len(m.group(1).expandtabs(4)), m.group(2), m.end()))
    if not found:
        return []
    shallow = min(f[0] for f in found)
    out = []
    for indent, name, end in found:
        if indent != shallow:
            continue
        body, _ = body_of(text, end)
        out.append((name, body))
    return out


def main():
    a3 = r"D:\Dropbox\Documents\Arma 3 Projects\a3"
    if len(sys.argv) > 1:
        a3 = sys.argv[1]
    if not os.path.isdir(a3):
        print("no %s" % a3)
        return 1

    data = {}
    files = 0
    for e in os.scandir(a3):
        if not e.is_dir():
            continue
        p = os.path.join(e.path, "config.cpp")
        if not os.path.isfile(p):
            continue
        try:
            text = io.open(p, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        if "class CfgGroups" not in text:
            continue
        files += 1
        m = re.search(r"^[ \t]*class CfgGroups", text, re.M)
        root, _ = body_of(text, m.end())

        for side_name, side_body in top_children(root):
            if side_name not in SIDES:
                continue
            for fac_name, fac_body in top_children(side_body):
                if not fac_body.strip():
                    continue
                for cat_name, cat_body in top_children(fac_body):
                    for grp_name, grp_body in top_children(cat_body):
                        # FULL FIDELITY, not just the roster. Rebuilding a group
                        # for another faction needs the rank (Arma hands command
                        # down that order) and the position (the formation), and
                        # a list of classnames carries neither.
                        men = []
                        for unit_name, unit_body in top_children(grp_body):
                            v = re.search(r'vehicle\s*=\s*"([^"]+)"', unit_body)
                            if not v:
                                continue
                            rank = re.search(r'rank\s*=\s*"([^"]+)"', unit_body)
                            pos = re.search(r'position\[\]\s*=\s*\{([^}]*)\}', unit_body)
                            xyz = [0.0, 0.0, 0.0]
                            if pos:
                                try:
                                    xyz = [float(x) for x in pos.group(1).split(",")][:3]
                                except ValueError:
                                    pass
                            while len(xyz) < 3:
                                xyz.append(0.0)
                            men.append({
                                "cls": v.group(1),
                                "rank": rank.group(1) if rank else "PRIVATE",
                                "pos": xyz,
                            })
                        if not men:
                            continue
                        name = re.search(r'name\s*=\s*"([^"]+)"', grp_body)
                        icon = re.search(r'icon\s*=\s*"([^"]+)"', grp_body)
                        rar = re.search(r'rarityGroup\s*=\s*([0-9.]+)', grp_body)
                        data.setdefault(SIDES[side_name], {}).setdefault(
                            fac_name, {}).setdefault(cat_name, {})[grp_name] = {
                                "name": name.group(1) if name else grp_name,
                                "icon": icon.group(1) if icon else "",
                                "rarityGroup": float(rar.group(1)) if rar else 1.0,
                                "men": men,
                            }

    if not os.path.isdir(os.path.dirname(OUT_JSON)):
        os.makedirs(os.path.dirname(OUT_JSON))
    io.open(OUT_JSON, "w", encoding="utf-8").write(json.dumps(data, indent=1, sort_keys=True))

    doc = [
        "# Base game groups",
        "",
        "Every `CfgGroups` entry the base game defines, by side and faction, with",
        "the size of each group and what is in it.",
        "",
        "Generated by `tools/gen_vanilla_groups.py` from the unpacked A3 tree. Do",
        "not hand-edit.",
        "",
        "**Mod factions are not here.** Aegis, lxWS and EF ship their own groups and",
        "are not in this tree - so `BLU_F` is covered and `BLU_T_F`, `BLU_W_F`,",
        "`BLU_NATO_lxWS` and the MJTF factions are not. Those still need an in-game",
        "dump before their group counts can be compared with anything.",
        "",
    ]
    total = 0
    for side in sorted(data):
        doc.append("## %s" % side)
        doc.append("")
        for fac in sorted(data[side]):
            n = sum(len(g) for g in data[side][fac].values())
            total += n
            doc.append("### `%s` - %d group(s)" % (fac, n))
            doc.append("")
            doc.append("| Category | Group | Size | Units |")
            doc.append("|---|---|---:|---|")
            for cat in sorted(data[side][fac]):
                for grp in sorted(data[side][fac][cat]):
                    rec = data[side][fac][cat][grp]
                    u = [m["cls"] for m in rec["men"]]
                    uniq = sorted(set(u))
                    shown = ", ".join("`%s`" % x for x in uniq[:4])
                    if len(uniq) > 4:
                        shown += ", +%d more" % (len(uniq) - 4)
                    doc.append("| %s | `%s` | %d | %s |" % (cat, grp, len(u), shown))
            doc.append("")

    io.open(OUT_DOC, "w", encoding="utf-8", newline="\r\n").write("\n".join(doc) + "\n")

    print("%d config.cpp file(s) carried CfgGroups" % files)
    print("%d group(s) across %d side(s)" % (total, len(data)))
    for side in sorted(data):
        print("   %-6s %d faction(s), %d group(s)" % (
            side, len(data[side]), sum(len(g) for f in data[side].values() for g in f.values())))
    print("-> %s" % OUT_DOC)
    return 0


if __name__ == "__main__":
    sys.exit(main())
