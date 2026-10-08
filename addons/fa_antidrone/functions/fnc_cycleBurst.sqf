#include "script_component.hpp"
/*
 * Author: YonV
 * Cycles the local player's Mk364 airburst range through the presets. Bound to a
 * CBA keybind (registered in fnc_initAntiDrone) and mirrored by the ACE
 * self-interaction menu (see CfgVehicles.hpp).
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */
private _presets = [0, 100, 150, 200, 250, 300, 400];
private _cur = ACE_player getVariable [QGVAR(burstRange), 0];
private _next = _presets select (((_presets find _cur) + 1) mod (count _presets));
[_next] call FUNC(setBurst);
