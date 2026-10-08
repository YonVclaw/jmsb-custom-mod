#include "script_component.hpp"
/*
 * Author: JMSB
 * What one side's datalink is holding, as a plain list of objects.
 *
 * P0-2 OF THE PLAN LIVES HERE. The element shape listRemoteTargets returns was
 * never verified against a running game, and a consumer written to one guess
 * throws on every tick if the guess is wrong. So this READS the shape rather
 * than assuming it: an element that IS an object is the object, an element that
 * CONTAINS one is unwrapped, and anything else is dropped. Both readings work,
 * whichever the engine turns out to use.
 *
 * IT LOGS THE RAW SHAPE ONCE, which is the point - one mission with this
 * running answers P0-2 for good, and the answer is in the RPT rather than in
 * somebody memory of an editor test.
 *
 * Arguments:
 * 0: The side whose picture to read <SIDE>
 *
 * Return Value:
 * Live tracked objects <ARRAY of OBJECT>
 *
 * Example:
 * private _tracks = [east] call jmfsb_iads_fnc_tracks
 *
 * Public: No
 */

params [["_side", sideUnknown, [sideUnknown]]];

if (_side isEqualTo sideUnknown) exitWith {[]};

private _raw = listRemoteTargets _side;
if (_raw isEqualTo []) exitWith {[]};

if (!GVAR(shapeSaid)) then {
    GVAR(shapeSaid) = true;
    INFO_2("listRemoteTargets element is a %1: %2",typeName (_raw select 0),_raw select 0);
};

private _out = [];

{
    private _e = _x;
    private _obj = objNull;

    if (_e isEqualType objNull) then {_obj = _e};
    if (_e isEqualType []) then {
        private _i = _e findIf {_x isEqualType objNull};
        if (_i > -1) then {_obj = _e select _i};
    };

    if (isNull _obj) then {continue};
    if (!alive _obj) then {continue};

    _out pushBackUnique _obj;
} forEach _raw;

_out
