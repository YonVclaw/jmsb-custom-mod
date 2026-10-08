#include "script_component.hpp"
/*
 * Author: YonV
 * Raises a jmfsb notification for the firer, if they are local and have an
 * interface. Every 40mm payload says what it did through here, so the line
 * lands in the player's own notification stack - their corner, their duration,
 * their text size - instead of a hint that ignores all three.
 *
 * Arguments:
 * 0: Firer <OBJECT>
 * 1: Heading <STRING>
 * 2: Body <STRING> (optional, default "")
 * 3: Accent colour, RGBA <ARRAY> (optional, default ember)
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [
    ["_unit",   objNull, [objNull]],
    ["_title",  "",      [""]],
    ["_text",   "",      [""]],
    ["_colour", [0.871, 0.361, 0.188, 1], [[]], 4]
];
if (local _unit && {hasInterface}) then { [_title, _text, _colour] call EFUNC(notify,notify) };
