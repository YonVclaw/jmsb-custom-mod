#include "script_component.hpp"
/*
 * Author: JMSB
 * One slice of a sweep: up to IADS_SCAN_SLICE vehicles from the snapshot, then
 * hand the rest to the next frame.
 *
 * IT ASKS THE MAP, NOT A SPAWNER. Nothing here knows or cares who built a
 * radar - ALiVE placement, jmfsb_airdefence, a mission maker dropping one in
 * Eden. That is what keeps this addon on the right side of the adapter seam
 * (docs/new.md rule 4), and it is why the rescan exists rather than an event:
 * there is no single spawn event to hook that would cover all three.
 *
 * A PROFILE HAS NO SENSORS. Only real objects are walked - the same reasoning
 * as jmfsb_uas spotting with knowsAbout rather than off a registry - so a
 * virtualised battery joins the net when ALiVE makes it real, on a later sweep.
 *
 * REGISTERED ONCE, kept forever: FUNC(register) refuses a second pass over a
 * vehicle it has already seen, so the sweep can run for a whole mission and
 * cost only the walk.
 *
 * THE SWEEP OWNS UP TO ITS COST. Busy time is summed across the slices and the
 * completion line carries it, so "is the air defence net what is hitching the
 * server" is a question the RPT answers with a number rather than a hunch.
 *
 * Arguments:
 * 0: Vehicle snapshot, taken by FUNC(scan) <ARRAY of OBJECT>
 * 1: Index to resume from <NUMBER>
 * 2: Managed sides, computed once per sweep <ARRAY of SIDE>
 * 3: Emitters registered so far <NUMBER>
 * 4: Receivers registered so far <NUMBER>
 * 5: Busy seconds summed so far <NUMBER>
 * 6: diag_tickTime when the sweep started <NUMBER>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params [
    ["_queue", [], [[]]],
    ["_index", 0, [0]],
    ["_sides", [], [[]]],
    ["_emitters", 0, [0]],
    ["_receivers", 0, [0]],
    ["_busy", 0, [0]],
    ["_started", 0, [0]]
];

private _t0 = diag_tickTime;
private _last = (_index + IADS_SCAN_SLICE) min (count _queue);

// An empty static has no crew to take a side from, and `side` on one answers
// civilian - which is how a whole battery of unmanned launchers can be skipped
// by a side test that looks right. The faction is the fallback, and reading it
// is what EFUNC(common,sideOfFaction) is for.
private _fnc_sideOf = {
    params ["_veh"];
    private _s = side _veh;
    if (_s in [east, west, independent]) exitWith {_s};
    [getText (configOf _veh >> "faction")] call EFUNC(common,sideOfFaction)
};

for "_i" from _index to (_last - 1) do {
    private _veh = _queue select _i;

    // The snapshot outlives the frame it was taken in, so a vehicle can die -
    // or be deleted outright - between the slice that would have reached it
    // and this one.
    if (isNull _veh || {!alive _veh}) then {continue};
    if (_veh getVariable [QGVAR(managed), false]) then {continue};

    // AN AI PILOT MANAGES HIS OWN EMISSIONS. A scheduler blinking a fighter's
    // radar while its pilot is trying to intercept is two systems on one
    // switch, and the pilot is the one who can see the merge.
    if (!GVAR(manageAir) && {_veh isKindOf "Air"}) then {continue};

    private _side = [_veh] call _fnc_sideOf;
    if !(_side in _sides) then {continue};

    private _cls = typeOf _veh;

    if ([_cls] call FUNC(isEmitter)) then {
        [_veh, _side, true] call FUNC(register);
        _emitters = _emitters + 1;
        continue;
    };

    // WHO ELSE GETS THE PICTURE. The default is the air-defence net: the
    // shooters that can act on a track somebody else is holding. Link Whole
    // Side is the 2040 reading of the same idea and is a module toggle rather
    // than the default, because it reaches into vehicles other systems may be
    // managing.
    private _wanted = GVAR(linkAll)
        || {(toLower _cls) in GVAR(extraReceivers)}
        || {[_veh] call FUNC(isShooter)};

    if (_wanted) then {
        [_veh, _side, false] call FUNC(register);
        _receivers = _receivers + 1;
    };
};

_busy = _busy + (diag_tickTime - _t0);

if (_last < count _queue) exitWith {
    [FUNC(scanStep), [_queue, _last, _sides, _emitters, _receivers, _busy, _started]] call CBA_fnc_execNextFrame;
};

// --- the sweep is done ------------------------------------------------------
GVAR(scanning) = false;

// ONE BROADCAST PER SWEEP, not one per radar. FUNC(register) keeps the list;
// this is where the clients hear about it - a publicVariable inside the
// register loop was the whole list resent for every set a battery added.
if (_emitters > 0) then {
    missionNamespace setVariable [QGVAR(radars), GVAR(radars), true];
};

// Always logged, joined or not: the absence of anything new is half of what a
// rescan is for, and the cost is what somebody hunting a freeze needs to see
// against the clock. Busy is the time this addon actually spent; wall is how
// long the sweep was spread over.
INFO_4("sweep: %1 emitter(s) and %2 receiver(s) joined - %3 ms busy, %4 ms wall",_emitters,_receivers,round (_busy * 1000),round ((diag_tickTime - _started) * 1000));
