# Respawn

`jmfsb_respawn`

Respawn handling, including the force-respawn call a trigger can make:

    [west] call jmfsb_respawn_fnc_forceRespawn;

Only the dead are affected, which is why it is safe to fire from a trigger that
may run more than once.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_common`
- `jmfsb_notify`

## Ships

10 functions.

## CBA settings

| Setting | Type | Name |
|---|---|---|
| `jmfsb_respawn_enabled` | CHECKBOX | Enable respawn |
| `jmfsb_respawn_time` | SLIDER | Respawn delay |

## Functions

<details><summary>10</summary>

- `jmfsb_respawn_fnc_addZeusModules`
- `jmfsb_respawn_fnc_adjustTime`
- `jmfsb_respawn_fnc_adjustTimeLocal`
- `jmfsb_respawn_fnc_disable`
- `jmfsb_respawn_fnc_enable`
- `jmfsb_respawn_fnc_forceRespawn`
- `jmfsb_respawn_fnc_gearManaged`
- `jmfsb_respawn_fnc_onPlayerKilled`
- `jmfsb_respawn_fnc_onPlayerRespawn`
- `jmfsb_respawn_fnc_toggle`

</details>
