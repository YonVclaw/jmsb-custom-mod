"""Generate jmfsb's third-party rifle patches from the mods' own configs.

    python tools/gen_weapon_patches.py            # write the addons
    python tools/gen_weapon_patches.py --report   # print what would be written, write nothing

Writes three addons, each skipped when its mod is absent:

  addons/weapons_sps                 SPS rifles and MGs: barrel mass, and the KAC LAMG
                                     (5.56) moved onto the vanilla SPAR-16 sound sets
  addons/weapons_mcc                 MCC rifles: barrel mass
  addons/compatibility/jsrs_sps      SPS 5.56 / .300 BLK rifles on JSRS 2025's sound sets,
                                     the same sets MCC's own JSRS compats use per calibre

BARREL MASS uses jmfsb's rule (addons/weapons/CfgWeapons.hpp): 2 x ACE's fallback,
which is WeaponSlotsInfo mass / 40, so mass / 20. Both mods already set an explicit
ace_overheating_barrelMass (SPS ~1.7-2.1 on its 5.56 rifles, MCC a flat 3) - below
that rule, so FA's hotter rounds jam them early. A mod value already above the rule
is kept: this only ever makes a barrel heavier. Pistols are left alone.

SOUNDS are patched on every fire mode in place (class M: <its own parent>), because
the AI modes inherit from the vanilla parent's modes, not from the SPS class's own -
patching only Single/FullAuto would leave the AI on the old sound.

Sources (third-party, not in the repo; re-run after the mods update):
  D:/work/sps/x/SPS/Weapons/*/config.cpp
  D:/work/mcc/MCC/*/config.cpp
"""
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SPS = "D:/work/sps/x/SPS/Weapons"
MCC = "D:/work/mcc/MCC"

RULE_DIVISOR = 20  # jmfsb's rule: 2 x ACE's fallback (mass / 40)

VANILLA_SHOT = ["SPAR01_Shot_SoundSet", "SPAR01_Tail_SoundSet", "SPAR01_InteriorTail_SoundSet"]
VANILLA_SILENCED = ["SPAR01_silencerShot_SoundSet", "SPAR01_silencerTail_SoundSet", "SPAR01_silencerInteriorTail_SoundSet"]

# JSRS 2025 sets, as MCC's jsrs_*_compat addons pair them by calibre.
JSRS = {
    "556": (["jsrs_2025_spar_shot_soundset", "jsrs_2025_556mm_tails_soundset", "jsrs_2025_556mm_echo_soundset"],
            ["jsrs_2025_spar_shot_silenced_soundset", "jsrs_2025_556mm_silenced_tails_soundset"]),
    "300": (["jsrs_2025_vector_shot_soundset", "jsrs_2025_762mm_tails_soundset", "jsrs_2025_762mm_echo_soundset"],
            ["jsrs_2025_vector_shot_silenced_soundset", "jsrs_2025_762mm_silenced_tails_soundset"]),
}

# SPS base classes and the calibre each fires. Variants inherit the base's modes.
SPS_VANILLA_SOUND = {"SPS_KAC_LAMG_black_F": "556"}          # the only one not already on SPAR01
SPS_JSRS = {
    "sps_m27_base_f": "556",
    "SPS_hk416_base_f": "556",
    "SPS_KAC_LAMG_black_F": "556",
    "SPS_hk337_base_f": "300",
}
# SPS weapons with no vanilla/JSRS match here - they keep their parent's sound.
SPS_UNMATCHED = [
    ("SPS_hk417_base_f", "HK417", "7.62x51"),
    ("SPS_AI_AXMC_base_F", "AI AXMC", ".338 LM / .300 WM / .308"),
    ("SPS_KAC_LWAMG_Tan_F", "KAC LW AMG", "7.62x51 belt"),
    ("hk_vp9", "HK VP9", "9x19 pistol"),
    ("fk_brno", "FK Brno PSD", "7.5 FK pistol"),
]


# ---------------------------------------------------------------- config parser

class Node:
    def __init__(self, name, parent=None, extern=False):
        self.name, self.parent, self.extern = name, parent, extern
        self.props = {}       # lower name -> raw value text
        self.children = {}    # lower name -> Node
        self.order = []


TOKEN = re.compile(r'\s+|//[^\n]*|/\*.*?\*/|#[^\n]*|"(?:[^"]|"")*"|[A-Za-z0-9_.\-]+|[{}:;=,\[\]+]', re.S)


def tokens(text):
    out = []
    for m in TOKEN.finditer(text):
        s = m.group(0)
        if s[0].isspace() or s.startswith("//") or s.startswith("/*") or s.startswith("#"):
            continue
        out.append(s)
    return out


def parse(text):
    toks = tokens(text)
    i = 0

    def value(i):
        # a value up to ';' at depth 0, kept as raw text
        depth, start = 0, i
        while True:
            t = toks[i]
            if t == "{":
                depth += 1
            elif t == "}":
                depth -= 1
            elif t == ";" and depth == 0:
                return " ".join(toks[start:i]), i + 1
            i += 1

    def body(node, i):
        while i < len(toks):
            t = toks[i]
            if t == "}":
                return i + 2 if i + 1 < len(toks) and toks[i + 1] == ";" else i + 1
            if t == "class":
                name = toks[i + 1]
                i += 2
                parent = None
                if toks[i] == ":":
                    parent = toks[i + 1]
                    i += 2
                if toks[i] == ";":
                    child = Node(name, parent, extern=True)
                    i += 1
                else:
                    child = Node(name, parent)
                    i = body(child, i + 1)
                key = name.lower()
                if key not in node.children or not child.extern:
                    if key not in node.children:
                        node.order.append(key)
                    node.children[key] = child
                continue
            if t == "delete":
                i += 3
                continue
            name = t
            i += 1
            while toks[i] in ("[", "]", "+"):
                i += 1
            if toks[i] == "=":
                v, i = value(i + 1)
                node.props[name.lower()] = v
            else:
                i += 1
        return i

    root = Node("root")
    body(root, 0)
    return root


def num(raw):
    try:
        return float(raw)
    except (TypeError, ValueError):
        return None


# ---------------------------------------------------------------- mod reading

def read_mod(files, prefix):
    """Top-level CfgWeapons classes a mod owns (name starts with prefix): name -> dict.
    Vanilla classes the mod restates (Rifle_Base_F, MMG_01_base_F...) count as outside it."""
    classes = {}
    for f in files:
        root = parse(open(f, encoding="utf-8", errors="replace").read())
        patches = root.children.get("cfgpatches")
        patch = patches.children[patches.order[0]].name if patches and patches.order else None
        weapons = root.children.get("cfgweapons")
        if not weapons:
            continue
        for key in weapons.order:
            n = weapons.children[key]
            if n.extern or not key.startswith(prefix):
                continue
            slots = n.children.get("weaponslotsinfo")
            classes[n.name.lower()] = {
                "node": n, "name": n.name, "parent": n.parent, "patch": patch,
                "file": os.path.basename(os.path.dirname(f)),
                "mass": num(slots.props.get("mass")) if slots else None,
                "barrel": num(n.props.get("ace_overheating_barrelmass")),
            }
    return classes


def chain(classes, key):
    out = []
    while key in classes and len(out) < 64:
        out.append(classes[key])
        key = (classes[key]["parent"] or "").lower()
    return out, key   # key = first ancestor outside the mod


def inherited(classes, key, field):
    for c in chain(classes, key)[0]:
        if c[field] is not None:
            return c[field]
    return None


def barrel_patches(classes, skip_root=("hgun_", "pistol", "launcher")):
    """Classes whose barrel mass goes up under the rule, in parent-first order."""
    order, seen = [], set()

    def visit(k):
        if k in seen or k not in classes:
            return
        seen.add(k)
        visit((classes[k]["parent"] or "").lower())
        order.append(k)

    for k in classes:
        visit(k)

    patched = {}   # key -> value the patched config ends up with
    out = []
    for k in order:
        c = classes[k]
        outside = chain(classes, k)[1]
        if outside.startswith(skip_root):
            continue
        mass = inherited(classes, k, "mass")
        if mass is None:
            continue
        parent = (c["parent"] or "").lower()
        # what this class reads with no patch of its own
        current = c["barrel"] if c["barrel"] is not None else patched.get(parent, inherited(classes, parent, "barrel"))
        mod_value = inherited(classes, k, "barrel")
        want = round(max(mass / RULE_DIVISOR, mod_value or 0), 2)
        if current is not None and abs(current - want) < 0.005:
            patched[k] = current
            continue
        patched[k] = want
        out.append((c, mass, mod_value, want))
    return out


# ---------------------------------------------------------------- emitting

def arr(items):
    return "{" + ", ".join('"%s"' % s for s in items) + "}"


def fmt(v):
    return ("%.2f" % v).rstrip("0").rstrip(".")


def modes_of(node):
    m = node.props.get("modes")
    return re.findall(r'"([^"]+)"', m) if m else []


def sound_block(c, shot, silenced, ind):
    """Every fire mode of class c, patched in place with the given sound sets."""
    node = c["node"]
    lines = []
    for mode in modes_of(node):
        own = node.children.get(mode.lower())
        parent = own.parent if own and not own.extern else mode
        lines += [
            ind + "class %s: %s {" % (mode, parent),
            ind + "    class BaseSoundModeType;",
            ind + "    class StandardSound: BaseSoundModeType {",
            ind + "        soundSetShot[] = %s;" % arr(shot),
            ind + "    };",
            ind + "    class SilencedSound: BaseSoundModeType {",
            ind + "        soundSetShot[] = %s;" % arr(silenced),
            ind + "    };",
            ind + "};",
        ]
    return lines


def mode_externs(c):
    """Modes whose parent is the same-named mode of c's parent (inherited, or restated as
    class M: M): they need declaring on that parent."""
    node = c["node"]
    out = []
    for m in modes_of(node):
        own = node.children.get(m.lower())
        if not own or own.extern or (own.parent or "").lower() == m.lower():
            out.append(m)
    return out


def root_externs(c):
    node = c["node"]
    out = []
    for m in modes_of(node):
        own = node.children.get(m.lower())
        if own and not own.extern and own.parent and own.parent.lower() != m.lower():
            out.append(own.parent)
    return out


def weapons_hpp(classes, patches, sounds, header):
    """CfgWeapons body: barrel patches plus in-place sound patches, parents declared first."""
    body = {}           # key -> list of lines inside the class
    comment = {}
    for c, mass, mod_value, want in patches:
        k = c["name"].lower()
        body.setdefault(k, []).append("        ace_overheating_barrelMass = %s;" % fmt(want))
        comment[k] = "mass %s -> rule %s, mod had %s" % (fmt(mass), fmt(mass / RULE_DIVISOR),
                                                         fmt(mod_value) if mod_value is not None else "none")
    for name, (shot, silenced) in sounds.items():
        k = name.lower()
        body.setdefault(k, []).extend(sound_block(classes[k], shot, silenced, "        "))

    keys = [k for k in order_parent_first(classes) if k in body]
    emitted = set(keys)
    roots, declared, externs = [], set(), []
    vanilla_modes = {}
    for k in keys:
        c = classes[k]
        p = c["parent"]
        if k in {n.lower() for n in sounds}:
            vanilla_modes.setdefault(p, set()).update(mode_externs(c))
            for r in root_externs(c):
                if r.lower() not in declared:
                    declared.add(r.lower())
                    roots.append("class %s;" % r)
        if p.lower() not in emitted and p.lower() not in declared:
            declared.add(p.lower())
            externs.append(p)

    lines = ["// Generated by tools/gen_weapon_patches.py - re-run it rather than hand-edit.", "// " + header]
    lines += roots
    lines += ["class CfgWeapons {"]
    for p in externs:
        if p in vanilla_modes and vanilla_modes[p]:
            gp = vanilla_parent(classes, p)
            decl = "    class %s%s {" % (p, ": " + gp if gp else "")
            lines.append(decl)
            lines += ["        class %s;" % m for m in sorted(vanilla_modes[p])]
            lines.append("    };")
            if gp and gp.lower() not in declared:
                lines.insert(lines.index(decl), "    class %s;" % gp)
                declared.add(gp.lower())
        else:
            lines.append("    class %s;" % p)
    for k in keys:
        c = classes[k]
        lines.append("")
        if k in comment:
            lines.append("    // %s" % comment[k])
        lines.append("    class %s: %s {" % (c["name"], c["parent"]))
        lines += body[k]
        lines.append("    };")
    lines.append("};")
    return "\n".join(lines) + "\n"


VANILLA_PARENTS = {
    "arifle_spar_01_base_f": "Rifle_Base_F",
    "lmg_mk200_f": "Rifle_Long_Base_F",
}


def vanilla_parent(classes, p):
    gp = VANILLA_PARENTS.get(p.lower())
    if gp is None:
        sys.exit("gen_weapon_patches: no vanilla parent recorded for %s - add it to VANILLA_PARENTS" % p)
    return gp


def order_parent_first(classes):
    order, seen = [], set()

    def visit(k):
        if k in seen or k not in classes:
            return
        seen.add(k)
        visit((classes[k]["parent"] or "").lower())
        order.append(k)

    for k in classes:
        visit(k)
    return order


def required(classes, keys):
    out = []
    for k in keys:
        for c in chain(classes, k)[0]:
            if c["patch"] and c["patch"] not in out:
                out.append(c["patch"])
    return out


SCRIPT_COMPONENT = """#define COMPONENT {comp}
#define COMPONENT_BEAUTIFIED {beaut}
#include "\\z\\jmfsb\\addons\\main\\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_{up}
    #define DEBUG_MODE_FULL
#endif
    #ifdef DEBUG_SETTINGS_{up}
    #define DEBUG_SETTINGS DEBUG_SETTINGS_{up}
#endif

#include "\\z\\jmfsb\\addons\\main\\script_macros.hpp"
"""

SUB_SCRIPT_COMPONENT = """#define SUBCOMPONENT {sub}
#include "..\\script_component.hpp"
"""

CONFIG = """#include "script_component.hpp"

// Generated by tools/gen_weapon_patches.py - re-run it rather than hand-edit.
class CfgPatches {{
    class {cls} {{
        name = COMPONENT_NAME;
        units[] = {{}};
        weapons[] = {{}};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {{{req}}};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    }};
}};

#include "CfgWeapons.hpp"
"""


def write(path, text, report):
    if report:
        return
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(text)


def write_readme(path, title, patch, blurb, report):
    """Written once; after that the top half is hand-kept and the generated half belongs to gen_addon_readmes."""
    if report or os.path.exists(path):
        return
    write(path, "# %s\n\n`%s`\n\n%s\n" % (title, patch, blurb), report)


def addon(folder, comp, beaut, req, hpp, blurb, report, sub=None):
    base = os.path.join(ROOT, "addons", folder)
    if sub:
        write(os.path.join(base, "script_component.hpp"), SUB_SCRIPT_COMPONENT.format(sub=sub), report)
    else:
        write(os.path.join(base, "$PBOPREFIX$"), "z\\jmfsb\\addons\\%s\n" % comp, report)
        write(os.path.join(base, "script_component.hpp"),
              SCRIPT_COMPONENT.format(comp=comp, beaut=beaut, up=comp.upper()), report)
        write_readme(os.path.join(base, "README.md"), beaut, "jmfsb_" + comp, blurb, report)
    req_text = ", ".join('"%s"' % r for r in req)
    write(os.path.join(base, "config.cpp"), CONFIG.format(cls="SUBADDON" if sub else "ADDON", req=req_text), report)
    write(os.path.join(base, "CfgWeapons.hpp"), hpp, report)


def main():
    report = "--report" in sys.argv
    sps = read_mod(sorted(glob.glob(SPS + "/*/config.cpp")), "sps_")
    mcc = read_mod(sorted(glob.glob(MCC + "/*/config.cpp")), "mcc_")
    if not sps or not mcc:
        sys.exit("gen_weapon_patches: SPS or MCC source not found (%s, %s)" % (SPS, MCC))

    for k in list(SPS_VANILLA_SOUND) + list(SPS_JSRS):
        if k.lower() not in sps:
            sys.exit("gen_weapon_patches: SPS class %s is gone - update the tables" % k)

    # SPS: barrel mass + LAMG on SPAR01
    sps_barrel = barrel_patches(sps)
    sps_sound = {k: (VANILLA_SHOT, VANILLA_SILENCED) for k in SPS_VANILLA_SOUND}
    keys = [c["name"].lower() for c, *_ in sps_barrel] + [k.lower() for k in sps_sound]
    hpp = weapons_hpp(sps, sps_barrel, sps_sound,
                      "SPS barrel mass to jmfsb's rule (mass / 20); KAC LAMG (5.56) on the vanilla SPAR-16 sound sets.")
    addon("weapons_sps", "weapons_sps", "Weapons_sps", ["jmfsb_main", "ace_overheating"] + required(sps, keys), hpp,
          "Barrel mass on the SPS rifles and MGs to jmfsb's rule (mass / 20), so FA ammunition\n"
          "does not jam them early; the KAC LAMG moved onto the vanilla SPAR-16 (5.56) sound sets.", report)

    # MCC: barrel mass
    mcc_barrel = barrel_patches(mcc)
    keys = [c["name"].lower() for c, *_ in mcc_barrel]
    hpp = weapons_hpp(mcc, mcc_barrel, {}, "MCC barrel mass to jmfsb's rule (mass / 20).")
    addon("weapons_mcc", "weapons_mcc", "Weapons_mcc", ["jmfsb_main", "ace_overheating"] + required(mcc, keys), hpp,
          "Barrel mass on the MCC rifles to jmfsb's rule (mass / 20), so FA ammunition does not\n"
          "jam them early.", report)

    # JSRS for SPS
    jsrs_sound = {k: JSRS[cal] for k, cal in SPS_JSRS.items()}
    hpp = weapons_hpp(sps, [], jsrs_sound, "SPS 5.56 and .300 BLK rifles on JSRS 2025's sound sets, paired as MCC's JSRS compats pair them.")
    req = ["jmfsb_weapons_sps", "jsrs2025_config_c"] + required(sps, [k.lower() for k in jsrs_sound])
    addon(os.path.join("compatibility", "jsrs_sps"), None, None, req, hpp, None, report, sub="jsrs_sps")

    print("weapons_sps: %d barrel patches, %d sound patches" % (len(sps_barrel), len(sps_sound)))
    print("weapons_mcc: %d barrel patches" % len(mcc_barrel))
    print("jsrs_sps:    %d sound patches" % len(jsrs_sound))
    if report:
        for name, rows in (("SPS", sps_barrel), ("MCC", mcc_barrel)):
            for c, mass, mod_value, want in rows:
                print("  %-4s %-48s mass %6s  mod %5s  -> %s" % (name, c["name"], fmt(mass),
                      fmt(mod_value) if mod_value is not None else "-", fmt(want)))
    print("SPS weapons with no sound match (keep their parent's sound):")
    for _k, name, cal in SPS_UNMATCHED:
        print("  %-12s %s" % (name, cal))


if __name__ == "__main__":
    main()
