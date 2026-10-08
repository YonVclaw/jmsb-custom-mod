#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_common_fnc_sortGroupsBySide

Description:
    Filters a list of groups down to one side.

Parameters:
    _groups : ARRAY of GROUP
    _side   : SIDE

Returns:
    ARRAY of GROUP

Example:
    [allGroups, side player] call jmfsb_common_fnc_sortGroupsBySide;

Author:
    Mr H. (original, MRHMilsimTools, ADPL-SA), ported by JMSB
---------------------------------------------------------------------------- */
params [["_groups", [], [[]]], "_side"];

_groups select {side _x isEqualTo _side}
