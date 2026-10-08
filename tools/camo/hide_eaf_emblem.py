"""Paint out the EAF (Livonian) emblem on the sheets the Turkish factions are built from.

user, days running: "turkey use eaf (remove the eaf logos or put black tukeys overs over it)".

The emblem is a small heraldic shield with a cross, the same asset on every EAF sheet. One copy of it is taken from
Aegis's Leopard sheet and matched against each source by normalised correlation on a quarter-scale grey copy; every
hit is filled from the skin around it. The cleaned sheets are written into the Turkish addon and the pipeline reads
them in place of the originals.

    python tools/camo/hide_eaf_emblem.py            # report the hits
    python tools/camo/hide_eaf_emblem.py --write     # write the cleaned sheets
"""
import hashlib
import json
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import numpy as np  # noqa: E402
from PIL import Image, ImageFilter  # noqa: E402
import faction_camo_make as FM  # noqa: E402

PR = FM.PR
BS = chr(92)
ROOT = r"D:\Git\jmfs-custom-mod"
ADDONS = os.path.join(ROOT, "addons")
MAP = os.path.join(ROOT, "work", "faction_camo.json")
# the emblem, as it sits on Aegis's Leopard sheet
TEMPLATE_SHEET = r"D:\Git\A3_Aegis_Public_Releases\A3_Aegis\armor_f_aegis\MBT_03\data\MBT_03_ext01_EAF_CO.paa"
TEMPLATE_BOX = (948, 1173, 62)          # centre x, centre y, half width, on a 2048 sheet
SCALE = 4                                # correlate at quarter size
THRESHOLD = 0.85          # 0.96 is the true emblem; the next candidates score 0.65 and are skin, not insignia


def load(p):
    png = PR.to_png(p, "eafm_" + hashlib.sha1(str(p).lower().encode()).hexdigest()[:12])
    if not png:
        return None
    return np.asarray(Image.open(png).convert("RGB"), dtype=np.float32) / 255


def grey_small(a):
    g = a @ FM.W
    h, w = g.shape
    return np.asarray(Image.fromarray((g * 255).astype(np.uint8)).resize((w // SCALE, h // SCALE)), dtype=np.float32) / 255


def correlate(img, tpl):
    """Normalised cross-correlation, by FFT."""
    th, tw = tpl.shape
    t = tpl - tpl.mean()
    tn = np.sqrt((t ** 2).sum()) or 1.0
    F = np.fft.rfft2(img, img.shape)
    T = np.fft.rfft2(t[::-1, ::-1], img.shape)
    num = np.fft.irfft2(F * T, img.shape)
    ones = np.ones_like(tpl)
    O = np.fft.rfft2(ones[::-1, ::-1], img.shape)
    s1 = np.fft.irfft2(np.fft.rfft2(img, img.shape) * O, img.shape)
    s2 = np.fft.irfft2(np.fft.rfft2(img ** 2, img.shape) * O, img.shape)
    n = th * tw
    var = np.maximum(s2 - (s1 ** 2) / n, 1e-6)
    return num / (np.sqrt(var) * tn + 1e-6)


def fill(a, mask):
    keep = (~mask).astype(np.float32)[..., None]
    num = np.asarray(Image.fromarray((a * keep * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(18)), dtype=np.float32) / 255
    den = np.asarray(Image.fromarray((keep[..., 0] * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(18)), dtype=np.float32) / 255
    around = num / np.maximum(den, 1e-3)[..., None]
    soft = np.asarray(Image.fromarray((mask * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(2.0)), dtype=np.float32) / 255
    return np.clip(a * (1 - soft[..., None]) + around * soft[..., None], 0, 1)


def eaf_sources():
    mp = json.load(open(MAP, encoding="utf-8"))
    out = {}
    for addon, rows in mp["camo"].items():
        if not addon.startswith("faction_turkey"):
            continue
        for cls, e in rows.items():
            for s_, _r in e.get("made", []):
                if "eaf" in str(s_).lower():
                    out[str(s_)] = True
    return sorted(out)


def main():
    write = "--write" in sys.argv
    base = load(TEMPLATE_SHEET)
    if base is None:
        raise SystemExit("cannot read the template sheet")
    cx, cy, r = TEMPLATE_BOX
    tpl_full = base[cy - r:cy + r, cx - r:cx + r]
    tpl = grey_small(tpl_full)
    tpl = tpl - tpl.mean()
    hits_total = 0
    for p in eaf_sources():
        a = load(p)
        if a is None:
            print("   unreadable: %s" % p)
            continue
        g = grey_small(a)
        if g.shape[0] < tpl.shape[0] or g.shape[1] < tpl.shape[1]:
            continue
        c = correlate(g, tpl)
        th, tw = tpl.shape
        mask = np.zeros(a.shape[:2], bool)
        found = 0
        cc = c.copy()
        for _ in range(4):
            i = int(np.argmax(cc))
            y, x = divmod(i, cc.shape[1])
            if cc[y, x] < THRESHOLD:
                break
            found += 1
            yy, xx = (y - th + 1) * SCALE, (x - tw + 1) * SCALE
            y0, y1 = max(0, yy), min(a.shape[0], yy + th * SCALE)
            x0, x1 = max(0, xx), min(a.shape[1], xx + tw * SCALE)
            mask[y0:y1, x0:x1] = True
            cc[max(0, y - th):y + th, max(0, x - tw):x + tw] = -1
        print("%-64s %d emblem(s)" % (os.path.basename(p)[:64], found))
        hits_total += found
        if found and write:
            out = fill(a, mask)
            rel = BS.join(["faction_turkey", "data", "camo", "noemblem", os.path.basename(p)])
            dst = os.path.join(ADDONS, rel.replace(BS, os.sep))
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            tmp = dst.replace(".paa", ".png")
            Image.fromarray((out * 255 + 0.5).astype(np.uint8)).save(tmp)
            if os.path.exists(dst):
                os.remove(dst)
            subprocess.run(["hemtt", "utils", "paa", "convert", tmp, dst], capture_output=True)
            os.remove(tmp)
    print()
    print("emblems found: %d%s" % (hits_total, "" if write else " (dry run - pass --write)"))


if __name__ == "__main__":
    main()
