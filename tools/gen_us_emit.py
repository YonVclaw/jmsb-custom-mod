"""Emission half of the US faction rebuild (imports the tables from gen_us.py)."""
import os, io, sys, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
_D = os.path.dirname(os.path.abspath(__file__))
A3PATCH = json.load(io.open(os.path.join(_D, "a3_patches.json"), encoding="utf-8"))
MODPATCH = json.load(io.open(os.path.join(_D, "mod_patches.json"), encoding="utf-8"))
from gen_us import (A3C as A3CLS, MDC as MODCLS, C, CI, A3G, MDG, FACTIONS, FAMILIES, MAP, TMAP, UNMAPPED, BASE,
                    fa_of, real, chain, res, res_turrets, roster_of, spar_swap,
                    SIXFIVE, q, arr_lines, GEAR, regear, DRONES, uniform_for, QAV_VEHICLES, ALWAYS, OVERRIDES)


# Classes whose parents are not loaded here (Contact story characters, FIR AWS).
# Cloning them produces "No entry ....scope / .vehicleClass" spam in the RPT.
CLASS_BLOCK_PREFIX = ("B_W_Story_", "B_T_Story_", "B_Story_", "FIR_", "E22_")


def blocked_class(n):
    return n.startswith(CLASS_BLOCK_PREFIX)


def is_static(n):
    return bool(set(chain(n)) & {"StaticWeapon", "StaticMGWeapon", "StaticCannon",
                                 "StaticGrenadeLauncher", "StaticMortar"})


def is_man(n):
    return bool(set(chain(n)) & {"CAManBase", "Man", "SoldierWB"})


# Addons that exist in the config dumps but are NOT loaded by the game, so they
# must never appear in requiredAddons (skipWhenMissingDependencies would drop the
# whole faction). Sourced from the launch RPT's "is not present" reports.
#   - Contact is an optional expansion: installed here but not enabled.
#   - the Aegis FIR compat pbo only ships when FIR AWS is present.
DEP_BLOCKLIST = {
    "A3_Characters_F_Contact",
    "A3_Data_F_Contact",
    "A3_Air_F_Contact",
    "A3_Armor_F_Contact",
    "A3_Soft_F_Contact",
    "A3_Static_F_Contact",
    "A3_Structures_F_Contact",
    "A3_Weapons_F_Contact",
    "A3_Aegis_Air_F_Aegis_Plane_Fighter_01_FIRCompat",
}
_missing = os.path.join(_D, "missing.txt")
if os.path.exists(_missing):          # everything the last launch reported absent
    DEP_BLOCKLIST |= set(io.open(_missing).read().split())

# blocked sub-pbo -> the root pbo of the same mod folder, e.g.
# A3_Aegis/air_f_aegis/plane_fighter_01 -> A3_Aegis/air_f_aegis
DEP_ROOT = {}
for _tbl in (A3PATCH, MODPATCH):
    for _folder, _names in _tbl.items():
        _parent = _folder.rsplit("/", 1)[0]
        if _parent == _folder:
            continue
        for _root in _tbl.get(_parent, []):
            for _n in _names:
                DEP_ROOT.setdefault(_n, _root)


def turret_override(paths_mags, ind):
    tree = {}
    for p, mags in paths_mags.items():
        parts = p.split("/")
        node = tree
        for i, part in enumerate(parts):
            ent = node.setdefault(part, {"_kids": {}, "_mags": None})
            if i == len(parts) - 1:
                ent["_mags"] = mags
            node = ent["_kids"]

    def emit(node, ind):
        out = ["%sclass Turrets: Turrets {" % ind]
        for name, ent in node.items():
            out.append("%s    class %s: %s {" % (ind, name, name))
            if ent["_mags"]:
                out += arr_lines("magazines", ent["_mags"], ind + "        ")
            if ent["_kids"]:
                out += emit(ent["_kids"], ind + "        ")
            out.append("%s    };" % ind)
        out.append("%s};" % ind)
        return out
    return emit(tree, ind)


SPARCAL = {"556": "30Rnd_556x45_Stanag", "762": "20Rnd_762x51_Mag"}

# ---------------------------------------------------------------------------
# Every faction gets the FULL group tree: the union of all four source factions'
# CfgGroups. A slot is filled with the faction's own class when it has one for
# that role, otherwise it is back-filled from a donor faction (and that donor
# class is cloned into the faction so the reference resolves).
# ---------------------------------------------------------------------------
import re as _re

DONORS = {                      # camo -> donor camos, in priority order
    "arid":     ["tropical", "woodland", "desert"],
    "tropical": ["arid", "woodland", "desert"],
    "woodland": ["tropical", "arid", "desert"],
    "desert":   ["arid", "tropical", "woodland"],
    # camo variants: BLU_F roster, so arid is the natural donor
    "ocp":      ["arid", "tropical", "woodland", "desert"],
    "snow":     ["arid", "tropical", "woodland", "desert"],
}


def rkey(n):
    s = n.lower()
    s = _re.sub(r'^(aegis_|atlas_)', '', s)
    s = _re.sub(r'_lxws$', '', s)
    s = _re.sub(r'^b_', '', s)
    s = _re.sub(r'^(d_|t_|w_|a_|r_)', '', s)
    s = _re.sub(r'_f$', '', s)
    s = _re.sub(r'_(v2|old|rf)$', '', s)
    return s


_ROSTERS = {}
for _camo, (_fac, _col) in FACTIONS.items():
    _ROSTERS[_camo] = sorted(roster_of(_fac))

_INDEX = {}
for _camo, _r in _ROSTERS.items():
    m = {}
    for n in sorted(_r, key=lambda x: (len(x), x)):
        m.setdefault(rkey(n), n)
    _INDEX[_camo] = m

UNION = {}
for _camo, (_fac, _col) in FACTIONS.items():
    for _GS in (A3G, MDG):
        if _fac not in _GS:
            continue
        for _cn, _cv in _GS[_fac]["cats"].items():
            for _gn, _g in _cv["groups"].items():
                UNION.setdefault((_cn, _gn), (_cv["name"], _g))


def role_class(camo, k):
    """class covering role `k` for this faction: its own if it has one, else a
    donor faction's (donors are tried in priority order)."""
    if k in _INDEX[camo]:
        return _INDEX[camo][k], False
    for don in DONORS[camo]:
        if k in _INDEX[don]:
            return _INDEX[don][k], True
    return None, False


def slot_class(camo, vehicle):
    k = rkey(vehicle)
    cls, borrowed = role_class(camo, k)
    if cls:
        return cls, borrowed
    r = real(vehicle)
    return (r, True) if r else (None, False)


# Every faction fields the SAME roster: the union of every role any of the four
# source factions has. A faction uses its own class for a role when it has one,
# otherwise it clones a donor's.
ROLE_UNION = set()
for _camo in FACTIONS:
    ROLE_UNION |= set(_INDEX[_camo])


def gen(fam, camo):
    fac, col = FACTIONS[camo]
    is_spar = FAMILIES[fam]
    comp = "faction_b_us_%s_%s" % (fam, camo)
    fcls = "jmfsb_b_us_%s_%s" % (fam, camo)
    disp = "US %s (%s)" % ("SPAR" if is_spar else "MX", camo.capitalize())
    d = os.path.join(BASE, comp)
    os.makedirs(d, exist_ok=True)

    def W(n, c):
        io.open(os.path.join(d, n), "w", encoding="utf-8", newline="\n").write(c)

    io.open(os.path.join(d, "$PBOPREFIX$"), "w", newline="\n").write(
        "z\\jmfsb\\addons\\%s\n" % comp)

    W("script_component.hpp",
      '#define COMPONENT %s\n#define COMPONENT_BEAUTIFIED %s\n'
      '#include "\\z\\jmfsb\\addons\\main\\script_mod.hpp"\n'
      '#include "\\z\\jmfsb\\addons\\main\\script_macros.hpp"\n' % (comp, disp))

    W("CfgFactionClasses.hpp",
      'class CfgFactionClasses {\n'
      '    class %s {\n'
      '        displayName = "[JMSB] %s";\n'
      '        priority = 3;\n'
      '        side = 1;\n'
      '        icon = "\\A3\\ui_f\\data\\map\\markers\\nato\\b_inf.paa";\n'
      '        flag = "\\A3\\Data_F\\Flags\\flag_nato_co.paa";\n'
      '    };\n};\n' % (fcls, disp))

    # roster = the faction's own classes, plus any class a group slot needs that
    # the faction has no counterpart for (back-filled from a donor faction)
    base = set(_ROSTERS[camo])
    slots, extra, borrowed_n = {}, set(), 0
    # fielded by every faction regardless of what its source faction issued
    extra.update(n for n in ALWAYS if n not in base)
    # equalise: every faction covers every role any faction has. Purely additive
    # -- nothing the faction already had is dropped.
    for k in sorted(ROLE_UNION):
        cls, borrowed = role_class(camo, k)
        if cls and cls not in base:
            extra.add(cls)
    for (cn, gn), (catname, g) in UNION.items():
        us = []
        for u in g["units"]:
            cls, borrowed = slot_class(camo, u["vehicle"])
            if not cls:
                continue
            if cls not in base:
                extra.add(cls)
            if borrowed:
                borrowed_n += 1
            us.append((cls, u["rank"], u["position"]))
        if us:
            slots[(cn, gn)] = (catname, g, us)
    roster = sorted(n for n in (base | extra) if not blocked_class(n))
    clone = {n: "jmfsb_%s_%s" % (comp, n) for n in roster}
    # mod drones: units only, no group slots, no entry in the class tables
    # (note: `d` is the addon dir -- do not shadow it here)
    drones = [x for x in (DRONES + QAV_VEHICLES)
              if x not in clone and not blocked_class(x)]
    for dr in drones:
        clone[dr] = "jmfsb_%s_%s" % (comp, dr)

    plain, structured, bodies = set(), {}, []
    nmag = nwep = ntur = 0
    for n in roster:
        mags = res(n, "magazines") or []
        weps = res(n, "weapons") or []
        newweps, cal = None, None
        if is_spar and weps:
            sw, cal = spar_swap(weps)
            if sw != weps:
                newweps = sw
        newmags, changed = [], False
        for m in mags:
            f = None
            if newweps and cal and m.startswith(SIXFIVE):
                f = fa_of(SPARCAL[cal], col, MAP)
            if not f:
                f = fa_of(m, col, MAP)
            if f:
                newmags.append(f); changed = True
            else:
                newmags.append(m)
        if changed:
            nmag += 1
        if newweps:
            nwep += 1

        tnew = {}
        # A turret override forces a forward-decl skeleton, and an empty nested
        # `class <Turret>;` SEVERS the inherited turret (hundreds of "No entry
        # .../CodRiverTurret.maxHorizontalRotSpeed" lines). Only the MainTurret
        # path is safe -- that is the shape the old build proved works. Statics
        # and secondary turrets (CodRiverTurret, TopTurret, ...) are left stock.
        tur = {} if is_static(n) else {
            k: v for k, v in res_turrets(n).items()
            if k == "MainTurret"
        }
        for path, tm in tur.items():
            conv = [fa_of(x, col, TMAP) or x for x in tm]
            if conv != tm:
                tnew[path] = conv

        b = ["    class %s: %s {" % (clone[n], n),
             "        scope = 2;",
             "        scopeCurator = 2;",
             "        side = 1;",
             '        faction = "%s";' % fcls]
        for prop, why in OVERRIDES.get(n, []):
            b.append("        %s%s" % (prop, "    // %s" % why if why else ""))
        if changed:
            b += arr_lines("magazines", newmags, "        ")
            b += arr_lines("respawnMagazines", newmags, "        ")
        if newweps:
            b += arr_lines("weapons", newweps, "        ")
            b += arr_lines("respawnWeapons", newweps, "        ")
        # Camo-variant factions get the full jmfsb OCP/snow re-dress; the four
        # source factions keep their issued kit and only get the uniform.
        if is_man(n) and uniform_for(camo):
            if camo in GEAR:
                nl, nb = regear(camo, res(n, "linkedItems"), res(n, "backpack"))
                if nl:
                    b += arr_lines("linkedItems", nl, "        ")
                    b += arr_lines("respawnLinkedItems", nl, "        ")
                if nb:
                    b.append('        backpack = "%s";' % nb)
            uni = uniform_for(camo)
            # Extended_Init_EventHandlers, not a bare EventHandlers class -- the
            # latter severs the base's CBA XEH support
            b.append("        class Extended_Init_EventHandlers {")
            b.append("            class ADDON {")
            b.append('                init = "params [\'_u\']; _u forceAddUniform \'%s\';";' % uni)
            b.append("            };")
            b.append("        };")
        crew = res(n, "crew")
        if crew and real(crew) in clone:
            b.append('        crew = "%s";' % clone[real(crew)])
        if tnew:
            b += turret_override(tnew, "        ")
            # skeleton only for the turrets we actually override -- declaring the
            # rest creates phantom empty classes (CBA 3DEN preload warnings)
            structured[n] = sorted(tnew.keys())
            ntur += 1
        else:
            plain.add(n)
        b.append("    };")
        bodies += b

    # Forward declarations. Structured (turret-skeleton) decls must follow their
    # own parent, so emit them depth-first rather than alphabetically -- HEMTT
    # L-C04 fires when a parent appears later in the file.
    fwd, emitted = [], set()

    def emit_plain(x):
        if x in emitted:
            return
        emitted.add(x)
        fwd.append("    class %s;" % x)

    def emit_struct(x, guard=()):
        """Declaration chain that makes `class Turrets: Turrets` legal to rapify.

        Each level restates its own parent and only DECLARES the nested name --
        never gives it a body of its own, which would sever the vanilla class
        (that was the "No entry .../Turrets/MainTurret.<prop>" RPT flood). One
        declaration level per turret depth, so the level above always declares
        what the level below inherits from.
        """
        if x in emitted or x in guard:
            return
        # deepest path this class overrides: MainTurret -> 2, MainTurret/X -> 4
        names, depth = ["MainTurret"], 2
        chain = [x]
        c = x
        for _ in range(depth):
            c = real(C.get(c, {}).get("parent") or "")
            if not c:
                break
            chain.append(c)
        # topmost is a bare extern, each one below adds a level
        for i, c in enumerate(reversed(chain)):
            if c in emitted:
                continue
            emitted.add(c)
            if i == 0:
                fwd.append("    class %s;" % c)
                continue
            p = real(C.get(c, {}).get("parent") or "")
            fwd.append("    class %s: %s {" % (c, p))
            ind = "        "
            for lvl in range(1, i + 1):
                nm = "Turrets" if lvl % 2 else names[lvl // 2 - 1]
                if lvl == i:
                    fwd.append("%sclass %s;" % (ind, nm))
                else:
                    fwd.append("%sclass %s: %s {" % (ind, nm, nm))
                    ind += "    "
            for lvl in range(i - 1, 0, -1):
                ind = ind[:-4]
                fwd.append("%s};" % ind)
            fwd.append("    };")

    for n in sorted(plain):
        emit_plain(n)
    for n in sorted(structured):
        emit_struct(n)

    if drones:
        fwd.append("    // mod drones (owning mods intentionally not in requiredAddons)")
        for dr in drones:
            fwd.append("    class %s;" % dr)
        bodies.append("    // ==== mod drone units fielded by every US faction ====")
        for dr in drones:
            bodies.append("    class %s: %s {" % (clone[dr], dr))
            bodies.append("        scope = 2;")
            bodies.append("        scopeCurator = 2;")
            bodies.append("        side = 1;")
            bodies.append('        faction = "%s";' % fcls)
            bodies.append("    };")
    v = ["class CfgVehicles {"] + fwd + [""] + bodies + ["};"]
    W("CfgVehicles.hpp", "\n".join(v) + "\n")

    cats = {}
    for (cname, gname), (catname, g, us) in slots.items():
        cat = cats.setdefault(cname, {"name": catname, "groups": {}})
        cat["groups"][gname] = {"name": g["name"], "icon": g["icon"], "units": us}

    gl = ["class CfgGroups {", "    class West {", "        class %s {" % fcls,
          '            name = "[JMSB] %s";' % disp]
    ngroups = 0
    for cname in sorted(cats):
        cat = cats[cname]
        if not cat["groups"]:
            continue
        gl.append("            class %s {" % cname)
        gl.append('                name = "%s";' % cat["name"])
        for gname in sorted(cat["groups"]):
            g = cat["groups"][gname]
            ngroups += 1
            gl.append("                class GVAR(%s) {" % gname)
            gl.append('                    name = "%s";' % g["name"])
            gl.append("                    side = 1;")
            gl.append('                    faction = "%s";' % fcls)
            if g["icon"]:
                gl.append('                    icon = "%s";' % g["icon"])
            for k, (cls, rank, pos) in enumerate(g["units"]):
                raw = pos.replace(" ", "").replace("\n", "").strip("{}")
                xyz = [p for p in raw.split(",") if p] or ["0", "0", "0"]
                while len(xyz) < 3:
                    xyz.append("0")
                gl.append("                    class Unit%d {" % k)
                gl.append("                        side = 1;")
                gl.append('                        vehicle = "%s";' % clone[cls])
                gl.append('                        rank = "%s";' % rank)
                gl.append("                        position[] = {%s, %s, %s};" % tuple(xyz))
                gl.append("                    };")
            gl.append("                };")
        gl.append("            };")
    gl += ["        };", "    };", "};"]
    W("CfgGroups.hpp", "\n".join(gl) + "\n")

    units = ",\n            ".join("QGVAR(%s)" % n for n in roster + drones)
    # every pbo that defines a class we inherit from has to be a dependency, or
    # the clone has no parent at runtime
    # collect the src pbo from BOTH tables: the merged table keeps only the mod's
    # src, which hides the vanilla pbo a class originally comes from
    # (B_T_LSV_01_AT_F -> soft_f_exp/lsv_01 as well as A3_Aegis/soft_f_aegis/lsv_01)
    srcs = set()
    for n in roster:
        for k in chain(n):
            for tbl in (C, A3CLS, MODCLS):
                v = tbl.get(k, {}).get("src")
                if v:
                    srcs.add(v)
    # Require the mod's ROOT pbo per source folder, not every individual sub-pbo:
    # listing ~130 sub-pbos is unmanageable and any one of them being absent drops
    # the faction. Vanilla A3 is not listed at all (it always loads first); only
    # A3_Characters_F_BLUFOR is kept as the base-class anchor.
    patches = set()
    for s in srcs:
        parts = s.split("/")
        if parts[0] in ("A3_Aegis", "A3_Atlas"):
            top = "/".join(parts[:2])             # A3_Aegis/characters_f_aegis
        else:
            top = parts[0]                        # vanilla pbo root, e.g. soft_f_exp
        for tbl in (A3PATCH, MODPATCH):
            if top in tbl:
                patches.update(tbl[top])
        # vanilla per-vehicle sub-pbos are separate addons (A3_Soft_F_Exp_LSV_01),
        # so declare the exact one too when it exists
        for tbl in (A3PATCH, MODPATCH):
            if s in tbl:
                patches.update(tbl[s])
    # skipWhenMissingDependencies drops the WHOLE faction if one entry is absent,
    # so never require anything the game does not actually load: the Contact
    # expansion is optional (installed but not enabled here) and a few mod pbos
    # are compat-only. Verified against the launch RPT.
    # A blocked sub-pbo still needs its parent pbo required, so load order for the
    # rest of that mod's content is kept -- swap in the root patch instead.
    blocked = patches & DEP_BLOCKLIST
    patches -= DEP_BLOCKLIST
    for b in blocked:
        root = DEP_ROOT.get(b)
        if root and root not in DEP_BLOCKLIST:
            patches.add(root)
    reqs = ['"jmfsb_main"',
            # vanilla pbos the cloned loadouts/vehicles pull from (all verified present)
            '"A3_Characters_F_BLUFOR"', '"A3_Weapons_F_Exp_Rifles_SPAR_01"',
            '"A3_Weapons_F_Exp_Rifles_SPAR_03"', '"A3_Armor_F_Exp_MBT_01"',
            '"A3_Air_F_Exp_UAV_03"',
            # QAV mod vehicles the US rosters field
            '"QAV_AbramsX"', '"qav_marshall"',
            '"jmfsbfa_ammo"', '"jmfsbfa_vehicles"',
            '"jmfsbfa_maincaliber"', '"jmfsbfa_mediumcaliber"',
            '"jmfsbfa_grenade_40mm"', '"jmfsbfa_missiles"']
    reqs += ['"%s"' % p for p in sorted(patches)]
    if camo == "desert":
        reqs.append('"data_f_lxWS_Loadorder"')
    W("config.cpp", '''#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            %s
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            %s
        };
        skipWhenMissingDependencies = 1;
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion/";
        author = QAUTHOR;
        authors[] = {"JMSB"};
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
''' % (units, ",\n            ".join(reqs)))
    return comp, len(roster), ngroups, nmag, nwep, ntur, borrowed_n


if __name__ == "__main__":
    tot = 0
    for fam in FAMILIES:
        for camo in FACTIONS:
            comp, nc, ng, nm, nw, nt, nb = gen(fam, camo)
            tot += nc
            print("%-30s classes=%-4d groups=%-3d famags=%-4d sparwep=%-4d turrets=%-3d borrowed=%d"
                  % (comp, nc, ng, nm, nw, nt, nb))
    print("total cloned classes:", tot)
    if UNMAPPED:
        print("FA targets that do not exist (kept vanilla):")
        for k, c in UNMAPPED.most_common(20):
            print("   ", k, c)
