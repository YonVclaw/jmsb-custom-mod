#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * ace_arsenal_rightPanelFilled - schedule the collapse.
 *
 * ACE raises this partway through fnc_fillRightPanel: the list is built, but
 * fillSort has not re-sorted it yet and the previous selection has not been
 * restored. Collapsing here would mean interleaving with both.
 *
 * TWO FRAMES LATER, not one. One frame later ACE has finished completely -
 * the timing @aceaxatt uses. But @aceaxatt runs on that same frame and, on a
 * panel that is not an attachment slot, puts the listbox back to full height;
 * the option panel this addon seats under the list needs the last word on
 * that height, so it waits one frame more. Two frames of the full list is
 * still imperceptible.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 * 1: Current left panel IDC <NUMBER>
 * 2: Current right panel IDC <NUMBER>
 *
 * Return Value:
 * None
 */

params ["_display", "_leftPanel", "_rightPanel"];

// Any other panel, or the setting off: the option panel must not be left
// standing under an attachment list, and the list we shortened goes back to
// full - @aceaxatt, if it is there, sets its own height a frame later.
if (!(_rightPanel in [AMMO_PANEL_IDCS]) || {!(missionNamespace getVariable [QGVAR(enabled), true])}) exitWith {
    private _group = _display displayCtrl IDC_optionsGroup;
    if (!isNull _group) then { _group ctrlShow false };

    // ONLY PUT BACK A LIST WE SHORTENED. This used to restore full height on
    // every panel that was not ours, on the reasoning that @aceaxatt sets its
    // own height a frame later and would win. That is no longer true in either
    // half: since 1.1.0.0 @aceaxatt owns the four weapon-magazine panels, and
    // this hook is deferred two frames against its one, so ours writes LAST -
    // an unconditional reset here would drop their options panel out from under
    // their list every time one of those tabs is opened.
    //
    // GVAR(built) is the honest test: non-empty means our own panel is up and
    // the list under it is short because of us. Empty means the layout belongs
    // to somebody else and is none of our business.
    if (GVAR(built) isNotEqualTo "") then {
        private _isContainer = _leftPanel in [CONTAINER_PANEL_IDCS];
        private _ctrl = _display displayCtrl ([IDC_rightTabContent, IDC_rightTabContentListnBox] select _isContainer);
        if (!isNull _ctrl) then {
            _ctrl ctrlSetPositionH (LIST_FULL_H(_isContainer));
            _ctrl ctrlCommit 0;
        };
    };

    GVAR(built) = "";
};

[{
    [{
        params ["_display"];
        if (isNull _display) exitWith {};

        [_display] call FUNC(collapsePanel);
        [_display] call FUNC(refreshOptions);

        // The panel has to follow the highlighted row, and ACE raises no event
        // for a row change. Hooked once per control, here rather than at
        // display load, because which control holds the rows changes with the
        // left panel - and after @aceaxatt's own hook, so on a click ours has
        // the last word on the list's height.
        ([_display] call FUNC(panelControl)) params ["_ctrl"];
        if (isNull _ctrl) exitWith {};
        if !(_ctrl getVariable [QGVAR(hooked), false]) then {
            _ctrl setVariable [QGVAR(hooked), true];
            _ctrl ctrlAddEventHandler ["LBSelChanged", {
                [ctrlParent (_this select 0)] call FUNC(refreshOptions);
            }];
        };
    }, _this] call CBA_fnc_execNextFrame;
}, [_display]] call CBA_fnc_execNextFrame;
