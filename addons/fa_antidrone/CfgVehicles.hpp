class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            // Mk364 programmable-airburst range submenu. Only shown while the
            // player has a Mk364 magazine; mirrors the CBA "cycle" keybind.
            class GVAR(mk364) {
                displayName = "Mk364 Airburst Range";
                condition = QUOTE(call FUNC(hasMk364));
                statement = "";
                class GVAR(mk364_off) { displayName = "Off (proximity only)"; condition = "true"; statement = QUOTE([0]   call FUNC(setBurst)); };
                class GVAR(mk364_100) { displayName = "100 m";                condition = "true"; statement = QUOTE([100] call FUNC(setBurst)); };
                class GVAR(mk364_150) { displayName = "150 m";                condition = "true"; statement = QUOTE([150] call FUNC(setBurst)); };
                class GVAR(mk364_200) { displayName = "200 m";                condition = "true"; statement = QUOTE([200] call FUNC(setBurst)); };
                class GVAR(mk364_250) { displayName = "250 m";                condition = "true"; statement = QUOTE([250] call FUNC(setBurst)); };
                class GVAR(mk364_300) { displayName = "300 m";                condition = "true"; statement = QUOTE([300] call FUNC(setBurst)); };
                class GVAR(mk364_400) { displayName = "400 m";                condition = "true"; statement = QUOTE([400] call FUNC(setBurst)); };
            };
        };
    };
};
