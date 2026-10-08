
if (EGVAR(common,aceTagging)) then {
    [
        QGVAR(enabled),
        "CHECKBOX",
        ["Enable ACE Tagging markers", "Automatically create markers on buildings sprayed with ACE Spray."],
        ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Tagging"],
        false,
        true
    ] call CBA_fnc_addSetting;
};
