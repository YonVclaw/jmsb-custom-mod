
[
    QGVAR(overlayOpacity), "SLIDER",
    ["Overlay opacity", "Suppression overlay opacity, the higher the value the more visible will be the supression effect."],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    [0,1,0.96,2],
    true,
    {
        private _display = uiNamespace getVariable [QGVAR(overlay), displayNull];
        if (isNull _display) exitWith {};
        private _overlayCtrl = _display displayCtrl IDC_OVERLAY;
        _overlayCtrl ctrlSetTextColor [0, 0, 0, _this];
        _overlayCtrl ctrlCommit 0;
    },
    false
] call CBA_fnc_addSetting;

[
    QGVAR(overlayTexture), "LIST",
    ["Overlay texture type", "Level of darkness of overlay texture. Darker texture means more screen will be covered with overlay when suppressed."],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    [[0, 1, 2], ["Light", "Medium", "Dark"], 1],
    true,
    {
        private _display = uiNamespace getVariable [QGVAR(overlay), displayNull];
        if (isNull _display) exitWith {};
        private _overlayCtrl = _display displayCtrl IDC_OVERLAY;
        _overlayCtrl ctrlSetText (OVERLAYS_LIST select _this);
        _overlayCtrl ctrlCommit 0;
    },
    false
] call CBA_fnc_addSetting;

[
    QGVAR(overlayFadeoutTime), "SLIDER",
    ["Overlay fadeout time", "Suppression overlay fadeout time in seconds"],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    [1,30,10,1],
    true,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(projectileMaxDistance), "SLIDER",
    ["Projectile max distance", "Max distance from passing projectile in meters. Projectiles passing at larger distance won't be taken into account."],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    [1,10,9,2],
    true,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(shooterMinDistance), "SLIDER",
    ["Min distance from shooter", "Min distance from shooter in meters. This option can be used to disable effect in CQB situations, 0 to disable min distance."],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    [0,50,0,2],
    true,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(checkLOS), "CHECKBOX",
    ["Check line of sight", "When enabled, checks line of sight between player's eyes and passing projectile, ignoring projectiles passing behind cover, walls etc."],
    ["1st Joint Multi-Functional Strike Battalion", COMPONENT_NAME],
    false,
    true,
    {},
    false
] call CBA_fnc_addSetting;
