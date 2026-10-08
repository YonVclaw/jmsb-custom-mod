#include "script_component.hpp"
/*
 * Author: Jacco Douma, JMSB
 * Takes a group off every network it transmits on.
 *
 * Arguments:
 * 0: Group <GROUP>
 *
 * Return Value:
 * The group's transmit list, empty <ARRAY>
 *
 * Example:
 * [group this] call jmfsb_bft_fnc_networkClear
 *
 * Public: Yes
 */

params [["_group", grpNull, [grpNull]]];

[_group, "*"] call FUNC(networkRemove)
