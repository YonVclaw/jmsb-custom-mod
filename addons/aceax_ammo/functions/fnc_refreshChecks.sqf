#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * Mark the value the highlighted row has on each axis and grey out the ones
 * that lead nowhere.
 *
 * ACEAX's rules: a value is lit when it is the row's own; pressable when a
 * member holds it - drawn plain for an exact match on the other axes, in the
 * weak-match wash when the arsenal only carries it with some other finish or
 * tier; disabled when no member in the panel holds it at all.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 * 1: The row's current class, lowercase <STRING>
 * 2: Family <STRING>
 *
 * Return Value:
 * None
 */

params ["_display", "_current", "_family"];

private _cfg = configFile >> "CfgMagazines" >> _current;
(_display displayCtrl IDC_optionsTitle) ctrlSetText getText (_cfg >> "displayName");

private _own = GVAR(values) getOrDefault [_current, []];

{
    private _axisIndex = _forEachIndex;
    _x params ["_axis", "", "_values"];
    private _mine = (( _own select { (_x select 0) isEqualTo _axis }) param [0, ["", ""]]) select 1;

    {
        private _button = _display displayCtrl (IDC_VALUE_BASE + _axisIndex * 100 + _forEachIndex);
        if (isNull _button) then { continue };

        private _value = _x;
        ([_family, _current, _axis, _value] call FUNC(resolve)) params ["_class", "_exact"];
        private _lit = _value isEqualTo _mine;

        _button ctrlEnable (_class isNotEqualTo "");
        _button ctrlSetBackgroundColor (switch (true) do {
            case (_lit): { [SELECTED_BG_COLOR] };
            case (_class isNotEqualTo "" && {!_exact}): { [WEAK_MATCH_BG_COLOR] };
            default { [INVISIBLE_COLOR] };
        });
        _button ctrlSetTextColor ([[WEAK_MATCH_TEXT_COLOR], [EXACT_MATCH_TEXT_COLOR]] select (_exact || _lit));
        _button ctrlCommit 0;
    } forEach _values;
} forEach GVAR(drawn);
