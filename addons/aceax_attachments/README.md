# ACEAX Attachments

`jmfsb_aceax_attachments`

Attachment merging for the ACE arsenal's right panel. ACE3 Arsenal Extended
groups similar items behind dropdowns, but only in its ten left-panel tabs -
attachments are explicitly skipped, so every optic, laser, muzzle device and
bipod gets its own row. The **@aceaxatt** extension is the runtime that
collapses them; this addon is the data that says which are variants of which.

Covers what the mission arsenal lists (`config\arsenal\common\items_optics`,
`_muzzles`, `_pointers_lights`, `_bipods`): **58 entries over 233 classes**,
across the base game, JCA, ACE, the CDLCs and this mod's own optics.

Colour finishes fold into one row. Beyond colour: the Aimpoint Micro R-1's
high/low mount, JCA's flip magnifier, EF's remote-display MBS and pistol
MicroSight, the weathered DMS and the ASP-1 Kir, ACE's red/green pointers.
Calibers are **not** a dropdown - a 5.56 can and a 7.62 can are different
items that fit different weapons, so each keeps its own row.

Without ACEAX the data is inert; without `@aceaxatt` nothing reads the
attachment half. Neither is an error, and neither is required to load.

## Regenerating

`XtdGearModels/` and `XtdGearInfos/` are **generated - do not hand-edit**.

The hand-written half lives in `tools/aceax/`:

| | |
|---|---|
| `overrides.yml` | the grouping rules - every judgement call about what merges and on which axis |
| `mod.yml` | which arsenal this covers |
| `dump_arsenal.py` | builds the toolchain's `_dump/arsenal.json` from an in-game item dump |

The generator itself is GrueArbre's / DiGii's shared ACEAX toolchain in
`D:\Git\AceArsenalExtended-Attachments	ools` (the `.py` files there carry no
mod identity and are meant to be copied). To regenerate: copy those `.py`
files and this directory's three files into a scratch working folder, then

```
python tools/dump_arsenal.py --rpt D:\Git0\work\orbat_dump_<date>.rpt
python tools/gen_aceax.py --check --list     # iterate on overrides.yml
python tools/gen_aceax.py
```

and copy the resulting `addons/main/XtdGear*` over the trees here, keeping
`overrides.yml` back in `tools/aceax/`. The in-game dump is required because
the CDLC configs are encrypted - the game is the only source of their display
names.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_main`
- `aceax_gearinfo` _(external)_

Carries `skipWhenMissingDependencies` - the PBO is skipped rather than breaking the load order when something above is absent.
