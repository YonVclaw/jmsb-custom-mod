#!/usr/bin/env python3
"""One ACE Arsenal Extended menu for every MCC carbine.

MCC ships one menu per handguard or per model - "M4A1 MI-Night Fighter", "M4A1 USGI",
"M4A1 BLOCK-II", "LMT MARS-L SPECWAR"... - so a rifle that comes in 1,291 classes is
spread over a dozen rows (user, 2026-10-08: "the extended arsenal config for mcc is
too narrow, all m4a1 and like classes need to be a single menu"). This reads MCC's own
class names and writes addons/weapons_mcc/XtdGear.hpp: ONE menu, "Carbines (MCC)", with
family, calibre, handguard, barrel, colour, stock and grip as its dropdowns. Our
XtdGearInfos entries load after MCC's (weapons_mcc requires every MCC addon), so they
win, and MCC's own menus simply end up empty.

    python tools/gen_mcc_xtdgear.py            reads D:\\work\\mcc\\MCC (the unpacked mod)
"""
import glob
import os
import re
import sys

MCC = os.environ.get("MCC_SRC", r"D:\work\mcc\MCC")
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "addons", "weapons_mcc", "XtdGear.hpp")

# the carbine families that share the menu, and the base-class words that mark a rifle
FAMILIES = {
    "M4A1": "Colt M4A1", "LMT": "LMT MARS-L", "SOLGW": "SOLGW Mk1", "REC7": "Barrett REC7",
    "SpearLT": "SIG Spear LT", "KS1": "KAC KS-1", "KS2": "KAC KS-2", "KS3": "KAC KS-3", "KS4": "KAC KS-4",
    "HK416A8": "HK416 A8", "G95": "HK G95", "G95A1": "HK G95A1", "G95KA1": "HK G95KA1",
}
VOCAB = {
    "calibre":   {"556": "5.56 mm", "300": ".300 BLK", "300BLK": ".300 BLK", "68SPC": "6.8 SPC", "6ARC": "6 mm ARC", "762x39": "7.62x39", "762": "7.62 mm", "9mm": "9 mm"},
    "barrel":    {"8": "8 in", "85": "8.5 in", "9": "9 in", "10": "10 in", "105": "10.5 in", "11": "11 in", "115": "11.5 in", "125": "12.5 in", "14": "14 in", "145": "14.5 in", "16": "16 in", "R20": "20 in (R20)", "R20S": "20 in (R20S)", "L143A2": "L143A2"},
    "colour":    {"BLK": "Black", "FDE": "FDE", "OD": "OD green", "DE": "Dark earth", "GRY": "Grey", "SIL": "Silver", "CAMO": "Camo", "BRZ": "Bronze", "ANO": "Anodised", "TS": "Two-tone", "GRN": "Green"},
    "stock":     {"CTR": "Magpul CTR", "SLK": "Magpul SL-K", "Bravo": "B5 Bravo", "BRAVO": "B5 Bravo", "SOPMOD": "SOPMOD", "M4SS": "M4 stock", "TR": "TR", "HK": "HK", "MPLFS": "Spear LT folding", "STR": "STR", "STD": "Standard"},
    "grip":      {"AFG": "AFG", "GRIPPOD": "Grip Pod", "GripPod": "Grip Pod", "VFG": "Vertical grip"},
    "handguard": {"MFR": "Geissele MFR", "Aero": "Aero", "Troy": "Troy", "NFM": "MI Night Fighter", "SMR": "Geissele SMR", "BII": "Block II", "FSP": "Block II (FSP)", "RAS": "KAC RAS", "URGI": "URG-I", "USGI": "USGI", "SPECWAR": "SPECWAR", "DI": "DI", "NZDF": "NZDF", "RAHE": "RAHE", "KSK": "KSK", "MK18": "Mk18", "Mk18": "Mk18"},
}
AXES = ["family", "calibre", "handguard", "barrel", "colour", "stock", "grip"]


def classes():
    """Every carbine class MCC defines, by family: the config files, minus their extended-arsenal data."""
    rx = re.compile(r"class\s+(MCC_(%s)[A-Za-z0-9_]*)\s*:\s*(MCC_[A-Za-z0-9_]+)" % "|".join(sorted(FAMILIES, key=len, reverse=True)))
    found = {}
    for f in glob.glob(os.path.join(MCC, "MCC_*", "**", "*.hpp"), recursive=True) + glob.glob(os.path.join(MCC, "MCC_*", "**", "*.cpp"), recursive=True):
        if "extended_arsenal" in f.lower():
            continue
        text = open(f, encoding="utf-8", errors="ignore").read()
        for m in rx.finditer(text):
            cls, fam, base = m.group(1), m.group(2), m.group(3)
            if cls.endswith("_Base") or "Mag" in cls:
                continue
            if not re.search(r"Carbine|Rifle|_Base$|MCC_(%s)" % fam, base):
                continue
            found[cls] = fam
    return found


def options_of(cls, fam):
    """Each token after the family word, filed under the axis whose vocabulary names it."""
    rest = cls[len("MCC_" + fam):].strip("_").split("_") if cls[len("MCC_" + fam):] else []
    opts = {"family": fam, "calibre": "STD", "handguard": "STD", "barrel": "STD", "colour": "STD", "stock": "STD", "grip": "NONE"}
    # the same thing spelt two ways in MCC is one value here
    SAME = {"BRAVO": "Bravo", "GRIPPOD": "GripPod", "300BLK": "300"}
    for tok in rest:
        tok = SAME.get(tok, tok)
        if tok == "":
            continue
        for axis in ("grip", "stock", "colour", "calibre", "barrel", "handguard"):
            if tok in VOCAB[axis] and opts[axis] in ("STD", "NONE"):
                opts[axis] = tok
                break
        else:
            # an unknown word is a variant of the handguard/model line, not a mystery
            opts["handguard"] = tok if opts["handguard"] == "STD" else opts["handguard"] + "_" + tok
    return opts


def main():
    found = classes()
    if not found:
        sys.exit("no MCC classes under %s" % MCC)
    infos = {cls: options_of(cls, fam) for cls, fam in found.items()}
    # the menu's values, per axis: what the classes actually use
    values = {axis: [] for axis in AXES}
    for o in infos.values():
        for axis in AXES:
            if o[axis] not in values[axis]:
                values[axis].append(o[axis])
    # a value's config class name must be a word; MCC's tokens are, bar the dot-free numbers
    def label(axis, v):
        if axis == "family":
            return FAMILIES.get(v, v)
        if v == "STD":
            return "Standard"
        if v == "NONE":
            return "None"
        return VOCAB.get(axis, {}).get(v, v.replace("_", " "))
    out = []
    out.append("// GENERATED by tools/gen_mcc_xtdgear.py from MCC's class names - do not edit.")
    out.append("// One ACE Arsenal Extended menu for every MCC carbine: %d classes, %d families." % (len(infos), len(values["family"])))
    out.append("class XtdGearModels {")
    out.append("    class CfgWeapons {")
    out.append("        class jmfsb_mcc_carbine {")
    out.append('            label = "Carbines (MCC)";')
    out.append('            author = "MCC - menu by 1st JMSB";')
    out.append("            options[] = {%s};" % ", ".join('"%s"' % a for a in AXES))
    for axis in AXES:
        out.append("            class %s {" % axis)
        out.append('                label = "%s";' % axis.capitalize())
        out.append("                values[] = {%s};" % ", ".join('"%s"' % v for v in values[axis]))
        for v in values[axis]:
            out.append('                class %s { label = "%s"; };' % (v, label(axis, v)))
        out.append("            };")
    out.append("        };")
    out.append("    };")
    out.append("};")
    out.append("")
    out.append("class XtdGearInfos {")
    out.append("    class CfgWeapons {")
    for cls in sorted(infos):
        o = infos[cls]
        out.append('        class %s { model = "jmfsb_mcc_carbine"; %s };' % (cls, " ".join('%s = "%s";' % (a, o[a]) for a in AXES)))
    out.append("    };")
    out.append("};")
    with open(OUT, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(out) + "\n")
    fams = {}
    for o in infos.values():
        fams[o["family"]] = fams.get(o["family"], 0) + 1
    print("wrote %s: %d classes" % (os.path.relpath(OUT, ROOT), len(infos)))
    for f, n in sorted(fams.items(), key=lambda x: -x[1]):
        print("   %-8s %4d" % (f, n))
    for axis in AXES[1:]:
        print("   %-10s %s" % (axis, ", ".join(values[axis])))


if __name__ == "__main__":
    main()
