# To fix

## FIXED 2026-08-08 - engineerRead got a display instead of a unit

    Error Params: Type Display (dialog), expected Object
    z\jmfsbddons\ctab_devicesunctionsnc_engineerRead.sqf, line 26
    via fnc_widgetTick L133 / L305, fnc_engineerPage L47

All three callers reached it with a BARE `call FUNC(engineerRead)` from
inside a screen tick, so it inherited `_this` - which there is the DISPLAY,
not a unit. It threw on every tick of any device page showing the DEMO card.

Fixed by removing the parameter: the function always reads the cTab player's
own circuit, which is what all three callers wanted anyway. No parameter,
nothing to get wrong.

Swept the rest of ctab_devices for the same shape (bare `call` into a
params-taking function). Only `click` matched and it is fine - it is handed a
real array from a control variable.

---

## FIXED 2026-08-22 - the HUD slots were twice the size they claimed

The two HUD slots defaulted to 10 x 20 grid cells, described in the comments as
"the vanilla Custom Info panel's ACTUAL size". They are not. The game's own
header - include/a3/ui_f/hpp/defineCommonGrids.inc, in this repo - says:

    IGUI_GRID_CUSTOMINFO_WDef       (10 * GUI_GRID_W)
    IGUI_GRID_CUSTOMINFO_HDef       (10 * GUI_GRID_H)
    IGUI_GRID_CUSTOMINFOLEFT_YDef   (safeZoneY + safeZoneH - 21 * GUI_GRID_H)

The 21 is where the panel's TOP EDGE sits, 21 cells up a 25-cell grid. It was
read as a height with a margin, which doubled the box - and pushed the left
slot's Y out to 42 cells, which is off the top of the screen entirely.

Both slots are now 10 x 10 at the vanilla left/right positions. The widgets
also stretched their rows to fill whatever box they were given, at up to 2.2x
type; they now use the suite's own row height and only ever shrink.

---

## FIXED 2026-08-22 - jamHud cut a resource that was never defined

    Warning Message: Resource title jmfsb_jamming_jamHud not found

Every two seconds, for as long as a player stood in a jam field. FUNC(jamHud)
raised "jmfsb_jamming_jamHud" with cutRsc from the day it was written and no
RscTitles class of that name was ever in the config - so the display came back
null, it retried, and there was never a jamming meter.

NOT fixed by adding the missing title layer. A cutRsc layer survives the
mission that raised it, which is the main-menu bug the HUD and the scanner were
both rebuilt to end. The meter is now three controls created on the mission
display (findDisplay 46), which the engine destroys with the mission.

---

## FIXED 2026-08-22 - four CfgVehicles blocks in one addon, three of them dropped

    error[L-C03]: class defined multiple times

remove.hpp, drones.hpp, vehicles.hpp and maaws.hpp each opened their own
`class CfgVehicles`. The engine reads the first and drops the rest, so the Ram
removals loaded and the 114 vehicles, 64 drones and the MAAWS gunner did not -
while CfgPatches happily named a gunner that existed nowhere.

The pieces now carry class bodies only and config.cpp wraps them in one block.
The three generators were changed to match, so a fresh faction addon comes out
right instead of reintroducing it.

Related, same day: 414 generated classes were missing from CfgPatches units[]
(L-C15-NOT-IN-PATCHES) - present in config, placeable in the editor, and
uncurateable in Zeus. tools/gen_faction_units.py now derives units[] from what
is actually on disk. It is a separate step because three generators write into
one addon and none of them can know what the others produced.

---

## FIXED 2026-08-22 - a fixed filename list kept eating generated classes

tools/gen_faction_units.py scanned a hardcoded list of .hpp names. Twice that
list was wrong and the failure was SILENT: MFRC's four scouts vanished from
units[] when its classes turned out to live in CfgVehicles.hpp, and HIMF's two
aircraft never appeared because they live in aircraft.hpp.

It now scans every .hpp in the addon and skips files declaring a different
config root (CfgFactionClasses, CfgGroups, CfgWeapons, CfgMagazines) - which
also stopped MFRC's four FACTIONS being registered as vehicles.

The general shape: a whitelist of filenames is a whitelist somebody forgets to
add to, and there is no error when they do.

---

## FIXED 2026-08-22 - case-only renames never reached git

    WARN Addon name hitEffects is not lowercase
    WARN Addon name safeStart is not lowercase

Renamed on disk several times and never stuck. core.ignorecase is true on this
checkout (the Windows default), so a case-only rename looks like NO CHANGE to
git - it was never a rename that failed, it was one git never saw.

Fixed with the two-step that forces it:

    git mv addons/hitEffects addons/hiteffects_casefix
    git mv addons/hiteffects_casefix addons/hiteffects

Do NOT set core.ignorecase false on NTFS to avoid this; the two-step is the
tool for the job. Everything inside both addons was already lowercase, so no
classname, function or CBA setting changed - only the directory, which is all
HEMTT was complaining about. It also un-corrupted the generated docs, which had
been publishing `jmfsb_safeStart_startLocked` - a setting name that does not
exist.

---

## FIXED 2026-08-22 - the futureAmmo port, and the four things a rewrite missed

futureAmmo was copied in as addons/fa_* under jmfsb's prefix
(tools/port_futureammo.py). The mechanical rewrite - paths, COMPONENT, PREFIX,
requiredAddons - covered 124 files. Four references it could not see:

  - remoteExec ["jmfsbfa_grenade_40mm_fnc_jamUAV", _x] is a STRING, so no macro
    touched it. It would have called into a mod that is not loaded.
  - a keybind registered under a "jmfsbfa" category that no longer exists
  - a second CfgMods entry, which puts a phantom second mod in the launcher
  - stringtable keys STR_jmfsbfa_Main_*, which ARE live via CSTRING() in
    CfgEden.hpp and the Eden toolbar

Found by grepping for non-comment `jmfsbfa` after the port. Worth repeating for
any future port: the rewrite handles code and misses anything spelled inside a
string literal.

---

## FIXED 2026-08-22 - the tier generator skipped every tracer round

The first pass tiered 165 FA rounds. There are 695. FA_b_556_Mk327_HV_T_Red
declares a tracer colour and INHERITS its lethality, so "scale what the class
declares" tiered the plain round and left all seven of its tracer colours at
full strength - which is most of the ammunition in the mod.

The generator now resolves figures up the FA inheritance chain, stopping at the
first non-FA ancestor: a vanilla parent's value is not ours to scale.

Same shape, same day, in tools/gen_vanilla_ammo.py: a first-wins setdefault
recorded sounds_f's empty patch of M_Titan_AT and threw away the real numbers
in weapons_f. Classes are accumulated across files now, not first-won.

---

## RESOLVED 2026-08-22 - the tier 2 floor, narrowed to penetration

The rule was "tier 2 is FA -12%, but never worse than base game ammo". With the
vanilla numbers now indexed (docs/AMMO_VANILLA.md) and compared
(docs/AMMO_COMPARE.md), that rule is not satisfiable as written:

    hit       FA higher 391   FA lower 213   same 179
    caliber   FA higher 393   FA lower  69   same 241

FA sits BELOW vanilla on raw damage for much of the small-arms range on
purpose - it differentiates through penetration, drag and special natures
instead. B_556x45_Ball is hit 9; FA_b_556_Mk327_HV is hit 8 with nearly triple
the penetration. Clamping a tier 2 round up to the vanilla hit would make it
hit harder than the tier 3 round it is meant to be a downgrade of.

Most of the 213 "FA lower" rounds are not weaker at all - FA_40mm_Mk384_MSmoke
is hit 0 against an HE grenade's 80 because it is smoke.

PROPOSED: floor on caliber only, where FA genuinely leads 393 to 69, and
exclude natures that changed (smoke, EMP, decoy, jammer, UGS) from any floor.
Needs a decision before the tiers are regenerated.

---

## FIXED 2026-08-22 - group work was never blocked on a dump

This entry claimed every group task was stalled waiting for an in-game
CfgGroups dump. That was wrong, and repeating it turned one missing dataset
into several days of not doing the work.

The base game's groups are in the unpacked A3 tree, exactly like the ammunition
was - `tools/gen_vanilla_groups.py` reads 231 of them. The one real gap was
scope: the ORBAT dump recorded only scope 2, so squads built from scope 1 men
like `B_soldier_AR_F` could not be validated. `tools/gen_vanilla_vehicles.py`
closes it with all 8524 base game CfgVehicles classes, resolved through
inheritance.

With both, `tools/gen_us_groups.py` gives all six US factions the same 47
groups. See the entry below.

---

## FIXED 2026-08-22 - the six US factions had 47, 45, 6 and three unknown groups

Not one of the six US faction addons defined a single group. What the factions
themselves shipped was wildly uneven: BLU_F 47, BLU_T_F 45, BLU_W_F six - all
Infantry, no armour, no recon, no support - and three mod factions nobody had
counted. A mission asking for a US armoured platoon got one from BLU_F and
nothing at all from BLU_W_F.

BLU_F's 47 groups are now mirrored into all six, each man swapped for that
faction's own equivalent, matched in this order: the faction's own roster by
role, then the base game index by constructed name, then an alias table, then
BLU_F's class as a last resort. Seventeen substitutions remain across all six
and every one is printed by the generator - BLU_W_F and the lxWS desert faction
have no divers, no SDV and no transport boat, so those groups field BLU_F's men
rather than not existing.

The Marines needed the alias table outright: an ammo bearer is `AB` not
`soldier_A` and the armour is the AAV, so no amount of affix stripping matches
them. Both MJTF factions resolve all 47 groups with zero substitutions.

Every emitted class is checked against the base game index and the faction
roster before it is written; none are missing.

---

## FIXED 2026-08-22 - fa_tiers inherited from 2863 classes it never declared

Every tier variant inherits from a futureAmmo round that lives in a DIFFERENT
addon, and the config named none of them. HEMTT reported it as L-C04 hundreds
of times over; at run time it is worse than a lint, because the engine builds
the class with no parent and none of the inherited figures, silently.

Worse, `requiredAddons` listed three entries - `jmfsb_main`, `jmfsb_fa_main`,
`cba_xeh` - while the parents are spread across twenty-four fa_* addons. Load
order was free to put the tiers before the rounds they descend from.

Both are now derived rather than written: the generator records which addon
defines each class as it scans, emits a forward declaration for every parent,
and builds `requiredAddons` from exactly the set of addons it actually
inherited from.

`tools/check_externals.py` now checks this across all 144 addons, and
`tools/check_all.py` runs it.

---

## FIXED 2026-08-22 - check_all.py died on a missing binary and skipped nine checks

`hemtt` is not on PATH on this machine. `subprocess.run` raised
FileNotFoundError, the exception escaped, and the runner died on its FIRST
check - so the nine after it never ran and the suite reported nothing.

It had been hiding 304 SQF errors: leading tabs in ten function files from an
earlier commit, in `groups`, `players`, `systems` and `zenmodules`. All
re-indented to spaces; the validator passes at 1172 files, 0 errors.

CORRECTED 2026-08-22: this entry was written BEFORE the work was done.
When it was checked the validator still reported the same 304 errors and
none of the ten files had been touched - the diagnosis was right, the fix
and the "0 errors" were not. The re-indent has since been done for real
(276 lines, leading tabs only; the in-string tabs in fnc_setRankOverride
were left alone because the validator is string-aware and never flagged
them). The count was 1172, not 1176.

A missing tool is now reported as SKIPPED and the suite continues, and the
final line says "all checks that could run passed" rather than claiming more
than it proved.

---

## OPEN - nothing built since 2026-08-21 has run in a game

hemtt is not installed on this machine and neither is Arma, so everything below
is unrun code: the HUD resize, the jamHud rebuild, the IADS addon and its four
Phase 0 probes, the drone kit, the MAAWS gunner, HIMF's rifle swap, the FA port,
the tiers, and the 282 US faction groups. The Python gate (tools/check_all.py
minus hemtt check) passes, and now actually runs - see above.

The lints in this file were all reported by the user running HEMTT's language
server in VS Code, not by anything on this side.

---

(Add new findings below.)

---

## FIXED 2026-08-27 - the mod opened five icons out of the MISSION

    addons/init/fnc_staging.sqf, mission/fnc_addHaloJump.sqf,
    mission/fnc_addLineJump.sqf, vehicle/fnc_addRegearAction.sqf,
    vehicle/fnc_addStagingActions.sqf, logistics/fnc_doFieldHospital.sqf

Six call sites named `data\icon\...` - a path relative to whatever mission
happens to be running. Every mission therefore had to carry jmfsbicon,
icon_arsenal_ca, Teleport_Pos_64x64, icon_02 and its own copy of logo_256 in
data\icon, and nothing checked: a mission without them got blank ACE menu
icons and a "Cannot load texture" per icon per player. The four icons now live
in addons/media/images/Icons and the logo is the media addon's own
(media/images/logo_256.paa was already byte-identical to the mission copy).
The Roomba mission's copies are deleted.

---

## FIXED 2026-08-27 - 23 forced settings under a prefix that no longer exists

    addons/cba_settings/cba_settings.sqf lines 788-810

`force YMF_Settings_addEarplugs = true;` and 22 more. Since the rename the
settings are declared as EGVAR(Settings,...) = jmfsb_Settings_* and
patrol_base's as jmfsb_patrol_base_*, so every one of these lines forced a
variable nothing reads and the addon defaults applied instead. Renamed to the
live names; YMF_Settings_patrolBaseZoneSize dropped (no such setting exists).

Two of the dead values disagreed with their addon defaults -
enableVehicleRadios (file true, default false) and patrol_base kitRange (file
3, default 5). Reviving a line that never worked must not change a server's
behaviour on its own, so both are written at the DEFAULT with a comment
saying what the old line wanted. Flip them on purpose if that is still the
intent.

