#include "script_component.hpp"
/*
 * Author: YonV
 * Disables AI on a UAV; called via remoteExec on the UAV's owner machine.
 *
 * Arguments:
 * 0: UAV object <OBJECT>
 * 1: AI modes to disable <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [
    ["_uav",   objNull,                          [objNull]],
    ["_modes", ["MOVE","TARGET","AUTOTARGET"],   [[]]]
];
{ _uav disableAI _x } forEach _modes;
_uav setVariable ["jmfsb_fa_grenade_40mm_jammed", true];
