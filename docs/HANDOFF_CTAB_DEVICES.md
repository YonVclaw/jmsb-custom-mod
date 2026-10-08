# Handoff — cTab Device Suite (`ctab_devices` + friends)

_Last updated: 2026-08-05, build **0.1.0.502**. Author: YonV._

This documents the state of the cTab-based device work in jmfsb, how the moving
parts fit together, and — in detail — the issues hit along the way, because
most of them will bite again if the mechanisms below are treated casually.

---

## 1. What this is

JMSB replaces cTab's devices with its own, **in place**. cTab's android IS the
S23 handheld, cTab's tablet IS the GFT-1 rugged tablet, cTab's FBCB2 IS the
FBCB4 vehicle screen. There are deliberately no parallel devices: an earlier
attempt at side-by-side devices produced duplicate ACE entries, skin races and
displays inheriting the device they were meant to replace.

The loaded cTab is the **workshop build "cTab Advanced 2.8.0.7"** — not the
repo at `O:\GIT\cTab` (close, but differs) and not BCE's fork. The player runs
TWO workshop cTabs; 2.8 wins the load order. Unpacked reference of the loaded
build: `c:\Users\jwise\play\ctab` (partial), repo reference `O:\GIT\cTab`.

### The addons

| addon | what it is |
|---|---|
| `addons/ctab_devices` | (renamed from `ctab_s7` 2026-08-05) the whole device suite: S23/GFT-1/FBCB4 reskins, app pages, live tiles, scanner readout, alarms, settings, embedded intrusion page, the cTab function forks |
| `addons/ctab_tools` | seven map drawing tools (compass, distance, profile, sight, buildings, grid, find-flat), ported from BCE's Compat_MapTools (Aaren, APL-SA, attributed); no PLP/BCE dependency remains |
| `addons/ctab_ace` | ACE map-gesture pointers drawn on the device maps (ported from BCE Compat_ACE, pointer half only) |
| `addons/ctab_groups`, `ctab_templates` | earlier work: group messaging + report templates (see memory/docs) |

Related: `jmfsb_hacking` (the intrusion suite the tablet page drives),
`jmfsb_notify` (on-screen notifications the mirror feeds).

---

## 2. Load-bearing mechanisms — do not casually change these

### 2.1 Function forks via CfgFunctions (the ONLY way to overwrite cTab)

cTab compiles its functions **final** (CBA PREP + compileFinal). Runtime
reassignment (`cTab_fnc_x = {...}`) is refused by the engine and kills the
calling script. BCE-style CfgFunctions re-pointing *inside cTab's config*
doesn't exist in the 2.8 build. The working mechanism, proven twice:

```
class CfgFunctions { class cTab { class Functions {
    class updateInterface { file = QPATHTOF(ctab_fork\fn_updateInterface.sqf); };
    class aceSelfActions  { file = QPATHTOF(ctab_fork\fn_aceSelfActions.sqf); };
};};};
```

Declared in *jmfsb's* config, compiled by the functions library **before**
cTab's PREP pass — cTab's own compile is then refused with one harmless RPT
line ("Attempt to override final function"). Forked so far:

- `fn_updateInterface.sqf` — the interface redraw. Carries every hide/show
  list, the jmfsb app modes, and the first-draw skin stamp. JMSB changes are
  marked `JMFSB:`; everything else is cTab's code so a cTab update can be
  re-forked by diffing.
- `fn_aceSelfActions.sqf` — the ACE self-interact menu builder. Renames the
  device entries (S23 / GFT-1 / FBCB4 + icons) at the source. cTab's macros
  are resolved to globals (`ctab_core_androidDevices`, `localize
  "STR_ctab_core_*"`, `cTab_fnc_*`) because the file compiles in jmfsb's
  component. cTab's PREFIX is `ctab`, core COMPONENT is `core`.

### 2.2 The click mechanism (nothing else works)

**No config-declared dispatch fires on controls merged into cTab's dialogs.**
Not `action`, not `onButtonClick`, not control-level event handlers, not
buttons ctrlCreate'd inside a merged group. All four failed in game, silently.

The working path: `fnc_wireButtons` creates one invisible display-level
catcher per button (config class `GVAR(catcher)` — colours zeroed in config
because script cannot override the stock button's orange focus fill), and the
**display's own MouseButtonDown handler hit-tests the catcher rectangles**,
walking last-created-first, guarding on `ctrlShown` of the source control and
its parent group. Everything dispatches through `fnc_click` (0.25 s debounce).
`fnc_syncCatchers` (0.2 s PFH) keeps catcher visibility mirroring sources so a
hidden screen's catcher can't steal a press.

New button = one row in `fnc_wireButtons`'s table + a case in `fnc_click`.

### 2.3 Layouts, the measured glass, and the remap

Each device's case art has a **measured** screen hole (PIL, walking the
transparent pixels from the canvas centre — a plain alpha bbox lies because
the letterbox bands are transparent too). The numbers live as defines in
`script_component.hpp` (`S23_GLASS_*`, `GFT_GLASS_*`, plus cTab's authored
content rects `S7_OLD_*`, `TAB_OLD_*`). **Never guess these** — guessed
apertures cost a build where the map stopped short of the glass.

- `fnc_remapControls` — sweeps every **top-level** control whose config centre
  lies in cTab's authored content rect proportionally into the measured glass.
  Group children are group-relative and must NOT be remapped (double shift) —
  but they DO have to be **scaled**: `ctrlSetPosition` on a controls group does
  not resize its children, so a stretched group left cTab's message and compose
  screens at their authored size with dead glass beside them. The sweep records
  every `ctrlType == 15` control it resizes and scales that group's children by
  the same factors in a second pass. Runs once, against config positions,
  before explicit placements.
- `fnc_androidLayout` — S23, dialog AND HUD. **Never RESIZES the bezel**: the
  two displays use different grids and reading `ctrlPosition` of the bezel is
  what lets one function lay out both. Forcing the dialog rect onto the HUD
  display is what once blew the held-up phone to fullscreen. The HUD's bezel is
  *translated* (+10% w, −13% h of its own size) to lift the case off the bottom
  edge and the chat lines; the remap is then given the old rect and the new one.
- `fnc_tabletLayout` — GFT-1. DOES refit the bezel (the art's content runs to
  the canvas bottom; on cTab's grid the keyboard hung off screen), then remaps
  via oldRect→newRect. It measures the dashboard group **after** the remap —
  the sweep already scaled its children, and measuring first applied the
  stretch twice.
- `fnc_fbcb4Layout` — FBCB4; remaps cTab's FBCB2 furniture from its 810×810
  map rect, and refits the case the way the GFT does. cTab's own FBCB2 grid is
  `safezoneH * 1.6`, on which this art (opaque content 1394 of 2048, top 327)
  stood 109% of the screen tall with the top of the map off screen.

The **tools drawer** is shared by all three: cTab's map switches (467540–546)
and this mod's drawing tools (467550–557) on one backing (`IDC_S7_TOOLSBG`),
over the map, opened by a dotted key on each glass. `TOOL_IDCS` in
`script_component.hpp` is the single list the fork's show pass and all three
layouts read, so they cannot drift. They used to be two rows on the settings
page, which meant leaving the map to reach a tool that only acts on the map.
- `fnc_deviceLayout` — runs the right layout from each holder control's
  `onLoad`, resolving the device by `ctrlIDD` (dlg 177382, dsp 177383, tablet
  1775154, FBCB2 1775144). This exists because `deviceOpen` resolves through
  cTab state that isn't built at control-load time — without this hook the
  layout waited for the 1 s tick and the player watched the stock screen snap
  into shape.

  **THE HOLDER MUST BE THE LAST CONTROL IN ITS `class controls` BLOCK, and the
  layout waits a frame.** Controls are created in declaration order and
  `onLoad` fires as each one is made, so a holder near the top of the file runs
  while every control below it is still `controlNull`; `_fnc_place` exits
  silently on null and the `laidOut` guard then blocks the `deviceOpen` pass
  that would have worked. Everything stays at its config position — that is
  three rounds of "the changes aren't in the build" in one bug, introduced by
  this very hook. If a layout change appears to do nothing in game, check the
  placed control is declared *before* the hook that places it.

### 2.3b Day and night cases

`cTabIfOpen select 9` is `[dayTexture, nightTexture]`, indexed by `_nightMode`
on every night-mode pass. Each jmfsb case therefore ships a pair; the night art
is generated from the day art by `data/gen_night.py` — **regenerate it whenever
the day art changes**, or the night case is still the old picture.

The transform is cTab's own, measured off its `android_s7` and
`tablet_background` pairs across the tonal range rather than invented: a flat
linear RGB multiply of **×0.35**, alpha untouched, no hue shift.

cTab defaults `nightMode` to 2 (dim after dark) for the Tablet and Android
groups but **0 for FBCB2** — so the FBCB4 would carry a night case it could
never show. `XEH_postInit` edits that default in place through cTab's own
pairs helpers, which also turns on cTab's `_brightness * 0.7` screen dim for
that device at night.

### 2.4 deviceSkin — the standing guard

cTab rebuilds `cTabIfOpen` (texture table included) on every open **after**
our open hook, and repaints the bezel from it on night-mode passes. One-shot
fixes therefore lose. `fnc_deviceSkin`, called from the 1 s `deviceTick` AND
from the fork just before its first repaint, re-asserts:

1. the bezel texture (case art; S23 black/tan per CBA setting),
2. `cTabIfOpen select 9` (the table cTab repaints from),
3. the stored glass rect on IDs 1210/1201/1202 — and **logs
   `JMFSB ctab_s7: ... drifted`** (capped) when it had to correct geometry.

Those drift lines in the RPT are the tripwire: if they appear, something is
genuinely fighting the layout and it's time to reconsider a full cTab fork.
So far every "cTab is overwriting us" suspicion has turned out to be our own
arithmetic instead.

### 2.5 Z-order rule

Config controls draw in declaration order. The app pages are declared last in
each ui file "so they cover the map" — which means **anything that must stay
clickable on every screen (menu keys!) must be declared after them**, at the
very end of the file. The S23's menu key was buried by the radio page for
exactly this reason.

### 2.6 One display class per device

`ui_s23.hpp` patches `cTab_Android_dlg` + the RscTitles HUD display,
`ui_tablet.hpp` patches `cTab_Tablet_dlg`, `ui_fbcb4.hpp` patches
`cTab_FBCB2_dlg`. Each device gets its own file and its own control classes
(`s7*`/`f4*`/`tab*` GVAR prefixes) — sharing elements between devices broke
the S7 repeatedly before the rule existed. Only root-level templates (e.g. the
scan-row text class) are shared.

---

## 3. Build & verify workflow

- `hemtt check` then `hemtt build` from `o:\GIT\jmfsb`. Per earlier session
  notes the launcher loads `.hemttout\release` directly — if a fix doesn't
  show in game, first check WHICH output the modline points at.
- **`ctab_devices` has `[rapify] enabled = false`** (its dialog maths can't be
  rapified). Consequence: **hemtt never parses this addon's configs.**
  "Undefined base class" and "Member already defined" both sailed through a
  clean `hemtt check` and crashed the game at launch. After ANY config edit in
  this addon run:

  ```
  python tools/check_ctab_configs.py
  ```

  It catches duplicate members/classes per scope and ui-file parent classes
  missing their root forward declaration.
- Bump `addons/main/script_version.hpp` BUILD on every delivered change; the
  reply convention is to end with the version.
- The seven map tools + ui configs pass `hemtt check` SQF lints; the BCE-ported
  bodies still carry Aaren's style (tabs, commented-out blocks, one ~330-line
  function) pending a decision on reformatting to the ACE guidelines
  (https://ace3.acemod.org/wiki/development/coding-guidelines — house style).

---

## 4. Issues hit, in honest detail

Process failures first, because they produced the worst outcomes:

1. **Edited another mod's repo.** An earlier session modified `O:\GIT\cTab`
   in place. When challenged, the first response defended file timestamps
   instead of checking. Reverted with git, re-implemented in jmfsb. RULE:
   `cTab`, `BCE`, `ITC`, `ALiVE`, `play\*` are read-only references. Every
   change goes in jmfsb.
2. **Patched a file from memory instead of reading it.** Added
   `descriptionShort` to a class that already had one four lines down →
   "Member already defined" → hard crash at game launch. The summary I worked
   from didn't show the existing property. RULE: read the target class before
   inserting a property. (`check_ctab_configs.py` now also catches it.)
3. **Missed a root forward declaration.** `ui_fbcb4.hpp` inherited
   `cTab_FBCB2_background` with no root `class cTab_FBCB2_background;` →
   "Undefined base class" → hard crash. hemtt cannot see it (rapify off).
   The checker's parent cross-check exists because of this.
4. **Truncated grep hid live dependencies.** Ported BCE's map tools after
   grepping for external calls `| head` — four `BCE_fnc_getMarkerColor` sites
   and two BCE globals were below the cut. Claimed the dependency was gone
   when it wasn't. RULE: grep without `head` and read every ported file end to
   end. (Also found in the same audit: BCE's own colour code takes `param [1]`
   of an RGBA array — the green channel — a real BCE bug not to copy.)
5. **Wrong CBA API signature.** Called `CBA_fnc_addDisplayHandler` with a
   display class name; it takes an event TYPE — the engine rejected
   `"rscdisplaymainmap"` as an unknown enum twice per mission start. Hooking a
   named display is XEH's job (`Extended_DisplayLoad_EventHandlers`).
6. **Shell-heredoc byte corruption (recurring!).** Python heredocs turn `\t`,
   `\f`, `\a` in emitted strings into TAB/FF/BEL bytes. Symptoms: RPT paths
   printing mangled ("ctabddons", "dataeed"), "Picture not found" engine
   overlays that look like black boxes, and one corrupted memory file. The
   bytes are invisible in editors and grep output — scan raw bytes when a
   path looks wrong. Use `r''` strings / `chr(92)` joins when writing configs
   from python.

Technical traps, each burned into a mechanism above:

7. **`cTabIfOpen` is nil when closed** — `param` returns Nothing and poisons
   downstream `getVariable`s (3 errors/sec all mission). Everything reads it
   through `fnc_ifName`.
8. **`cTab_fnc_setSettings` third argument must be `true`** — false means "do
   not redraw"; modes changed invisibly and buttons read as dead.
9. **Guessed art apertures** (see 2.3) and **letterbox bands are transparent**,
   so naive alpha bboxes lie; the GFT's screen punch is alpha≈8, needing a
   threshold.
10. **The HUD display lives inside `class RscTitles`** — a root-level patch of
    the same class name is a different, dead class (one build shipped with no
    HUD scanner rows because of it).
11. **cTab's drag handles** (idc 5–8) existed all along, unreachable; the
    remap made them grabbable and dragging shifted everything. Hidden and
    disabled in the android layout. Their drag code lives in control-class
    mouse attributes, not in any named function — greps for a "mover" come up
    empty.
12. **Resizing a controls group does not resize its children** (GFT dashboard
    white bands). Scale children by the group's growth ratio.
13. **The GFT menu key never existed** — fork, layout and dispatch all
    referenced 467390/391, but the config classes died with a deleted file.
    Nothing warns about a `displayCtrl` that returns controlNull.
14. **ACE menu names rebuilt live** — cTab regenerates its self-interact
    children on every menu open, so renaming cached actions can't work; the
    builder itself is forked (2.1).
15. **Phantom template controls**: a template class declared inside a dialog's
    `controls` block is instantiated as a box at the origin. Templates live at
    config root.
16. **`QQGVAR` is nested-quoting only**; `QPATHTOF` is current-module only —
    cross-addon art needs `QPATHTOEF(module,path)`.
17. **Weather glyph sheet**: cells were mis-mapped and the tint layer was
    empty; regenerated by `tools/gen_wx_icons.py` splitting by colour (blue →
    tintable cloud layer, accents → detail layer). Several conditions have no
    cell on the sheet and are composed (overcast/snow/wind/fog/night).

## 5. Open items

- **Build 505 is the annotated-screenshot pass and none of it is verified
  in-game yet.** New in it: group-child scaling in the remap (the "fill the
  screen" fix), the tools drawer and its three keys, the HUD phone's layout
  hook and nudge, the FBCB4 case refit, the pinned jam/mesh header icons, the
  scanner column squared to cTab's hook readout, bigger message text, the
  erased S23 camera lens, the jmfsb logo on the FBCB4 case, and the FBCB4
  power key closing the dialog.
- **Everything since build ~477 is lightly tested or untested.** In-game
  verified so far: the click mechanism, the S23 dialog layout (glass, header,
  menu key), FBCB4 basic layout, GFT case fit. NOT yet verified: v12
  load-instant layout, drag-handle removal, menu-key z-order fix, GFT menu
  key existing at all, ACE menu rename fork, alarms suite, notification
  mirror, helmet cams (`ctab_camera = 1` on 18 headgear classes), split cam
  pages, MBS third sight, arsenal recategorisation, all seven map tools, ACE
  pointers, ACRE rack readout, rebuilt weather glyphs.
- **CBA keybind list still says "Configure S7 Android"** — registered inside
  cTab's script; unreachable from jmfsb without editing cTab.
- **GFT spec question**: user once spec'd "no function buttons, only the menu
  icon"; the tablet currently keeps the live-tile dashboard (which the menu
  key returns to). Standing decision with the user.
- **BCE-ported tool bodies vs ACE style guide** — reformat or stay diffable
  against BCE? Asked, unanswered.
- **`old/` directory** — stale copies of addons that keep ambushing searches
  (the loading-logo confusion came from there). Cleanup offered, unanswered.
- Settings/profile keys were renamed with the addon
  (`jmfsb_ctab_s7_*` → `jmfsb_ctab_devices_*`) — players' saved device prefs
  reset once.

## 6. Where things live

- Measured art + icons: `addons/ctab_devices/data/` (PNG sources alongside
  PAAs; `hemtt utils paa convert` refuses to overwrite — delete the PAA first).
- Generators: `tools/gen_wx_icons.py` (weather glyphs from the stock sheet),
  `addons/ctab_devices/data/gen_icons.py` (drawn app icons),
  `tools/gen_tablet_bezel.py`, `tools/check_ctab_configs.py` (run it!).
- cTab references: repo `O:\GIT\cTab` (read-only), loaded-build unpack
  `c:\Users\jwise\play\ctab`. BCE source `O:\GIT\Better-CAS-Environment-`
  (read-only, APL-SA — attribute Aaren on anything adapted).
