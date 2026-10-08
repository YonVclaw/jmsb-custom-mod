#include "script_component.hpp"
/*
 * Author: JMSB
 * The sides whose air defence this manages: every side the players are not on.
 *
 * NOT AN ATTRIBUTE, BY RULE (D59). Sides are typed once in this mod - JMSB -
 * Enemy names the hostile one, JMSB - Core names the players' - and a module
 * that asked again would be a fourth place to say something different by
 * accident. This derives it the same way jmfsb_uas keeps enemy drones off
 * friendly commanders: hostility is asked of the engine rather than assumed
 * from the side names, so a mission that made west and independent friends
 * gets what it asked for.
 *
 * A PLAYER-SIDE SAM IS THE PLAYERS' PROBLEM. Blinking it would be this mod
 * reaching into the section's own hardware and switching it off, which is not
 * what an enemy air defence system is for.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Sides <ARRAY of SIDE>
 *
 * Example:
 * private _sides = call jmfsb_iads_fnc_sides
 *
 * Public: No
 */

private _mine = call EFUNC(common,playerSides);

// No player slots at all means nobody to be hostile to. Managing everything is
// the useful answer rather than switching off: an empty editor mission with two
// radars dropped on the ground is exactly where this gets tested first.
if (_mine isEqualTo []) exitWith {[east, west, independent]};

[east, west, independent] select {
    private _s = _x;
    (_mine findIf {(_s getFriend _x) >= 0.6}) < 0
}
