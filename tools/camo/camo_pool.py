"""Which camos are available for each vehicle in the game.

VEHICLES: every placeable (scope 2) vehicle in the base game, its expansions (Bohemia's DLC that ship
as .pbo) and jmfsb's vehicle addon, one row per model - a camo is a set of textures for one model.
POOL: every paint the base game, the expansions and A3_Aegis_Public_Releases (Aegis, Atlas, OpF) define
for that model - TextureSources entries and the hiddenSelectionsTextures of placeable classes. The same
textures offered twice are listed once, from the first in that order. A paint that needs a texture from
outside the pool (a creator DLC's) is left out and counted. (user, 2026-09-14)
"""
import collections, json, os, pickle, re, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
# Everything this script caches or renders - the class table, the camo pool, the wheel masks, scratch PNGs.
# Outside the repo on purpose: it runs to hundreds of MB and none of it belongs in git. Override with
# JMFSB_CAMO_CACHE. It used to be a Claude session scratchpad under %TEMP%, which would have taken the
# generator with it when that was cleaned.
SP = os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache")
os.makedirs(SP, exist_ok=True)
AP = r"D:\Git\jmfs-custom-mod\tools\aegis_port"
sys.path.insert(0, AP)
sys.setrecursionlimit(20000)
import vanilla_config as VC   # noqa: E402
import vehicle_bases as VB    # noqa: E402
import game_vehicles as GV    # noqa: E402
import port as P              # noqa: E402
import emit as E              # noqa: E402

FOLDERS = [("Dta", "Base game"), ("Addons", "Base game"), ("Curator", "Base game"), ("Kart", "Karts"),
           ("Heli", "Helicopters"), ("Mark", "Marksmen"), ("Expansion", "Apex"), ("Jets", "Jets"),
           ("Argo", "Malden"), ("Orange", "Laws of War"), ("Tacops", "Tac-Ops"), ("Tank", "Tanks"),
           ("Enoch", "Contact (platform)"), ("Contact", "Contact"), ("AoW", "Art of War")]
EXPANSIONS = list(dict.fromkeys(label for _f, label in FOLDERS if label != "Base game"))
POOL_ORDER = ["Base game"] + EXPANSIONS + ["Aegis", "Atlas", "OpF"]
VEHICLE_ORDER = {o: i for i, o in enumerate(["Base game"] + EXPANSIONS + ["JMSB"])}
FAMS = ["Tracked", "Wheeled", "Helicopter", "Plane", "Boat", "Static weapon"]
MODS = {"a3_aegis": "Aegis", "a3_atlas": "Atlas", "a3_opf": "OpF"}
STR = {}


LOADING = [None]


class Stamped(VB.Node):
    """A class as first given a body, stamped with the folder it came from - a paint an expansion adds to a
    base-game class's TextureSources is the expansion's."""
    def __init__(self, *a, **k):
        super().__init__(*a, **k)
        self.origin = LOADING[0]


VB.Node = Stamped


class FirstWins(dict):
    """The folder that first defines a class is where it comes from; later configs only restate it."""
    def __setitem__(self, k, v):
        if k not in self:
            dict.__setitem__(self, k, v)


def model_key(path):
    if not isinstance(path, str) or not path.strip():
        return None
    q = path.strip().replace("/", "\\").lstrip("\\").lower()
    if not q.endswith(".p3d"):
        q += ".p3d"
    # jmfsb's copy of a source model and the source model are one model: the path under the addon's folder
    m = re.match(r"z\\jmfsb\\addons\\[^\\]+\\models\\[^\\]+\\(.+)$", q) or re.match(r"a3_(?:aegis|atlas|opf)\\[^\\]+\\(.+)$", q)
    return ("src:" + m.group(1)) if m else q


MISSING = collections.defaultdict(list)


def clean(t):
    return t.strip().replace("/", "\\").lstrip("\\")


def paint_name(t, mk):
    """A class's own paint, named by the words its texture file adds to the model's name:
    apc_tracked_02_ext_01_hexarid_co on apc_tracked_02_cannon_f -> Hexarid. Empty when it adds none."""
    base = re.sub(r"\.(paa|tga|png)$", "", clean(t).split("\\")[-1], flags=re.I).lower()
    model = set(re.split(r"[_\W]+", mk.split("\\")[-1].replace(".p3d", "")))
    words = [x for x in re.split(r"[_\W]+", base)
             if x and x not in model and x not in ("co", "ca", "f") and not VB.noncamo(x)]
    short = {"wdl": "Woodland", "ghex": "Green Hex", "hex": "Hex", "des": "Desert", "tna": "Tanoa", "blk": "Black",
             "un": "UN", "aaf": "AAF", "ldf": "LDF", "csat": "CSAT", "nato": "NATO", "fia": "FIA", "whex": "Woodland Hex",
             "ard": "Ardistan", "arc": "Arctic", "snow": "Snow", "grn": "Green", "olv": "Olive", "idap": "IDAP"}
    return " ".join(short.get(x, x.capitalize()) for x in words)


def tex_norm(t):
    return re.sub(r"\.(paa|tga|png)$", "", t.strip().replace("/", "\\").lstrip("\\").lower())


def display(v):
    t = (P.text(v) if isinstance(v, tuple) else (v or "")).strip()
    return STR.get(t[1:].lower(), t) if t.startswith("$") else t


# ---------------------------------------------------------------- the base game and its expansions
def load_game():
    table, where = {}, FirstWins()
    for folder, label in FOLDERS:
        base = os.path.join(VC.A3, folder)
        if not os.path.isdir(base):
            continue
        LOADING[0] = label
        for path in sorted(os.path.join(r, x) for r, _d, fs in os.walk(base) for x in fs if x.lower().endswith(".pbo")):
            try:
                _props, entries = VC.pbo_index(path)
            except Exception:
                continue
            for e in entries:
                if not e[0].lower().replace("/", "\\").endswith("config.bin"):
                    continue
                try:
                    data = VC.pbo_read(path, e)
                    if data[:4] == b"\0raP":
                        GV.Walk(data, label, table, where).walk(16, None, 0)
                except Exception as ex:
                    print("  !", os.path.basename(path), e[0], ex)
    return {k: VB.Rec(n, where.get(k, "Base game")) for k, n in table.items() if n.body}


def game_side(recs, vehicles, pool, fams):
    for k, r in recs.items():
        fam, uav, anc = VB.family(recs, r.name)
        if fam is None:
            continue
        mk = model_key(VB.value(recs, r.name, "model"))
        if not mk:
            continue
        public = VB.scope(recs, r.name) == 2
        schemes = {}
        for c in reversed([x for kind, x in anc if kind == "src"]):
            ts = c.node.kids.get("texturesources")
            for kk, e in (ts.kids.items() if ts else []):
                if e.body:
                    schemes[kk] = (getattr(e, "origin", None) or c.folder, e, c.name)
        if not public and not schemes:
            continue
        fams.setdefault(mk, (fam, uav))
        dn = VB.resolve_str(VB.value(recs, r.name, "displayname") or "") or r.name
        if public:
            vehicles[mk].append({"cls": r.name, "dn": dn, "from": r.folder})
            hst = VB.value(recs, r.name, "hiddenselectionstextures")
            if isinstance(hst, list):
                pool[mk].append({"origin": r.folder, "name": dn, "cls": r.name, "kind": "class",
                                 "tex": [x for x in hst if isinstance(x, str)], "factions": []})
        for kk, (origin, e, owner) in schemes.items():
            pool[mk].append({"origin": origin, "name": VB.resolve_str(e.props.get("displayname", e.name)) or e.name,
                             "cls": "%s / %s" % (owner, e.name), "kind": "scheme",
                             "tex": [x for x in (e.props.get("textures") or []) if isinstance(x, str)],
                             "factions": [x for x in (e.props.get("factions") or []) if isinstance(x, str)]})


# ---------------------------------------------------------------- A3_Aegis_Public_Releases
def aegis_side(w, pool):
    V = ("cfgvehicles",)
    cv = w.R.kids.get("cfgvehicles")

    def mod_of(node):
        for f in node.files:
            for part in re.split(r"[\\/]", f.lower()):
                if part in MODS:
                    return MODS[part]
        return None
    for _lo, node in cv.kids.items():
        if node.decl:
            continue
        try:
            if w.kind(V, node.name) != "vehicle":
                continue
            mk = model_key(P.text(w.value(V, node.name, "model")))
            chain = w.ancestry(V, node.name)[0]
        except Exception:
            continue
        if not mk:
            continue
        schemes = {}
        for n in reversed(chain):
            sn = w.snode(V, n)
            ts = sn.kids.get("texturesources") if sn is not None else None
            for kk, e in (ts.kids.items() if ts is not None else []):
                if not e.decl:
                    schemes[kk] = (mod_of(e) or mod_of(sn) or "Aegis", e, sn.name)
        own = node.props.get("hiddenselectionstextures")
        public = P.num(w.value(V, node.name, "scope")) == 2
        if public and own is not None and isinstance(own[2], list):
            pool[mk].append({"origin": mod_of(node) or "Aegis", "name": display(w.value(V, node.name, "displayname")) or node.name,
                             "cls": node.name, "kind": "class",
                             "tex": [P.text(x) for x in own[2] if isinstance(x, tuple)], "factions": []})
        for kk, (origin, e, owner) in schemes.items():
            dn = e.props.get("displayname")
            tex = e.props.get("textures")
            facs = e.props.get("factions")
            pool[mk].append({"origin": origin, "name": (display(dn[2]) if dn else "") or e.name,
                             "cls": "%s / %s" % (owner, e.name), "kind": "scheme",
                             "tex": [P.text(x) for x in (tex[2] if tex and isinstance(tex[2], list) else []) if isinstance(x, tuple)],
                             "factions": [P.text(x) for x in (facs[2] if facs and isinstance(facs[2], list) else []) if isinstance(x, tuple)]})


# ---------------------------------------------------------------- jmfsb
JMFSB_ADDONS = os.path.join(VB.JMFSB, "addons")




def jmfsb_table():
    """Every CfgVehicles class body in every jmfsb addon, jmfsb's macros spelled out per addon."""
    g, _also = VB.load_jmfsb()
    for addon in sorted(os.listdir(JMFSB_ADDONS)):
        if addon == "vehicle":
            continue
        base = os.path.join(JMFSB_ADDONS, addon)
        for r_, _d, fs in os.walk(base):
            for x in fs:
                if not x.lower().endswith((".hpp", ".cpp")):
                    continue
                t = VB.read_text(os.path.join(r_, x))
                if not re.search(r"\bclass\s+CfgVehicles\b", t):
                    continue
                t = re.sub(r"\bQEGVAR\((\w+),\s*(\w+)\)", r'"jmfsb_\1_\2"', t)
                t = re.sub(r"\bEGVAR\((\w+),\s*(\w+)\)", r"jmfsb_\1_\2", t)
                t = re.sub(r"\bQGVAR\((\w+)\)", r'"jmfsb_%s_\1"' % addon, t)
                t = re.sub(r"\bGVAR\((\w+)\)", r"jmfsb_%s_\1" % addon, t)
                t = re.sub(r"\b(?:Q?PATHTOE?F|CSTRING|LLSTRING|LSTRING|ECSTRING)\(([^()]*)\)", r'"\1"', t)
                try:
                    cv = VB.parse(t).kids.get("cfgvehicles")
                except Exception as ex:
                    print("  ! jmfsb", addon, x, ex)
                    continue
                for k, nd in (cv.kids.items() if cv else []):
                    if nd.body and k not in g:
                        g[k] = VB.Rec(nd, addon)
    return g


def jmfsb_side(vehicles, fams, recs):
    g = jmfsb_table()
    for k, r in g.items():
        if k in recs or VB.VV.c.get(k) is not None:
            continue                     # a base-game class jmfsb restates, not a jmfsb vehicle
        fam, uav, _anc = VB.family(g, r.name)
        if fam is None or VB.scope(g, r.name) != 2:
            continue
        mk = model_key(VB.value(g, r.name, "model"))
        if not mk:
            continue
        if not fams.get(mk):
            fams[mk] = (fam, uav)
        vehicles[mk].append({"cls": r.name, "dn": display(VB.value(g, r.name, "displayname")) or r.name,
                             "from": "JMSB"})


def main():
    STR.update({k.lower(): v for k, v in json.load(open(os.path.join(AP, "vanilla_strings.json"), encoding="utf-8")).items()})
    STR.update(E.load_strings())
    VB.strings.update(STR)
    cache = os.path.join(SP, "camo_pool.pickle")
    if "--reuse" in sys.argv and os.path.exists(cache):
        vehicles, pool, fams, found = pickle.load(open(cache, "rb"))
    else:
        recs = load_game()
        w = P.World()
        vehicles, pool, fams = collections.defaultdict(list), collections.defaultdict(list), {}
        game_side(recs, vehicles, pool, fams)
        aegis_side(w, pool)
        jmfsb_side(vehicles, fams, recs)
        found = {}
        for ps in pool.values():
            for p in ps:
                for t in p["tex"]:
                    q = clean(t)
                    if q and not q.startswith("#") and q not in found:
                        found[q] = ("game:" + q) if q.lower().startswith("a3\\") else w.resolve_src(q, (".paa",))
        vehicles, pool = dict(vehicles), dict(pool)
        pickle.dump((vehicles, pool, fams, found), open(cache, "wb"))

    def rep_of(tex):
        for t in tex:
            got = found.get(clean(t))
            if got:
                return got
        return None

    rows = []
    for mk, vs in vehicles.items():
        cands = sorted(pool.get(mk, []), key=lambda p: (POOL_ORDER.index(p["origin"]) if p["origin"] in POOL_ORDER else 99,
                                                        0 if p["kind"] == "scheme" else 1))
        seen, camos, missed, by_name = [], [], set(), {}
        for p in cands:
            tex = [t for t in p["tex"] if t.strip() and not t.strip().startswith("#")]
            norm = tuple(tex_norm(t) for t in tex)
            if not norm:
                continue
            gone = [clean(t) for t in tex if not found.get(clean(t))]
            if gone:
                if norm not in missed:
                    missed.add(norm)
                    MISSING[(p["origin"], "\\".join(gone[0].lower().split("\\")[:2]))].append((mk, p["cls"], gone[0]))
                continue
            if any(s[:len(norm)] == norm[:len(s)] for s in seen):
                continue
            seen.append(norm)
            name = (p["name"] if p["kind"] == "scheme" else paint_name(tex[0], mk)) or p["name"]
            key = (p["origin"], name.strip().lower())
            if key in by_name:                # one camo again, on another variant of the model (a medical hull, a turret)
                by_name[key]["variants"].append(p["cls"])
                continue
            by_name[key] = c = {"name": name, "origin": p["origin"], "cls": p["cls"], "kind": p["kind"],
                                "textures": len(norm), "factions": p["factions"], "rep": rep_of(tex),
                                "variants": [p["cls"]]}
            camos.append(c)
        vs = sorted(vs, key=lambda v: (VEHICLE_ORDER.get(v["from"], 99), v["dn"].lower(), v["cls"].lower()))
        fam, uav = fams.get(mk) or (None, False)
        rows.append({"model": mk, "family": fam, "uav": uav, "name": vs[0]["dn"],
                     "from": sorted({v["from"] for v in vs}, key=lambda o: VEHICLE_ORDER.get(o, 99)),
                     "vehicles": vs, "camos": camos, "outside": len(missed)})
    rows.sort(key=lambda r: (VEHICLE_ORDER.get(r["from"][0], 99), FAMS.index(r["family"]) if r["family"] in FAMS else 9,
                             r["name"].lower()))
    meta = {"expansions": EXPANSIONS, "poolOrder": POOL_ORDER}
    json.dump({"rows": rows, "meta": meta}, open(os.path.join(SP, "camo_pool.json"), "w", encoding="utf-8"),
              ensure_ascii=False, indent=1)
    by = collections.Counter(c["origin"] for r in rows for c in r["camos"])
    print("vehicles (models): %d | placeable classes: %d | camos: %d | from: %s" % (
        len(rows), sum(len(r["vehicles"]) for r in rows), sum(len(r["camos"]) for r in rows), dict(by)))
    print("rows by first source:", dict(collections.Counter(r["from"][0] for r in rows)))
    print("paints left out for textures outside the pool:", sum(r["outside"] for r in rows))
    for (o, pre), xs in sorted(MISSING.items(), key=lambda kv: -len(kv[1]))[:15]:
        print("   missing %4d %-12s %-28s e.g. %s | %s" % (len(xs), o, pre, xs[0][1], xs[0][2]))
    print("vehicles with a camo from Aegis/Atlas/OpF:", sum(1 for r in rows if any(c["origin"] in ("Aegis", "Atlas", "OpF") for c in r["camos"])))
    for r in rows[:6] + [x for x in rows if x["from"][0] == "JMSB"][:3]:
        print("  %-30s %-22s %-10s camos %3d  %s" % (r["name"][:30], ",".join(r["from"])[:22], r["family"],
              len(r["camos"]), [(c["name"], c["origin"]) for c in r["camos"]][:5]))


if __name__ == "__main__":
    main()
