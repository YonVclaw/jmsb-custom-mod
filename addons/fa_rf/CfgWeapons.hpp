// Append the 2040 rounds to the RF 120mm Twin Mortar weapon (shared by the
// B/O/I TwinMortar_RF static vehicles from the Reaction Forces CDLC).
//
// Name the real parent (Twin_Mortar_120mm_RF: mortar_155mm_AMOS) rather than
// reopening it parentless. RF bases its twin-mortar WEAPON on the vanilla 155mm
// artillery weapon mortar_155mm_AMOS; in-game Config Viewer confirms the chain
// Twin_Mortar_120mm_RF -> mortar_155mm_AMOS -> CannonCore -> Default. NOTE: the
// vehicle base is TwinMortar_base_RF, but that is a CfgVehicles class and is NOT
// the weapon's parent — inheriting from it collapses the weapon to scope=private.
// A parentless reopen collapses it the same way, so name mortar_155mm_AMOS
// (defined in A3_Weapons_F, already in requiredAddons).
class CfgWeapons {
    // Glock 19X: its parent is Pistol_Base_F (work/orbat_dump_2026-08-30.rpt WEAPON line); the FA 9x19 mags ride
    // on a well of ours, so RF's own magazines and wells are left exactly as they are
    class Pistol_Base_F;
    class hgun_Glock19_RF: Pistol_Base_F {
        magazineWell[] += {"jmfsb_fa_Glock19_RF"};
    };
    class mortar_155mm_AMOS;
    class Twin_Mortar_120mm_RF: mortar_155mm_AMOS {
        magazines[] += {
            "FA_6Rnd_120mm_heer_B", "FA_6Rnd_120mm_heer_O", "FA_6Rnd_120mm_heer_I",
            "FA_2Rnd_120mm_apmi_B", "FA_2Rnd_120mm_apmi_O", "FA_2Rnd_120mm_apmi_I",
            "FA_2Rnd_120mm_lgm_B", "FA_2Rnd_120mm_lgm_O", "FA_2Rnd_120mm_lgm_I",
            "FA_4Rnd_120mm_smk_B", "FA_4Rnd_120mm_smk_O", "FA_4Rnd_120mm_smk_I",
            "FA_2Rnd_120mm_apmine_B", "FA_2Rnd_120mm_apmine_O", "FA_2Rnd_120mm_apmine_I",
            "FA_4Rnd_120mm_atmine_B", "FA_4Rnd_120mm_atmine_O", "FA_4Rnd_120mm_atmine_I",
            "FA_2Rnd_120mm_sfm_B", "FA_2Rnd_120mm_sfm_O", "FA_2Rnd_120mm_sfm_I",
            "FA_2Rnd_120mm_strix_B", "FA_2Rnd_120mm_strix_O", "FA_2Rnd_120mm_strix_I",
            "FA_6Rnd_120mm_tb_B", "FA_6Rnd_120mm_tb_O", "FA_6Rnd_120mm_tb_I",
            "FA_8Rnd_120mm_ir_B"
        };
    };
};
