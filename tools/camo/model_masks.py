"""Where each painted vehicle's wheels - and its glass - lie on its camo textures, so a made camo leaves them in
their own paint (user, 2026-09-15: "don;t camo thew wheels", with a screenshot of the PGL-625E and a Typhoon in
Chinese woodland digital, rims and tyres patterned; 2026-09-18: "do not camo tired", "do not camo windshields").

Glass: the faces of a selection whose name says glass (glass1, sklo, okno, canopy...) and the faces of any section
whose texture does (*_glass_ca.paa). Surveyed 2026-09-18 over every China model: no camo sheet carries a glass
face in LOD 0 - the game keeps the windscreens on their own glass textures, which the config never renames - so
the glass masks are a safety net that comes out empty, and the survey is what says the windscreens are safe.

Read from LOD 0 of the vehicle's own model (plane_undersides.py's ODOL and MLOD readers): the faces of the named
selections whose names say wheel - wheel_1_1, wheel_1_1_damper, kolL1, podkolo... (an animation selection that
lists only vertices gives the faces all of whose vertices it holds). For each hidden selection (camo1...): a mask,
white where its wheel faces lie and none of its other faces share the spot, grown a pixel and feathered. Written
into planes/masks/index.json as "wheels", beside the planes' underside masks ("mask").

    python model_masks.py [--only model_base,model_base]
"""
import hashlib, json, os, pickle, re, sys
import numpy as np
from PIL import Image, ImageDraw, ImageFilter

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
# Everything this script caches or renders - the class table, the camo pool, the wheel masks, scratch PNGs.
# Outside the repo on purpose: it runs to hundreds of MB and none of it belongs in git. Override with
# JMFSB_CAMO_CACHE. It used to be a Claude session scratchpad under %TEMP%, which would have taken the
# generator with it when that was cleaned.
SP = os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache")
os.makedirs(SP, exist_ok=True)
sys.path.insert(0, r"D:\Git\jmfs-custom-mod\tools\aegis_port")
sys.setrecursionlimit(20000)
import plane_undersides as PU  # noqa: E402
import vanilla_config as VC    # noqa: E402

WHEEL = re.compile(r"(?i)wheel|kolo|^kol[lp]?\d|podkol|tire|tyre")
GLASS = re.compile(r"(?i)glass|sklo|okno|windshield|windscreen|window|canopy")
JMFSB = r"D:\Git\jmfs-custom-mod"
MAP = os.path.join(JMFSB, "work", "faction_camo.json")
MOD_ROOTS = {"qav_type08\\": r"D:\work\qav\type\QAV_Type08", "qav_challenger\\": r"D:\work\qav\QAV_Challenger"}
MOD_CONFIGS = [r"D:\work\qav\type\QAV_Type08\config.cpp", r"D:\work\qav\QAV_Challenger\config.cpp"]
OUT = os.path.join(SP, "planes", "masks")
INDEX = os.path.join(OUT, "index.json")
MODELS = os.path.join(SP, "models")
S = PU.MASK_SIZE
_p3d = None


def game_p3d(path):
    """The game's own model at that path, copied out of its PBO."""
    global _p3d
    if _p3d is None:
        cache = os.path.join(SP, "p3d_index.pickle")
        if os.path.exists(cache):
            _p3d = pickle.load(open(cache, "rb"))
        else:
            _p3d = {}
            for f in list(VC.FOLDERS) + ["Contact"]:
                for r, _d, fs in os.walk(os.path.join(VC.A3, f)):
                    for x in fs:
                        if not x.lower().endswith(".pbo"):
                            continue
                        pbo = os.path.join(r, x)
                        try:
                            props, entries = VC.pbo_index(pbo)
                        except Exception:
                            continue
                        pre = props.get("prefix", "").strip("\\").lower()
                        for e in entries:
                            lo = e[0].lower().replace("/", "\\")
                            if lo.endswith(".p3d"):
                                _p3d.setdefault((pre + "\\" + lo) if pre else lo, (pbo, e))
            pickle.dump(_p3d, open(cache, "wb"))
    lo = path.lower().replace("/", "\\").strip("\\")
    got = _p3d.get(lo)
    if not got:
        return None
    dst = os.path.join(MODELS, hashlib.sha1(lo.encode()).hexdigest()[:10] + "_" + os.path.basename(lo))
    if not os.path.exists(dst):
        os.makedirs(MODELS, exist_ok=True)
        open(dst, "wb").write(VC.pbo_read(*got))
    return dst


def model_file(model):
    q = model.strip().replace("/", "\\").lstrip("\\")
    if not q.lower().endswith(".p3d"):
        q += ".p3d"
    lo = q.lower()
    if lo.startswith("a3\\"):
        return game_p3d(q)
    if lo.startswith("z\\jmfsb\\"):
        p = os.path.join(JMFSB, q[len("z\\jmfsb\\"):])
        return p if os.path.exists(p) else None
    for pre, root in MOD_ROOTS.items():
        if lo.startswith(pre):
            p = os.path.join(root, q[len(pre):])
            return p if os.path.exists(p) else None
    return None


def faces_of(geo, name, F):
    idx = geo["selections"].get(name)
    if idx is not None and len(idx):
        return np.asarray(idx, dtype=np.int64)
    verts = geo.get("sel_verts", {}).get(name)
    if verts is None or not len(verts):
        return np.zeros(0, np.int64)
    inset = np.zeros(len(geo["verts"]) + 1, bool)
    inset[verts[(verts >= 0) & (verts < len(geo["verts"]))]] = True
    held = inset[np.where(F < 0, len(geo["verts"]), F)] | (F < 0)          # -1 pads a triangle
    return np.nonzero(held.all(1) & (F[:, 0] >= 0))[0]


def part_faces(geo, F, rx, by_texture=False):
    """The faces the named selections (and bones) hold, and - by_texture - those textured with a file so named."""
    names = {n for n in list(geo["selections"]) + list(geo.get("sel_verts", {})) if rx.search(n)}
    part = np.zeros(len(geo["faces"]), bool)
    for n in names:
        part[faces_of(geo, n, F)] = True
    # a binarized model's wheel selections are bones: a face all of whose vertices a wheel bone moves is wheel
    bones, vb = geo.get("bones") or [], geo.get("vertex_bones")
    if bones and vb is not None and len(vb) == len(geo["verts"]):
        part_bone = np.append(np.array([bool(rx.search(b)) for b in bones]), False)
        pv = part_bone[np.where((vb < 0) | (vb >= len(bones)), len(bones), vb)].any(1)
        pv = np.append(pv, True)                                           # -1 pads a triangle
        part |= pv[np.where(F < 0, len(pv) - 1, F)].all(1) & (F[:, 0] >= 0)
        names |= {b for b in bones if rx.search(b)}
    if by_texture and "face_tex" in geo:
        ti = {i for i, t in enumerate(geo["textures"]) if rx.search(t)}
        if ti:
            part |= np.isin(np.asarray(geo["face_tex"]), list(ti))
            names |= {geo["textures"][i] for i in ti}
    return part, names


def wheel_masks(geo, hs, rx=WHEEL, by_texture=False):
    F = np.full((len(geo["faces"]), 4), -1, dtype=np.int64)
    for fi, f in enumerate(geo["faces"]):
        F[fi, :len(f)] = f[:4]
    wheel, names = part_faces(geo, F, rx, by_texture)
    uv = geo["uv"]
    out = {}
    for i, name in enumerate(hs):
        idx = faces_of(geo, name.lower(), F)
        if not len(idx) or not wheel[idx].any():
            continue
        wi, bi = Image.new("L", (S, S), 0), Image.new("L", (S, S), 0)
        wd, bd = ImageDraw.Draw(wi), ImageDraw.Draw(bi)
        for fi in idx:
            f = geo["faces"][fi]
            if len(f) < 3:
                continue
            pts = [(float(uv[k][0] % 1.0001) * S, float(uv[k][1] % 1.0001) * S) for k in f]
            (wd if wheel[fi] else bd).polygon(pts, fill=255)
        m = (np.asarray(wi) > 0) & ~(np.asarray(bi) > 0)
        if m.sum() < 40:
            continue
        img = Image.fromarray((m * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(3)).filter(ImageFilter.GaussianBlur(1.2))
        out[i] = (img, int(wheel[idx].sum()), len(idx))
    return out, sorted(names)


def main():
    import camo_pool as CP
    VB = CP.VB
    only = set(sys.argv[sys.argv.index("--only") + 1].lower().split(",")) if "--only" in sys.argv else None
    table, g, _s = pickle.load(open(os.path.join(SP, "faction_table.pickle"), "rb"))
    for path in MOD_CONFIGS:
        cv = VB.parse(VB.read_text(path)).kids.get("cfgvehicles")
        for k, nd in (cv.kids.items() if cv else []):
            if nd.body and k not in table:
                table[k] = VB.Rec(nd, "mod")
    camo = json.load(open(MAP, encoding="utf-8"))["camo"]
    painted = {c.lower() for picks in camo.values() for c, p in picks.items() if p.get("made")}
    models = {}
    for k in sorted(g):
        if k not in painted:
            continue
        r = g[k]
        model = VB.value(table, r.name, "model")
        mk = CP.model_key(model)
        hs = VB.value(table, r.name, "hiddenselections")
        if mk and isinstance(model, str) and isinstance(hs, list) and mk not in models:
            models[mk] = (model, [x for x in hs if isinstance(x, str)])
    index = json.load(open(INDEX)) if os.path.exists(INDEX) else {}
    os.makedirs(OUT, exist_ok=True)
    done = unread = nowheels = 0
    for mk, (model, hs) in sorted(models.items()):
        base = mk.split("\\")[-1].replace(".p3d", "")
        if only and base not in only:
            continue
        path = model_file(model)
        if not path:
            print("  ! no model file: %s" % mk)
            unread += 1
            continue
        try:
            head = open(path, "rb").read(4)
            geo = PU.read_odol_lod0(path) if head == b"ODOL" else PU.read_mlod_lod0(path) if head == b"MLOD" else None
        except Exception as ex:
            print("  ! %s: %s" % (base, ex))
            unread += 1
            continue
        if geo is None:
            print("  ! %s: not a model (%r)" % (base, head))
            unread += 1
            continue
        wm, names = wheel_masks(geo, hs)
        gm, gnames = wheel_masks(geo, hs, GLASS, by_texture=True)
        entry = index.setdefault(mk, {})
        tag = hashlib.sha1(mk.encode()).hexdigest()[:8]
        for part, masks in (("wheels", wm), ("glass", gm)):
            for i in list(entry):                                          # an earlier run's mask this one no longer finds
                if i in entry and part in entry[i] and int(i) not in masks:
                    del entry[i][part]
            for i, (img, nw, nf) in masks.items():
                p = os.path.join(OUT, "%s_%s__%d__%s.png" % (base, tag, i, part))
                img.save(p)
                entry.setdefault(str(i), {"selection": hs[i]})[part] = p
        if wm:
            done += 1
        else:
            nowheels += 1
        print("%-34s %-4s wheel selections %3d  wheels on %s  glass names %d, glass on %s" % (
            base[:34], geo["version"], len(names), {hs[i]: "%d/%d faces" % (nw, nf) for i, (img, nw, nf) in wm.items()},
            len(gnames), {hs[i]: "%d/%d faces" % (nw, nf) for i, (img, nw, nf) in gm.items()} or "none"))
        json.dump(index, open(INDEX, "w"), indent=1)
    print("models with wheel masks %d, without wheels on a camo texture %d, unread %d" % (done, nowheels, unread))


if __name__ == "__main__":
    main()
