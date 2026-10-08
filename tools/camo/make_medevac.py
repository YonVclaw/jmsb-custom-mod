"""The EU medevac Ghost Hawk: Atlas's woodland Ghost Hawk sheet with Aegis's medevac panels stamped onto it.

The user asked for the Transport_01 helicopters to wear
D:\\Git\\A3_Aegis_Public_Releases\\A3_Atlas\\air_f_atlas\\Heli_Transport_01\\Data\\Heli_Transport_01_ext01_au_CO.paa
and for the medevac one to carry a medical symbol (2026-09-21). The symbol is not invented: Aegis ships
Heli_Transport_01_ext01_medevac_CO.paa, which is the base game's own ext01 sheet with four medical panels painted
on. Those panels are found by comparing the two, and only those pixels are taken - so the panels land exactly where
the model expects them, on Atlas's camo.

Run: python tools/camo/make_medevac.py
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import subprocess  # noqa: E402
import numpy as np  # noqa: E402
from PIL import Image, ImageFilter  # noqa: E402
import faction_camo_make as FM  # noqa: E402

PR = FM.PR
BS = chr(92)
JMFSB = r"D:\Git\jmfs-custom-mod"
ATLAS = r"D:\Git\A3_Aegis_Public_Releases\A3_Atlas\air_f_atlas\Heli_Transport_01\Data"
AEGIS = r"D:\Git\A3_Aegis_Public_Releases\A3_Aegis\air_f_aegis\Heli_Transport_01\Data"
PLAIN = "game:A3" + BS + "Air_F_Beta" + BS + "Heli_Transport_01" + BS + "Data" + BS + "Heli_Transport_01_ext01_CO.paa"
OUT = os.path.join(JMFSB, "addons", "faction_eudf", "data", "Heli_Transport_01",
                   "Heli_Transport_01_ext01_au_medevac_CO.paa")


def load(p, tag):
    png = PR.to_png(p, tag)
    if not png:
        raise SystemExit("cannot read " + str(p))
    return np.asarray(Image.open(png).convert("RGB"), dtype=np.float32) / 255


def main():
    au = load(os.path.join(ATLAS, "Heli_Transport_01_ext01_au_CO.paa"), "mv_au")
    med = load(os.path.join(AEGIS, "Heli_Transport_01_ext01_medevac_CO.paa"), "mv_med")
    plain = load(PLAIN, "mv_plain")
    for a in (med, plain):
        if a.shape != au.shape:
            raise SystemExit("sheet sizes differ: %s vs %s" % (a.shape, au.shape))
    # the panels: where Aegis's medevac sheet departs from the sheet it was painted over
    d = np.abs(med - plain).max(2)
    m = (d > 0.12).astype(np.float32)
    # a soft edge, so the panel does not show a hard seam against the camo
    m = np.asarray(Image.fromarray((m * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(1.2)), dtype=np.float32) / 255
    out = au * (1 - m[..., None]) + med * m[..., None]
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    tmp = OUT.replace(".paa", ".png")
    Image.fromarray((np.clip(out, 0, 1) * 255 + 0.5).astype(np.uint8)).save(tmp)
    if os.path.exists(OUT):
        os.remove(OUT)                      # hemtt's convert refuses an existing output and still exits 0
    subprocess.run(["hemtt", "utils", "paa", "convert", tmp, OUT], capture_output=True)
    os.remove(tmp)
    if not os.path.exists(OUT):
        raise SystemExit("paa conversion produced nothing")
    print("panels taken: %d px (%.2f%% of the sheet)" % (int((d > 0.12).sum()), 100 * float((d > 0.12).mean())))
    print("written:", OUT)


if __name__ == "__main__":
    main()
