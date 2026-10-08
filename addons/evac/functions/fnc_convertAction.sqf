#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_evac_fnc_convertAction

Description:
    Runs the medic's evac progress bar, then performs the evac. Re-checks
    canConvert on completion so the action can't resolve on a target that woke
    up, died, or was already evacuated mid-bar.

Parameters:
    _medic    : OBJECT - the medic performing the evac.
    _casualty : OBJECT - the downed player being evacuated.

Returns:
    None

Author:
    JMSB
---------------------------------------------------------------------------- */
params ["_medic", "_casualty"];

if (isNull objectParent _medic) then {
    [_medic] call ace_common_fnc_goKneeling;
};

[
    GVAR(time),
    [_medic, _casualty],
    {
        (_this select 0) params ["_medic", "_casualty"];
        if !([_medic, _casualty] call FUNC(canConvert)) exitWith {
            ["Evac", "Failed.", [0.831, 0.267, 0.267, 1]] call EFUNC(notify,notify);
        };
        [_medic, _casualty] call FUNC(convert);
        ["Evac", "Casualty evacuated - reinforcement inbound.", [0.4, 0.702, 0.4, 1]] call EFUNC(notify,notify);
    },
    {
        (_this select 0) params ["_medic"];
        ["Evac", "Cancelled.", [0.871, 0.361, 0.188, 1]] call EFUNC(notify,notify);
    },
    "Evacuating casualty...",
    {true},
    ["isNotInside"]
] call ace_common_fnc_progressBar;
