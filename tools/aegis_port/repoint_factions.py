"""Point jmfsb's own addons at the classes `port.py --seeds` imported (user, 2026-10-04: the Aegis
family leaves the load order, "fix what you can").

    python tools/aegis_port/repoint_factions.py [--dry]

Reads work/aegis_seed_map.json (source class -> the jmfsb addon and name it came in under, written
by seed_map.py) and rewrites, in every addon outside the five the port writes into:
    class X;          ->  class EGVAR(addon,name);
    class Y: X {      ->  class Y: EGVAR(addon,name) {
    "X"               ->  QEGVAR(addon,name)
and every `a3_aegis\\...` texture a faction names directly, to the copy under the vehicle or
uniform addon's models/, or to a copy in the faction's own data\\aegis (flags, faction icons, the
woodland Slammer sheets the import does not carry). Only names in seeds.txt are touched.
"""
import json
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
JMFSB = os.path.normpath(os.path.join(HERE, "..", ".."))
ADDONS = os.path.join(JMFSB, "addons")
REPO = r"D:/Git/A3_Aegis_Public_Releases"
TARGETS = {"weapons", "vests", "headware", "uniform", "vehicle"}
# compat addons that patch the mods' own classes when the mods are loaded - left alone
SKIP = {"fa_aegis", "fa_atlas", "vests_aegis"}
DRY = "--dry" in sys.argv


def load_map():
    m = json.load(open(os.path.join(JMFSB, "work", "aegis_seed_map.json"), encoding="utf-8"))
    seeds = {l.strip().lower() for l in open(os.path.join(HERE, "seeds.txt"), encoding="utf-8")
             if l.strip() and not l.startswith("#")}
    return {k.lower(): v for k, v in m.items() if k.lower() in seeds}


def model_index():
    idx = {}
    for a in ("vehicle", "uniform", "weapons", "vests", "headware"):
        base = os.path.join(ADDONS, a)
        for dp, _dn, fs in os.walk(os.path.join(base, "models")):
            for f in fs:
                rel = os.path.relpath(os.path.join(dp, f), base)
                idx.setdefault(f.lower(), (a, rel))
    return idx


def repo_file(path):
    rel = path.strip("\\").replace("\\", "/")
    top, rest = rel.split("/", 1)
    want = rest.lower()
    for mod in ("A3_Aegis", "A3_Atlas", "A3_OpF"):
        if mod.lower() != top.lower():
            continue
        for dp, _dn, fs in os.walk(os.path.join(REPO, mod)):
            for f in fs:
                full = os.path.join(dp, f)
                if os.path.relpath(full, os.path.join(REPO, mod)).replace("\\", "/").lower() == want:
                    return full
    return None


def main():
    m = load_map()
    names = sorted(m, key=len, reverse=True)
    alt = "|".join(re.escape(n) for n in names)
    decl = re.compile(r"(?i)\bclass\s+(%s)\s*;" % alt)
    parent = re.compile(r"(?i)(:\s*)(%s)(?=\s*\{)" % alt)
    quoted = re.compile(r'(?i)"(%s)"' % alt)
    tex = re.compile(r'(?i)"\\?(a3_(?:aegis|atlas|opf)\\[^"]+\.paa)"')
    models = model_index()
    local = {}          # lower path -> (faction addon holding the copy, file name)

    def eg(n, q):
        v = m[n.lower()]
        return ("QEGVAR(%s,%s)" if q else "EGVAR(%s,%s)") % (v["addon"], v["name"])

    changed = {}
    for addon in sorted(os.listdir(ADDONS)):
        if addon in TARGETS or addon in SKIP or not os.path.isdir(os.path.join(ADDONS, addon)):
            continue
        for dp, dn, fs in os.walk(os.path.join(ADDONS, addon)):
            dn[:] = [d for d in dn if d not in ("models", "data")]
            for f in fs:
                if not f.endswith((".hpp", ".cpp")) or f.startswith("imported_"):
                    continue
                path = os.path.join(dp, f)
                t0 = t = open(path, encoding="utf-8", newline="").read()
                t = decl.sub(lambda mo: "class %s;" % eg(mo.group(1), False), t)
                t = parent.sub(lambda mo: mo.group(1) + eg(mo.group(2), False), t)
                t = quoted.sub(lambda mo: eg(mo.group(1), True), t)

                def retex(mo, addon=addon):
                    p = mo.group(1).lower()
                    hit = models.get(p.split("\\")[-1])
                    if hit:
                        return "QPATHTOEF(%s,%s)" % hit
                    if p not in local:
                        src = repo_file(p)
                        if src is None:
                            print("  not in the sources:", p)
                            return mo.group(0)
                        dst = os.path.join(ADDONS, addon, "data", "aegis", os.path.basename(src))
                        if not DRY:
                            os.makedirs(os.path.dirname(dst), exist_ok=True)
                            shutil.copy2(src, dst)
                        local[p] = (addon, os.path.basename(src))
                    owner, fn = local[p]
                    if owner == addon:
                        return "QPATHTOF(data\\aegis\\%s)" % fn
                    return "QPATHTOEF(%s,data\\aegis\\%s)" % (owner, fn)
                t = tex.sub(retex, t)
                if t != t0:
                    changed[os.path.relpath(path, JMFSB)] = sum(1 for a, b in zip(t0.splitlines(), t.splitlines()) if a != b)
                    if not DRY:
                        open(path, "w", encoding="utf-8", newline="").write(t)
    retarget_fa_aegis(changed)
    for k, v in sorted(changed.items()):
        print("%-60s %5d lines" % (k, v))
    print("files:", len(changed), "local texture copies:", len(local))


def retarget_fa_aegis(changed):
    """fa_aegis put FA rounds into Aegis's magazines and wells and was skipped without Aegis, taking
    fa_tiers_mods (which requires it) down too. It now builds on the imported copies: its magazine
    parents and the imported wells (Gepard, 12 ga) by their jmfsb names; its config.cpp requires
    jmfsb_weapons in place of the Aegis patches (by hand). The SR25, SLR, WF50 and SCAR entries stay,
    inert unless a mod defining those loads. Every imported class counts here, not only the seeds."""
    full = {k.lower(): v for k, v in json.load(open(os.path.join(JMFSB, "work", "aegis_seed_map.json"),
                                                     encoding="utf-8")).items()}
    wells = {v["name"].lower(): v["name"] for v in full.values() if v["ns"] == "cfgmagazinewells" and v["addon"] == "weapons"}

    def head(mo):
        n = mo.group(2)
        v = full.get(n.lower())
        if v is not None and v["ns"] in ("cfgmagazines", "cfgmagazinewells"):
            return "%sEGVAR(%s,%s)%s" % (mo.group(1), v["addon"], v["name"], mo.group(3))
        short = re.sub(r"(?i)^aegis_", "", n)
        if short != n and short.lower() in wells:            # Aegis_SMG_Gepard_9x21 -> jmfsb_weapons_SMG_Gepard_9x21
            return "%sEGVAR(weapons,%s)%s" % (mo.group(1), wells[short.lower()], mo.group(3))
        return mo.group(0)
    for f in ("CfgMagazines.hpp", "CfgMagazinewells.hpp"):
        path = os.path.join(ADDONS, "fa_aegis", f)
        t0 = t = open(path, encoding="utf-8", newline="").read()
        t = re.sub(r"(\bclass\s+)(\w+)(\s*[;{])", head, t)
        t = re.sub(r"(:\s*)(\w+)(\s*\{)", head, t)
        if t != t0:
            changed[os.path.relpath(path, JMFSB)] = sum(1 for a, b in zip(t0.splitlines(), t.splitlines()) if a != b)
            if not DRY:
                open(path, "w", encoding="utf-8", newline="").write(t)


if __name__ == "__main__":
    main()
