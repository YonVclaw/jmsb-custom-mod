#include "script_component.hpp"

params [
    ["_target", objNull, [objNull]],
    ["_player", objNull, [objNull]]
];

if (isNull _target) exitWith {false};
if (isNull _player) exitWith {false};

private _item = QGVAR(vs17);

(
    alive _player &&
    !(_player getVariable ["ace_captives_isSurrendering", false]) &&
    !(_player getVariable ["ace_captives_isHandcuffed", false]) &&
    !(_player getVariable ["ace_isUnconscious", false]) &&
    (
        (_player canAdd _item) ||
        ((uniform _player != "") && (_player canAddItemToUniform _item)) ||
        ((vest _player != "") && (_player canAddItemToVest _item)) ||
        ((backpack _player != "") && (_player canAddItemToBackpack _item))
    )
);
