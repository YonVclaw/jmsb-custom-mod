#include "script_component.hpp"
/*
 * Author: JMSB
 * Files what the air defence net can see onto its side's threat board.
 *
 * THE BRIDGE IS THE POINT OF THE WHOLE PHASE. A radar wired only to the
 * launchers beside it is a private conversation: the commander cannot reason
 * about the aircraft, the drone dispatch cannot be cued by it, and no other
 * system in the mod can ever hear it. The board is where this mod already puts
 * sightings - see EFUNC(common,contactReport) - so posting there costs one
 * call and every consumer that exists now or later gets the air picture for
 * free.
 *
 * IT POSTS THE FUNCTION, NOT THE EVENT. The contact event carries five
 * arguments and drops the sixth, and the sixth is the OBJECT that was seen - a
 * live handle to an aircraft is exactly what a consumer wants to keep tracking
 * rather than a position that was true a moment ago.
 *
 * ERROR ZERO, because a datalink track is a sensor holding a target right now,
 * not a bearing somebody triangulated. Consumers that want to know how good a
 * fix is read the error; this is the good end of that scale, and the board's
 * own confidence decay is what makes it stale rather than a fudge factor here.
 *
 * FRIENDLY TRACKS ARE NOT CONTACTS. A datalink carries own-position reports
 * too, which is what puts the side's own aircraft on the picture; filing those
 * as sightings would have every commander in the mod reacting to its own air.
 *
 * Parameters (CBA PFH): 0: args (unused), 1: handle (unused)
 *
 * Return Value:
 * None
 *
 * Public: No
 */

if (!isServer) exitWith {};

private _clock = diag_tickTime;

{
    private _side = _x;
    private _tracks = [_side] call FUNC(tracks);

    {
        private _t = _x;
        private _tside = side _t;

        if (_tside isEqualTo sideUnknown) then {continue};
        if ((_side getFriend _tside) >= 0.6) then {continue};

        [_side, _tside, ASLToAGL getPosASL _t, 0, "radar", _t] call EFUNC(common,contactReport);
    } forEach _tracks;
} forEach (call FUNC(sides));

// Same rule as FUNC(tick): quiet when quick, a line when it was not.
private _ms = (diag_tickTime - _clock) * 1000;
if (_ms > IADS_SLOW_MS) then {
    WARNING_1("reveal took %1 ms",round _ms);
};
