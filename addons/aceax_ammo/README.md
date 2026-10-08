# ACEAX Ammo

`jmfsb_aceax_ammo`

Arsenal Extended, for ammunition. The mission arsenal lists **1025 magazines**,
and a large share of them differ from a neighbour only in the colour the tracer
burns or the colour of the magazine body. Those are the same item in a
different paint and they cost a row each.

This folds them **by round type: 95 families, 1033 rows down to 243**, with the same option
panel under the list that the attachments get - one row of buttons per axis a
family varies on (Tracer: Red / Green / ..., Finish: Black / Tan / ...), in
ACEAX's own geometry and colours, so the three option panels in the arsenal
read as one feature (user, 2026-08-29: "the ACEAX accessories should include
the ammo").

Its **data** covers every magazine the mission fields — 95 families over 885
classes. Its **runtime** collapses two panels: grenades and explosives. The four
weapon-magazine panels are `@aceaxatt`'s since 1.1.0.0, and it reads this
addon's data to do them. Grenades matter as much as rifle ammunition here: the
smoke, chemlight and flare colour families live there.

## What is ours and what is ACEAX's

**It was all ours.** ACE Arsenal Extended had no concept of a magazine: the
toolchain knew primary/handgun/launcher, the six worn-gear tabs and the four
attachment slots over `CfgWeapons`, `CfgVehicles` and `CfgGlasses`, and
`@aceaxatt` reported "not my slot" for every magazine panel. The data was still
written in ACEAX's own `XtdGearModels` / `XtdGearInfos` schema, on the reasoning
that it would already be correct if ACEAX ever grew the feature.

**It grew the feature.** `@aceaxatt` 1.1.0.0 (2026-08-30) answers
`"CfgMagazines"` for IDCs 3002, 3004, 30 and 32 and collapses them off this
addon's data — `aceax_gearinfo` was always parameterised by config root, so
ACEAX core needed no change at all. Those four panels are now theirs, and this
addon no longer touches them.

**What is left here** is the data, which is the only
`XtdGearInfos >> CfgMagazines` in the load order — their magazine support folds
nothing without it — and the runtime for `IDC_buttonThrow` (34) and
`IDC_buttonPut` (36), which their own `defines.hpp` calls "deliberately NOT
handled ... the toolchain does not generate data for them". Ours does.

The original reasoning, kept because it is why the data was portable: it
addon's data is already correct for it.

## What folds and what does not

**One row per round type in one magazine form** (user, 2026-08-29: "the ammo
should be by type like 328 or 329 etc"): `100Rnd 6.5mm Mk328`, `100Rnd 6.5mm
Mk329`, `30Rnd 5.56 Mk332 AP`, `30Rnd 6.5mm Mk329 (MSBS)` are each a row, and
under each the option panel offers what does not change what the round does -
**Tracer** (Ball / Red / Green / ... / IR), **Finish** (Default / Black / Khaki
/ Tan / Sand ...), and for smoke, flares and chemlights their **Colour**.
Calibre, capacity, magazine model and the load (`Mk332_AP` vs `XM891_CTEP`)
stay apart: those are what the player is choosing between on purpose - the same
line the attachment compat draws when it refuses to put two calibres of
suppressor in one row.

**The names had to be tokenised, not peeled.** The first generator stripped
suffixes, and the classes do not nest that way: the finish sits *before* the
tracer marker (`..._Mk328_Black_T_Red`), the FA tracer marker is `_T_<Colour>`
with the ball round carrying nothing, and the smoke and flare colours are
CamelCase compounds (`SmokeShellBlue`, `FlareCIR`). So one round type came out
as four rows - `Mk328`, `Mk328 T`, `Mk328 Black T`, `Mk328 Khaki T` - and the
ball round was never in its family at all. `tools/gen_aceax_ammo.py` now reads
every token as a tracer marker, a finish, a colour or part of the stem, and the
stem is the family; `--report` prints every family with its members.

## Two panel controls, not one

The single thing most likely to break this: **which control holds the rows is
decided by the LEFT panel, not the right one.** ACE fills a plain listbox
(IDC 14) and then swaps to the listnbox (IDC 15) when the left panel is a
uniform, vest or backpack. Read the wrong one and you find zero rows and
silently do nothing, which looks exactly like the data being wrong.

`fnc_panelControl` is the only place that decision is made.

## How it works

`ace_arsenal_rightPanelFilled` fires partway through ACE's fill - before it
re-sorts and before it restores the selection - so the collapse is deferred one
frame, at which point ACE has completely finished; the timing `@aceaxatt` uses.
It collapses the **list**, never `ace_arsenal_virtualItems`: magazine
compatibility is per weapon, so a representative chosen once and globally could
be one the selected weapon does not take, and the whole family would vanish.
Nothing of ACE's state is written.

**The rows are the truth.** Which row survives, and what the option panel may
offer, are both decided from a snapshot of the panel: the buttons offer only
the values of variants that were *in* the list - ACE had already filtered it by what the
weapon takes and what the arsenal carries - never the family's whole roster
from config. The highlighted row survives if it is in the family; otherwise the
variant the player last picked for that family, so moving to another weapon and
back keeps the tracer colour; otherwise the first row, in ACE's own order.

**Pressing a value loads it.** A value resolves the way ACEAX resolves one: the
member with that value and the row's current values on every other axis, or -
drawn in the weak-match wash - the nearest member that has it at all. The
surviving row is rewritten to name it, and then ACE's own selection handler is
called on that row, exactly as `@aceaxatt` does for an attachment - rewriting a
row fires no `LBSelChanged`, and neither does clicking a row that is already
highlighted, so without that call the pick changed nothing until the player
clicked away and back. The panel reads the highlighted row's own data rather
than a row-number map, because ACE re-sorts the list in place when the sort
changes and raises no event for it.

**Sharing the column with `@aceaxatt`.** Both seat their panel under the same
list by shortening it, and this addon runs last — two frames after the fill
against their one, later-registered on the click. That was harmless while they
only claimed attachment slots. Since 1.1.0.0 they claim the four
weapon-magazine panels too, so running last became a liability: restoring the
list to full height on any panel that is not ours would drop *their* options
panel out from under *their* list. `fnc_onRightPanelFilled` therefore restores
the height only when `GVAR(built)` says this addon is the one that shortened
it.

## Regenerating

`XtdGearModels.hpp` and `XtdGearInfos.hpp` are **generated — do not hand-edit**.

```
python tools/gen_aceax_ammo.py
```

It reads the mission's own `config\arsenal\common\magazines.hpp`, so re-run it
after changing what the arsenal offers. The axes it peels are the tables at the
top of that script.

Display names are deliberately **not** baked in — the runtime reads them from
config when it draws the panel. Several of these magazines come from CDLCs
whose configs are encrypted, so a build-time dump cannot see their names; the
attachment compat needs a whole in-game item dump for exactly this reason, and
reading at runtime sidesteps it.

## Settings

**ACE Arsenal → Ammunition → Collapse ammunition variants** - off restores every
magazine to its own row. **Log the ammunition collapse** writes what every
collapse saw and did to the RPT (which control held the rows, how many, which
families folded and which row each kept) - turn it on before reporting that the
panel did not fold, because the log is the difference between "the data is
wrong" and "the script never ran".

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_main`
- `ace_arsenal` _(external)_
- `cba_settings` _(external)_

Carries `skipWhenMissingDependencies` - the PBO is skipped rather than breaking the load order when something above is absent.

## Ships

11 functions.

## Functions

<details><summary>11</summary>

- `jmfsb_aceax_ammo_fnc_buildIndex`
- `jmfsb_aceax_ammo_fnc_buildOptions`
- `jmfsb_aceax_ammo_fnc_collapsePanel`
- `jmfsb_aceax_ammo_fnc_layout`
- `jmfsb_aceax_ammo_fnc_onRightPanelFilled`
- `jmfsb_aceax_ammo_fnc_onValueButton`
- `jmfsb_aceax_ammo_fnc_panelControl`
- `jmfsb_aceax_ammo_fnc_pickVariant`
- `jmfsb_aceax_ammo_fnc_refreshChecks`
- `jmfsb_aceax_ammo_fnc_refreshOptions`
- `jmfsb_aceax_ammo_fnc_resolve`

</details>
