#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "jmfsb_uniform_pla_Soldier_U_B_CombatUniform_A", "jmfsb_uniform_pla_Soldier_U_B_CombatUniform_vest_A", "jmfsb_uniform_pla_Soldier_U_B_CombatUniform_tshirt_A", "jmfsb_uniform_pla_Soldier_U_B_GhillieSuit_A", "jmfsb_uniform_pla_B_Kitbag_rgr_A", "jmfsb_uniform_pla_B_Carryall_A", "jmfsb_uniform_pla_B_AssaultPack_A", "jmfsb_uniform_pla_B_ViperHarness_A", "jmfsb_uniform_pla_B_ViperLightHarness_A", "jmfsb_uniform_pla_B_FieldPack_A", "jmfsb_uniform_pla_B_TacticalPack_A", "jmfsb_uniform_pla_B_RadioBag_01_A", "jmfsb_uniform_pla_Soldier_U_Tank_A", "jmfsb_uniform_pla_Soldier_U_O_PilotCoveralls_A", "jmfsb_uniform_pla_Soldier_U_B_HeliPilotCoveralls_A", "jmfsb_uniform_pla_Soldier_U_O_V_Soldier_Viper_A", "jmfsb_uniform_pla_Soldier_U_B_CombatUniform_W", "jmfsb_uniform_pla_Soldier_U_B_CombatUniform_vest_W", "jmfsb_uniform_pla_Soldier_U_B_CombatUniform_tshirt_W", "jmfsb_uniform_pla_Soldier_U_B_GhillieSuit_W", "jmfsb_uniform_pla_B_Kitbag_rgr_W", "jmfsb_uniform_pla_B_Carryall_W", "jmfsb_uniform_pla_B_AssaultPack_W", "jmfsb_uniform_pla_B_ViperHarness_W", "jmfsb_uniform_pla_B_ViperLightHarness_W", "jmfsb_uniform_pla_B_FieldPack_W", "jmfsb_uniform_pla_B_TacticalPack_W", "jmfsb_uniform_pla_B_RadioBag_01_W", "jmfsb_uniform_pla_Soldier_U_Tank_W", "jmfsb_uniform_pla_Soldier_U_O_PilotCoveralls_W", "jmfsb_uniform_pla_Soldier_U_B_HeliPilotCoveralls_W", "jmfsb_uniform_pla_Soldier_U_O_V_Soldier_Viper_W", "jmfsb_uniform_pla_B_ViperHarness_hex_M_F_A", "jmfsb_uniform_pla_B_ViperHarness_hex_TL_F_A", "jmfsb_uniform_pla_B_ViperHarness_hex_Medic_F_A", "jmfsb_uniform_pla_B_ViperHarness_hex_LAT_F_A", "jmfsb_uniform_pla_B_ViperHarness_hex_JTAC_F_A", "jmfsb_uniform_pla_B_ViperHarness_hex_Exp_F_A", "jmfsb_uniform_pla_B_FieldPack_ocamo_Medic_A", "jmfsb_uniform_pla_B_FieldPack_cbr_LAT_A", "jmfsb_uniform_pla_B_FieldPack_cbr_HAT_A", "jmfsb_uniform_pla_B_FieldPack_blk_DiverExp_A", "jmfsb_uniform_pla_B_FieldPack_ocamo_LAT_F_A", "jmfsb_uniform_pla_B_FieldPack_oucamo_AT_A", "jmfsb_uniform_pla_B_FieldPack_ocamo_AA_A", "jmfsb_uniform_pla_B_FieldPack_cbr_Ammo_A", "jmfsb_uniform_pla_B_FieldPack_ocamo_ReconMedic_A", "jmfsb_uniform_pla_B_FieldPack_cbr_AT_A", "jmfsb_uniform_pla_B_FieldPack_cbr_Ammo_F_A", "jmfsb_uniform_pla_B_FieldPack_cbr_RPG_AT_A", "jmfsb_uniform_pla_B_FieldPack_ocamo_ReconExp_A", "jmfsb_uniform_pla_B_FieldPack_cbr_Repair_A", "jmfsb_uniform_pla_B_FieldPack_oucamo_LAT_A", "jmfsb_uniform_pla_B_FieldPack_oucamo_AA_A", "jmfsb_uniform_pla_B_FieldPack_oucamo_Medic_A", "jmfsb_uniform_pla_B_FieldPack_oucamo_Ammo_A", "jmfsb_uniform_pla_B_FieldPack_oucamo_Repair_A", "jmfsb_uniform_pla_B_TacticalPack_ocamo_AT_F_A", "jmfsb_uniform_pla_B_TacticalPack_ocamo_AA_F_A", "jmfsb_uniform_pla_B_Carryall_oucamo_AAA_A", "jmfsb_uniform_pla_B_Carryall_cbr_AHAT_A", "jmfsb_uniform_pla_B_Carryall_oucamo_Eng_A", "jmfsb_uniform_pla_B_Carryall_oucamo_AAT_A", "jmfsb_uniform_pla_B_Carryall_ocamo_Eng_A", "jmfsb_uniform_pla_B_Carryall_ocamo_AAR_A", "jmfsb_uniform_pla_B_Carryall_cbr_AAT_A", "jmfsb_uniform_pla_B_Carryall_oucamo_Exp_A", "jmfsb_uniform_pla_B_Carryall_ocamo_Exp_A", "jmfsb_uniform_pla_B_Carryall_ocamo_AAA_A", "jmfsb_uniform_pla_B_Carryall_oucamo_AAR_A", "jmfsb_uniform_pla_B_Carryall_ocamo_Mine_A", "jmfsb_uniform_pla_B_AssaultPack_ocamo_Medic_F_A", "jmfsb_uniform_pla_B_RadioBag_01_hex_F_A", "jmfsb_uniform_pla_B_ViperHarness_hex_M_F_W", "jmfsb_uniform_pla_B_ViperHarness_hex_TL_F_W", "jmfsb_uniform_pla_B_ViperHarness_hex_Medic_F_W", "jmfsb_uniform_pla_B_ViperHarness_hex_LAT_F_W", "jmfsb_uniform_pla_B_ViperHarness_hex_JTAC_F_W", "jmfsb_uniform_pla_B_ViperHarness_hex_Exp_F_W", "jmfsb_uniform_pla_B_FieldPack_ocamo_Medic_W", "jmfsb_uniform_pla_B_FieldPack_cbr_LAT_W", "jmfsb_uniform_pla_B_FieldPack_cbr_HAT_W", "jmfsb_uniform_pla_B_FieldPack_blk_DiverExp_W", "jmfsb_uniform_pla_B_FieldPack_ocamo_LAT_F_W", "jmfsb_uniform_pla_B_FieldPack_oucamo_AT_W", "jmfsb_uniform_pla_B_FieldPack_ocamo_AA_W", "jmfsb_uniform_pla_B_FieldPack_cbr_Ammo_W", "jmfsb_uniform_pla_B_FieldPack_ocamo_ReconMedic_W", "jmfsb_uniform_pla_B_FieldPack_cbr_AT_W", "jmfsb_uniform_pla_B_FieldPack_cbr_Ammo_F_W", "jmfsb_uniform_pla_B_FieldPack_cbr_RPG_AT_W", "jmfsb_uniform_pla_B_FieldPack_ocamo_ReconExp_W", "jmfsb_uniform_pla_B_FieldPack_cbr_Repair_W", "jmfsb_uniform_pla_B_FieldPack_oucamo_LAT_W", "jmfsb_uniform_pla_B_FieldPack_oucamo_AA_W", "jmfsb_uniform_pla_B_FieldPack_oucamo_Medic_W", "jmfsb_uniform_pla_B_FieldPack_oucamo_Ammo_W", "jmfsb_uniform_pla_B_FieldPack_oucamo_Repair_W", "jmfsb_uniform_pla_B_TacticalPack_ocamo_AT_F_W", "jmfsb_uniform_pla_B_TacticalPack_ocamo_AA_F_W", "jmfsb_uniform_pla_B_Carryall_oucamo_AAA_W", "jmfsb_uniform_pla_B_Carryall_cbr_AHAT_W", "jmfsb_uniform_pla_B_Carryall_oucamo_Eng_W", "jmfsb_uniform_pla_B_Carryall_oucamo_AAT_W", "jmfsb_uniform_pla_B_Carryall_ocamo_Eng_W", "jmfsb_uniform_pla_B_Carryall_ocamo_AAR_W", "jmfsb_uniform_pla_B_Carryall_cbr_AAT_W", "jmfsb_uniform_pla_B_Carryall_oucamo_Exp_W", "jmfsb_uniform_pla_B_Carryall_ocamo_Exp_W", "jmfsb_uniform_pla_B_Carryall_ocamo_AAA_W", "jmfsb_uniform_pla_B_Carryall_oucamo_AAR_W", "jmfsb_uniform_pla_B_Carryall_ocamo_Mine_W", "jmfsb_uniform_pla_B_AssaultPack_ocamo_Medic_F_W", "jmfsb_uniform_pla_B_RadioBag_01_hex_F_W"
        };
        weapons[] = {
            "jmfsb_uniform_pla_U_B_CombatUniform_A",
            "jmfsb_uniform_pla_U_B_CombatUniform_vest_A",
            "jmfsb_uniform_pla_U_B_CombatUniform_tshirt_A",
            "jmfsb_uniform_pla_U_B_GhillieSuit_A",
            "jmfsb_uniform_pla_H_HelmetO_A",
            "jmfsb_uniform_pla_H_HelmetLeaderO_A",
            "jmfsb_uniform_pla_H_HelmetSpecO_A",
            "jmfsb_uniform_pla_H_Booniehat_A",
            "jmfsb_uniform_pla_V_CarrierRigKBT_01_A",
            "jmfsb_uniform_pla_V_CarrierRigKBT_01_heavy_A",
            "jmfsb_uniform_pla_V_CarrierRigKBT_01_light_A",
            "jmfsb_uniform_pla_H_HelmetHBK_A",
            "jmfsb_uniform_pla_H_HelmetHBK_chops_A",
            "jmfsb_uniform_pla_H_HelmetHBK_ear_A",
            "jmfsb_uniform_pla_H_HelmetHBK_headset_A",
            "jmfsb_uniform_pla_U_Tank_A",
            "jmfsb_uniform_pla_U_O_PilotCoveralls_A",
            "jmfsb_uniform_pla_U_B_HeliPilotCoveralls_A",
            "jmfsb_uniform_pla_H_HelmetCrew_A",
            "jmfsb_uniform_pla_H_PilotHelmetHeli_A",
            "jmfsb_uniform_pla_H_CrewHelmetHeli_A",
            "jmfsb_uniform_pla_H_MilCap_A",
            "jmfsb_uniform_pla_H_Cap_A",
            "jmfsb_uniform_pla_V_SmershVest_01_A",
            "jmfsb_uniform_pla_V_SmershVest_01_radio_A",
            "jmfsb_uniform_pla_H_HelmetO_ViperSP_A",
            "jmfsb_uniform_pla_U_O_V_Soldier_Viper_A",
            "jmfsb_uniform_pla_U_B_CombatUniform_W",
            "jmfsb_uniform_pla_U_B_CombatUniform_vest_W",
            "jmfsb_uniform_pla_U_B_CombatUniform_tshirt_W",
            "jmfsb_uniform_pla_U_B_GhillieSuit_W",
            "jmfsb_uniform_pla_H_HelmetO_W",
            "jmfsb_uniform_pla_H_HelmetLeaderO_W",
            "jmfsb_uniform_pla_H_HelmetSpecO_W",
            "jmfsb_uniform_pla_H_Booniehat_W",
            "jmfsb_uniform_pla_V_CarrierRigKBT_01_W",
            "jmfsb_uniform_pla_V_CarrierRigKBT_01_heavy_W",
            "jmfsb_uniform_pla_V_CarrierRigKBT_01_light_W",
            "jmfsb_uniform_pla_H_HelmetHBK_W",
            "jmfsb_uniform_pla_H_HelmetHBK_chops_W",
            "jmfsb_uniform_pla_H_HelmetHBK_ear_W",
            "jmfsb_uniform_pla_H_HelmetHBK_headset_W",
            "jmfsb_uniform_pla_U_Tank_W",
            "jmfsb_uniform_pla_U_O_PilotCoveralls_W",
            "jmfsb_uniform_pla_U_B_HeliPilotCoveralls_W",
            "jmfsb_uniform_pla_H_HelmetCrew_W",
            "jmfsb_uniform_pla_H_PilotHelmetHeli_W",
            "jmfsb_uniform_pla_H_CrewHelmetHeli_W",
            "jmfsb_uniform_pla_H_MilCap_W",
            "jmfsb_uniform_pla_H_Cap_W",
            "jmfsb_uniform_pla_V_SmershVest_01_W",
            "jmfsb_uniform_pla_V_SmershVest_01_radio_W",
            "jmfsb_uniform_pla_H_HelmetO_ViperSP_W",
            "jmfsb_uniform_pla_U_O_V_Soldier_Viper_W"
        };
        requiredVersion = REQUIRED_VERSION;
        // Base-game characters only: every parent is A3's. ACP itself is NOT
        // required - its textures are vendored under data/.
        requiredAddons[] = {"jmfsb_main", "A3_Characters_F", "A3_Characters_F_Exp", "A3_Characters_F_Enoch", "A3_Characters_F_Tank"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
