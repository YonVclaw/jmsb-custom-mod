#include "script_component.hpp"

params [
    ["_target", objNull, [objNull]],
    ["_player", objNull, [objNull]]
];

if (isNull _target) exitWith {false};
if (isNull _player) exitWith {false};

private _result = [_player, QGVAR(vs17), 1, [1, 2, 3], false] call EFUNC(common,addItem);
private _addedToUnit = _result # 0;

if (_addedToUnit) then {
    deleteVehicle _target;
};

_addedToUnit;
