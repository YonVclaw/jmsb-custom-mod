#include "script_component.hpp"
/*
 * Author: YonV
 * HuntIR-style delivery. Pops a parachute at the round's apex and lets the
 * payload float down, then runs the effect function at the landing point.
 * The carrier never explodes — it is deleted at apex by fnc_handle and this
 * chute carries the effect the rest of the way.
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Apex position (ATL) <ARRAY>
 * 2: Effect lifetime in seconds <NUMBER>
 * 3: Effect radius in metres <NUMBER>
 * 4: Effect function <CODE>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [
    ["_unit",   objNull, [objNull]],
    ["_pos",    [0,0,0], [[]]],
    ["_life",   60,      [0]],
    ["_radius", 100,     [0]],
    ["_fnc",    {},      [{}]]
];

// Deploy from a sensible height even if the round topped out low.
private _apex = +_pos;
_apex set [2, (_pos # 2) max 60];

private _chute = createVehicle ["Steerable_Parachute_F", _apex, [], 0, "CAN_COLLIDE"];
_chute setPosATL _apex;
_chute allowDamage false;

// Descend under the chute; deploy the payload once it settles (or after a
// hard cap so the round can never hang in the air).
[{
    params ["_args", "_h"];
    _args params ["_chute", "_unit", "_pos", "_life", "_radius", "_fnc", "_deadline"];

    private _landed = !isNull _chute && {(getPosATL _chute # 2) <= 1.5};
    if (isNull _chute || _landed || {time > _deadline}) exitWith {
        private _dp = if (isNull _chute) then { _pos } else { getPosATL _chute };
        if (!isNull _chute) then { deleteVehicle _chute };
        [_unit, _dp, _life, _radius] call _fnc;
        _h call CBA_fnc_removePerFrameHandler;
    };
}, 0.1, [_chute, _unit, _pos, _life, _radius, _fnc, time + 90]] call CBA_fnc_addPerFrameHandler;
