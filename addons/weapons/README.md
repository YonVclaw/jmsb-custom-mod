# Weapons

`jmfsb_weapons`

Weapon classes and adjustments over the base game's.

**The MX family and the Mk200 run cooler under ACE overheating** (user,
2026-08-29: "reduce the cook off chance with the MX's"). ACE heats a barrel by
`energy / (barrelMass x 466)` and cools it at a rate in which barrel mass
cancels, so barrel mass is the one lever on where a weapon settles under
sustained fire; the chambered round cooks off past 180 C. Each weapon gets an
explicit `ace_overheating_barrelMass` - which ACE 3.21.2 reads before it falls
back to inventory mass / 40 - at **2 x the base game's fallback**. Every round
adds half the temperature and the sustained rate of fire that stays under the
ignition line doubles.

**No inventory mass is changed.** The first version also wrote a heavier
`WeaponSlotsInfo` mass; `ace_realisticweights` loads after this addon on this
server and overwrote it anyway, so the "mass gain" never reached the game. The
carried weight is whatever the load order says; the barrel mass is explicit and
the load order cannot touch it.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `cba_jr` _(external)_
- `A3_Data_F_Decade_Loadorder` _(external)_
- `jmfsb_main`
- `A3_Weapons_F` _(external)_
- `A3_Weapons_F_Machineguns_M200` _(external)_
- `A3_Weapons_F_Mark_Machineguns_M200` _(external)_

## Ships

2 unit classes, 247 weapon/item classes.
