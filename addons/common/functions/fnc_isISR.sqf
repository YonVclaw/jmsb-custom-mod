#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_common_fnc_isISR

Description:
    Is this unit an ISR operator? One test shared by everything that cares -
    the hacking tablet and Intel Hunt processing - so a mission sets the flag
    once and both respect it.

    The variable NAME is a setting rather than a constant, because missions that
    already mark ISR operators some other way should not have to rename anything.

Parameters:
    _unit : OBJECT - the unit. Optional, default the local player.

Returns:
    BOOL

Example:
    [player] call jmfsb_common_fnc_isISR

Author:
    JMSB
---------------------------------------------------------------------------- */
params [["_unit", objNull, [objNull]]];

if (isNull _unit) then { _unit = player };
if (isNull _unit) exitWith { false };

_unit getVariable [GVAR(isrVariable), false]
