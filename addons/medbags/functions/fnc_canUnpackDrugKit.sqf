#include "..\script_component.hpp"
/*

 * \jmfsb_medical\supplies\functions\fn_canUnpackMedicKit.sqf
 * by YonV
 *
 * check if medical supplies can be unpacked
 *
 * Arguments:
 * 0: unit - <OBJECT>
 *
 * Return:
 * <BOOLEAN>
 *
 * Example:
 * [player] call jmfsb_medbags_fnc_canUnpackMedicKit;
 *
 */

// -------------------------------------------------------------------------------------------------

private _unit = param [0, objNull, [objNull]];

// -------------------------------------------------------------------------------------------------

if (isNull _unit) exitWith {false};

// -------------------------------------------------------------------------------------------------

(
    ("jmfsb_medbags_DrugKit" in items _unit) &&
    (alive _unit) &&
    [player, 2] call ace_common_fnc_isMedic &&   // a Medic (class 2): the lifesaver has the Medic Bag
    !(_unit getVariable ["ace_captives_isSurrendering", false]) &&
    !(_unit getVariable ["ace_captives_isHandcuffed", false]) &&
    !(_unit getVariable ["ace_isUnconscious", false]) &&
    (not visibleMap)
);
