#include "script_component.hpp"
/*
 * Author: Jacco Douma, JMSB
 * Takes a group off every network it only listens to.
 *
 * Arguments:
 * 0: Group <GROUP>
 *
 * Return Value:
 * The group's listen list, empty <ARRAY>
 *
 * Example:
 * [group this] call jmfsb_bft_fnc_networkClearObserved
 *
 * Public: Yes
 */

params [["_group", grpNull, [grpNull]]];

[_group, "*"] call FUNC(networkRemoveObserver)
