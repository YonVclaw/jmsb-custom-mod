class CfgVehicles {
    class Item_optic_Nightstalker;
    class Item_optic_AMS;

    class GVAR(Item_optic_Nightstalker): Item_optic_Nightstalker {
        displayName="[JMSB] Nightstalker";
        author="NemesisRE";
        vehicleClass="WeaponAccessories";
        class TransportItems {
            class GVAR(optic_Nightstalker) {
                name=QGVAR(optic_Nightstalker);
                count=1;
            };
        };
    };

    class GVAR(Item_optic_AMS): Item_optic_AMS {
        displayName="[JMSB] AMS (Black)";
        author="NemesisRE";
        class TransportItems {
            class GVAR(optic_AMS) {
                name=QGVAR(optic_AMS);
                count=1;
            };
        };
    };

    class GVAR(Item_optic_AMS_khk): GVAR(Item_optic_AMS) {
        displayName="[JMSB] AMS (Khaki)";
        class TransportItems {
            class GVAR(optic_AMS_khk) {
                name=QGVAR(optic_AMS_khk);
                count=1;
            };
        };
    };

    class GVAR(Item_optic_AMS_snd): GVAR(Item_optic_AMS) {
        displayName="[JMSB] AMS (Sand)";
        class TransportItems {
            class GVAR(optic_AMS_snd) {
                name=QGVAR(optic_AMS_snd);
                count=1;
            };
        };
    };

    class GVAR(Item_optic_AMSTI): Item_optic_AMS {
        displayName="[JMSB] AMS-TI (Black)";
        author="NemesisRE";
        class TransportItems {
            class GVAR(optic_AMSTI) {
                name=QGVAR(optic_AMSTI);
                count=1;
            };
        };
    };

    class GVAR(Item_optic_AMSTI_khk): GVAR(Item_optic_AMSTI) {
        displayName="[JMSB] AMS-TI (Khaki)";
        class TransportItems {
            class GVAR(optic_AMSTI_khk) {
                name=QGVAR(optic_AMSTI_khk);
                count=1;
            };
        };
    };

    class GVAR(Item_optic_AMSTI_snd): GVAR(Item_optic_AMSTI) {
        displayName="[JMSB] AMS-TI (Sand)";
        class TransportItems {
            class GVAR(optic_AMSTI_snd) {
                name=QGVAR(optic_AMSTI_snd);
                count=1;
            };
        };
    };

};
