#include "script_component.hpp"
/*
 * Author: Jacco Douma, JMSB
 * Deletes every marker this machine drew last pass.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call jmfsb_bft_fnc_remove
 *
 * Public: No
 */

{
    deleteMarkerLocal _x;
} forEach GVAR(markers);

GVAR(markers) = [];
