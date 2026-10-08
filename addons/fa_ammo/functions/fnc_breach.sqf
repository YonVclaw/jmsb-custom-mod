#include "..\script_component.hpp"
/*
 * Author: YonV (adapted from fn_lot_breach.sqf by Lotto)
 * Mk353 BRC door breach — tracks the fired round frame-by-frame and uses its
 * actual point of impact (where it stops existing) rather than a fixed
 * distance-ahead-of-muzzle guess, then finds the nearest door animation
 * source at that impact point and forces it open regardless of lock state
 * (clears both the vanilla door-disabled flag and, if a mission has scripted
 * the building itself as locked, the object's lock command).
 *
 * Honest caveat: Arma's door/lock system is inconsistent across building
 * types. When the door's memory-point position can't be resolved the
 * function opens all door sources near the impact point as a fallback.
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Projectile <OBJECT>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [["_unit", objNull, [objNull]], ["_proj", objNull, [objNull]]];
if (isNull _unit) exitWith {};

private _debug = GVAR(debugBreaching);
private _fnc_dbg = {
    if (_debug) then { systemChat format ["[BRC breach] %1", _this] };
};

if (isNull _proj) exitWith {
    ["no projectile object to track, aborting"] call _fnc_dbg;
};

private _fnc_resolve = {
    params ["_unit", "_aim", "_fnc_dbg"];

    private _house = nearestObject [_aim, "House"];
    if (isNull _house) then { _house = nearestBuilding _aim };
    if (isNull _house) exitWith { ["no house/building found near impact point"] call _fnc_dbg; };
    private _houseDist = _aim distance _house;
    if (_houseDist > 8) exitWith {
        [format ["nearest building (%1) is %2 m from impact point, aborting (max 8 m)", typeOf _house, _houseDist]] call _fnc_dbg;
    };
    [format ["target building: %1, distance to impact point: %2 m", typeOf _house, _houseDist]] call _fnc_dbg;

    if (locked _house > 0) then {
        [format ["building was locked (%1), unlocking", locked _house]] call _fnc_dbg;
        _house lock 0;
    };

    // HOOK: if a dedicated breaching mod is present, call it here and exit.

    private _doors = ("true" configClasses (configOf _house >> "AnimationSources"))
        apply { configName _x }
        select {
            private _n = toLower _x;
            (["door", _n] call BIS_fnc_inString) &&
            {!(["sound", _n] call BIS_fnc_inString)} &&
            {!(["handle", _n] call BIS_fnc_inString)} &&
            {!(["lock", _n] call BIS_fnc_inString)}
        };
    if (_doors isEqualTo []) exitWith {
        [format ["building %1 has no door AnimationSources, nothing to open", typeOf _house]] call _fnc_dbg;
    };
    [format ["found %1 candidate door animation source(s): %2", count _doors, _doors]] call _fnc_dbg;

    private _best  = "";
    private _bestD = 1e9;
    {
        private _p = _house selectionPosition [_x, "Memory"];
        if (_p isEqualTo [0,0,0]) then { _p = _house selectionPosition _x };
        if (_p isNotEqualTo [0,0,0]) then {
            private _d = (_house modelToWorld _p) distance _aim;
            if (_d < _bestD) then { _bestD = _d; _best = _x };
        };
    } forEach _doors;

    private _fnc_open = {
        params ["_h", "_door"];
        _h setVariable [format ["bis_disabled_%1", _door], 0, true];
        _h animateDoor [_door, 1];
    };

    if (_best != "") then {
        [format ["opening nearest door: %1 (%2 m from impact point)", _best, _bestD]] call _fnc_dbg;
        [_house, _best] call _fnc_open;
    } else {
        ["no door selection position resolved, falling back to opening ALL candidate doors"] call _fnc_dbg;
        { [_house, _x] call _fnc_open } forEach _doors;
    };

    if (local _unit && {hasInterface}) then {
        ["Breach", "Door forced.", [0.871, 0.361, 0.188, 1]] call EFUNC(notify,notify);
    };
};

private _startPos = getPosASL _proj;
[format ["tracking projectile from %1", _startPos]] call _fnc_dbg;

[{
    params ["_args", "_h"];
    _args params ["_proj", "_unit", "_fnc_dbg", "_fnc_resolve", "_lastPos"];

    if (!isNull _proj) exitWith {
        _args set [4, getPosASL _proj];
    };

    // Projectile no longer exists — it either hit something or expired at
    // the end of its flight. Either way, _lastPos is the last position it
    // occupied, i.e. its point of impact.
    _h call CBA_fnc_removePerFrameHandler;
    [format ["projectile stopped existing, impact point %1", _lastPos]] call _fnc_dbg;
    [_unit, _lastPos, _fnc_dbg] call _fnc_resolve;
}, 0, [_proj, _unit, _fnc_dbg, _fnc_resolve, _startPos]] call CBA_fnc_addPerFrameHandler;
