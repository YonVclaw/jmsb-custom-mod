#include "script_component.hpp"
/*
 * Author: YonV
 * Returns all living enemy entities near a position.
 *
 * Arguments:
 * 0: Position <ARRAY>
 * 1: Radius in metres <NUMBER>
 * 2: Friendly side (enemies are those hostile to this side) <SIDE>
 *
 * Return Value:
 * Array of objects <ARRAY>
 *
 * Public: No
 */
params [
    ["_pos",    [0,0,0], [[]]],
    ["_radius", 100,     [0]],
    ["_side",   west,    [west]]
];
(_pos nearEntities [["Man","Car","Tank","Air","Ship","UAV"], _radius]) select {
    alive _x && {[_side, side group _x] call BIS_fnc_sideIsEnemy}
}
