#include "script_component.hpp"
/*
 * Author: YonV
 * Mk386 UGS — unattended ground sensor; reports enemy contacts via markers until expiry.
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Impact position <ARRAY>
 * 2: Lifetime in seconds <NUMBER>
 * 3: Detection radius in metres <NUMBER>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [
    ["_unit",   objNull, [objNull]],
    ["_pos",    [0,0,0], [[]]],
    ["_life",   1800,    [0]],
    ["_radius", 150,     [0]]
];
private _side = side group _unit;
private _s = createVehicle ["Land_Pod_Heli_Transport_04_box_F", _pos, [], 0, "CAN_COLLIDE"];
_s setObjectScale 0.4;

[{
    params ["_args", "_h"];
    _args params ["_s", "_side", "_radius", "_end"];
    if (isNull _s || {time > _end}) exitWith {
        if (!isNull _s) then {
            { deleteMarker _x } forEach (_s getVariable ["mk", []]);
            deleteVehicle _s;
        };
        _h call CBA_fnc_removePerFrameHandler;
    };
    { deleteMarker _x } forEach (_s getVariable ["mk", []]);
    private _mk = [];
    {
        private _m = createMarker [format ["ugs_%1", netId _x], getPosVisual _x];
        _m setMarkerTypeLocal "mil_dot"; _m setMarkerColorLocal "ColorOrange"; _m setMarkerSize [0.6, 0.6];
        _mk pushBack _m;
    } forEach ([getPos _s, _radius, _side] call FUNC(enemiesNear));
    _s setVariable ["mk", _mk];
}, 12, [_s, _side, _radius, time + _life]] call CBA_fnc_addPerFrameHandler;

[_unit, "UGS Picket", "Active."] call FUNC(notify);
