# The 2040 factions

Everything under **2040 …** in the 3DEN and Zeus faction lists: 24 addons, 27
factions (`faction_jmsb` declares one). State as of 2026-09-29, read from the
shipped configs in `addons/faction_*`.

Every one of them is a **new faction beside its source**, never an edit of it.
The source faction is left exactly as its mod ships it, so a mission built on
the original is untouched and the two sit next to each other in the editor.

## At a glance

Side: **E** East/OPFOR (`side = 0`), **W** West/BLUFOR (`1`), **I** Independent
(`2`). Tier is the gear tier from `docs/weapon_pools_2040.md` (0 broke /
irregular, 1 funded, 2 near-peer, 3 peer, 4 peer+), read from the FA round the
men carry (`FA_*_t<n>` magazines). Men and vehicles are `scope = 2` classes;
groups are CfgGroups entries.

| 3DEN / Zeus name | Addon | Side | Source faction | Tier | Men | Vehicles | Groups | Vehicle camo |
|---|---|:---:|---|:---:|---:|---:|---:|---|
| 2040 US Army JTF (Woodland) | `faction_us_jtf_wdl` | W | `BLU_W_F` | 3 | 69 | 99 | 45 | NATO paints, green |
| 2040 US Army JTF (Desert) | `faction_us_jtf_des` | W | `BLU_NATO_lxWS` | 3 | 66 | 97 | 45 | NATO paints, tan |
| 2040 US Army JTF (Tropical) | `faction_us_jtf_tna` | W | `BLU_T_F` | 3 | 69 | 98 | 45 | NATO Pacific green |
| 2040 US Army JTF (OCP) | `faction_us_jtf_ocp` | W | `BLU_NATO_lxWS` | 3 | 66 | 97 | 45 | NATO paints, tan |
| 2040 Marine (Woodland) | `faction_marine_wdl` | W | `EF_B_MJTF_Wdl` | 3 | 44 | 69 | 45 | source's own |
| 2040 Marine (Desert) | `faction_marine_des` | W | `EF_B_MJTF_Des` | 3 | 44 | 69 | 45 | source's own |
| 2040 EUDF (Woodland) | `faction_eudf` | W | `BLU_F` | 3 | 85 | 128 | 45 | EU Woodland |
| 2040 EUDF (Arid) | `faction_eudf_des` | W | `BLU_NATO_lxWS` | 3 | 66 | 76 | 45 | EU Desert |
| 2040 EUDF (Arctic) | `faction_eudf_arc` | W | `CF_BLU_F` | 3 | 102 | 78 | 45 | EU Arctic |
| 2040 HIMF | `faction_himf` | W | Atlas `Atlas_B_H_*` | 2 | 44 | 35 | 20 | source's own |
| 2040 Gendarmerie | `faction_gen` | W | `BLU_GEN_F` | 2 | 10 | 13 | 4 | source's own |
| 2040 1st JMSB | `faction_jmsb` | W | built from `BLU_CTRG_F` | 3 | 1 | - | 1 | - |
| 2040 Russia | `faction_russia` | E | `OPF_R_F` | 3 | 67 | 76 | 60 | Russian Green |
| 2040 Russia (Arid) | `faction_russia_ard` | E | `OPF_R_ard_F` | 3 | 68 | 76 | 60 | Russian Sand |
| 2040 Russia (Arctic) | `faction_russia_arc` | E | `CF_OPF_R_A_F` | 3 | 62 | 70 | 60 | Russian Arctic |
| 2040 China | `faction_china` | E | `OPF_T_F` | 4 | 66 | 89 | 64 | Chinese Woodland Digital |
| 2040 China (Desert) | `faction_china_ard` | E | `OPF_CD_F` | 4 | 66 | 89 | 64 | Chinese Arid Digital |
| 2040 Iran | `faction_iran` | E | `OPF_F` | 3 | 75 | 102 | 76 | base-game Hex |
| 2040 Iran (Tropical) | `faction_iran_tna` | E | `OPF_F` | 3 | 75 | 102 | 76 | Iranian Green Hex |
| 2040 Turkey (Arid) | `faction_turkey` | E | Athena `Athena_OPF_T_F` | 4 | 77 | 55 | 64 | Turkish Arid |
| 2040 Turkey (Tropical) | `faction_turkey_tna` | E | Athena `Athena_OPF_T_F` | 4 | 77 | 55 | 64 | Turkish Green |
| 2040 Turkey (Arid) | `faction_turkey_ind_ard` | I | Athena `Athena_OPF_T_F` | 4 | 77 | 55 | 64 | Turkish Arid |
| 2040 Turkey (Tropical) | `faction_turkey_ind` | I | Athena `Athena_OPF_T_F` | 4 | 77 | 55 | 64 | Turkish Green |
| 2040 Syndikat | `faction_syndikat` | I | `IND_C_F` | 0 | 27 | 23 | 13 | source's own |

The faction class is the addon's `ADDON` macro: `jmfsb_faction_<addon suffix>`,
e.g. `jmfsb_faction_russia`; the 1st JMSB's is `jmfsb_faction_jmsb_ocp`. Units are `jmfsb_faction_<suffix>_<source class>`.
Turkey appears twice under each name, once East and once Independent. The
side in the editor tells them apart.

## What every generated faction has in common

These apply to every faction built by `tools/gen_us_factions.py`, which is all
of them except HIMF (`tools/gen_himf.py`) and the 1st JMSB (hand-written).

- **The source's order of battle.** Men, vehicles and groups follow the source
  faction's own roster. A source that ships no groups gets a template:
  Turkey uses the base game's Pacific CSAT order of battle (`GROUP_TEMPLATE`),
  and the Gendarmerie's four motorised groups are written from scratch
  (`EXTRA_GROUPS`).
- **Future ammunition.** Every magazine the FA index knows is swapped for the
  faction's tier of that round (`FA_<side>_<mag>_t<n>`). Syndikat, at tier 0,
  keeps the source's rounds.
- **Suppressors at tier 3 and up.** Each primary a man carries without a
  muzzle item gets a suppressed preset (the weapon's own MuzzleSlot can,
  colour-matched), in the addon's `CfgWeapons.hpp`. At tier 4 the sidearms get
  one too. These are the `_snds` classes in the tables below.
- **Drones in every squad.** Every infantry, motorised and mechanised squad has
  a Drone Operator, and its grenadier carries a second drone. What they carry
  follows the tier and side: see *Drone backpacks* in
  `docs/weapon_pools_2040.md`.
- **Three editor subcategories only.** Men file under Men, Men (Special
  Forces) or Men (Story). Duplicates a source keeps under other subcategories,
  such as CSAT's urban copies and RF's QRF men, are dropped.
- **No external mod dependency.** Every addon except HIMF requires only
  `jmfsb_*` addons (`jmfsb_main`, plus `jmfsb_uniform`, `jmfsb_vests`,
  `jmfsb_headware`, `jmfsb_weapons` and `jmfsb_vehicle` as it uses them).
  Aegis, Atlas and Athena classes the rosters named were replaced on
  2026-09-13 by the imported `jmfsb_vehicle_*` / `jmfsb_weapons_*` class where
  one exists, otherwise by the nearest base-game class of the same side and
  role (`tools/swap_faction_mods.py`). Every addon carries
  `skipWhenMissingDependencies`.

## West

### US Army JTF: Woodland, Desert, Tropical, OCP

The US Army of 2040, one force in four theatres, all at tier 3. Each is built
on the base game's own NATO roster for its theatre: woodland on `BLU_W_F`,
desert and OCP on Western Sahara's `BLU_NATO_lxWS`, tropical on `BLU_T_F`.

- **Rifles:** the MX family (MXC and MX with ACO/Holo, suppressed). Black
  furniture in woodland, khaki in tropical, mixed in desert/OCP.
- **Kit:** each source roster's own, except OCP, which wears the repo's OCP
  retextures (`jmfsb_uniform_U_B_CombatUniform_ocp_F`, `jmfsb_vests` plate
  carriers, `jmfsb_headware` FAST-MT and booniehat).
- **Armour:** QAV AbramsX and M3A1–A3 Knights, AMV-7 Marshall (the Badger IFV
  is renamed Marshall), M-ATV LAAD/AT/FSV, Polaris DAGOR. No Striders.
- **Air:** Little Birds, UH-80 Ghost Hawks, CH-47I Chinook, A-10D, F/A-181
  Black Wasp II, V-44 X Blackfish.
- **Air defence and fires:** MIM-104 Patriot + AN/MPQ-105, NASAMS, Skynex,
  Sentinel, 76n6 Clam Shell, Sholef and Seara, RSG60 + AMOS.
- **Unmanned:** Ripsaw, THeMIS, Honeybadger, MQ-8B Fire Scout, XQ-47B, and
  Darter / Pelican in the squads.
- The Tropical faction swaps to green: NATO Pacific kit and vehicles, the
  QAV Pacific AbramsX, olive Marshalls, green Hurons and Honeybadger. Little
  Birds, A-10 and Black Wasp have no green scheme and keep their own.

### Marine: Woodland, Desert

The US Marine Corps, from Expeditionary Forces' MJTF, tier 3. Rifles are EF's
MX-AR family in coyote. It has the amphibious and carrier arm the Army lacks:
AAV-9 Mack, LCC-1, RAH-66 Comanche, QAV-80 Harpy, MV-35 Phantom, the M3A1
Knight and AbramsX as armour, and the same air-defence set as the Army. The
Special Forces subcategory holds MJTF's recon (12 men).

### EUDF: Woodland, Arid, Arctic

The European Defence Force, tier 3, on `BLU_F` (woodland, the fullest roster),
`BLU_NATO_lxWS` (arid) and the Arctic factions mod's `CF_BLU_F` (arctic).

- **Rifles:** the MX family, arctic white in the Arctic faction.
- **Different from the US:** no Marshall or Badger (`NOT_FIELDED`). Armour is
  the AWC 301–304 Nyx, Luchs 3A5 and Challenger 2/2E, with Namer, Nemmera,
  Rooikat 120 and Rhino MGS. Air is European: NH90 TTH (the renamed Ghost Hawk),
  H225M Super Cougar, Merlin HC5, Tiger HAD, F-35F, A-149 Gryphon, C-192
  Samson. It also fields naval Mk41/Destroyer VLS and Mk45 Hammer.
- **Paint:** its own patterned camo (EU Woodland, EU Desert, EU Arctic), so an
  EU vehicle is never mistaken for a US one in plain NATO paint. Woodland and
  arid copy NATO olive and sand sheets. Arctic is the one camo made from
  scratch: solid white, tyres kept.

### HIMF

The Horizon Islands force, tier 2, generated by `tools/gen_himf.py`. Every man
inherits Atlas's own HIMF soldier (`Atlas_B_H_*`), so uniform, vest, helmet
and rifle are Atlas's: M16A4 on the line, XMS on the commandos. HIMF adds
Tanoan identities, the tier-2 round, squad drones (Darter with the operator,
Pelican with the grenadier) and its own vehicle list:

- Ram 1500s as the only transport (no HEMTTs, no M-ATVs), and EF's Gyra and
  Gyra HMG as the only APCs.
- Aircraft: the AT-27M35 Tucano and Caesar BTT (planes); MH-9, AH-9, WY-55
  Hellcat and H225M (helicopters).

**The one faction with an outside dependency:** it requires
`A3_Atlas_Characters_F_Atlas`, and without Atlas it is skipped. See the
addon's README for the kit table.

### Gendarmerie

The base game's `BLU_GEN_F` as a police force, not an army. Its kit is forced
by hand (`FORCE_LOADOUT`), and its round is tier 2. The source has no groups,
so all four motorised patrols are ours (`EXTRA_GROUPS`). They ride Offroads
(comms and covered) and a covered pickup. It also fields Vans, Ram 1500s,
Gyras, an Otokar ARMA, a Combat Boat, a RHIB and an H225 Super Puma, which sit
outside the groups.

### 1st JMSB

The players' own company, one faction, in OCP whatever the map (user,
2026-10-08: "only one camo ocp"). It is deliberately one man (a Recon Scout)
and one sixty-four-slot group: a player's loadout, gear and vehicle are set
by the mission, so a config roster would be classes nobody spawns. The scout
carries only a pistol by design; the mission gives him the rest. His default
kit is the user's own arsenal export - SF fatigues in OCP, a MIG Ferro Bison
carrier with a PRC-152, the OCP boonie, an SPS VP9 - applied as a loadout
array on spawn, and the class keeps CBA's extended event handlers.
`CfgVehicles.hpp` and `CfgFactionClasses.hpp` explain why.

## East

### Russia: Green, Arid, Arctic

The 2040 Russian army at tier 3, copied **as is** from its three sources
(`OPF_R_F`, `OPF_R_ard_F`, the Arctic factions mod's `CF_OPF_R_A_F`). The
instruction was "copy those three factions over as is, except give them
drones for 2040 and future ammo": there is no kit or rifle swap.

- **Rifles:** AK-12 and AK-12U in 5.45, suppressed (arctic-finished in the
  Arctic faction), RPK-12, MP-153.
- **Armour:** T-140/T-140K Angara, T-100X Futura, T100 Black Eagle, BTR-100
  Bogatyr, BTR-T Okhotnik, 2S90M Nosorog, ZSU-35 Tigris, 2S9 Sochor, BM-2T
  Stalker. Typhoon trucks, Galkin, Sokol 3T.
- **Air:** Mi-48 Kajman, Mi-35 Krokodil, Mi-33 Sova, Mi-290 Tuskar, Ka-60
  Kasatka, To-201 Shikra, Yak-130.
- **Air defence:** S-400, 3K72 Burevestnik, R-750 Cronus radar, Rapier FSC.
- **Unmanned:** SwitchBlade 300/600 (tubes in the squads), MQ-12 Falcon, UGV
  Uran, plus the east's Darter and AL-6 medical drones.
- **Paint:** Russian Green, Russian Sand (darker than NATO sand) and Russian
  Arctic. All three were approved on 2026-09-19.

### China: Woodland, Desert

The PLA at peer+ (tier 4). It shares the t4 shelf only with Turkey. It is built on the base game's Pacific CSAT (`OPF_T_F`, "China" in
this load order) and `OPF_CD_F` for the desert. The desert source is thin, so
`GROUP_TEMPLATE` and `ROSTER_TEMPLATE` build it up to the same roster.

- **Kit:** JAM SOF green-hex (woodland) or hex (desert) fatigues, set per man.
- **Rifles:** the CTAR/CTARS family, suppressed; black in woodland, tan in
  desert.
- **Vehicles:** ZTZ-99A, ZTZ-96B/X, ZTL-11, ZBD-04A, PLZ-05, PGZ-09, CSK-131
  Mengshi, Qilin LSV, SX2190 trucks; Z-10, Z-9, Z-8 and pods, J-20, L-15,
  Y-32; HQ-9B, HQ-7B, YLC-8B; HJ-12 / HN-6; YJ-12 anti-ship.
- **Unmanned:** CH-4 and GJ-11 UCAVs, BZK-005, ASN-209, CH-901 and WS-43
  loitering munitions, Sharp Claw UGVs.
- **Paint:** Chinese Woodland Digital (mid, dark and light green with a sandy
  brown, never pink) and Chinese Arid Digital. Each China vehicle offers the
  other Chinese schemes in its appearance menu.

### Iran: Arid, Tropical

The base game's CSAT (`OPF_F`) as Iran, tier 3, re-armed on the AK-103. Both
factions share one roster. The Tropical faction differs only in its vehicle
paint.

- **Rifles:** AK-103 (ARCO), AK-103 GL, SVD, RPK-12.
- **Vehicles:** T-14/T-14K Armata, T-100X Futura, T100 Black Eagle, Karatel,
  Mk49 Spartan, Typhoon trucks; Mi-48 Kajman, Mi-290 Taru and pods, Ka-60
  Kasatka, To-201 Shikra, Yak-130, Y-32; S-400, 3K72, Mk-29 ESSM, 76n6 Clam
  Shell; SwitchBlade 300/600, Hermes 450, MQ-12 Falcon, UGV Saif.
- **Paint:** base-game Hex (Arid) or Iranian Green Hex (Tropical).

### Turkey: Arid, Tropical (East) and Arid, Tropical (Independent)

The Turkish army, peer+ (tier 4), on Athena's Pacific OPFOR roster. It is
built four times: both camos on both sides. One roster and one rule set cover
all four, so the same army can be the enemy in one mission and a third party
in the next. The independent pair are copies of the east pair
(`FACTION_TWIN`, `tools/dup_faction.py`) with only the side and camo changed.

- **Rifles:** the SCAR-L family, suppressed; LMG_03, P07.
- **Vehicles:** Otokar ARMA, BMC Vasak 3, Gyra/Gyra AA/HMG/IFV, Strider, M-ATV,
  HEMTT trucks; AH-64E Guardian, S-70E5, CH-47I Chinook, Merlin HC5,
  F-35F; 3K72 Burevestnik; MQ-4A Greyhawk and UGV Stompers.
- **Paint:** Turkish Arid (after the user's Leopard 2 photo) or Turkish Green,
  with a small Turkish flag on each vehicle.

## Independent

### Syndikat

The base game's `IND_C_F` at tier 0: broke and irregular. No aircraft and no
artillery. It adds seven motorised groups of its own (Jeep LMG/SPG-9, HMG
technicals, truck and van combat groups) beside the source's six foot groups.
Every squad carries the UAV_02 quad, an IED quad and an IED Pelican. Its men
are on the source's own classes and rounds.

## How they are built, and what not to do

- **`tools/gen_us_factions.py` wrote the configs, but they are no longer pure
  generator output.** Since then they have been changed in place by
  `tools/swap_faction_mods.py` (mod dependencies, 2026-09-13),
  `tools/apply_faction_camo.py` / `tools/camo/faction_camo_make.py` (vehicle
  camo, files in each addon's `data/camo`), `tools/apply_faction_extras.py`
  (units the generator adds) and `tools/dup_faction.py` (the Turkey and Iran
  copies). **Re-running `gen_us_factions.py` puts the Aegis/Atlas/Athena
  names back and loses the camo.** Change a faction by editing its addon, or
  by re-running the tool that owns that layer.
- The ORBAT dump the generator reads is not on disk.
- A faction's decisions live as comments in its generator tables: `TARGETS`,
  `TIER`, `KIT_SWAP`, `RIFLE_SWAP`, `NOT_FIELDED`, `ROSTER_ADD`,
  `GROUP_TEMPLATE`, `FACTION_SIDE`, `FACTION_TWIN`. Each comment is dated and
  quotes the user's instruction.
- Vehicle paint rules: wheels and glass are never camo'd. Turrets items
  (Mk6, static HMG/GMG, static launchers, SAM/radar) keep their own paint.
  A family shares sheets.
- Removed and not coming back unasked: both CSATs, the Insurgents, the AAF,
  the LDF, both FIAs, both PLAs (2026-08-29, addons under
  `backup/factions_removed_2026-08-29/`), the EUDF Tropical and Woodland-NATO
  mirrors (2026-09-19), and the base-game US rows (2026-08-27). Their
  `TARGETS` lines are commented out, not deleted.

## Open points found while writing this

These are observations from the configs. None was changed.

- **Russia, Turkey and EUDF men set no kit of their own.** There is no
  `uniformClass` or `linkedItems[]`, so each man wears his parent's. Since the
  2026-09-13 swap, 46 of 61 men in 2040 Russia (44 of 59 in Arid, 40 of 59 in
  Arctic) sit on base-game CSAT classes (`O_Soldier_*`), not Contact's
  `O_R_*`. "Copy as is" therefore now looks like CSAT for most of the roster.
  Turkey's men are on base-game Pacific CSAT (`O_T_*`).
- **Iran wears base-game CSAT hex, not the Iranian digital set.** The
  generator's `KIT_SWAP` comment describes Aegis Gear Overhaul's `irdigi` set,
  but the shipped men name `U_O_CombatUniform_ocamo`. Iran (Tropical) men
  wear the same arid hex, so only the vehicles are green.
- `docs/FACTIONS.md` and its `_EAST`/`_GUER`/`_CIV` siblings are the
  2026-08 tier plan from `tools/gen_faction_addons.py`, whose input
  (`work/factions.json`) is gone. Read them as history. This file is the
  current state.
