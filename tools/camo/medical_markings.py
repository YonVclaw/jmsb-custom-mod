"""Put the game's own medical markings on every medical vehicle, over whatever camo it already wears.

user, 2026-09-21: "if a vech8cle is medical make sure the arma medical symbel is on it".

The symbols are not invented. Aegis ships a marked sheet for several models (the Ghost Hawk, the Marshall, the
Stomper, the BM-2T); comparing one against the plain sheet it was painted over gives the marking pixels exactly
where the model expects them. Those pixels are stamped onto the faction's own sheet for that slot.

    python tools/camo/medical_markings.py            # report what it would do
    python tools/camo/medical_markings.py --write     # write the sheets and update the camo map
"""
import hashlib
import io
import json
import os
import re
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
AEG = r"D:\Git\A3_Aegis_Public_Releases\A3_Aegis"

# model fragment -> (marked sheet, the plain sheet it was painted over, which hidden selection carries it)
PAIRS = [
    ("heli_transport_01", os.path.join(AEG, "air_f_aegis", "Heli_Transport_01", "Data", "Heli_Transport_01_ext01_medevac_CO.paa"),
     "game:A3" + BS + "Air_F_Beta" + BS + "Heli_Transport_01" + BS + "Data" + BS + "Heli_Transport_01_ext01_CO.paa", 0),
    ("apc_wheeled_01", os.path.join(AEG, "armor_f_aegis", "APC_Wheeled_01", "Data", "APC_Wheeled_01_base_medevac_CO.paa"),
     "game:a3" + BS + "armor_f_beta" + BS + "APC_Wheeled_01" + BS + "data" + BS + "APC_Wheeled_01_base_co.paa", 0),
    ("ugv_01", os.path.join(AEG, "soft_f_aegis", "UGV_01", "Data", "UGV_01_ext_medevac_CO.paa"),
     "game:A3" + BS + "Drones_F" + BS + "soft_f_gamma" + BS + "UGV_01" + BS + "data" + BS + "UGV_01_ext_co.paa", 0),
    ("apc_tracked_02", os.path.join(AEG, "armor_f_aegis", "APC_Tracked_02", "Data", "APC_Tracked_02_ext_01_medevac_RUkhk_CO.paa"),
     os.path.join(AEG, "armor_f_aegis", "APC_Tracked_02", "Data", "APC_Tracked_02_ext_01_RUkhk_CO.paa"), 0),
]
MEDICAL = re.compile(r"(?i)_(medic|medical|medevac)(_|$)")


def load(p, tag):
    # the cache key must follow the PATH, not the caller's label, or changing a source silently reuses the old one
    png = PR.to_png(p, tag + "_" + hashlib.sha1(str(p).lower().encode()).hexdigest()[:10])
    if not png:
        return None
    return np.asarray(Image.open(png).convert("RGB"), dtype=np.float32) / 255


def marking_mask(marked, plain):
    """Where the marked sheet departs from the sheet it was painted over: the panels and crosses."""
    if marked is None or plain is None:
        return None, None
    if plain.shape != marked.shape:
        plain = np.asarray(Image.fromarray((plain * 255).astype(np.uint8)).resize(marked.shape[1::-1]), dtype=np.float32) / 255
    d = np.abs(marked - plain).max(2)
    m = (d > 0.12).astype(np.float32)
    m = np.asarray(Image.fromarray((m * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(1.2)), dtype=np.float32) / 255
    return m, marked


def main():
    write = "--write" in sys.argv
    mp = json.load(io.open(MAP, encoding="utf-8"))
    masks = {}
    for frag, marked_p, plain_p, slot in PAIRS:
        mk, src = marking_mask(load(marked_p, "med_m_" + frag), load(plain_p, "med_p_" + frag))
        if mk is None:
            print("   cannot read the pair for %s - skipped" % frag)
            continue
        masks[frag] = (mk, src, slot)
        print("%-18s markings cover %.2f%% of the sheet" % (frag, 100 * float((mk > 0.5).mean())))
    done, skipped = 0, []
    for addon, rows in sorted(mp["camo"].items()):
        for cls, e in sorted(rows.items()):
            if not MEDICAL.search(cls):
                continue
            tex = [t for t in e.get("textures", []) if isinstance(t, str)]
            hit = next((f for f in masks if any(f in t.lower().replace("/", BS) for t in tex)), None)
            if hit is None:
                hit = next((f for f in masks if f in cls.lower()), None)
            if hit is None:
                skipped.append(cls)
                continue
            mk, marked, slot = masks[hit]
            if slot >= len(tex):
                skipped.append(cls)
                continue
            cur = tex[slot]
            q = FM.CP.clean(cur)
            if q.lower().startswith("z" + BS + "jmfsb" + BS):
                cur_file = os.path.join(ADDONS, q[len("z" + BS + "jmfsb" + BS + "addons" + BS):])
            else:
                cur_file = "game:" + q
            a = load(cur_file, "med_c_" + hashlib.sha1(q.lower().encode()).hexdigest()[:12])
            if a is None:
                skipped.append(cls)
                continue
            m2 = mk if mk.shape == a.shape[:2] else np.asarray(
                Image.fromarray((mk * 255).astype(np.uint8)).resize(a.shape[1::-1]), dtype=np.float32) / 255
            src2 = marked if marked.shape == a.shape else np.asarray(
                Image.fromarray((marked * 255).astype(np.uint8)).resize(a.shape[1::-1]), dtype=np.float32) / 255
            out = a * (1 - m2[..., None]) + src2 * m2[..., None]
            stem = os.path.basename(q).rsplit(".", 1)[0]
            rel = BS.join([addon, "data", "camo", "made", "medical", stem + "_med_CO.paa"])
            dst = os.path.join(ADDONS, rel.replace(BS, os.sep))
            if write:
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                tmp = dst.replace(".paa", ".png")
                Image.fromarray((np.clip(out, 0, 1) * 255 + 0.5).astype(np.uint8)).save(tmp)
                if os.path.exists(dst):
                    os.remove(dst)
                subprocess.run(["hemtt", "utils", "paa", "convert", tmp, dst], capture_output=True)
                os.remove(tmp)
                new_path = BS + "z" + BS + "jmfsb" + BS + "addons" + BS + rel
                e["textures"][slot] = new_path
                for o in e.get("options", []):
                    if o.get("ours") and slot < len(o.get("textures", [])):
                        o["textures"][slot] = new_path
                e["made"] = e.get("made", []) + [[cur_file, rel]]
            done += 1
    print()
    print("medical vehicles marked: %d%s" % (done, "" if write else " (dry run - pass --write)"))
    if skipped:
        print("no marked sheet exists for %d: %s%s" % (len(skipped), ", ".join(s.split("_", 2)[-1][:28] for s in skipped[:6]),
                                                       " ..." if len(skipped) > 6 else ""))
    if write:
        json.dump(mp, io.open(MAP, "w", encoding="utf-8", newline="\n"), indent=1, ensure_ascii=False)
        print("camo map updated - run tools/apply_faction_camo.py")


if __name__ == "__main__":
    main()
