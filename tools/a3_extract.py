"""Tokenise + tree-parse the unpacked A3 configs and dump every CfgVehicles class
(parent / faction / magazines / weapons / turret mags) plus the CfgGroups trees.

Comment stripping happens INSIDE the tokenizer (string-aware) -- a regex pre-pass
eats the // in url="https://..." and desyncs everything.
"""
import os, json, io, sys

A3 = r"O:\OneDrive\Documents\Arma 3 Projects\a3"
OUT = os.path.dirname(os.path.abspath(__file__))


def strip_comments(s):
    out = []
    i, n = 0, len(s)
    while i < n:
        c = s[i]
        if c == '"':                       # string: "" is an escaped quote
            out.append(c); i += 1
            while i < n:
                if s[i] == '"':
                    if i + 1 < n and s[i + 1] == '"':
                        out.append('""'); i += 2; continue
                    out.append('"'); i += 1; break
                out.append(s[i]); i += 1
            continue
        if c == '/' and i + 1 < n and s[i + 1] == '/':
            while i < n and s[i] != '\n':
                i += 1
            continue
        if c == '/' and i + 1 < n and s[i + 1] == '*':
            i += 2
            while i + 1 < n and not (s[i] == '*' and s[i + 1] == '/'):
                i += 1
            i += 2
            continue
        out.append(c); i += 1
    return "".join(out)


def parse(text):
    """-> nested dict {name: {'_parent':p, '_props':{k:v}, 'children':{...}}}"""
    s = strip_comments(text)
    i, n = 0, len(s)
    root = {}
    stack = [root]

    def skip_ws():
        nonlocal i
        while i < n and s[i] in " \t\r\n":
            i += 1

    def read_value():
        """read up to the matching ; respecting strings and {}"""
        nonlocal i
        depth = 0
        buf = []
        while i < n:
            c = s[i]
            if c == '"':
                buf.append(c); i += 1
                while i < n:
                    if s[i] == '"':
                        if i + 1 < n and s[i + 1] == '"':
                            buf.append('""'); i += 2; continue
                        buf.append('"'); i += 1; break
                    buf.append(s[i]); i += 1
                continue
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
            elif c == ';' and depth <= 0:
                i += 1
                break
            buf.append(c); i += 1
        return "".join(buf).strip()

    while i < n:
        skip_ws()
        if i >= n:
            break
        if s[i] == '}':
            i += 1
            skip_ws()
            if i < n and s[i] == ';':
                i += 1
            if len(stack) > 1:
                stack.pop()
            continue
        # identifier
        j = i
        while j < n and (s[j].isalnum() or s[j] in "_"):
            j += 1
        word = s[i:j]
        if not word:
            i += 1
            continue
        i = j
        if word == "class":
            skip_ws()
            j = i
            while j < n and (s[j].isalnum() or s[j] in "_"):
                j += 1
            name = s[i:j]
            i = j
            skip_ws()
            parent = None
            if i < n and s[i] == ':':
                i += 1
                skip_ws()
                j = i
                while j < n and (s[j].isalnum() or s[j] in "_"):
                    j += 1
                parent = s[i:j]
                i = j
                skip_ws()
            if i < n and s[i] == '{':
                i += 1
                cur = stack[-1]
                node = cur.get(name)
                if node is None:
                    node = {"_parent": parent, "_props": {}, "children": {}}
                    cur[name] = node
                elif parent:
                    node["_parent"] = parent
                stack.append(node["children"])
            else:                                   # forward decl `class X;`
                if i < n and s[i] == ';':
                    i += 1
                cur = stack[-1]
                cur.setdefault(name, {"_parent": parent, "_props": {}, "children": {}})
            continue
        # property
        skip_ws()
        if i < n and s[i] == '[':
            while i < n and s[i] != '=':
                i += 1
        if i < n and s[i] == '=':
            i += 1
            skip_ws()
            val = read_value()
            # stack[-1] is a children dict; props live on the owning node, so use a
            # sentinel key that cannot collide with a class name
            stack[-1].setdefault("__props__", {})[word] = val
        else:
            while i < n and s[i] != ';':
                i += 1
            i += 1
    return root


def arr(val):
    v = val.strip()
    if v.startswith("{"):
        v = v[1:-1] if v.endswith("}") else v[1:]
    out = []
    for part in v.split(","):
        p = part.strip()
        if p.startswith('"') and p.endswith('"') and len(p) >= 2:
            p = p[1:-1]
        if p:
            out.append(p)
    return out


def unq(v):
    v = v.strip()
    if v.startswith('"') and v.endswith('"') and len(v) >= 2:
        return v[1:-1]
    return v


def walk_turrets(children, path, acc):
    tur = children.get("Turrets")
    if not tur:
        return
    for tname, tnode in tur["children"].items():
        if tname == "__props__":
            continue
        props = tnode["children"].get("__props__", {})
        mags = arr(props["magazines"]) if "magazines" in props else None
        wep = arr(props["weapons"]) if "weapons" in props else None
        p = path + [tname]
        if mags or wep:
            acc["/".join(p)] = {"magazines": mags, "weapons": wep}
        walk_turrets(tnode["children"], p, acc)


def main():
    # config.cpp lives at the pbo root AND in per-vehicle subfolders
    # (armor_f_gamma/mbt_01/config.cpp), so walk the whole tree.
    KEEP = ("characters", "soft", "armor", "air", "static", "boat", "data", "supplies",
            "weapons", "drones", "missions")
    paths = []
    for root, _dn, fn in os.walk(A3):
        if "config.cpp" not in fn:
            continue
        rel = os.path.relpath(root, A3).replace("\\", "/")
        top = rel.split("/")[0]
        if top.split("_")[0] not in KEEP:
            continue
        if top.split("_")[0] == "missions":      # only for CfgGroups completeness
            continue
        paths.append((rel, os.path.join(root, "config.cpp")))
    classes = {}
    groups = {}
    for d, p in sorted(paths):
        try:
            txt = io.open(p, encoding="utf-8", errors="replace").read()
        except Exception as e:
            print("!! read", d, e); continue
        try:
            tree = parse(txt)
        except Exception as e:
            print("!! parse", d, e); continue

        cv = tree.get("CfgVehicles")
        if cv:
            for name, node in cv["children"].items():
                if name == "__props__":
                    continue
                props = node["children"].get("__props__", {})
                ent = classes.setdefault(name, {})
                if node.get("_parent"):
                    ent["parent"] = node["_parent"]
                ent["src"] = d
                for k in ("faction", "side", "scope", "displayName", "vehicleClass",
                          "editorSubcategory", "crew", "uniformClass", "backpack"):
                    if k in props:
                        ent[k] = unq(props[k])
                for k in ("magazines", "respawnMagazines", "weapons", "respawnWeapons",
                          "linkedItems", "items"):
                    if k in props:
                        ent[k] = arr(props[k])
                tacc = {}
                walk_turrets(node["children"], [], tacc)
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
                        cat = fac["cats"].setdefault(catname, {
                            "name": unq(catnode["children"].get("__props__", {}).get("name", catname)),
                            "groups": {}})
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
                                        "vehicle": unq(up["vehicle"]),
                                        "rank": unq(up.get("rank", "PRIVATE")),
                                        "position": up.get("position", "{0,0,0}"),
                                    })
                            cat["groups"][gname] = {
                                "name": unq(gp.get("name", gname)),
                                "icon": unq(gp.get("icon", "")),
                                "faction": unq(gp.get("faction", facname)),
                                "units": units,
                            }
    json.dump(classes, io.open(os.path.join(OUT, "a3_classes.json"), "w", encoding="utf-8"), indent=0)
    json.dump(groups, io.open(os.path.join(OUT, "a3_groups.json"), "w", encoding="utf-8"), indent=0)
    print("classes:", len(classes), " group-factions:", len(groups))
    for f in ("BLU_F", "BLU_T_F", "BLU_W_F", "BLU_NATO_lxWS"):
        if f in groups:
            ng = sum(len(c["groups"]) for c in groups[f]["cats"].values())
            print("  groups %-16s cats=%d groups=%d" % (f, len(groups[f]["cats"]), ng))
        else:
            print("  groups %-16s MISSING" % f)


main()
