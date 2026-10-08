"""Clone the Aegis CSAT Russia faction (OPF_R_F) into jmfsb with futureAmmo.

Same approach as the FDF/US ports: units are subclassed from the Aegis classes so
they keep their own gear and models, only ammunition changes. Drones follow the
faction_o_raf pattern -- the faction's own UAV units plus the GX / loitering
munition set, and a drone operator in every infantry group.
"""
import os, io, json, collections

D = os.path.dirname(os.path.abspath(__file__))
BASE = r"O:\GIT\jmfsb\addons"
COMP = "faction_o_opfr"
FCLS = "jmfsb_o_opfr"
DISP = "CSAT Russia"
COL = "Green"                      # matches faction_o_raf

A3C = json.load(io.open(os.path.join(D, "a3_classes.json"), encoding="utf-8"))
MDC = json.load(io.open(os.path.join(D, "mod_classes.json"), encoding="utf-8"))
A3G = json.load(io.open(os.path.join(D, "a3_groups.json"), encoding="utf-8"))
MDG = json.load(io.open(os.path.join(D, "mod_groups.json"), encoding="utf-8"))
A3P = json.load(io.open(os.path.join(D, "a3_patches.json"), encoding="utf-8"))
MDP = json.load(io.open(os.path.join(D, "mod_patches.json"), encoding="utf-8"))
FA = set(io.open(os.path.join(D, "fa_classes.txt")).read().split())
BLOCK = set(io.open(os.path.join(D, "missing.txt")).read().split()) | {
    "A3_Characters_F_Contact", "A3_Data_F_Contact"}

C = {}
for src in (A3C, MDC):
    for k, v in src.items():
        C.setdefault(k, {}).update(v)
CI = {k.lower(): k for k in C}


def real(n):
    return CI.get((n or "").lower())


def chain(n):
    out, seen, k = [], set(), real(n)
    while k and k not in seen:
        seen.add(k); out.append(k); k = real(C[k].get("parent"))
    return out


def res(n, key):
    for k in chain(n):
        if key in C[k]:
            return C[k][key]
    return None


def res_turrets(n):
    acc = {}
    for k in reversed(chain(n)):
        for p, d in (C[k].get("turrets") or {}).items():
            if d.get("magazines") is not None:
                acc[p] = d["magazines"]
    return acc


MAP = {
    "30Rnd_545x39_AK12_Mag_F":        "FA_Aegis_30Rnd_545x39_7N44",
    "30Rnd_545x39_AK12_Mag_Tracer_F": "FA_Aegis_30Rnd_545x39_7N44",
    "45Rnd_545x39_AK12_Mag_F":        "FA_Aegis_45Rnd_545x39_7N44",
    "60Rnd_545x39_AK12_Mag_F":        "FA_Aegis_60Rnd_545x39_7N44",
    "75Rnd_545x39_AK12_Mag_F":        "FA_Aegis_60Rnd_545x39_7N44",
    "30Rnd_762x39_AK12_Lush_Mag_F":   "FA_30Rnd_762x39_7N43",
    "30rnd_762x39_AK12_Lush_Mag_F":   "FA_30Rnd_762x39_7N43",
    "75Rnd_762x39_AK12_Lush_Mag_F":   "FA_75Rnd_762x39_7N43",
    "20rnd_127x55_mag_rf":            "FA_20Rnd_127x55_7N52",
    "10rnd_127x55_mag_rf":            "FA_10Rnd_127x55_7N52",
    "10Rnd_762x54_Mag":               "FA_Aegis_10Rnd_762x54_SVD_HV",
    "150Rnd_762x54_Box":              "FA_150Rnd_762x54_Box",
    "1Rnd_HE_Grenade_shell":          "FA_1Rnd_40mm_Mk380_NRP",
    "3Rnd_HE_Grenade_shell":          "FA_1Rnd_40mm_Mk380_NRP",
}
TMAP = {
    "200Rnd_762x51_Belt_Red":               "FA_200Rnd_762_M80A2_HV",
    "100Rnd_127x99_mag_Tracer_Red":         "FA_200Rnd_127_Mk258",
    "200Rnd_127x99_mag_Tracer_Red":         "FA_200Rnd_127_Mk258",
    "12Rnd_120mm_APFSDS_shells_Tracer_Red": "FA_30Rnd_120mm_APFSDS",
    "8Rnd_120mm_HE_shells_Tracer_Red":      "FA_30Rnd_120mm_AMP",
    "8Rnd_120mm_HEAT_MP_T_Red":             "FA_30Rnd_120mm_HEATMP",
    "680Rnd_35mm_AA_shells_Tracer_Red":     "FA_680Rnd_35mm_AHEAD",
}


def fa_of(m, table):
    b = table.get(m)
    if not b:
        return None
    for c in ("%s_T_%s" % (b, COL), b):
        if c in FA:
            return c
    return None


roster = sorted(n for n in C if res(n, "faction") == "OPF_R_F" and res(n, "scope") == "2")

EF_GYRA = [
    "EF_O_Gyra_Antiair_OPF_T",
    "EF_O_Gyra_HMG_OPF_T",
    "EF_O_Gyra_Armed_OPF_T",
]
GYRA_TEX = [
    "ef\\ef_gyra_t\\data\\gyra_hull_1_olive_co.paa",
    "ef\\ef_gyra_t\\data\\gyra_details_1_olive_co.paa",
    "ef\\ef_gyra_t\\data\\gyra_int_1_olive_co.paa",
    "ef\\ef_gyra_t\\data\\gyra_hmg_1_olive_co.paa",
    "ef\\ef_gyra_t\\data\\gyra_rws_1_olive_co.paa",
    "ef\\ef_gyra_t\\data\\gyra_turret_1_olive_co.paa",
    "ef\\ef_gyra_t\\data\\gyra_mortar_1_olive_co.paa",
    "a3\\armor_f\\data\\camonet_nato_green_co.paa",
]

# extra drones, mirroring faction_o_raf. Owning mods stay out of requiredAddons.
DRONES = [
    "GX_O_DRONE40_UAV_HE", "GX_O_DRONE40_UAV_RECON",
    "GX_O_HONEYBADGER_UGV_AT_BLACK", "GX_O_HONEYBADGER_UGV_AT_DESERT",
    "GX_O_HONEYBADGER_UGV_AT_GREEN", "GX_O_HONEYBADGER_UGV_AT_HEX",
    "GX_O_HUNTER_SP_UAV", "GX_O_MAGURA_V5_USV", "GX_O_RQ11B_UAV",
    "GX_O_THEMIS_UGV_CARGO", "GX_O_THEMIS_UGV_DEFNDER_MEDIUM",
    "GX_O_THEMIS_UGV_HUNTER_LAUNCHER",
    "O_Crocus_AP", "O_Crocus_AP_TI", "O_Crocus_AT", "O_Crocus_AT_TI",
    "O_KVN_AP", "O_KVN_AP_TI", "O_KVN_AT", "O_KVN_AT_TI",
    "O_UAV_RC40_HE_RF", "O_UAV_RC40_SENSOR_RF", "rksla3_uav_h450_2",
]
extra = [d for d in DRONES + EF_GYRA if d not in roster]
clone = {n: "jmfsb_%s_%s" % (COMP, n) for n in roster + extra}

d = os.path.join(BASE, COMP)
os.makedirs(d, exist_ok=True)
W = lambda n, c: io.open(os.path.join(d, n), "w", encoding="utf-8", newline="\n").write(c)
io.open(os.path.join(d, "$PBOPREFIX$"), "w", newline="\n").write("z\\jmfsb\\addons\\%s\n" % COMP)
W("script_component.hpp",
  '#define COMPONENT %s\n#define COMPONENT_BEAUTIFIED %s\n'
  '#include "\\z\\jmfsb\\addons\\main\\script_mod.hpp"\n'
  '#include "\\z\\jmfsb\\addons\\main\\script_macros.hpp"\n' % (COMP, DISP))
W("CfgFactionClasses.hpp",
  'class CfgFactionClasses {\n    class %s {\n'
  '        displayName = "[JMSB] %s";\n        priority = 3;\n        side = 0;\n'
  '        icon = "\\A3\\ui_f\\data\\map\\markers\\nato\\o_inf.paa";\n'
  '        flag = "\\A3\\Data_F\\Flags\\Flag_CSAT_CO.paa";\n    };\n};\n' % (FCLS, DISP))

struct, fwd, bodies, nmag, ntur = {}, [], [], 0, 0
for n in roster + extra:
    t = {}
    for p, tm in res_turrets(n).items():
        conv = [fa_of(x, TMAP) or x for x in tm]
        if conv != tm:
            t[p] = conv
    if t:
        struct[n] = t
for n in roster + extra:
    if n not in struct:
        fwd.append("    class %s;" % n)
for n in sorted(struct):
    par = real(C[real(n)].get("parent") or "")
    if par and par not in struct:
        fwd.append("    class %s;" % par)
    fwd.append("    class %s: %s {" % (n, par) if par else "    class %s {" % n)
    fwd.append("        class Turrets {")
    for p in sorted(struct[n]):
        fwd.append("            class %s;" % p.split("/")[-1])
    fwd.append("        };")
    fwd.append("    };")

for n in roster + extra:
    b = ["    class %s: %s {" % (clone[n], n), "        scope = 2;",
         "        scopeCurator = 2;", "        side = 0;",
         '        faction = "%s";' % FCLS]
    mags = res(n, "magazines") or []
    new, ch = [], False
    for m in mags:
        f = fa_of(m, MAP)
        new.append(f or m); ch = ch or bool(f)
    if ch:
        nmag += 1
        for arr in ("magazines", "respawnMagazines"):
            b.append("        %s[] = {" % arr)
            for i, m in enumerate(new):
                b.append('            "%s"%s' % (m, "," if i < len(new) - 1 else ""))
            b.append("        };")
    if n in EF_GYRA:
        b.append("        hiddenSelectionsTextures[] = {")
        for i, t in enumerate(GYRA_TEX):
            b.append('            "%s"%s' % (t, "," if i < len(GYRA_TEX) - 1 else ""))
        b.append("        };")
    crew = res(n, "crew")
    if crew and real(crew) in clone:
        b.append('        crew = "%s";' % clone[real(crew)])
    if n in struct:
        ntur += 1
        b.append("        class Turrets: Turrets {")
        for p in sorted(struct[n]):
            leaf = p.split("/")[-1]
            b.append("            class %s: %s {" % (leaf, leaf))
            b.append("                magazines[] = {")
            ms = struct[n][p]
            for i, m in enumerate(ms):
                b.append('                    "%s"%s' % (m, "," if i < len(ms) - 1 else ""))
            b.append("                };")
            b.append("            };")
        b.append("        };")
    b.append("    };")
    bodies += b
W("CfgVehicles.hpp", "\n".join(["class CfgVehicles {"] + fwd + [""] + bodies + ["};"]) + "\n")

# ---- CfgGroups: the faction's real tree, with a drone operator in every
# infantry group (faction_o_raf does the same)
UAVOP = "O_R_soldier_UAV_F"
cats = {}
for GS in (A3G, MDG):
    if "OPF_R_F" not in GS:
        continue
    for cn, cv in GS["OPF_R_F"]["cats"].items():
        cat = cats.setdefault(cn, {"name": cv["name"], "groups": {}})
        for gn, g in cv["groups"].items():
            us = [(real(u["vehicle"]), u["rank"], u["position"])
                  for u in g["units"] if real(u["vehicle"]) in clone]
            if us:
                cat["groups"][gn] = {"name": g["name"], "icon": g["icon"], "units": us}

added = 0
if UAVOP in clone:
    for cn, cat in cats.items():
        if cn.lower() not in ("infantry", "support", "specops"):
            continue
        for gn, g in cat["groups"].items():
            if len(g["units"]) < 3 or any(u[0] == UAVOP for u in g["units"]):
                continue
            g["units"].append((UAVOP, "PRIVATE", "{%d,%d,0}" % (5, -5 * len(g["units"]))))
            added += 1

gl = ["class CfgGroups {", "    class East {", "        class %s {" % FCLS,
      '            name = "[JMSB] %s";' % DISP]
ng = 0
for cn in sorted(cats):
    cat = cats[cn]
    if not cat["groups"]:
        continue
    gl.append("            class %s {" % cn)
    gl.append('                name = "%s";' % cat["name"])
    for gn in sorted(cat["groups"]):
        g = cat["groups"][gn]; ng += 1
        gl.append("                class GVAR(%s) {" % gn)
        gl.append('                    name = "%s";' % g["name"])
        gl.append("                    side = 0;")
        gl.append('                    faction = "%s";' % FCLS)
        if g["icon"]:
            gl.append('                    icon = "%s";' % g["icon"])
        for k, (cls, rank, pos) in enumerate(g["units"]):
            xyz = [p for p in pos.replace(" ", "").strip("{}").split(",") if p] or ["0", "0", "0"]
            while len(xyz) < 3:
                xyz.append("0")
            gl.append("                    class Unit%d {" % k)
            gl.append("                        side = 0;")
            gl.append('                        vehicle = "%s";' % clone[cls])
            gl.append('                        rank = "%s";' % rank)
            gl.append("                        position[] = {%s, %s, %s};" % tuple(xyz[:3]))
            gl.append("                    };")
        gl.append("                };")
    gl.append("            };")
gl += ["        };", "    };", "};"]
W("CfgGroups.hpp", "\n".join(gl) + "\n")

# requiredAddons: mod roots only, never a blocked/absent addon
srcs = set()
for n in roster:
    for k in chain(n):
        s = C[k].get("src")
        if s:
            srcs.add(s)
patches = set()
for s in srcs:
    if "/" not in s:
        continue
    top = "/".join(s.split("/")[:2])
    if not top.startswith(("A3_Aegis/", "A3_Atlas/")):
        continue
    for tbl in (A3P, MDP):
        if top in tbl:
            patches.update(tbl[top])
patches -= BLOCK
reqs = ['"jmfsb_main"', '"A3_Characters_F_OPFOR"', '"jmfsbfa_ammo"', '"jmfsbfa_vehicles"',
        '"jmfsbfa_maincaliber"', '"jmfsbfa_mediumcaliber"', '"jmfsbfa_grenade_40mm"',
        '"jmfsbfa_missiles"'] + ['"%s"' % p for p in sorted(patches)]
units = ",\n            ".join("QGVAR(%s)" % n for n in roster + extra)
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

print("units: %d (roster %d + drones %d)" % (len(roster) + len(extra), len(roster), len(extra)))
print("FA mag swaps: %d  turret swaps: %d" % (nmag, ntur))
print("groups: %d  drone operator added to: %d" % (ng, added))
print("deps: %d" % len(reqs))
