#include "script_component.hpp"
/*
 * Author: JMSB
 * Persists which leaders are spent, so a restart resumes the campaign rather
 * than undoing it. The dead stay dead (rule 5: finite, no regeneration).
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Public: No
 */

if (isNil "jmfsb_adapter_alive_fnc_setData") exitWith {};

private _spent = [];
{
    if ((_x select 2) isNotEqualTo "up") then { _spent pushBack _forEachIndex };
} forEach GVAR(leaders);

[QGVAR(spent), _spent] call jmfsb_adapter_alive_fnc_setData;
