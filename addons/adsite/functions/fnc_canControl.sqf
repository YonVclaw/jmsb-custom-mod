#include "..\script_component.hpp"
/*
 * Author: JMSB
 * May this unit change a Site's settings, order intercepts and call strikes?
 *
 * Only a unit on the Site's side, and then by the Site's own access rule (the
 * module's "Tacpad Control"): its CREW, anyone NEAR it (inside the protected
 * area) or the whole SIDE. A Zeus may always - it is editing the mission.
 * Asked on the server for every order; the panel asks it too, only to grey out
 * what would be refused.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Board row of the Site (FUNC(board)) <ARRAY>
 *
 * Return Value:
 * Allowed <BOOL>
 *
 * Example:
 * [player, _row] call jmfsb_adsite_fnc_canControl
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]], ["_row", [], [[]]]];

if (isNull _unit || {_row isEqualTo []}) exitWith {false};
if (!isNull getAssignedCuratorLogic _unit) exitWith {true};
_row params ["", "", "_side", "_centre", "_radius", "", "", "_access", "_members"];
if (side group _unit isNotEqualTo _side) exitWith {false};

switch (_access) do {
    case "side": { true };
    case "crew": { _members findIf {(vehicle _unit) isEqualTo (objectFromNetId (_x # 0))} > -1 };
    default { (_unit distance2D ASLToAGL _centre) <= _radius };
}
