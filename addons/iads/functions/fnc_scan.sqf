#include "script_component.hpp"
/*
 * Author: JMSB
 * Starts one sweep of the map for radars and shooters not yet on the net.
 *
 * A SLICE PER FRAME, NEVER THE MAP IN ONE. The first shape of this walked the
 * whole of `vehicles` in a single frame, and the rescan runs it every few
 * minutes - which is a freeze on a metronome, timed to the one interval a
 * player cannot help noticing. The list is snapshotted here and FUNC(scanStep)
 * chews through it a slice per frame; a sweep takes a few more frames of wall
 * time and no frame pays for more than its slice.
 *
 * ONE SWEEP AT A TIME. A rescan that fires while the previous sweep is still
 * walking is skipped rather than queued - the next one picks up whatever it
 * would have found, and two sweeps interleaving would register nothing twice
 * (FUNC(register) refuses seconds) while paying twice.
 *
 * WHAT IT ASKS THE MAP AND WHY is documented on FUNC(scanStep), which is the
 * half that does the work.
 *
 * Parameters (CBA PFH): 0: args (unused), 1: handle (unused)
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call jmfsb_iads_fnc_scan
 *
 * Public: No
 */

if (!isServer) exitWith {};
if (GVAR(scanning)) exitWith {
    TRACE_1("rescan fired while a sweep was still walking - skipped",count GVAR(radars));
};

private _sides = call FUNC(sides);
if (_sides isEqualTo []) exitWith {};

GVAR(scanning) = true;

// The snapshot is the slicing contract: the sweep walks the list as it stood
// when it started, and whatever spawns mid-sweep is the next sweep's to find.
[+vehicles, 0, _sides, 0, 0, 0, diag_tickTime] call FUNC(scanStep);
