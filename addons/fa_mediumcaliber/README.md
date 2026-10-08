# Future Ammunition - Medium Caliber

`jmfsb_fa_mediumcaliber`

Applies proximity-burst effect and distance-scaled damage to all UAVs and infantry within the lethal radius (drones for counter-UAS, infantry for defilade defeat). Routes damage via remoteExec for non-local targets. Generalized from the anti-drone module's fnc_detonateAD.sqf.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `ace_ballistics` _(external)_
- `jmfsb_fa_main`
- `cba_main` _(external)_

## Ships

3 functions.

## CBA settings

| Setting | Type | Name |
|---|---|---|
| `jmfsb_fa_mediumcaliber_factionScaling` | CHECKBOX | Enable Faction Scaling |
| `jmfsb_fa_mediumcaliber_greenFraction` | SLIDER | Green (Independent) Faction Fraction |
| `jmfsb_fa_mediumcaliber_redFraction` | SLIDER | Red (OPFOR) Faction Fraction |
| `jmfsb_fa_mediumcaliber_cuasCeiling` | SLIDER | Counter-UAS Effectiveness Ceiling |
| `jmfsb_fa_mediumcaliber_enableAirburst` | CHECKBOX | Enable Scripted Airburst |

## Functions

<details><summary>3</summary>

- `jmfsb_fa_mediumcaliber_fnc_detonateShell`
- `jmfsb_fa_mediumcaliber_fnc_initEngine`
- `jmfsb_fa_mediumcaliber_fnc_trackShell`

</details>
