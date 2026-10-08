[
    QGVAR(fatalInjuriesCardiacArrestTimeCoefficient),
    "SLIDER",
    ["Fatal Injuries Cardiac Arrest Time Coefficient", "Coefficient for controlling the Cardiac Arrest Time on fatal injuries when 'Fatal Injuries' is NOT 'Always'."],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    [0.01, 1, 0.2, 2],
    true // isGlobal
] call CBA_fnc_addSetting;
