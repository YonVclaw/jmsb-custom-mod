#include "script_component.hpp"

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};

(
    (QGVAR(vs17) in items _unit) &&
    (alive _unit) &&
    !(_unit getVariable ["ace_captives_isSurrendering", false]) &&
    !(_unit getVariable ["ace_captives_isHandcuffed", false]) &&
    !(_unit getVariable ["ace_isUnconscious", false]) &&
    !(visibleMap)
);
