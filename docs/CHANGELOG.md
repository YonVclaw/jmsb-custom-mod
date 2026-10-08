# Change notes

Assembled from `docs/tofix.md`, the dated `(user, 2026-08-xx …)` markers the code
carries, the faction generators' own notes and the release zips. Builds are the
`jmfsb-0.1.0.<build>` numbers on the release.

## 30 - 31 August 2026 (builds 929 - 933)

### The deploy caught up with the source (build 930)

The folder the game actually loads, `@1st Joint Multi-Functional Strike Battalion Custom`, was a build 903
copy that had been written to by plain file copies - so every PBO any earlier
build had put there was still in it, and still loading. Seventeen addons deleted
from the source in the 29 August rework were among them, all inheriting classes
that left with E22 and EUDF35: a 42 MB RPT, about 335,000 `No entry ... .side`
warnings. `jmfsb_fa_tiers_mods` was being skipped outright, because the orphan
`jmfsb_fa_e22raf` it required could not load either.

- **Deploys mirror now.** `robocopy /MIR` per subfolder (`addons`, `keys`,
  `optionals`), root files copied without it so Steam's `meta.cpp` survives. The
  17 orphans and 147 stale `.bisign` files are gone; the deployed set is the 153
  PBOs the source builds and nothing else.
- **The dev mission was repointed at what the mod ships.** ALiVE's OPCOM and ATO
  factions and the drone list moved from the deleted `jmfsb_PLA_wdl` to
  `jmfsb_China`; HIMF's supports moved from Atlas's trucks - gone with the
  rebuild - to the Pickup family; the tropical JTF's SDV, the ALiVE transport
  helicopter and the CAS aircraft took their current names; the four JSOC
  stealth uniforms name Atlas's originals now that our copies are gone.

### Everything that talks to the player goes through the notification panel (build 930)

- **The motor pool and the ACE vehicle spawner** were on `CBA_fnc_notify`, which
  ignores every `jmfsb_notify` setting a player has - corner, duration, size.
- **APS**, the **vector marker and waypoint**, the **breaching round**, the
  **40mm payloads** (decoy, jammer, multispectral screen, NR-P relay, UGS picket,
  EMP) and **evac** and the **Mk364 airburst setting** were on plain hints or
  ACE's `displayTextStructured`. All of them raise a jmfsb notification now,
  with the house colours - red for a refusal, green for a success, amber for a
  warning. `jmfsb_notify` is a required addon in the seven that gained it.
- Diagnostics stayed as they were: `systemChat` for the debug lines, `cutText`
  for the teleport fade, and the Endex splash, which the panel cannot carry.

### The PLA armour pack left the load order (build 933, 31 August)

- **The mission's six ALiVE lists** that named its vehicles - two AA class lists,
  two support lists, two supply lists - now name China's own: the Gyra AA, the
  S-750 and the Cronus radar for air defence, the ghex Tempest family for
  supports and supplies. The support and supply lists were keyed `OPF_F=` while
  the modules place `jmfsb_China`, so they had matched nothing since the faction
  was renamed; they are keyed to the faction now.
- **The APS fit table** dropped the fragments that only matched the pack and its
  CSAT-skin companion - `plz05`, `pll09`, `ztz`, `ztq`, `zbd`, `zbl`, `ztd`,
  `pgz`, `csk181`. `ztl` stays: that is QAV's Type 08, still loaded. `625e` was
  added, for the PGL-625E that took the PGZ-09's air-defence slot and was
  getting no APS at all. The GL-5 brand test read `"pla"` and had stopped
  matching anything; it reads `"china"` now.

### MOPP is out (build 933)

The crate left the mission's logistics table and the Zeus supply-crate module
(user). The crate model case, the two `mopp` unpack functions - already
uncompiled, their `PREP`s commented out - and their commented `PREP` lines went
with it. The item class stays commented out in `medbags`, with a note saying
what putting it back would need.

- **The Zeus supply-crate dropdown drew the wrong labels.** Its two lists are
  paired by index, and `crate_mopp` had left the type list while `MOPP Crate`
  stayed in the label list: TOW drew "MOPP Crate", the mortar box drew "Titan AT
  Box", and so on down to the Javelin label, which nothing could reach. Fixed.

### The JSOC and NCU uniforms are back, on the jmfsb prefix (31 August)

The 29 August rework deleted our JSOC Stealth and Euro NCU uniforms and pointed
the arsenal at Atlas's originals instead, keeping only the OCP and Snow paints
Atlas has no version of. **That was not what was wanted** (user: "no uniform was
supposed to be deleted and replaced with an Aegis/Atlas uni"), and the user
restored both addons from git.

- **The restore came back on the wrong prefix.** HEAD predates the 29 August
  rename, so `jmfsb_uniform` and `jmfsb_uniform_eu` returned as `m·m·x·l_*`
  while the rest of the mod is `jmfsb_*` - the include path, the `$PBOPREFIX$`,
  every class and six texture filenames. Repaired by the same method the
  original sweep used: byte-level replace over 20 files so CRLF and encodings
  survive, then the six assets renamed after the text pass so the references
  written already named them.
- **Both models are MLOD and were proved before being touched.** All 104,566
  occurrences across `U_CombatUniformNCU_01.p3d` and `_02.p3d` were checked to
  sit inside printable NUL-bounded path strings - four distinct paths per model,
  none outside a run - which is what makes a length-changing replace safe in a
  format with no offset tables. `hemtt check` validating **6** files for
  binarization where it validated 4 is the proof it worked.
- **18 uniforms back**: `jmfsb_uniform_U_B_{,D_,T_,W_,OCP_,Snow_}JSOC_Stealth
  Uniform_F` and their rolled-up pairs, and `jmfsb_uniform_eu_U_CombatUniform
  NCU_0{1,2}_{mcam,mcam_wdl,ocp}_F`. Their XtdGear came back with them, so the
  JSOC model carries all six camos and the NCU model all three.
- **The arsenal names ours again.** The twelve `Atlas_*` rows in
  `items_uniforms.hpp` are `jmfsb_uniform_*` and `jmfsb_uniform_eu_*`; all 226
  jmfsb uniform and vest rows the mission names were checked against what the
  mod defines, and none dangles. Atlas is still named in `uniform/CfgWeapons.hpp`
  for the icon paths, which is a texture reference, not a copy.

### Jamming split into radio, data and GPS (31 August)

One emitter denied everything, so "you are jammed" was all a player could learn
and all the system could say. It is three domains now (user), each asked about by
name, each with its own emitter, and each losing you something different.

- **`jamFactor` takes a domain, not a mode.** Every zone carries a `domains`
  list; a zone with none set carries radio and data, which is what one emitter
  denied before, so an untouched mission behaves exactly as it did. `radio` is
  the voice net, `data` is TAC//MSG and the map, `gps` is the receiver, `uav` is
  unchanged and still reads the `jamUavs` flag, and `any` is the question the
  meter and the EW scanner ask - "is the spectrum dirty at all". `linkState` asks
  for data, `jammerLoop` for radio, the scanner for any.
- **0.75 is one number.** Where the handset says DENIED, where the meter turns
  red, where the GPS comes off and where keying up counts as burning through are
  the same band, named once as `JAM_DENIED_BAND`.
- **Every site rolls its own reach, 1000-3000 m** (user: "radius is too small,
  they need to be 1000 to 3000 random number"). The module's two radius
  attributes are the BOUNDS now, not a hub figure and a terminal figure - a
  300 m field was a building's worth of ground and a player walked out of it
  without noticing. The domain still follows objective size; the reach does not,
  so two masts of the same kind are not the same problem.
- **The state word is NONET, not DENIED** (user), on the handset, the tacpad
  panel header, the JAM app's three rows and the meter.
- **LOCATE JAMMER runs the artillery ladder** (user: "add these sites to the
  intel like the arty and aa sites"). It used to plot every emitter as icons in
  one go - no narrowing, no lock, and no spotrep, so a located jammer never
  reached the COP. It now takes the same `ladderCircle` artillery and air
  defence take, which tightens with each hack, holds its lock until that site is
  dead, and files intel through the adapter. The zone carries its owner's side
  for it; the registry never needed one before. The COP has no
  electronic-warfare type, so a mast files as `unknown` - a structure the
  commander can see and cannot classify.
- **A site is three props** (user): a terminal that says what it denies and IS
  the emitter, plus an omnidirectional antenna and a satellite dish rolled from
  three colours each. The dressing carries nothing - it is there so a site reads
  as a site from three hundred metres rather than as a lone box on a hillside.
  `RuggedTerminal_01_communications_hub_F` denies GPS, `RuggedTerminal_01_F`
  data, `RuggedTerminal_01_communications_F` radio.
- **Every site is an ALiVE objective now** (user), so the commander garrisons
  what it owns. Through `adapter_alive_fnc_registerSite`, which already existed
  and already owned the dedup and the rule that an asymmetric commander is not
  handed a fixed installation to turn into an IED factory.
  `tools/check_invariants.py` caught the first cut calling `ALiVE_fnc_OPCOM`
  direct, and then caught it a second time *in a comment* - the seam is enforced
  on the text of the file.
- **Data denial takes BFT with it.** A tracker arrives over the link TAC//MSG
  uses, so `bft_fnc_draw` drops every group but your own when the link reads
  DENIED - your own member marks survive, which is self location on with the
  net picture gone. The state comes from `messaging_fnc_linkState` rather than a
  second copy of the band, so the handset and the map cannot drift apart.
- **GPS is space-based, and there is one of it.** No mast over the ground it
  denies: **one** uplink on the whole map (user) steers a 1 km or 2 km sphere
  that wanders, turning at the world edge and re-rolling its heading - weather
  rather than terrain. It is the only field a player cannot walk out of and wait
  out, so the answer is the uplink, which is findable, garrisoned and hackable
  like any other site. Kill it and the sphere goes with it, for good.
- **The GPS effect strips the item.** Radio and data denial are gradients; GPS is
  not - the engine either draws the receiver or it does not. `gpsApply` unlinks
  what the player is carrying and gives back exactly what it took, off a class
  list rather than a config dependency, so a vanilla `ItemGPS` looted mid-mission
  is denied too. **The map self-icon goes with it**, which is the point:
  `mapContent = 0` in the difficulty preset means that icon comes only from
  carrying a GPS.
- **The meter shows all three** (user). RADIO / DATA / GPS, each `OK` bone,
  `DEG` amber or `OUT` red with its own bar, all three drawn whenever the panel
  is up. A single bar stopped meaning anything the moment the terminal could
  take the net without touching TAC//MSG.
- **Burning through is answered, not rolled for.** A set powerful enough to
  punch a hole in a radio field does so - and `jmfsb_reaction` skips the
  detection ladder and goes straight to MAJOR plus a QRF on the transmitter
  (user: "more powerful radio can cut through but will get a QRF"). Two reads of
  the field, bare and with the set's power, so a low-powered radio in the same
  place raises an ordinary contact and only the man who reached for the big
  antenna pays.
  - **The burn-through model had never run.** It was a preInit variable with no
    setting and no module attribute - off everywhere, in every mission, since it
    was written. It has a **Radio Burn-Through** checkbox and a reference-power
    field on the module now, along with **GPS Denial** and **Uplink Radius**.
- **Two bugs hemtt found on the way**: `getVariable [...] max (...)` parses as
  `getVariable ([...] max ...)` because `max` binds tighter, and a `forEach`
  binding `_x` over a `params ["_x","_y"]` corner fed an array to the position
  maths.

### The 31 August JAM SOF additions (31 August)

JAM SOF Equipment 2035 updated (`sof_characters.pbo` 26090102) with 37 new
items. All 37 verified against the derapified `Headgear`/`Uniforms`/`Vests`
configs out of the live PBO - every one `scope = 2` - and the day's ORBAT dump
confirms the updated PBO was the one loaded. **All 37 are remade as `jmfsb_*`
classes** (user: "treat them like the other existing jam sof helmets are
treated"), so every arsenal row names ours, not the mod's.

- **The reason it matters, and not only for consistency.** JAM SOF ships **no
  ACE property of any kind** - `grep -ric hearing` over the whole derapified
  `sof_characters` returns 0, in a config that puts a headset texture on the
  model 81 times. Left on the mod's classes, the four new Hi-Cut covers would
  have been the only ones in the arsenal without electronic hearing protection.
  Ours inherit the `_rgr` bases, where the family's `0.85 / 0.05 / hasEHP` lines
  live.
- **Four Hi-Cut covers**, alpine and USMC winter, plain and enhanced. The mod
  pairs both with the *sand* helmet and headset, not the green, and both those
  and the two accessory paints were already vendored - so
  `h_opscore_cover_alp_co.paa` and `h_opscore_cover_mrpt_win_co.paa` were the
  only new art.
- **The cold-weather set is a new garment on a new model.** It is a *pairing*,
  not a camo: `SOF_B_SFColdFatigues_mcam_gry` wears `U_ColdWeatherJacket_gry`
  over `U_FatiguesSF_Pants_mcam`, which is why its class names carry two. Six
  wearers on `U_UniformSpecCold.p3d` with `mcam_gry` as the base, six items, six
  editor proxies; in XtdGear it is its own model with **jacket** and **trousers**
  as separate axes. Six of the twelve combinations exist; the rest grey out, as
  they already do on the Hi-Cut. Plus the desert SF Fatigues pair, on the
  existing model with one new camo value - solid tan the way `RGR` is solid
  green.
- **The reworked AVS took a third axis and a real flag.** The mod's `_new`
  carriers are three new p3ds (`V_CarrierAVS_Lite_new`, `_Rifle_new`,
  `_Gunner_new`) with a third hidden selection - `camo1` is the pouches, `camo2`
  the flag patch - so they are their own base classes rather than variants of
  the Lite above them. A `cut` axis (Orig / Lite / Rifle / Gunner) keeps all 31
  on one arsenal entry; without it the reworked Lite would land on our
  retextures' camo/flag coordinate and shadow them. Black, coyote and sand join
  the camo axis.
  - **The Flag / NoFlag buttons finally pick out a difference.** The six
    original copies blank `camo1` on their flagged *and* their `_noflag` rows,
    so both wear no patch and the axis is decorative for them. The 25 new ones
    reproduce the mod: flagged rows wear `FlagPatch_us`, `_noflag` rows blank
    the slot. The six were left alone - changing them would put a flag on kit
    players already have saved.
- **No `hiddenSelectionsMaterials` on the cold set or the new AVS**, matching
  the mod, so the p3ds' own materials apply and the cold jacket's rvmat and the
  pouch rvmat did not have to be vendored.
- **Art vendored**: 8 files into `uniform_sof\data\` (two cover paints, two
  desert paints, three cold jackets, two cold trousers, the cold set's UI icon)
  and 11 into `vests_sof\data\` (three carrier paints, seven pouch paints and
  the flag patch). Everything else the 37 need was already there.
- **Into the arsenals**: the twelve helmets and uniforms in the common arsenal
  beside the SOF gear already there; the 25 AVS carriers in the four squad
  arsenals that carry the family - JMSB, Reaper, Talon and Wraith. All 37 rows
  read `jmfsb_uniform_sof_*` or `jmfsb_vests_sof_*`.

### The Rapier battery moved to Turrets (31 August)

RKSL files every Rapier FSC piece under its own editor heading - `vehicleClass`
`RKSL_UK_GBAD`, `editorSubcategory` `RKSLA3_UK_GBAD_SUBCAT`, Ground Based Air
Defence - and our eighteen copies (launcher, Blindfire FCR and Dagger SR across
the two Chinas, Iran and the three Russias) inherited both, so they sat on a
shelf of their own instead of with the rest of the statics (user).

- **All eighteen carry `vehicleClass = "Static"` and `editorSubcategory =
  "EdSubcat_Turrets"` now** - the same two lines, for the same reason, that
  `addons/antiship` already puts on its launcher and radar.
- **The generator writes them.** `EXTRA_UNITS` entries take an optional `props`
  list of raw config lines (comments included), emitted verbatim after `crew`;
  the Rapier entries pass `EDEN_TURRET`. A regeneration - or
  `tools/apply_faction_extras.py`, which shares `emit_extras` - produces what is
  on disk. CSAT, CSAT (Tropical), the three RAF theatres and the Insurgents
  carry the key too, so the fix survives if any of them comes back.

## 22 – 29 August 2026 (builds 836 → 900)

### 29 August, evening — the new preset (builds 901+)

E22 Northstar and EUDF35 left the load order; Aegis, Atlas, Atlas - Opposing
Forces, Athena, AddGis, Russia 2035 and the Aegis OCP retextures came back.

- **Prefix `mmxl` → `jmfsb`** across the mod, the models and the dev mission.
- **EUDF factions removed** (all three). **Russia factions removed** pending a
  dump with Russia 2035 in it. `fa_e22raf` and the three E22 magazine wells gone.
- **US Army JTF (all four theatres) rebuilt from the base game's own rosters**
  (`BLU_W_F`, `BLU_NATO_lxWS`, `BLU_T_F`) - which Aegis extends in the load
  order - with QAV armour, NATO air and artillery, the GX drones and the base
  game's Praetorian where E22's JC air defence was. Names unchanged, so the
  mission's motor pool still works (its E22 boats now name the JTF's own).
- **HIMF on Atlas's own HIMF**: every man inherits `Atlas_B_H_*` (uniform, vest,
  helmet, M16A4 / XMS, packs), FA t2 rounds kept; E22's Pandurs gone (Atlas's Otokar ARMAs
  stood in for a night, removed 30 August - the Gyras are the armour); the vendored HIMF textures and kit tables are gone.
- **The AddGis G433 family folds in the arsenal** (user): one XtdGear model in
  `jmfsb_weapons`, camo (Black / Khaki / Sand) on one axis and configuration
  (plain / grip / GL) on the other, laid out like the MX family beside it -
  nine rifles become one entry with two rows of buttons. All nine were already
  in JMFSB's group arsenal; only the model was missing.
- **E22's Joint Command air defence, back on the US factions** (user, sorted by
  colour): the ADS-1 NASAMS, the ADS-2 Skynex and the JC radar - W on the
  woodland, tropical and Marine (Woodland) rosters, D on desert, OCP and
  Marine (Desert). Northstar left the load order on 29 August and `DROP_MODS`
  still refuses the prefix, but its **air-defence component is still loaded** -
  all 36 surviving E22 classes are JC SAMs, AAA and radars - so these six are
  excepted by name rather than the drop being weakened. They sit beside the
  base-game Praetorian, not in place of it.
- **Emplaced weapons, on request** (user, 30 August): the Syndikat gains ACE's
  M47 Super-Dragon, the Mk6 mortar and both SwitchBlade launch tubes (the
  tier-0 "no artillery" rule now excepts that one mortar by name); HIMF gains
  the Commando Mortar, the olive Mk6, the Super-Dragon, both SwitchBlade tubes
  and GX's Hunter SP launcher; the two Chinas and the three Russias gain the
  anti-ship battery (Iran already had it - `addons/antiship` files it under
  `OPF_F`); and every east faction gains RKSL's Rapier FSC battery - launcher,
  Blindfire and Dagger - each with the east autopilot.
- **A borrowed static kept its source's crew.** `pick_crew` only matches men
  whose class name says crew or pilot, and the Syndikat has neither - so its
  Super-Dragon and SwitchBlade tubes spawned a **NATO rifleman** inside them.
  A faction with no crewman now falls back to its own base man.
- **Syndikat loses three inherited vehicles** (user): Aegis's two I_C Stompers
  and its ZU-23. All three came in with `IND_C_F`, none was in a group, and a
  tracked armed robot and a towed AA gun are not tier 0 kit. 45 -> 42 units.
- **The two Chinas gain RKSL's Hermes 450** (`rksla3_uav_h450_2`, user). The
  "Hermes 450 is ind" rule still refuses it to CSAT, Russia and the PLA;
  China is deliberately not on that list.
- **HIMF gains four drones** (user): RKSL's RQ-7 Shadow 200 and Aeroshark Mini
  UAV, and GX's MAGURA V5 USV and RQ-11B Raven - all forward-declared like
  every outside parent. The Raven is on the dump generator's players-only
  list (hand-launched, no AI can fly one); HIMF is built by hand and was
  asked for it, so it has one.
- **Config patches that were wiping other mods' inheritance** (found in the
  30 August RPT, `Updating base class 'X'->''`): eight ACE medical actions
  (`ElasticBandage`, `PackingBandage`, `QuikClot`, `Morphine`,
  `CheckBloodPressure` and the three bandages under `Bandaging`) were reopened
  with no parent, which strips everything ACE put on them; the static Titan
  tube had lost `missiles_titan`; the AbramsX autocannon's `HighROF` had lost
  `HE`; and the `hd_dot` / `mil_objective` markers had lost `Flag`. All now
  name their parent.
- **Six new factions** (user, 30 August):
  - **2040 China** (`OPF_T_F`) and **2040 China (Desert)** (`OPF_CD_F`), peer+ /
    tier 4, in the JAM SOF green-hex and hex sets with the CTAR family by unit
    type and the 5.8 DBP39 round. The two sources were 218 units / 64 groups
    against 60 / 9, so both are built from the tropical order of battle and the
    desert force borrows what it has no equivalent of - **165 units and 64
    groups each, role for role**.
  - **2040 Iran** (`OPF_F`), peer / tier 3, in Aegis Gear Overhaul's Iranian
    digital set, AK-103s with an ARCO, RPK-12 machine guns and SVDs, coyote-brown
    packs, 7.62x39 7N47 CT rounds.
  - **2040 Russia / (Arid) / (Arctic)** (`OPF_R_F`, `OPF_R_ard_F`,
    `CF_OPF_R_A_F`), peer / tier 3, copied as they ship - what they gain is the
    2040 label, the east drone allocation, the future 5.45 round and **one
    order of battle: 60 groups each** (they shipped 60 / 41 / 38), each
    resolved into that theatre's own men.
- **Two whole class families were being discarded as "a dropped mod's"**: the
  Arctic factions' 338 `CF_*` classes (a mod the generator had never been told
  about - 2040 Russia (Arctic) was being built almost entirely from borrowed
  woodland men) and Contact's `O_R_*` Russians (base game, but absent from the
  vanilla index, which cost 2040 Russia its mechanised squads and diver team).
- **Every faction now carries future ammunition.** Two things were stopping it:
  `gen_fa_tiers.py` still listed `fa_aegis` and `fa_atlas` as dead from when
  those mods were out of the load order (so the only future build of the AK-12
  5.45 was never tiered), and three candidate loads for that magazine was a tie
  the chooser could not break. Tier 0 (Syndikat) has no future round by design.
- **A stale index was thinning every Pacific faction.** `class_origin` calls
  anything the vanilla index does not know "dropped", and that index is built
  from an unpacked a3 tree with no Apex classes in it - so the tropical rosters
  lost their statics, transport helicopters and planes without a word. The
  dump's own parent chain is consulted before a class is called dropped; the US
  JTF factions gained 30-60 units each as a result.
- **PLA camo removed**: `addons/uniform_pla` - 170 vendored ACP Xingkong
  classes and 74 MB of textures - went with the two PLA factions that wore
  it. Kept whole in `backup/uniform_pla_removed_2026-08-30/`, and
  `tools/gen_pla_kit.py` can rebuild it from the ACP pack.
- **Gendarmerie re-armed** (user's two loadout arrays): the JCA UMP is gone -
  the rank and file carry AddGis's M16 carbine with the MK7 (visor up), the
  commander Aegis's M4A1 with the beret, both with the G17 in place of the
  P07. One magazine each, frag, smoke and a first aid kit; no NVGs.
- **One order of battle for the four JTF theatres** ("make sure all the jtf
  factions have the same groups"): woodland shipped 6 groups, desert and OCP
  36, tropical 45 - because their source factions differ that much. All four
  now carry the same **47 groups** in the same seven categories, built from
  BLU_T_F's order of battle with every man resolved into that theatre's own
  class by role. Where a theatre has no equivalent (woodland has no recon,
  divers or sniper of its own) the tropical man is borrowed and re-dressed in
  the theatre's kit. The two UGV groups are the only ones dropped, in all four.
- **Nine factions removed** (user: only the US stays - plus HIMF, Syndikat and,
  restored on 30 August, the Gendarmerie; the Marines and MFRC are US too): CSAT Iran (both),
  Insurgents, AAF, LDF, FIA (both), PLA (both). Backed up whole under
  `backup/factions_removed_2026-08-29/`; their generator lines are commented
  out, not deleted. The Roomba mission's ALiVE OPFOR (OPCOM, ATO, placement,
  supplies, AA, drone lists) moved from `jmfsb_PLA_wdl` to the base game's
  `OPF_F` with the PLA mod's own vehicles and the mods' own drones.
- **HIMF air arm without EUDF35**: the AT-27M35 Tucano (Embraer EMB 312 mod,
  grey) and Atlas's HIMF Caesar BTT are the only planes; Atlas's own HIMF EC-04
  / EC-03 take the transport slots the EUDF Wildcats held.
- **Copies of Aegis / Atlas removed, links put back**: the FAST-MT models and
  the tan / RGR / black / coyote helmets (Aegis's), the plain / desert / tropic /
  woodland JSOC uniforms (Atlas's), the NCU models and Multicam paints
  (Atlas's). Our own paints on them inherit the originals; the mission arsenal
  names `Aegis_*` / `Atlas_*` for the rest. Gendarmerie's E22 vest → the base
  game's plate carrier; the mission's four E22 air-defence objects → the base
  game's SAM, AAA and radar.

### 29 August — builds 876–900

**Arsenal**
- **Ammunition folded by round type.** One row per round type in one magazine
  form (`100Rnd 6.5mm Mk328`, `30Rnd 5.56 Mk332 AP` …) and, under the list, the
  same option panel the attachments get: Tracer (Ball / Red / Green / … / IR),
  Finish (Black / Khaki / Tan …), Colour for smoke, flares and chemlights.
  1033 magazines → 243 rows. Picking a variant loads it.
- **JCA dual mount on the MX and the SPARs.** The MX reads the base game's own
  side rail, which CBA Joint Rails never touches; the mount is now registered
  there as well as on the SPARs' rail. The same addon had also been stripping
  every 7.62 suppressor off the MX's 6.5 slot — restored.
- **Khaki 30Rnd 6.5 EPR** magazines added to the arsenal list (the one 6.5
  family that was missing a finish).

**Vehicles**
- **APS map panel.** On the map, in a fitted vehicle: every fitted vehicle you
  are entitled to see (own / group / side — a setting), its charges, its
  emitter, and HK HOLD · RF HOLD · BURST. Holds are shared state; the HUD tile
  shows them. The HUD APS tile and the panel are gone entirely on foot.
- **APS arms itself** from its settings; the JMSB - APS module is an override
  and now applies even when placed after the settings armed the system.
- **Motor pool** closes the moment the vehicle is on the pad.
- **Enemy Drones module: airframes per side.** West / East / Independent each
  get their own ceiling (-1 = shared number, 0 = grounded).

**Weapons**
- **MX family and Mk200 run cooler under ACE** — explicit barrel mass at 2× the
  game's fallback, so every round adds half the heat and the sustainable rate
  of fire under the 180 °C cook-off line doubles. No inventory-mass change
  (the earlier "mass gain" was being overwritten by ACE realistic weights).

**Factions**
- **HIMF air arm**: the one plane is the EUDF's A-149 Gripen; helicopters are
  the MH-9, AH-9, RF's WY-55 Hellcat and the EUDF's WY-55 Wildcat (armed and
  unarmed). Black Wasp, Caesar BTT, Blackfish, Ghost Hawk, Huron and Blackfoot
  removed.
- HIMF: Mk-I EMR for the marksman; auto rifleman's support weapon corrected;
  armour is EF's Gyra and E22's Pandur; HIMF-specific kit tables moved out to
  `backup/himf_frce_2026-08-29` (E22 woodland kit worn instead).

**Interface**
- Diary menu restored on the map. Modal dialogs opaque (0.95) and OK-only.
- `hemtt check` clean — zero lints, help level included.

### 28 August — builds 853–875

**Factions**
- **US Army JTF**: E22's air arm dropped in favour of NATO's aircraft (Little
  Birds, Ghost Hawks, Hurons, A-10D, Black Wasp) and NATO artillery; armour is
  the M3A1/A2/A3 Knights only; the tropical theatre is green throughout; a
  common vehicle set (Marshall, ATGM Marshall, Blackfish) in every JTF.
- **HIMF rebuilt on the base game**: all 11 RF Ram 1500 variants in Jungle
  paint (no HEMTTs, no M-ATVs — the pickups are the transport), XMS rifles at
  FA tier 2, the old HIMF's olive vests and helmets, Atlas's HIMF paint vendored
  onto base-game headgear and vests (textures only), Speedboat Minigun.
- **CSAT → "2040 CSAT Iran"** (both theatres): Persian identities, RF ASh-12
  rifles with 12.7×55 FA loads, Navid MMG with a proper magazine well.
- **PLA (Arid / Woodland)** from the PLA mod: 32 vehicles indexed, ACP Xingkong
  kit vendored, Contact modular helmets, ARX for leaders, Katiba for the line.
- **Squad drones**: a drone operator in every rifle/motorised/mechanised squad
  per `docs/weapon_pools_2040.md`; East squads get a SwitchBlade operator.
- Blood type on the admin panel's player card.

**Systems**
- **ACRE radio mesh** (`jmfsb_radio_mesh`): manpacks and vehicle racks relay for
  their own side; jamming folded into the same signal path.
- **APS** (`jmfsb_aps`): Drongo-style hard kill rebuilt in-mod, fitted by
  faction tier (basic → enhanced; Trophy / Afganit / Iron Fist / GL-5), plus
  the RF burst — a microwave pulse that strips guidance, drops drones and jams
  nearby radios.
- **ACEAX attachment compat** (`jmfsb_aceax_attachments`): 58 entries over 233
  optics, cans, pointers and bipods fold behind dropdowns.
- **JCA rails** first pass: JCA bipods and cans on the MX/SPAR slots.

### 27 August — builds 849–852

- **Mod reduction begins**: Aegis and Atlas leave the load order. The faction
  generators drop their classes; KVN drones out; GX drones player-only.
- **US factions replaced by E22 Northstar's JTF** (`jmfsb_US_JTF_wdl / des /
  tna / ocp`), armour = QAV Knights + Marshalls; the four base-game US faction
  addons and the naval JTF deleted.
- **EUDF factions** (`jmfsb_EUDF / _arc / _ard`) from EUDF35, tier 3, with the
  Blackfoot.
- Five icons the mod was opening out of the mission moved in-mod; 23 forced
  settings under the dead `YMF_` prefix renamed; `hemtt check` made clean,
  `BIS_fnc_param` replaced.

### 26 August — builds 836–848

- Revisions across the ALiVE adapter, anti-ship, CAS, UAS, hacking, reaction,
  BFT and ambience addons (no dated notes were kept for these; the design they
  serve is `docs/new.md`).

### 22 August

- **futureAmmo ported in** as the `fa_*` addons under the mod's prefix (124
  files) and its four missed cross-references fixed.
- **Ammunition tiers**: the tier generator now covers all 695 FA rounds,
  tracer variants included (it had done 165); the tier-2 floor narrowed to
  penetration; `docs/AMMO_VANILLA.md` and `docs/AMMO_COMPARE.md` written;
  `fa_tiers` declares all 2863 external parents it inherits from.
- **Factions**: four `CfgVehicles` blocks in one addon had been dropping 114
  vehicles, 64 drones and the MAAWS gunner — fixed, and 414 generated classes
  added to `units[]` so Zeus can place them; the six US factions given proper
  groups; the generator's fixed filename list replaced with a scan.
- **HUD** slots sized to the vanilla Custom Info panel (they were twice it and
  the left slot sat off-screen); the jamming meter, which had never drawn,
  rebuilt on the mission display.
- `check_all.py` no longer dies when `hemtt` is missing; case-only addon
  renames (`hiteffects`, `safestart`) landed in git.
