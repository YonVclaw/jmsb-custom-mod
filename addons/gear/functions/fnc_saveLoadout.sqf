#include "script_component.hpp"
/*
 * Author: CPL.Brostrom.A
 * This function save players loadout
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * true or false <BOOL>
 *
 * Example:
 * [player] call jmfsb_gear_fnc_saveLoadout
 *
 */

params [["_unit", objNull, [objNull]]];

private _loadout = [_unit] call CBA_fnc_getLoadout;
_loadout = [_loadout] call EFUNC(systems,filterUnitLoadout);

_unit setVariable [QEGVAR(Gear,Loadout), _loadout];
_unit setVariable [QEGVAR(Gear,SavedLoadout), true];

// PAC keeps it too, per role, when that addon is loaded - one "save" for the player.
if (!isNil "jmfsb_pac_fnc_loadoutSave") then {[_unit] call jmfsb_pac_fnc_loadoutSave};

["Gear", "Loadout has been saved.", NOTE_GOOD] call JMFSBFUNC(notify,notify);

_unit getVariable [QEGVAR(Gear,SavedLoadout), false];
