"""Index an unpacked mod's CfgVehicles the way the game resolves them: every config.cpp preprocessed
and parsed (tools/aegis_port/source_config), merged in load order, and each class's values resolved
through its parents - the mod's own first, then the base game's (tools/aegis_port's vanilla cache).

    python tools/mod_index.py <unpacked mod folder> <out.json>

The folder holds one directory per PBO named by its prefix (D:\\work\\2035russia\\min_rf_units) or a
single prefix directory holding them (D:\\work\\tmt\\TMT\\TMT_Core). Used to build jmfsb factions on
mods that are loaded beside jmfsb; nothing of the mod is copied.
"""
import json
import os
import pickle
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, "aegis_port"))
sys.setrecursionlimit(20000)
import vanilla_config  # noqa: F401,E402 - the cache's node class lives there
import source_config as S  # noqa: E402

KEYS = ("scope", "scopecurator", "side", "faction", "displayname", "editorsubcategory", "vehicleclass",
        "uniformclass", "model", "simulation", "crew", "weapons", "magazines", "linkeditems", "backpack",
        "hiddenselectionstextures", "transportsoldier", "icon", "textureList", "role", "cost", "gunnertype",
        "modelsides")
MAN_ROOTS = {"caman", "man"}


def val(v):
    if isinstance(v, list):
        return [val(x) for x in v]
    if isinstance(v, tuple):
        return v[1]
    return v


def main(src, out):
    src = os.path.abspath(src)
    tops = [d for d in os.listdir(src) if os.path.isdir(os.path.join(src, d))]
    S.SRC, S.MODS = src, tuple(tops)
    with open(os.path.join(HERE, "aegis_port", "vanilla_config.cache"), "rb") as fh:
        cache = pickle.load(fh)
    V = cache["tree"]
    data = S.load(cache["includes"], cache["patches"].keys())
    R = data["tree"]
    mv = R.get("CfgVehicles")
    vv = V.c.get("cfgvehicles")

    def node(name):
        lo = name.lower()
        n = mv.kids.get(lo) if mv is not None else None
        if n is not None and not n.decl:
            return ("m", n)
        v = vv.c.get(lo) if vv is not None else None
        return ("v", v) if v is not None else (None, None)

    def chain(name):
        out, seen = [], set()
        while name and name.lower() not in seen:
            seen.add(name.lower())
            kind, n = node(name)
            if n is None:
                out.append((name, None, None))
                break
            out.append((name, kind, n))
            name = n.parent if kind == "m" else n.p
        return out

    def resolve(name):
        res, anc = {}, []
        for nm, kind, n in chain(name):
            anc.append(nm)
            if n is None:
                continue
            for k in KEYS:
                k = k.lower()
                if k in res:
                    continue
                if kind == "m" and k in n.props:
                    res[k] = val(n.props[k][2])
                elif kind == "v" and k in getattr(n, "v", {}):
                    res[k] = n.v[k]
        return res, anc

    units = []
    for lo, n in (mv.kids.items() if mv is not None else ()):
        if n.decl:
            continue
        r, anc = resolve(n.name)
        low = [a.lower() for a in anc]
        r["class"], r["ancestry"] = n.name, anc
        r["pbo"] = n.pbos[-1] if n.pbos else ""
        r["is_man"] = bool(MAN_ROOTS & set(low))
        r["unresolved_parent"] = anc[-1] if node(anc[-1])[1] is None else None
        units.append(r)
    # weapons and magazines: what a man carries and which magazines fit it
    def resolve_in(table_m, table_v, name, keys):
        res, seen = {}, set()
        while name and name.lower() not in seen:
            seen.add(name.lower())
            n = table_m.kids.get(name.lower()) if table_m is not None else None
            if n is not None and not n.decl:
                for k in keys:
                    if k not in res and k in n.props:
                        res[k] = val(n.props[k][2])
                name = n.parent
                continue
            v = table_v.c.get(name.lower()) if table_v is not None else None
            if v is None:
                break
            for k in keys:
                if k not in res and k in getattr(v, "v", {}):
                    res[k] = v.v[k]
            name = v.p
        return res
    weapons, mags = {}, {}
    mw, vw = R.get("CfgWeapons"), V.c.get("cfgweapons")
    for lo, n in (mw.kids.items() if mw is not None else ()):
        if n.decl:
            continue
        r = resolve_in(mw, vw, n.name, ("scope", "type", "displayname", "magazines", "magazinewell", "baseweapon"))
        muz = []
        slot = None
        for nm in (n.name,):
            cur = n
            while cur is not None and slot is None:
                wsi = cur.kids.get("weaponslotsinfo")
                if wsi is not None and not wsi.decl and "muzzleslot" in wsi.kids:
                    slot = wsi.kids["muzzleslot"]
                cur = mw.kids.get(cur.parent.lower()) if cur.parent else None
        if slot is not None:
            ci = slot.kids.get("compatibleitems")
            if ci is not None:
                muz = [k for k, p in ci.props.items() if val(p[2]) in (1, "1")]
            elif "compatibleitems" in slot.props:
                muz = val(slot.props["compatibleitems"][2])
            r["muzzle_parent"] = slot.parent
        r["muzzles"] = muz
        r["parent"] = n.parent
        r["own"] = sorted(n.props)
        # does the weapon (or a parent the mod writes) carry LinkedItems - a preset then inherits them
        linked, cur, hops = False, n, 0
        while cur is not None and hops < 30 and not linked:
            li = cur.kids.get("linkeditems")
            linked = li is not None and not li.decl
            cur = mw.kids.get(cur.parent.lower()) if cur.parent else None
            hops += 1
        r["linked"] = linked                 # what the class writes itself, not inherits
        # a uniform's wearer (ItemInfo >> uniformClass): whose modelSides decide which sides may wear it
        wearer, cur, hops = None, n, 0
        while cur is not None and hops < 30 and wearer is None:
            ii = cur.kids.get("iteminfo")
            if ii is not None and not ii.decl and "uniformclass" in ii.props:
                wearer = val(ii.props["uniformclass"][2])
            nxt = cur.parent
            cur = mw.kids.get(nxt.lower()) if nxt else None
            if cur is None and nxt and wearer is None:
                v = vw.c.get(nxt.lower()) if vw is not None else None
                while v is not None and wearer is None:
                    vi = getattr(v, "c", {}).get("iteminfo")
                    wearer = getattr(vi, "v", {}).get("uniformclass") if vi is not None else None
                    v = vw.c.get(v.p.lower()) if v.p else None
            hops += 1
        if wearer:
            r["uniformclass"] = wearer
        weapons[n.name] = r
    mm, vm = R.get("CfgMagazines"), V.c.get("cfgmagazines")
    for lo, n in (mm.kids.items() if mm is not None else ()):
        if not n.decl:
            r = resolve_in(mm, vm, n.name, ("scope", "ammo", "count", "displayname"))
            r["parent"] = n.parent
            mags[n.name] = r
    wells = {}
    mwl = R.get("CfgMagazineWells")
    for n in (mwl.kids.values() if mwl is not None else ()):
        if not n.decl:
            wells[n.name] = {k: val(p[2]) for k, p in n.props.items()}
    fac = {}
    for sect in ("CfgFactionClasses", "CfgEditorSubcategories"):
        t = R.get(sect)
        fac[sect] = {n.name: {k: val(v[2]) for k, v in n.props.items()} for n in (t.kids.values() if t else ()) if not n.decl}
    patches = {a["pbo"]: a["patches"] for a in data["addons"]}
    json.dump({"units": units, "weapons": weapons, "magazines": mags, "wells": wells, "classes": fac, "patches": patches, "cdlc": data["cdlc"],
               "errors": data["errors"], "unknown_requires": dict(data["unknown_requires"])},
              open(out, "w", encoding="utf-8"), indent=1)
    print("%d CfgVehicles, %d factions, %d addons, %d skipped as needing a DLC" % (
        len(units), len(fac["CfgFactionClasses"]), len(data["addons"]), len(data["cdlc"])))


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
