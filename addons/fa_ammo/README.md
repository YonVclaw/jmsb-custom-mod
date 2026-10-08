# Future Ammunition

`jmfsb_fa_ammo`

Adds the "Future Ammunition" briefing subject to a unit's map Notes tab, with one record per caliber / family. Runs client-side for the local player (see XEH_postInit), and re-runs on respawn since diary records live on the unit object.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_fa_main`
- `jmfsb_notify`
- `cba_main` _(external)_
- `ace_ballistics` _(external)_
- `A3_Weapons_F_Mark` _(external)_

## Ships

2 functions.

## CBA settings

| Setting | Type | Name |
|---|---|---|
| `jmfsb_fa_ammo_enableBreaching` | CHECKBOX | Enable Mk353 BRC Breaching Script |
| `jmfsb_fa_ammo_debugBreaching` | CHECKBOX | Debug Mk353 BRC Breaching |

## Functions

<details><summary>2</summary>

- `jmfsb_fa_ammo_fnc_addDiary`
- `jmfsb_fa_ammo_fnc_breach`

</details>
