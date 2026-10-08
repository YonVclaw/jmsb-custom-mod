#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_evac_fnc_canConvert

Description:
    Gate for the medic "Evacuate (Reinforce)" action. True only when the target
    is a downed (ACE-unconscious) living player that hasn't already been
    evacuated, and - if the Medics Only setting is on - the caller is an ACE
    medic.

Parameters:
    _medic    : OBJECT - the unit doing the evac (the interacting player).
    _casualty : OBJECT - the downed player being evacuated (the ACE target).

Returns:
    BOOL

Author:
    JMSB
---------------------------------------------------------------------------- */
params ["_medic", "_casualty"];

if !(GVAR(enabled)) exitWith { false };
// ACM brings its own evacuation; ours stands down behind it (see XEH_postInit).
if (missionNamespace getVariable [QEGVAR(patches,usesACM), false]) exitWith { false };
if (_medic isEqualTo _casualty) exitWith { false };
if !(isPlayer _casualty) exitWith { false };
if !(alive _casualty) exitWith { false };
if !(_casualty getVariable ["ACE_isUnconscious", false]) exitWith { false };
if (_casualty getVariable [QGVAR(claimed), false]) exitWith { false };
if (GVAR(medicOnly) && {!([_medic] call ace_medical_treatment_fnc_isMedic)}) exitWith { false };

true
