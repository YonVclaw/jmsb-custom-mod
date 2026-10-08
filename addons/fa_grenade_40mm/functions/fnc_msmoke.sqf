#include "script_component.hpp"
/*
 * Author: YonV
 * Mk384 M-SMK — multispectral smoke screen (visual + partial thermal).
 * Swap "SmokeShell" for ACE/CUP smoke class to get full thermal block.
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Impact position <ARRAY>
 * 2: Lifetime in seconds <NUMBER> (unused — smoke has its own lifetime)
 * 3: Screen radius in metres <NUMBER>
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
    ["_radius", 25,      [0]]
];
private _spread = _radius * 0.5;
for "_i" from 0 to 4 do {
    private _o = [(_pos # 0) + (random _spread) - (_spread * 0.5),
                  (_pos # 1) + (random _spread) - (_spread * 0.5), 0];
    createVehicle ["SmokeShell", _o, [], 0, "CAN_COLLIDE"];
};
[_unit, "Multispectral Screen", "Up."] call FUNC(notify);
