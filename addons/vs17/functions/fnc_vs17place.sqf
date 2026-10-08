#include "script_component.hpp"

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};
if !(QGVAR(vs17) in items _unit) exitWith {false};

private _pos = getPosASL _unit;
private _dir = getDir _unit;

private _vs17 = createVehicle [QGVAR(vs17_item), _pos, [], 0, "CAN_COLLIDE"];
_vs17 setPosASL _pos;
_vs17 setDir _dir;
_vs17 setVectorUp surfaceNormal position _vs17;

_unit removeItem QGVAR(vs17);

true;
