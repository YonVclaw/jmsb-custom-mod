#include "script_component.hpp"
/*
 * Author: CPL.Brostrom.A
 * This module function spawn a 1st Joint Multi-Functional Strike Battalion Fieald Hostpital.
 *
 * Arguments:
 * 0: modulePos <POSITION>
 * 1: objectPos <OBJECT>
 *
 * Example:
 * [getPos logic, this] call jmfsb_zenmodules_fnc_createStaging
 *
 * Public: No
 */

params ["_modulePos", "_objectPos"];

[
    "1st Joint Multi-Functional Strike Battalion Staging Zone", 
    [
        ["SLIDER:RADIUS", ["Zone size", "well you see its the size that maters"], [0, 25, 50], false]
    ], 
    {
        params ["_arg", "_pos"];
        _arg params ["_size"];
        _pos params ["_modulePos"];

        [_modulePos, _size] call jmfsb_mission_fnc_addStagingZone;

    },
    {},
    [_modulePos]
] call zen_dialog_fnc_create;
