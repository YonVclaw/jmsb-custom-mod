"""Port ACP US_OCP + Multicam_Snow gear into the jmfsb gear addons.

Uniforms -> addons/uniform, backpacks -> addons/backpack.  Textures are copied
into each addon's own data/ and referenced with QPATHTOF, so nothing depends on
ACP at runtime (same approach as the existing Multicam_Snow backpacks).
"""
import os, io, re, shutil, sys

ACP = r"C:\Users\jwise\play\z\acp\addons"
GH = r"O:\GIT\jmfsb\addons"

CAMOS = {                      # jmfsb token -> (ACP family, display prefix)
    "ocp":  ("US_OCP", "OCP"),
    "snow": ("Multicam_Snow", "Multicam Snow"),
}

# ACP class (without the acp_<fam>_<pbo>_ prefix) -> (jmfsb suffix, display)
UNIFORMS = [
    ("U_B_CombatUniform_%s",         "U_B_CombatUniform_%s_F",        "Combat Fatigues"),
    ("U_B_CombatUniform_tshirt_%s",  "U_B_CombatUniform_tshirt_%s_F", "Combat Fatigues (T-Shirt)"),
    ("U_B_CombatUniform_vest_%s",    "U_B_CombatUniform_vest_%s_F",   "Combat Fatigues (Rolled-up)"),
    ("U_B_CTRG_Soldier_%s_F",        "U_B_CTRG_Soldier_%s_F",         "Recon Fatigues"),
    ("U_B_GhillieSuit_%s",           "U_B_GhillieSuit_%s_F",          "Ghillie Suit"),
]
BACKPACKS = [
    ("B_AssaultPack_%s",         "AssaultPack_%s",         "Assault Pack"),
    ("B_AssaultPackEnhanced_%s", "AssaultPackEnhanced_%s", "Assault Pack (Enhanced)"),
    ("B_Bergen_%s_F",            "Bergen_%s",              "Bergen"),
    ("B_Carryall_%s",            "Carryall_%s",            "Carryall"),
    ("B_FieldPack_%s",           "FieldPack_%s",           "Field Pack"),
    ("B_Kitbag_rgr_%s",          "Kitbag_%s",              "Kitbag"),
    ("B_TacticalPack_%s",        "TacticalPack_%s",        "Tactical Pack"),
]

PBOS = ("core", "extra_backpacks", "extra_vests", "extra_headgear", "contact", "ghillie")


def load(fam):
    """{classname: (parent, body)} across the family's pbos"""
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


def tex_of(body):
    m = re.search(r'hiddenSelectionsTextures\[\]\s*=\s*\{([^}]*)\}', body, re.S)
    if not m:
        return []
    return [x.strip().strip('"') for x in m.group(1).split(",") if x.strip()]


def pic_of(body):
    m = re.search(r'picture\s*=\s*"([^"]+)"', body)
    return m.group(1) if m else None


def copy_asset(path, dest_dir):
    """copy \\z\\acp\\addons\\X\\data\\y.paa into the jmfsb addon's data/"""
    rel = path.lstrip("\\").replace("\\", "/")
    src = os.path.join(r"C:\Users\jwise\play", *rel.split("/"))
    if not os.path.exists(src):
        return None
    sub = "ui" if "/UI/" in rel or "/ui/" in rel else ""
    dd = os.path.join(dest_dir, "data", sub) if sub else os.path.join(dest_dir, "data")
    os.makedirs(dd, exist_ok=True)
    base = os.path.basename(src)
    shutil.copyfile(src, os.path.join(dd, base))
    return ("data\\%s\\%s" % (sub, base)) if sub else ("data\\%s" % base)


def qp(rel):
    return "QPATHTOF(%s)" % rel


EXT_W, EXT_V = set(), set()


def main():
    report = []
    for tok, (fam, disp) in CAMOS.items():
        tbl = load(fam)
        idx = {}
        for full, (parent, body, pbo) in tbl.items():
            short = full.split("_%s_" % pbo, 1)[-1] if ("_%s_" % pbo) in full else full
            idx.setdefault(short, (full, parent, body))

        # ---------------- uniforms ----------------
        uw, uv, missing = [], [], []
        for acp_pat, gh_pat, label in UNIFORMS:
            acp_name = acp_pat % fam
            if acp_name not in idx:
                missing.append(acp_name)
                continue
            full, parent, body = idx[acp_name]
            texs = [copy_asset(t, os.path.join(GH, "uniform")) for t in tex_of(body)]
            texs = [t for t in texs if t]
            pic = pic_of(body)
            picr = copy_asset(pic, os.path.join(GH, "uniform")) if pic else None
            gcls = gh_pat % tok
            holder = "B_%s_soldier_F" % (gh_pat % tok).replace("U_B_", "").replace("_F", "")
            uw.append((gcls, parent, label, texs, picr, holder))
            # holder body class: mirror ACP's Soldier_* if present
            sold = idx.get("Soldier_" + acp_name)
            hparent = sold[1] if sold else ("B_CTRG_Soldier_F" if "CTRG" in acp_name else "B_Soldier_F")
            uv.append((holder, hparent, gcls, texs))
        report.append((tok, "uniform", len(uw), missing))

        # ---------------- backpacks ----------------
        bp = []
        if tok == "ocp":       # snow backpacks already exist in jmfsb
            for acp_pat, gh_pat, label in BACKPACKS:
                acp_name = acp_pat % fam
                if acp_name not in idx:
                    continue
                full, parent, body = idx[acp_name]
                texs = [copy_asset(t, os.path.join(GH, "backpack")) for t in tex_of(body)]
                texs = [t for t in texs if t]
                pic = pic_of(body)
                picr = copy_asset(pic, os.path.join(GH, "backpack")) if pic else None
                bp.append((gh_pat % tok, parent, label, texs, picr))
            report.append((tok, "backpack", len(bp), []))

        # ---------------- emit ----------------
        # Fragments are #included INSIDE the addon's existing CfgWeapons /
        # CfgVehicles blocks -- emitting our own root classes here would be a
        # duplicate definition of those classes.
        # externs are collected across all camos and written once -- declaring the
        # same vanilla parent in two fragments is a duplicate definition
        EXT_W.update(p for _g, p, _l, _t, _pi, _h in uw)
        out = ["// ACP %s uniforms -- included from CfgWeapons.hpp" % disp, ""]
        for gcls, parent, label, texs, picr, holder in uw:
            out.append("    class GVAR(%s): %s {" % (gcls, parent))
            out.append("        author = QAUTHOR;")
            out.append("        MACRO_ITEM_COMMON")
            out.append('        displayName = "[JMSB] %s (%s)";' % (label, disp))
            if picr:
                out.append("        picture = %s;" % qp(picr))
            if texs:
                out.append("        hiddenSelectionsTextures[] = {%s};" %
                           ", ".join(qp(t) for t in texs))
            out.append("        class ItemInfo: ItemInfo {")
            out.append("            uniformClass = QGVAR(%s);" % holder)
            out.append("        };")
            out.append("    };")
        io.open(os.path.join(GH, "uniform", "acp_%s_weapons.hpp" % tok), "w",
                encoding="utf-8", newline="\n").write("\n".join(out) + "\n")

        EXT_V.update(hparent for _h, hparent, _g, _t in uv)
        out = ["// ACP %s uniform holder classes -- included from CfgVehicles.hpp" % disp, ""]
        for holder, hparent, gcls, texs in uv:
            out.append("    class GVAR(%s): %s {" % (holder, hparent))
            out.append("        scope = 1;")
            out.append("        scopeCurator = 0;")
            out.append("        uniformClass = QGVAR(%s);" % gcls)
            if texs:
                out.append("        hiddenSelectionsTextures[] = {%s};" %
                           ", ".join(qp(t) for t in texs))
            out.append("    };")
        io.open(os.path.join(GH, "uniform", "acp_%s_vehicles.hpp" % tok), "w",
                encoding="utf-8", newline="\n").write("\n".join(out) + "\n")

        if tok == "ocp" and bp:
            o2 = ["// ACP US OCP backpacks -- included from CfgVehicles.hpp", ""]
            # skip parents the host CfgVehicles.hpp already forward-declares
            hp = os.path.join(GH, "backpack", "CfgVehicles.hpp")
            have = set(re.findall(r'^\s*class\s+([A-Za-z0-9_]+)\s*;',
                                  io.open(hp, encoding="utf-8").read(), re.M)) \
                if os.path.exists(hp) else set()
            for p in sorted({p for _g, p, _l, _t, _pi in bp} - have):
                o2.append("    class %s;" % p)
            o2.append("")
            for gcls, parent, label, texs, picr in bp:
                o2.append("    class GVAR(%s): %s {" % (gcls, parent))
                o2.append("        author = QAUTHOR;")
                o2.append('        displayName = "[JMSB] %s";' % label)
                o2.append('        hiddenSelections[] = {"Camo"};')
                if texs:
                    o2.append("        hiddenSelectionsTextures[] = {%s};" %
                              ", ".join(qp(t) for t in texs))
                if picr:
                    o2.append("        picture = %s;" % qp(picr))
                o2.append("        MACRO_ITEM_COMMON")
                o2.append("    };")
            io.open(os.path.join(GH, "backpack", "acp_ocp.hpp"), "w",
                    encoding="utf-8", newline="\n").write("\n".join(o2) + "\n")

    def write_externs(fname, header, names, host):
        """emit only parents the host file does not already declare -- a second
        `class X;` for the same name is a duplicate definition"""
        hp = os.path.join(GH, "uniform", host)
        have = set()
        if os.path.exists(hp):
            have = set(re.findall(r'^\s*class\s+([A-Za-z0-9_]+)\s*;',
                                  io.open(hp, encoding="utf-8").read(), re.M))
        body = header + "\n" + "".join("    class %s;\n" % c
                                       for c in sorted(names - have))
        io.open(os.path.join(GH, "uniform", fname), "w",
                encoding="utf-8", newline="\n").write(body)

    write_externs("acp_externs_weapons.hpp",
                  "// vanilla parents used by the ported ACP uniforms",
                  EXT_W, "CfgWeapons.hpp")
    write_externs("acp_externs_vehicles.hpp",
                  "// vanilla parents used by the ported ACP uniform holders",
                  EXT_V, "CfgVehicles.hpp")

    for tok, kind, n, miss in report:
        print("%-6s %-9s emitted=%-3d missing=%s" % (tok, kind, n, miss or "-"))


main()
