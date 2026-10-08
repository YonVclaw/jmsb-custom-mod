#include "script_component.hpp"
/*
 * Author: JMSB
 * Pop-up ambush: a dark site lights only when the net hands it something worth
 * shooting at, and goes dark again after.
 *
 * PHASE 3 OF THE PLAN, AND IT IS GATED. The whole mode rests on one engine
 * behaviour nobody has verified - whether a launcher with no radar of its own
 * will FIRE on a datalink track or merely draw it on the sensor display. If it
 * only draws it, this mode is theatre: sites light up, nothing shoots, and the
 * mission is easier than it was before. So the module attribute is OFF by
 * default and says so, and the probe command is what turns the guess into an
 * answer.
 *
 * IF THE PROBE SAYS NO, the fallback the design names is confirmSensorTarget -
 * telling the launcher the track is real. It is deliberately NOT called here on
 * spec: a command invoked with a signature nobody has checked throws on every
 * tick, and a thrown ambush is worse than no ambush.
 *
 * WHY A DARK SITE IS WORTH THE TROUBLE: a SAM that radiates continuously is
 * found by flying a route once and noting where the warning came from. One that
 * is silent until something enters its envelope cannot be scouted that way -
 * the first warning IS the engagement, and the pilot's answer has to be a plan
 * rather than a map.
 *
 * Arguments:
 * 0: The side <SIDE>
 * 1: That side's radars <ARRAY of OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [east, _radars] call jmfsb_iads_fnc_ambush
 *
 * Public: No
 */

params [["_side", sideUnknown, [sideUnknown]], ["_radars", [], [[]]]];

if (_side isEqualTo sideUnknown || {_radars isEqualTo []}) exitWith {};

private _tracks = [_side] call FUNC(tracks);
if (_tracks isEqualTo []) exitWith {};

private _now = CBA_missionTime;

{
    private _r = _x;

    // A pinned set is already lit and a set inside its window is already up;
    // re-lighting either would only push the window out for free.
    if (_r getVariable [QGVAR(pinned), false]) then {continue};
    if (_now < (_r getVariable [QGVAR(ambushUntil), -1e9])) then {continue};

    if ((_tracks findIf {(_x distance _r) < GVAR(envelope)}) < 0) then {continue};

    _r setVariable [QGVAR(ambushUntil), _now + IADS_AMBUSH_WINDOW];
    [_r, true] call FUNC(emit);

    INFO_2("%1 lit on a track inside %2 m",typeOf _r,round GVAR(envelope));
} forEach _radars;
