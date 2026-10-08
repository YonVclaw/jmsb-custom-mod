# DESIGN_RESTART — top-down restart, 2026-08-08

This document is the user's stated design requirements from the 2026-08-08
restart session, plus their settled answers to the open questions. It
supersedes the FEATURE SCOPE of work.md / DESIGN_INTEL_SYSTEM Parts 1–4 wherever
they conflict. Mechanisms, code, and pre-work findings from those parts remain
valid and are referenced below as CARRY-OVER. Mark the old parts
superseded-by-this-doc; do not silently rewrite them.

## 0. Standing rules

1. **Keep it simple.** No new system where an existing one can be reused.
2. **CBA settings are OPERATION values only** — ranges, counts, chances, timers
   (sliders). Never WHERE or WHO. Location and identity always derive from
   ALiVE data (TAORs, commanders, registries, clusters) or map markers.
3. **ALiVE wins.** JMSB hunts what ALiVE places; jmfsb spawns only what ALiVE
   doesn't (coastal, caches, QRF, leaders). Every jmfsb spawn is profiled.
4. **Adapter invariant** stands: `jmfsb_adapter_alive` is the only ALiVE-aware
   code (grep regression test stays in check_all.py).
5. **No end state.** Play until bored of the map. Finite content is fine
   (leaders don't regenerate); persistent attrition is the campaign.
6. **Plumbing before features**: nothing new merges until slice zero (§9) has
   passed in a live mission.

## 1. Force on force — the hunt network

The player objective: **un-integrate** the enemy's defense network. Every
system below is an intel target; destroying its units visibly degrades the
enemy.

### 1.1 AA + artillery hunt (NO jmfsb spawning)
- Targets are the AA and artillery units **ALiVE placement already creates**.
- AA pool: `ALIVE_aaProfileBehaviour` (placement registers every AA profile at
  creation — verified in source). Artillery pool: profile capability filter.
- All sides. Pool size is governed by the mission maker's ALiVE placement
  settings, not by jmfsb.
- No sync needed. (Optional later: sync jmfsb→placement to scope the hunt to
  specific placements' objectives. Not built now.)

### 1.2 Integrated coastal defense (jmfsb spawns)
- JMSB spawns + profiles coastal sites (radar/launcher split per the built
  anti-ship design). Standard ALiVE profile spawn distance — no custom
  un-virtualization.
- All sides present. Auto-placement: shoreline candidates near marine clusters;
  **large water only, no ponds** (water-body area test); terrain check;
  minimum spacing (CBA); TAOR-filtered (§4).
- Role: primarily hunt targets, but sites remain FUNCTIONAL — players may
  operate large boats, and sites engage per the built battery behavior.

### 1.3 Drones (jmfsb spawns)
- Drones profile fine (ground = vehicle profiles; air profiles supported;
  MACC adoption verified). Patrol drones at objectives exist as profiles and
  materialize only when players are in range — no far-from-player active units.
- **Supply caches**: physical objects, auto-placed (TAOR-filtered, spacing,
  terrain). Destroying a cache cuts the side's active drone ceiling for a
  random window. CBA sliders: base max, reduced max, window min/max
  (e.g. 8 → 4 for ~26 min).
- **Spawned jammers** (no jammer drones): static jammer props auto-placed at
  guarded objectives, TAOR-filtered —
  `RuggedTerminal_01_communications_hub_F` = **large** jamming zone,
  `RuggedTerminal_01_communications_F` = **small** zone (radii = CBA sliders;
  CARRY-OVER jamFactor model). **Jamming stops when the jammer is hacked OR
  destroyed** — either removes its zone immediately and permanently. They join
  the LOCATE JAMMER product pool.
- Drone detection of a player = the same event/roll as a failed hack (§2).
  One reaction path, no special case.

## 2. Intel + hacking (carry-over core)

- The circle system is CARRY-OVER as built: snapshot renderer, shrinking
  offset ladder, cached throw per target per tier, one renderer.
- Hackable: towers, downed drones, AI units. Products point at §1 targets
  (LOCATE AA exact; LOCATE ARTILLERY fuzzed ladder; coastal + caches join the
  pools).
- **Radio detection**: transmissions from radios **over 1 W** are detectable
  unless SATCOM. Wattage threshold = CBA slider (default 1 W). A detected
  transmission rolls the same detection degrees as a failed hack — SMALL:
  silent flag; MAJOR: the objective-lost-grade reaction below. This replaces
  the DF-station triangulation stack for the restart scope.
- **Fail/detect with degrees** (CBA: fail %, detect %):
  - SMALL: silent flag; player may sneak away or retry at **3× fail/detect
    chance**.
  - MAJOR: objective-lost-grade reaction — 4–10 arty rounds (CBA range +
    random), drone response, and AI/profiles within 300–1000 m
    (`getNearProfiles` + `knowsAbout`) learn the player's position.

## 3. QRF on objective taken

- Trigger: CARRY-OVER capture detection (presence + zero enemies held N sec).
  QRF **replaces** Objective Watch — no countdown, no warning.
- Waves, owning commander's faction:
  1. **Arty**: 10–40 rounds scaled to objective size, dispersion scaled to
     size. *Asymmetric commanders have no arty wave — instead 3–4 mortar
     rounds, ~50% of the time (CBA).* 
  2. **Drones**: X spawn at 3000–6000 m, move to objective, recon + kamikaze
     mix. **Respects the cache-reduced ceiling** — killing caches weakens QRF.
  3. **Squads**: 2–5 spawn at TAOR-valid origins, profiled immediately,
     waypoint to objective (spawn→profile→move, the Jman snippet path:
     https://www.alivewiki.com/wiki/Script_Snippets.html#Spawn_.26_Profile_Group_Script_By_Jman).
- Applies to conventional AND asymmetric objectives.

## 4. TAOR derivation (no settings)

Per side: union the `taor` keys, and separately the `blacklist` keys, of the
placement modules synced to that side's AI commander (keys verified in
source). Apply to: coastal sites, caches, patrol-drone points, QRF spawn
origins (3000–6000 m ring ∩ TAOR), safe houses (asymmetric commander's TAORs).
Friendly-base exclusion falls out automatically. Empty TAOR = whole map minus
blacklist.

## 5. Asymmetric — the leader chain

- **3 leaders** (1, 2, 3). FINITE — no replacements. Kill or capture cuts the
  asymmetric pool **25% per leader** (CBA slider).
- Leaders rotate every 20 min (CBA): board a vehicle, drive to the next safe
  house.
- **Safe houses**: buildings in settlement clusters inside the asymmetric
  TAORs — IN ADDITION to ALiVE's installations. Trap chance per house (CBA):
  trap = IED (most likely) or mortar strike 3–4 rounds / 50 m dispersion.
- Intel points at the SAFE HOUSE, never the leader exactly; intel found IN a
  house points at the NEXT house — always via the circle ladder.
- **Capture + deliver to prison** (markers `jmfsb_prison`, `jmfsb_prison_*`;
  nearest counts): reveals the location of ONE other uncaptured leader.
- **Installations** (`factory`/`HQ`/`depot`/`roadblocks` from the asymmetric
  commander's objectives) join the intel target pool alongside safe houses.
- **Cell phones**: every insurgent body carries one; phones, radios, and other
  intel items must be physically **deposited at an intel drop in the player
  base** (a deployable Intel Drop Case item; ACE interact on it to
  deposit) [AMENDED 2026-08-08: an ITEM, not a marker - the collection point
  moves with the section] — the counter tallies DEPOSITED items only, carried items count for
  nothing. Every X deposited (CBA slider) yields one circle hint via the
  CARRY-OVER intel-hunt loop. Target pool: safe houses + installations.
- **Civ-comms hack nodes**: existing towers PLUS new "internet pops" — a
  stack of rugged-server props auto-placed in city buildings (settlement
  clusters, asymmetric TAOR, spacing). Hacking either adds the leader/
  safe-house product when an asymmetric commander is present.

## 6. Coexistence

Conventional + asymmetric commanders on one map is native ALiVE. JMSB scopes
by `controltype` read from `OPCOM_instances`: §1–§3 systems attach to
conventional sides (QRF to both), §5 to the asymmetric side.

## 7. Data wiring (complete)

| Need | Source |
|---|---|
| AA targets | `ALIVE_aaProfileBehaviour` + profile handler |
| Arty targets | profile handler + artillery capability caches |
| Spawn areas | `taor`/`blacklist` keys on commanders' synced placements |
| Objectives (QRF, patrols, sizing) | `OPCOM_instances` → objectives |
| Conventional vs asymmetric | `controltype` in `OPCOM_instances` |
| Installations | asymmetric commander objective keys |
| Coastal/cache/pop candidates | marine + settlement clusters, `ALIVE_gridData`, engine terrain/water checks, TAOR filter |
| Safe houses | settlement building scan ∩ asymmetric TAOR |
| Prison | `jmfsb_prison`, `jmfsb_prison_*` markers |
| Intel drop | a deployed Intel Drop Case item (was: markers) |
| Phone hints | jmfsb intel-hunt loop (CBA: X per hint) |
| AI learns players | `ALIVE_fnc_getNearProfiles` + `knowsAbout` |
| Fires out | `ARTY_REQUEST` on `ALIVE_eventLog` |
| JMSB spawns | spawn→profile→move + jmfsb registry |
| Restart survival | `sys_data` LoadData/SaveData pairs |
| Tuning | CBA sliders (operation values only) |

## 8. Kept / cut

**Kept, untouched:** adapter + event contract, circle renderer + products,
hack core + tablet, EW jamFactor model + zones (jamming delivered by spawned
static jammer props at objectives — hub prop = large zone, terminal prop =
small; DF stations superseded by the radio-detection rule),
notification system, fire path, anti-ship battery behavior, capture detection,
friendly systems (Friendly Ops, CIWS/C-RAM, evac, timed repair, patrol base),
devices/cTab layer, sys_data persistence pairs, 5-module Eden layout.

**Cut/shelved from Part 4 scope:** per-settlement cells + link chart, terror
attacks, civilian truck routes, Enemy Force Director escalation ladder,
poisoned point-products (trap chance lives only on safe houses), Objective
Watch countdown, leader regeneration, hostility-driven recruitment economy.

## 9. Slice zero — gate before ANY feature work

In a live mission, in order; each dumps evidence to RPT:
1. Adapter reads: enumerate `OPCOM_instances`, read `controltype`, read a
   placement's `taor`/`blacklist`, read `ALIVE_aaProfileBehaviour` entries.
2. Spawn→profile→move: one squad spawned, profiled, waypointed; observe
   virtual movement + materialization.
3. One `ARTY_REQUEST` from jmfsb → battery fires.
4. Capture detection fires `jmfsb_objective_captured` on a test objective.

Pass all four → build in this order. **PRIORITY RULE: any system that
interacts with cTab is built or rebuilt FIRST.** cTab-facing systems: the
hacking console/tablet UI and its products (§2), the circle renderer feeding
the map, the intel-hunt tally + hint flow (deposit → counter → circle), and
the alert/notification feed. Sequence:
1. cTab-facing layer (§2 hack console, products, circles, tally, alerts) —
   built/rebuilt and verified on the device before anything else.
2. §1.2 coastal (smallest full spawn system).
3. Caches/drones (§1.3).
4. Hack reaction ladder (§2 fail/detect consequences).
5. QRF (§3).
6. Leader chain + safe houses + internet pops (§5).
Fail any slice → fix the pipe before anything else.

## 10. Open items (deliberate)

- Exact rugged-server prop classname for internet pops (pick at build).
- `ied` installation type ranking (leave IED caches to ALiVE's IED system;
  not a traceable node — standing recommendation, user has not overruled).
- Per-side EW/insurgency refactor: deferred until a mission actually needs
  two hostile sides with full systems.

## 11. Build-session annotations (2026-08-08, plan approval)

- §8 "Friendly Ops" is STRUCK from the kept list: D63 stands (user
  re-confirmed at plan approval) - ALiVE's Player Combat Support / Player
  Resupply are the support system and jmfsb never rebuilds it.
- §8 "5-module Eden layout" is superseded by D64 (user re-confirmed at plan
  approval): one module = one system, and the restart systems get NO Eden
  modules at all - WHERE derives from ALiVE per rule 2.
- Name corrections against source: marine clusters are
  `ALIVE_clustersCivMarine`; the persistence surface is `ALiVE_fnc_getData` /
  `ALiVE_fnc_setData` (no generic SaveData/LoadData pair).
- `adapter_alive` was never committed before the purge, so it was written
  FRESH this session (15 fns incl. the slice-zero probes). The invariant
  check is broadened to any `ALiVE_`/`ALIVE_` symbol.

## 12. Build log - section 9 complete (2026-08-08)

Slice zero PASSED in a live mission (all four probes, RPT-verified: 3 OPCOMs
with controltype, TAOR/blacklist arrays, AA pool of 6, spawn->profile->
waypoint, ARTY_REQUEST accepted, capture event raised). Everything below was
built on that footing, in the order section 9 sets.

| Step | Addon | State |
|---|---|---|
| 1 | `hacking` (+`adapter_alive`) | LOCATE AA (exact) and LOCATE ARTILLERY (cached-throw ladder); intel tally: search -> carry -> deposit into a deployed Intel Drop Case -> hint circle on installations and safe houses. Phones on asymmetric bodies, RADIOS on occupation/invasion bodies, by controltype. |
| 2 | `coastal` | Auto-sited anti-ship batteries: marine clusters + engine water-ring test (no ponds) + TAOR. Profiled; a site is a PLACE and its battery re-points at whatever hardware is currently standing. |
| 3 | `jamming`, `uas` | Jam zones from props at objectives (hub=large, terminal=small; hack OR destroy kills the zone) + LOCATE JAMMER. Profiled patrols over objectives; supply caches cut the side's ceiling for a window; drone spotting uses knowsAbout. |
| 4 | `reaction` | One path for hack-fail / drone-spot / radio>threshold. SMALL is a silent flag at 3x; MAJOR asks the hostile commander's guns, sends a drone from its ceiling, and reveals the player. SATCOM exempt via ACRE's own antenna check. |
| 5 | `qrf` | Capture detection over objectives and `jmfsb_qrf*` markers; arty scaled to the objective (asym = mortars, 50%), a drone, and 2-5 profiled squads walked in from 3-6 km. |
| 6 | `leaders` | Three finite leaders in settlement safe houses, rotating; TRACE NETWORK points at the house and at the NEXT house once moving; watched houses; capture + deliver to `jmfsb_prison*` reveals another exactly; internet pops; spent state persisted. |

PURGED NAMES NOT RESURRECTED: electronic_war_zones, drones, kamikaze,
intel_hunt, objective_watch, insurgency, deception, traffic, enemy_force,
ciws, aircraft, ambient_*, base_defense, friendly_ops,
counter_battery. Carried-over MECHANISMS live under new names or inside the
addon that owns them.

RESTORED 2026-10-07 (user: "do we still have integrated aa" ... "all 3"): `iads` (radar emission
control, shared datalink picture, threat-board reports) and `airdefence`, from ee1e25a9 as they
were deleted. The full air-defence system the user asked for after it - munition interception,
coordinated Sites, CIWS, emission control, warnings as jmfsb notices, its status and controls in
jmfsb's own UI - is designed in docs/DESIGN_AIR_DEFENCE.md and built the same day as `adsite` (the engaging
brain; `airdefence` places, `iads` runs the radars). Unverified in game: `#jmfsb adsite.probe`, then TESTS.md s12.

Setup a mission needs: an ALiVE commander or two, and a `jmfsb_prison`
marker. The intel drop is an ITEM (Intel Drop Case) - deploy it where the
section actually is, and move it when the base moves. Everything else derives from
ALiVE. Chat: `#jmfsbreads/squad/fire/capture`, `#jmfsbcoastal`, `#jmfsbjam`,
`#jmfsbuas`, `#jmfsbreact`, `#jmfsbqrf`, `#jmfsbleaders`.

NOTHING IN STEPS 1-6 HAS RUN IN GAME. Only slice zero has.

### Intel integration with ALiVE (2026-08-26)

Intel now points at everything ALiVE runs, not only what jmfsb spawns. Three
new adapter reads, all server-side with published counts for the client
buttons: `camps` (mil_placement's random camps, off the `campSafePos` key on
the cluster hash, side = who garrisons it now), `logisticsHubs` (LOGCOM's
`ALIVE_ML_supplyNetwork` nodes, HQ plus every delivery point still feeding
something alive), `radars` (vehicle profiles by class - SAM search sets,
Clam Shells). `aaTargets` widened from placement's registry to every
anti-air-capable vehicle profile (ALiVE's SEAD rule). Products: LOCATE CAMP,
LOCATE LOGISTICS; LOCATE RADAR now covers ALiVE's radars beside the coastal
ones; LOCATE AA and LOCATE ARTILLERY point at current profile positions.
Deposit hints draw from the same pools. Installations were already read.
Anti-ship batteries stay jmfsb's own. NOT RUN IN GAME.

### ALiVE integration, the rest (2026-08-26)

- Event bridge: the adapter listens to ALiVE's whole event log and re-raises
  plain summaries as `jmfsb_adapter_alive_event` / `_capture`; `qrf`
  announces hostile captures the moment OPCOM logs them.
- One intel: ALiVE's corpse-file chance is zeroed per commander; jmfsb's
  circles and hints are filed into the friendly G2 as spot reports
  (`reportIntel`), so tablet, COP and jmfsb's map agree. The hint tally
  (banked, tier, hinted ids) persists through ALiVE's data layer.
- The commander's stake: coastal batteries and drone caches register as
  OPCOM objectives (`registerSite`); a hit cache asks LOGCOM for a section
  (`requestSupply`) - a convoy players can find and interdict.
- Friendly C2: the support app lists ALiVE's own batteries (`alivearty`)
  and ATO (`alivecas`, experimental) as providers; BFT draws virtual
  friendlies from the COP; `reaction` scales detection by settlement
  hostility and warns a group when the enemy commander has its position.
- Respawn: jmfsb defers to ALiVE multispawn's gear restore when it is on,
  and falls back to the role loadout instead of an empty one otherwise.
- The `airdefence` stopgap references are gone. NOT RUN IN GAME.

### Class picker (2026-08-26)

Every module field that takes class names (antiship launchers per side and
shared, missiles, decoys; ambience shells and drones; cas airframe; uas
drones per side) opens a selection window instead of an edit box:
`jmfsb_ClassPick_*` in main/CfgEdenDrone.hpp on ALiVE's inline-controls-group
substrate, with SIDE and FACTION cycle filters (Type/Source for ammo), a
multi-select list, "(unrecognised)" rows for stored names the list does not
know, and a typed override. Per-side fields have the side fixed. Handlers
are jmfsb_common's (listClasses, edenClassPickLoad/Save). The wire format is
unchanged - a comma-separated string - so no read site moved. NOT RUN IN EDEN.

### Qualification arsenals (2026-10-07)

A PAC skill can now carry `arsenal:<name>`: holding it adds the arsenal
document `<unit>.arsenal.qual_<NAME>` (same slug rule as plt_/sqd_/role_) as
one more layer after common, platoon, squad and role. `pac` applySkills keeps
the list on the unit and raises `jmfsb_pac_arsenalChanged` when it changes;
so do the structure and settings republishes. `groups` buildArsenal (the
arsenal block moved out of setupPlayer) rebuilds from scratch on that event,
so a skill granted or taken away mid-mission shows in the arsenal with no
respawn. PAC setting `arsenalMode`: `role` (role lists only), `traits`
(qualification lists only), `both` (default). JMFSB data: skills Marksman
and Breacher added, Medic/ISR/Pilot given `arsenal:` effects; qual_MARKSMAN
holds the AXMC/HK417, their magazines and the long optics, moved out of the
common arsenal; qual_MEDIC/BREACHER/ISR/PILOT exist empty. NOT RUN IN GAME.
Same day: a role's `defaultSkills` ("Skills it grants") - stored and edited
on the role page and the website since 2026-09 but applied by nothing - now
apply. `pac` applySkills adds the current role's grants (YMF_role) to the
man's own PAC skills, so role skills and personal qualifications are held at
once; changing role drops the old role's grants. NOT RUN IN GAME.
Same day: Pilot and Medic are roles, not traits - both skills removed from
JMFSB.skills (and from the players holding them; qual_PILOT/qual_MEDIC were
empty and deleted; pilotTalon no longer requires pilot). Because PAC owns the
ACE classes, a role's own ace_medical_medicClass / ACE_IsEngineer / ACE_isEOD
were being reset to 0 and skipped on the role; applySkills now applies the
role's values first as a floor and a trait can only raise them. NOT RUN IN GAME.
Same day: the role floor in applySkills also covers job flags a trait sets
(isLeader, isJFO, isISR, UAVHacker - any name managedNames reports): a role's
true goes on, so a JTAC is a JFO without holding the JFO trait. NOT RUN IN GAME.
Same day, JMFSB data and display: Demo and Medical roles removed (their slots
are Recon; JMFSB 6 is Commander, XO and six Staff - staffC2 from isrC2); the
JTAC/ISR/Security/Medical C2 roles went with it. Medic is a SKILL again
(medic:2 + arsenal:medic; qual_MEDIC holds the medic bags, kitbags, surgical
kit, PAK and medical drone). Role names lost their orbat suffix. Both orbats
run the common arsenal (arsenalVersion ""). They are called SKILLS, not
traits: arsenalMode is role | skills | both ("traits" still read as skills).
PAC puts each man's skill abbreviations on him (jmfsb_pac_skillTags, public,
MED first); the tacpad role tag, the HUD squad list, the BFT map label and the
slot menu show them. ACE name tags cannot. NOT RUN IN GAME.
CORRECTION, same day (user: "ace traits come from skills, role is your slot in
the team"): the role floor in applySkills is removed. ACE medic/engineer/EOD and
the leader/JFO/ISR/UAV flags come from skills only (a role's own values are
skipped by groups and reset by PAC, as before). Two skills setting one class
give the higher. A role touches skills only through its "Skills it grants".
Same day: Leader is a ROLE, not a skill - the lead skill is gone (and off its 4
holders); with no skill claiming isLeader, groups applies each role's own
isLeader again. Admin panel = THIS OP ONLY, PAC record = permanent (user): the
Player Skills box now gives PAC skills for the mission (none/CLS/Medic,
none/Engineer/Adv, BRC, ISR, JFO, DRA, UAV, MKS, SNP; LEAD gone) through the new
jmfsb_pac_fnc_sessionSkills - server-side by Steam id in jmfsb_pac_session,
published, so respawns and rejoins keep it until the mission ends; never
stored. applySkills reads "skill:<id>" entries as whole skills (effects,
arsenal, tag). The old respawn wipe of tempEffects is gone. NOT RUN IN GAME.
Same day: BRASS and NIGHT BRASS colour schemes, the briefing deck's palette
(#f4f2ec / #1c2321 / #7a6224 by day, #1c2321 / #f4f2ec / #c8a24a by night) -
tacpad fnc_theme, the CBA setting, the settings app's preset cards (so TAC//PAC,
which paints with the tacpad theme, has them too) and DIVINER_Web's
JMFSBD_MOD_SCHEMES. NOT RUN IN GAME.
Same day: the JMFSB order of battle "vanilla" is now "default" (JMFSB.orbat.default,
currentOrbat default) and the "vanilla" suffix is gone from every squad and
platoon name - in both orbat documents, the radio plan and the player records.
The tropical orbat and its 25 roles are deleted (no player held one). Every
player-side JMSB uniform (uniform, uniform_sof, uniform_eu) was already in the
default arsenal. The motorpool version is still named "vanilla".

### ACM (2026-10-07)

New addon `acm`, loaded only with Advanced Combat Medicine (skipWhenMissing on
ACM's CfgPatches). Its preInit re-defaults ACM's treatment gates to JMSB's two
tiers - CLS = ACE medic 1, Medic = 2 - per the user's tier table, and re-defaults
the five jmfsb_medbags contents to ACM kit (O- blood, vials and syringes, airway
and chest kit). jmfsb_acm_fnc_setDefault re-registers a setting from CBA's own
record with only the default changed, so titles, lists and scripts survive and
any server/mission/player value still wins. ACE's medic* gates are left alone:
jmfsb_cba_settings forces them. NOT RUN IN GAME.
