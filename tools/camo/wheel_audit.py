"""Every made sheet in every faction, measured against its source inside the wheel mask. --fix deletes the ones whose
wheels were changed, so the next make writes them with the source's own wheels."""
import json, os, pickle, sys
sys.path.insert(0, "D:/Git/jmfs-custom-mod/tools/camo")
sys.path.insert(0, "D:/Git/jmfs-custom-mod/tools")
import numpy as np  # noqa: E402
from PIL import Image  # noqa: E402
import faction_camo_make as FM  # noqa: E402
import model_masks as MM  # noqa: E402
import vehicle_bases as VB  # noqa: E402

CP, PR = FM.CP, FM.PR
BS = chr(92)
G = "D:/Git/jmfs-custom-mod/addons/"
FIX = "--fix" in sys.argv
index = json.load(open(MM.INDEX))
table, g, strings = pickle.load(open("D:/work/camo_cache/faction_table.pickle", "rb"))
mp = json.load(open("D:/Git/jmfs-custom-mod/work/faction_camo.json", encoding="utf-8"))
seen, bad, gone = set(), [], {}
for addon, rows in mp["camo"].items():
    for cls, e in rows.items():
        model = VB.value(table, cls, "model")
        mk = CP.model_key(model) if model else None
        masks = index.get(mk, {}) if mk else {}
        if not masks:
            continue
        for src, rel in e.get("made", []):
            n = rel.split(BS)[-1]
            ti = next((i for i, t in enumerate(e["textures"]) if isinstance(t, str) and t.lower().endswith(n.lower())), None)
            wmp = masks.get(str(ti), {}).get("wheels") if ti is not None else None
            f = G + rel.replace(BS, "/")
            if not wmp or rel.lower() in seen or not os.path.exists(f):
                continue
            seen.add(rel.lower())
            try:
                import hashlib
                h = hashlib.sha1((str(src) + rel).lower().encode()).hexdigest()[:14]
                out = np.asarray(Image.open(PR.to_png(f, "wa_o_" + h)).convert("RGB"), dtype=np.float32) / 255
                a = np.asarray(Image.open(PR.to_png(src, "wa_s_" + h)).convert("RGB").resize(out.shape[1::-1], Image.BILINEAR), dtype=np.float32) / 255
                wm = np.asarray(Image.open(wmp).convert("L").resize((out.shape[1], out.shape[0])), np.float32) / 255 > 0.99
            except Exception as ex:
                print("   unreadable", rel, ex)
                continue
            if wm.sum() < 100:
                continue
            d = float(np.abs(out - a)[wm].mean())
            if d > 0.01:
                bad.append((d, addon, rel))
                if FIX:
                    os.remove(f)
                    gone[addon] = gone.get(addon, 0) + 1
print("made sheets with a wheel mask checked:", len(seen))
print("wheels changed from the source (diff > 0.01):", len(bad))
for d, addon, rel in sorted(bad, reverse=True)[:20]:
    print("   %.3f  %s" % (d, rel))
if FIX:
    print("deleted for remake:", gone, "total", sum(gone.values()))
