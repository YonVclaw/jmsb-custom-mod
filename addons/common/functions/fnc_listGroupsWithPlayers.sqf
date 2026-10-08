#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_common_fnc_listGroupsWithPlayers

Description:
    Every group that currently contains at least one player.

Parameters:
    None.

Returns:
    ARRAY of GROUP

Author:
    Mr H. (original, MRHMilsimTools, ADPL-SA), ported by JMSB
---------------------------------------------------------------------------- */
allGroups select {({isPlayer _x} count (units _x)) > 0}
