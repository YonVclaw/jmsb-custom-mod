#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * Bring the option panel in line with whatever row is highlighted.
 *
 * A collapsed row hides the rest of its family, so there has to be somewhere
 * to reach them: the same panel under the list that @aceaxatt gives an optic
 * or a suppressor (user, 2026-08-29: "the ACEAX accessories should include the
 * ammo") - one row of buttons per axis the family varies on.
 *
 * READ FROM THE PANEL, NOT FROM A ROW MAP. The highlighted row names its class
 * in its own data, and the family comes from that. ACE re-sorts the list in
 * place when the sort dropdown changes and raises no event for it, so anything
 * keyed on row numbers is wrong after the first re-sort.
 *
 * Idempotent: the controls are only rebuilt when the family or the members in
 * the list change; otherwise only the marks move. That is what makes it safe
 * to call from a value button's own click.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 *
 * Return Value:
 * None
 */

params ["_display"];

([_display] call FUNC(panelControl)) params ["_ctrl", "_isLnb"];

// Not an ammo panel - the click hook fires on attachment panels too - or the
// setting off. The panel goes away; the list's height is somebody else's.
if (isNull _ctrl || {!(missionNamespace getVariable [QGVAR(enabled), true])}) exitWith {
    [_display, 0, false] call FUNC(layout);
    GVAR(built) = "";
};

private _sel = if (_isLnb) then { lnbCurSelRow _ctrl } else { lbCurSel _ctrl };
if (_sel < 0) exitWith {
    [_display, 0] call FUNC(layout);
    GVAR(built) = "";
};

private _current = toLower (if (_isLnb) then { _ctrl lnbData [_sel, 0] } else { _ctrl lbData _sel });
private _family = GVAR(model) get _current;
private _members = if (isNil "_family") then { [] } else { GVAR(present) getOrDefault [_family, []] };

// A magazine with no variants in this list has nothing to choose.
if (count _members < 2) exitWith {
    [_display, 0] call FUNC(layout);
    GVAR(built) = "";
};

// ---- the axes worth drawing: those with more than one value in the list ----
// In the family's own value order, so Red / Green / Yellow come out the same
// way on every magazine.
private _fnc_valueOf = {
    params ["_class", "_axis"];
    (((GVAR(values) getOrDefault [_class, []]) select { (_x select 0) isEqualTo _axis }) param [0, ["", ""]]) select 1
};
private _axes = [];
{
    _x params ["_axis", "_axisLabel", "_values", "_labels"];
    private _present = _members apply { [_x, _axis] call _fnc_valueOf };
    private _have = [];
    private _haveLabels = [];
    {
        if (_x in _present) then {
            _have pushBack _x;
            _haveLabels pushBack (_labels select _forEachIndex);
        };
    } forEach _values;
    if (count _have > 1) then { _axes pushBack [_axis, _axisLabel, _have, _haveLabels] };
} forEach (GVAR(axes) getOrDefault [_family, []]);

if (_axes isEqualTo []) exitWith {
    [_display, 0] call FUNC(layout);
    GVAR(built) = "";
};

// ---- build when the family or its members changed, else just the marks ----
private _key = format ["%1|%2", _family, _members];
if (_key isNotEqualTo GVAR(built) || {isNull (_display displayCtrl IDC_optionsGroup)}) then {
    [_display, _current, _family, _axes] call FUNC(buildOptions);
    GVAR(built) = _key;
} else {
    [_display, GVAR(adjusted)] call FUNC(layout);
};

[_display, _current, _family] call FUNC(refreshChecks);
