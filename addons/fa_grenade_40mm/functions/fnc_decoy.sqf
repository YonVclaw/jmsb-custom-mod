#include "script_component.hpp"
/*
 * Author: YonV
 * Mk385 DCOY — RF/IR decoy that baits enemy drones and loitering munitions.
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Impact position <ARRAY>
 * 2: Lifetime in seconds <NUMBER>
 * 3: Bait radius in metres <NUMBER>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [
    ["_unit",   objNull, [objNull]],
    ["_pos",    [0,0,0], [[]]],
    ["_life",   120,     [0]],
    ["_radius", 300,     [0]]
];
private _side = side group _unit;
private _d  = createVehicle ["Land_PortableLongRangeAntenna_01_olive_F", _pos, [], 0, "CAN_COLLIDE"];
private _ir = "B_IRStrobe" createVehicle _pos;
_ir attachTo [_d, [0,0,1.5]];

[{
    params ["_args", "_h"];
    _args params ["_d", "_side", "_radius", "_end"];
    if (isNull _d || {time > _end}) exitWith {
        if (!isNull _d) then {
            { deleteVehicle _x } forEach attachedObjects _d;
            deleteVehicle _d;
        };
        _h call CBA_fnc_removePerFrameHandler;
    };
    {
        (group _x) reveal [_d, 4];
        _x doTarget _d; _x doFire _d;
    } forEach (
        (getPos _d nearEntities [["Air","UAV"], _radius]) select {
            unitIsUAV _x && {[_side, side group _x] call BIS_fnc_sideIsEnemy}
        }
    );
}, 1, [_d, _side, _radius, time + _life]] call CBA_fnc_addPerFrameHandler;

[_unit, "Decoy", "Emitting."] call FUNC(notify);
