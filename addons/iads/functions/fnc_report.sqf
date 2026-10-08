#include "script_component.hpp"
/*
 * Author: JMSB
 * What the net is doing right now, as one line per side - for `#jmfsb iads`.
 *
 * THE FIRST THING IT PRINTS IS WHETHER THE MODULE IS EVEN UP, because "no
 * radars" and "no module" look identical from the outside and are completely
 * different problems.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * The report <STRING>
 *
 * Example:
 * private _txt = call jmfsb_iads_fnc_report
 *
 * Public: No
 */

if (!GVAR(moduleUp)) exitWith {
    "IADS: no module placed - every radar is radiating the way the engine left it"
};

private _out = [format ["IADS: blink %1-%2 s, floor %3, %4 receiver(s) on the link",
    round GVAR(blinkMin), round GVAR(blinkMax), GVAR(minEmitters), count GVAR(receivers)]];

{
    private _side = _x;
    private _mine = GVAR(radars) select {(_x getVariable [QGVAR(side), sideUnknown]) isEqualTo _side};
    if (_mine isEqualTo []) then {continue};

    private _lit = _mine select {_x getVariable [QGVAR(radiating), false]};
    private _pinned = _mine select {_x getVariable [QGVAR(pinned), false]};

    _out pushBack format ["%1: %2 radar(s), %3 lit, %4 pinned, %5 track(s)",
        _side, count _mine, count _lit, count _pinned, count ([_side] call FUNC(tracks))];
} forEach (call FUNC(sides));

if ((count _out) isEqualTo 1) then {
    _out pushBack "no radars found yet - nothing hostile on the map carries one, or the scan has not run";
};

// The engine answers, because the two questions asked of this report are "is it
// working" and "why is it not", and half of the second one is what this build
// actually has.
private _has = call FUNC(engine);
if ((_has getOrDefault ["detector", 0]) isEqualTo 1) then {
    private _missing = [];
    {
        if ((_has getOrDefault [_x, -1]) isEqualTo 0) then {_missing pushBack _x};
    } forEach ["setVehicleRadar", "listRemoteTargets", "confirmSensorTarget"];

    if (_missing isNotEqualTo []) then {
        _out pushBack format ["engine is MISSING: %1", _missing joinString ", "];
    };
};

_out joinString " | "
