#include "script_component.hpp"
/*
 * Author: YonV
 * Core tracker — polls a 40mm support round and deploys its payload at APEX or LAND.
 * Calls the effect function with [_unit, _pos, _life, _radius].
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Projectile <OBJECT>
 * 2: Registry entry [mode, fnc, life (s), radius (m)] <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [
    ["_unit",  objNull, [objNull]],
    ["_proj",  objNull, [objNull]],
    ["_entry", [],      [[]]]
];
_entry params [
    ["_mode",   "LAND", [""]],
    ["_fnc",    {},     [{}]],
    ["_life",   60,     [0]],
    ["_radius", 100,    [0]]
];

[{
    params ["_args", "_h"];
    _args params ["_proj", "_unit", "_mode", "_fnc", "_life", "_radius", "_lastPos"];
    private _chute = _mode isEqualTo "CHUTE";
    if (isNull _proj) exitWith {
        if (_chute) then {
            [_unit, _lastPos, _life, _radius, _fnc] call FUNC(chute);
        } else {
            [_unit, _lastPos, _life, _radius] call _fnc;
        };
        _h call CBA_fnc_removePerFrameHandler;
    };
    _args set [6, getPosATL _proj];
    // APEX and CHUTE both deploy at the top of the arc; LAND waits for the ground.
    private _trigger = if (_mode in ["APEX", "CHUTE"]) then {
        (velocity _proj # 2) <= 0
    } else {
        (getPosATL _proj # 2) <= 1
    };
    if (_trigger) exitWith {
        private _p = getPosATL _proj;
        deleteVehicle _proj;
        if (_chute) then {
            [_unit, _p, _life, _radius, _fnc] call FUNC(chute);
        } else {
            [_unit, _p, _life, _radius] call _fnc;
        };
        _h call CBA_fnc_removePerFrameHandler;
    };
}, 0, [_proj, _unit, _mode, _fnc, _life, _radius, getPosATL _proj]] call CBA_fnc_addPerFrameHandler;
