#include "script_component.hpp"
/*
 * Author: JMSB
 * Is anyone hostile to the holder still inside - real or virtual?
 *
 * Entities first, because that is cheap and decisive. Then profiles through
 * the adapter, ONE SIDE PER QUERY: ALiVE's selector takes a single side
 * string, and handing it a list quietly matches nothing - which would have
 * made every objective look clear.
 *
 * Arguments:
 * 0: Position <ARRAY>
 * 1: Radius (m) <NUMBER>
 * 2: Holding side <SIDE>
 *
 * Return Value:
 * Contested <BOOL>
 *
 * Public: No
 */

params ["_pos", "_radius", "_side"];

private _hit = allUnits findIf {
    alive _x
    && {(side group _x) isNotEqualTo civilian}
    && {(side group _x) getFriend _side < 0.6}
    && {(getPosATL _x) distance2D _pos <= _radius}
};
if (_hit > -1) exitWith {true};

if (isNil "jmfsb_adapter_alive_fnc_nearProfiles") exitWith {false};

private _out = false;
{
    if ((_x getFriend _side) < 0.6) then {
        private _p = [_pos, _radius, [[_x] call EFUNC(common,sideToText)]]
            call jmfsb_adapter_alive_fnc_nearProfiles;
        if (_p isEqualType [] && {_p isNotEqualTo []}) exitWith { _out = true };
    };
} forEach [west, east, independent];

_out
