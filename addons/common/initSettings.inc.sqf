// CBA Settings [ADDON: jmfsb_common]

[
    QGVAR(isrVariable), "EDITBOX",
    ["ISR unit variable", "Name of the unit variable marking someone as an ISR operator. Gates the hacking tablet and Intel Hunt processing. Set it on a unit with: this setVariable ['isISR', true]"],
    ["1st Joint Multi-Functional Strike Battalion", "Common"],
    "isISR",
    true
] call CBA_fnc_addSetting;

// The threat board's own debug - every contact filed, in the RPT.
[
    QGVAR(boardDebug), "CHECKBOX",
    ["Threat Board Debug", "Log every contact jmfsb's sensors file on a side's threat board - what that side knows, where, how wrong it might be, and which sensor said so."],
    ["1st Joint Multi-Functional Strike Battalion", "Common"],
    false,
    true
] call CBA_fnc_addSetting;
