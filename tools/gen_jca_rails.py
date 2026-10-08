"""JCA attachments on the base game's rails - addons/jca_rails (user, 2026-08-28:
"look up all the JCA attachments and edit them to be compatible with MXs and
SPARs").

JCA is an external mod and stays untouched; CBA Joint Rails is in the load
order, and under it a weapon's slots are the asdg_* classes (the MX family and
the SPAR-16/16S/17 sit on asdg_OpticRail1913, asdg_FrontSideRail,
asdg_UnderSlot and asdg_MuzzleSlot_65 / _556 / _762 - cba_jr and the MX Redux
compat, derapified 2026-08-28). A mod makes an item fit by listing it in the
slot class's compatibleItems, which is all this addon does. Read from the
unpacked JCA config in D:\\work:

  * optics    -> asdg_OpticRail1913 (JCA lists them there already - only the
                 ones it missed are added; pistol optics are left alone)
  * pointers, flashlights -> asdg_FrontSideRail AND the base game's own
                 PointerSlot_Rail, both root classes. WHICH ONE A RIFLE READS
                 (cba_jr 3.19.0.260808 and weapons_f, derapified 2026-08-29):
                 the SPAR-16/16S/17 are patched by Joint Rails to
                 asdg_FrontSideRail; the MX family is NOT - cba_jr rewrites
                 the MX's CowsSlot and UnderBarrelSlot and leaves its
                 PointerSlot on vanilla's `class PointerSlot: PointerSlot_Rail`,
                 the root class every vanilla rifle side rail descends from.
                 JCA itself lists its laser modules and torches on both
                 (weapons_f_JCA_IA/config.cpp) and keeps the dual mount for its
                 own M4A4 - that omission is the whole of "the dual mount
                 does not fit the MX". Adding it to the same two root classes
                 is exactly JCA's own mechanism and touches no weapon class.
                 NEVER patch arifle_MX_Base_F's WeaponSlotsInfo for this: the
                 2026-08-29 attempt wrote the nested classes without
                 inheritance and replaced the MX's whole slot table.
  * MRT switch states -> wherever the item they switch from goes. JCA's dual
                 mounts are switchable: JCA_acc_DualMount_black_Pointer cycles
                 into _Laser_Red, _Laser_Green, _Light and _Light_LP, which are
                 scope=1 and so invisible to the arsenal but are what the item
                 BECOMES. Registering only the arsenal-visible state leaves the
                 mount fitting the rail until the moment it is switched.
  * bipods    -> asdg_UnderSlot. JCA registers them ONLY on its own
                 UnderBarrelSlot_rail, so no base-game rifle takes them.
  * muzzles   -> the asdg caliber slot JCA's own weapon slot names them under
                 (MuzzleSlot_556 -> asdg_MuzzleSlot_556, _762 -> _762, 9MM,
                 45ACP...). The 6.5 slot inherits the 7.62 items under JR, so
                 the MX already takes JCA's 7.62 cans; the 5.56 rifle cans are
                 added to asdg_MuzzleSlot_65 too, for the MX (user's ask).

Usage:  python tools/gen_jca_rails.py [--jca <path to weapons_f_JCA_IA/config.cpp>] [--report]
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_JCA = r"D:\work\weapons_f_JCA_IA\config.cpp"
ADDON = os.path.join(ROOT, "addons", "jca_rails")

# JCA's own weapon slot class -> the Joint Rails slot the same items belong on
MUZZLE_MAP = {
    "MuzzleSlot_556": "asdg_MuzzleSlot_556",
    "MuzzleSlot_762": "asdg_MuzzleSlot_762",
    "MuzzleSlot_9mm": "asdg_MuzzleSlot_9MM",
    "MuzzleSlot_45ACP": "asdg_MuzzleSlot_45ACP",
    # JCA keeps these cans to one weapon each (a child slot); they are ordinary
    # 7.62 / .338 cans and the SPAR-17 (and, by JR inheritance, the MX) may
    # take the SR25's. The .50 M107, the MP5 and the .300 BLK cans stay
    # exclusive - no base-game rifle they belong on.
    "JCA_MuzzleSlot_SR25": "asdg_MuzzleSlot_762",
    "JCA_MuzzleSlot_AWM": "asdg_MuzzleSlot_338",
}
# items that belong on a pistol or one SMG, never on a rifle rail
EXCLUSIVE = re.compile(r"Mk23|MP5|Pistol", re.I)
# the slot classes and what they derive from (cba_jr for asdg_*, weapons_f for
# PointerSlot_Rail), for the external declarations the config needs
ASDG_PARENT = {
    "PointerSlot": None,
    "PointerSlot_Rail": "PointerSlot",
    "asdg_SlotInfo": None,
    "asdg_OpticRail": "asdg_SlotInfo",
    "asdg_OpticRail1913": "asdg_OpticRail",
    "asdg_FrontSideRail": "asdg_SlotInfo",
    "asdg_UnderSlot": "asdg_SlotInfo",
    "asdg_MuzzleSlot": "asdg_SlotInfo",
    "asdg_MuzzleSlot_762": "asdg_MuzzleSlot",
    "asdg_MuzzleSlot_65": "asdg_MuzzleSlot_762",
    "asdg_MuzzleSlot_556": "asdg_MuzzleSlot",
    "asdg_MuzzleSlot_9MM": "asdg_MuzzleSlot",
    "asdg_MuzzleSlot_45ACP": "asdg_MuzzleSlot",
    "asdg_MuzzleSlot_338": "asdg_MuzzleSlot",
    "asdg_MuzzleSlot_127": "asdg_MuzzleSlot",
}
# Slots whose compatibleItems is itself INHERITED in the defining config -
# cba_jr writes `class asdg_MuzzleSlot_65: asdg_MuzzleSlot_762 { class
# compatibleItems: compatibleItems {` so the 6.5 slot takes every 7.62 can.
# Our patch has to say `: compatibleItems` too: a bare `class compatibleItems {`
# on a class the engine already holds REPLACES its base with nothing (the RPT
# says "Updating base class 'compatibleItems'->''"), and the MX lost every
# 7.62 suppressor the moment this addon loaded. Every other slot here defines
# its list from scratch and a bare body is correct for it.
INHERITED_ITEMS = {"asdg_MuzzleSlot_65"}


def strip_comments(s):
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    return re.sub(r"//[^\n]*", "", s)


def block(text, start):
    """text[start:] is just past a '{' - return (inner, end index past '}')."""
    depth, i = 1, start
    while depth and i < len(text):
        depth += (text[i] == "{") - (text[i] == "}")
        i += 1
    return text[start:i - 1], i


def compat_lists(text):
    """slot class -> [items] for every 'class X[: Y] { class compatibleItems { a=1; } }'."""
    out = {}
    for m in re.finditer(r"class\s+(\w+)\s*(?::\s*(\w+))?\s*\{", text):
        name = m.group(1)
        inner, _e = block(text, m.end())
        cm = re.search(r"class\s+compatibleItems(?:\s*:\s*\w+)?\s*\{", inner)
        if not cm:
            continue
        cinner, _ = block(inner, cm.end())
        items = re.findall(r"^\s*(\w+)\s*=\s*1\s*;", cinner, re.M)
        if items:
            out.setdefault(name, [])
            for it in items:
                if it not in out[name]:
                    out[name].append(it)
    return out


def items_by_kind(text):
    """JCA attachment classes by kind, from the ItemInfo parent found up
    their JCA_* inheritance chain (JCA_optic_ACOG_black: JCA_optic_ACOG_base:
    ItemCore, with the ItemInfo on the base)."""
    kinds = {"optic": [], "pointer": [], "bipod": [], "muzzle": []}
    classes = {}     # JCA_* class -> (parent, own body)
    for m in re.finditer(r"class\s+(JCA_\w+)\s*:\s*(\w+)\s*\{", text):
        inner, _ = block(text, m.end())
        classes.setdefault(m.group(1), (m.group(2), inner))

    def iteminfo_base(name):
        seen = set()
        while name in classes and name not in seen:
            seen.add(name)
            parent, inner = classes[name]
            ii = re.search(r"class\s+ItemInfo\s*:\s*(\w+)", inner)
            if ii:
                return ii.group(1).lower()
            name = parent
        return ""

    for name, (parent, inner) in classes.items():
        if re.search(r"_base$", name, re.I):
            continue
        scope = re.search(r"^\s*scope\s*=\s*(\d+)\s*;", inner, re.M)
        if scope and scope.group(1) != "2":
            continue
        if not re.search(r"^\s*displayName\s*=", inner, re.M):
            continue     # a base or a variant with nothing of its own
        base = iteminfo_base(name)
        if "optics" in base:
            kinds["optic"].append(name)
        elif "flashlight" in base or "pointer" in base:
            kinds["pointer"].append(name)
        elif "underitem" in base or "underbarrel" in base or "bipod" in base:
            kinds["bipod"].append(name)
        elif "muzzle" in base:
            kinds["muzzle"].append(name)
    return kinds, classes


def switch_family(name, classes):
    """Every class an MRT-switchable item can turn into, itself included.

    MRT_SwitchItemNextClass / PrevClass chain the states of one physical
    accessory. They are scope=1, so items_by_kind never sees them, but the slot
    has to accept them or switching an attached item fails."""
    out, queue = [], [name]
    while queue:
        cur = queue.pop()
        if cur in out or cur not in classes:
            continue
        out.append(cur)
        _parent, inner = classes[cur]
        for key in ("MRT_SwitchItemNextClass", "MRT_SwitchItemPrevClass"):
            for m in re.finditer(r'%s\s*=\s*"(\w+)"' % key, inner):
                queue.append(m.group(1))
    return out


def main():
    jca = DEFAULT_JCA
    if "--jca" in sys.argv:
        jca = sys.argv[sys.argv.index("--jca") + 1]
    if os.path.isfile(jca):
        jca = os.path.dirname(jca)
    if not os.path.isdir(jca):
        print("!! no JCA tree at %s" % jca)
        return 2
    # the slot lists sit in the root config.cpp, the items in acc/config.cpp -
    # read every config.cpp under the unpacked mod
    text = ""
    for dp, _dn, fns in os.walk(jca):
        for fn in fns:
            if fn.lower() == "config.cpp":
                text += "\n" + strip_comments(io.open(os.path.join(dp, fn), encoding="utf-8", errors="replace").read())
    lists = compat_lists(text)
    kinds, jca_classes = items_by_kind(text)

    def registered(slot):
        return set(lists.get(slot, []))

    add = {}   # asdg slot -> [items]

    def want(slot, item):
        if item not in registered(slot):
            add.setdefault(slot, [])
            if item not in add[slot]:
                add[slot].append(item)

    # anything JCA files under one of its pistol slots is a pistol item
    pistol_items = set()
    for slot, items in lists.items():
        if "pistol" in slot.lower():
            pistol_items.update(items)

    def exclusive(it):
        return it in pistol_items or EXCLUSIVE.search(it)

    # optics: every rifle optic on the Picatinny rail; pistol ones stay pistol
    for it in kinds["optic"]:
        if not exclusive(it):
            want("asdg_OpticRail1913", it)
    # pointers and lights: the rifle ones; pistol lights stay on the pistol rail.
    # Each one brings its MRT switch states with it - see switch_family. Both
    # root rails, because the SPARs read one and the MX reads the other - see
    # the docstring.
    for it in kinds["pointer"]:
        if exclusive(it):
            continue
        for state in switch_family(it, jca_classes):
            want("asdg_FrontSideRail", state)
            want("PointerSlot_Rail", state)
    # bipods: the one slot every base-game rifle has under JR
    for it in kinds["bipod"]:
        want("asdg_UnderSlot", it)
    # muzzles: by the caliber JCA's own weapon slots file them under
    for jslot, aslot in MUZZLE_MAP.items():
        for it in lists.get(jslot, []):
            if it.startswith("JCA_"):
                want(aslot, it)
    # the MX takes the 5.56 rifle cans too (the 6.5 slot already inherits the 7.62 ones)
    for it in lists.get("MuzzleSlot_556", []):
        if it.startswith("JCA_"):
            want("asdg_MuzzleSlot_65", it)
    # a JCA muzzle no JCA weapon slot files (nothing to infer a caliber from)
    filed = set(x for k in MUZZLE_MAP for x in lists.get(k, []))
    unfiled = [it for it in kinds["muzzle"] if it not in filed
               and not any(it in registered(a) for a in ASDG_PARENT)]

    if "--report" in sys.argv:
        for k, v in kinds.items():
            print("%-8s %d" % (k, len(v)))
        for slot in sorted(add):
            print("\n+ %s (%d):" % (slot, len(add[slot])))
            for it in add[slot]:
                print("    %s" % it)
        if unfiled:
            print("\n?? muzzles with no caliber slot (not registered):")
            for it in unfiled:
                print("    %s" % it)
        return 0

    # ---- the addon --------------------------------------------------------
    os.makedirs(ADDON, exist_ok=True)
    L = ["// Generated by tools/gen_jca_rails.py - re-run rather than hand-edit.",
         "// JCA'S ATTACHMENTS ON THE BASE GAME'S RAILS. A rifle's slots are root classes -",
         "// CBA Joint Rails' asdg_* for the SPARs, the base game's own PointerSlot_Rail",
         "// for the MX's side rail, which cba_jr leaves alone - and an item fits a slot",
         "// when it is listed in that class's compatibleItems. JCA lists its optics,",
         "// lasers and torches there but keeps the dual mount for its own M4A4, its",
         "// bipods on its own slot and its cans by 5.56 / 7.62. This addon adds the",
         "// missing entries to the same root classes; no weapon class is touched and JCA",
         "// itself is untouched. See the tool's docstring for what goes where.",
         '#include "script_component.hpp"',
         "",
         "class CfgPatches {",
         "    class ADDON {",
         "        name = COMPONENT_NAME;",
         "        units[] = {};",
         "        weapons[] = {};",
         "        requiredVersion = REQUIRED_VERSION;",
         '        requiredAddons[] = {"jmfsb_main", "cba_jr", "Weapons_F_JCA_IA"};',
         "        skipWhenMissingDependencies = 1;",
         "        author = QAUTHOR;",
         "        VERSION_CONFIG;",
         "    };",
         "};",
         ""]
    needed = set()
    for slot in add:
        s_ = slot
        while s_:
            needed.add(s_)
            s_ = ASDG_PARENT.get(s_)
    # declare the chain, parents first - external declarations carry no
    # parent (hemtt L-C10; the class is CBA's, this only names it)
    order = [s_ for s_ in ASDG_PARENT if s_ in needed]
    for s_ in order:
        if s_ in add:
            continue
        L.append("class %s;" % s_)
    L.append("")
    for slot in order:
        if slot not in add:
            continue
        par = ASDG_PARENT[slot]
        L.append("class %s: %s {" % (slot, par))
        if slot in INHERITED_ITEMS:
            L.append("    class compatibleItems: compatibleItems {")
        else:
            L.append("    class compatibleItems {")
        for it in add[slot]:
            L.append("        %s = 1;" % it)
        L.append("    };")
        L.append("};")
        L.append("")
    tmp = os.path.join(ADDON, "config.cpp.tmp")
    io.open(tmp, "w", encoding="utf-8", newline="\n").write("\n".join(L))
    os.replace(tmp, os.path.join(ADDON, "config.cpp"))
    print("wrote addons/jca_rails: %s" % ", ".join("%s +%d" % (s_, len(add[s_])) for s_ in order if s_ in add))
    if unfiled:
        print("  ?? %d JCA muzzle(s) with no caliber slot, not registered: %s" % (len(unfiled), ", ".join(unfiled[:8])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
