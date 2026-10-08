#include "..\script_component.hpp"
#include "..\defines.hpp"
/*
 * The control currently holding the ammo rows, or controlNull.
 *
 * TWO THINGS have to be true and they come from opposite sides of the dialog:
 * the RIGHT panel has to be one of the six that list CfgMagazines, and which
 * CONTROL those rows landed in is decided by the LEFT panel - ACE builds into
 * the listbox and then swaps to the listnbox when the left panel is a
 * container. Reading the wrong control finds zero rows and the collapse
 * silently does nothing, which is indistinguishable from the data being wrong.
 *
 * Arguments:
 * 0: Arsenal display <DISPLAY>
 *
 * Return Value:
 * [control, isListnBox] - control is controlNull when this is not an ammo panel <ARRAY>
 */

params ["_display"];

// ACE nils these when the arsenal closes, and the collapse runs a frame late,
// so it can land after that even though the display was valid when scheduled.
if (isNil "ace_arsenal_currentRightPanel" || {isNil "ace_arsenal_currentLeftPanel"}) exitWith {
    [controlNull, false]
};

if !(ace_arsenal_currentRightPanel in [AMMO_PANEL_IDCS]) exitWith { [controlNull, false] };

private _isContainer = ace_arsenal_currentLeftPanel in [CONTAINER_PANEL_IDCS];
private _ctrl = _display displayCtrl ([IDC_rightTabContent, IDC_rightTabContentListnBox] select _isContainer);

if (isNull _ctrl) exitWith { [controlNull, false] };
[_ctrl, _isContainer]
