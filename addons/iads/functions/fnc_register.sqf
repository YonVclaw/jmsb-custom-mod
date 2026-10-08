#include "script_component.hpp"
/*
 * Author: JMSB
 * Puts one vehicle on the net: on the datalink, and - if it emits - on the
 * blink schedule.
 *
 * THE DATALINK IS THE MOD'S OWN HELPER, not three setVehicle* calls written out
 * again here. EFUNC(common,setDatalink) is where this mod decided what "on the
 * net" means and why it sets all three flags rather than splitting them by
 * role; a second copy of that decision is a second thing to keep in step.
 *
 * A NEW SET STARTS LIT AND DETERMINISTIC. Left on the engine's default the AI
 * decides, and "the AI decides" is exactly the state EMCON exists to replace -
 * so the first thing that happens to a radar is being told, explicitly, that it
 * is radiating. The scheduler takes it down from there.
 *
 * THE FIRST FLIP IS ROLLED, NOT SCHEDULED. A scan that registers a battery of
 * six at once would otherwise have six sets flipping on the same second for the
 * rest of the mission, which is the metronome the jitter exists to avoid.
 *
 * Arguments:
 * 0: The vehicle <OBJECT>
 * 1: Its side <SIDE>
 * 2: It emits - false registers a receiver <BOOL> (optional, default true)
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, east, true] call jmfsb_iads_fnc_register
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]], ["_side", sideUnknown, [sideUnknown]], ["_emitter", true, [true]]];

if (!isServer || {isNull _veh}) exitWith {};
if (_veh getVariable [QGVAR(managed), false]) exitWith {};

_veh setVariable [QGVAR(managed), true];
_veh setVariable [QGVAR(side), _side];

[_veh] call EFUNC(common,setDatalink);

if (!_emitter) exitWith {
    GVAR(receivers) pushBackUnique _veh;
};

// PINNED SETS NEVER GO DARK. An early-warning radar a mission wants found, or
// the one set a scenario is built around, is named in the module rather than
// left to a scheduler that cannot know it is special.
_veh setVariable [QGVAR(pinned), (toLower (typeOf _veh)) in GVAR(exempt)];

private _now = CBA_missionTime;
_veh setVariable [QGVAR(nextFlip), _now + GVAR(blinkMin) + random ((GVAR(blinkMax) - GVAR(blinkMin)) max 0)];

GVAR(radars) pushBackUnique _veh;

// NOT BROADCAST HERE. The list does go out to clients - it is the registry an
// intel product would read to decide whether it has anything to offer - but
// once per completed sweep, in FUNC(scanStep), and on prune in FUNC(tick).
// From in here it went out per radar: a battery of six was the whole list
// resent six times in one frame.

[_veh, true] call FUNC(emit);
