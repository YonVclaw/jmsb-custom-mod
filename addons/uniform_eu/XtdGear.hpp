class XtdGearModels {
    class CfgWeapons {
        class GVAR(CombatUniformNCU) {
            label = "Euro Combat Uniform";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"MTP", "MTP_W", "OCP"};
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
                class MTP_W {
                    label = "MTP-W";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Full", "RolledUp"};
                class Full {
                    label = "Full";
                };
                class RolledUp {
                    label = "Rolled";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        class GVAR(U_CombatUniformNCU_01_mcam_F) {
            model = QGVAR(CombatUniformNCU);
            camo = "MTP";
            type = "Full";
        };
        class GVAR(U_CombatUniformNCU_02_mcam_F) {
            model = QGVAR(CombatUniformNCU);
            camo = "MTP";
            type = "RolledUp";
        };
        class GVAR(U_CombatUniformNCU_01_mcam_wdl_F) {
            model = QGVAR(CombatUniformNCU);
            camo = "MTP_W";
            type = "Full";
        };
        class GVAR(U_CombatUniformNCU_02_mcam_wdl_F) {
            model = QGVAR(CombatUniformNCU);
            camo = "MTP_W";
            type = "RolledUp";
        };
        class GVAR(U_CombatUniformNCU_01_ocp_F) {
            model = QGVAR(CombatUniformNCU);
            camo = "OCP";
            type = "Full";
        };
        class GVAR(U_CombatUniformNCU_02_ocp_F) {
            model = QGVAR(CombatUniformNCU);
            camo = "OCP";
            type = "RolledUp";
        };
    };
};
