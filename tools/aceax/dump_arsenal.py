"""Write _dump/arsenal.json - the one "pack" this compat is built from.

The compat covers every attachment the 2040 mission arsenal lists, across the
base game, JCA, ACE, the XM157 mod, the 2040 mod's own optics and three CDLCs.
No single Workshop item holds those, and the CDLC configs are encrypted (.ebo),
so the toolchain's dump_configs.py cannot produce the dump. This does, from
either of two sources, into the derapify-JSON shape modconfig.py reads
(class -> props, inheritance as "__parent", ItemInfo as a nested class):

  * THE GAME (the real thing): 2040's tools/dump_orbat.sqf logs one
    `ITEM;class;parent;type;scope;scopeArsenal;displayName;model;picture;[textures]`
    line per attachment in CfgWeapons. Names are already resolved, CDLC items
    included. This is what the shipped compat is built from.

  * DERAPIFIED PBOs (authoring, before a game run): a directory of unpacked
    PBOs with every config.bin derapified to `config.bin.json` beside it (and
    text config.cpp converted to `config.cpp.json`), plus a directory of the
    base game's language stringtables. Only the mission's classes and their
    ancestors are kept, so the compat never grows past the arsenal.

Both routes list what the mission names that the source does not have - the
dead entries (Aegis is out of the load order) are the point of that list.

Usage:
    python tools/dump_arsenal.py --rpt <Arma3 .rpt with ITEM lines>
    python tools/dump_arsenal.py --unpacked <dir> --lang <dir of stringtable.xml>
Options:
    --mission <dir>   the mission's config/arsenal/common (default: the dev Roomba)
"""
from __future__ import annotations

import argparse
import glob
import io
import json
import os
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import modinfo  # noqa: E402

MISSION = (r"D:\Dropbox\Documents\Arma 3 - Other Profiles\YonV\missions\2040"
           r"\Task_Force_Roomba_dev.Tanoa\config\arsenal\common")
FILES = ("items_optics.hpp", "items_muzzles.hpp", "items_pointers_lights.hpp", "items_bipods.hpp")
PACK = "arsenal"

# ItemInfo `type` -> the vanilla ItemInfo base modconfig recognises the kind by
TYPE_BASE = {
    201: "InventoryOpticsItem_Base_F",
    101: "InventoryMuzzleItem_Base_F",
    301: "InventoryFlashLightItem_Base_F",
    302: "InventoryUnderItem_Base_F",
}
STAMP = re.compile(r"^\s*\d{1,2}:\d{2}:\d{2}(?:\.\d+)?\s+")
RE_ITEM = re.compile(r"^ITEM;([^;]+);([^;]*);(\d+);(\d+);(-?\d+);([^;]*);([^;]*);([^;]*);(.*)$")


def mission_classes(mission: str) -> list[str]:
    out: list[str] = []
    for fn in FILES:
        text = io.open(os.path.join(mission, fn), encoding="utf-8", errors="replace").read()
        for m in re.finditer(r'^\s*"([A-Za-z0-9_]+)"', text, re.M):
            if m.group(1) not in out:
                out.append(m.group(1))
    return out


# ---------------------------------------------------------------------------
def from_rpt(rpt: str, wanted: list[str]) -> tuple[dict, list[str]]:
    """The game's own view of every attachment: flat classes, names resolved."""
    items: dict[str, dict] = {}
    with io.open(rpt, encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            m = RE_ITEM.match(STAMP.sub("", raw.rstrip("\r\n")))
            if not m:
                continue
            cls, parent, typ, scope, scope_ars, name, model, picture, tex = m.groups()
            base = TYPE_BASE.get(int(typ))
            if not base:
                continue
            props = {
                "__parent": parent or "ItemCore",
                "scope": int(scope),
                "displayName": name,
                "model": model,
                "picture": picture,
                "ItemInfo": {"__parent": base, "type": int(typ)},
            }
            if int(scope_ars) >= 0:
                props["scopeArsenal"] = int(scope_ars)
            textures = re.findall(r'"([^"]+)"', tex)
            if textures:
                props["hiddenSelectionsTextures"] = textures
            items[cls.lower()] = (cls, props)
    lower = {c.lower(): c for c in wanted}
    cfg = {}
    for key, (cls, props) in items.items():
        if key in lower:
            cfg[lower[key]] = props
    missing = [c for c in wanted if c.lower() not in items]
    return {"CfgWeapons": cfg}, missing


# ---------------------------------------------------------------------------
def from_unpacked(root: str, wanted: list[str]) -> tuple[dict, list[str]]:
    """Every derapified config under `root`, pruned to the mission's classes
    and their ancestors (so kind, scope and displayName still resolve)."""
    classes: dict[str, tuple[str, dict]] = {}   # lower -> (real name, props)
    # The base game first, then everything that patches it: ACE re-declares
    # optic_Arco with a new displayName and no parent, and the mod's partial
    # class must land ON TOP of the vanilla one, not replace it.
    files = sorted(glob.glob(os.path.join(root, "**", "config.*.json"), recursive=True),
                   key=lambda f: (not os.path.relpath(f, root).lower().startswith("weapons_f"), f))
    for f in files:
        try:
            d = json.load(open(f, encoding="utf-8"))
        except ValueError:
            continue
        for k, v in d.items():
            if k.lower() != "cfgweapons" or not isinstance(v, dict):
                continue
            for cls, props in v.items():
                if not isinstance(props, dict):
                    continue
                key = cls.lower()
                if key in classes:
                    merged = dict(classes[key][1])
                    merged.update(props)
                    classes[key] = (classes[key][0], merged)
                else:
                    classes[key] = (cls, props)
    keep: dict[str, dict] = {}
    missing: list[str] = []
    for c in wanted:
        key = c.lower()
        if key not in classes:
            missing.append(c)
            continue
        seen = set()
        while key and key in classes and key not in seen:
            seen.add(key)
            real, props = classes[key]
            keep.setdefault(real, props)
            parent = props.get("__parent")
            key = parent.lower() if isinstance(parent, str) else ""
    return {"CfgWeapons": keep}, missing


def stringtables(lang: str) -> str:
    """All the base game's stringtables as one file - modconfig reads every
    <Key ID=...><English> it finds."""
    parts = []
    for f in sorted(glob.glob(os.path.join(lang, "*.xml"))):
        parts.append(io.open(f, encoding="utf-8", errors="replace").read())
    return "\n".join(parts)


# ---------------------------------------------------------------------------
def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rpt", help="an Arma 3 RPT holding ITEM lines (tools/dump_orbat.sqf)")
    ap.add_argument("--unpacked", help="directory of unpacked PBOs with derapified config JSON")
    ap.add_argument("--lang", help="directory of base-game stringtable.xml files (with --unpacked)")
    ap.add_argument("--mission", default=MISSION, help="the mission's config/arsenal/common")
    args = ap.parse_args()
    if not args.rpt and not args.unpacked:
        ap.error("one of --rpt / --unpacked is required")

    wanted = mission_classes(args.mission)
    print("%d attachment class(es) in the mission arsenal" % len(wanted))
    if args.rpt:
        data, missing = from_rpt(args.rpt, wanted)
        table = ""
        source = "the game (%s)" % os.path.basename(args.rpt)
    else:
        data, missing = from_unpacked(args.unpacked, wanted)
        table = stringtables(args.lang) if args.lang else ""
        source = "derapified PBOs (%s)" % args.unpacked

    modinfo.DUMP.mkdir(exist_ok=True)
    out = modinfo.DUMP / ("%s.json" % PACK)
    out.write_text(json.dumps(data, indent=1), encoding="utf-8")
    xml = modinfo.DUMP / ("%s.stringtable.xml" % PACK)
    xml.write_text(table, encoding="utf-8")
    found = len(wanted) - len(missing)
    print("wrote %s: %d class(es) (%d of the mission's, %d ancestors) from %s"
          % (out, len(data["CfgWeapons"]), found, len(data["CfgWeapons"]) - found, source))
    if missing:
        print("\n%d mission entr(y/ies) the source does not have - dead in the arsenal, or a mod not loaded:"
              % len(missing))
        by_prefix: dict[str, list[str]] = {}
        for c in missing:
            by_prefix.setdefault(c.split("_")[0], []).append(c)
        for p, cs in sorted(by_prefix.items()):
            print("  %-10s %3d  %s" % (p, len(cs), ", ".join(cs[:6]) + (" ..." if len(cs) > 6 else "")))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
