// Reeveli's two settings, under jmfsb's own category.

[
    QGVAR(actionRadius),
    "SLIDER",
    ["Action visibility radius", "How close to a teleport object the action shows, in metres."],
    ["1st Joint Multi-Functional Strike Battalion", "Teleport"],
    [5, 30, 5, 0],
    1,
    {}
] call CBA_fnc_addSetting;

[
    QGVAR(actionTime),
    "SLIDER",
    ["Teleportation time", "How long the move and its screen fade last, in seconds."],
    ["1st Joint Multi-Functional Strike Battalion", "Teleport"],
    [1, 120, 6, 0],
    1,
    {}
] call CBA_fnc_addSetting;
