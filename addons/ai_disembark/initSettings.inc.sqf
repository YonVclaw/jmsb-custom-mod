
[
    QGVAR(enabled),
    "CHECKBOX",
    ["Force reload on disembarking AI", "Forces AI to play reload animation after disembarking from vehicle. Prevents instant shooting after disembark."],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - AI Disembark"],
    false,
    1
] call CBA_fnc_addSetting;

[
    QGVAR(stayInImmobileChance),
    "SLIDER",
    ["Stay in immobile vehicle chance", "Chance that AI will be told to stay in immobilized vehicles, applied on vehicle init."],
    ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - AI Disembark"],
    [0, 1, 0, 0, true],
    1
] call CBA_fnc_addSetting;
