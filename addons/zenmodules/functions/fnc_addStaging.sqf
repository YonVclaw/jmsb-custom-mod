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


[_objectPos, 12] call jmfsb_mission_fnc_addStagingZone;
