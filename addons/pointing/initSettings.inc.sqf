
if (EGVAR(common,aceFinger)) then {
    [
        QGVAR(vehicleEnabled),
        "CHECKBOX",
        ["Enable pointing in vehicles", "Allows to point current camera direction in vehicles to rest of the crew."],
        ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - Pointing"],
        true,
        true
    ] call CBA_fnc_addSetting;
};
