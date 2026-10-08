#include "..\script_component.hpp"
/*
 * Which magazine a value button stands for, from where the row is now.
 *
 * ACEAX's own rule: an EXACT match is the member of the family that has the
 * asked-for value on that axis and the current values on every other axis;
 * failing that, a WEAK match is any member that has the asked-for value at all
 * - the arsenal simply does not carry the exact one, and offering the nearest
 * beats greying the button out. Only members that were in the panel count
 * (GVAR(present)), so nothing the weapon does not take is ever resolved to.
 *
 * Arguments:
 * 0: Family <STRING>
 * 1: The row's current class, lowercase <STRING>
 * 2: Axis <STRING>
 * 3: Value <STRING>
 *
 * Return Value:
 * [class (lowercase, "" for none), exact match <BOOL>] <ARRAY>
 */

params ["_family", "_current", "_axis", "_value"];

private _members = GVAR(present) getOrDefault [_family, []];
private _axes = (GVAR(axes) getOrDefault [_family, []]) apply { _x select 0 };

private _fnc_valueOf = {
    params ["_class", "_axis"];
    (((GVAR(values) getOrDefault [_class, []]) select { (_x select 0) isEqualTo _axis }) param [0, ["", ""]]) select 1
};

// the values wanted on every axis: the row's own, with this one swapped
private _want = _axes apply {
    if (_x isEqualTo _axis) then { _value } else { [_current, _x] call _fnc_valueOf }
};

private _exact = _members findIf {
    private _class = _x;
    (_axes apply { [_class, _x] call _fnc_valueOf }) isEqualTo _want
};
if (_exact > -1) exitWith { [_members select _exact, true] };

private _weak = _members findIf { ([_x, _axis] call _fnc_valueOf) isEqualTo _value };
if (_weak > -1) exitWith { [_members select _weak, false] };

["", false]
