#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_evac_fnc_convert

Description:
    Performs the evac once the progress bar completes. Marks the casualty claimed
    (so it can't be evac'd twice in the round-trip window) and hands off to the
    server, which snapshots the casualty's injuries, spawns the matching AI
    casualty clone, then fully heals the real player onto the medic.

Parameters:
    _medic    : OBJECT - the medic performing the evac.
    _casualty : OBJECT - the downed player being evacuated.

Returns:
    None

Author:
    JMSB
---------------------------------------------------------------------------- */
params ["_medic", "_casualty"];

_casualty setVariable [QGVAR(claimed), true, true];

[QGVAR(evac), [_medic, _casualty]] call CBA_fnc_serverEvent;
