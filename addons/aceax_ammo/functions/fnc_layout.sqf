#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * Place the option panel under the list, or take it down.
 *
 * The list is shortened by the panel's height plus a gap and the panel is
 * seated in the room made - exactly the geometry @aceaxatt uses on the same
 * column, so a magazine's options sit where an optic's do.
 *
 * WHO OWNS THE LIST'S HEIGHT. @aceaxatt sets the listbox back to full height
 * whenever the panel it is looking at is not an attachment slot - on every
 * fill and on every row click, animated. This runs after it in both cases (a
 * frame later on fill, later-registered on the click), so on an ammo panel the
 * last word is ours. Off an ammo panel the list is never touched from here
 * unless the caller says so: our click hook also fires on attachment panels,
 * and resetting the height there would knock @aceaxatt's own panel out from
 * under the list it just shortened.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 * 1: Panel height in grid units, 0 to take it down <NUMBER>
 * 2: Put the list back to full height when taking the panel down <BOOL> (optional, default true)
 *
 * Return Value:
 * None
 */

params ["_display", "_adjusted", ["_touchList", true]];

private _group = _display displayCtrl IDC_optionsGroup;
([_display] call FUNC(panelControl)) params ["_ctrl", "_isLnb"];

if (isNull _ctrl) exitWith {
    if (!isNull _group) then { _group ctrlShow false };
};

private _full = LIST_FULL_H(_isLnb);

if (_adjusted <= 0) exitWith {
    if (!isNull _group) then { _group ctrlShow false };
    if (_touchList) then {
        _ctrl ctrlSetPositionH _full;
        _ctrl ctrlCommit 0;
    };
};

if (isNull _group) exitWith {};

(ctrlPosition _ctrl) params ["_x", "_y", "_w"];
_ctrl ctrlSetPositionH (_full - (_adjusted + OPTIONS_GAP) * GRID_H);
_ctrl ctrlCommit 0;
_group ctrlSetPosition [_x, _y + _full - _adjusted * GRID_H, _w, _adjusted * GRID_H];
_group ctrlCommit 0;
_group ctrlShow true;
