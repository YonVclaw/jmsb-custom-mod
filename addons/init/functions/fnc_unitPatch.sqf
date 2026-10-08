#include "script_component.hpp"
/*
 * Author: YonV
 * Keeps the battalion patch (jmfsb_media_patch) on a unit's uniform while the
 * Insignia setting is on.
 *
 * A PATCH THE MAN CHOSE IS HIS. Only an empty shoulder or our own patch is
 * (re)applied, so the Medic, EOD and JFIRE patches - or anything picked in the
 * arsenal - stay where they are.
 *
 * WHY THE UNIFORM IS REMEMBERED. The engine paints an insignia on the uniform,
 * not the man: a new uniform comes up bare while BIS_fnc_getUnitInsignia still
 * names the old class, and BIS_fnc_setUnitInsignia skips a class it thinks is
 * already on. So when the uniform changes, ours is cleared and put back.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call jmfsb_init_fnc_unitPatch
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]]];

if (isNull _unit || {!local _unit} || {!EGVAR(Settings,allowInsigniaApplication)}) exitWith {};

private _uniform = uniform _unit;
if (_uniform isEqualTo "") exitWith {};

private _patch = QEGVAR(media,patch);
private _current = [_unit] call BIS_fnc_getUnitInsignia;
if !(_current in ["", _patch]) exitWith {};

private _changed = _uniform isNotEqualTo (_unit getVariable [QGVAR(patchUniform), ""]);
if (_current isEqualTo _patch && !_changed) exitWith {};

if (_current isEqualTo _patch) then {[_unit, ""] call BIS_fnc_setUnitInsignia};
[_unit, _patch] call BIS_fnc_setUnitInsignia;
_unit setVariable [QGVAR(patchUniform), _uniform];
