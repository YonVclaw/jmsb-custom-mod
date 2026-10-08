// CBA Settings [ADDON: jmfsb_evac]

[
    QGVAR(enabled), "CHECKBOX",
    ["Enable Medic Evac", "Master toggle for the medic 'Evacuate (Reinforce)' action that replaces respawn."],
    ["1st Joint Multi-Functional Strike Battalion", "Evac"],
    true,   // default
    true    // isGlobal
] call CBA_fnc_addSetting;

[
    QGVAR(medicOnly), "CHECKBOX",
    ["Medics Only", "If checked, only ACE medics can evacuate a downed player. Uncheck to let anyone do it."],
    ["1st Joint Multi-Functional Strike Battalion", "Evac"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(time), "SLIDER",
    ["Evac Time (s)", "How long the medic's evacuate progress bar takes, in seconds."],
    ["1st Joint Multi-Functional Strike Battalion", "Evac"],
    [0, 60, EVAC_DEFAULT_TIME, 0],
    true
] call CBA_fnc_addSetting;
