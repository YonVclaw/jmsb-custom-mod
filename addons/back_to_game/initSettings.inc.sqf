[
    QGVAR(enableAddon),
    "CHECKBOX",
    ["Enable Back To Game", "Activate teleport and loadout restore after reconnect."],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Back To Game"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(teleportToLeader),
    "CHECKBOX",
    ["Teleport to leader", "Allow player teleportation to his group leader."],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Back To Game"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(teleportToVehicle),
    "CHECKBOX",
    ["Teleport to vehicle", "Allow player teleportation to his last vehicle or group leader vehicle."],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Back To Game"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(removeBody),
    "CHECKBOX",
    ["Remove body", "Removes bodies of alive people who disconnected."],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Back To Game"],
    true,
    true
] call CBA_fnc_addSetting;
