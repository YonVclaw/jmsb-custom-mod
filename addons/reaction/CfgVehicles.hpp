class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Edit;
        };
        class ModuleDescription;
    };

    // PLACING THIS MODULE IS THE ENABLE. No module, no enemy reaction - there is no
    // separate on switch to forget, and no system quietly running because a
    // setting defaulted to on in a mission that never asked for one.
    //
    // Every attribute here is an OPERATION value: how many, how often, how
    // likely. WHERE and WHO are never asked for - those come from ALiVE's own
    // commanders, their TAORs and their objectives, so this cannot be pointed
    // at ground its commander does not operate on.
    class jmfsb_moduleReaction: Module_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "JMSB - Enemy Reaction";
        author = QAUTHOR;
        category = "jmfsb_modules";
        function = QUOTE(DFUNC(moduleController));
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;
        icon = "\a3\ui_f\data\map\markers\nato\o_recon.paa";

        class Attributes: AttributesBase {
            class failChance: Edit {
                property = QGVAR(failChance);
                displayName = "Hack Fail Chance (%)";
                tooltip = "Chance an intrusion fails outright.";
                typeName = "NUMBER";
                defaultValue = "25";
                expression = QUOTE(_this setVariable [ARR_2('failChance',_value)]);
            };
            class detectChance: Edit {
                property = QGVAR(detectChance);
                displayName = "Detection Chance (%)";
                tooltip = "Chance a failure, a drone sighting or a transmission is noticed. The first notice is silent; the second brings the response.";
                typeName = "NUMBER";
                defaultValue = "50";
                expression = QUOTE(_this setVariable [ARR_2('detectChance',_value)]);
            };
            class roundsMin: Edit {
                property = QGVAR(roundsMin);
                displayName = "Barrage Rounds Min";
                tooltip = "Fewest shells a major response puts down.";
                typeName = "NUMBER";
                defaultValue = "4";
                expression = QUOTE(_this setVariable [ARR_2('roundsMin',_value)]);
            };
            class roundsMax: Edit {
                property = QGVAR(roundsMax);
                displayName = "Barrage Rounds Max";
                tooltip = "Most shells. The real count is rolled between the two.";
                typeName = "NUMBER";
                defaultValue = "10";
                expression = QUOTE(_this setVariable [ARR_2('roundsMax',_value)]);
            };
            class watts: Edit {
                property = QGVAR(watts);
                displayName = "Radio Watts Watched";
                tooltip = "Transmit power at or above which a radio can be direction-found. Squad radios sit below it; an ACRE SATCOM antenna is exempt.";
                typeName = "NUMBER";
                defaultValue = "1";
                expression = QUOTE(_this setVariable [ARR_2('watts',_value)]);
            };
        };

        class ModuleDescription: ModuleDescription {
            description[] = {
                "Placing this module turns on enemy reaction. Without it, the system is off.",
                "",
                "Hack Fail Chance (%) - Chance an intrusion fails outright",
                "Detection Chance (%) - Chance a failure, a drone sighting or a transmission is noticed",
                "Barrage Rounds Min - Fewest shells a major response puts down",
                "Barrage Rounds Max - Most shells",
                "Radio Watts Watched - Transmit power at or above which a radio can be direction-found",
            };
        };
    };
};
