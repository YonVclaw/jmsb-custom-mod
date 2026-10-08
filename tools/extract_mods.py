"""Extract A3_Aegis + A3_Atlas configs into the same schema as a3_classes.json."""
import os, io, json, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import a3_extract as X

ROOTS = [r"c:\Users\jwise\play\A3_Aegis", r"c:\Users\jwise\play\A3_Atlas"]
OUT = os.path.dirname(os.path.abspath(__file__))

classes, groups = {}, {}
nfiles = 0
for R in ROOTS:
    for root, _d, fn in os.walk(R):
        if "config.cpp" not in fn:
            continue
        p = os.path.join(root, "config.cpp")
        rel = os.path.relpath(root, os.path.dirname(R)).replace("\\", "/")
        try:
            tree = X.parse(io.open(p, encoding="utf-8", errors="replace").read())
        except Exception as e:
            print("!! parse", rel, e); continue
        nfiles += 1

        cv = tree.get("CfgVehicles")
        if cv:
            for name, node in cv["children"].items():
                if name == "__props__":
                    continue
                props = node["children"].get("__props__", {})
                ent = classes.setdefault(name, {})
                if node.get("_parent"):
                    ent["parent"] = node["_parent"]
                ent["src"] = rel
                for k in ("faction", "side", "scope", "displayName", "vehicleClass",
                          "editorSubcategory", "crew", "uniformClass", "backpack"):
                    if k in props:
                        ent[k] = X.unq(props[k])
                for k in ("magazines", "respawnMagazines", "weapons", "respawnWeapons",
                          "linkedItems", "items"):
                    if k in props:
                        ent[k] = X.arr(props[k])
                tacc = {}
                X.walk_turrets(node["children"], [], tacc)
                if tacc:
                    ent["turrets"] = tacc

        cg = tree.get("CfgGroups")
        if cg:
            for sidename, sidenode in cg["children"].items():
                if sidename == "__props__":
                    continue
                for facname, facnode in sidenode["children"].items():
                    if facname == "__props__":
                        continue
                    fac = groups.setdefault(facname, {"side": sidename, "cats": {}})
                    for catname, catnode in facnode["children"].items():
                        if catname == "__props__":
                            continue
                        cp = catnode["children"].get("__props__", {})
                        cat = fac["cats"].setdefault(catname, {
                            "name": X.unq(cp.get("name", catname)), "groups": {}})
                        for gname, gnode in catnode["children"].items():
                            if gname == "__props__":
                                continue
                            gp = gnode["children"].get("__props__", {})
                            units = []
                            for uname, unode in sorted(gnode["children"].items()):
                                if uname == "__props__":
                                    continue
                                up = unode["children"].get("__props__", {})
                                if "vehicle" in up:
                                    units.append({
                                        "slot": uname,
                                        "vehicle": X.unq(up["vehicle"]),
                                        "rank": X.unq(up.get("rank", "PRIVATE")),
                                        "position": up.get("position", "{0,0,0}"),
                                    })
                            cat["groups"][gname] = {
                                "name": X.unq(gp.get("name", gname)),
                                "icon": X.unq(gp.get("icon", "")),
                                "faction": X.unq(gp.get("faction", facname)),
                                "units": units,
                            }

json.dump(classes, io.open(os.path.join(OUT, "mod_classes.json"), "w", encoding="utf-8"), indent=0)
json.dump(groups, io.open(os.path.join(OUT, "mod_groups.json"), "w", encoding="utf-8"), indent=0)
print("files:", nfiles, "classes:", len(classes), "group-factions:", len(groups))
for f in ("BLU_F", "BLU_T_F", "BLU_W_F", "BLU_NATO_lxWS"):
    if f in groups:
        print("  %-16s cats=%d groups=%d" % (f, len(groups[f]["cats"]),
              sum(len(c["groups"]) for c in groups[f]["cats"].values())))
    else:
        print("  %-16s no groups" % f)
