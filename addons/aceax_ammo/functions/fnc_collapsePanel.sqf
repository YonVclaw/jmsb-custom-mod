#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * Collapse the ammo panel so each family occupies one row.
 *
 * Runs a frame after ace_arsenal_rightPanelFilled, once ACE has finished
 * sorting the list and restoring the selection - the timing @aceaxatt uses for
 * the attachment slots, and for the same reason. At that point the panel holds
 * exactly the magazines valid here: ACE has already filtered by
 * compatibleMagazines and by what the arsenal offers, so this needs to know
 * nothing about the weapon.
 *
 * THE ROWS ARE THE TRUTH. What survives is decided from a snapshot of the
 * panel, and what the dropdown may offer afterwards is exactly the members
 * that were IN the panel (GVAR(present)) - never the family's whole roster
 * from config, which would let a player pick a tracer variant the arsenal
 * does not carry or this muzzle does not take.
 *
 * WHICH ROW SURVIVES: the highlighted one if it is in the family, so the
 * collapse never moves the player's selection off what they had; else the
 * variant the player last picked for that family (GVAR(choice)), so moving to
 * another weapon and back keeps it; else the family's first row, which leaves
 * the panel in ACE's own sort order.
 *
 * Collapsing the LIST and not ace_arsenal_virtualItems is deliberate, for the
 * same reason the attachment compat does it: magazine compatibility is per
 * weapon, so a representative chosen once and globally could be one the
 * selected weapon does not take, and the whole family would disappear.
 * Nothing of ACE's is written.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 *
 * Return Value:
 * None
 */

params ["_display"];

GVAR(present) = createHashMap;

private _debug = missionNamespace getVariable [QGVAR(debug), false];
([_display] call FUNC(panelControl)) params ["_ctrl", "_isLnb"];

// Logged BEFORE any early exit, as @aceaxatt learned to: a pass that finds no
// control or no rows has to say so, or a config fault looks exactly like a
// script that never ran.
if (_debug) then {
    diag_log format ["[jmfsb_aceax_ammo] collapse: left=%1 right=%2 ctrlNull=%3 lnb=%4 rows=%5 enabled=%6",
        missionNamespace getVariable ["ace_arsenal_currentLeftPanel", "nil"],
        missionNamespace getVariable ["ace_arsenal_currentRightPanel", "nil"],
        isNull _ctrl, _isLnb,
        if (isNull _ctrl) then { -1 } else { if (_isLnb) then { (lnbSize _ctrl) select 0 } else { lbSize _ctrl } },
        missionNamespace getVariable [QGVAR(enabled), true]];
};

if (isNull _ctrl) exitWith {};
if !(missionNamespace getVariable [QGVAR(enabled), true]) exitWith {};

private _rows = if (_isLnb) then { (lnbSize _ctrl) select 0 } else { lbSize _ctrl };
if (_rows < 2) exitWith {};

private _selected = if (_isLnb) then { lnbCurSelRow _ctrl } else { lbCurSel _ctrl };

// ---- read the whole panel before touching it ----
// Deleting renumbers the rows underneath, so every decision is made from this
// snapshot and only then acted on.
private _rowClass = [];
for "_i" from 0 to (_rows - 1) do {
    _rowClass pushBack (toLower (if (_isLnb) then { _ctrl lnbData [_i, 0] } else { _ctrl lbData _i }));
};

// ---- bucket the rows by family ----
private _byFamily = createHashMap;   // family -> row indices, in panel order
{
    private _family = GVAR(model) get _x;
    if (isNil "_family") then { continue };
    (_byFamily getOrDefault [_family, [], true]) pushBack _forEachIndex;
    (GVAR(present) getOrDefault [_family, [], true]) pushBack _x;
} forEach _rowClass;

// ---- one row per family ----
private _doomed = [];
{
    private _family = _x;
    private _idx = _y;
    if (count _idx < 2) then { continue };

    private _keep = -1;
    if (_selected in _idx) then {
        _keep = _selected;
    } else {
        private _want = GVAR(choice) get _family;
        if (!isNil "_want") then {
            private _pos = (_idx apply { _rowClass select _x }) find _want;
            if (_pos > -1) then { _keep = _idx select _pos };
        };
    };
    if (_keep < 0) then { _keep = _idx select 0 };

    { if (_x != _keep) then { _doomed pushBack _x } } forEach _idx;
    if (_debug) then {
        diag_log format ["[jmfsb_aceax_ammo]   %1: rows %2, keeping %3 (%4)", _family, _idx, _keep, _rowClass select _keep];
    };
} forEach _byFamily;

// ---- one name per row ----
// Every row of ours reads "[JMSB] <rounds> <calibre> <load> (<magazine>)"
// rather than its magazine's own displayName, which leaves out the calibre and
// the magazine and is shared by a base round and its three tiers. Renamed
// before the deletions, while the snapshot's indices still hold; the tooltip
// keeps the magazine's own name and class.
{
    private _name = GVAR(rowName) get _x;
    if (isNil "_name") then { continue };
    if (_isLnb) then { _ctrl lnbSetText [[_forEachIndex, 1], _name] } else { _ctrl lbSetText [_forEachIndex, _name] };
} forEach _rowClass;

if (_doomed isEqualTo []) exitWith {
    if (_debug) then { diag_log "[jmfsb_aceax_ammo] collapse: nothing to fold" };
};

// ---- delete bottom-up ----
// Highest index first, so each deletion only renumbers rows already dealt with
// and no index bookkeeping is needed at all.
_doomed sort false;
{
    if (_isLnb) then { _ctrl lnbDeleteRow _x } else { _ctrl lbDelete _x };
} forEach _doomed;

// ---- keep the highlight on the row that had it ----
// Every deleted row above the selection moves it up one. The engine keeps the
// NUMBER, not the row, so the highlight is put back where the class went -
// and only when it actually moved, because lbSetCurSel fires ACE's own
// handler.
if (_selected > -1 && {!(_selected in _doomed)}) then {
    private _now = _selected - ({ _x < _selected } count _doomed);
    private _cur = if (_isLnb) then { lnbCurSelRow _ctrl } else { lbCurSel _ctrl };
    if (_cur != _now) then {
        if (_isLnb) then { _ctrl lnbSetCurSelRow _now } else { _ctrl lbSetCurSel _now };
    };
};

if (_debug) then {
    private _left = if (_isLnb) then { (lnbSize _ctrl) select 0 } else { lbSize _ctrl };
    diag_log format ["[jmfsb_aceax_ammo] collapse: %1 rows -> %2, %3 famil(ies) seen", _rows, _left, count _byFamily];
};
