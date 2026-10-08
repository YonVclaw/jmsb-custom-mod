#include "script_component.hpp"
/*
 * Author: JMSB
 * The beat: blink every managed radar, and hold the floor of lit ones.
 *
 * TWO RULES, IN THIS ORDER, AND THE ORDER IS THE DESIGN.
 *
 *   1. EVERY SET RE-ROLLS ITS OWN TIMER. A single interval shared by the net is
 *      a metronome - count to twenty, cross while it is down - and a metronome
 *      is a system players beat rather than fly against. Each radar holds its
 *      state for its own draw out of the blink range and then flips.
 *
 *   2. THE FLOOR OVERRULES THE BLINK. Independent timers will eventually put a
 *      whole side dark at once, and a side that is briefly blind by accident is
 *      a side that gets overflown by luck. Whatever the dice said, the required
 *      number of sets are lit - and the one brought back up is the one that has
 *      been quiet LONGEST, so the duty is shared out instead of landing on the
 *      same radar every time.
 *
 * A PINNED SET IS OUTSIDE BOTH. It is lit, it stays lit, and it still counts
 * towards the floor - which is what makes "Always-On Classes" a way to say the
 * early-warning radar IS the side's coverage.
 *
 * PRUNING IS HERE rather than in a sweeper of its own: this is the only thing
 * that walks the whole list every few seconds, so it is the honest place to
 * drop what has been destroyed.
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
private _now = CBA_missionTime;

// Dead hardware leaves the net, and takes its debug marker with it.
private _live = [];
{
    if (!isNull _x && {alive _x}) then {
        _live pushBack _x;
        continue;
    };
    private _mkr = _x getVariable [QGVAR(marker), ""];
    if (_mkr isNotEqualTo "") then {deleteMarker _mkr};
} forEach GVAR(radars);

if (count _live != count GVAR(radars)) then {
    GVAR(radars) = _live;
    missionNamespace setVariable [QGVAR(radars), GVAR(radars), true];
};

GVAR(receivers) = GVAR(receivers) select {!isNull _x && {alive _x}};

if (GVAR(radars) isEqualTo []) exitWith {};

private _span = (GVAR(blinkMax) - GVAR(blinkMin)) max 0;

{
    private _side = _x;
    private _mine = GVAR(radars) select {(_x getVariable [QGVAR(side), sideUnknown]) isEqualTo _side};
    if (_mine isEqualTo []) then {continue};

    // --- 1. the blink -----------------------------------------------------
    {
        private _r = _x;
        private _lit = _r getVariable [QGVAR(radiating), false];

        // HELD OFF by an air defence Site (jmfsb_adsite: silent until cued, a
        // burst handed round, an anti-radiation missile inbound): dark, and not
        // the blink's to light. Checked before the pin, which it outranks.
        if (_r getVariable [QGVAR(heldOff), false]) then {
            if (_lit) then {[_r, false] call FUNC(emit)};
            continue;
        };

        // Pinned, or lit by the ambush trigger and still inside its window:
        // either way this set is not the scheduler's to move.
        if (_r getVariable [QGVAR(pinned), false] || {_now < (_r getVariable [QGVAR(ambushUntil), -1e9])}) then {
            if (!_lit) then {[_r, true] call FUNC(emit)};
            continue;
        };

        if (_now >= (_r getVariable [QGVAR(nextFlip), 0])) then {
            [_r, !_lit] call FUNC(emit);
            _r setVariable [QGVAR(nextFlip), _now + GVAR(blinkMin) + random _span];
        };
    } forEach _mine;

    // --- 2. the floor -----------------------------------------------------
    if (GVAR(minEmitters) > 0) then {
        private _lit = _mine select {_x getVariable [QGVAR(radiating), false]};
        private _need = (GVAR(minEmitters) min (count _mine)) - (count _lit);

        if (_need > 0) then {
            // a set held off by a Site is not the floor's to light either
            private _dark = (_mine - _lit) select {!(_x getVariable [QGVAR(heldOff), false])};

            // Longest dark first. `since` is when a set last changed state, so
            // ascending puts the one that has been quiet longest at the front.
            //
            // SORTED ON TWO NUMBERS, NOT ON [time, object]. Arma compares
            // arrays element by element, and two sets registered in the same
            // frame carry the same `since` - which would leave it comparing the
            // OBJECTS to break the tie. The index is the tiebreak instead.
            private _keyed = [];
            {
                _keyed pushBack [_x getVariable [QGVAR(since), 0], _forEachIndex];
            } forEach _dark;
            _keyed sort true;

            {
                if (_forEachIndex >= _need) exitWith {};
                private _r = _dark select (_x select 1);
                [_r, true] call FUNC(emit);
                // Its turn starts now: without this it would be eligible to
                // flip straight back down on the next tick.
                _r setVariable [QGVAR(nextFlip), _now + GVAR(blinkMin) + random _span];
            } forEach _keyed;
        };
    };

    // --- 3. the ambush ----------------------------------------------------
    if (GVAR(ambush)) then {
        [_side, _mine] call FUNC(ambush);
    };
} forEach (call FUNC(sides));

// The beat owns up when it is slow. This runs every few seconds for the whole
// mission, so a quiet pass logs nothing - but a pass that ate a chunk of a
// frame is exactly the line somebody hunting a stutter needs to find, or to
// find missing.
private _ms = (diag_tickTime - _clock) * 1000;
if (_ms > IADS_SLOW_MS) then {
    WARNING_2("tick took %1 ms over %2 radar(s)",round _ms,count GVAR(radars));
};
