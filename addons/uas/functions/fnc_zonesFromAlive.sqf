#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_uas_fnc_zonesFromAlive

Description:
    Turns each commander's ALiVE objectives into patrol zones.

    A ZONE IS A ZONE, WHOEVER DREW IT. This does not add a second kind of
    patrol - it appends ordinary entries to QGVAR(zones), the same shape a
    JMSB - Drone Patrol module pushes, so FUNC(planPatrols), FUNC(topUp),
    FUNC(placeCaches), FUNC(spotSweep) and FUNC(ceilingFor) all work on them
    unchanged. That is the whole reason FUNC(zonesFor) was written to return a
    superset of the old objective-list shape.

    jmfsb had no zones at all: patrols orbited each commander's objectives
    directly, and FUNC(planPatrols) asked the adapter every tick. Doing it once,
    here, means the ALiVE half and the hand-placed half are the same list from
    then on, and neither can shadow the other.

    OFF BY DEFAULT. Loading ALiVE should not silently put drones over every
    objective on the map. QGVAR(aliveZones) is the opt-in, and it stands where
    jmfsb's JMSB - UAS module stood - that module was the enable, and DIVINER
    deleted it.

    ONCE PER OBJECTIVE, EVER. The id of every objective already turned into a
    zone is kept in QGVAR(aliveZoneIds), so a second call - a commander that
    initialises late, a re-raised ready event - adds the new ones and leaves the
    existing zones alone. Zones are append-only and an index is stable; adding
    the same objective twice would give one piece of ground two ceilings.

    NO ARTILLERY. ALiVE-derived zones never call for fire. A mission that wants
    overflight to land as shells says so on a Drone Patrol module drawn over
    that ground, which is a deliberate decision about one place rather than a
    blanket one about every objective a commander owns.

Parameters:
    None.

Returns:
    NUMBER - zones added by this call.

Author:
    YonV
---------------------------------------------------------------------------- */
if (!isServer) exitWith {0};
if (!GVAR(aliveZones)) exitWith {0};
if (isNil QEFUNC(adapter_alive,commanders) || {isNil QEFUNC(adapter_alive,objectivesFor)}) exitWith {0};

private _seen = missionNamespace getVariable [QGVAR(aliveZoneIds), []];
private _zones = missionNamespace getVariable [QGVAR(zones), []];
private _added = 0;
private _done = [];

{
    _x params [["_side", sideUnknown]];
    // ONE COMMANDER PER SIDE. Two OPCOMs on the same side share their
    // objectives, and walking both would ask for the same ground twice.
    if (_side isEqualTo sideUnknown || {_side in _done}) then {continue};
    _done pushBack _side;

    private _objs = ([_side] call EFUNC(adapter_alive,objectivesFor)) select {
        !((_x param [0, ""]) in _seen)
    };
    if (_objs isEqualTo []) then {continue};

    // The share of this commander's objectives that get flown over, capped.
    // A percentage has no ceiling - 30% of 173 objectives is 52 zones, and the
    // planner would try to keep an airframe over every one of them.
    private _want = (round ((count _objs) * GVAR(aliveZoneShare) / 100)) max 1;
    _want = _want min (round GVAR(aliveZoneMax)) min (count _objs);

    private _pick = _objs call BIS_fnc_arrayShuffle;
    _pick resize _want;

    {
        _x params [["_id", ""], ["_pos", []], ["_size", 0]];
        if (_pos isEqualTo []) then {continue};

        // 0 means the objective's own size, which is what ALiVE thinks that
        // place is worth; anything else overrides every objective alike.
        private _radius = GVAR(aliveZoneRadius);
        if (_radius <= 0) then {_radius = _size};
        if (_radius <= 0) then {_radius = 500};

        // Empty class: FUNC(topUp) falls back to the faction scan, which is the
        // right answer here - the airframe should be the commander's own.
        _zones pushBack [
            _side, +_pos, _radius, "",
            round (GVAR(aliveZoneDrones) max 1),
            [false, 6, 100, 300]
        ];
        _seen pushBack _id;
        _added = _added + 1;
    } forEach _pick;
} forEach (call EFUNC(adapter_alive,commanders));

if (_added == 0) exitWith {0};

missionNamespace setVariable [QGVAR(zones), _zones];
missionNamespace setVariable [QGVAR(aliveZoneIds), _seen];
INFO_1("%1 patrol zone(s) taken from ALiVE objectives",_added);

// SAME ENABLE AS A MODULE. The planner walks every zone on one clock, so this
// only has to make sure the clock is running.
if (!GVAR(moduleUp)) then {
    GVAR(moduleUp) = true;
    [] call FUNC(start);
};

_added
