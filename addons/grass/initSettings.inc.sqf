[
    QGVAR(enabled),
    "CHECKBOX",
    ["Force Grass", "Forces grass for all players"],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Grass"],
    false,
    1,
    {[_this] call FUNC(toggle)}
] call CBA_fnc_addSetting;
