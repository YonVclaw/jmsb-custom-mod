"""Make the faction camo textures the pool does not have, and rewrite work/faction_camo.json for
tools/apply_faction_camo.py.

THE ASK (user, 2026-09-14), in order: "can you make textures ?"; "the russion shades of green and sand need to
be darker than the nato versions"; a photo "an example of russion artic vechicle camo"; two images "example of
the chinise camo's for vechicles"; then "on turkey the hemetts color is a bit off", a Turkish Leopard 2 photo
"as an example of arid camo for turkey make sure a small logo for the turkish miltary is on each vecnicle", "for
china a bit to much pink", a photo for a Chinese arid, "chinise artic camo", "chinice desert camo", and "need
russian and chinise camo for thses D:\\work\\qav\\type".

  faction_russia        Russian Green    NATO Olive's hue at 80% of its lightness
  faction_russia_arc    Russian Arctic   white, grey blotches, charcoal bands - after the photo
  faction_russia_ard    Russian Sand     NATO Sand's hue at 80% of its lightness
  faction_china         Chinese Woodland Digital  } every China vehicle also offers all four Chinese camos in its
  faction_china_ard     Chinese Desert Digital    } appearance menu - Woodland, Arid, Desert, Arctic - beside the
                                                    paints it had; the QAV Type 08s the three Russian ones too
  faction_turkey, _ind  Turkish Arid     ochre tan with dark green wavy bands - after the Leopard 2 photo -
                                         and a small Turkish flag (the photo's marking) on the main texture
Iran keeps the base game's arid hex. Russian camos are darker than NATO's (user); the others take their colours
from the user's images by eye, brought to the game's own paint brightness (a texture sits far darker than paint
looks in a photo).

A texture is made from the vehicle's plainest paint - a scheme named green, olive, sand... before its own look,
before a hex - keeping its shading, panel lines, weathering and markings (pixels far more colourful than the
paint and of another hue). A camo pattern under that paint is flattened first (depattern).

    python faction_camo_make.py --preview [--only a,b]   a before/after sheet of the PREVIEW vehicles, nothing written
    python faction_camo_make.py --plan [--only a,b]      each vehicle's source, nothing made
    python faction_camo_make.py [--only a,b]             make the textures into the addons and rewrite the map
"""
import colorsys, hashlib, json, os, pickle, re, subprocess, sys

BS_ = chr(92)
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
import camo_pool as CP  # noqa: E402
import paint_ref as PR  # noqa: E402

VB = CP.VB
JMFSB = r"D:\Git\jmfs-custom-mod"
MAP = os.path.join(JMFSB, "work", "faction_camo.json")
WORK = os.path.join(SP, "camo_make")
TABLE = os.path.join(SP, "faction_table.pickle")
W = np.array([0.2126, 0.7152, 0.0722], dtype=np.float32)
REF = json.load(open(os.path.join(SP, "paint_ref.json")))
DARKER = 0.8
WHITE_L = 0.624   # white_probe.py: the clean whites (saturation under 1%) - Laws of War ambulance .476, Samson
                  # .624, Mohawk .665; civilian whites measure darker, their atlases being mostly trim and interior
# Mods whose vehicles the factions use and whose files are on disk: config, and where its textures' prefix lives
MOD_CONFIGS = [r"D:\work\qav\type\QAV_Type08\config.cpp",
               r"D:\work\qav\QAV_Challenger\config.cpp",
               os.path.join(JMFSB, "work", "ef_dump.hpp")]   # tools/camo/ef_dump.py, from an in-game dump
MOD_ROOTS = {"qav_type08\\": r"D:\work\qav\type\QAV_Type08",
             "qav_challenger\\": r"D:\work\qav\QAV_Challenger",
             # user, 2026-09-21: "the textures are here D:\Git\EF_Samples\Hunter use olive"
             "ef_samples\\": r"D:\Git\EF_Samples"}
# Creator DLC art that the game will not hand over, but that ships unencrypted in a sample pack. The mod
# lays a texture out under ef\<vehicle>\data\; the pack lays the same files flat under one folder per
# vehicle, so they are matched on file name.
EF_SAMPLES = os.environ.get("EF_SAMPLES", r"D:\Git\EF_Samples")
_ef_index = None


def ef_file(q):
    global _ef_index
    if _ef_index is None:
        _ef_index = {}
        if os.path.isdir(EF_SAMPLES):
            for root, _d, fs in os.walk(EF_SAMPLES):
                for f in fs:
                    if f.lower().endswith((".paa", ".tga")):
                        _ef_index.setdefault(f.lower(), os.path.join(root, f))
    return _ef_index.get(os.path.basename(q.replace("/", "\\")).lower())


def shade(ref, factor):
    h, l, s = colorsys.rgb_to_hls(*REF[ref])
    return np.array(colorsys.hls_to_rgb(h, l * factor, s), dtype=np.float32)


TAGS = {"rusgreen": "Russian Green", "russand": "Russian Sand", "rusarctic": "Russian Arctic",
        "cnwdl": "Chinese Woodland Digital", "cnarid": "Chinese Arid Digital", "cndes": "Chinese Desert Digital",
        "cnarctic": "Chinese Arctic Digital", "trarid": "Turkish Arid", "trgreen": "Turkish Green",
        "irghex": "Iranian Green Hex",
        "euwdl": "EU Woodland", "eudes": "EU Desert", "euarc": "EU Arctic", "eutna": "EU Tropical",
        "vks": "Russian Air Force", "plaaf": "Chinese Air Force", "tuaf": "Turkish Air Force", "euaf": "EU Air Force"}
TAG_OWNER = {"rusgreen": "faction_russia", "russand": "faction_russia_ard", "rusarctic": "faction_russia_arc",
             "cnwdl": "faction_china", "cnarid": "faction_china_ard", "cndes": "faction_china", "cnarctic": "faction_china",
             "trarid": "faction_turkey", "trgreen": "faction_turkey", "irghex": "faction_iran_tna",
             "euwdl": "faction_eudf", "eudes": "faction_eudf_des", "euarc": "faction_eudf_arc",
             "eutna": "faction_eudf_tna",
             "vks": "faction_russia", "plaaf": "faction_china", "tuaf": "faction_turkey", "euaf": "faction_eudf"}
def chip(h, sat, ref, factor):
    """A paint of the chip's hue and saturation at the brightness of the game's own paint named, times factor -
    a chip is a lit swatch, a texture sits far darker (the sand chip measures 0.43, NATO Sand's sheets 0.275)."""
    c = np.array(colorsys.hls_to_rgb(h / 360, 0.3, sat), dtype=np.float32)
    want = float(np.array(REF[ref], dtype=np.float32) @ W) * factor
    return np.clip(c * (want / float(c @ W)), 0, 1)


# user, 2026-09-18, "ok start working on russia" with two AK 3rd Gen chips: Russian Green AK11159 (Tamiya XF62,
# FS 34083; measured off the chip #282916, hue 63, saturation .30) and Russian Sand 7K AK11370 (#7c6c52, hue 37,
# saturation .20). Each is laid on at the game's NATO paint brightness times DARKER, the standing rule ("the
# russion shades of green and sand need to be darker than the nato versions"): the green lands at 0.150, a hair
# under the chip's own 0.155; the sand at 0.220 against NATO Sand's 0.275.
# 2026-09-18 evening, "the russian green needs to be darker also": the green comes down from 0.8 to 0.7 of NATO
# Olive (0.150 to 0.131), the sand stays. A QAV Type 08 keeps the 0.8 level (TARGET_KEEP), as the arid ones keep
# theirs: their own rvmats already sit them darker in game than the BI models at the same sheet level.
# 2026-09-19, "russia should not be fucking lime green": the AK chip's swatch measured hue 63 at saturation .30, and
# the game's light turns that lime. The green is now a muted dark olive - hue 75, saturation .12, the hue and
# saturation Aegis's own Russian green measures (paint_ref.json) - at the darker level (0.7 of NATO Olive).
# 2026-09-19: Aegis's khaki sheets are copied wherever a Russian model has them, so the made ones take that exact
# paint - REF["Russian Green"] is the colour paint_ref.py measured off Aegis's Green sheets (#2d2e25, hue 67,
# saturation .11, 0.177) - and no darkening, or a made vehicle would sit a step darker than a copied one.
# russand: #4f4837, measured off Aegis's own sand sheet on the Boomerang (paint_colour, 2026-09-20), so a made
# vehicle matches a copied one
# 2026-09-21, "pur white for artic": the EU arctic is a plain white paint, the game's own clean white
# 2026-10-06, "remake russia without the e22 but make camos to match the e22 color scheme": the Russian green and sand
# are e22 RAF's woodland and arid paint, measured with paint_ref.paint_colour off its T-100 hull sheets (#2e3129,
# #504940) - a shade off Aegis's green (#2d2e25) and the old sand (#4f4837). The Turkish tropical keeps the old green
# (TARGET_GREEN_SRC) - it was only ever borrowed from Russia.
E22_WOODLAND = np.array([0x2e, 0x31, 0x29], dtype=np.float32) / 255
E22_ARID = np.array([0x50, 0x49, 0x40], dtype=np.float32) / 255
TARGET = {"rusgreen": E22_WOODLAND,
          "russand": E22_ARID,
          "euarc": np.ones(3, dtype=np.float32)}
TARGET_GREEN_SRC = np.array(REF["Russian Green"], dtype=np.float32)      # the Turkish tropical's green
TARGET_KEEP = {"rusgreen": E22_WOODLAND}
# A camo that is a MOD's own scheme, copied as it is rather than made:
#   (scheme name, the mods it may come from, what to do for a model the mod has no scheme for)
# "leave" puts the vehicle back in its own paint - Turkey, where the user asked for the made textures gone
# outright. "make" falls back to the made camo - Russia, where leaving a third of the faction in factory
# paint would read worse than a recolour (user, 2026-09-16: "the russian textures from
# D:\Git\A3_Aegis_Public_Releases should be whats applyed to the green russiasn faction").
# Aegis's own Russian green IS its "Green" scheme - the RUkhk sheets the made camo was recoloured from.
# trarid was "leave" while the user wanted the made textures gone outright; "make" now, so the models Atlas
# has no Marar scheme for get the made Turkish Arid instead of sitting in factory paint (user, 2026-09-16:
# "with turkey fill in the gaps of missing textures").
# rusgreen WAS ("green", ("Aegis",), "make") - Aegis's own Green copied where the model has it (user, 2026-09-16).
# Dropped 2026-09-18 with the AK chip: a copied Aegis sheet is Aegis's green (hue 67, saturation .11, 0.177), not
# the chip's, and "one should not be darker than the other" wants every Russian vehicle made the same way. Put
# it back if the user would rather keep Aegis's hand-made sheets where they exist.
MOD_SCHEME = {"irghex": (("greenhex", ("Base game", "Apex", "Aegis", "JMSB", "mod")), "make"),
              "trarid": ("marar", ("Atlas",), "make"),
              # rusgreen and russand copied Aegis's Green and Sand sheets where a model had them (2026-09-16/20).
              # 2026-10-06: made for every model in e22's colours instead, so the whole faction matches e22 alike.
              # the Challenger's own schemes come up as "Base game" or "JMSB" depending on which config the table
              # read them from (the mod's, or jmfsb_vehicle's import of it): either way they are the mod's own sheets
              # the EU woodland is copy-only: Aegis's woodland, else the vehicle's own olive (user, 2026-09-21)
              # NATO colours, copied off the vehicle itself - no woodland sheets (user, 2026-09-21)
              # 2026-09-25, "return the eu to nato colors ... use existing textures for woodland and arid, only make
              # artic": copy-only. Each vehicle's own NATO olive (woodland) or sand (arid) sheets, copied as they are;
              # a model with neither keeps its own paint. Nothing is made for either.
              "euwdl": (("__none__", ()), "leave"),
              "eudes": (("__none__", ()), "leave")}
CHINESE = ["cnwdl", "cnarid", "cndes", "cnarctic"]
RUSSIAN = ["rusgreen", "russand", "rusarctic"]

# plainest-first source names. blue is the jets' plain paint (Aegis's Grey on the Neophron is a grey digital);
# Aegis's Russia and the game's BLUFOR are the UAVs', SDV's and boats' (their own OPFOR paint is a grey hex no
# tint grouping can flatten); Russia comes last where its red stars do not belong - markings are kept
# "blue"/"bluestar" are deliberately absent: they are a JET's plain paint (PLANE_PLAIN keeps them). On a
# ground vehicle the only Blue is the civilian one, and painting every Zamak from its blue cab left the blue
# showing through the camo - saturated enough that keep_mask held it for a marking (user, 2026-09-16: "wtf is
# up with the jmfsb_China_O_T_Truck_02_MRL_F", a blue-cabbed MRL).
GREENISH = ["russia", "green", "olive", "khaki", "sand", "desert", "brown", "tan", "blufor", "grey", "black"]
SANDY = ["sand", "desert", "tan", "khaki", "russia", "green", "olive", "brown", "blufor", "grey", "black"]
WHITISH = ["white", "grey", "russia", "green", "olive", "khaki", "sand", "desert", "brown", "tan", "blufor", "black"]
NEUTRAL = ["green", "olive", "khaki", "sand", "desert", "brown", "tan", "blufor", "grey", "black", "russia"]
# PLAINEST SCHEME PER MODEL, over the faction's list. The Zamak's own paint is the base game's OPFOR hex, and no
# recolour flattens that hex: the Russian KamAZ came out green with the hex cells showing (user, 2026-10-06: "the
# kamaz have a weird hex pattern to them"). The AAF scheme is no better - AAF digital, which showed through the same
# way - and the LDF one is splinter. Aegis's Russian khaki (RUkhk) is plain on every Truck_02 model, so the Russian
# camos start from that: model pattern -> a texture pattern the preferred set carries. Only these sheets are read
# from the Aegis source (AEGIS_SOURCE); every other vehicle's choice is untouched.
PREFER_BY_MODEL = {tag: {r"truck_02_": r"_rukhk_co\.paa$"} for tag in RUSSIAN}
AEGIS_SOURCE = {"a3_aegis\\soft_f_aegis\\truck_02\\": r"D:\Git\A3_Aegis_Public_Releases\A3_Aegis\soft_f_aegis\Truck_02"}
JOBS = {    # addon: (default camo, plainest-first sources, the camos its appearance menu offers)
    "faction_russia": ("rusgreen", GREENISH, []),
    "faction_russia_arc": ("rusarctic", WHITISH, []),
    "faction_russia_ard": ("russand", SANDY, []),
    # 2026-09-18: the woodland alone - "the tropical and woodland pla cammo", one reference image. The Arid,
    # Desert and Arctic menu entries of the earlier runs are not made until they are asked for again.
    "faction_china": ("cnwdl", NEUTRAL, []),
    # 2026-09-18, "lets do the arid plan/china": the arid faction wears the PLA arid digital (the LZ324 photo's
    # colours), made and levelled the way the woodland is - not the parade-ground desert scheme it defaulted to
    "faction_china_ard": ("cnarid", NEUTRAL, []),
    # 2040 Iran (Tropical): the base game's own green hex on every model that has one, copied - it is a base-game
    # path, so nothing is even written - and a model without one left in its arid hex (user, 2026-09-20)
    "faction_iran_tna": ("irghex", NEUTRAL, []),
    "faction_turkey": ("trarid", NEUTRAL, ["trgreen"]),
    "faction_turkey_ind": ("trgreen", NEUTRAL, ["trarid"]),
    # both camos on both sides (user, 2026-09-21: "2 typed of tukey factions arid and woodland tropical, on both
    # east and ind side"): east arid + east tropical, independent arid + independent tropical
    "faction_turkey_tna": ("trgreen", NEUTRAL, ["trarid"]),
    "faction_turkey_ind_ard": ("trarid", NEUTRAL, ["trgreen"]),
    # EU (user: "eu woodland should be the wdl camos from aegis/atlas. find or make an artic vertion and deset
    # versions"): Aegis's/Atlas's own wdl; Atlas's own desert where it has one, else the wdl's pattern in desert or
    # arctic colours; a vehicle with no wdl, the same colours as blotches over its plainest paint
    # faction_eudf_wdl and faction_eudf_tna are gone (user, 2026-09-19: "green and arid are all wee are doing", "and
    # artic for russia and the eu"): the EU is 2040 EUDF (Woodland) - the fullest roster, once the plain EUDF -
    # EUDF (Arid) and EUDF (Arctic).
    "faction_eudf_des": ("eudes", ["sand", "desert", "tan", "khaki", "green", "olive", "brown", "blufor", "blue",
                                   "grey", "black", "russia"], []),
    "faction_eudf_arc": ("euarc", ["white", "grey", "green", "olive", "khaki", "sand", "desert", "brown", "tan",
                                   "blufor", "blue", "black", "russia"], []),
    # "do want to make eu and us a bit differnt": the US factions wear the game's plain NATO paints, so every EU
    # faction wears the pattern - EUDF the woodland, EUDF (Tropical) the same pattern in tropical greens
    "faction_eudf": ("euwdl", NEUTRAL, []),
}
DEFAULT_NATO = set()   # the EU woodland and arid copy NATO olive / sand per vehicle (MOD_SCHEME "leave")
# Vehicles whose parent the pipeline cannot read (Creator DLC, encrypted), painted BY SELECTION NAME from a
# sibling's sheets: the jmfsb class states hiddenSelections[] itself, so the game pairs texture to selection by
# the names given here and the parent's own order never enters into it. user, 2026-09-18, twice: "jmfsb_China_
# O_T_Truck_03_cargo_RF is not camoed" - Reaction Forces' Typhoon Cargo. Every Tempest variant on disk (seven
# models, surveyed) lays its cab and chassis on Camo1 = truck_03_ext01 and Camo2 = truck_03_ext02, so the RF
# flatbed, built on the same model, takes those two from the faction's Tempest transport and keeps its bed.
# UNVERIFIED against the RF model itself: if the cab or bed comes up wrong in game, dump_hidden_selections.sqf
# with RF loaded gives the real names and this entry gets corrected.
#   class-name pattern: (sibling class-name pattern, selection names, which of the sibling's textures they take -
#   an index into the sibling's set, or "tile" for a plain sheet of the camo with no baked detail, which fits any
#   UV layout without painting another model's panel lines on it)
# 2026-09-18, after the cab and chassis took: "the beds of the trucks are not camoed". The bed is a third
# selection, Camo3 on every Tempest variant on disk, carrying RF's own encrypted sheet, which cannot be
# recoloured. It takes the tile instead.
MANUAL = {r"(?i)Truck_03_cargo_RF$": (r"(?i)Truck_03_transport", ["Camo1", "Camo2", "Camo3"], [0, 1, "tile"]),
          # user, 2026-09-18: "there are 3 versions of the otokar they all need to be in the turkey faction" - the
          # Marid HMG is Western Sahara's, unreadable on disk; work/ef_selections.txt has its selections in order
          r"(?i)APC_Wheeled_02_hmg_lxWS$": (r"(?i)APC_Wheeled_02_rcws_v2", ["camo1", "camo2", "camo3", "camo6"],
                                            [0, 1, "tile", "tile"]),
          # the unarmed Marid (user, 2026-09-19: "not an unarmed one"): dumped as camo1, camo2, CamoNet, CamoSlat, camo6
          r"(?i)APC_Wheeled_02_unarmed_lxWS$": (r"(?i)APC_Wheeled_02_rcws_v2", ["camo1", "camo2", "camo6"], [0, 1, "tile"]),
          # the Western Sahara A-10D in the EU arid has lxWS-only sheets and flew in US markings (user, 2026-09-19);
          # it takes the EU air force greys the plain EUDF's Wipeout wears - a sibling in ANOTHER addon (4th field)
          r"(?i)Plane_CAS_01_dynamicLoadout_lxWS$": (r"(?i)Plane_CAS_01_dynamicLoadout", ["Camo_1", "Camo_2"], [0, 1], "faction_eudf"),
          # the EF Hunter FSV: dumped as camo1 (MRAP_01_base), camo2 (MRAP_01_adds), camo3/camo4 (EF's own FSV sheets)
          # the medevac Ghost Hawk takes the medical-panel sheet for camo1 and its sister's camo for the rest
          # (user, 2026-09-21: "add a medical symbel to the medicvac helo"). 2026-09-25: Aegis's own medevac set - its
          # ext01_medevac sheet (copied into faction_eudf unchanged) and the base game's dark ext02, add and DAP sheets it
          # was painted over - one scheme on the whole airframe; the arctic whitens all four, red kept
          # the Ghost Hawk's selections are camo1..camo4 (the game's config, work/ef_selections.txt); "Camo_1" named
          # nothing on the model, so the medevac never took these sheets (found 2026-09-26)
          r"(?i)_B_Heli_Transport_01_medevac_F$": (r"(?i)_B_Heli_Transport_01_F$", ["camo1", "camo2", "camo3", "camo4"],
                                                   ['\\z\\jmfsb\\addons\\faction_eudf\\data\\Heli_Transport_01\\Heli_Transport_01_ext01_medevac_CO.paa',
                                                    '\\A3\\Air_F_Beta\\Heli_Transport_01\\Data\\Heli_Transport_01_ext02_CO.paa',
                                                    '\\A3\\Air_F_Beta\\Heli_Transport_01\\Data\\Heli_Transport_01_ext01_add_co.paa',
                                                    '\\A3\\Air_F_Beta\\Heli_Transport_01\\Data\\heli_transport_01_dap_CO.paa']),
          # camo3/camo4 are the EF module (gun, launcher, radar): made from the EF's own olive sheets (user, 2026-09-20:
          # "you did not camo the ef part" - a grey tile is what the placeholder gave them)
          r"(?i)EF_B_MRAP_01_(FSV|AT|LAAD)_NATO$": (r"(?i)_B_MRAP_01_F$", ["camo1", "camo2", "camo3", "camo4"],
                                                    [0, 1, 'ef_samples\\Hunter\\hunter_01_olive_co.paa', 'ef_samples\\Hunter\\hunter_02_olive_co.paa'])}
# Per addon, over MANUAL. The EU arid's NH90 variants with no Western Sahara twin wear Western Sahara's own NATO sand
# sheets (user, 2026-09-26: "only one in the arid eu faction has the right camo"). Creator DLC is encrypted, so the
# sheets are referenced where they lie - the arid faction's desert vehicles need Western Sahara loaded already.
WS_NH90_SAND = [BS_ + "lxWS" + BS_ + "air_f_lxWS" + BS_ + "Data" + BS_ + "NATO" + BS_ + f for f in (
    "lxWS_Heli_Transport_01_ext01_sand_CO.paa", "lxWS_Heli_Transport_01_ext02_sand_CO.paa",
    "heli_transport_01_ext01_add_sand_co.paa", "Heli_Transport_01_DAP_sand_CO.paa")]
MANUAL_BY_ADDON = {"faction_eudf_des": {
    r"(?i)_B_Heli_Transport_01_(pylons|unarmed)_F$": (r"(?i)_B_Heli_Transport_01_F$", ["camo1", "camo2", "camo3", "camo4"],
                                                    WS_NH90_SAND),
    # no sand medevac sheet exists: the medevac is the sand NH90, without the red crosses
    r"(?i)_B_Heli_Transport_01_medevac_F$": (r"(?i)_B_Heli_Transport_01_F$", ["camo1", "camo2", "camo3", "camo4"],
                                             WS_NH90_SAND)}}
REFERENCED = ("lxws" + BS_,)    # encrypted Creator DLC: referenced by path, never read or copied
TILE = 2048


def make_tile(tag):
    """A sheet of the camo alone: the pattern laid on a flat paint at the game's level, no shading, no markings.
    Written once per camo under the owner's data/camo/made/tile folder; returns the config path."""
    rel = "%s\\data\\camo\\made\\tile\\%s_tile_co.paa" % (TAG_OWNER[tag], tag)
    dst = os.path.join(JMFSB, "addons", rel)
    if os.path.exists(dst) and not (tag in REMAKE_TAGS and os.path.getmtime(dst) < REMAKE_SINCE):
        return "\\z\\jmfsb\\addons\\" + rel
    if tag in DIGITAL:
        hexes, _sh, _cf, _blob, _rag, (ref, factor) = DIGITAL[tag]
        base = base_level(srgb(hexes), ref, factor)[0]
    elif tag in TARGET:
        base = TARGET[tag]
    elif tag in ("trarid", "trgreen"):
        hexes, _band, (ref, factor) = TURKISH_GREEN if tag == "trgreen" else TURKISH
        base = base_level(srgb(hexes), ref, factor)[0]
    elif tag == "rusarctic":
        base = np.array(colorsys.hls_to_rgb(40 / 360, WHITE_L, 0.03), dtype=np.float32)
    else:
        return None
    a = np.tile(base[None, None, :], (TILE, TILE, 1)).astype(np.float32)
    a = np.clip(a * (1 + 0.02 * (np.random.default_rng(7).random((TILE, TILE, 1)) - 0.5)), 0, 1).astype(np.float32)
    DIGITAL_KEY[0] = rel
    SRC_NAME[0] = "tile"
    seed = int(hashlib.sha1(("tile" + tag).encode()).hexdigest()[:8], 16)
    if tag in DIGITAL:
        out = digital(a, seed, tag)
    elif tag == "euarc":
        out = arctic_white(a)
    elif tag in TARGET:
        out = solid(a, TARGET[tag], None, tag)
    elif tag in ("trarid", "trgreen"):
        out = splinter(a, seed, TILE, tag)
    else:
        out = arctic(a, seed)
    pink_check(out, a, rel)
    tmp = os.path.join(WORK, "tile_%s.png" % tag)
    Image.fromarray((out * 255 + 0.5).astype(np.uint8)).save(tmp)
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    if os.path.exists(dst):
        os.remove(dst)
    subprocess.run(["hemtt", "utils", "paa", "convert", tmp, dst], capture_output=True)
    os.remove(tmp)
    if not os.path.exists(dst):
        print("   ! convert failed, no tile written: %s" % rel)
        return None
    return "\\z\\jmfsb\\addons\\" + rel
WHY = sys.argv[sys.argv.index("--why") + 1] if "--why" in sys.argv else None
ONLY = set(sys.argv[sys.argv.index("--only") + 1].split(",")) if "--only" in sys.argv else None
PREVIEW = ["jmfsb_China_qav_o_t_625e", "jmfsb_China_O_T_APC_Tracked_02_cannon_ghex_F",
           "jmfsb_China_ard_O_Truck_02_transport_F", "jmfsb_Turkey_B_Truck_01_cargo_F",
           "jmfsb_Turkey_Athena_O_T_MRAP_03_F", "jmfsb_Turkey_Athena_O_T_Truck_03_covered_F",
           "_MRAP_01_AT_EF", "_Heli_Transport_01_F", "_MBT_03_cannon", "_Truck_01_transport",
           "jmfsb_Russia_O_R_Plane_Fighter_02_F", "jmfsb_China_O_T_VTOL_02_infantry_dynamicLoadout_F",
           "jmfsb_Turkey_Athena_B_G_Plane_Fighter_05_F", "jmfsb_EUDF_B_Plane_CAS_01_dynamicLoadout_F"]
if "--preview-names" in sys.argv:
    PREVIEW = sys.argv[sys.argv.index("--preview-names") + 1].split(",")
# --names a,b: a real run for only the classes whose name has one of these; the addon's other rows are kept
NAMES = sys.argv[sys.argv.index("--names") + 1].lower().split(",") if "--names" in sys.argv else None
STATS = {"pattern flattened": 0, "plain": 0, "flags": 0, "pink checked": 0, "pattern flattened by brightness": 0,
         "hex source, broad shading": 0}


def norm(n):
    return re.sub(r"\[.*?\]|[^a-z]", "", (n or "").lower())


def hue(a):
    mx, mn = a.max(-1), a.min(-1)
    d = np.where(mx - mn < 1e-6, 1e-6, mx - mn)
    r, g, b = a[..., 0], a[..., 1], a[..., 2]
    h = np.where(mx == r, (g - b) / d % 6, np.where(mx == g, (b - r) / d + 2, (r - g) / d + 4)) * 60
    return h, mx - mn


def paint_of(a, lum):
    m = lum > 0.02
    lo, hi = np.percentile(lum[m], [25, 75])
    sel = m & (lum >= lo) & (lum <= hi)
    return np.median(a[sel], axis=0), m


def keep_mask(a, p, m):
    """The padding, and markings: far more colourful than the paint and of another hue."""
    h, c = hue(a)
    ph, pc = hue(p[None, None, :])
    dh = np.abs(h - float(ph[0, 0]))
    dh = np.minimum(dh, 360 - dh)
    return (~m) | ((c > max(0.10, 3 * float(pc[0, 0]))) & (dh > 45))


def depattern(a, lum, m):
    """A camo pattern under the paint, flattened: hex cells differ in tint, shading only in brightness. The
    pixels are grouped by tint (r and g over the sum, on a lightly blurred copy, so a panel line takes its
    cell's group); where two or more large, distinct groups turn up, each is brought to the texture's
    median brightness, its own shading kept. A plain paint has one tint and is left as it is."""
    h, w = lum.shape
    rad = max(1.5, w / 512)
    b = np.asarray(Image.fromarray((a * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.GaussianBlur(rad)),
                   dtype=np.float32) / 255
    s = b.sum(-1) + 1e-4
    ch = np.stack([b[..., 0] / s, b[..., 1] / s], -1)
    bl = b @ W
    lo, hi = np.percentile(bl[m], [10, 95])
    px = ch[m & (bl > lo) & (bl < hi)]
    if len(px) < 100:               # a flat sheet (the bed tile): nothing between its percentiles, nothing to flatten
        STATS["plain"] += 1
        return lum
    px = px[:: max(1, len(px) // 200000)]
    order = np.argsort(px[:, 0])
    c = px[order[[len(px) // 6, len(px) // 2, len(px) * 5 // 6]]]
    for _ in range(15):
        lab = ((px[:, None, :] - c[None]) ** 2).sum(-1).argmin(1)
        c = np.stack([px[lab == i].mean(0) if (lab == i).any() else c[i] for i in range(3)])
    share = np.bincount(lab, minlength=3) / len(lab)
    big = [i for i in range(3) if share[i] >= 0.12]
    if len(big) < 2 or max(float(np.linalg.norm(c[i] - c[j])) for i in big for j in big if i < j) < 0.012:
        STATS["plain"] += 1
        return lum
    full = np.stack([((ch - c[i]) ** 2).sum(-1) for i in range(3)]).argmin(0)
    lg = float(np.median(lum[m]))
    lc = np.array([float(np.median(lum[m & (full == i)])) if (m & (full == i)).any() else lg for i in range(3)])
    factor = (lg / np.maximum(lc, 1e-3)).astype(np.float32)[full]
    enc = np.clip((factor - 0.25) / 2.5, 0, 1)
    enc = np.asarray(Image.fromarray((enc * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.GaussianBlur(rad)),
                     dtype=np.float32) / 255
    STATS["pattern flattened"] += 1
    return np.clip(lum * (enc * 2.5 + 0.25), 0, 1)


SRC_NAME = [""]             # the source sheet being read, lower-cased path: prepare() gates the hex handling on it
SNOW_TAGS = {"euarc", "rusarctic", "cnarctic"}
WHEEL_SHEET = re.compile(r"(?i)(^|[_-])(wheel|wheels|tyre|tyres|tire|tires|rim|rims)([_-]|$)")
# a mod sheet that holds the running gear: no model, so no mask - left alone rather than painted over
PARTS_SHEET = re.compile(r"(?i)(^|[_-])(details?|mprimer)([_-]|$)")
PARTS_ROOTS = ("ef_samples" + chr(92), "d:" + chr(92) + "git" + chr(92) + "ef_samples")
# a parts sheet from the base game counts too, not just a mod's
PARTS_ANY = re.compile(r"(?i)(^|[_-])mprimer([_-]|$)")
TURRET = re.compile(r"(?i)turret|tower|rcws|_gun|cannon|weapon|mlrs|arty|tows")
PLAIN_TURRETS = set()   # 2026-09-20: vehicle turrets are camoed with the hull, no plain base colour
HEX_NAMED = re.compile(r"(?i)hex|_arid|ghex")


def hex_source():
    return bool(HEX_NAMED.search(SRC_NAME[0] or ""))


def depattern_lum(lum, m, w):
    """The second flattening stage, by brightness alone. The CSAT hex on the Qilin's arid sheet is three tones
    that differ far more in brightness than in tint, so the tint grouping above left it standing and the Russian
    plain paint came out hex-patterned (preview, 2026-09-18). The paint's brightness is blurred just enough that
    a hex cell keeps its level while a panel line or rivet does not, and grouped into three; only when at least
    two large groups sit on flat plateaus - each group's spread under a third of the gap between them, which a
    smooth run of baked shadow never manages - is it a pattern, and each group is brought to the sheet's median.
    The group map is taken from the blurred copy, so a dark line keeps its contrast against its own cell."""
    if not hex_source():
        return lum                  # only a sheet the game names as a hex gets this far (see hex_source)
    rad = max(2.0, w / 160)
    mf = m.astype(np.float32)
    bl = blur_lum(lum * mf, rad) / np.maximum(blur_lum(mf, rad), 1e-3)
    lo, hi = np.percentile(bl[m], [5, 97])
    px = bl[m & (bl > lo) & (bl < hi)]
    if len(px) < 1000:
        return lum
    px = px[:: max(1, len(px) // 200000)]
    K = 4
    c = np.percentile(px, [12, 37, 62, 87]).astype(np.float32)
    for _ in range(15):
        lab = np.abs(px[:, None] - c[None]).argmin(1)
        c = np.array([px[lab == i].mean() if (lab == i).any() else c[i] for i in range(K)], dtype=np.float32)
    share = np.bincount(lab, minlength=K) / len(lab)
    std = np.array([px[lab == i].std() if (lab == i).any() else 0 for i in range(K)])
    big = [i for i in range(K) if share[i] >= 0.08]
    gaps = [abs(c[i] - c[j]) for i in big for j in big if i < j]
    flat = any(abs(c[i] - c[j]) >= 0.04 and abs(c[i] - c[j]) > 3 * max(std[i], std[j])
               for i in big for j in big if i < j)
    if not flat or not gaps:
        return lum
    full = np.abs(bl[..., None] - c[None, None, :]).argmin(-1)
    # ...with SHARP edges between the groups: across a hex cell's edge the blurred brightness steps most of the way
    # from one group's level to the next within two blur radii; across a plain sheet's baked shading it creeps,
    # and a threshold crossed by a slow gradient is not a pattern. The plateau test alone fired on 94 of 100
    # sheets (any hull with a lit top and a shaded side has two plateaus).
    sd = int(2 * rad) + 1
    step = np.abs(bl - np.roll(bl, sd, 1))
    at = m & np.roll(m, sd, 1) & (full != np.roll(full, sd, 1))
    if at.sum() < 500:
        return lum
    sharp = float(np.median(step[at])) / float(min(gaps))
    if sharp < 0.45:
        return lum
    # the cells' drawn outlines lie on the group boundaries: a band along them takes a median, which drops a line
    # up to four pixels wide, while a panel line elsewhere on the sheet is left as it is
    edge = (full != np.roll(full, 1, 1)) | (full != np.roll(full, 1, 0))
    band = np.asarray(Image.fromarray((edge * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(9))) > 0
    med = np.asarray(Image.fromarray((np.clip(lum, 0, 1) * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.MedianFilter(9)),
                     dtype=np.float32) / 255
    lum = np.where(band & m, med, lum)
    lg = float(np.median(lum[m]))
    lc = np.array([float(np.median(lum[m & (full == i)])) if (m & (full == i)).any() else lg for i in range(K)])
    factor = (lg / np.maximum(lc, 1e-3)).astype(np.float32)[full]
    enc = np.clip((factor - 0.25) / 2.5, 0, 1)
    enc = blur_lum(enc, max(1.0, w / 512))
    STATS["pattern flattened by brightness"] += 1
    return np.clip(lum * (enc * 2.5 + 0.25), 0, 1)


def paint_level(a):
    """(median brightness of the paint, how many pixels of paint it was measured over)."""
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    if not m.any():
        return None, 0
    lum = plane_lum(a) if hex_source() else depattern(a, lum0, m)
    lo, hi = np.percentile(lum[m], [25, 75])
    sel = m & (lum >= lo) & (lum <= hi)
    if not sel.any():
        return None, 0
    return float(np.median(lum[sel])), int(m.sum())


# user, 2026-09-18, a screenshot of two Kamysh hulls in Russian Sand and Russian Green, blotched with lighter
# patches: "see how spottie the camors are on some russian vechicles". The patches are the source sheet's dust
# and mud, tens of pixels across, coming through the plain paint as shading. A plain paint (and the arctic
# blotch camo, laid over the same sheets) keeps the source's broad light and shade and its finest lines - panel
# lines, rivets, bolts - and drops everything between, which is where weathering lives. The digital camos keep
# the full shading as before: the pattern carries it.
MID_DROP = [False]


def two_band_lum(a):
    h, w = a.shape[:2]
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    mf = m.astype(np.float32)

    def over_paint(x, radius):
        return blur_lum(x * mf, radius) / np.maximum(blur_lum(mf, radius), 1e-3)
    return np.clip(over_paint(lum0, w / 32) + (lum0 - over_paint(lum0, w / 512)), 0, 1)


def prepare(a, lp_set=None):
    """lp_set: the reference measured across the vehicle's WHOLE texture set. Without it each sheet is
    anchored on its own median, which lifts a dark gun or track sheet to the brightness of a hull."""
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    if hex_source():
        # a CSAT hex (the Qilin's arid, the Xi'an's green): four flat tones with bevelled cell edges, which neither
        # the tint grouping nor a brightness grouping cleared in four previews (2026-09-18). Its shading is taken
        # the way a plane's is - the broad light and shade alone - so the hex goes, and the panel lines with it;
        # the normal and specular maps still carry those. A plain source keeps its full detail as before.
        lum = plane_lum(a)
        STATS["hex source, broad shading"] += 1
    elif MID_DROP[0]:
        lum = two_band_lum(a)
    else:
        lum = depattern(a, lum0, m)
    lo, hi = np.percentile(lum[m], [25, 75])
    lp = float(np.median(lum[m & (lum >= lo) & (lum <= hi)]))
    return lum, p, m, (lp_set if lp_set else lp)


ARCTIC_WHITE = 0.90     # the paint's median; its highlights run up to 1.0


def arctic_white(a):
    """EU Arctic, 2026-09-25: "make a solid white for the eu artic ... texture the whole vechicle". Every painted
    pixel goes white - no pattern, no colour kept from the source (the keep_mask of solid() held the QAV
    Challenger's woodland greens as "markings", and the pure 1.0 target flattened every panel line away). The
    source's brightness is kept as shading, compressed to half so a dark sheet or baked shadow comes out a light
    grey, never black. Pure-black padding (not paint) stays; the wheels and glass are put back by make()."""
    lum = a @ W
    m = lum > 0.02
    if not m.any():
        return a
    med = float(np.median(lum[m]))
    r = lum / max(med, 1e-3)
    nl = np.clip(ARCTIC_WHITE * (1 + (r - 1) * 0.5), 0.55, 1.0)
    out = np.repeat(nl[..., None], 3, axis=-1).astype(np.float32)
    # a red marking - the medevac's medical panels, a tail light - is kept; no olive or sand is that saturated
    hh, chroma = hue(a)
    red = (chroma > 0.25) & ((hh < 20) | (hh > 340))
    return np.where((m & ~red)[..., None], out, a)


# sheets of running gear and loose parts: the HEMTT's mprimer (its spare tyre), the QAV Challenger's c2wheels1 (every
# road wheel and its rubber). No wheel mask covers them - the spare is no wheel selection, the mod model is unread.
ARCTIC_PARTS = re.compile(r"(?i)((^|[_-]|c\d)wheels?\d*([_-]|$))|mprimer|((^|[_-])details?([_-]|$))")


def arctic_parts(a):
    """EU Arctic on a parts sheet: only the PAINT goes white - the olive or sand pixels, found by hue as tint_parts()
    finds them. Rubber, bare metal and black are neutral and come through untouched, so a tyre stays a tyre."""
    # judged by REGION, on a blurred copy and by saturation: per pixel, the HEMTT's near-black olive reads as neutral
    # and the sheet came out speckled black and white (2026-09-25 preview); a saturation cut of 0.08 keeps the
    # tyres and leaves the paint to go white
    b = np.asarray(Image.fromarray((a * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.GaussianBlur(4)),
                   dtype=np.float32) / 255
    hh, chroma = hue(b)
    mx = b.max(-1)
    sel = (chroma / np.maximum(mx, 1e-3) > 0.08) & (hh > 25) & (hh < 175) & (mx > 0.03)
    if not sel.any():
        return a
    feather = np.asarray(Image.fromarray((sel * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(1.5)),
                         dtype=np.float32)[..., None] / 255
    lum = a @ W
    med = float(np.median(lum[sel]))
    nl = np.clip(ARCTIC_WHITE * (1 + (lum / max(med, 1e-3) - 1) * 0.5), 0.55, 1.0)
    return (a * (1 - feather) + np.repeat(nl[..., None], 3, axis=-1) * feather).astype(np.float32)


def solid(a, tgt, lp_set=None, tag=None):
    if tag in UNIFORM:
        lp_set = None                       # each sheet on its own paint, then levelled (level_solid)
    MID_DROP[0] = tag in UNIFORM
    lum, p, m, lp = prepare(a, lp_set)
    MID_DROP[0] = False
    lt = float(tgt @ W)
    k = float(np.clip(lt / max(lp, 1e-3), 0.6, 1.5))
    nl = np.clip(lt + (lum - lp) * k, 0, 1)
    new = np.clip(tgt[None, None, :] * (nl / lt)[..., None], 0, 1)
    keep = keep_mask(a, p, m)
    out = np.where(keep[..., None], a, new)
    if tag in UNIFORM:
        out = level_solid(out, m, keep, float(tgt @ W), DIGITAL_KEY[0])
    return out


SOLID_IQR = 0.06    # the spread the plain sheets already have (cage .008, hulls .03-.06); the dusty RUkhk sheets ran to .16


def level_solid(out, m, keep, lt, key):
    """A plain paint levelled by its flat panels, not its average. user, 2026-09-18: "the textures for russia are
    not consistante" - uniform_shade() brought every sheet's MEAN to the target, so a sheet heavy with dark parts
    had its panels pushed up and a clean one had them pushed down: the medians ran 0.114 to 0.189 for one paint.
    Here the median of the paint is put at the target, and then the sheet's contrast is capped: the source sheets
    differ as much in weathering as in level (interquartile range .008 to .165), and a dusty, mottled Tempest next
    to a clean Kamysh reads as two different paints. Deviations from the median are compressed to SOLID_IQR on a
    sheet that spreads wider; a sheet already within it is left alone."""
    paint = m & ~keep
    if not paint.any():
        return out
    lum = out @ W
    med = float(np.median(lum[paint]))
    gain = float(np.clip(lt / max(med, 1e-3), 0.7, 1.4))
    out = np.where(paint[..., None], np.clip(out * gain, 0, 1), out)
    lum = out @ W
    med = float(np.median(lum[paint]))
    q1, q3 = np.percentile(lum[paint], [25, 75])
    iqr = float(q3 - q1)
    f = 1.0
    if iqr > SOLID_IQR:
        f = SOLID_IQR / iqr
        want = med + (lum - med) * f
        ratio = np.where(lum > 1e-3, want / np.maximum(lum, 1e-3), 1.0)
        out = np.where(paint[..., None], np.clip(out * ratio[..., None], 0, 1), out)
        lum = out @ W
    SHADE[key] = (med, gain, float(lum[paint].mean()), float(np.median(lum[paint])), iqr, f)
    return out


def lay(a, cols, cls, w, blur=None, mode="add", lp_set=None, lum_in=None):
    """The pattern's colours over the texture's own shading and markings. "add" moves each colour's brightness
    by the texture's shading; "mul" scales it - the digital camos' dark browns and whites stay clean that way."""
    cmap = cols[cls]
    radius = max(1.5, w / 1024) if blur is None else blur
    if radius > 0:
        cmap = np.asarray(Image.fromarray((cmap * 255).astype(np.uint8)).filter(ImageFilter.GaussianBlur(radius)),
                          dtype=np.float32) / 255
    lum, p, m, lp = prepare(a, lp_set)
    keep = None
    if lum_in is not None:
        # a TOPSIDE plane: the Xi'an's green hex survived depattern() and showed through the digital as hex-shaped
        # tone and hex outlines (arid preview, 2026-09-18). Its shading comes from plane_lum() instead - the broad
        # light and shade, plus fine detail off a median-filtered copy that has lost the hex's thin cell lines -
        # and only a strongly coloured marking of another hue is kept: the hex's own greens were passing the
        # ordinary keep_mask at the islands' edges and showing as green fringes.
        lum = lum_in
        lo, hi = np.percentile(lum[m], [25, 75])
        lp = float(np.median(lum[m & (lum >= lo) & (lum <= hi)]))
        h_, c_ = hue(a)
        ph, _pc = hue(p[None, None, :])
        dh = np.abs(h_ - float(ph[0, 0]))
        keep = (~m) | ((c_ > 0.3) & (np.minimum(dh, 360 - dh) > 60))
    if mode == "mul":
        # A dark atlas - an engine bay, a greeble sheet, the LSV Mk II's detail pages - has a low median paint,
        # so its lighter pixels ran the multiplier up to the old flat 2.2 cap and the base green came out neon
        # (user, 2026-09-16: "jmfsb_China_O_T_LSV_02_* have weird shadding and shadows"). Shading below the knee
        # is untouched; above it the lift is compressed, so a highlight still reads as one without blowing out.
        r = lum / max(lp, 1e-3)
        r = np.where(r > 1.2, 1.2 + (r - 1.2) * 0.35, r)
        ratio = np.clip(r, 0.25, 1.7)
        new = np.clip(cmap * ratio[..., None], 0, 1)
    else:
        lc = np.maximum(cmap @ W, 1e-3)
        k = float(np.clip(float(np.median(cols @ W)) / max(lp, 1e-3), 0.6, 1.5))
        nl = np.clip(lc + (lum - lp) * k, 0, 1)
        new = np.clip(cmap * (nl / lc)[..., None], 0, 1)
    if keep is None:
        keep = keep_mask(a, p, m)
    return np.where(keep[..., None], a, new), (lum, m, lp, keep)


# user, 2026-09-18: "make sure all the vechicles are the same shade one should not be darker than the other".
# Two things made them differ. Every sheet of a vehicle was anchored on ONE brightness - the sheet with the most
# paint on it - so a hull measured against its own wheel sheet (the PGL-625E's is 87% tyre, so dark) came out
# bright, and one measured against a pale sheet came out dark. And the multiplier is a ratio to the paint's
# MEDIAN, so a sheet heavy with baked shadow averaged darker than one that is mostly flat panel. For these camos
# each sheet is anchored on its own paint (lp_set is ignored) and, after painting, its paint area is brought to
# the palette's share-weighted brightness by a gain - clamped, so a sheet that is mostly shadow is lifted, not
# blown out - and the gain and the level reached are recorded so the spread can be reported.
UNIFORM = {"cnwdl", "cnarid", "rusgreen", "russand", "rusarctic", "trarid", "trgreen", "euwdl", "eudes", "euarc"}
SHADE = {}
DIGITAL_KEY = [None]        # the sheet being made, for SHADE and the pink report
LEVEL_KEEP = {"cnarid": 1.15}   # the level a QAV Type 08 sheet keeps when its camo's base is lowered (digital())
# user, 2026-10-01: "the pla qav_625e's are darker than the rest of the camo's" - the woodland QAVs had no lift, so
# their own rvmats sat them darker than the faction's BI-model vehicles; they take the arid set's 15% (1.0 -> 1.15).
LEVEL_KEEP["cnwdl"] = 1.15


def wheel_paint(a, tag):
    """The source's own wheels, untouched (user, 2026-09-20: "wheels are not grey"). Kept as a function so the
    verifier and the callers have one place that decides what a wheel looks like."""
    return a


def _wheel_paint_neutral(a, tag):
    """The wheel faces in the camo's base colour as a plain paint - the source's shading kept as a brightness
    ratio, compressed above the paint level as lay() does - so the tyre stays black and the rim comes out a
    plain grey-green like the reference truck's. Keeping the source's own wheel paint put the PGL-625E's rims
    on in the QAV mod's olive scheme, whose worn rims and honeycomb treads are a chipped pink-grey (seen in
    the 2026-09-18 preview) - which is the pink the user has been seeing on that vehicle."""
    lum = a @ W
    # user, 2026-09-18: "you camoed the wheels on the russian green vechicles"; 2026-09-20: "you textured the fucking
    # tires in chin factions AGAIN NO FUCKING TEXTURING OF THE FUCKING TIRES". Every camo, the digital ones included:
    # the wheel is neutral - the source's shading with its colour removed, pulled down toward rubber, so a dusty
    # tyre comes out dark grey and a black one stays black; the rims sit at a dark grey. No camo colour on a wheel.
    g = np.clip(0.04 + (lum - 0.04) * 0.45, 0, 0.22)
    return np.repeat(g[..., None], 3, axis=-1).astype(np.float32)


def uniform_shade(out, a, m, keep, cols, share, key):
    target = float((cols @ W) @ share)
    paint = m & ~keep
    if not paint.any():
        return out
    lum = out @ W
    mean = float(lum[paint].mean())
    gain = float(np.clip(target / max(mean, 1e-3), 0.8, 1.25))
    out = np.where(paint[..., None], np.clip(out * gain, 0, 1), out)
    SHADE[key] = (mean, gain, float((out @ W)[paint].mean()), float(np.median((out @ W)[paint])))
    return out


def srgb(hexes):
    return np.array([[int(h[i:i + 2], 16) / 255 for i in (1, 3, 5)] for h in hexes], dtype=np.float32)


def base_level(cols, ref, factor, which=0):
    """The colours scaled together so one of them (the first) is as bright as the paint named - a texture sits
    darker than the paint looks in a photo."""
    lum = WHITE_L if ref == "White" else float(np.array(REF[ref], dtype=np.float32) @ W)
    return np.clip(cols * (lum * factor / float(cols[which] @ W)), 0, 1)


# EU camos, darkest first: the Aegis wdl's black bands, brown patches, grey-green base - and their desert and
# arctic counterparts. The lightest is brought to the paint named.
EU_COLOURS = {
    # LDF's own colours, clustered off the sheets that actually carry it - the Livonian van, the KamAZ and
    # the Mi-48 (user, 2026-09-16: "for the eu use ldf camos and make whats needed"). The art itself only
    # covers about 15 models, far too few to dress a faction, so the EU wears LDF by being MADE in these.
    # 2026-09-19, a Bundeswehr Leopard 2 photo, "wth camo is thaty on the eu its black its not a woodland green
    # holly fuck 3rd time i am telling y ou": the LDF grey-and-black above is gone. The EU woodland is the NATO
    # three-tone the photo shows - bronze green base, leather brown patches, tar black patches (RAL 6031 / 8027 /
    # 9021: #48573b / #5f4b34 / #22221f, about 50 / 32 / 18) - with the green at NATO Olive's own level. Made
    # throughout: no LDF copies, which were the grey.
    # 2026-09-19, "nato" with the NATO-standard MERDC sheet: the EU wears MERDC. Verdant: forest green and light
    # green as the two main colours (45% each), sand and black as thin accents (5% each). The last colour listed is
    # the base the level is set by; MERDC_MAIN names the second main colour.
    # 2026-09-19: Aegis's wdl sheets are copied where a model has one; the rest is MADE in those sheets' own colours,
    # measured off MBT_01_body_wdl_CO - green #393b32 at 0.227 (1.21 x NATO Olive), brown #2e2b25, black #202120 -
    # in patches of the size that sheet carries. Not MERDC: that was a misreading of "nato".
    "euwdl": (["#202120", "#2e2b25", "#393b32"], ("NATO Olive", 1.21)),
    # 2026-09-18 evening, "make an eu arid faction with this", a Bundeswehr Boxer photo: a sand base carrying big,
    # soft-edged olive-green and tan-brown blotches. The photo was not saved by the client, so these are by eye:
    # sand #c6b48f, olive #6f7553, tan-brown #a08a64, about 55 / 30 / 15. The base sits at NATO Sand (the China
    # arid came down to that level today and was called right). Listed darkest first like the others.
    # 2026-09-19, "the eu arid looks to much like turkey": Turkey is an ochre tan with thin dark-green bands, so the
    # EU arid goes the other way - a pale grey-beige base with LARGE dark-green and brown blotches, the Bundeswehr
    # look of the Boxer photo, and a shade paler (x1.05 NATO Sand against Turkey's x0.92).
    # MERDC desert (the sheet's red desert): earth red and sand as the mains, earth yellow and black as accents - a
    # brown-and-sand two-tone, nothing like Turkey's ochre with green bands (user, 2026-09-19: "looks to much like
    # turkey")
    # 2026-09-19, "add some black to the eu arid make it 3 color": sand base, olive blotches, black patches - the
    # Boxer's sand and olive with black for the third colour, darkest first
    "eudes": (["#1d1d1b", "#4e5a3d", "#cdc4a5"], ("NATO Sand", 1.05)),
    # 2026-09-19, "and artic for russia and the eu": white base, grey and charcoal patches in the woodland's layout
    # MERDC snow (trees): white and forest green as the mains, sand and black as accents
    # 2026-09-19, "why does eu artic have ... no camo": winter over woodland - Aegis's wdl sheets with the green tone
    # turned white (winter()), brown and black patches kept; a vehicle without a wdl sheet is made in that layout
    # 2026-09-20, "some eu artic has to much black make it 3 color grey white, and a darker gray no black", then
    # "grey white dark green please": white base, grey patches, dark green patches - the woodland's layout
    # 2026-09-21, "pur white for artic": plain white, no patches - handled by TARGET below, kept here so the
    # tag still resolves a colour reference
    "euarc": (["#e6e6e3", "#e6e6e3", "#e6e6e3"], ("White", 1.0)),
    "eutna": (["#1f2a1c", "#4a5a2e", "#6f7f3c"], ("NATO Olive", 1.3)),
}


def remap(a, tag):
    """The wdl pattern kept, its colours swapped: the paint's pixels grouped into three by tint and brightness (on
    a lightly blurred copy, so a panel line takes its patch's group), darkest to lightest, each given the new colour
    of its rank and keeping its own shading."""
    hexes, (ref, factor) = EU_COLOURS[tag]
    dst = base_level(srgb(hexes), ref, factor, which=-1)
    h, w = a.shape[:2]
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    rad = max(1.5, w / 256)
    b = np.asarray(Image.fromarray((a * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.GaussianBlur(rad)),
                   dtype=np.float32) / 255
    s = b.sum(-1) + 1e-4
    bl = b @ W
    feat = np.stack([b[..., 0] / s * 4, b[..., 1] / s * 4, bl * 3], -1)
    lo, hi = np.percentile(bl[m], [5, 97])
    px = feat[m & (bl > lo) & (bl < hi)]
    px = px[:: max(1, len(px) // 200000)]
    order = np.argsort(px[:, 2])
    c = px[order[[len(px) // 6, len(px) // 2, len(px) * 5 // 6]]]
    for _ in range(20):
        lab = ((px[:, None, :] - c[None]) ** 2).sum(-1).argmin(1)
        c = np.stack([px[lab == i].mean(0) if (lab == i).any() else c[i] for i in range(3)])
    rank = np.argsort(np.argsort(c[:, 2]))
    full = np.stack([((feat - c[i]) ** 2).sum(-1) for i in range(3)]).argmin(0)
    lc = np.array([float(np.median(lum0[m & (full == i)])) if (m & (full == i)).any() else 0.2 for i in range(3)])
    # capped tight: darker detail grouped with the black bands turned into bright halos at 1.8 (preview)
    ratio = np.clip(lum0 / np.maximum(lc[full], 1e-3), 0.45, 1.25)
    new = np.clip(dst[rank[full]] * ratio[..., None], 0, 1)
    return np.where(keep_mask(a, p, m)[..., None], a, new)


def merdc(a, seed, tag):
    """MERDC: the base and a second main colour in large irregular blotches, about 45% each, with two thin accent
    streaks of about 5% each (sand and black on the verdant and snow schemes, earth yellow and black on the desert)."""
    hexes, (ref, factor) = EU_COLOURS[tag]
    cols = base_level(srgb(hexes)[::-1].copy(), ref, factor)                 # base, main 2, accent 1, black
    h, w = a.shape[:2]
    rng = np.random.default_rng(seed)
    f1 = noise(rng, h, w, 3)
    main2 = f1 > np.quantile(f1, 0.55)                                      # the second main colour, 45%
    f2, f3 = noise(rng, h, w, 5), noise(rng, h, w, 5)
    g1, g2 = noise(rng, h, w, 4), noise(rng, h, w, 4)                       # gates: the contours broken into streaks
    d2 = np.abs(f2 - np.median(f2))
    acc1 = (d2 < np.quantile(d2, 0.10)) & (g1 > np.median(g1))              # short streaks: sand / earth yellow, ~5%
    d3 = np.abs(f3 - np.median(f3))
    acc2 = (d3 < np.quantile(d3, 0.10)) & (g2 > np.median(g2)) & ~acc1      # short streaks: black, ~5%
    cls = np.where(acc2, 3, np.where(acc1, 2, np.where(main2, 1, 0)))
    MID_DROP[0] = True
    out, (lum, m, lp, keep) = lay(a, cols, cls, w, blur=max(2.0, w / 400), mode="mul")
    MID_DROP[0] = False
    return uniform_shade(out, a, m, keep, cols, np.array([0.45, 0.45, 0.05, 0.05], dtype=np.float32), DIGITAL_KEY[0])


# darkest first: black accent, second accent, second main, base
MERDC_SET = {
    # Sampled off the NATO MERDC sheet the user supplied (2026-09-22), then scaled DOWN: the sheet's numbers come
    # from a lit render, so a texture has to sit below them or it renders pale (user: "way to bright"). Listed
    # accent-first; the code reverses, so the LAST entry is the base and takes the widest coverage. The sheet's
    # dominant tone is its MIDDLE one - having the lightest dominant is what made these read bright.
    # verdant: mid green base, light green, dark olive, black
    "euwdl": ["#0f0f0c", "#232219", "#3a3c2c", "#2e2f22"],
    # snow: mid olive base, white, dark olive, grey. The white stays white; the rest is olive, not tan, as asked.
    "euarc": ["#726f66", "#292b20", "#cfcdc6", "#404332"],
    # red desert: mid brown base, dark brown, sand, black
    "eudes": ["#14120f", "#69614b", "#342c21", "#4a4032"],
}
def merdc_set(a, seed, tag):
    """The MERDC pattern in a fixed palette: two main colours in large blotches, a third colour and black."""
    cols = srgb(MERDC_SET[tag])[::-1].copy()                 # base, main 2, accent, black
    h, w = a.shape[:2]
    rng = np.random.default_rng(seed)
    # MERDC is blotches, not streaks: three irregular fields thresholded on their own noise, largest first
    f1, f2, f3 = noise(rng, h, w, 3), noise(rng, h, w, 4), noise(rng, h, w, 5)
    main2 = f1 > np.quantile(f1, 0.58)                       # about 42 per cent
    third = (f2 > np.quantile(f2, 0.82)) & ~main2            # about 15 per cent
    black = (f3 > np.quantile(f3, 0.93)) & ~third            # about 7 per cent, over either main colour
    cls = np.where(black, 3, np.where(third, 2, np.where(main2, 1, 0)))
    soft = np.asarray(Image.fromarray((cls * 80).astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(max(1.0, w / 1200))), dtype=np.float32) / 80
    lum0 = a @ W
    p_, m = paint_of(a, lum0)
    keep = strict_keep(a, p_, m)
    lp = float(np.median(lum0[m])) if m.any() else 0.25
    # a light source sheet must not lift the palette: the ceiling is tight
    ratio = np.clip(lum0 / max(lp, 1e-3), 0.6, 1.12)[..., None]
    lo = np.clip(np.floor(soft).astype(np.int64), 0, 3)
    hi = np.clip(lo + 1, 0, 3)
    t = (soft - lo)[..., None]
    base = cols[lo] * (1 - t) + cols[hi] * t                 # soft edges between the bands
    new = np.clip(base * ratio, 0, 1)
    return np.where(keep[..., None] | (~m)[..., None], a, new)


def winter(a, w):
    """Aegis's wdl sheet in winter: its three tones found (black, brown, green), the green - the base - turned white
    at the game's clean-white level; brown and black patches stay, every pixel keeping its own shading."""
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    keep = strict_keep(a, p, m)
    full, col, tl = tone_split(a, m & ~keep, 3, w)                      # darkest first: black, brown, green
    white = np.array(colorsys.hls_to_rgb(40 / 360, WHITE_L, 0.03), dtype=np.float32)
    cols = np.stack([col[0], col[1], white])
    ratio = np.clip(lum0 / np.maximum(tl[full], 1e-3), 0.45, 1.3)
    new = np.clip(cols[full] * ratio[..., None], 0, 1)
    return np.where(keep[..., None], a, new)


WDL_REF = os.path.join(JMFSB, "addons", "faction_eudf", "data", "camo", "aegis", "MRAP_01", "Data", "MRAP_01_base_wdl_CO.paa")
WDL_REF_SRC = r"D:\Git\A3_Aegis_Public_Releases\A3_Aegis\soft_f_aegis\MRAP_01\Data\MRAP_01_base_wdl_CO.paa"
_wdl_ref = []


_wdl_refs = {}
WDL_FAMILY = {}          # family key (e.g. "apc_tracked_01") -> a wdl sheet of that family in the release, filled by main()


def wdl_reference(src=None):
    """(tone map, tone colours darkest first, tone brightnesses, paint mean) of the wdl sheet that stands for this
    source's family - the family's own Aegis wdl sheet when the release has one, else Aegis's wdl Hunter sheet."""
    ref = WDL_REF_SRC if os.path.exists(WDL_REF_SRC) else WDL_REF
    if src:
        stem = re.sub(r"(?i)_co$", "", re.sub(r"\.\w+$", "", str(src).replace("/", "\\").split("\\")[-1])).lower()
        m_ = re.match(r"^([a-z]+_\d+)", stem)
        fam = m_.group(1) if m_ else stem.split("_")[0]
        ref = WDL_FAMILY.get(fam, ref)
    if ref in _wdl_refs:
        return _wdl_refs[ref]
    png = PR.to_png(ref, "wdl_reference_" + hashlib.sha1(ref.lower().encode()).hexdigest()[:10])
    a = np.asarray(Image.open(png).convert("RGB"), dtype=np.float32) / 255
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    keep = strict_keep(a, p, m)
    full, col, tl = tone_split(a, m & ~keep, 3, a.shape[1])
    full = np.where(m & ~keep, full, -1)
    _wdl_refs[ref] = (full, col, tl, float(lum0[m].mean()))
    return _wdl_refs[ref]


def wdl_transfer(a, seed, tag):
    """The Aegis wdl pattern and colours on a made sheet. The reference's tone map is scaled to the sheet and shifted
    by the seed, so two vehicles do not share one layout; the padding of the reference (no tone) takes the base."""
    full_ref, col, tl, ref_mean = wdl_reference(SRC_NAME[0] if tag == "euwdl" else None)
    h, w = a.shape[:2]
    rng = np.random.default_rng(seed)
    src = np.asarray(Image.fromarray((full_ref + 1).astype(np.uint8)).resize((w, h), Image.NEAREST)).astype(np.int64) - 1
    src = np.roll(src, (int(rng.integers(0, h)), int(rng.integers(0, w))), (0, 1))
    cls = np.where(src < 0, 2, src)                                         # the base is the lightest, index 2
    if tag == "euarc":
        hexes, (ref, factor) = EU_COLOURS[tag]
        cols = base_level(srgb(hexes), ref, factor, which=-1)              # white base, grey, dark green
    else:
        cols = col                                                          # the wdl's own colours, at their own level
    MID_DROP[0] = True
    out, (lum, m, lp, keep) = lay(a, cols, cls, w, blur=max(1.5, w / 1000), mode="mul")
    MID_DROP[0] = False
    share = np.array([float((cls == i).mean()) for i in range(3)], dtype=np.float32)
    out = uniform_shade(out, a, m, keep, cols, share / max(share.sum(), 1e-6), DIGITAL_KEY[0])
    if tag == "euwdl":
        # at the reference sheet's brightness: the made sheet sits beside copied Aegis sheets on the same vehicle
        cur = float((out @ W)[m & ~keep].mean()) if (m & ~keep).any() else ref_mean
        gain = float(np.clip(ref_mean / max(cur, 1e-3), 0.7, 1.6))
        out = np.where((m & ~keep)[..., None], np.clip(out * gain, 0, 1), out)
    return out


def eu_blotch(a, seed, tag):
    if tag in ("euwdl", "euarc"):
        return wdl_transfer(a, seed, tag)
    if tag == "eudes":
        hexes, (ref, factor) = EU_COLOURS[tag]
        cols = base_level(srgb(hexes)[::-1].copy(), ref, factor)             # sand, olive, black
        h, w = a.shape[:2]
        rng = np.random.default_rng(seed)
        f1, f2 = noise(rng, h, w, 3), noise(rng, h, w, 4)
        olive = f1 > np.quantile(f1, 0.68)                                  # olive blotches, 32%
        black = (f2 > np.quantile(f2, 0.88)) & ~olive                       # black patches, ~12%
        MID_DROP[0] = True
        out, (lum, m, lp, keep) = lay(a, cols, np.where(black, 2, np.where(olive, 1, 0)), w, blur=max(2.0, w / 300), mode="mul")
        MID_DROP[0] = False
        return uniform_shade(out, a, m, keep, cols, np.array([0.56, 0.32, 0.12], dtype=np.float32), DIGITAL_KEY[0])
    """For a vehicle with no wdl: the EU colours as the wdl lays them - a base, brown patches, long black bands.
    The arid (eudes) is the Boxer's: soft olive and tan-brown blotches over sand, no bands."""
    hexes, (ref, factor) = EU_COLOURS[tag]
    cols = base_level(srgb(hexes)[::-1].copy(), ref, factor)                 # base first
    h, w = a.shape[:2]
    rng = np.random.default_rng(seed)
    if tag == "eudes":
        f1, f2 = noise(rng, h, w, 3), noise(rng, h, w, 3)                    # bigger blotches than the woodland's
        green = f1 > np.quantile(f1, 0.70)                                  # olive, 30%
        brown = (f2 > np.quantile(f2, 0.85)) & ~green                       # tan-brown, 15%
        cls = np.where(green, 2, np.where(brown, 1, 0))
        MID_DROP[0] = True
        out, (lum, m, lp, keep) = lay(a, cols, cls, w, blur=max(2.0, w / 300), mode="mul")
        MID_DROP[0] = False
        return uniform_shade(out, a, m, keep, cols, np.array([0.55, 0.15, 0.30], dtype=np.float32), DIGITAL_KEY[0])
    # the woodland as Aegis's wdl sheets lay it: brown and black patches over the dark green, a few hull-lengths
    # across, soft edged
    f1, f2 = noise(rng, h, w, 5), noise(rng, h, w, 5)
    brown = f1 > np.quantile(f1, 0.70)                                      # brown, 30%
    black = (f2 > np.quantile(f2, 0.75)) & ~brown                           # black-green, ~22%
    MID_DROP[0] = True
    out, (lum, m, lp, keep) = lay(a, cols, np.where(black, 2, np.where(brown, 1, 0)), w, blur=max(2.0, w / 400), mode="mul")
    MID_DROP[0] = False
    return uniform_shade(out, a, m, keep, cols, np.array([0.48, 0.30, 0.22], dtype=np.float32), DIGITAL_KEY[0])


def noise(rng, h, w, n, octaves=((1, 0.6), (2, 0.3), (4, 0.1))):
    out = np.zeros((h, w), dtype=np.float32)
    for scale, wgt in octaves:
        f = (rng.random((n * scale, n * scale)) * 255).astype(np.uint8)
        out += wgt * np.asarray(Image.fromarray(f).resize((w, h), Image.BICUBIC), dtype=np.float32) / 255
    return out


def arctic(a, seed, lp_set=None):
    """Russian Arctic: white at the game's clean white paint, grey and charcoal at the ratios e22 RAF's alpine camo net
    has to its white (#b8b9ba, #898885, #363634 - 0.74 and 0.29; 2026-10-06, "white, in e22's alpine greys"), near
    neutral as its are. The photo's pattern - white ground, grey blotches, a charcoal band - is kept."""
    l = WHITE_L
    cols = np.array([colorsys.hls_to_rgb(210 / 360, l, 0.02), colorsys.hls_to_rgb(45 / 360, l * 0.74, 0.02),
                     colorsys.hls_to_rgb(60 / 360, l * 0.29, 0.02)], dtype=np.float32)
    share = [0.52, 0.33, 0.15]
    h, w = a.shape[:2]
    rng = np.random.default_rng(seed)
    f1 = noise(rng, h, w, 5, ((1, 0.6), (2.2, 0.3), (4.6, 0.1))) if False else \
        noise(rng, h, w, 5, ((1, 0.6), (2, 0.3), (4, 0.1)))
    grey = f1 < np.quantile(f1, share[1] + share[2])
    fd = np.roll(f1, (h // 36, w // 30), (0, 1))                         # the dark band, off to one side
    dark = grey & (fd < np.quantile(fd, share[2] * 1.7))
    MID_DROP[0] = True
    out, (lum, m, lp, keep) = lay(a, cols, np.where(dark, 2, np.where(grey, 1, 0)), w, lp_set=None)
    MID_DROP[0] = False
    return uniform_shade(out, a, m, keep, cols, np.array(share, dtype=np.float32), DIGITAL_KEY[0])


# Digital camos, from the user's images (2026-09-14), colours matched by eye:
#   tag: (colours, base first; their shares of the area; block size as a part of the texture's width; blob size
#         in blocks; how ragged the blob edges are; the paint the base colour's brightness is brought to, and by
#         how much - the desert and arid bases are paler sands than NATO's)
DIGITAL = {
    # woodland: the user's example, then "less pink", "light brown not pink", and a ZBL-09 photo ("see brown not
    # pink", 2026-09-15) - mid green, dark green, light yellow-green, earth brown. What made it read pink was red
    # ahead of yellow: the brown wants its green-to-blue gap wider than its red-to-green one (#8a7048 is +26/+42;
    # the light tan before it was +40/+48 and the one in the shipped textures +30/+11, salmon in sunlight)
    # The light green was the bright block: after base_level it sat at 0.272 against a 0.206 base, +32%, and a
    # hull carrying 26% of it read far brighter than the 625E, whose texture barely shows any (user, 2026-09-16:
    # "pla is still top bright only one vechicel is the corect share"). #79843f lands at 0.223, +8%.
    # 2026-09-18, "lets try to retexture china again", "no fucking pink camo", and a rendered truck in PLA digital
    # woodland as "a better example": a grey-green base, a light sage, a dark grey-green and a muted taupe brown,
    # clustered off the truck's box side by tint (medians #5e6554 / #7c8268 / #454946 / #61594e, shares .32 / .30
    # / .25 / .14). The brown is the pink risk: it is kept as taupe with its green-to-blue gap wider than its
    # red-to-green one (#6a5c44 is +14/+24; the truck's own median brown is #63594e, +10/+11, and a taupe that
    # neutral reads warmer than it is beside grey-greens), so no shading multiplier can push it to salmon - and pink_check()
    # below measures every made sheet for pink it did not inherit from its source, and the run reports any.
    # Blocks finer than before (the truck's box carries about 65 across its length), blobs a little smaller.
    # The base sits AT the game's NATO Olive: the palette's share-weighted brightness is 1.01 x the base, so a
    # vehicle in this camo reads as bright as a vanilla olive one - and every vehicle the same (uniform_shade).
    "cnwdl": (["#5e6554", "#7c8268", "#434a40", "#6a5c44"], [0.32, 0.30, 0.24, 0.14], 1 / 100, 5.0, 0.25,
              ("NATO Olive", 1.0)),
    # arid, 2026-09-18 "arid example": a parade photo of ZTQ-15s in the PLA arid digital - a warm tan base, a cream
    # sand, a khaki, a grey-brown, and a few olive-green blocks. The image itself was not saved to disk by the
    # client, so these are by eye, not clustered: tan #c9b58e, cream #e4dcc3, khaki #a6916a, grey-brown #7a7266
    # (+8/+12, a taupe, hue 36 - nowhere near pink), olive #8c9955. Its blocks are about twice the woodland's
    # (some 27 along a 7 m hull against the truck's 65 along 5 m), so the cell is 1/50 of the sheet and the blobs
    # a little tighter. The base sits a little above the game's NATO Sand (x1.15) - the PLA arid is a paler sand
    # than NATO's - and uniform_shade holds every vehicle to the same mean anyway.
    # 2026-09-18 evening, "the china arid needs to be a bit darker": the base comes down from 1.15 x NATO Sand to
    # NATO Sand itself, about 13% darker across the set (every sheet is levelled to the palette, so this is the
    # one knob). If it wants more, 0.9 is the next step.
    "cnarid": (["#c9b58e", "#e4dcc3", "#a6916a", "#7a7266", "#8c9955"], [0.40, 0.24, 0.18, 0.12, 0.06], 1 / 50,
               4.0, 0.25, ("NATO Sand", 1.0)),
    "cndes": (["#d9c7a0", "#b99a6c", "#7e7465", "#e8dcc2", "#5f7a3c", "#5e594b"],
              [0.40, 0.22, 0.14, 0.12, 0.06, 0.06], 1 / 60, 3.5, 0.2, ("NATO Sand", 1.3)),  # the ZTZ-99A parade photo
    "cnarctic": (["#e6e7e6", "#b5b6b5", "#56585b", "#a07d52"], [0.45, 0.22, 0.19, 0.14], 1 / 90, 3.0, 0.25,
                 ("White", 1.0)),                                           # the ZTZ-99 snow photo
}


def plane_lum(a):
    """A plane skin's shading as plane_paint() keeps it: broad light and shade over the paint alone, plus the
    finest detail, with everything between - a hex or digital camo of any colour - dropped."""
    h, w = a.shape[:2]
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    mf = m.astype(np.float32)

    def over_paint(x, radius):
        return blur_lum(x * mf, radius) / np.maximum(blur_lum(mf, radius), 1e-3)
    # Broad shading only. The Xi'an's hex is painted with bevelled cell edges and cell-to-cell tone, and both a
    # median filter and a w/24 blur left it showing through the digital (two previews, 2026-09-18). At w/10 the
    # cells average out; the panel lines go with them, which on a plane the normal and specular maps carry anyway.
    return np.clip(over_paint(lum0, w / 10), 0, 1)


def digital(a, seed, tag, lp_set=None, flat=False):
    """Blobs of blocks: each colour past the first takes its share of a coarse grid where a smooth noise, roughened
    cell by cell, is highest; the grid is then scaled up with hard edges."""
    hexes, share, cell_frac, blob, ragged, (ref, factor) = DIGITAL[tag]
    # user, 2026-09-18, with "the china arid needs to be a bit darker": "the qav type 8s are good color and shade
    # wise". The QAV Type 08s wear their own rvmats and sit darker in game than the BI models at the same sheet
    # level, so they keep the level the set had (1.15) while every other arid vehicle comes down to NATO Sand.
    if "qav" in (SRC_NAME[0] or "") and tag in LEVEL_KEEP:
        factor = LEVEL_KEEP[tag]
    share = np.array(share, dtype=np.float32)
    cols = base_level(srgb(hexes), ref, factor)
    h, w = a.shape[:2]
    cell = max(2, int(round(w * cell_frac)))
    gh, gw = -(-h // cell), -(-w // cell)
    rng = np.random.default_rng(seed)
    grid = np.zeros((gh, gw), dtype=np.uint8)
    free = np.ones((gh, gw), dtype=bool)
    for i in range(1, len(share)):
        f = noise(rng, gh, gw, max(2, int(round(gw / blob)))) + rng.random((gh, gw)).astype(np.float32) * ragged
        want = share[i] * gh * gw
        sel = free.copy() if free.sum() <= want else free & (f >= np.quantile(f[free], 1 - want / free.sum()))
        grid[sel] = i
        free &= ~sel
    cls = np.asarray(Image.fromarray(grid).resize((gw * cell, gh * cell), Image.NEAREST))[:h, :w]
    lum_in = plane_lum(a) if flat else None
    if tag in UNIFORM:
        out, (lum, m, lp, keep) = lay(a, cols, cls, w, blur=0, mode="mul", lp_set=None, lum_in=lum_in)
        return uniform_shade(out, a, m, keep, cols, share, DIGITAL_KEY[0])
    return lay(a, cols, cls, w, blur=0, mode="mul", lp_set=lp_set, lum_in=lum_in)[0]


# Turkish Arid, from the user's Leopard 2 photo: ochre tan, long dark green wavy bands
# The ochre was too red to read as sand (user, 2026-09-16: "turketr is way to orange needs to be more snad in
# color"): #c89f68 ran R-G +41 against G-B +55. #c2ab80 is +23/+43 - the yellow kept, the orange taken out.
# Measured, not guessed: at NATO Sand x1.2 the made textures came out at 0.299 median luminance against
# China's 0.192 - 56% brighter, which is what "way to much orange"/"pumkin orange" was. x0.92 lands near 0.23.
# The tan loses more red too: #c2ab80 ran R-G +23, #baac86 runs +14.
TURKISH = (["#baac86", "#3f4a36"], 0.14, ("NATO Sand", 0.92))     # bands widened after the preview
TURKISH_GREEN = (["#5a6644", "#2c3626"], 0.14, ("NATO Olive", 1.0))   # the same bands in greens, for the menu


def flag_image(width):
    """The Turkish flag at width x width/1.5, drawn eight times larger and scaled down. By the flag law's
    construction (G the height): crescent circle centre 1/2 G from the hoist, diameter 1/2 G; the inner circle
    1/16 G further, diameter 2/5 G; the star's circle, diameter 1/4 G, 1/3 G past the crescent's centre."""
    s = 8
    fh = max(8, int(round(width / 1.5)))
    G = fh * s
    red = (227, 10, 23)
    im = Image.new("RGB", (int(width * s), G), red)
    d = ImageDraw.Draw(im)
    cx = cy = 0.5 * G
    r = 0.25 * G
    d.ellipse([cx - r, cy - r, cx + r, cy + r], fill=(255, 255, 255))
    ci, ri = cx + G / 16, 0.2 * G
    d.ellipse([ci - ri, cy - ri, ci + ri, cy + ri], fill=red)
    sx, R = cx + G / 3 + G / 8, G / 8
    pts = []
    for k in range(10):
        ang = np.pi + k * np.pi / 5                                          # a point toward the crescent
        rad = R if k % 2 == 0 else R * 0.382
        pts.append((sx + rad * np.cos(ang), cy + rad * np.sin(ang)))
    d.polygon(pts, fill=(255, 255, 255))
    return np.asarray(im.resize((int(width), fh), Image.LANCZOS), dtype=np.float32) / 255


FLAG_BOXES = []     # (y0, y1, x0, x1) of the flags placed on the sheet being made; pink_check() looks past them


def place_flags(out, lum, m, lp, count=2):
    FLAG_BOXES.clear()
    """Flags on the flattest stretches of paint: sliding a flag-sized window (with a margin) over the texture at
    256 px, where it lies wholly on paint and its brightness varies least, and the second far from the first."""
    h, w = out.shape[:2]
    fw = max(24, int(w * 0.045))
    flag = flag_image(fw)
    fh = flag.shape[0]
    S = 256
    sc = w / S
    small = np.asarray(Image.fromarray((lum * 255).astype(np.uint8)).resize((S, int(round(h / sc))), Image.BOX),
                       dtype=np.float32) / 255
    ms = np.asarray(Image.fromarray((m * 255).astype(np.uint8)).resize((S, small.shape[0]), Image.BOX),
                    dtype=np.float32) / 255 > 0.99
    ww, wh = max(3, int(np.ceil(fw * 1.6 / sc))), max(3, int(np.ceil(fh * 1.6 / sc)))

    def box(x):
        c = np.pad(np.cumsum(np.cumsum(x, 0), 1), ((1, 0), (1, 0)))
        return c[wh:, ww:] - c[:-wh, ww:] - c[wh:, :-ww] + c[:-wh, :-ww]

    area = ww * wh
    cover = box(ms.astype(np.float32)) / area
    mean = box(small) / area
    std = np.sqrt(np.maximum(box(small ** 2) / area - mean ** 2, 0))
    score = np.where(cover > 0.999, std + 0.3 * np.abs(mean - lp), np.inf)
    placed = 0
    for _ in range(count):
        if not np.isfinite(score).any():
            break
        y, x = np.unravel_index(np.argmin(score), score.shape)
        yy, xx = np.ogrid[:score.shape[0], :score.shape[1]]
        score[(yy - y) ** 2 + (xx - x) ** 2 < (S * 0.25) ** 2] = np.inf
        x0 = int(x * sc + (ww * sc - fw) / 2)
        y0 = int(y * sc + (wh * sc - fh) / 2)
        if x0 < 0 or y0 < 0 or x0 + fw > w or y0 + fh > h:
            continue
        shading = np.clip(lum[y0:y0 + fh, x0:x0 + fw] / max(lp, 1e-3), 0.75, 1.15)[..., None]
        out[y0:y0 + fh, x0:x0 + fw] = np.clip(flag * (WHITE_L / 1.0) * shading, 0, 1)
        FLAG_BOXES.append((y0, y0 + fh, x0, x0 + fw))
        placed += 1
    STATS["flags"] += placed
    return out


def turkish(a, seed, flag, tag="trarid"):
    hexes, band, (ref, factor) = TURKISH_GREEN if tag == "trgreen" else TURKISH
    cols = base_level(srgb(hexes), ref, factor)
    h, w = a.shape[:2]
    rng = np.random.default_rng(seed)
    f = noise(rng, h, w, 3, ((1, 0.8), (2, 0.2)))
    d = np.abs(f - np.median(f))
    cls = (d < np.quantile(d, band)).astype(np.uint8)                        # the contour of a smooth field: long wavy bands
    MID_DROP[0] = True
    out, (lum, m, lp, keep) = lay(a, cols, cls, w, blur=max(1.0, w / 1500), mode="mul")
    MID_DROP[0] = False
    out = uniform_shade(out, a, m, keep, cols, np.array([1 - band, band], dtype=np.float32), DIGITAL_KEY[0])
    return place_flags(out, lum, m, lp) if flag else out


# Planes (user: "on the air craft look up air craft camos and make suire the underside is light sky color", "by
# aircraft i mean planes"): two upper greys as soft disruptive patches over a light underside, after the air forces'
# own schemes - Russia's VKS blue-greys over light blue (Su-35/Su-34), the PLAAF's low-visibility greys over light
# grey, the Turkish F-16's FS 36270 / FS 36118 over FS 36375 Light JMSB Gray, the Luftwaffe Eurofighter's FS 35237
# Blue Grey for the EU. The underside is where the model's own faces point down (plane_undersides.py); colours are
# scaled together so the underside sits at SKY_L.
PLANE = {    # tag: (upper colours, the second's share, underside colour)
    "vks": (["#8a9aa6", "#4f5a66"], 0.45, "#a9c3d6"),
    "plaaf": (["#7e878d", "#5a6268"], 0.40, "#b7c0c6"),
    "tuaf": (["#84898c", "#4d5154"], 0.45, "#a8adb0"),
    "euaf": (["#5a6f80", "#848a8e"], 0.30, "#a8adb0"),
}
SKY_L = 0.52        # 0.45 barely stood out from the lighter upper grey (preview)
# user, 2026-09-18, naming jmfsb_China_O_T_VTOL_02_infantry_dynamicLoadout_F and _vehicle_: "theses you can camo the
# top and the sides leave the underside the color it is". A plane matching this wears the FACTION camo on its
# upper faces and keeps, where its faces point down, the light underside the air-force scheme gave it (make()
# blends plane_paint's underside back in over the digital by the underside mask).
TOPSIDE = re.compile(r"(?i)VTOL_02")
UNDER = [None]      # the addon's air-force tag, for the underside blend
# Empty: no faction paints its aircraft any more (user, 2026-09-21). The air-force schemes are still defined
# below, so naming a faction here again is all it takes to bring one back.
PLANE_TAGS = {}
# faction_eudf is not here: "for air craft the default colors are fine" (user, 2026-09-21)
# The camos some faction actually wears. Anything else is offered in the appearance menu only, and ships
# at half size - the Chinese Arid and Arctic sets, which no faction fields.
DEFAULT_TAGS = {t for t, _p, _o in JOBS.values()} | set(PLANE_TAGS.values())
PLANE_PLAIN = ["grey", "blue", "bluestar", "green", "olive", "khaki", "sand", "desert", "brown", "tan", "blufor", "black",
               "russia"]
MASK_INDEX = os.path.join(SP, "planes", "masks", "index.json")
MASKS = json.load(open(MASK_INDEX)) if os.path.exists(MASK_INDEX) else {}
PLANES_ONLY = "--planes" in sys.argv
REMAKE_TAGS = set(sys.argv[sys.argv.index("--remake-tags") + 1].split(",")) if "--remake-tags" in sys.argv else set()
REMAKE_SINCE = os.path.getmtime(__file__)


def blur_lum(x, radius):
    return np.asarray(Image.fromarray((np.clip(x, 0, 1) * 255 + 0.5).astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(max(0.5, radius))), dtype=np.float32) / 255


def plane_paint(a, seed, tag, mask):
    """An aircraft skin is plain panels and fine lines, so the texture's shading is kept at the two ends only -
    broad light and shade (blurred over about a 48th of the texture) and the finest detail (panel lines, rivets) -
    and anything between, a hex or digital camo of any colour included, drops out (the Xi'an's grey hex stayed
    through the tint grouping, which a grey-on-grey pattern gives nothing to group by). Then the two upper greys as
    soft patches and, where the model's faces point down, the light underside colour."""
    uppers, second, sky = PLANE[tag]
    cols = srgb(uppers + [sky])
    cols = np.clip(cols * (SKY_L / float(cols[2] @ W)), 0, 1)
    h, w = a.shape[:2]
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    # blurred over the paint alone (blur of lum*mask over blur of mask): the atlas's dark padding bled into the
    # islands' edges as dark rims, which would show as seams on the model (preview)
    mf = m.astype(np.float32)

    def over_paint(radius):
        return blur_lum(lum0 * mf, radius) / np.maximum(blur_lum(mf, radius), 1e-3)
    lum = np.clip(over_paint(w / 48) + (lum0 - over_paint(w / 512)), 0, 1)
    lo, hi = np.percentile(lum[m], [25, 75])
    lp = float(np.median(lum[m & (lum >= lo) & (lum <= hi)]))
    rng = np.random.default_rng(seed)
    f = noise(rng, h, w, 4, ((1, 0.7), (2, 0.3)))
    cls = (f < np.quantile(f, second)).astype(np.uint8)
    cmap = np.asarray(Image.fromarray((cols[:2][cls] * 255).astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(max(1.5, w / 400))), dtype=np.float32) / 255
    ratio = np.clip(lum / max(lp, 1e-3), 0.35, 1.8)[..., None]
    out = np.clip(cmap * ratio, 0, 1)
    if mask and os.path.exists(mask):
        under = np.asarray(Image.open(mask).convert("L").resize((w, h), Image.BILINEAR), dtype=np.float32)[..., None] / 255
        sky_px = np.clip(cols[2] * np.clip(ratio, 0.5, 1.5), 0, 1)
        out = out * (1 - under) + sky_px * under
    # nothing of the source's markings is kept on a plane: they are national insignia, and the Turkish F-35 made
    # from the desert F-35 flew with Israeli roundels (user, 2026-09-19, and again 2026-09-20: the roundel's white and
    # blue are "not paint", so keeping every non-paint pixel kept the roundel). Only the atlas padding stays: the
    # near-black background between the islands.
    pad = (~m) & (lum0 < 0.06) & ((a.max(-1) - a.min(-1)) < 0.05)
    return np.where(pad[..., None], a, out)


def pink_mask(rgb):
    """Pixels that read pink: hue past 300 or under 20, with enough chroma to show and not near black."""
    h, c = hue(rgb)
    return ((h >= 300) | (h < 20)) & (c > 0.12) & (rgb.max(-1) > 0.15)


PINK = []


def pink_check(out, a, rel):
    """Pink the made sheet has that its source did not (a source's red stars and lamps are kept on purpose).
    user, 2026-09-18: "no fucking pink camo", "review what you do to make sure there is no pink"."""
    got = pink_mask(out) & ~pink_mask(a)
    for y0, y1, x0, x1 in FLAG_BOXES:          # the Turkish flag's red is meant
        got[y0:y1, x0:x1] = False
    FLAG_BOXES.clear()
    frac = float(got.mean())
    STATS["pink checked"] += 1
    if frac > 0.0002:                 # 0.02% of a sheet - a few hundred pixels at 2048, a blob, not a seam
        PINK.append((rel, frac))
        print("   ! PINK: %.3f%% of %s" % (100 * frac, rel))
    return frac


# China's squarify is OFF (user, 2026-09-19: "un do what you did to china the vechicles are bright fucking orange ...
# put them all back"): the CSAT arid hex's tan came out orange on the models, and only the models with a hex sheet
# got it. Both China factions are back on the digital palettes made before, on every vehicle.
MODIFY = {
          "trarid": ("eaf_arid", ("ldf", "eaf"))}
# EAF arid: the plain EAF_arid sheet's sand as the base, measured off MBT_03_ext02_EAF_arid_CO (0.415), with a darker
# sand and an olive-brown for the splinter's other two tones, darkest first
EAF_ARID = (["#3e3a2c", "#5a5140", "#736957"], 0.415)
# Turkish Tropical: darkest first - the EAF dark, a woodland green, the EAF sand; and its own base level, a third
# below the arid sheet's, so the tropical faction is not the brighter of the two (user: one must not be lighter)
# the arid's own tones with a green: dark, green, sand - darkest first. The green is the one that spreads.
TURKISH_TROPICAL = (["#3e3a2c", "#414a35", "#736957"], 0.30)


def tone_split(a, m, K, w):
    """The paint grouped into K tones by tint and brightness on a lightly blurred copy (a panel line takes its cell's
    tone): (label per pixel, median colour per tone, median brightness per tone), tones ordered darkest first."""
    rad = max(1.5, w / 1024)
    b = np.asarray(Image.fromarray((a * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.GaussianBlur(rad)),
                   dtype=np.float32) / 255
    s_ = b.sum(-1) + 1e-4
    bl = b @ W
    feat = np.stack([b[..., 0] / s_ * 6, b[..., 1] / s_ * 6, bl * 3], -1)
    lo, hi = np.percentile(bl[m], [3, 97])
    sel = m & (bl > lo) & (bl < hi)
    px = feat[sel]
    px = px[:: max(1, len(px) // 200000)]
    q = np.percentile(px[:, 2], np.linspace(12, 88, K))
    c = np.stack([px[np.argmin(np.abs(px[:, 2] - qq))] for qq in q])
    for _ in range(25):
        lab = ((px[:, None, :] - c[None]) ** 2).sum(-1).argmin(1)
        c = np.stack([px[lab == i].mean(0) if (lab == i).any() else c[i] for i in range(K)])
    full = np.stack([((feat - c[i]) ** 2).sum(-1) for i in range(K)]).argmin(0)
    lum0 = a @ W
    col = np.stack([np.median(a[m & (full == i)].reshape(-1, 3), 0) if (m & (full == i)).any() else c[i, :3] * 0 + 0.3 for i in range(K)])
    tl = np.array([float(np.median(lum0[m & (full == i)])) if (m & (full == i)).any() else 0.2 for i in range(K)])
    order = np.argsort(tl)
    rank = np.argsort(order)
    return rank[full], col[order], tl[order]


def strict_keep(a, p, m):
    """Only a strongly coloured marking of another hue is kept - a camo's own tones never are."""
    h_, c_ = hue(a)
    ph, _pc = hue(p[None, None, :])
    dh = np.abs(h_ - float(ph[0, 0]))
    return (~m) | ((c_ > 0.3) & (np.minimum(dh, 360 - dh) > 60))


def squarify(a, w):
    """The CSAT hex re-cut as squares: the sheet's four tones found, the tone map quantised onto a square grid by
    majority (so the square clusters follow the hex clusters), and each pixel given its square's tone colour with
    its own shading - brightness relative to the tone it wore - so panel lines, rivets and wear stay."""
    h, ww = a.shape[:2]
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    keep = strict_keep(a, p, m)
    # the markings are kept out of the tone split and the vote: on the quad bike a red tail light became the fourth
    # "tone" and every square it won came out red (pink check, 2026-09-19)
    paint = m & ~keep
    full, col, tl = tone_split(a, paint, 4, w)
    # a tone that is a sliver of the paint, or strongly coloured, is no camo tone: it is the blur-bleed around a red
    # tail light (the quad bike, three remakes running) and it won every square along that light. Its pixels go to
    # the nearest real tone by colour.
    share = np.array([float((paint & (full == i)).mean()) for i in range(4)])
    _h, cc = hue(col[None, :, :])
    ok = (share >= 0.05 * share.sum()) & (cc[0] < 0.25)
    if ok.any() and not ok.all():
        good = np.nonzero(ok)[0]
        d = np.stack([((a - col[i]) ** 2).sum(-1) for i in good], -1)
        full = np.where(ok[full], full, good[d.argmin(-1)])
    cell = max(4, int(round(w / 64)))                                       # ~32 px at 2048: a digital block
    gh, gw = -(-h // cell), -(-ww // cell)
    pad = np.full((gh * cell, gw * cell), -1, dtype=np.int64)
    pad[:h, :ww] = np.where(paint, full, -1)
    blocks = pad.reshape(gh, cell, gw, cell).transpose(0, 2, 1, 3).reshape(gh, gw, -1)
    counts = np.stack([(blocks == k).sum(-1) for k in range(4)], -1)
    grid = counts.argmax(-1)
    cls = np.repeat(np.repeat(grid, cell, 0), cell, 1)[:h, :ww]
    ratio = lum0 / np.maximum(tl[full], 1e-3)
    # the hex cells' drawn outlines lie on the tone boundaries: along a band there the shading takes a median, which
    # drops a line a few pixels wide, and the hex lattice stops showing through the squares (preview, 2026-09-19)
    edge = (full != np.roll(full, 1, 1)) | (full != np.roll(full, 1, 0))
    band = np.asarray(Image.fromarray((edge * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(9))) > 0
    med = np.asarray(Image.fromarray((np.clip(ratio / 2, 0, 1) * 255 + 0.5).astype(np.uint8)).filter(ImageFilter.MedianFilter(11)),
                     dtype=np.float32) / 255 * 2
    ratio = np.where(band, med, ratio)
    ratio = np.where(ratio > 1.2, 1.2 + (ratio - 1.2) * 0.35, ratio)
    # capped at 1.3, not 1.7: the hex's brown tone under a bright highlight went salmon on the quad bike and the
    # Stomper's interior (pink check, 2026-09-19)
    ratio = np.clip(ratio, 0.25, 1.3)
    new = np.clip(col[cls] * ratio[..., None], 0, 1)
    return np.where(keep[..., None], a, new)


def eaf_arid(a, w, tag="trarid"):
    """Aegis's EAF splinter recoloured arid: its three tones found and swapped, darkest to lightest, for the EAF arid
    sand and two darker sands; each pixel keeps its own shading. Turkish Green (trgreen) is the same three tones
    the other way up - the olive-brown where the sand was, the sand where the olive-brown was."""
    hexes, base_l = EAF_ARID
    cols = srgb(hexes)
    cols = np.clip(cols * (base_l / float(cols[-1] @ W)), 0, 1)             # the lightest AT the EAF arid sheet's level
    green = None
    if tag == "trgreen":
        # user, 2026-09-21: the arid scheme with the shares swapped - the green covers the most
        hexes, base_l = TURKISH_TROPICAL
        cols = srgb(hexes)
        cols = np.clip(cols * (base_l / float(cols[-1] @ W)), 0, 1)
        green = 1
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    keep = strict_keep(a, p, m)
    full, _col, tl = tone_split(a, m & ~keep, 3, w)
    if green is not None:
        # the source tone that covers the most becomes the green; the other two keep the arid's sand and dark
        share = [float(((full == i) & m & ~keep).sum()) for i in range(3)]
        big = int(np.argmax(share))
        order = [j for j in range(3) if j != big]
        cols = np.stack([cols[green] if i == big else cols[order.pop(0) if order else 0] for i in range(3)])
    ratio = np.clip(lum0 / np.maximum(tl[full], 1e-3), 0.45, 1.3)
    new = np.clip(cols[full] * ratio[..., None], 0, 1)
    return np.where(keep[..., None], a, new)


# user, 2026-09-22: "use the green form russia and the sand color from tyrkey arid" - so the tropical Turkey is
# exactly the Russian green beside the arid faction's own sand, in the shares the photographs show.
TROPICAL_GREEN = np.array(TARGET_GREEN_SRC, dtype=np.float32)   # faction_russia's green, #2d2e25
TROPICAL_SAND = srgb(["#736957"])[0]                            # the Turkish arid's lightest tone


def tint_parts(a, tag):
    """A running-gear sheet (the EF Gyra's "details"): the tyres are neutral rubber and must not be painted, but
    its stowage and panels are coloured and were left green on an arid vehicle (user, 2026-09-22: "in arid tyrkey
    there is some dark green parts on the gyra"). Only the COLOURED pixels are retinted, each keeping its own
    shading; anything neutral - rubber, bare metal, black - comes through untouched."""
    base = None
    if tag == "trgreen":
        base = TROPICAL_GREEN
    elif tag == "trarid":
        base = np.clip(srgb([EAF_ARID[0][1]])[0] * (EAF_ARID[1] / max(float(srgb([EAF_ARID[0][2]])[0] @ W), 1e-3)), 0, 1)
    elif tag in MERDC_SET:
        base = srgb(MERDC_SET[tag])[::-1][0]
    if base is None:
        return a
    # The discriminator is HUE, not saturation: the panels that show green are desaturated olive, while the brake
    # discs are rust and the tyres are neutral. Only green-hued pixels are retinted.
    hh, chroma = hue(a)
    sel = (chroma > 0.015) & (hh > 55) & (hh < 175)
    if not sel.any():
        return a
    lum0 = a @ W
    lp = float(np.median(lum0[sel]))
    ratio = np.clip(lum0 / max(lp, 1e-3), 0.6, 1.25)[..., None]
    new = np.clip(base[None, None, :] * ratio, 0, 1)
    return np.where(sel[..., None], new, a)


def tropical(a, seed, w):
    """The Turkish woodland: olive drab with soft sand blobs, as the reference photographs show it. The colours are
    ANCHORED - each pixel is its palette colour times its own shading, never the source's brightness."""
    cols = np.stack([TROPICAL_GREEN, TROPICAL_SAND])
    h, ww = a.shape[:2]
    rng = np.random.default_rng(seed)
    f = noise(rng, h, ww, 3)
    sand = f > np.quantile(f, 0.66)                       # a third of the hull, the rest green
    soft = np.asarray(Image.fromarray((sand * 255).astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(max(2.0, ww / 500))), dtype=np.float32) / 255
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    keep = strict_keep(a, p, m)
    lp = float(np.median(lum0[m])) if m.any() else 0.25
    # a light source sheet must not lift the palette
    ratio = np.clip(lum0 / max(lp, 1e-3), 0.6, 1.12)[..., None]
    base = cols[0][None, None, :] * (1 - soft[..., None]) + cols[1][None, None, :] * soft[..., None]
    new = np.clip(base * ratio, 0, 1)
    return np.where(keep[..., None] | (~m)[..., None], a, new)


def splinter(a, seed, w, tag="trarid"):
    """For a Turkish vehicle with no EAF sheet: the splinter pattern made - angular polygons (nearest-point regions
    of scattered seeds) in the EAF arid tones, 55 / 28 / 17. Turkish Green: the same tones, shares reversed - the
    olive-brown as the base, the sand as the 17%."""
    hexes, base_l = TURKISH_TROPICAL if tag == "trgreen" else EAF_ARID
    if tag == "trgreen":
        hexes = [hexes[0], hexes[2], hexes[1]]      # so [::-1] puts the GREEN first: the base, at 55%
    cols = srgb(hexes)[::-1].copy()
    ref = float(max(c @ W for c in cols))           # the lightest tone sets the level, never the base
    cols = np.clip(cols * (base_l / max(ref, 1e-3)), 0, 1)
    h, ww = a.shape[:2]
    rng = np.random.default_rng(seed)
    n = 90
    pts = np.stack([rng.random(n) * h, rng.random(n) * ww], 1)
    yy, xx = np.mgrid[0:h:8, 0:ww:8]
    d = (yy[..., None] - pts[:, 0]) ** 2 + (xx[..., None] - pts[:, 1]) ** 2
    region = d.argmin(-1)
    tone_of = rng.choice(3, size=n, p=[0.55, 0.28, 0.17])
    cls = np.asarray(Image.fromarray(tone_of[region].astype(np.uint8)).resize((ww, h), Image.NEAREST))
    MID_DROP[0] = True
    out, (lum, m, lp, keep) = lay(a, cols, cls, w, blur=max(1.0, w / 2000), mode="mul")
    MID_DROP[0] = False
    return uniform_shade(out, a, m, keep, cols, np.array([0.55, 0.28, 0.17], dtype=np.float32), DIGITAL_KEY[0])


# the game's green hex (Apex, CSAT Pacific), measured on Truck_03_ext01_ghex / MBT_02_body_ghex / MRAP_02_ext_01_ghex:
# darkest first - near-black, dark olive, olive green
GREEN_HEX = ["#0f0f0b", "#232218", "#42452b"]


def greenhex(a, w):
    """An arid hex sheet in the game's green hex: its three tones found and swapped, darkest to lightest, for the
    green hex's three; each pixel keeps its own shading. A sheet that is not a hex gets the same three tones over
    its own light and shade, which reads as the green scheme."""
    cols = srgb(GREEN_HEX)
    lum0 = a @ W
    p, m = paint_of(a, lum0)
    keep = strict_keep(a, p, m)
    full, _col, tl = tone_split(a, m & ~keep, 3, w)
    ratio = np.clip(lum0 / np.maximum(tl[full], 1e-3), 0.45, 1.3)
    new = np.clip(cols[full] * ratio[..., None], 0, 1)
    return np.where(keep[..., None], a, new)


def load_table():
    if os.path.exists(TABLE):
        return pickle.load(open(TABLE, "rb"))
    strings = json.load(open(os.path.join(CP.AP, "vanilla_strings.json"), encoding="utf-8"))
    VB.strings.update({k.lower(): v for k, v in strings.items()})
    VB.strings.update(CP.E.load_strings())
    recs = CP.load_game()
    CP.LOADING[0] = "JMSB"
    g = CP.jmfsb_table()
    table = dict(recs)
    for k, r in g.items():
        table.setdefault(k, r)
    pickle.dump((table, g, dict(VB.strings)), open(TABLE, "wb"))
    return table, g, dict(VB.strings)


def main():
    preview = "--preview" in sys.argv
    plan = "--plan" in sys.argv
    table, g, strings = load_table()
    VB.strings.update(strings)
    for path in MOD_CONFIGS:                    # the mods' own classes, so a faction vehicle built on one resolves
        cv = VB.parse(VB.read_text(path)).kids.get("cfgvehicles")
        for k, nd in (cv.kids.items() if cv else []):
            if nd.body and k not in table:
                table[k] = VB.Rec(nd, "mod")
    _v, pool, _f, found = pickle.load(open(os.path.join(SP, "camo_pool.pickle"), "rb"))
    old = json.load(open(MAP, encoding="utf-8"))
    for addon, picks in old["camo"].items():
        for pick in picks.values():
            pick["copy"] = [[s, (addon + "\\" + r) if r.lower().startswith("data\\") else r] for s, r in pick["copy"]]
    os.makedirs(WORK, exist_ok=True)

    def source_of(t):
        """A readable file for a texture path: game:<path>, a path on disk, None (not a file), False (missing)."""
        q = CP.clean(t)
        lo = q.lower()
        if not q or q.startswith("#"):
            return None
        for pre, root in AEGIS_SOURCE.items():
            if lo.startswith(pre):
                p = os.path.join(root, q[len(pre):])
                return p if os.path.exists(p) else False
        if lo.startswith("a3\\"):
            return ("game:" + q) if PR.game_entry(q) else False
        if lo.startswith("z\\jmfsb\\"):
            base = re.sub(r"\.(paa|tga)$", "", os.path.join(JMFSB, q[len("z\\jmfsb\\"):]), flags=re.I)
            return next((base + e for e in (".paa", ".tga") if os.path.exists(base + e)), False)
        if lo.startswith("ef\\"):
            p = ef_file(q)
            return p if p else False
        for pre, root in MOD_ROOTS.items():
            if lo.startswith(pre):
                p = os.path.join(root, q[len(pre):])
                return p if os.path.exists(p) else False
        real = found.get(q)
        return real if real and not real.startswith("game:") else False

    made_by, used_rel, made_wheels = {}, {}, {}
    MODIFIED = {}           # (source, tag) -> "squarify" | "eaf_arid": the MODIFY path realise() chose for that sheet

    def made_rel(owner, mk, q, tag):
        folder = re.sub(r"^src:", "", mk).split("\\")[-2] if "\\" in mk else "misc"
        stem = re.sub(r"_co$", "", re.sub(r"\.\w+$", "", q.split("\\")[-1]), flags=re.I)
        rel = "%s\\data\\camo\\made\\%s\\%s_%s_co.paa" % (owner, folder, stem, tag)
        if used_rel.get(rel.lower(), q.lower()) != q.lower():
            rel = rel[:-7] + "_%s_co.paa" % hashlib.sha1(q.lower().encode()).hexdigest()[:4]
        used_rel[rel.lower()] = q.lower()
        return rel

    def stale(path, tag, masks):
        """Made before a change it has to show: wheel masks it now takes, or its camo's colours changed since this
        script was last edited (--remake-tags)."""
        t = os.path.getmtime(path)
        for part in ("wheels", "glass"):
            if masks and masks.get(part) and os.path.exists(masks[part]) and t < os.path.getmtime(masks[part]):
                return True
        return tag in REMAKE_TAGS and t < REMAKE_SINCE

    def make(src, tag, rel, seed, flag, masks=None, lp_set=None):
        key = (str(src).lower(), tag)
        wheels = tuple((masks or {}).get(k) for k in ("wheels", "glass"))
        # One source texture serves several vehicles, and the first to ask used to settle it for the rest. A
        # vehicle whose model HAS a wheel mask could therefore inherit a file made without one and keep its
        # painted tyres (the China Arid Truck_02 did). Let a caller through when it brings a wheel or glass mask
        # the cached file was not made with; stale() then decides whether the file on disk needs redoing.
        if key in made_by and not (any(wheels) and wheels != made_wheels.get(key)):
            return made_by[key]
        made_wheels[key] = wheels
        dst0 = os.path.join(JMFSB, "addons", rel)
        if plan or (not preview and "--remake" not in sys.argv and os.path.exists(dst0) and not stale(dst0, tag, masks)):
            made_by[key] = (rel, None, None)            # already made: only what is missing or stale is made again
            return made_by[key]
        name = hashlib.sha1(str(src).lower().encode()).hexdigest()[:16]
        png = PR.to_png(src, "src_" + name)
        if not png:
            return None
        SRC_NAME[0] = str(src).lower()
        rgba = np.asarray(Image.open(png).convert("RGBA"), dtype=np.float32) / 255
        a = rgba[..., :3]
        DIGITAL_KEY[0] = rel
        # a whole sheet of wheels (the QAV PGL-625E's 625E_wheels): no mask can cut it, so none of it is painted
        stem_ = re.sub(r"(?i)_co$", "", os.path.basename(str(src)).rsplit(".", 1)[0])
        wheel_only = bool(WHEEL_SHEET.search(stem_))
        if not wheel_only and tag not in SNOW_TAGS and PARTS_SHEET.search(stem_) and (
                PARTS_ANY.search(stem_) or str(src).lower().startswith(PARTS_ROOTS)):
            wheel_only = True
        if wheel_only:
            STATS["wheel sheet, left as it is"] = STATS.get("wheel sheet, left as it is", 0) + 1
        modify = MODIFIED.get(key)
        if wheel_only:
            # a whole sheet of wheels stays as it is; a running-gear sheet keeps its rubber but loses its colour
            out = tint_parts(a, tag) if PARTS_SHEET.search(stem_) else a
        elif modify == "squarify":
            out = squarify(a, a.shape[1])
        elif modify == "winter":
            out = winter(a, a.shape[1])
        elif modify == "eaf_arid":
            out = tropical(a, seed, a.shape[1]) if tag == "trgreen" else eaf_arid(a, a.shape[1], tag)
        elif tag == "trgreen":
            out = tropical(a, seed, a.shape[1])
        elif tag == "trarid":
            out = splinter(a, seed, a.shape[1], tag)
            out = place_flags(out, a @ W, paint_of(a, a @ W)[1], float(np.median((a @ W)[paint_of(a, a @ W)[1]])), 2) if flag else out
        elif tag == "euarc":
            out = arctic_parts(a) if ARCTIC_PARTS.search(stem_) else arctic_white(a)
        elif tag in TARGET:
            tgt = TARGET_KEEP[tag] if (tag in TARGET_KEEP and "qav" in SRC_NAME[0]) else TARGET[tag]
            out = solid(a, tgt, lp_set, tag)
        elif tag == "rusarctic":
            out = arctic(a, seed, lp_set)
        elif tag in DIGITAL:
            out = digital(a, seed, tag, lp_set, flat=bool((masks or {}).get("mask")))   # a plane: flat shading
        elif tag in EU_COLOURS:
            lo_src = str(src).lower()
            if tag in MERDC_SET:
                out = merdc_set(a, seed, tag)
            elif tag in PLAIN_TURRETS and TURRET.search(os.path.basename(lo_src.replace(chr(92), "/"))):
                # the turret in the scheme's base colour, plain: green for the woodland, sand for the arid
                hexes, (ref, factor) = EU_COLOURS[tag]
                # the list is darkest first: scale it by its LIGHTEST (the base), as remap() does - scaling by the
                # black band put the base near white, and the first turrets came out at 0.83 (verify, 2026-09-19)
                out = solid(a, base_level(srgb(hexes), ref, factor, which=-1)[-1], None, tag)
            else:
                out = eu_blotch(a, seed, tag)       # MERDC over the plainest paint; a wdl or LDF sheet is one more source
        elif tag in PLANE:
            out = plane_paint(a, seed, tag, (masks or {}).get("mask"))
        elif tag == "irghex":
            out = greenhex(a, a.shape[1])
        else:
            out = turkish(a, seed, flag, tag)
        um = (masks or {}).get("mask")                  # a plane's underside, kept in its air-force colour (TOPSIDE)
        if um and os.path.exists(um) and tag in UNIFORM and UNDER[0] in PLANE:
            under = np.asarray(Image.open(um).convert("L").resize((a.shape[1], a.shape[0]), Image.BILINEAR),
                               dtype=np.float32)[..., None] / 255
            out = out * (1 - under) + plane_paint(a, seed, UNDER[0], um) * under
        for part in ("wheels", "glass"):                # the wheels and the glass are never patterned (user: "don;t
            pm = (masks or {}).get(part)                # camo thew wheels", "do not camo windshields"): the glass keeps
            if pm and os.path.exists(pm):               # the source's, the wheels a plain rim paint (wheel_paint)
                wm = np.asarray(Image.open(pm).convert("L").resize((a.shape[1], a.shape[0]), Image.BILINEAR),
                                dtype=np.float32)[..., None] / 255
                # a modified sheet (the EAF recolour) had its tyres recoloured with the rest - "why the fuck are the
                # tired in turkey camoed" (user, 2026-09-20). Inside the wheel mask it takes the SOURCE's wheels.
                # user, 2026-09-20 (fourth and fifth time): "STOP FUCKING TEXTURING WHEELS". Every sheet, modified or
                # made, any camo: the wheel area is the neutral wheel paint; the glass is the source's own.
                under = wheel_paint(a, tag) if part == "wheels" else a
                if part == "glass":
                    under = a
                out = out * (1 - wm) + under * wm
        # the near-black fallback guards the tyres of a model no wheel mask was read for. A sheet of a SURVEYED model
        # with no wheels on it has none to guard, and on the EU arctic it left the HEMTT bed and cover speckled black
        if not ((masks or {}).get("wheels")) and not (masks or {}).get("surveyed"):
            lum_src = a @ W
            cut = 0.04 if tag in SNOW_TAGS else 0.07
            rubber = (lum_src < cut) & ((a.max(-1) - a.min(-1)) < 0.04)
            if rubber.any():
                out = np.where(rubber[..., None], a, out)
        pink_check(out, a, rel)
        alpha = rgba[..., 3:]
        arr = np.concatenate([out, alpha], -1) if float(alpha.min()) < 0.999 else out
        img = Image.fromarray((arr * 255 + 0.5).astype(np.uint8))
        # SCALE (user, 2026-09-16: "the mod is getting to large"). Two cuts that leave what a vehicle wears
        # by default at full size: nothing needs to ship above 2048, and a camo no faction wears - one that
        # exists only to sit in the appearance menu - ships at half. Halving in exact steps keeps every
        # dimension a power of two, which PAA wants.
        cap = 2048
        if tag not in DEFAULT_TAGS:
            cap = min(cap, max(img.size) // 2)
        while max(img.size) > cap and min(img.size) > 8:
            img = img.resize((max(8, img.width // 2), max(8, img.height // 2)), Image.LANCZOS)
        tmp = os.path.join(WORK, "%s_%s.png" % (name, tag))
        img.save(tmp)
        if preview:
            made_by[key] = (rel, png, tmp)
            return made_by[key]
        dst = os.path.join(JMFSB, "addons", rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        # hemtt's convert REFUSES an output file that exists ("Output file already exists") and still exits 0,
        # so a re-run that kept the old file read as a success: every remake since the first build was silently
        # a no-op, which is how the pink brown outlived two palette changes (user, 2026-09-15: "but is it fixed").
        # Remove it first, and judge the convert by the file being newly written, not by its existing.
        if os.path.exists(dst):
            os.remove(dst)
        subprocess.run(["hemtt", "utils", "paa", "convert", tmp, dst], capture_output=True)
        os.remove(tmp)
        if not os.path.exists(dst):
            print("   ! convert failed, no texture written: %s" % rel)
            made_by[key] = None
            return None
        made_by[key] = (rel, png, None)
        return made_by[key]

    def is_co(q):
        return re.search(r"_co(\.\w+)?$", q, re.I)

    def set_level(tex):
        """One brightness reference for the whole set. Measured per sheet, then taken from the sheet with
        the most paint on it - a vehicle's hull, not its gun or its tracks. Anchoring each sheet on its own
        median is what lifted the dark ones to hull brightness ("gun is to light")."""
        best, most = None, 0
        for t in tex:
            q, src = CP.clean(t), source_of(t)
            if src is None or src is False or not is_co(q):
                continue
            png = PR.to_png(src, "src_" + hashlib.sha1(str(src).lower().encode()).hexdigest()[:16])
            if not png:
                continue
            try:
                SRC_NAME[0] = str(src).lower()
                a = np.asarray(Image.open(png).convert("RGB"), dtype=np.float32) / 255
                lp, n = paint_level(a)
            except Exception:
                continue
            if lp and n > most:
                best, most = lp, n
        return best

    def realise(tex, tag, mk, flag, masks=None, modify=None):
        """The texture set in that camo: config paths and what was made; None when a texture cannot be. masks: a
        plane's underside mask by each texture's place in the set (plane_undersides.py's index)."""
        # user, 2026-09-18: "the turkey hemtt fuel truck is screwed up". The game's own Olive scheme for the HEMTT
        # fuel truck names the mine-primer sheet as its third texture, not the fuel tank, so the tank was painted
        # from a sheet laid out for another part. On a fuel-truck model that third sheet is the tank's.
        if "truck_01_fuel" in (mk or "").lower():
            tex = [("a3" + chr(92) + "soft_f_gamma" + chr(92) + "truck_01" + chr(92) + "data" + chr(92) + "truck_01_fuel_co.paa")
                   if "mprimer" in CP.clean(t).lower() else t for t in tex]
        paths, made, first = [], [], True
        lp_set = set_level(tex)
        for i, t in enumerate(tex):
            q, src = CP.clean(t), source_of(t)
            if src is None:
                paths.append(t.strip())
            elif is_co(q):
                seed = int(hashlib.sha1((q + tag).lower().encode()).hexdigest()[:8], 16)
                if modify:
                    MODIFIED[(str(src).lower(), tag)] = modify
                got = make(src, tag, made_rel(TAG_OWNER[tag], mk, q, tag), seed, flag and first,
                           (masks or {}).get(str(i)) or ({"surveyed": True} if masks and tag == "euarc" else None), lp_set)
                first = False
                if not got:
                    return None
                paths.append("\\z\\jmfsb\\addons\\" + got[0])
                made.append([src, got[0]])
            elif q.lower().startswith(("a3\\", "z\\jmfsb\\") + tuple(MOD_ROOTS)):
                paths.append("\\" + q)
            else:
                return None           # a mod's non-colour texture: not worth a copy for a recolour
        return paths, made

    def copy_set(tex, owner):
        """A mod's texture set as it is, copied into the owner's data\\camo: config paths and the copies."""
        paths, copy = [], []
        for t in tex:
            q, src = CP.clean(t), source_of(t)
            if q.lower().startswith(REFERENCED):
                paths.append(BS_ + q)
            elif src is None:
                paths.append(t.strip())
            elif src is False:
                return None
            elif q.lower().startswith(("a3\\", "z\\jmfsb\\")):
                paths.append("\\" + q)
            elif q.lower().startswith(tuple(MOD_ROOTS)):
                # a mod folder on disk (the QAV Challenger): copied, so jmfsb carries no dependency on it
                parts_ = [x for x in q[len(next(k for k in MOD_ROOTS if q.lower().startswith(k))):].split("\\") if x]
                rel = "\\".join([owner, "data"] + [x for x in parts_ if x.lower() != "data"])
                copy.append([src, rel])
                paths.append("\\z\\jmfsb\\addons\\" + rel)
            else:
                parts = re.split(r"[\\/]", src)
                i = next((n for n, s in enumerate(parts) if s.lower() in CP.MODS), None)
                if i is None:
                    return None
                rel = "\\".join([owner, "data"] + [x for x in parts[i + 2:] if x.lower() != "data"])
                copy.append([src, rel])
                paths.append("\\z\\jmfsb\\addons\\" + rel)
        return paths, copy

    # user, 2026-09-20: "vechicles in the same class famile have some shared textures" - a HEMTT variant shares the
    # cab and body sheets with every other HEMTT, so a scheme that covers the family's shared sheets covers every
    # variant: each sheet of the vehicle's factory set is looked up BY NAME (Truck_01_ext_01 -> Truck_01_ext_01_wdl)
    # in the release, the hits copied, and only the sheets the release has no twin for are made.
    # the EU arid is not here any more either: Atlas's Marar is Turkish, not NATO sand (user, 2026-09-25)
    SHEET_TOKENS = {}   # tag: (token, release subfolders - "" the whole tree)
    # the EU WOODLAND is not here any more: it wears NATO colours, so there is no scheme to copy by sheet name
    # sheets the token cannot find, named by the user: stem (variant stripped) -> the release file
    SHEET_ALIAS = {"eudes": {"truck_01_ext_01": 'D:\\Git\\A3_Aegis_Public_Releases\\A3_Atlas\\soft_f_atlas\\Truck_01\\Data\\Truck_01_ext_01_fr_CO.paa',
                             "truck_01_fuel": 'D:\\Git\\A3_Aegis_Public_Releases\\A3_Atlas\\soft_f_atlas\\Truck_01\\Data\\Truck_01_fuel_ADF_CO.paa'},
                   "euwdl": {"heli_transport_01_ext01": os.path.join('D:\\Git\\A3_Aegis_Public_Releases\\A3_Atlas\\air_f_atlas\\Heli_Transport_01\\Data', "Heli_Transport_01_ext01_au_CO.paa"),
                             "vtol_01_ext02": 'D:\\Git\\A3_Aegis_Public_Releases\\A3_Aegis\\air_f_aegis\\VTOL_01\\Data\\VTOL_01_EXT02_BAF_CO.paa',
                             "heli_transport_01_ext02": os.path.join('D:\\Git\\A3_Aegis_Public_Releases\\A3_Atlas\\air_f_atlas\\Heli_Transport_01\\Data', "Heli_Transport_01_ext02_au_CO.paa")}}
    RELEASES = r"D:\Git\A3_Aegis_Public_Releases"
    VARIANT = r"(?i)_(olive|pacific|desert|sand|black|blufor|opfor|indep|ghex|tropic|arid|green|grey|gray|nato|csat|aaf|ldf|eaf|wdl|winter|snow|khk|rukhk|arctic|blue|red|white|yellow|orange|guer|ind|civ)$"
    _sheet_index = {}

    def sheet_index(tag):
        if tag not in _sheet_index:
            token, subs = SHEET_TOKENS[tag]
            idx = {}
            for sub_ in subs:
                for dp, _dn, fn in os.walk(os.path.join(RELEASES, sub_)):
                    if re.search(r"(?i)characters|bags|structures|editorpreviews", dp):
                        continue
                    for f in fn:
                        m = re.match(r"(?i)^(.*)_(?:%s)_co\.paa$" % token.strip("()?:"), f)
                        if m:
                            idx.setdefault(m.group(1).lower(), os.path.join(dp, f))
            _sheet_index[tag] = idx
        return _sheet_index[tag]

    _size = {}

    def sheet_size(pth, why):
        if pth not in _size:
            try:
                png = PR.to_png(pth, "sz_" + hashlib.sha1(str(pth).lower().encode()).hexdigest()[:14])
                _size[pth] = Image.open(png).size if png else None
            except Exception:
                _size[pth] = None
        return _size[pth]

    def near_sheet(idx, stem, src):
        """A release sheet named within three letters of this one, and the same size: tower / tow."""
        for k, f in idx.items():
            if k == stem or not (k.startswith(stem) or stem.startswith(k)):
                continue
            if abs(len(k) - len(stem)) > 3:
                continue
            a, b = sheet_size(str(src), "near-src"), sheet_size(f, "near-rel")
            if a and a == b:
                return f
        return None

    PLAIN = ("olive", "green", "indepolive", "oliveblacktwotone", "usolive", "olivegreen", "nato", "blufor")

    SAND = ("sand", "tan", "desert", "arid", "khaki", "nato")
    # sheets that carry another nation's insignia whatever their scheme is called: Atlas's "Desert" Comanche is an
    # Israeli splinter with the Star of David and a yellow V (user, 2026-09-26). Never copied onto the EU.
    MARKED = re.compile(r"(?i)a3_atlas.*heli_attack_01_desert_co")
    PATTERNED = re.compile(r"dazzle|hex|digi|camo|tiger|splinter|wdl|woodland|merdc|marar|ldf|winter|snow|arctic")

    def plain_rank(nm, tag="euwdl"):
        """How plain a scheme's NAME is for this theatre: an exact match first, then one that carries the word."""
        want = SAND if tag == "eudes" else ("olive", "green", "wdl")
        if PATTERNED.search(nm):
            return 9                    # a camo pattern, not a NATO paint: Dazzle (Sand), Green Hex, Digital
        if nm in want[:3]:
            return 0
        if nm in ("olivegreen", "indepolive", "oliveblacktwotone", "natosand", "desertnato"):
            return 1
        if any(w in nm for w in want):
            return 2
        return 3 if nm in PLAIN else 9

    def plain_set(cands, nsel, tag_="euwdl"):
        """The vehicle's plainest single-colour scheme, index-aligned with its factory set."""
        best = None
        for c in sorted((c for c in cands if len(c[6]) == nsel), key=lambda c: c[2]):
            if plain_rank(norm(c[3]), tag_) > 2 or not readable(c[6]):
                continue
            if best is None or plain_rank(norm(c[3]), tag_) < plain_rank(norm(best[3]), tag_):
                best = c
        return list(best[6]) if best else None

    def same_model(hit, stem, src):
        """Does this release sheet belong to the same model as the sheet it would replace?"""
        parts = [x for x in re.split(r"[\\/]", hit) if x]
        fold = next((x.lower() for x in reversed(parts[:-1]) if x.lower() != "data"), "")
        if fold and fold in stem.lower():
            return True
        sp = [x for x in re.split(r"[\\/]", str(src)) if x]
        sfold = next((x.lower() for x in reversed(sp[:-1]) if x.lower() != "data"), "")
        return bool(fold) and fold == sfold

    NET_GREEN = 'A3\\Armor_F\\Data\\camonet_NATO_Green_CO.paa'
    NET_SWAP = re.compile(r"(?i)camonet_(AAF_Digi|NATO)_(Green|Desert|Jungle|Digi)")

    def greener(t, tag):
        """The plain green camo net in place of a digital or desert one, on a woodland vehicle."""
        if tag != "euwdl":
            return t
        q = CP.clean(t)
        base_ = q.replace("/", chr(92)).split(chr(92))[-1]
        if NET_SWAP.search(base_) and "nato_green" not in base_.lower():
            return NET_GREEN
        return t

    def family_pick(r, tag, label, mk, base, cands=()):
        """The vehicle's factory set, sheet by sheet: the release's twin of the scheme copied, the rest made."""
        idx, owner = sheet_index(tag), TAG_OWNER[tag]
        if tag == "euwdl" and not WDL_FAMILY:
            for k, f in idx.items():
                m_ = re.match(r"^([a-z]+_\d+)", k)
                WDL_FAMILY.setdefault(m_.group(1) if m_ else k.split("_")[0], f)
        paths, copies, to_make, hits, olive_used = [None] * len(base), [], [], [], 0
        for i, t in enumerate(base):
            q = CP.clean(t)
            stem = re.sub(r"(?i)_co$", "", re.sub(r"\.\w+$", "", q.split("\\")[-1]))
            al = SHEET_ALIAS.get(tag, {})
            hit = al.get(stem.lower()) or al.get(re.sub(VARIANT, "", stem).lower())
            named = bool(hit)
            hit = hit or idx.get(stem.lower()) or idx.get(re.sub(VARIANT, "", stem).lower())
            fsrc = source_of(t) if is_co(q) else None
            if not hit and fsrc and fsrc is not True:
                hit = near_sheet(idx, stem.lower(), fsrc) or near_sheet(idx, re.sub(VARIANT, "", stem).lower(), fsrc)
            if hit and not named and not same_model(hit, stem, fsrc or t):
                hit = None                                  # another model's sheet that happens to share a name
            if hit and fsrc and fsrc is not True:
                a_, b_ = sheet_size(str(fsrc), "fit-src"), sheet_size(hit, "fit-rel")
                if a_ and b_ and a_ != b_:
                    hit = None                              # a different UV layout
            if hit and is_co(q):
                parts = re.split(r"[\\/]", hit)
                j = next((n for n, s_ in enumerate(parts) if s_.lower() in CP.MODS), None)
                if j is None:                                   # a top-level folder CP.MODS does not name
                    rp = re.split(r"[\\/]", RELEASES)
                    j = len(rp) if len(parts) > len(rp) + 2 else None
                if j is not None:
                    rel = "\\".join([owner, "data"] + [x for x in parts[j + 2:] if x.lower() != "data"])
                    copies.append([hit, rel])
                    paths[i] = "\\z\\jmfsb\\addons\\" + rel
                    hits.append(parts[-1])
                    continue
            to_make.append(i)
        # All or nothing. A set part copied and part left in the vehicle's own paint puts two or three schemes on
        # one vehicle - the user's "clown cars with 3 or 4 differnt camos on them" (2026-09-21). If the release
        # cannot dress every colour sheet, the vehicle wears one scheme of its own instead.
        colour_slots = [i for i, t_ in enumerate(base) if is_co(CP.clean(t_))]
        if not hits or len(hits) < len(colour_slots):
            return None, None
        if to_make:
            # no woodland twin for this sheet: the vehicle's OLIVE sheet for that slot where it has one (its factory
            # sheet may be a digital camo), else the factory sheet. Never a made one.
            alt = plain_set(cands, len(base), tag)
            pick_src = [greener(alt[i] if alt and source_of(alt[i]) else base[i], tag) for i in to_make]
            olive_used = sum(1 for j, i in enumerate(to_make) if alt and pick_src[j] != base[i])
            rest = copy_set(pick_src, owner)
            if rest is None:
                return None, None
            for j, i in enumerate(to_make):
                paths[i] = rest[0][j]
            copies.extend(rest[1])
        STATS["family sheets copied"] = STATS.get("family sheets copied", 0) + len(hits)
        STATS["family sheets left in their own paint"] = STATS.get("family sheets left in their own paint", 0) + len(to_make)
        return {"camo": label, "from": "the release's %s by sheet name (%d of %d: %s)%s" % (
                    SHEET_TOKENS[tag][0], len(hits), len(base), ", ".join(hits),
                    (", the rest in the vehicle's olive" if olive_used else ", the rest in their own paint") if to_make else ""),
                "source": "Woodland", "entry": "hiddenSelectionsTextures", "textures": paths, "copy": copies,
                "made": []}, ("", "", 0, "Woodland", "Aegis", "hiddenSelectionsTextures", list(base))

    def eu_pick(r, tag, label, mk, cands, readable, rank=None):
        """EU: the mods' own wdl (woodland) or desert where the model has it, else the wdl's pattern recoloured."""
        def has(c, word):
            return any(word in CP.clean(t).split("\\")[-1].lower() for t in c[6] if is_co(CP.clean(t)))
        def named(c, want):
            return norm(c[3]) == want or norm(c[1]) == want
        usable = sorted((c for c in cands if readable(c[6])), key=lambda c: c[2])

        # user, 2026-09-16: "for the eu use ldf camos and make whats needed", "also look at base game".
        # The LDF set for this faction's theatre, copied as it is - from Aegis, Atlas, OpF OR the game's own
        # Contact platform, which carries the widest LDF of the lot. A base-game path is referenced where it
        # lies rather than copied, so this costs nothing on disk for those.
        want = "ldfarid" if tag == "eudes" else "ldf"
        if tag in ("eudes", "euwdl", "euarc"):
            # 2026-09-18 evening: the EU arid is the Boxer scheme, made over every vehicle's plainest paint - an LDF
            # arid copy or recolour would be another pattern altogether, and one vehicle would not match the next
            nsel_ = len([x for x in (VB.value(table, r.name, "hiddenselections") or []) if isinstance(x, str)])
            for c in sorted(cands, key=rank):
                if not readable(c[6]) or not any(is_co(CP.clean(t)) for t in c[6] if source_of(t)):
                    continue
                if nsel_ and len(c[6]) != nsel_:
                    continue
                got = realise(c[6], tag, mk, False, MASKS.get(mk))
                if got:
                    show("%s - %s" % (r.name.split("_", 2)[-1][:28], label), (str(got[1][0][0]).lower(), tag), r.name)
                    return {"camo": label, "from": "made from %s (%s)" % (c[3], c[4]), "source": c[3], "entry": c[5],
                            "textures": got[0], "copy": [], "made": got[1]}, c
            return None, None
        for c in (c for c in usable if named(c, want)):
            got = copy_set(c[6], TAG_OWNER[tag])
            if got:
                return {"camo": label, "from": "%s's own %s" % (c[4], c[3]), "source": c[3], "entry": c[5],
                        "textures": got[0], "copy": got[1], "made": []}, c
        # no LDF set for this model in this theatre: keep the LDF pattern, recolour it into the theatre
        for c in (c for c in usable if named(c, "ldf") or named(c, "ldfarid")):
            got = realise(c[6], tag, mk, False, MASKS.get(mk))
            if got:
                show("%s - %s" % (r.name.split("_", 2)[-1][:28], label), (str(got[1][0][0]).lower(), tag), r.name)
                return {"camo": label, "from": "made from %s (%s)" % (c[3], c[4]), "source": c[3],
                        "entry": c[5], "textures": got[0], "copy": [], "made": got[1]}, c

        # The step that used to sit here copied Aegis's own Woodland (or Atlas's Desert) wholesale. That is
        # what kept 25 EU vehicles off LDF entirely - a copied sheet never passes through the palette - so it
        # is gone: past a real LDF sheet, the EU is MADE, in the LDF colours sampled off the Livonian van,
        # KamAZ and Mi-48.
        if tag != "euwdl":
            for c in (c for c in usable if has(c, "wdl")):
                got = realise(c[6], tag, mk, False, MASKS.get(mk))
                if got:
                    show("%s - %s" % (r.name.split("_", 2)[-1][:28], label), (str(got[1][0][0]).lower(), tag), r.name)
                    return {"camo": label, "from": "made from %s (%s)" % (c[3], c[4]), "source": c[3], "entry": c[5],
                            "textures": got[0], "copy": [], "made": got[1]}, c
        return None, None

    def copy_only(tag):
        return tag in SHEET_TOKENS or MOD_SCHEME.get(tag, ("",))[-1] == "leave"

    sheet = []

    def show(label, key, vehicle):
        got = made_by.get(key)
        if preview and got and not any(s[2] == got[2] for s in sheet):
            sheet.append((label, got[1], got[2], vehicle))

    for addon, (tag, plain, options) in JOBS.items():
        if ONLY and addon not in ONLY:
            continue
        if addon in DEFAULT_NATO:
            if not preview and not plan:
                old["camo"][addon] = {}
            print("== %s -> default NATO paint" % addon)
            continue
        label = TAGS[tag]
        rows, counts, left = {}, {}, {}
        UNDER[0] = PLANE_TAGS.get(addon)

        def masked_first(k):
            # a sheet one variant shares with another is made once (make() caches it by source): the variant whose
            # model HAS a wheel mask goes first, so an encrypted EF Hunter takes the base Hunter's masked adds sheet
            # rather than making one with its spare wheels painted (EU arctic, 2026-09-25)
            return (CP.model_key(VB.value(table, g[k].name, "model")) not in MASKS, k)
        for k in sorted(g, key=masked_first):
            r = g[k]
            if r.folder != addon:
                continue
            if preview and not any(p.lower() in r.name.lower() for p in PREVIEW):
                continue
            if NAMES and not any(p in r.name.lower() for p in NAMES):
                continue
            fam, _uav, anc = VB.family(table, r.name)
            lowest = 1 if addon in old["hide"] or addon in old.get("unhide", {}) else 2
            if fam is None or VB.scope(table, r.name) < lowest:
                if fam is None and "crew" in r.node.props:
                    left.setdefault("its parent is another mod's or a creator DLC's", []).append(r.name)
                continue
            hs = VB.value(table, r.name, "hiddenselections")
            mk = CP.model_key(VB.value(table, r.name, "model"))
            if not isinstance(hs, list) or not hs or not mk:
                left.setdefault("no hidden selections, so config cannot repaint it", []).append(r.name)
                continue
            if fam == "Boat":   # user, 2026-09-16: "mater of fact leve all boats", "do not make textures for them"
                left.setdefault("a boat: left in its own paint", []).append(r.name)
                continue
            if fam == "Plane":  # user, 2026-09-21: "why are you fucking camoing plans"
                left.setdefault("an aircraft: left in its own colours", []).append(r.name)
                continue
            if fam == "Static weapon" and not any("pod_heli" in VB.anc_name(k, x).lower() for k, x in anc):
                # user, 2026-09-20: "do not texture turrents unless i tell you to" - Mk6, HMGs, launchers, SAM/radar,
                # ship guns; the Taru pods inherit StaticWeapon but are cargo, not turrets
                left.setdefault("a turret: left in its own paint", []).append(r.name)
                continue
            plane = fam == "Plane" and addon in PLANE_TAGS
            if PLANES_ONLY and not plane:
                continue
            vtag = PLANE_TAGS[addon] if plane else tag
            if plane and tag in DIGITAL and TOPSIDE.search(r.name):
                vtag = tag                      # the faction camo on top, the underside kept (TOPSIDE)
            vlabel, vplain = TAGS[vtag], (PLANE_PLAIN if plane else plain)
            mpath = (VB.value(table, r.name, "model") or "").lower()
            prefer_tex = next((tp for mp, tp in PREFER_BY_MODEL.get(vtag, {}).items() if re.search(mp, mpath)), None)
            chain = {VB.anc_name(kd, x).lower() for kd, x in anc}
            own_ts = VB.nested(table, r.name, "texturesources")
            cands = []           # (name, entry name, tier, scheme name, from, entry, textures)
            for kk, e in own_ts.items():
                if e.name.lower().startswith("jmfsb_camo_"):
                    continue         # our own output: never a paint to start from (see ours() below)
                dn = VB.resolve_str(e.props.get("displayname", e.name)) or e.name
                cands.append((norm(dn), norm(e.name), 0, dn, getattr(e, "origin", None) or "Base game", e.name,
                              e.props.get("textures") or []))
            for p in pool.get(mk, []):
                if p["kind"] != "scheme":
                    continue
                owner_cls, entry = p["cls"].split(" / ")[0], p["cls"].split(" / ")[-1]
                order = CP.POOL_ORDER.index(p["origin"]) if p["origin"] in CP.POOL_ORDER else 99
                cands.append((norm(p["name"]), norm(entry), 1 + (owner_cls.lower() not in chain) + order / 100,
                              p["name"], p["origin"], p["cls"], p["tex"]))
            def ours(tex):
                """A texture this script wrote. Once the class table is read from configs we have already
                painted, a vehicle's hiddenSelectionsTextures ARE our camo, so "its own paint" would mean
                recolouring a recolour - and when a prune had since removed the file, it meant a vehicle with
                no source at all (the Turkish and Russian statics lost their paint that way). Keeping our own
                output out of the candidates is what makes a re-run give the same answer as the first run."""
                return any(r"\camo" + "\\" in CP.clean(t).lower()
                           and CP.clean(t).lower().startswith(r"z\jmfsb" + "\\")
                           for t in tex if isinstance(t, str))

            # The paint the vehicle INHERITS, our own class's entry skipped. The class table is read from
            # configs this script has already painted, so the class's own hiddenSelectionsTextures is our
            # output; the factory paint is the parent's. Taking the class's own value made "its own paint"
            # mean our camo - harmless while the file existed, and a vehicle with no source at all once a
            # prune removed it.
            cur = None
            for kind, x in VB.ancestry(table, r.name)[1:]:
                if kind == "src" and "hiddenselectionstextures" in x.node.props:
                    cur = x.node.props["hiddenselectionstextures"]
                    break
                if kind == "vanilla" and isinstance(x.v, dict) and "hiddenselectionstextures" in x.v:
                    cur = x.v["hiddenselectionstextures"]
                    break
            if isinstance(cur, list) and not ours(cur):
                cands.append(("", "", 0, "its own paint", "Base game", "hiddenSelectionsTextures", cur))

            def readable(tex):
                files = [source_of(t) for t in tex]
                return any(files) and all(f is not False for f in files)

            if WHY and WHY.lower() in r.name.lower():
                for c in cands:
                    print("   why %-34s %-26s %-10s tier %.2f readable %s" % (r.name[-34:], c[3][:26], c[4][:10], c[2],
                                                                          readable(c[6])))

            nsel = len([x for x in hs if isinstance(x, str)])

            def preferred(c):
                """A PREFER_BY_MODEL set: every sheet the vehicle takes in it matches. Aegis's sets are longer
                (their chassis sheet), so they are cut to the vehicle's count as the game pairs them, by index."""
                head = [x for x in list(c[6])[:nsel] if isinstance(x, str)]
                return bool(prefer_tex) and len(c[6]) >= nsel and len(head) == nsel                     and all(re.search(prefer_tex, x.lower()) for x in head)

            def rank(c):
                # the game pairs hiddenSelectionsTextures[i] with hiddenSelections[i], so a set of another
                # length is mis-paired whatever its name: the PGL-625E (3 selections - hull, wheels, camo net)
                # was taking the Rhino's inherited 7-texture Green, which put a hull texture on its wheels and
                # left the wheel mask painting a hull (user, 2026-09-15: "the tires are still camoed")
                if preferred(c):
                    return (0, -1, c[2])
                fit = 0 if len(c[6]) == nsel else 1
                hit = [vplain.index(n) for n in (c[0], c[1]) if n in vplain]
                if hit:
                    return (fit, min(hit), c[2])
                return (fit, len(vplain) if c[5] == "hiddenSelectionsTextures" else len(vplain) + 1, c[2])

            pick, chosen = None, None
            if vtag in MOD_SCHEME:
                # user, 2026-09-16: "for turkey remove your home made textures and use Marar's textures from
                # D:\Git\A3_Aegis_Public_Releases". Marar is an Atlas faction and covers 15 models, so a
                # vehicle it does not cover is left in its own paint rather than given a made camo.
                spec = MOD_SCHEME[vtag]
                gap = spec[-1]
                wants = [(spec[0], spec[1])] if isinstance(spec[0], str) else list(spec[:-1])
                want = wants[0][0]
                for c in sorted((c for c in cands if readable(c[6])), key=lambda c: c[2]):
                    if not any(norm(c[3]) == w and c[4] in o for w, o in wants):
                        continue
                    if len(c[6]) < nsel:
                        # the game pairs texture to selection by index: Aegis's five-sheet Green for its own Qilin
                        # variant went onto the three-selection base Qilin (verify, 2026-09-19)
                        continue
                    # a LONGER set is fine cut to the vehicle's count: Aegis's four-sheet HEMTT Woodland is the base
                    # game's three sheets plus a cover the transport model has no selection for (user, 2026-09-20:
                    # "with eu there is woodland camo in ...Truck_01")
                    got = copy_set(list(c[6])[:nsel], TAG_OWNER[vtag])
                    if got:
                        pick = {"camo": vlabel, "from": "%s's own %s" % (c[4], c[3]), "source": c[3],
                                "entry": c[5], "textures": got[0], "copy": got[1], "made": []}
                        chosen = c
                        break
                if pick is None and vtag in SHEET_TOKENS and isinstance(cur, list) and not ours(cur) \
                        and len([t for t in cur if isinstance(t, str)]) == nsel:
                    pick, chosen = family_pick(r, vtag, vlabel, mk, [t for t in cur if isinstance(t, str)], cands)
                if pick is None and gap == "leave":
                    # nothing of that scheme for this model: its own plainest scheme, copied as it is
                    # (user, 2026-09-21: "juat use trhe default fucking olive")
                    # a longer set is cut to the vehicle's count, as the game itself pairs them by index: the
                    # Prowler's Olive names six sheets for its four selections, the HEMTT's four for three
                    for c in sorted((c for c in cands if readable(c[6]) and len(c[6]) >= nsel
                                     and not any(MARKED.search(CP.clean(t)) for t in c[6] if isinstance(t, str))),
                                    key=lambda c: (plain_rank(norm(c[3]), vtag), c[2])):
                        if plain_rank(norm(c[3]), vtag) > 2:
                            # an arid faction takes a sand scheme or none: letting anything else through is what
                            # put Dazzle and Green on the EU arid (user, 2026-09-21: "clown cars")
                            continue
                        got = copy_set(list(c[6])[:nsel], TAG_OWNER[vtag])
                        if got:
                            pick = {"camo": vlabel, "from": "its own %s (%s), copied" % (c[3], c[4]),
                                    "source": c[3], "entry": c[5], "textures": got[0], "copy": got[1], "made": []}
                            chosen = c
                            break
                if pick is None and gap == "leave":
                    left.setdefault("no %s scheme for this model, left in its own paint" % want.title(),
                                    []).append(r.name)
                    continue
            if pick is None and vtag in MODIFY:
                how, names = MODIFY[vtag]
                for c in sorted((c for c in cands if readable(c[6])), key=lambda c: c[2]):
                    if norm(c[3]) not in names and norm(c[1]) not in names:
                        continue
                    if len(c[6]) != nsel:
                        continue
                    got = realise(c[6], vtag, mk, vtag == "trarid", MASKS.get(mk), modify=how)
                    if got:
                        pick = {"camo": vlabel, "from": "%s of %s (%s)" % (how, c[3], c[4]), "source": c[3],
                                "entry": c[5], "textures": got[0], "copy": [], "made": got[1]}
                        for j, made1 in enumerate(got[1]):
                            show("%s - %s #%d" % (r.name.split("_", 2)[-1][:26], vlabel, j), (str(made1[0]).lower(), vtag), r.name)
                        chosen = c
                        break
            if pick is None and vtag in EU_COLOURS:
                pick, chosen = eu_pick(r, vtag, vlabel, mk, cands, readable, rank)
            if pick is None:
                for c in sorted(cands, key=rank):
                    if not readable(c[6]) or not any(is_co(CP.clean(t)) for t in c[6] if source_of(t)):
                        continue
                    if preferred(c):
                        c = c[:6] + (list(c[6])[:nsel],)
                    if nsel and len(c[6]) != nsel:
                        continue
                    got = realise(c[6], vtag, mk, vtag == "trarid", MASKS.get(mk))
                    if got:
                        pick = {"camo": vlabel, "from": "made from %s (%s)" % (c[3], c[4]), "source": c[3],
                                "entry": c[5], "textures": got[0], "copy": [], "made": got[1]}
                        for j, made1 in enumerate(got[1]):      # every texture: wheels may sit on the second
                            show("%s - %s #%d" % (r.name.split("_", 2)[-1][:26], vlabel, j), (str(made1[0]).lower(), vtag), r.name)
                        chosen = c
                        break
            if pick is None and vtag in MOD_SCHEME and MOD_SCHEME[vtag][-1] == "leave":
                # copy-only camo: nothing is made for it, so a vehicle with no sheet to copy keeps its own paint
                left.setdefault("no sheet of that scheme to copy, left in its own colours", []).append(r.name)
                continue
            if pick is None:
                left.setdefault("no readable paint to start from", []).append(r.name)
                continue
            if plane and mk not in MASKS:
                left.setdefault("a plane whose underside could not be read (no light underside)", []).append(r.name)
            # Every painted vehicle offers at least its OWN camo. Without an entry here it got
            # `textureList[] = {};` and no TextureSources at all, which stops BIS_fnc_initVehicle repainting
            # over the camo but also empties the texture dropdown - the EU, Russian and Turkish vehicles lost
            # their texture selection that way (user, 2026-09-16: "you have broken the texture sleection for
            # nasto vechicles"). China kept a menu only because it was the one faction offering alternatives.
            offers = list(options) + (RUSSIAN if options and "qav_" in r.name.lower() else [])
            if vtag not in offers:
                offers = [vtag] + offers
            if offers:
                opts = []
                for ot in offers:
                    if ot == vtag:
                        opts.append({"class": "jmfsb_camo_" + ot, "name": TAGS[ot], "ours": True, "textures": list(pick["textures"])})
                        continue
                    got = realise(chosen[6], ot, mk, False, MASKS.get(mk))
                    if got:
                        opts.append({"class": "jmfsb_camo_" + ot, "name": TAGS[ot], "ours": True, "textures": got[0]})
                        show("%s - %s" % (r.name.split("_", 2)[-1][:28], TAGS[ot]), (str(got[1][0][0]).lower(), ot), r.name)
                for kk, e in own_ts.items():            # the paints it had, kept in the menu
                    # ...but not the camos an earlier run of this script wrote into that same menu. Once the
                    # class table is read from configs we have already painted, they come back as if they were
                    # paints the vehicle shipped with, and get listed a second time - the engine merges the two
                    # same-named classes and HEMTT reports every property in them as L-C02 duplicates.
                    if e.name.lower().startswith("jmfsb_camo_"):
                        continue
                    tx = [x for x in (e.props.get("textures") or []) if isinstance(x, str)]
                    if tx:
                        dn_ = VB.resolve_str(e.props.get("displayname", e.name)) or e.name
                        au_ = VB.resolve_str(e.props.get("author", "")) or ""
                        opts.append({"class": e.name, "name": dn_ if not str(dn_).startswith("$") else e.name,
                                     "author": au_ if not str(au_).startswith("$") else "", "textures": tx})
                # A camo that is exactly a paint the vehicle ALREADY offers needs no entry of its own: the
                # tropical Iran wears the game's green hex, so every vehicle got an "Iranian Green Hex" beside
                # the identical "Green Hex" (user, 2026-09-21: "why the fuck did you do that extra fucked up
                # step"). Point the default at the entry that is already there and drop ours.
                def norm_t(x):
                    return str(x).strip().lstrip(BS_).replace("/", BS_).lower()
                mine = [norm_t(t) for t in pick["textures"]]
                twin = next((o for o in opts if not o.get("ours")
                             and [norm_t(t) for t in o.get("textures", [])] == mine), None)
                if twin is not None:
                    opts = [o for o in opts if not (o.get("ours") and o["class"] == "jmfsb_camo_" + vtag)]
                    pick["default"] = twin["class"]
                    STATS["camo already in the vehicle's menu"] = STATS.get("camo already in the vehicle's menu", 0) + 1
                else:
                    pick["default"] = "jmfsb_camo_" + vtag
                pick["options"] = opts
            rows[r.name] = pick
            if plan and norm(pick["source"]) not in plain:
                print("   not plain: %-44s %-34s" % (r.name.split("_", 2)[-1][:44], pick["from"][:34]))
            counts["made"] = counts.get("made", 0) + 1
        for pat, spec in dict(MANUAL, **MANUAL_BY_ADDON.get(addon, {})).items():
            sib_pat, sels, take = spec[:3]
            pool_rows = old["camo"].get(spec[3], {}) if len(spec) > 3 else rows
            for k in sorted(g):
                r = g[k]
                if r.folder != addon or not re.search(pat, r.name):
                    continue
                if preview and not any(p.lower() in r.name.lower() for p in PREVIEW):
                    continue
                sib = next((n for n in pool_rows if re.search(sib_pat, n) and n != r.name and pool_rows[n].get("textures")), None)
                if all(isinstance(i, str) and i != "tile" for i in take):
                    # every sheet named outright (the medevac): nothing of a sibling's is taken, its menu and default
                    # included - a sibling's default may be a paint of its own the medevac would be repainted in
                    sp = {"camo": TAGS[tag], "source": "named sheets", "entry": "hiddenSelectionsTextures",
                          "textures": [], "default": "jmfsb_camo_" + tag,
                          "options": [{"class": "jmfsb_camo_" + tag, "name": TAGS[tag], "ours": True, "textures": []}]}
                    sib = "the named sheets"
                elif sib is None:
                    left.setdefault("no sibling painted to take selections from", []).append(r.name)
                    continue
                else:
                    sp = pool_rows[sib]
                d_ = sp.get("default") or ""
                vt = d_[len("jmfsb_camo_"):] if d_.startswith("jmfsb_camo_") else tag

                mk_r = CP.model_key(VB.value(table, r.name, "model"))
                made_r, copy_r = [], []

                def taken(texs, ot):
                    got = []
                    for i in take:
                        if i == "tile":
                            t = None if (plan or preview) else make_tile(ot)
                            got.append(t or "#(argb,8,8,3)color(0.5,0.5,0.5,1)")
                        elif isinstance(i, str):
                            # a source sheet of the vehicle's own (the EF Hunter's module sheets). A copy-only camo
                            # takes it as it is; any other paints it in that camo.
                            one = None if (plan or preview) else (
                                copy_set([i], TAG_OWNER.get(ot, addon)) if copy_only(ot) else realise([i], ot, mk_r, False, None))
                            got.append(one[0][0] if one else "#(argb,8,8,3)color(0.5,0.5,0.5,1)")
                            if one and not copy_only(ot):
                                made_r.extend(one[1])
                            elif one:
                                copy_r.extend(one[1])
                        else:
                            got.append(texs[i])
                    return got
                pick = {"camo": sp["camo"], "from": "by selection name, as %s (parent unreadable)" % sib.split("_", 2)[-1],
                        "source": sp["source"], "entry": sp["entry"], "selections": sels,
                        "textures": taken(sp["textures"], vt), "copy": copy_r, "made": made_r,
                        "default": sp.get("default")}
                pick["options"] = [dict(o, textures=taken(o["textures"], o["class"].replace("jmfsb_camo_", "")))
                                   for o in sp.get("options", [])
                                   if o.get("ours") and len(o["textures"]) > max([i for i in take if isinstance(i, int)] or [-1])]
                rows[r.name] = pick
                counts["by name"] = counts.get("by name", 0) + 1
                for why, cs in list(left.items()):
                    if r.name in cs:
                        cs.remove(r.name)
        print("== %s -> %s%s: %s" % (addon, label, (" (+ menu: %s)" % ", ".join(TAGS[o] for o in options)) if options else "",
                                     counts))
        for why, cs in left.items():
            print("   left as is, %s: %d  e.g. %s" % (why, len(cs), ", ".join(c.split("_", 2)[-1] for c in (cs if os.environ.get("CAMO_ALL") else cs[:6]))))
        if not preview and not plan:
            if PLANES_ONLY or NAMES:          # the planes only, or named classes: every other vehicle keeps its entry
                rows = dict(old["camo"].get(addon, {}), **rows)
            old["camo"][addon] = rows
            if addon in old["hide"]:
                old.setdefault("unhide", {})[addon] = old["hide"].pop(addon)
    print("stats:", STATS)
    if SHADE:
        lv = sorted(SHADE.items(), key=lambda kv: kv[1][2])
        print("shade over %d made sheets: paint mean before %.3f..%.3f, gain %.2f..%.2f, after %.3f..%.3f (median %.3f..%.3f)" % (
            len(lv), min(v[0] for _k, v in lv), max(v[0] for _k, v in lv), min(v[1] for _k, v in lv),
            max(v[1] for _k, v in lv), lv[0][1][2], lv[-1][1][2], min(v[3] for _k, v in lv), max(v[3] for _k, v in lv)))
        for k, v in lv[:3] + lv[-3:]:
            print("   %-70s before %.3f gain %.2f after %.3f%s" % (k[-70:], v[0], v[1], v[2],
                  ("  IQR %.3f x%.2f" % (v[4], v[5])) if len(v) > 4 else ""))
    if PINK:
        print("!! PINK in %d made sheets:" % len(PINK))
        for rel, frac in PINK:
            print("   %.3f%%  %s" % (100 * frac, rel))
    if plan:
        return
    if preview:
        tile, per = 256, 3
        n_rows = (len(sheet) + per - 1) // per
        img = Image.new("RGB", (tile * 2 * per + 24, (tile + 20) * max(1, n_rows)), (20, 20, 20))
        d = ImageDraw.Draw(img)
        for i, (lab, before, after, _cls) in enumerate(sheet):
            x, y = (i % per) * (tile * 2 + 12), (i // per) * (tile + 20)
            img.paste(Image.open(before).convert("RGB").resize((tile, tile), Image.BOX), (x, y))
            img.paste(Image.open(after).convert("RGB").resize((tile, tile), Image.BOX), (x + tile, y))
            d.text((x + 4, y + tile + 3), lab, fill=(255, 255, 255))
        img.save(os.path.join(SP, "camo_preview.png"))
        print("preview:", len(sheet), "textures ->", os.path.join(SP, "camo_preview.png"))
        return
    json.dump(old, open(MAP, "w", encoding="utf-8", newline="\n"), indent=1, ensure_ascii=False)
    print("made %d textures; map -> %s" % (len([v for v in made_by.values() if v]), MAP))


if __name__ == "__main__":
    main()
