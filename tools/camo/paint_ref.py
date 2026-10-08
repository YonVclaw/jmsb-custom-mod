"""The paint colour of reference camos, measured on the full textures, and a contact sheet of them.

Paint colour: the median of the pixels in the middle half of the texture's brightness (the atlas's black
padding left out) - panel shadows and highlights fall outside it, the paint itself does not."""
import colorsys, json, os, subprocess, sys
import numpy as np
from PIL import Image, ImageDraw

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
# Everything this script caches or renders - the class table, the camo pool, the wheel masks, scratch PNGs.
# Outside the repo on purpose: it runs to hundreds of MB and none of it belongs in git. Override with
# JMFSB_CAMO_CACHE. It used to be a session scratchpad under %TEMP%, which would have taken the
# generator with it when that was cleaned.
SP = os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache")
os.makedirs(SP, exist_ok=True)
sys.path.insert(0, r"D:\Git\jmfs-custom-mod\tools\aegis_port")
import vanilla_config as VC  # noqa: E402

TMP = os.path.join(SP, "ref_tmp")
os.makedirs(TMP, exist_ok=True)
_entries = None


def game_entry(path):
    global _entries
    if _entries is None:
        _entries = {}
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
                        if lo.endswith(".paa"):
                            _entries[(pre + "\\" + lo) if pre else lo] = (pbo, e)
    lo = path.lower().replace("/", "\\").strip("\\")
    if not lo.endswith(".paa"):
        lo += ".paa"
    return _entries.get(lo)


def to_png(rep, name):
    """rep is game:<path> or a file on disk; returns a PNG path."""
    out = os.path.join(TMP, name + ".png")
    if os.path.exists(out):
        return out
    src = rep
    if rep.startswith("game:"):
        got = game_entry(rep[5:])
        if got is None:
            return None
        src = os.path.join(TMP, name + ".paa")
        open(src, "wb").write(VC.pbo_read(*got))
    subprocess.run(["hemtt", "utils", "paa", "convert", src, out], capture_output=True)
    return out if os.path.exists(out) else None


def paint_colour(png):
    a = np.asarray(Image.open(png).convert("RGB").resize((512, 512), Image.BOX), dtype=np.float32) / 255
    lum = a @ np.array([0.2126, 0.7152, 0.0722], dtype=np.float32)
    m = lum > 0.03
    lo, hi = np.percentile(lum[m], [25, 75])
    sel = m & (lum >= lo) & (lum <= hi)
    return np.median(a[sel], axis=0)


def hls(rgb):
    h, l, s = colorsys.rgb_to_hls(*[float(x) for x in rgb])
    return h * 360, l, s


if __name__ == "__main__":
    rows = json.load(open(os.path.join(SP, "camo_pool.json"), encoding="utf-8"))["rows"]
    WANT = {
        "NATO Sand": ("Base game", "Sand", ["M2A1 Slammer", "AMV-7 Marshall", "IFV-6c Panther"]),
        "NATO Olive": ("Base game", "Olive", ["M2A1 Slammer", "AMV-7 Marshall", "IFV-6c Panther"]),
        "Russian Green": ("Aegis", "Green", ["BTR-K Kamysh", "T-100 Varsuk", "Zamak Transport", "PO-30 Orca", "T-140 Angara"]),
        "Ardistan": ("Atlas", "Ardistan", ["BTR-K Kamysh", "T-100 Varsuk", "Zamak Transport", "PO-30 Orca",
                                          "To-199 Neophron (CAS)", "BTR-100A Lokhos"]),
        "CSAT Hex": ("Base game", "Hex", ["BTR-K Kamysh", "T-100 Varsuk"]),
    }
    sheet, out = [], {}
    for label, (origin, name, vehicles) in WANT.items():
        cols = []
        for r in rows:
            if r["name"] not in vehicles:
                continue
            c = next((c for c in r["camos"] if c["origin"] == origin and c["name"] == name and c.get("rep")), None)
            if c is None:
                continue
            png = to_png(c["rep"], "%s_%s" % (label.replace(" ", ""), r["name"].replace(" ", "").replace("/", "")))
            if not png:
                print("  no texture:", label, r["name"], c["rep"])
                continue
            rgb = paint_colour(png)
            cols.append(rgb)
            sheet.append((label + " - " + r["name"], png, rgb))
            h, l, s = hls(rgb)
            print("%-14s %-24s #%02x%02x%02x  H %3.0f L %.3f S %.3f" % (label, r["name"], *(int(x * 255) for x in rgb), h, l, s))
        if cols:
            med = np.median(np.array(cols), axis=0)
            out[label] = [float(x) for x in med]
            h, l, s = hls(med)
            print("%-14s %-24s #%02x%02x%02x  H %3.0f L %.3f S %.3f" % (label, "== median", *(int(x * 255) for x in med), h, l, s))
    json.dump(out, open(os.path.join(SP, "paint_ref.json"), "w"), indent=1)
    tile = 256
    cols_n = 6
    img = Image.new("RGB", (tile * cols_n, (tile + 40) * ((len(sheet) + cols_n - 1) // cols_n)), (24, 24, 24))
    d = ImageDraw.Draw(img)
    for i, (lab, png, rgb) in enumerate(sheet):
        x, y = (i % cols_n) * tile, (i // cols_n) * (tile + 40)
        img.paste(Image.open(png).convert("RGB").resize((tile, tile), Image.BOX), (x, y))
        d.rectangle([x, y + tile, x + tile, y + tile + 40], fill=tuple(int(v * 255) for v in rgb))
        d.text((x + 4, y + tile + 4), lab[:40], fill=(255, 255, 255))
    img.save(os.path.join(SP, "refs_sheet.png"))
    print("sheet:", len(sheet))
