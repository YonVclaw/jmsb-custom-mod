#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * Point the highlighted, collapsed row at another member of its family, and
 * load it.
 *
 * The row keeps its place in the list and only changes what it stands for -
 * its data, its text and its picture - and then ACE's own selection handler is
 * called on it, exactly as @aceaxatt does for an attachment. Rewriting a row's
 * data fires no LBSelChanged, and neither does clicking a row that is already
 * highlighted, so without that call the player would pick a tracer colour that
 * nothing loaded until they clicked some other row and came back. In container
 * mode the +/- buttons read the row when they are pressed, and ACE's listnbox
 * handler only refreshes the item info.
 *
 * Nothing of ACE's state is touched: from ACE's side this is a row that
 * happens to name a different magazine than it did a moment ago.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 * 1: The magazine to swap in, any case <STRING>
 *
 * Return Value:
 * Swapped <BOOL>
 */

params ["_display", "_class"];

([_display] call FUNC(panelControl)) params ["_ctrl", "_isLnb"];
if (isNull _ctrl || _class isEqualTo "") exitWith { false };

private _sel = if (_isLnb) then { lnbCurSelRow _ctrl } else { lbCurSel _ctrl };
if (_sel < 0) exitWith { false };

// Only ever swap within one family: the panel was built for the row that is
// highlighted, and this is the guard that it still is.
private _was = toLower (if (_isLnb) then { _ctrl lnbData [_sel, 0] } else { _ctrl lbData _sel });
private _family = GVAR(model) get _was;
if (isNil "_family" || {(GVAR(model) get (toLower _class)) isNotEqualTo _family}) exitWith { false };
if ((toLower _class) isEqualTo _was) exitWith { false };

private _cfg = configFile >> "CfgMagazines" >> _class;
_class = configName _cfg;
private _name = getText (_cfg >> "displayName");
private _pic = getText (_cfg >> "picture");
// the row keeps its family's name (fnc_collapsePanel); the tooltip says which variant it now holds
private _row = GVAR(rowName) getOrDefault [toLower _class, _name];

if (_isLnb) then {
    _ctrl lnbSetData [[_sel, 0], _class];
    _ctrl lnbSetText [[_sel, 1], _row];
    _ctrl lnbSetPicture [[_sel, 0], _pic];
    _ctrl lnbSetTooltip [[_sel, 0], format ["%1%2%3", _name, endl, _class]];
} else {
    _ctrl lbSetData [_sel, _class];
    _ctrl lbSetText [_sel, _row];
    _ctrl lbSetPicture [_sel, _pic];
    _ctrl lbSetTooltip [_sel, format ["%1%2%3", _name, endl, _class]];
};

// Remembered per family, so this variant is the one that survives the next
// collapse - on this weapon, or on another that takes the same magazines.
GVAR(choice) set [_family, toLower _class];

// Load it. ACE reads the row's data and does everything it would on a click.
if (_isLnb) then {
    [_ctrl, _sel] call ace_arsenal_fnc_onSelChangedRightListnBox;
} else {
    [_ctrl, _sel] call ace_arsenal_fnc_onSelChangedRight;
};

TRACE_2("variant picked",_sel,_class);
true
