#include "script_component.hpp"
/*
 * Author: JMSB
 * Infantry guarding one battery.
 *
 * They stand OFF the hardware, not on it - a ring out from the radar rather
 * than a huddle around it. A player who has found the site should still have to
 * deal with somebody before walking onto it, and guards standing between the
 * launchers would just be killed by whatever kills the launchers.
 *
 * Profiled like everything else here, so a guarded site costs the same as an
 * unguarded one while nobody is near it.
 *
 * Arguments:
 * 0: The battery's position <ARRAY>
 * 1: The side <SIDE>
 * 2: Man classes to draw from <ARRAY>
 * 3: Markers never to place on <ARRAY>
 *
 * Return Value:
 * How many groups were made <NUMBER>
 *
 * Example:
 * [_pos, east, _kinds, _black] call jmfsb_airdefence_fnc_buildSecurity
 */

params [["_pos", [], [[]]], ["_side", sideUnknown, [sideUnknown]],
        ["_kinds", [], [[]]], ["_black", [], [[]]]];

private _want = round GVAR(security);
if (_want <= 0) exitWith {0};
if (_pos isEqualTo [] || {_kinds isEqualTo []}) exitWith {0};

// Two is the ceiling on purpose. This is a temporary system standing in for
// ALiVE's own, and a battery is not meant to become a garrison a section has to
// assault - it is meant to be defended enough that walking on is not free.
_want = _want min 2;

private _spots = [[], _want, createHashMapFromArray [
    ["centre", _pos],
    ["minRange", AD_SEC_MIN_R],
    ["maxRange", AD_SEC_MAX_R],
    ["footprint", 4],
    ["clearRadius", 4],
    ["separation", 80],
    ["blacklist", _black]
]] call EFUNC(common,findSite);

if (_spots isEqualTo []) exitWith {
    TRACE_1("no ground for security at this battery",mapGridPosition _pos);
    0
};

private _made = 0;
private _groups = [];

{
    private _at = _x;
    private _grp = createGroup [_side, true];
    if (isNull _grp) then {continue};

    private _n = AD_SEC_MIN + floor random (AD_SEC_MAX - AD_SEC_MIN + 1);
    for "_i" from 1 to _n do {
        private _u = _grp createUnit [selectRandom _kinds, _at getPos [random 10, random 360], [], 0, "CAN_COLLIDE"];
        if (isNull _u) then {continue};
    };

    if (units _grp isEqualTo []) then {
        deleteGroup _grp;
        continue;
    };

    // They hold the ground they were put on. A guard that wanders is not
    // guarding anything, and one that charges leaves the site open.
    _grp setBehaviour "SAFE";
    _grp setCombatMode "YELLOW";

    private _wp = _grp addWaypoint [_at, 0];
    _wp setWaypointType "SENTRY";

    _groups pushBack _grp;
    _made = _made + 1;
} forEach _spots;

if (_groups isEqualTo []) exitWith {0};

[{
    params ["_groups", "_side", "_pos"];

    private _live = _groups select {!isNull _x};
    if (_live isEqualTo []) exitWith {};

    // NOT PROFILED - see the note in FUNC(buildBattery). Guards handed to
    // ALiVE's runtime profiler are deleted by it, and a site whose guards
    // vanished is the same empty site the user photographed. They stay live
    // and say so to ALiVE rather than only to the log.
    {[_x] call EFUNC(adapter_alive,profileIgnore)} forEach _live;

    INFO_2("%1 security group(s) on the battery at %2",count _live,mapGridPosition _pos);
}, [_groups, _side, _pos]] call CBA_fnc_execNextFrame;

_made
