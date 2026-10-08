
if (EGVAR(common,aceSafemode)) then {
    [
        QGVAR(startLocked),
        "CHECKBOX",
        ["Lock weapon", "Locks your weapon safety on game start"],
        ["1st Joint Multi-Functional Strike Battalion", "1st Joint Multi-Functional Strike Battalion - safestart"],
        true,
        2
    ] call CBA_fnc_addSetting;
};
