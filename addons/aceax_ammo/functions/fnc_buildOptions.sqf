#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * Build the option panel for a family: the magazine's name, then one row of
 * value buttons per axis it varies on - Tracer: Red / Green / ..., Finish:
 * Black / Tan / ... - four to a row, in ACEAX's own geometry.
 *
 * Mirrors aceaxatt_main_fnc_generateOptionsUI. The group is created once per
 * arsenal display and emptied and refilled when the family changes; a family
 * that is still up only has its marks refreshed (fnc_refreshChecks), because a
 * panel rebuilt under the cursor is a panel that does not take the click.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 * 1: The row's current class, lowercase <STRING>
 * 2: Family <STRING>
 * 3: Axes to draw - [axis, axis label, [values], [labels]] each, only those
 *    with more than one value present <ARRAY>
 *
 * Return Value:
 * None
 */

params ["_display", "_current", "_family", "_axes"];

private _group = _display displayCtrl IDC_optionsGroup;
if (isNull _group) then {
    _group = _display ctrlCreate [QGVAR(group), IDC_optionsGroup];
} else {
    { ctrlDelete _x } forEach GVAR(controls);
};
GVAR(controls) = [];

// ---- the head: the magazine and how many it stands for ----
private _title = _display ctrlCreate [QGVAR(title), IDC_optionsTitle, _group];
_title ctrlSetPosition [0, 0];
_title ctrlSetText getText (configFile >> "CfgMagazines" >> _current >> "displayName");
_title ctrlCommit 0;
GVAR(controls) pushBack _title;

private _sub = _display ctrlCreate [QGVAR(sub), IDC_optionsSub, _group];
_sub ctrlSetPosition [0, 7 * GRID_H];
_sub ctrlSetText format ["%1 variants", count (GVAR(present) getOrDefault [_family, []])];
_sub ctrlCommit 0;
GVAR(controls) pushBack _sub;

// ---- the axes ----
private _posY = 12;
{
    private _axisIndex = _forEachIndex;
    _x params ["_axis", "_axisLabel", "_values", "_labels"];

    private _head = _display ctrlCreate [QGVAR(axisTitle), IDC_AXIS_TITLE_BASE + _axisIndex, _group];
    _head ctrlSetPosition [0, _posY * GRID_H];
    _head ctrlSetText _axisLabel;
    _head ctrlCommit 0;
    GVAR(controls) pushBack _head;
    _posY = _posY + 6;

    private _posX = 0;
    {
        private _button = _display ctrlCreate [QGVAR(valueButton), IDC_VALUE_BASE + _axisIndex * 100 + _forEachIndex, _group];
        _button ctrlSetPosition [_posX * GRID_W, _posY * GRID_H];
        _button ctrlSetText (_labels select _forEachIndex);
        _button setVariable [QGVAR(pick), [_axis, _x]];
        _button ctrlAddEventHandler ["ButtonClick", {
            [ctrlParent (_this select 0), _this select 0] call FUNC(onValueButton);
        }];
        _button ctrlCommit 0;
        GVAR(controls) pushBack _button;

        _posX = _posX + 20;
        if (_posX >= 80) then {
            _posX = 0;
            _posY = _posY + 10;
        };
    } forEach _values;

    if (_posX != 0) then { _posY = _posY + 10 };
    _posY = _posY + 2;
} forEach _axes;

GVAR(drawn) = _axes;
GVAR(adjusted) = 120 min (_posY + 2);
[_display, GVAR(adjusted)] call FUNC(layout);
