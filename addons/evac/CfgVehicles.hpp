class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            // Interact-menu action on a downed teammate: the medic aims at the
            // unconscious player and evacuates them.
            class ACE_MainActions {
                class GVAR(evacuate) {
                    displayName = "Evacuate (Reinforce)";
                    icon = "\a3\ui_f\data\igui\cfg\actions\heal_ca.paa";
                    condition = QUOTE([ARR_2(_player,_target)] call FUNC(canConvert));
                    statement = QUOTE([ARR_2(_player,_target)] call FUNC(convertAction));
                    exceptions[] = {"isNotInside"};
                    showDisabled = 0;
                    priority = 2.5;
                    distance = 4;
                };
            };
        };
    };
};
