class XtdGearModels {
    class CfgWeapons {
        class GVAR(KBT) {
            label = "KBT Rig";
            options[] = {"type", "camo"};
            class type {
                alwaysSelectable = 1;
                values[] = {"Base", "Combat", "Command", "Compact", "CQB", "Crew", "Heavy", "Holster", "Light", "Recon", "Tactical"};
                class Base {
                    label = "Base";
                };
                class Combat {
                    label = "Combat";
                };
                class Command {
                    label = "Command";
                };
                class Compact {
                    label = "Compact";
                };
                class CQB {
                    label = "CQB";
                };
                class Crew {
                    label = "Crew";
                };
                class Heavy {
                    label = "Heavy";
                };
                class Holster {
                    label = "Holster";
                };
                class Light {
                    label = "Light";
                };
                class Recon {
                    label = "Recon";
                };
                class Tactical {
                    label = "Tactical";
                };
            };
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Sand", "Olive", "MTP_Arid", "MTP_Desert", "MTP_Tropic", "MTP_Woodland", "MTP_Alpine", "OCP"};
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Sand {
                    label = "Sand";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class MTP_Arid {
                    label = "MTP-Ard";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class MTP_Desert {
                    label = "MTP-Des";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class MTP_Tropic {
                    label = "MTP-Trp";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class MTP_Woodland {
                    label = "MTP-Wdl";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP_Alpine {
                    label = "MTP-Alp";
                    image = "z\aceax\addons\gearinfo\data\camo\gry.paa";
                };
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_black_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_olive_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_sand_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_black_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_black_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_olive_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_sand_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_black_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_olive_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_sand_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_black_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_olive_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_sand_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_black_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_olive_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_sand_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_black_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_olive_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_sand_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_black_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_olive_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_sand_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_black_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_olive_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_sand_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_olive_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_black_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_olive_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_sand_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_sand_F) {
            model = QGVAR(KBT);
            type = "Base";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_alpine_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "MTP_Alpine";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_arid_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "MTP_Arid";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_desert_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "MTP_Desert";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_tropic_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "MTP_Tropic";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_woodland_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "MTP_Woodland";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_black_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "Black";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_olive_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "Olive";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_sand_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "Sand";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_combat_ocp_F) {
            model = QGVAR(KBT);
            type = "Combat";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_command_ocp_F) {
            model = QGVAR(KBT);
            type = "Command";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_compact_ocp_F) {
            model = QGVAR(KBT);
            type = "Compact";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_CQB_ocp_F) {
            model = QGVAR(KBT);
            type = "CQB";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_crew_ocp_F) {
            model = QGVAR(KBT);
            type = "Crew";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_heavy_ocp_F) {
            model = QGVAR(KBT);
            type = "Heavy";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_holster_ocp_F) {
            model = QGVAR(KBT);
            type = "Holster";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_light_ocp_F) {
            model = QGVAR(KBT);
            type = "Light";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_recon_ocp_F) {
            model = QGVAR(KBT);
            type = "Recon";
            camo = "OCP";
        };
        class GVAR(JCA_V_CarrierRigKBT_01_tactical_ocp_F) {
            model = QGVAR(KBT);
            type = "Tactical";
            camo = "OCP";
        };
    };
};
