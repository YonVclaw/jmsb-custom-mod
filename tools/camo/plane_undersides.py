"""Which parts of each plane's camo textures lie on its underside, read from the models themselves.

THE ASK (user, 2026-09-14): "on the air craft look up air craft camos and make suire the underside is light sky
color", "by aircraft i mean planes".

The base game's models are binarized (ODOL v73). They are read here after the Go port of BIS.P3D.ODOL
(github.com/habitualdev/IntelPackage, armaformats/p3d/odol and core/compression/lzo.go, MIT) - only what LOD 0
needs: named selections, faces, UV set 0, vertex positions and normals; everything before it is skipped field by
field exactly as that port reads it. The Aegis models jmfsb ships are MLOD, read through `hemtt utils p3d json`.

For each hidden selection (camo1, camo2...) of each plane model: a mask the size of the texture, white where the
selection's faces point down (normal y below DOWN) and none of its faces pointing elsewhere share the spot - a
mirrored or shared UV island stays camo - feathered a few pixels. Arma's Y is up; a model whose top faces point
the other way is flipped first.

    python plane_undersides.py [--only name,name] [--overlay]
"""
import collections, json, os, pickle, re, struct, subprocess, sys
import numpy as np
from PIL import Image, ImageDraw, ImageFilter

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
# Everything this script caches or renders - the class table, the camo pool, the wheel masks, scratch PNGs.
# Outside the repo on purpose: it runs to hundreds of MB and none of it belongs in git. Override with
# JMFSB_CAMO_CACHE. It used to be a session scratchpad under %TEMP%, which would have taken the
# generator with it when that was cleaned.
SP = os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache")
os.makedirs(SP, exist_ok=True)
sys.setrecursionlimit(20000)
OUT = os.path.join(SP, "planes", "masks")
JMFSB = r"D:\Git\jmfs-custom-mod"
DOWN = -0.25
MASK_SIZE = 1024


# ---------------------------------------------------------------- LZO (BIS.Core.Compression.LZO.Decompress)
def zero_run(src, ip, base):
    extra = 0
    while True:
        b = src[ip]
        ip += 1
        if b:
            return extra + base + b, ip
        extra += 255


def lzo(src, ip, size):
    out = bytearray(size)
    op = t = m_pos = 0
    if src[ip] > 17:
        t = src[ip] - 17
        ip += 1
        if t < 4:
            state = "match_next"
        else:
            out[op:op + t] = src[ip:ip + t]
            op += t
            ip += t
            state = "first_literal_run"
    else:
        state = "b3"
    while True:
        if state == "b3":
            t = src[ip]
            ip += 1
            if t >= 16:
                state = "match"
                continue
            if t == 0:
                t, ip = zero_run(src, ip, 15)
            n = t + 3
            out[op:op + n] = src[ip:ip + n]
            op += n
            ip += n
            state = "first_literal_run"
        elif state == "first_literal_run":
            t = src[ip]
            ip += 1
            if t >= 16:
                state = "match"
                continue
            m_pos = op - (1 + 0x0800) - (t >> 2) - (src[ip] << 2)
            ip += 1
            for _ in range(3):
                out[op] = out[m_pos]
                op += 1
                m_pos += 1
            state = "match_done"
        elif state == "match":
            if t >= 64:
                m_pos = op - 1 - ((t >> 2) & 7) - (src[ip] << 3)
                ip += 1
                t = (t >> 5) - 1
                state = "copy_match"
            elif t >= 32:
                t &= 31
                if t == 0:
                    t, ip = zero_run(src, ip, 31)
                m_pos = op - 1 - ((src[ip] >> 2) + (src[ip + 1] << 6))
                ip += 2
                state = "copy_match"
            elif t >= 16:
                m_pos = op - ((t & 8) << 11)
                t &= 7
                if t == 0:
                    t, ip = zero_run(src, ip, 7)
                m_pos -= (src[ip] >> 2) + (src[ip + 1] << 6)
                ip += 2
                if m_pos == op:
                    if op != size:
                        raise ValueError("LZO underrun %d/%d" % (op, size))
                    return bytes(out), ip
                m_pos -= 0x4000
                state = "copy_match"
            else:
                m_pos = op - 1 - (t >> 2) - (src[ip] << 2)
                ip += 1
                out[op] = out[m_pos]
                out[op + 1] = out[m_pos + 1]
                op += 2
                state = "match_done"
        elif state == "copy_match":
            n = t + 2
            if m_pos + n <= op:
                out[op:op + n] = out[m_pos:m_pos + n]
                op += n
            else:
                for _ in range(n):
                    out[op] = out[m_pos]
                    op += 1
                    m_pos += 1
            state = "match_done"
        elif state == "match_done":
            t = src[ip - 2] & 3
            state = "b3" if t == 0 else "match_next"
        elif state == "match_next":
            out[op:op + t] = src[ip:ip + t]
            op += t
            ip += t
            t = src[ip]
            ip += 1
            state = "match"


# ---------------------------------------------------------------- ODOL (BIS.P3D.ODOL, v44+ with the compression flag)
class R:
    def __init__(self, b):
        self.b, self.p = b, 0

    def skip(self, n):
        self.p += n

    def u8(self):
        self.p += 1
        return self.b[self.p - 1]

    def i16(self):
        self.p += 2
        return struct.unpack_from("<h", self.b, self.p - 2)[0]

    def i32(self):
        self.p += 4
        return struct.unpack_from("<i", self.b, self.p - 4)[0]

    def u32(self):
        self.p += 4
        return struct.unpack_from("<I", self.b, self.p - 4)[0]

    def f32s(self, n):
        self.p += 4 * n
        return struct.unpack_from("<%df" % n, self.b, self.p - 4 * n)

    def asciiz(self):
        e = self.b.index(b"\0", self.p)
        s = self.b[self.p:e].decode("latin1")
        self.p = e + 1
        return s

    def compressed(self, size):
        """ReadCompressed with LZO and the compression flag (ODOL v64+); nothing at all for an empty block."""
        if size == 0:
            return b""
        if not self.u8():
            self.p += size
            return self.b[self.p - size:self.p]
        data, self.p = lzo(self.b, self.p, size)
        return data

    def compressed_array(self, elem):
        n = self.i32()
        return n, self.compressed(n * elem)

    def condensed_array(self, elem):
        n = self.i32()
        if self.u8():                           # every element the one default value
            self.p += elem
            return n, self.b[self.p - elem:self.p] * n
        return n, self.compressed(n * elem)


def skip_model_info(r, v, nlods):
    r.skip(4 + 4 + 4 + 4 + 4 + 4 + 12 + 4 + 4 + 4 + 24)
    if v >= 70:
        r.skip(4)
    if v >= 71:
        r.skip(4)
    if v >= 52:
        r.skip(24)
    r.skip(36 + 36 + 4)
    if v >= 73:
        r.skip(1)
    if v >= 42:
        r.skip(16)
    if v >= 43:
        r.skip(8)
    if v >= 33:
        r.skip(1)
    if v >= 37:
        r.skip(5)
    if v >= 48:
        r.skip(4)
    r.skip(1)                                   # animated
    bones = []
    if r.asciiz():                              # skeleton: its bones' names, which each vertex's bone refs point at
        if v >= 23:
            r.skip(1)
        for _ in range(r.i32()):
            bones.append(r.asciiz().lower())
            r.asciiz()
        if v > 40:
            r.asciiz()
    r.skip(1)                                   # map type
    r.compressed_array(4)                       # mass array
    r.skip(16)
    if v >= 72:
        r.skip(4)
    if v >= 53:
        r.skip(1)
    if v >= 54:
        r.skip(1)
    r.skip(12 + 4)
    if v >= 38:
        r.skip(1)
    r.asciiz()
    r.asciiz()
    r.skip(1)
    if v >= 31:
        r.skip(4)
    if v >= 57:
        r.skip(12 * nlods)
    return bones


def skip_animations(r, v):
    types = []
    for _ in range(r.i32()):
        at = r.u32()
        r.asciiz()
        r.asciiz()
        r.skip(16)
        if v >= 56:
            r.skip(8)
        r.skip(4)
        if at <= 7:
            r.skip(8)
        elif at == 8:
            r.skip(32)
        elif at == 9:
            r.skip(4)
            if v >= 55:
                r.skip(4)
        else:
            raise ValueError("unknown AnimType %d" % at)
        types.append(at)
    nb = r.i32()
    for _ in range(nb):
        for _ in range(r.i32()):
            r.skip(4 * r.i32())
    for _ in range(nb):
        for k in range(len(types)):
            if r.i32() != -1 and types[k] not in (8, 9):
                r.skip(24)


def skip_material(r):
    r.asciiz()
    mv = r.u32()
    r.skip(6 * 16 + 4 + 16)
    if mv == 3:
        r.skip(1)
    if mv >= 6:
        r.asciiz()
    if mv >= 4:
        r.skip(8)
    nst = r.u32() if mv > 6 else 0
    ntg = r.u32() if mv > 8 else nst

    def stage():
        if mv >= 5:
            r.skip(4)
        r.asciiz()
        if mv >= 8:
            r.skip(4)
        if mv >= 11:
            r.skip(1)
    if mv < 8:
        for _ in range(nst):
            r.skip(4 + 48)
            stage()
    else:
        for _ in range(nst):
            stage()
        for _ in range(ntg):
            r.skip(4 + 48)
    if mv >= 10:
        stage()


def read_odol_lod0(path):
    r = R(open(path, "rb").read())
    if r.b[:4] != b"ODOL":
        raise ValueError("not ODOL")
    r.p = 4
    v = r.i32()
    if v >= 75:
        r.skip(8)
    if v >= 59:
        r.skip(4)
    if v >= 58:
        r.asciiz()
    nl = r.i32()
    res = r.f32s(nl)
    bones = skip_model_info(r, v, nl)
    if v >= 30 and r.u8():
        skip_animations(r, v)
    starts = [r.u32() for _ in range(nl)]
    r.p = starts[0]                              # LOD 0: the most detailed visual LOD
    vi = 4 if v >= 69 else 2

    def index_array():
        n, data = r.compressed_array(vi)
        return np.frombuffer(data, dtype="<i4" if vi == 4 else "<u2").astype(np.int64) if n else np.zeros(0, np.int64)

    for _ in range(r.i32()):                     # proxies
        r.asciiz()
        r.skip(48 + 12 + (4 if v >= 40 else 0))
    nsub = r.i32()                               # this LOD's bone indices into the skeleton's
    sub2skel = struct.unpack_from("<%di" % nsub, r.b, r.p) if nsub else ()
    r.p += 4 * nsub
    for _ in range(r.i32()):
        r.skip(4 * r.i32())
    if v >= 50:
        r.skip(4)
    else:
        r.condensed_array(4)
    if v >= 51:
        r.skip(4)
    r.skip(8 + 36 + 4)
    textures = [r.asciiz() for _ in range(r.i32())]
    for _ in range(r.i32()):
        skip_material(r)
    index_array()
    index_array()
    faces = []
    nf = r.i32()
    r.skip(6)
    for _ in range(nf):
        n = r.u8()
        faces.append(struct.unpack_from("<%d%s" % (n, "i" if vi == 4 else "H"), r.b, r.p))
        r.p += n * vi
    sections = []
    for _ in range(r.i32()):
        lo, hi = r.i32(), r.i32()
        r.skip(8 + 4)
        tex = r.i16()
        r.skip(4)
        if r.i32() == -1:
            r.asciiz()
        if v >= 36:
            r.skip(4 * r.i32())
            if v >= 67 and r.i32() >= 1:
                r.skip(44)
        else:
            r.skip(4)
        sections.append((lo, hi, tex))
    selections = {}
    for _ in range(r.i32()):
        name = r.asciiz()
        sel_faces = index_array()
        r.skip(4)
        sectional = r.u8()
        n, data = r.compressed_array(4)
        sel_sections = np.frombuffer(data, dtype="<i4") if n else np.zeros(0, np.int32)
        sel_verts = index_array()
        r.compressed(r.i32())
        selections[name.lower()] = (sel_faces, sel_sections, sel_verts)
    for _ in range(r.i32()):
        r.asciiz()
        r.asciiz()
    for _ in range(r.i32()):
        r.skip(4)
        r.skip(12 * r.i32())
    r.skip(12 + 1 + 4)
    if v >= 50:
        r.condensed_array(4)
    uv = None
    for k in range(1 + 0):
        mn = r.f32s(4)
        nv = r.u32()
        if r.u8():
            raw = r.b[r.p:r.p + 4] * nv
            r.p += 4
        else:
            raw = r.compressed(nv * 4)
        q = np.frombuffer(raw, dtype="<i2").reshape(-1, 2).astype(np.float64)
        uv = np.stack([1.52587890625e-05 * (q[:, 0] + 32767) * (mn[2] - mn[0]) + mn[0],
                       1.52587890625e-05 * (q[:, 1] + 32767) * (mn[3] - mn[1]) + mn[1]], 1)
    nuv = r.u32()
    for _ in range(nuv - 1):
        r.skip(16)
        nv = r.u32()
        if r.u8():
            r.skip(4)
        else:
            r.compressed(nv * 4)
    n, data = r.compressed_array(12)
    verts = np.frombuffer(data, dtype="<f4").reshape(-1, 3).astype(np.float64)
    n, data = r.condensed_array(4)
    packed = np.frombuffer(data, dtype="<i4").astype(np.int64)
    # each vertex's bones (AnimationRTWeight: an int32 count, then four (bone, weight) byte pairs), as skeleton bone
    # indices - -1 where none. A binarized model's wheel_1_1_damper and the like list no faces and no vertices: the
    # skeleton says what they move
    r.compressed_array(8)                        # ST coords
    nb, bdata = r.compressed_array(12)
    vertex_bones = np.full((nb, 4), -1, dtype=np.int64)
    if nb and nsub:
        rec = np.frombuffer(bdata, dtype=np.uint8).reshape(nb, 12)
        cnt = np.frombuffer(bdata, dtype="<i4").reshape(nb, 3)[:, 0]
        local = rec[:, 4:12:2].astype(np.int64)
        lut = np.append(np.array(sub2skel, dtype=np.int64), -1)
        vertex_bones = lut[np.minimum(local, nsub)]
        vertex_bones[np.arange(4)[None, :] >= cnt[:, None]] = -1

    def comp(shift):
        c = (packed >> shift) & 0x3FF
        return np.where(c > 511, c - 1024, c) * (-1.0 / 511)
    normals = np.stack([comp(0), comp(10), comp(20)], 1)

    # a section's faces by their byte offsets in the face list (Section.GetFaces)
    size3, pad4 = (16, 4) if vi == 4 else (8, 2)
    offsets, pos = [], 0
    for f in faces:
        offsets.append(pos)
        pos += size3 + (pad4 if len(f) == 4 else 0)
    offsets = np.array(offsets)

    def section_faces(si):
        lo, hi, _t = sections[si]
        return np.nonzero((offsets >= lo) & (offsets < hi))[0]

    face_tex = np.full(len(faces), -1)
    for si, (lo, hi, t) in enumerate(sections):
        face_tex[section_faces(si)] = t
    sel, sel_verts = {}, {}
    for name, (fs, ss, vs) in selections.items():
        idx = fs if len(fs) else (np.concatenate([section_faces(int(s)) for s in ss]) if len(ss) else np.zeros(0, np.int64))
        sel[name] = idx
        sel_verts[name] = vs                     # an animation selection may list only its vertices
    return {"version": v, "res": res[0], "faces": faces, "uv": uv, "verts": verts, "normals": normals,
            "selections": sel, "sel_verts": sel_verts, "textures": textures, "face_tex": face_tex,
            "bones": bones, "vertex_bones": vertex_bones}


def read_mlod_lod0(path):
    js = os.path.join(SP, "planes", os.path.basename(path) + ".json")
    if not os.path.exists(js):
        subprocess.run(["hemtt", "utils", "p3d", "json", path, js], capture_output=True)
    d = json.load(open(js))
    lod = d["lods"][0]
    pts = np.array([p["coords"] for p in lod["points"]], dtype=np.float64)
    fn = np.array(lod["face_normals"], dtype=np.float64)
    faces, uvs, nrm, tex = [], [], [], []
    verts = []
    for f in lod["faces"]:
        idx = []
        for vx in f["vertices"]:
            idx.append(len(verts))
            verts.append(pts[vx["point_index"]])
            uvs.append(vx["uv"])
            nrm.append(fn[vx["normal_index"]])
        faces.append(tuple(idx))
        tex.append(f.get("texture", ""))
    npts, nfaces = len(pts), len(lod["faces"])
    sel = {}
    for name, data in lod["taggs"]:
        if name.startswith("#") or len(data) != npts + nfaces:
            continue
        sel[name.lower()] = np.nonzero(np.array(data[npts:], dtype=np.uint8))[0]
    textures = sorted(set(tex))
    return {"version": "MLOD", "res": lod["resolution"], "faces": faces, "uv": np.array(uvs), "verts": np.array(verts),
            "normals": np.array(nrm), "selections": sel, "textures": textures,
            "face_tex": np.array([textures.index(t) for t in tex])}


# ---------------------------------------------------------------- masks
def masks_for(geo, selections):
    faces, uv, verts, normals = geo["faces"], geo["uv"], geo["verts"], geo["normals"]
    # face normals: the mean of the vertex normals; which way is up is settled by the top of the model
    fn = np.array([normals[list(f)].mean(0) if len(f) else (0, 0, 0) for f in faces])
    fc = np.array([verts[list(f)].mean(0) if len(f) else (0, 0, 0) for f in faces])
    # outward normals lean away from the middle: faces above the model's centre point up on the whole (the top 5%
    # of a jet is mostly its fin's side faces, which says nothing)
    flipped = float(np.sum((fc[:, 1] - fc[:, 1].mean()) * fn[:, 1])) < 0
    if flipped:
        fn = -fn
    out = {}
    for name in selections:
        idx = geo["selections"].get(name.lower())
        if idx is None or not len(idx):
            out[name] = None
            continue
        down = Image.new("L", (MASK_SIZE, MASK_SIZE), 0)
        other = Image.new("L", (MASK_SIZE, MASK_SIZE), 0)
        dd, od = ImageDraw.Draw(down), ImageDraw.Draw(other)
        nd = 0
        for fi in idx:
            f = faces[fi]
            if len(f) < 3:
                continue
            pts = [(float(uv[k][0] % 1.0001) * MASK_SIZE, float(uv[k][1] % 1.0001) * MASK_SIZE) for k in f]
            if fn[fi][1] < DOWN:
                dd.polygon(pts, fill=255)
                nd += 1
            else:
                od.polygon(pts, fill=255)
        d = np.asarray(down) > 0
        o = np.asarray(other.filter(ImageFilter.MaxFilter(3))) > 0
        m = Image.fromarray(((d & ~o) * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(2))
        out[name] = (m, nd, len(idx), flipped)
    return out


def main():
    import camo_pool as CP
    import paint_ref as PR
    only = set(sys.argv[sys.argv.index("--only") + 1].lower().split(",")) if "--only" in sys.argv else None
    overlay = "--overlay" in sys.argv
    VB = CP.VB
    table, g, _s = pickle.load(open(os.path.join(SP, "faction_table.pickle"), "rb"))
    models = {}                                  # model key -> (model path, hidden selections, default textures)
    for k in sorted(g):
        r = g[k]
        if not r.folder.startswith("faction_"):
            continue
        fam, _u, _a = VB.family(table, r.name)
        if fam != "Plane":
            continue
        model = VB.value(table, r.name, "model")
        mk = CP.model_key(model)
        hs = VB.value(table, r.name, "hiddenselections")
        hst = VB.value(table, r.name, "hiddenselectionstextures")
        if mk and isinstance(hs, list) and mk not in models:
            models[mk] = (model, [x for x in hs if isinstance(x, str)], [x for x in (hst or []) if isinstance(x, str)])
    os.makedirs(OUT, exist_ok=True)
    index = {}
    sheet = []
    for mk, (model, hs, hst) in sorted(models.items()):
        base = mk.split("\\")[-1].replace(".p3d", "")
        if only and base not in only:
            continue
        q = CP.clean(model)
        if not q.lower().endswith(".p3d"):
            q += ".p3d"
        if q.lower().startswith("z\\jmfsb\\"):
            path, reader = os.path.join(JMFSB, q[len("z\\jmfsb\\"):]), read_mlod_lod0
        else:
            path, reader = os.path.join(SP, "planes", base + ".p3d"), read_odol_lod0
        try:
            geo = reader(path)
        except Exception as ex:
            print("  ! %s: %s" % (base, ex))
            continue
        ms = masks_for(geo, hs)
        index[mk] = {}
        flip = next((v[3] for v in ms.values() if v), None)
        print("%-28s %s lod %.1f faces %d flipped %s selections %s" % (base, geo["version"], geo["res"], len(geo["faces"]),
                                                                     flip, {n: (v[1], v[2]) if v else None for n, v in ms.items()}))
        for i, name in enumerate(hs):
            if not ms.get(name) or re.search(r"(?i)number|cockpit|glass|interior|clan|insignia|decal", name):
                continue                        # only the exterior paint takes the sky colour
            m, nd, nf, flipped = ms[name]
            p = os.path.join(OUT, "%s__%s.png" % (base, name))
            m.save(p)
            index[mk][str(i)] = {"selection": name, "mask": p, "down_faces": nd, "faces": nf}
            if overlay and i < len(hst) and hst[i]:
                src = ("game:" + CP.clean(hst[i])) if CP.clean(hst[i]).lower().startswith("a3\\") else \
                    os.path.join(JMFSB, CP.clean(hst[i])[len("z\\jmfsb\\"):]) if CP.clean(hst[i]).lower().startswith("z\\jmfsb\\") else None
                png = PR.to_png(src, "plane_" + base + "_" + name) if src else None
                if png:
                    t = Image.open(png).convert("RGB").resize((512, 512), Image.BOX)
                    mm = np.asarray(m.resize((512, 512)), dtype=np.float32)[..., None] / 255 * 0.65
                    blend = np.asarray(t, dtype=np.float32) * (1 - mm) + np.array([80, 200, 255], dtype=np.float32) * mm
                    sheet.append(("%s %s" % (base, name), t, Image.fromarray(blend.astype(np.uint8))))
    json.dump(index, open(os.path.join(OUT, "index.json"), "w"), indent=1)
    if overlay and sheet:
        tile = 384
        img = Image.new("RGB", (tile * 2, (tile + 18) * len(sheet)), (20, 20, 20))
        d = ImageDraw.Draw(img)
        for n, (lab, t, b) in enumerate(sheet):
            y = n * (tile + 18)
            img.paste(t.resize((tile, tile)), (0, y))
            img.paste(b.resize((tile, tile)), (tile, y))
            d.text((4, y + tile + 3), lab, fill=(255, 255, 255))
        img.save(os.path.join(SP, "plane_undersides.png"))
        print("overlay:", len(sheet))


if __name__ == "__main__":
    main()
