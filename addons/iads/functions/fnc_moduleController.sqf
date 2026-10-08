#include "script_component.hpp"
/*
 * Author: JMSB
 * Reads the module and arms the net. PLACING THE MODULE IS THE ENABLE - with no
 * module every radar on the map radiates the way the engine left it, which is
 * the base game and a perfectly reasonable mission.
 *
 * ONE MODULE RUNS THE SYSTEM. Two schedulers over one set of radars would fight
 * over the same switch and the loser would be whichever ran second, so a second
 * placement is refused out loud rather than silently doubling the beat.
 *
 * THE BLINK RANGE IS SANITISED HERE, not at every use. A mission maker who
 * types 40 and 20 the wrong way round should get a working net, and `random` of
 * a negative span returns a negative number - which would put a flip in the
 * past and give that radar a stroboscope.
 *
 * Arguments:
 * 0: The module logic <OBJECT>
 * 1: Synchronised units <ARRAY>
 * 2: Activated <BOOL>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]], ["_units", [], [[]]], ["_activated", true, [true]]];

if (!_activated || {isNull _logic}) exitWith {};
if (!isServer) exitWith {};

if (GVAR(moduleUp)) exitWith {
    WARNING("a second IADS module was placed - ignored, one module runs this system");
};
GVAR(moduleUp) = true;

private _min = _logic getVariable ["blinkMin", 20];
private _max = _logic getVariable ["blinkMax", 40];
GVAR(blinkMin) = (_min min _max) max 1;
GVAR(blinkMax) = (_min max _max) max GVAR(blinkMin);

GVAR(minEmitters) = (_logic getVariable ["minEmitters", 1]) max 0;
GVAR(rescan) = (_logic getVariable ["rescan", 5]) max 0;
GVAR(manageAir) = _logic getVariable ["manageAir", false];
GVAR(linkAll) = _logic getVariable ["linkAll", false];
GVAR(revealEvery) = (_logic getVariable ["revealEvery", 10]) max 0;
GVAR(ambush) = _logic getVariable ["ambush", false];
GVAR(envelope) = (_logic getVariable ["envelope", 4000]) max 0;
GVAR(debugMarkers) = _logic getVariable ["debugMarkers", false];

// Class lists are matched in lower case because a mission maker typing a
// classname by hand is a mission maker typing it in whatever case they read it
// in, and a list that only works when the capitals match is a list that looks
// broken.
private _fnc_classes = {
    params ["_csv"];
    ((_csv splitString " ,") apply {toLower (trim _x)}) select {_x isNotEqualTo ""}
};

GVAR(exempt) = [_logic getVariable ["exempt", ""]] call _fnc_classes;
GVAR(extraReceivers) = [_logic getVariable ["extraReceivers", ""]] call _fnc_classes;

// THE ENGINE IS ASKED BEFORE ANYTHING IS PROMISED. Every radar this manages is
// switched with one command; if this build does not have it, a net that
// reported itself as running would be blinking nothing at all. Unknown is not
// the same as missing - see FUNC(engine) - so only a definite NO disarms.
//
// GUARDED, because the asking is itself done with a command. If FUNC(engine)
// failed to compile on this build it is nil, and arming the net anyway is the
// right answer: a diagnostic that cannot run is no reason to switch off a
// system that can.
private _has = createHashMap;
if (!isNil QFUNC(engine)) then {
    _has = call FUNC(engine);
};

if ((_has getOrDefault ["setVehicleRadar", -1]) isEqualTo 0) exitWith {
    GVAR(moduleUp) = false;
    ERROR("setVehicleRadar is not in this build - EMCON cannot switch anything, so the net is NOT armed");
};

[] call FUNC(start);
