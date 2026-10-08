# aegis_port

**Seed mode, 2026-10-04 (the one in use).** The full import below was taken out on 2026-10-01
("make sure all aegis imported is removed"). When the Aegis family then left the load order
(user, 2026-10-04: "fix what you can"), the port came back in seed mode: only the classes jmfsb's
own faction addons name are imported, with what they need, and the factions are pointed at them.

Since 2026-10-05 ("also add back all the vehicles and weapons from opensource aegis/atlas") the run adds
`--full vehicle,weapon,accessory`: beside the seeds, every vehicle and weapon the full import brings (own
model only, the 2026-09-13 rule), public under jmfsb_blue/red/green and folded one vehicle per type
(2026-09-14). The seeds stay hidden; `seed_map.py` passes the same `--full`.

```sh
python tools/aegis_port/port.py --seeds tools/aegis_port/seeds.txt --full vehicle,weapon,accessory --plan
python tools/aegis_port/port.py --seeds tools/aegis_port/seeds.txt --full vehicle,weapon,accessory
python tools/aegis_port/seed_map.py            # work/aegis_seed_map.json: source name -> jmfsb addon and name
python tools/aegis_port/repoint_factions.py    # factions (and fa_aegis) name the imported classes
```

`seeds.txt` is the Aegis/Atlas list of `work/aegis_removal.md`. Seed mode differs from the full import:

- **Soldiers come in** (into `uniform`), and with them their kit - uniforms, vests, headgear, weapons,
  backpacks, NVGs, facewear, magazines - since the factions' men are built on them.
- **Vehicles and weapons on base-game models come in** (a seed is there because a faction uses it), and
  so does the FAMAS family (the factions carry it, user 2026-10-01). Its GL models name Aegis's
  withdrawn M203 textures and animation include: the launcher gets a plain dark finish
  (`emit.WITHDRAWN`) and no leaf-sight animation.
- **No collapsing, and every imported vehicle and soldier is hidden** (scope 1): the faction classes on
  top are the units. Gear keeps its scope, so it shows in the arsenal.
- **Western Sahara stays named.** A class filed under one of its factions comes in when its parents and
  model are the base game's; its desert uniforms, backpacks and texture paths (`lxWS\...`) are kept as
  written, since jmfsb's factions already build on that DLC. Classes built on its encrypted classes,
  and Aegis's EF/RF compatibility classes (not in the public sources), stay out - `--plan` lists them.
- **A soldier's magazines go into `weapons`**, or `uniform` and `weapons` would require each other.
- `fa_aegis` now builds its FA magazines on the imported magazines and wells and requires
  `jmfsb_weapons` instead of Aegis (it was skipped without Aegis, and `fa_tiers_mods` with it).
- **Pruning** (`prune_seeds.py`, after Turkey, Russia and China moved onto other mods the same day) keeps
  only what jmfsb still names - from other addons and from the five addons' own files. Run
  `seed_map.py` on the full list first, so the map knows every class.
- **The takeover is one-way.** A bare declaration the import restates is deleted from the addon's own
  file; when a later, smaller import stops restating it, the class is left undeclared (L-C04). Before a
  run that imports less, put back the declarations c47d7484 had (`git show c47d7484:addons/<a>/...`).

Imports the Aegis, Atlas and OpF vehicles, weapons, vests, uniforms and headgear into jmfsb's
own addons, with every model, texture, material, sound and animation they use. Nothing
requires Aegis, Atlas or OpF afterwards, and no class is named after them. Sources: the public
[A3_Aegis_Public_Releases](https://github.com/senicluxus/A3_Aegis_Public_Releases) repository,
APL-SA like jmfsb. Every class keeps its original author.

## Running it

```sh
python tools/aegis_port/vanilla_config.py         # after a game update: the base game's classes, into vanilla_config.cache
python tools/aegis_port/port.py --census          # what the sources hold, by kind and by model
python tools/aegis_port/port.py --plan            # what comes in, where, and why the rest does not
python tools/aegis_port/port.py --dry             # everything except writing; the log lands in port_report.json
python tools/aegis_port/port.py                   # write it
python tools/aegis_port/port.py --configs-only    # rewrite the configs, leave models/ as copied
```

A re-run replaces what the last run wrote: the `models/` folder of each target addon (it
carries a `GENERATED.txt`, and the port refuses to delete one that does not), the
`imported_*.hpp` files, their `#include` lines, and the lists between the markers in each
`config.cpp`.

`SRC` in `source_config.py` is the clone of the sources; `A3` and `CBA` in `vanilla_config.py`
are the game and the CBA workshop folder.

| file | what |
|---|---|
| `vanilla_config.py` | reads the base game's and CBA's `config.bin` out of the installed PBOs into a class tree, plus every file path the game ships |
| `source_config.py` | preprocesses (`#include`, `#define`, `##`) and parses every source addon into the one merged config the game would build |
| `port.py` | decides what comes in and where (`--census`, `--plan`) |
| `emit.py` | writes it: the classes, the base-game ancestry they need, the files, the wiring |
| `vanilla_strings.json` | the game's stringtable, so `$STR_` keys can be written as text |

## What comes in

| kind | addon |
|---|---|
| vehicles: cars, armour, boats, helicopters, planes, drones, static weapons | `vehicle` |
| rifles, pistols, launchers, and weapon accessories | `weapons` |
| vests | `vests` |
| uniforms, and the soldier class each one needs | `uniform` |
| headgear | `headware` |

**Vehicles and weapons come in only on a model the import brings in** (user, 2026-09-13: "you
were not supose to import any vechicle that had a base game p3d", then "no vechicles no weapons,
vests uniforms and headgear are ok"). A vehicle or weapon that is new paint on a base-game model
stays out; so does an accessory on one, unless an imported rifle comes fitted with it. Vests,
uniforms and headgear keep their base-game-model variants. A backpack in a vehicle's cargo is
not pulled in (backpacks were not asked for); a static weapon's own assembly bags are.

With each class comes everything it needs, into the same addon: its parents, magazines, ammo,
magazine wells, recoils, sound sets and shaders, reload gestures, crew poses and particle
effects. Factions are not: everything goes under `jmfsb_blue`, `jmfsb_red` or `jmfsb_green` by
side (see below). Assets go under the addon's `models/<source folder>/`, keeping the sources'
folder layout, so a `model.cfg` still sits beside and above its models.

**Left out:** Atlas's FAMAS family - the F1, G2 and G4, their grip, M203 and preset versions, and
their magazines, magazine well, reload gesture and magazine proxy (user, 2026-09-13: "you can
remove the FAMAS"; its M203 versions dress the launcher in Aegis's M4A1 M203 textures, which Aegis
deleted from the public repository in January 2025, commit 74aca1a9); a class whose model was
removed from the public repository (the SR25 family, the
KBT rigs, the IVAS, and what inherits them); a class built on a creator DLC, including Aegis's
Western Sahara variants - named `*_lxWS`, filed under one of that DLC's factions (NATO desert,
SFIA, ION, Tura), or with a turret that still fires its weapons (the 2S90M cannon variants) - whose
turrets, sounds and textures are that DLC's; the
sources' own compatibility addons for Western Sahara, Reaction Forces and Expeditionary Forces;
deprecated aliases kept for old missions. `--plan` lists every one with its reason.

## What it writes into each addon

- `imported_config.hpp`, `imported_root.hpp`: tables the addon does not open itself, and the
  weapon modes, rail slots and effects that live at the config root.
- `imported_<Table>_decl.hpp` and `imported_<Table>.hpp` for a table the addon already opens
  (`CfgWeapons`, `CfgVehicles`): the declarations go at the top of the addon's block, the
  imported classes after the addon's own - or before them, where the addon's classes inherit
  imported ones (headware).
- In `config.cpp`: the includes, the imported classes in `units[]`/`weapons[]` between markers,
  and `A3_Data_F_Decade_Loadorder` (plus `cba_jr` where a rail slot is inherited) in
  `requiredAddons`.
- **A bare declaration in the addon's own block** (`class Rifle_Base_F;`) that the import has
  to restate moves into the declarations file; HEMTT rejects the same class written twice.
  Nothing the addon defines is touched.
- **headware only:** its FAST-MT paints inherited Aegis's helmet. They now inherit the
  imported one, their icons point into `models/`, and the Aegis requirement is gone.

## The decisions, and why

- **The config is expanded before it is read.** The sources build item holders out of
  token-pasting macros and write scope and side as names. The earlier port matched raw text
  and missed every class written through a macro. Arma's `##` is not C's: it disappears
  without eating the space beside it (`class ##a##`).
- **The base game's own config decides what is vanilla,** read from the installed PBOs, not a
  name list: the port needs parents to restate an ancestry, sides to pick crews, and file paths
  to tell a base-game texture from a DLC one.
- **A creator-DLC addon is one that sets `skipWhenMissingDependencies`** and requires a patch
  nobody defines. Aegis's main addons list Western Sahara's patches too, only to load after it.
- **Every texture beside a model comes with it,** not just the ones a config names (user,
  2026-09-12: "bring in all textures for any assit imported", "bring in all uniform textures
  and vest and helment textures").
- **Three factions, by side** (user, 2026-09-13: "all the factiosn you just imported, replace
  them with jmfsb_blue, jmfsb_red and jmfsb_green"). The mods' factions are not imported. Every
  imported vehicle and soldier - whatever faction the sources filed it under, theirs or the
  game's - goes under `jmfsb_blue` (side 1), `jmfsb_red` (0) or `jmfsb_green` (2), defined in the
  vehicle addon with the base game's side art; civilians go to the game's own `CIV_F`. A class
  whose side cannot be read keeps the faction it had, and the port lists it.
- **One vehicle of each type per jmfsb faction** (user, 2026-09-14: "in jmfsb_red/blue/green only have
  one of each type of vechicle and make sure all the textures are avaiable in the vechicle
  customation"). A type is what Eden cannot change: model, nearest base class, hull and turret
  weapons, pylon slots. Classes that differ only in paint, crew, cargo or default pylons fold into
  the one with the plainest name; the rest stay in the config hidden (scope 1), because faction
  addons build on them. Every paint the folded classes wore that the kept class does not already
  offer becomes a TextureSources entry on it, open to every faction, so Eden's appearance menu lists
  them all. Civilians are left as they are. `emit.collapse_vehicles`; the port log lists each group.
- **Crews are not kept** (asked 2026-09-12). A crew becomes the base game's crewman, pilot or
  UAV AI for the same side, because the mods' soldiers wear gear that was not imported.
- **A uniform's soldier is hidden** (scope 1). The uniform needs the class; Aegis's unit
  rosters were not asked for.
- **Names:** the mod prefix comes off and `GVAR` goes on, so `Aegis_arifle_X` becomes
  `jmfsb_weapons_arifle_X`. A name that is still taken, by jmfsb's own class or by a copy that
  could not be dropped, gets `_2`.
- **Duplicates are dropped, not numbered** (user, 2026-09-13: "Keep Aegis's version"). With the
  prefix off, two kinds of source class land on one name: the old name a mod kept as an alias
  when it renamed a class (`arifle_RFB_F` beside `Opf_arifle_RFB_F`), and an item both Aegis and
  Atlas make. The alias goes, a hidden copy beside a public one goes, and where two mods make
  the same thing Aegis's copy stays. Where jmfsb already has its own class of that name (its
  JSOC stealth uniforms, MTP carriers, FAST-MT covers) jmfsb's wins. Classes built on a dropped
  copy move onto the copy kept when both are the same model - Atlas's own paint variants of the
  AAF MRAP sit on Aegis's MRAP and keep their textures - and every reference to a dropped copy,
  a faction or a cargo magazine, is turned to the one kept. Only a copy with a different model
  and classes of its own on it stays, and then the public class keeps the unnumbered name.
- **A reference to a class that did not come in is removed,** never left dangling: a linked
  optic whose model is gone leaves the rifle without it. A path into a creator DLC's data is
  emptied the same way.
- **The base-game ancestry is restated,** because HEMTT (L-C04) only follows inheritance
  through classes the config writes. The nearest base-game ancestor that holds a nested class
  is restated with its real parent and a declaration of that class, only as deep as needed and
  declarations first - the way `addons/naval` does by hand. A class restated without its
  parent is cut off from it.
- **Spelling follows the definition.** HEMTT holds a parent to the case of its definition
  (L-C05); the game writes `class default;` in one place and `class Default {` in another, and
  the sources write `class Components: components`.
- **A paint scheme the sources added to a base-game vehicle** is written out in full on the
  imported vehicle, since that edit to the base game is not imported.
- **Additions to base-game classes are mirrored.** Where the sources add their magazines to a
  base-game magazine well, their optics to a rail, or their reload to an action, the port adds
  the imported ones.
- **Values are written the way HEMTT's help lints want them.** A quoted string HEMTT can work
  out as math (L-C12: `"-0.22-0.015"`, `"-rad(30)"`, `"8 + 16"`) is written as the number HEMTT
  would store; `emit.py` ports HEMTT 1.21.0's evaluator token for token, so what changes is
  exactly what it flags. Words a player reads - display names, descriptions, tooltips - stay
  words, even where they parse ("7.62-51"). `"_this call f"` becomes `"call f"` (L-C13) where every
  `_this` in the string is that one: `call` hands on the caller's `_this` either way.
- **model.cfg files that land in one folder are merged** (found in game, 2026-09-13: an Aegis vest
  drawn at the wearer's feet). Aegis's and Atlas's Vests, Headgear and Uniforms folders, OpF's
  Uniforms and both mods' DynamicLoadout pods share a folder in jmfsb; written one after the other,
  the last model.cfg won and every model only the others defined was binarized without a
  skeleton. Every skeleton and model class now goes into one file, first come first kept; a shared
  base two mods write differently (Aegis's `ArmaMan` is not Atlas's) is kept once per mod, the later
  one renamed after its mod along with its uses.
- **Proxies are followed.** A model names its proxies without an extension
  (`proxy:a3_aegis\...\Main_Rotor_Blur_F.001`); they are rewritten into jmfsb and the models they
  name are copied - rotors, wrecks, the Merlin's switch panel.
- **Materials name `.paa` textures.** The sources' materials name the `.tga` working files; BI's
  packer rewrites those to `.paa`, HEMTT does not, and the game could not load the materials.
- **Damage and wound materials have no leading backslash** (found in game, 2026-09-13: "Cannot
  load material file" for all fifteen of the BTR-100 export's). The sources and the game write
  `mat[]` entries as `A3\...rvmat`; the port had put a `\` in front, and the game failed every
  material in those lists while the model loaded the same files by the same path without it.
- **Two mods adding to one array keep both additions** (`source_config.merge`). Aegis and Atlas each
  `magazines[] +=` a 25mm pylon pod onto the game's `gatling_25mm`; the later one used to replace the
  earlier, so Aegis's pod came in naming a weapon that refused it ("wrong 'pylonWeapon'").
- **A uniform comes in only with its soldier.** The soldier class is what a uniform puts on the
  wearer; ten Aegis, Atlas and OpF uniforms have soldiers built on Western Sahara's encrypted
  soldiers, which stay out, and came in unwearable (ACE: "has invalid uniformClass"). They now stay
  out with them; `--plan` lists them.
- **A rail addition takes the form of the game's slot.** The sources add their pistol lights to
  `PointerSlot_Pistol` with `compatibleItems[] +=`, but the game writes that slot's list as a
  class, so it logged "Cannot update non array from array" and added nothing. Where the game's
  slot, or its nearest parent that has one, writes a class, the items go in as class entries.
- **A vehicle's launcher comes with its pylon or turret** (the Vikhr, Vorona and AGM-154 launchers):
  they descend from LauncherCore like a soldier's launcher, and were being left for the soldier
  weapons pass, which skips vehicle guns.
- **`magazines[] +=` on a base-game weapon is mirrored**, like the other additions: Aegis hands its
  20-round rocket pod to `rockets_Skyfire` that way.
- **The Contact folder is not the base game.** It loads only with the Contact DLC switched on, and
  counting it let Aegis's 25x40mm ammo pass for the game's own (`vanilla_config.py`).

## Known gaps

- Imported models name base-game textures and materials that HEMTT has no game data to find
  (BBE4/BBE5). Copies of them sit in `include/a3`, taken from the unpacked game data in
  `Documents\Arma 3 Projects\a3`; a `.tga` a model names is the game's `.paa` under that name, as
  `include/a3` already did. After a re-run, copy in whatever new paths `hemtt check` names.
- The XM25's custom sight overlay and airburst programming are Aegis scripts and UI. They are
  not ported, so the XM25 fires as a plain grenade launcher.
