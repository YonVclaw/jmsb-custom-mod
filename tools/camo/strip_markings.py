"""Paint out a national marking that a shipped texture carries.

Atlas's desert F-35 sheet (Plane_Fighter_05_ext1_desert_CO.paa) carries Israeli Air Force roundels, and it is the
default texture for that model, so the markings show even with aircraft left unpainted (user, 2026-09-21: "a few of
them have the star of david"). The roundels are found by colour - a strong blue on an otherwise desaturated skin -
grown a little, and filled from the surrounding skin, so the panel lines around them stay.

The result goes into addons/vehicle, the mod's shared vehicle-texture addon, because more than one faction uses it.

    python tools/camo/strip_markings.py
"""
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import numpy as np  # noqa: E402
from PIL import Image, ImageFilter  # noqa: E402
import faction_camo_make as FM  # noqa: E402

PR = FM.PR
JMFSB = r"D:\Git\jmfs-custom-mod"
JOBS = [(r"D:\Git\A3_Aegis_Public_Releases\A3_Atlas\air_f_atlas\Plane_Fighter_05\Data\Plane_Fighter_05_ext1_desert_CO.paa",
         os.path.join(JMFSB, "addons", "vehicle", "models", "air", "Plane_Fighter_05", "Data",
                      "Plane_Fighter_05_ext1_desert_nomark_CO.paa"))]


def marking(a):
    """A national marking: strong colour where the skin around it has almost none."""
    h, c = FM.hue(a)
    m = (a @ FM.W) > 0.02
    blue = m & (c > 0.14) & (h > 185) & (h < 265)
    # the roundel is a disc: the blue ring, the white star inside it and the white rim around it. Grow the blue
    # generously so the whole disc goes, or the star is left behind as white specks.
    grown = np.asarray(Image.fromarray((blue * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(21)),
                       dtype=np.float32) / 255 > 0.5
    return np.asarray(Image.fromarray((grown * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(9)),
                      dtype=np.float32) / 255 > 0.5


def fill(a, mask):
    """Replace the masked pixels with the skin around them: a heavy blur of the unmasked image."""
    keep = (~mask).astype(np.float32)[..., None]
    num = np.asarray(Image.fromarray((a * keep * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(14)), dtype=np.float32) / 255
    den = np.asarray(Image.fromarray((keep[..., 0] * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(14)), dtype=np.float32) / 255
    around = num / np.maximum(den, 1e-3)[..., None]
    soft = np.asarray(Image.fromarray((mask * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(1.2)), dtype=np.float32) / 255
    return np.clip(a * (1 - soft[..., None]) + around * soft[..., None], 0, 1)


def main():
    for src, dst in JOBS:
        png = PR.to_png(src, "mark_" + os.path.basename(src)[:24])
        if not png:
            raise SystemExit("cannot read " + src)
        a = np.asarray(Image.open(png).convert("RGB"), dtype=np.float32) / 255
        m = marking(a)
        out = fill(a, m)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        tmp = dst.replace(".paa", ".png")
        Image.fromarray((out * 255 + 0.5).astype(np.uint8)).save(tmp)
        if os.path.exists(dst):
            os.remove(dst)
        subprocess.run(["hemtt", "utils", "paa", "convert", tmp, dst], capture_output=True)
        os.remove(tmp)
        if not os.path.exists(dst):
            raise SystemExit("paa conversion produced nothing for " + dst)
        print("painted out %.3f%% of the sheet: %s" % (100 * float(m.mean()), os.path.basename(dst)))


if __name__ == "__main__":
    main()
