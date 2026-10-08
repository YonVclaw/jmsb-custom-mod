#include "..\script_component.hpp"
/*
 * Author: JMSB
 * A Site member's surface weapon onto a point on the ground, from the tacpad.
 *
 * Artillery-capable members fire their own artillery solution
 * (doArtilleryFire) with the first magazine that reaches; anything else with a
 * surface weapon is told to fire on the point. What flies is the game's round.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Point, ASL <ARRAY>
 *
 * Return Value:
 * What happened, for the sender <STRING>
 *
 * Example:
 * [_veh, _pos] call jmfsb_adsite_fnc_strike
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]], ["_pos", [], [[]]]];

if (!alive _veh || {_pos isEqualTo []}) exitWith {"no weapon"};
private _at = ASLToAGL _pos;

private _arty = (getArtilleryAmmo [_veh]) select {_at inRangeOfArtillery [[_veh], _x]};
if (_arty isNotEqualTo []) exitWith {
    _veh doArtilleryFire [_at, _arty # 0, 3];
    format ["fire mission, %1, 3 rounds on %2", getText (configFile >> "CfgMagazines" >> (_arty # 0) >> "displayName"), mapGridPosition _at]
};

private _entries = (([_veh] call FUNC(profile)) # 0) select {(_x # 7) isEqualTo ROLE_SURFACE && {(_veh distance _at) <= (_x # 5)}};
if (_entries isEqualTo []) exitWith {"nothing on that member reaches the point"};
(_entries # 0) params ["_path", "_weapon"];
private _man = [_veh turretUnit _path, driver _veh] select (_path isEqualTo [-1]);
if (isNull _man) exitWith {"no crew on that weapon"};
_man doWatch _at;
_man doSuppressiveFire _at;
format ["firing on %1", mapGridPosition _at]
