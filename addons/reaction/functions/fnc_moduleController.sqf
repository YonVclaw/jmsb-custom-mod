#include "script_component.hpp"
/*
 * Author: JMSB
 * Reads the module and arms enemy reaction. PLACING THE MODULE IS THE ENABLE - with no
 * module this system does nothing at all.
 *
 * The attributes are operation values only: how many, how often, how likely.
 * WHERE and WHO are never asked for; they come from ALiVE's commanders, their
 * TAORs and their objectives.
 *
 * Arguments:
 * 0: The module logic <OBJECT>
 * 1: Synchronised units <ARRAY>
 * 2: Activated <BOOL>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]], ["_units", [], [[]]], ["_activated", true, [true]]];

if (!_activated || {isNull _logic}) exitWith {};
if (!isServer) exitWith {};

// One module runs this system. A second would re-arm it and place everything
// twice over, so it says so in the log rather than quietly doing it.
if (GVAR(moduleUp)) exitWith {
    WARNING("a second JMSB - Enemy Reaction module was placed - ignored, one module runs this system");
};
GVAR(moduleUp) = true;

GVAR(failChance) = _logic getVariable ["failChance", 25];
GVAR(detectChance) = _logic getVariable ["detectChance", 50];
GVAR(roundsMin) = _logic getVariable ["roundsMin", 4];
GVAR(roundsMax) = _logic getVariable ["roundsMax", 10];
GVAR(watts) = _logic getVariable ["watts", 1];

// The knobs CLIENTS read: the key-up filter in FUNC(onTransmit) runs where
// the radio is, and the hacking console's fail roll (hackComplete) runs on
// the hacker's machine and reads failChance. Everything else stays
// server-side.
publicVariable QGVAR(watts);
publicVariable QGVAR(failChance);

// Nothing to schedule. This system is event driven and the values above were
// all it was waiting for; FUNC(roll) checks GVAR(moduleUp) before it does
// anything, so arming is the whole of the start.
INFO("armed");
