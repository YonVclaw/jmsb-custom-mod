#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * ButtonClick handler for a value button in the option panel.
 *
 * The button carries its axis and value; the row that is highlighted says
 * where we are; fnc_resolve says which magazine that makes. The panel is then
 * refreshed rather than rebuilt - the same family is still up, so only the
 * marks move - which matters because this runs INSIDE the button's own click:
 * a control deleted in its own handler is how a panel stops answering.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 * 1: The button <CONTROL>
 *
 * Return Value:
 * None
 */

params ["_display", "_button"];

(_button getVariable [QGVAR(pick), []]) params [["_axis", "", [""]], ["_value", "", [""]]];
if (_axis isEqualTo "") exitWith {};

([_display] call FUNC(panelControl)) params ["_ctrl", "_isLnb"];
if (isNull _ctrl) exitWith {};
private _sel = if (_isLnb) then { lnbCurSelRow _ctrl } else { lbCurSel _ctrl };
if (_sel < 0) exitWith {};

private _current = toLower (if (_isLnb) then { _ctrl lnbData [_sel, 0] } else { _ctrl lbData _sel });
private _family = GVAR(model) get _current;
if (isNil "_family") exitWith {};

([_family, _current, _axis, _value] call FUNC(resolve)) params ["_class"];
if (_class isEqualTo "" || _class isEqualTo _current) exitWith {};

[_display, _class] call FUNC(pickVariant);
[_display] call FUNC(refreshOptions);
