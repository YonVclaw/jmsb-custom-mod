# Headware

`jmfsb_headware`

Our paints on Aegis's FAST-MT, and our boonie hats and balaclavas.

**The FAST-MT is Aegis's, linked, not copied** (user, 2026-08-29: "things
copied from Aegis or Atlas need to be removed and the dependencies moved back to
linking to Aegis/Atlas"). This addon used to ship the three FAST-MT models, their
materials and maps, and the tan / ranger-green / black / coyote helmets, headsets
and covers - all of them Aegis's own. They are gone; `Aegis_H_Helmet_FASTMT_*`
are the classes to reach for. What is left is ours: the Multicam, Multicam
Alpine, Multicam Woodland and US OCP paints, and the MTP / tropic / woodland /
desert cover paints, each inheriting `Aegis_H_Helmet_FASTMT_base_F` (or the
headset / cover base) and putting its own texture on Aegis's model. Aegis's
headgear addon is a required addon; without it this PBO is skipped.

The boonie hats (Multicam, Alpine, Woodland, the solids, OCP) sit on the base
game's boonie and the balaclavas on the base game's; none of that is Aegis's.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `A3_Data_F_Decade_Loadorder` _(external)_
- `jmfsb_main`
- `ace_hearing` _(external)_

Carries `skipWhenMissingDependencies` - the PBO is skipped rather than breaking the load order when something above is absent.

## Ships

35 unit classes, 56 weapon/item classes.
