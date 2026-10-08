"""Port the COMPLETE ACP US_OCP + Multicam_Snow gear sets into the jmfsb addons.

Uniforms -> addons/uniform, vests -> addons/vests, headgear -> addons/headware,
backpacks -> addons/backpack.  Textures are vendored into each addon's data/ and
referenced with QPATHTOF, so nothing depends on ACP at runtime.

Anything jmfsb already covers for that camo is skipped (matched on the class name
with the camo token stripped), so this only fills gaps.
"""
import os, io, re, shutil, collections

ACP = r"C:\Users\jwise\play\z\acp\addons"
GH = r"O:\GIT\jmfsb\addons"
PLAY = r"C:\Users\jwise\play"

CAMOS = {"ocp": ("US_OCP", "OCP"), "snow": ("Multicam_Snow", "Multicam Snow")}
PBOS = ("core", "extra_vests", "extra_headgear", "extra_backpacks", "ghillie", "facewear",
        "contact", "futuristic", "vehicle_crew", "modern_west", "coldwar_west")

TARGET = {"U_": ("uniform", "CfgWeapons"), "V_": ("vests", "CfgWeapons"),
          "H_": ("headware", "CfgWeapons"), "B_": ("backpack", "CfgVehicles"),
          "G_": ("headware", "CfgWeapons")}

CAMO_TOKENS = ("us_ocp", "multicam_snow", "ocp", "mcam_snow", "snow", "multicam", "us")

# These are US/NATO gear addons -- ACP retextures every body model into each camo
# (Livonian LDF, AAF, CSAT, Russian obr88/KZS/Gorka, Viper...). Only keep kit a
# US faction would plausibly wear.
DROP = ("_I_E_", "_I_G_", "obr88", "KZS", "Gorka", "Viper", "Aegis_O_", "BG_Guerilla",
        "BG_Guerrilla", "Guerilla", "Guerrilla", "_O_R_", "ocamo", "hex", "_AAF",
        "Story_Protagonist", "CBRN")


def us_only(core):
    if any(d.lower() in core.lower() for d in DROP):
        return False
    # side prefix: U_I_/U_O_/V_I_/H_O_ etc. are Indep/OPFOR models
    import re as _r
    if _r.match(r'^[UVHBG]_[IO]_', core):
        return False
    return True


def norm(n):
    """class name with camo tokens stripped, for gap detection"""
    s = n.lower()
    for t in sorted(CAMO_TOKENS, key=len, reverse=True):
        s = s.replace("_" + t, "")
    return s.strip("_")


def load(fam):
    out = {}
    for pbo in PBOS:
        p = os.path.join(ACP, "%s_%s" % (fam, pbo), "config.cpp")
        if not os.path.exists(p):
            continue
        s = io.open(p, encoding="utf-8", errors="replace").read()
        for m in re.finditer(r'^(\t*)class\s+(acp_[A-Za-z0-9_]+)\s*:\s*([A-Za-z0-9_]+)\s*\r?\n\1\{',
                             s, re.M):
            name, parent, start = m.group(2), m.group(3), m.end()
            depth, i = 1, start
            while i < len(s) and depth:
                if s[i] == '{':
                    depth += 1
                elif s[i] == '}':
                    depth -= 1
                i += 1
            out[name] = (parent, s[start:i - 1], pbo)
    return out


def prop(body, key):
    m = re.search(r'\b%s\s*=\s*"([^"]*)"' % key, body)
    return m.group(1) if m else None


def arrprop(body, key):
    m = re.search(r'\b%s\[\]\s*=\s*\{([^}]*)\}' % key, body, re.S)
    if not m:
        return []
    return [x.strip().strip('"') for x in m.group(1).split(",") if x.strip()]


def copy_asset(path, addon):
    rel = path.lstrip("\\").replace("\\", "/")
    src = os.path.join(PLAY, *rel.split("/"))
    if not os.path.exists(src):
        return None
    sub = "ui" if "/ui/" in rel.lower() else ""
    dd = os.path.join(GH, addon, "data", sub) if sub else os.path.join(GH, addon, "data")
    os.makedirs(dd, exist_ok=True)
    base = os.path.basename(src)
    shutil.copyfile(src, os.path.join(dd, base))
    return ("data\\%s\\%s" % (sub, base)) if sub else ("data\\%s" % base)


def jmfsb_existing():
    """{addon: {normalised class name}} already defined in jmfsb"""
    out = collections.defaultdict(set)
    for addon in ("uniform", "uniform_eu", "uniform_sof", "vests", "vests_aegis",
                  "vests_ws", "headware", "backpack", "nvg"):
        d = os.path.join(GH, addon)
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            if not f.endswith(".hpp"):
                continue
            s = io.open(os.path.join(d, f), encoding="utf-8", errors="replace").read()
            for m in re.finditer(r'class GVAR\(([A-Za-z0-9_]+)\)', s):
                out[addon].add(norm(m.group(1)))
    # gear addons share a namespace per slot
    slot = {"uniform": ["uniform", "uniform_eu", "uniform_sof"],
            "vests": ["vests", "vests_aegis", "vests_ws"],
            "headware": ["headware", "nvg"], "backpack": ["backpack"]}
    merged = {}
    for k, addons in slot.items():
        s = set()
        for a in addons:
            s |= out[a]
        merged[k] = s
    return merged


def main():
    HAVE = jmfsb_existing()
    emitted = collections.defaultdict(list)      # addon -> lines
    holders = []                                 # uniform holder classes
    externs = collections.defaultdict(set)       # addon -> parents
    stats = collections.Counter()

    for tok, (fam, disp) in CAMOS.items():
        tbl = load(fam)
        # short name (without acp_<fam>_<pbo>_ prefix) -> (full, parent, body)
        idx = {}
        for full, (parent, body, pbo) in tbl.items():
            pre = "acp_%s_%s_" % (fam, pbo)
            if full.startswith(pre):
                idx.setdefault(full[len(pre):], (full, parent, body))

        def resolve_parent(p):
            """walk acp_ parents until a non-ACP (vanilla/mod) class"""
            seen = set()
            while p.startswith("acp_") and p not in seen:
                seen.add(p)
                nxt = tbl.get(p)
                if not nxt:
                    break
                p = nxt[0]
            return p

        for core in sorted(idx):
            if core.endswith("_insignia") or core.endswith("_flag"):
                continue
            if not us_only(core):
                stats[(tok, TARGET.get(core[:2], ("?",))[0], "drop")] += 1
                continue
            pfx = core[:2]
            if pfx not in TARGET:
                continue
            addon, cfg = TARGET[pfx]
            gname = core                          # keep the ACP camo token
            if norm(gname) in HAVE[addon]:
                stats[(tok, addon, "skip")] += 1
                continue
            full, parent, body = idx[core]
            parent = resolve_parent(parent)
            texs = [t for t in (copy_asset(x, addon) for x in
                                arrprop(body, "hiddenSelectionsTextures")) if t]
            pic = prop(body, "picture")
            picr = copy_asset(pic, addon) if pic else None
            dn = prop(body, "displayName") or core
            dn = re.sub(r'^\[[^\]]*\]\s*', '', dn)
            externs[addon].add(parent)

            L = ["    class GVAR(%s): %s {" % (gname, parent),
                 "        author = QAUTHOR;",
                 '        displayName = "[JMSB] %s (%s)";' % (dn, disp)]
            if picr:
                L.append("        picture = %s;" % ("QPATHTOF(%s)" % picr))
            sel = arrprop(body, "hiddenSelections")
            if sel:
                L.append("        hiddenSelections[] = {%s};" %
                         ", ".join('"%s"' % s for s in sel))
            if texs:
                L.append("        hiddenSelectionsTextures[] = {%s};" %
                         ", ".join("QPATHTOF(%s)" % t for t in texs))
            if pfx == "U_":
                hold = "Soldier_%s" % gname
                L.append("        class ItemInfo: ItemInfo {")
                L.append("            uniformClass = QGVAR(%s);" % hold)
                L.append("        };")
                sold = idx.get("Soldier_" + core)
                hp = resolve_parent(sold[1]) if sold else "B_Soldier_F"
                htex = texs
                if sold:
                    ht = [t for t in (copy_asset(x, "uniform") for x in
                                      arrprop(sold[2], "hiddenSelectionsTextures")) if t]
                    htex = ht or texs
                holders.append((hold, hp, gname, htex))
            else:
                L.append("        MACRO_ITEM_COMMON")
            L.append("    };")
            emitted[addon] += L
            stats[(tok, addon, "new")] += 1

    # ---- write fragments ----
    for addon, lines in emitted.items():
        head = ["// Full ACP OCP + Multicam Snow gear set ported into jmfsb.",
                "// Included from the addon's own Cfg*.hpp -- no root class here.", ""]
        io.open(os.path.join(GH, addon, "acp_full.hpp"), "w",
                encoding="utf-8", newline="\n").write("\n".join(head + lines) + "\n")

    if holders:
        L = ["// Holder classes for the ported ACP uniforms", ""]
        for hold, hp, gname, texs in holders:
            L.append("    class GVAR(%s): %s {" % (hold, hp))
            L.append("        scope = 1;")
            L.append("        scopeCurator = 0;")
            L.append("        uniformClass = QGVAR(%s);" % gname)
            if texs:
                L.append("        hiddenSelectionsTextures[] = {%s};" %
                         ", ".join("QPATHTOF(%s)" % t for t in texs))
            L.append("    };")
            externs["uniform_v"].add(hp)
        io.open(os.path.join(GH, "uniform", "acp_full_holders.hpp"), "w",
                encoding="utf-8", newline="\n").write("\n".join(L) + "\n")

    # ---- externs, filtered against what each host file already declares ----
    def host_decls(addon, fname):
        p = os.path.join(GH, addon, fname)
        if not os.path.exists(p):
            return set()
        return set(re.findall(r'^\s*class\s+([A-Za-z0-9_]+)\s*;',
                              io.open(p, encoding="utf-8").read(), re.M))

    for addon in emitted:
        fname = "CfgVehicles.hpp" if addon == "backpack" else "CfgWeapons.hpp"
        have = host_decls(addon, fname)
        names = sorted(externs[addon] - have)
        io.open(os.path.join(GH, addon, "acp_full_externs.hpp"), "w",
                encoding="utf-8", newline="\n").write(
            "// parents used by the ported ACP gear\n" +
            "".join("    class %s;\n" % c for c in names))
    if holders:
        have = host_decls("uniform", "CfgVehicles.hpp")
        names = sorted(externs["uniform_v"] - have)
        io.open(os.path.join(GH, "uniform", "acp_full_holder_externs.hpp"), "w",
                encoding="utf-8", newline="\n").write(
            "// parents used by the ported ACP uniform holders\n" +
            "".join("    class %s;\n" % c for c in names))

    for (tok, addon, kind), n in sorted(stats.items()):
        print("%-5s %-9s %-5s %d" % (tok, addon, kind, n))


main()
