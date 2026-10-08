class CfgWeapons {
    // ---- external base classes (declared so inheritance is preserved) ----
    class EBR_base_F;
    class LMG_Mk200_F;
    class MMG_01_base_F;
    class arifle_SPAR_01_base_F;

    // ===== HK416 / M27 (5.56x45)  |  barrelMass x1.15, weight x1.15, dispersion x1.1 =====
    class sps_m27_base_f: arifle_SPAR_01_base_F {
        ACE_Overheating_Dispersion[] = {0, 0.00033, 0.00055, 0.00132};
    };
    class SPS_hk416_base_f: arifle_SPAR_01_base_F {
        ACE_Overheating_Dispersion[] = {0, 0.000275, 0.00044, 0.0011};
    };
    class sps_m27_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.725;
        };
    };
    class sps_hk416d_14_5_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.814998;
        };
    };
    class sps_hk416d_14_5_hk_ctr_vfg_black_f: sps_hk416d_14_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.939998;
        };
    };
    class sps_hk416d_14_5_t_ctr_vfg_black_f: sps_hk416d_14_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.939998;
        };
    };
    class sps_hk416d_14_5_hk_afg_black_f: sps_hk416d_14_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.814998;
        };
    };
    class sps_hk416d_14_5_hk_ctr_afg_black_f: sps_hk416d_14_5_hk_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.939998;
        };
    };
    class sps_hk416d_14_5_t_ctr_afg_black_f: sps_hk416d_14_5_hk_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.939998;
        };
    };
    class sps_hk416d_14_5_hk_black_f: sps_hk416d_14_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.939998;
        };
    };
    class sps_hk416d_14_5_hk_ctr_black_f: sps_hk416d_14_5_hk_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 84.064998;
        };
    };
    class sps_hk416d_14_5_t_ctr_black_f: sps_hk416d_14_5_hk_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 84.064998;
        };
    };
    class sps_hk416d_16_5_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 91.607416;
        };
    };
    class sps_hk416d_16_5_hk_ctr_vfg_black_f: sps_hk416d_16_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 88.732416;
        };
    };
    class sps_hk416d_16_5_t_ctr_vfg_black_f: sps_hk416d_16_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 88.732416;
        };
    };
    class sps_hk416d_16_5_hk_afg_black_f: sps_hk416d_16_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 91.607416;
        };
    };
    class sps_hk416d_16_5_hk_ctr_afg_black_f: sps_hk416d_16_5_hk_afg_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 88.732416;
        };
    };
    class sps_hk416d_16_5_t_ctr_afg_black_f: sps_hk416d_16_5_hk_afg_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 88.732416;
        };
    };
    class sps_hk416d_16_5_hk_black_f: sps_hk416d_16_5_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 88.732416;
        };
    };
    class sps_hk416d_16_5_hk_ctr_black_f: sps_hk416d_16_5_hk_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 85.857416;
        };
    };
    class sps_hk416d_16_5_t_ctr_black_f: sps_hk416d_16_5_hk_black_f {
        ace_overheating_barrelMass = 2.41845;
        class WeaponSlotsInfo {
            mass = 85.857416;
        };
    };
    class sps_hk416d_10_4_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 82.706445;
        };
    };
    class sps_hk416d_10_4_hk_ctr_vfg_black_f: sps_hk416d_10_4_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 79.831445;
        };
    };
    class sps_hk416d_10_4_t_ctr_vfg_black_f: sps_hk416d_10_4_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 79.831445;
        };
    };
    class sps_hk416d_10_4_hk_afg_black_f: sps_hk416d_10_4_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 82.706445;
        };
    };
    class sps_hk416d_10_4_hk_ctr_afg_black_f: sps_hk416d_10_4_hk_afg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 79.831445;
        };
    };
    class sps_hk416d_10_4_t_ctr_afg_black_f: sps_hk416d_10_4_hk_afg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 79.831445;
        };
    };
    class sps_hk416d_10_4_hk_black_f: sps_hk416d_10_4_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 79.831445;
        };
    };
    class sps_hk416d_10_4_hk_ctr_black_f: sps_hk416d_10_4_hk_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 76.956445;
        };
    };
    class sps_hk416d_10_4_t_ctr_black_f: sps_hk416d_10_4_hk_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 76.956445;
        };
    };
    class sps_hk416d_10_4_smr_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_vfg_black_f: sps_hk416d_10_4_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_vfg_black_f: sps_hk416d_10_4_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_afg_black_f: sps_hk416d_10_4_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_afg_black_f: sps_hk416d_10_4_smr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_afg_black_f: sps_hk416d_10_4_smr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_black_f: sps_hk416d_10_4_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_black_f: sps_hk416d_10_4_smr_hk_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_black_f: sps_hk416d_10_4_smr_hk_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_hk_vfg_sf_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_vfg_sf_black_f: sps_hk416d_10_4_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_vfg_sf_black_f: sps_hk416d_10_4_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_afg_sf_black_f: sps_hk416d_10_4_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_afg_sf_black_f: sps_hk416d_10_4_smr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_afg_sf_black_f: sps_hk416d_10_4_smr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_sf_black_f: sps_hk416d_10_4_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_sf_black_f: sps_hk416d_10_4_smr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_sf_black_f: sps_hk416d_10_4_smr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_hk_vfg_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_vfg_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_vfg_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_afg_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_afg_ral8000_f: sps_hk416d_10_4_smr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_afg_ral8000_f: sps_hk416d_10_4_smr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_ral8000_f: sps_hk416d_10_4_smr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_ral8000_f: sps_hk416d_10_4_smr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_hk_vfg_sf_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_vfg_sf_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_vfg_sf_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_afg_sf_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_afg_sf_ral8000_f: sps_hk416d_10_4_smr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_afg_sf_ral8000_f: sps_hk416d_10_4_smr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_sf_ral8000_f: sps_hk416d_10_4_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_sf_ral8000_f: sps_hk416d_10_4_smr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_sf_ral8000_f: sps_hk416d_10_4_smr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_hk_vfg_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_vfg_fde_f: sps_hk416d_10_4_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_vfg_fde_f: sps_hk416d_10_4_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_afg_fde_f: sps_hk416d_10_4_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_afg_fde_f: sps_hk416d_10_4_smr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_afg_fde_f: sps_hk416d_10_4_smr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_fde_f: sps_hk416d_10_4_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_fde_f: sps_hk416d_10_4_smr_hk_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_fde_f: sps_hk416d_10_4_smr_hk_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_hk_vfg_sf_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_vfg_sf_fde_f: sps_hk416d_10_4_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_vfg_sf_fde_f: sps_hk416d_10_4_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_afg_sf_fde_f: sps_hk416d_10_4_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 81.682428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_afg_sf_fde_f: sps_hk416d_10_4_smr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_afg_sf_fde_f: sps_hk416d_10_4_smr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_sf_fde_f: sps_hk416d_10_4_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 78.807428;
        };
    };
    class sps_hk416d_10_4_smr_hk_ctr_sf_fde_f: sps_hk416d_10_4_smr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_10_4_smr_t_ctr_sf_fde_f: sps_hk416d_10_4_smr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.06425;
        class WeaponSlotsInfo {
            mass = 75.932428;
        };
    };
    class sps_hk416d_16_5_smr_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_vfg_black_f: sps_hk416d_16_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_vfg_black_f: sps_hk416d_16_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_afg_black_f: sps_hk416d_16_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_afg_black_f: sps_hk416d_16_5_smr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_afg_black_f: sps_hk416d_16_5_smr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_black_f: sps_hk416d_16_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_black_f: sps_hk416d_16_5_smr_hk_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_black_f: sps_hk416d_16_5_smr_hk_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_hk_vfg_sf_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_vfg_sf_black_f: sps_hk416d_16_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_vfg_sf_black_f: sps_hk416d_16_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_afg_sf_black_f: sps_hk416d_16_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_afg_sf_black_f: sps_hk416d_16_5_smr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_afg_sf_black_f: sps_hk416d_16_5_smr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_sf_black_f: sps_hk416d_16_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_sf_black_f: sps_hk416d_16_5_smr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_sf_black_f: sps_hk416d_16_5_smr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_hk_vfg_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_vfg_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_vfg_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_afg_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_afg_ral8000_f: sps_hk416d_16_5_smr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_afg_ral8000_f: sps_hk416d_16_5_smr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_ral8000_f: sps_hk416d_16_5_smr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_ral8000_f: sps_hk416d_16_5_smr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_hk_vfg_sf_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_vfg_sf_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_vfg_sf_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_afg_sf_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_afg_sf_ral8000_f: sps_hk416d_16_5_smr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_afg_sf_ral8000_f: sps_hk416d_16_5_smr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_sf_ral8000_f: sps_hk416d_16_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_sf_ral8000_f: sps_hk416d_16_5_smr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_sf_ral8000_f: sps_hk416d_16_5_smr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_hk_vfg_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_vfg_fde_f: sps_hk416d_16_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_vfg_fde_f: sps_hk416d_16_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_afg_fde_f: sps_hk416d_16_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_afg_fde_f: sps_hk416d_16_5_smr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_afg_fde_f: sps_hk416d_16_5_smr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_fde_f: sps_hk416d_16_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_fde_f: sps_hk416d_16_5_smr_hk_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_fde_f: sps_hk416d_16_5_smr_hk_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_hk_vfg_sf_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_vfg_sf_fde_f: sps_hk416d_16_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_vfg_sf_fde_f: sps_hk416d_16_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_afg_sf_fde_f: sps_hk416d_16_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.583399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_afg_sf_fde_f: sps_hk416d_16_5_smr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_afg_sf_fde_f: sps_hk416d_16_5_smr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_sf_fde_f: sps_hk416d_16_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.708399;
        };
    };
    class sps_hk416d_16_5_smr_hk_ctr_sf_fde_f: sps_hk416d_16_5_smr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_16_5_smr_t_ctr_sf_fde_f: sps_hk416d_16_5_smr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 84.833399;
        };
    };
    class sps_hk416d_14_5_smr_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_vfg_black_f: sps_hk416d_14_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_vfg_black_f: sps_hk416d_14_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_afg_black_f: sps_hk416d_14_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_afg_black_f: sps_hk416d_14_5_smr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_afg_black_f: sps_hk416d_14_5_smr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_black_f: sps_hk416d_14_5_smr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_black_f: sps_hk416d_14_5_smr_hk_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_black_f: sps_hk416d_14_5_smr_hk_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_hk_vfg_sf_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_vfg_sf_black_f: sps_hk416d_14_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_vfg_sf_black_f: sps_hk416d_14_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_afg_sf_black_f: sps_hk416d_14_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_afg_sf_black_f: sps_hk416d_14_5_smr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_afg_sf_black_f: sps_hk416d_14_5_smr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_sf_black_f: sps_hk416d_14_5_smr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_sf_black_f: sps_hk416d_14_5_smr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_sf_black_f: sps_hk416d_14_5_smr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_hk_vfg_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_vfg_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_vfg_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_afg_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_afg_ral8000_f: sps_hk416d_14_5_smr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_afg_ral8000_f: sps_hk416d_14_5_smr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_ral8000_f: sps_hk416d_14_5_smr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_ral8000_f: sps_hk416d_14_5_smr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_hk_vfg_sf_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_vfg_sf_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_vfg_sf_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_afg_sf_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_afg_sf_ral8000_f: sps_hk416d_14_5_smr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_afg_sf_ral8000_f: sps_hk416d_14_5_smr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_sf_ral8000_f: sps_hk416d_14_5_smr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_sf_ral8000_f: sps_hk416d_14_5_smr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_sf_ral8000_f: sps_hk416d_14_5_smr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_hk_vfg_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_vfg_fde_f: sps_hk416d_14_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_vfg_fde_f: sps_hk416d_14_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_afg_fde_f: sps_hk416d_14_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_afg_fde_f: sps_hk416d_14_5_smr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_afg_fde_f: sps_hk416d_14_5_smr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_fde_f: sps_hk416d_14_5_smr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_fde_f: sps_hk416d_14_5_smr_hk_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_fde_f: sps_hk416d_14_5_smr_hk_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_hk_vfg_sf_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_vfg_sf_fde_f: sps_hk416d_14_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_vfg_sf_fde_f: sps_hk416d_14_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_afg_sf_fde_f: sps_hk416d_14_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.812398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_afg_sf_fde_f: sps_hk416d_14_5_smr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_afg_sf_fde_f: sps_hk416d_14_5_smr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_sf_fde_f: sps_hk416d_14_5_smr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.937398;
        };
    };
    class sps_hk416d_14_5_smr_hk_ctr_sf_fde_f: sps_hk416d_14_5_smr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_smr_t_ctr_sf_fde_f: sps_hk416d_14_5_smr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 83.062398;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_vfg_black_f: sps_hk416d_14_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_vfg_black_f: sps_hk416d_14_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_afg_black_f: sps_hk416d_14_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_afg_black_f: sps_hk416d_14_5_exsmr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_afg_black_f: sps_hk416d_14_5_exsmr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_black_f: sps_hk416d_14_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_black_f: sps_hk416d_14_5_exsmr_hk_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_black_f: sps_hk416d_14_5_exsmr_hk_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_vfg_sf_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_vfg_sf_black_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_vfg_sf_black_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_afg_sf_black_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_afg_sf_black_f: sps_hk416d_14_5_exsmr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_afg_sf_black_f: sps_hk416d_14_5_exsmr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_sf_black_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_sf_black_f: sps_hk416d_14_5_exsmr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_sf_black_f: sps_hk416d_14_5_exsmr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_vfg_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_vfg_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_vfg_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_afg_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_afg_ral8000_f: sps_hk416d_14_5_exsmr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_afg_ral8000_f: sps_hk416d_14_5_exsmr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_ral8000_f: sps_hk416d_14_5_exsmr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_ral8000_f: sps_hk416d_14_5_exsmr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_vfg_sf_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_vfg_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_vfg_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_afg_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_afg_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_afg_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_sf_ral8000_f: sps_hk416d_14_5_exsmr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_vfg_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_vfg_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_vfg_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_afg_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_afg_fde_f: sps_hk416d_14_5_exsmr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_afg_fde_f: sps_hk416d_14_5_exsmr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_fde_f: sps_hk416d_14_5_exsmr_hk_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_fde_f: sps_hk416d_14_5_exsmr_hk_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_vfg_sf_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_vfg_sf_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_vfg_sf_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_afg_sf_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.702313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_afg_sf_fde_f: sps_hk416d_14_5_exsmr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_afg_sf_fde_f: sps_hk416d_14_5_exsmr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_sf_fde_f: sps_hk416d_14_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.827313;
        };
    };
    class sps_hk416d_14_5_exsmr_hk_ctr_sf_fde_f: sps_hk416d_14_5_exsmr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_14_5_exsmr_t_ctr_sf_fde_f: sps_hk416d_14_5_exsmr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 85.952313;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_vfg_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_vfg_black_f: sps_hk416d_16_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_vfg_black_f: sps_hk416d_16_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_afg_black_f: sps_hk416d_16_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_afg_black_f: sps_hk416d_16_5_exsmr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_afg_black_f: sps_hk416d_16_5_exsmr_hk_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_black_f: sps_hk416d_16_5_exsmr_hk_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_black_f: sps_hk416d_16_5_exsmr_hk_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_black_f: sps_hk416d_16_5_exsmr_hk_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_vfg_sf_black_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_vfg_sf_black_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_vfg_sf_black_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_afg_sf_black_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_afg_sf_black_f: sps_hk416d_16_5_exsmr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_afg_sf_black_f: sps_hk416d_16_5_exsmr_hk_afg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_sf_black_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_sf_black_f: sps_hk416d_16_5_exsmr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_sf_black_f: sps_hk416d_16_5_exsmr_hk_sf_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_vfg_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_vfg_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_vfg_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_afg_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_afg_ral8000_f: sps_hk416d_16_5_exsmr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_afg_ral8000_f: sps_hk416d_16_5_exsmr_hk_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_ral8000_f: sps_hk416d_16_5_exsmr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_ral8000_f: sps_hk416d_16_5_exsmr_hk_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_vfg_sf_ral8000_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_vfg_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_vfg_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_afg_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_afg_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_afg_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_afg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_sf_ral8000_f: sps_hk416d_16_5_exsmr_hk_sf_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_vfg_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_vfg_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_vfg_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_afg_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_afg_fde_f: sps_hk416d_16_5_exsmr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_afg_fde_f: sps_hk416d_16_5_exsmr_hk_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_fde_f: sps_hk416d_16_5_exsmr_hk_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_fde_f: sps_hk416d_16_5_exsmr_hk_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_vfg_sf_fde_f: sps_m27_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_vfg_sf_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_vfg_sf_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_afg_sf_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.473314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_afg_sf_fde_f: sps_hk416d_16_5_exsmr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_afg_sf_fde_f: sps_hk416d_16_5_exsmr_hk_afg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_sf_fde_f: sps_hk416d_16_5_exsmr_hk_vfg_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.598314;
        };
    };
    class sps_hk416d_16_5_exsmr_hk_ctr_sf_fde_f: sps_hk416d_16_5_exsmr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class sps_hk416d_16_5_exsmr_t_ctr_sf_fde_f: sps_hk416d_16_5_exsmr_hk_sf_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 87.723314;
        };
    };
    class SPS_hk416_11_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_vfg_sf_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_sf_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_sf_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_sf_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_vfg_a7_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_a7_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_a7_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_a7_black_f: SPS_hk416_11_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_afg_sf_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_sf_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_sf_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_sf_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_afg_a7_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_a7_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_a7_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_a7_black_f: SPS_hk416_11_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_sf_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_sf_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_sf_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_sf_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_a7_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_a7_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_a7_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_a7_black_f: SPS_hk416_11_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_vfg_sf_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_sf_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_sf_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_sf_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_vfg_a7_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_a7_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_a7_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_a7_fde_f: SPS_hk416_11_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_afg_sf_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_sf_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_sf_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_sf_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_afg_a7_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_a7_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_a7_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_a7_fde_f: SPS_hk416_11_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_sf_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_sf_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_sf_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_sf_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_a7_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_a7_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_a7_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_a7_fde_f: SPS_hk416_11_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_vfg_sf_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_sf_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_sf_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_vfg_a7_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_vfg_a7_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_vfg_a7_ral8000_f: SPS_hk416_11_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_afg_sf_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_sf_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_sf_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_sf_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_afg_a7_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_afg_a7_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_hk_ctr_afg_a7_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_t_ctr_afg_a7_ral8000_f: SPS_hk416_11_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 81.810999;
        };
    };
    class SPS_hk416_11_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_sf_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_sf_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_sf_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_sf_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_a7_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_a7_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_hk_ctr_a7_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_t_ctr_a7_ral8000_f: SPS_hk416_11_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 78.935999;
        };
    };
    class SPS_hk416_11_sl_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_vfg_sf_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_sf_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_sf_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_sf_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_vfg_a7_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_a7_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_a7_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_a7_black_f: SPS_hk416_11_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_afg_sf_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_sf_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_sf_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_sf_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_afg_a7_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_a7_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_a7_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_a7_black_f: SPS_hk416_11_sl_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_sf_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_sf_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_sf_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_sf_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_a7_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_a7_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_a7_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_a7_black_f: SPS_hk416_11_sl_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_vfg_sf_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_sf_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_sf_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_sf_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_vfg_a7_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_a7_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_a7_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_a7_fde_f: SPS_hk416_11_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_afg_sf_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_sf_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_sf_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_sf_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_afg_a7_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_a7_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_a7_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_a7_fde_f: SPS_hk416_11_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_sf_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_sf_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_sf_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_sf_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_a7_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_a7_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_a7_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_a7_fde_f: SPS_hk416_11_sl_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_vfg_sf_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_sf_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_sf_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_vfg_a7_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_vfg_a7_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_vfg_a7_ral8000_f: SPS_hk416_11_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_afg_sf_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_sf_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_sf_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_sf_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_afg_a7_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_afg_a7_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_afg_a7_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_afg_a7_ral8000_f: SPS_hk416_11_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_sl_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_sf_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_sf_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_sf_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_sf_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_a7_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_a7_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_hk_ctr_a7_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_sl_t_ctr_a7_ral8000_f: SPS_hk416_11_sl_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_vfg_sf_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_sf_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_sf_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_sf_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_vfg_a7_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_a7_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_a7_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_a7_black_f: SPS_hk416_11_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_afg_sf_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_sf_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_sf_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_sf_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_afg_a7_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_a7_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_a7_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_a7_black_f: SPS_hk416_11_smr_afg_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_sf_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_sf_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_sf_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_sf_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_a7_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_a7_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_a7_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_a7_black_f: SPS_hk416_11_smr_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_vfg_sf_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_sf_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_sf_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_sf_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_vfg_a7_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_a7_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_a7_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_a7_fde_f: SPS_hk416_11_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_afg_sf_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_sf_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_sf_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_sf_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_afg_a7_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_a7_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_a7_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_a7_fde_f: SPS_hk416_11_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_sf_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_sf_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_sf_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_sf_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_a7_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_a7_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_a7_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_a7_fde_f: SPS_hk416_11_smr_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_vfg_sf_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_sf_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_sf_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_vfg_a7_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_vfg_a7_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_vfg_a7_ral8000_f: SPS_hk416_11_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_afg_sf_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_sf_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_sf_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_sf_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_afg_a7_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_afg_a7_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_afg_a7_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_afg_a7_ral8000_f: SPS_hk416_11_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 79.796823;
        };
    };
    class SPS_hk416_11_smr_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_sf_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_sf_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_sf_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_sf_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_a7_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_a7_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_hk_ctr_a7_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_11_smr_t_ctr_a7_ral8000_f: SPS_hk416_11_smr_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 76.921823;
        };
    };
    class SPS_hk416_20_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_vfg_sf_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_sf_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_sf_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_sf_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_vfg_a7_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_a7_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_a7_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_a7_black_f: SPS_hk416_20_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_afg_sf_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_sf_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_sf_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_sf_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_afg_a7_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_a7_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_a7_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_a7_black_f: SPS_hk416_20_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_sf_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_sf_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_sf_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_sf_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_a7_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_a7_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_a7_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_a7_black_f: SPS_hk416_20_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_vfg_sf_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_sf_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_sf_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_sf_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_vfg_a7_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_a7_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_a7_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_a7_fde_f: SPS_hk416_20_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_afg_sf_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_sf_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_sf_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_sf_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_afg_a7_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_a7_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_a7_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_a7_fde_f: SPS_hk416_20_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_sf_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_sf_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_sf_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_sf_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_a7_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_a7_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_a7_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_a7_fde_f: SPS_hk416_20_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_vfg_sf_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_sf_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_sf_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_vfg_a7_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_vfg_a7_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_vfg_a7_ral8000_f: SPS_hk416_20_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_afg_sf_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_sf_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_sf_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_sf_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_afg_a7_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_afg_a7_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_hk_ctr_afg_a7_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_t_ctr_afg_a7_ral8000_f: SPS_hk416_20_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 100.279997;
        };
    };
    class SPS_hk416_20_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_sf_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_sf_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_sf_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_sf_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_a7_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_a7_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_hk_ctr_a7_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_t_ctr_a7_ral8000_f: SPS_hk416_20_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.404997;
        };
    };
    class SPS_hk416_20_exsl_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_vfg_sf_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_sf_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_sf_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_sf_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_vfg_a7_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_a7_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_a7_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_a7_black_f: SPS_hk416_20_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_afg_sf_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_sf_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_sf_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_sf_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_afg_a7_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_a7_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_a7_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_a7_black_f: SPS_hk416_20_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_sf_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_sf_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_sf_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_sf_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_a7_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_a7_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_a7_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_a7_black_f: SPS_hk416_20_exsl_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_vfg_sf_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_sf_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_sf_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_sf_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_vfg_a7_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_a7_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_a7_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_a7_fde_f: SPS_hk416_20_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_afg_sf_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_sf_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_sf_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_sf_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_afg_a7_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_a7_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_a7_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_a7_fde_f: SPS_hk416_20_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_sf_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_sf_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_sf_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_sf_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_a7_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_a7_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_a7_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_a7_fde_f: SPS_hk416_20_exsl_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_vfg_sf_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_sf_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_sf_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_vfg_a7_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_vfg_a7_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_vfg_a7_ral8000_f: SPS_hk416_20_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_afg_sf_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_sf_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_sf_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_sf_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_afg_a7_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_afg_a7_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_afg_a7_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_afg_a7_ral8000_f: SPS_hk416_20_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.910216;
        };
    };
    class SPS_hk416_20_exsl_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_sf_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_sf_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_sf_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_sf_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_a7_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_a7_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_hk_ctr_a7_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_exsl_t_ctr_a7_ral8000_f: SPS_hk416_20_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.035216;
        };
    };
    class SPS_hk416_20_g95_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_vfg_sf_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_sf_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_sf_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_sf_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_vfg_a7_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_a7_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_a7_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_a7_black_f: SPS_hk416_20_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_afg_sf_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_sf_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_sf_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_sf_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_afg_a7_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_a7_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_a7_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_a7_black_f: SPS_hk416_20_g95_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_sf_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_sf_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_sf_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_sf_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_a7_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_a7_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_a7_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_a7_black_f: SPS_hk416_20_g95_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_vfg_sf_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_sf_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_sf_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_sf_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_vfg_a7_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_a7_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_a7_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_a7_fde_f: SPS_hk416_20_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_afg_sf_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_sf_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_sf_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_sf_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_afg_a7_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_a7_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_a7_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_a7_fde_f: SPS_hk416_20_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_sf_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_sf_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_sf_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_sf_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_a7_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_a7_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_a7_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_a7_fde_f: SPS_hk416_20_g95_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_vfg_sf_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_sf_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_sf_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_vfg_a7_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_vfg_a7_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_vfg_a7_ral8000_f: SPS_hk416_20_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_afg_sf_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_sf_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_sf_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_sf_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_afg_a7_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_afg_a7_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_afg_a7_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_afg_a7_ral8000_f: SPS_hk416_20_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 96.675937;
        };
    };
    class SPS_hk416_20_g95_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_sf_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_sf_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_sf_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_sf_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_a7_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_a7_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_hk_ctr_a7_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_g95_t_ctr_a7_ral8000_f: SPS_hk416_20_g95_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 93.800937;
        };
    };
    class SPS_hk416_20_exsmr_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_vfg_sf_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_sf_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_sf_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_sf_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_vfg_a7_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_a7_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_a7_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_a7_black_f: SPS_hk416_20_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_afg_sf_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_sf_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_sf_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_sf_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_afg_a7_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_a7_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_a7_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_a7_black_f: SPS_hk416_20_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_sf_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_sf_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_sf_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_sf_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_a7_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_a7_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_a7_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_a7_black_f: SPS_hk416_20_exsmr_black_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_vfg_sf_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_sf_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_sf_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_sf_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_vfg_a7_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_a7_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_a7_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_a7_fde_f: SPS_hk416_20_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_afg_sf_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_sf_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_sf_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_sf_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_afg_a7_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_a7_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_a7_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_a7_fde_f: SPS_hk416_20_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_sf_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_sf_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_sf_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_sf_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_a7_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_a7_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_a7_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_a7_fde_f: SPS_hk416_20_exsmr_fde_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_vfg_sf_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_sf_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_sf_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_vfg_a7_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_vfg_a7_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_vfg_a7_ral8000_f: SPS_hk416_20_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_afg_sf_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_sf_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_sf_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_sf_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_afg_a7_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_afg_a7_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_afg_a7_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_afg_a7_ral8000_f: SPS_hk416_20_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 97.004665;
        };
    };
    class SPS_hk416_20_exsmr_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_sf_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_sf_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_sf_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_sf_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_a7_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_a7_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_hk_ctr_a7_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_20_exsmr_t_ctr_a7_ral8000_f: SPS_hk416_20_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.622;
        class WeaponSlotsInfo {
            mass = 94.129665;
        };
    };
    class SPS_hk416_16_5_ex_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_vfg_sf_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_sf_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_vfg_a7_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_a7_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_ex_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_afg_sf_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_sf_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_sf_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_afg_a7_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_a7_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_a7_black_f: SPS_hk416_16_5_ex_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_sf_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_sf_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_sf_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_sf_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_a7_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_a7_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_a7_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_a7_black_f: SPS_hk416_16_5_ex_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_vfg_sf_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_sf_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_vfg_a7_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_a7_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_ex_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_afg_sf_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_sf_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_afg_a7_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_a7_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_ex_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_sf_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_sf_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_sf_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_sf_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_a7_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_a7_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_a7_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_a7_fde_f: SPS_hk416_16_5_ex_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_sf_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_vfg_a7_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_ex_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_afg_sf_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_sf_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_afg_a7_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_afg_a7_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_ex_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 97.583069;
        };
    };
    class SPS_hk416_16_5_ex_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_sf_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_sf_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_sf_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_a7_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_a7_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_ex_t_ctr_a7_ral8000_f: SPS_hk416_16_5_ex_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.708069;
        };
    };
    class SPS_hk416_16_5_exsl_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_vfg_sf_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_sf_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_vfg_a7_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_a7_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_exsl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_afg_sf_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_sf_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_sf_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_afg_a7_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_a7_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_a7_black_f: SPS_hk416_16_5_exsl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_sf_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_sf_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_sf_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_sf_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_a7_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_a7_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_a7_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_a7_black_f: SPS_hk416_16_5_exsl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_vfg_sf_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_sf_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_vfg_a7_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_a7_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_exsl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_afg_sf_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_sf_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_afg_a7_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_a7_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_exsl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_sf_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_sf_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_sf_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_sf_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_a7_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_a7_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_a7_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_a7_fde_f: SPS_hk416_16_5_exsl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_sf_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_vfg_a7_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_exsl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_afg_sf_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_sf_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_afg_a7_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_afg_a7_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_exsl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.213289;
        };
    };
    class SPS_hk416_16_5_exsl_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_sf_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_sf_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_sf_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_a7_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_a7_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_exsl_t_ctr_a7_ral8000_f: SPS_hk416_16_5_exsl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.338289;
        };
    };
    class SPS_hk416_16_5_g95_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_vfg_sf_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_sf_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_vfg_a7_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_a7_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_afg_sf_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_sf_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_sf_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_afg_a7_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_a7_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_a7_black_f: SPS_hk416_16_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_sf_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_sf_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_sf_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_sf_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_a7_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_a7_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_a7_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_a7_black_f: SPS_hk416_16_5_g95_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_vfg_sf_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_sf_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_vfg_a7_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_a7_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_afg_sf_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_sf_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_afg_a7_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_a7_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_sf_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_sf_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_sf_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_sf_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_a7_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_a7_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_a7_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_a7_fde_f: SPS_hk416_16_5_g95_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_sf_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_vfg_a7_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_afg_sf_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_sf_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_afg_a7_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_afg_a7_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 93.979011;
        };
    };
    class SPS_hk416_16_5_g95_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_sf_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_sf_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_sf_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_a7_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_a7_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_g95_t_ctr_a7_ral8000_f: SPS_hk416_16_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.104011;
        };
    };
    class SPS_hk416_16_5_exsmr_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_vfg_sf_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_sf_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_vfg_a7_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_a7_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_afg_sf_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_sf_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_sf_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_afg_a7_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_a7_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_a7_black_f: SPS_hk416_16_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_sf_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_sf_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_sf_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_sf_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_a7_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_a7_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_a7_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_a7_black_f: SPS_hk416_16_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_vfg_sf_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_sf_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_vfg_a7_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_a7_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_afg_sf_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_sf_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_afg_a7_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_a7_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_sf_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_sf_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_sf_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_sf_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_a7_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_a7_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_a7_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_a7_fde_f: SPS_hk416_16_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_sf_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_vfg_a7_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_afg_sf_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_sf_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_afg_a7_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_afg_a7_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 94.307729;
        };
    };
    class SPS_hk416_16_5_exsmr_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_sf_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_sf_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_sf_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_a7_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_a7_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_exsmr_t_ctr_a7_ral8000_f: SPS_hk416_16_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.432729;
        };
    };
    class SPS_hk416_16_5_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_vfg_sf_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_sf_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_vfg_a7_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_a7_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_afg_sf_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_sf_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_sf_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_afg_a7_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_a7_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_a7_black_f: SPS_hk416_16_5_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_sf_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_sf_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_sf_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_sf_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_a7_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_a7_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_a7_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_a7_black_f: SPS_hk416_16_5_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_vfg_sf_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_sf_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_vfg_a7_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_a7_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_afg_sf_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_sf_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_afg_a7_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_a7_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_sf_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_sf_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_sf_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_sf_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_a7_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_a7_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_a7_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_a7_fde_f: SPS_hk416_16_5_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_sf_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_vfg_a7_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_afg_sf_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_sf_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_afg_a7_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_afg_a7_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 92.943;
        };
    };
    class SPS_hk416_16_5_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_sf_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_sf_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_sf_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_a7_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_a7_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_t_ctr_a7_ral8000_f: SPS_hk416_16_5_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.068;
        };
    };
    class SPS_hk416_16_5_smr_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_vfg_sf_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_sf_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_vfg_a7_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_a7_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_afg_sf_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_sf_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_sf_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_afg_a7_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_a7_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_a7_black_f: SPS_hk416_16_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_sf_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_sf_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_sf_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_sf_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_a7_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_a7_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_a7_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_a7_black_f: SPS_hk416_16_5_smr_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_vfg_sf_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_sf_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_vfg_a7_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_a7_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_afg_sf_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_sf_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_afg_a7_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_a7_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_sf_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_sf_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_sf_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_sf_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_a7_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_a7_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_a7_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_a7_fde_f: SPS_hk416_16_5_smr_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_sf_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_vfg_a7_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_afg_sf_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_sf_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_afg_a7_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_afg_a7_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 91.417815;
        };
    };
    class SPS_hk416_16_5_smr_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_sf_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_sf_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_sf_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_a7_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_a7_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_smr_t_ctr_a7_ral8000_f: SPS_hk416_16_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.542815;
        };
    };
    class SPS_hk416_16_5_sl_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_vfg_sf_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_sf_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_sf_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_sf_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_vfg_a7_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_a7_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_a7_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_a7_black_f: SPS_hk416_16_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_afg_sf_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_sf_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_sf_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_sf_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_afg_a7_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_a7_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_a7_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_a7_black_f: SPS_hk416_16_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_sf_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_sf_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_sf_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_sf_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_a7_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_a7_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_a7_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_a7_black_f: SPS_hk416_16_5_sl_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_vfg_sf_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_sf_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_sf_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_sf_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_vfg_a7_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_a7_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_a7_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_a7_fde_f: SPS_hk416_16_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_afg_sf_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_sf_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_sf_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_sf_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_afg_a7_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_a7_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_a7_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_a7_fde_f: SPS_hk416_16_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_sf_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_sf_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_sf_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_sf_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_a7_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_a7_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_a7_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_a7_fde_f: SPS_hk416_16_5_sl_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_vfg_sf_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_sf_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_sf_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_vfg_a7_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_vfg_a7_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_vfg_a7_ral8000_f: SPS_hk416_16_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_afg_sf_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_sf_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_sf_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_afg_a7_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_afg_a7_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_afg_a7_ral8000_f: SPS_hk416_16_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 90.928815;
        };
    };
    class SPS_hk416_16_5_sl_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_sf_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_sf_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_sf_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_a7_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_a7_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_16_5_sl_t_ctr_a7_ral8000_f: SPS_hk416_16_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 88.053815;
        };
    };
    class SPS_hk416_14_5_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_vfg_sf_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_sf_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_sf_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_sf_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_vfg_a7_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_a7_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_a7_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_a7_black_f: SPS_hk416_14_5_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_afg_sf_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_sf_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_sf_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_sf_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_afg_a7_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_a7_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_a7_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_a7_black_f: SPS_hk416_14_5_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_sf_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_sf_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_sf_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_sf_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_a7_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_a7_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_a7_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_a7_black_f: SPS_hk416_14_5_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_vfg_sf_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_sf_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_sf_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_sf_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_vfg_a7_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_a7_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_a7_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_a7_fde_f: SPS_hk416_14_5_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_afg_sf_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_sf_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_sf_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_sf_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_afg_a7_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_a7_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_a7_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_a7_fde_f: SPS_hk416_14_5_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_sf_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_sf_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_sf_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_sf_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_a7_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_a7_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_a7_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_a7_fde_f: SPS_hk416_14_5_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_vfg_sf_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_sf_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_vfg_a7_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_vfg_a7_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_afg_sf_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_sf_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_afg_a7_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_afg_a7_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_t_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 91.171999;
        };
    };
    class SPS_hk416_14_5_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_sf_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_sf_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_sf_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_sf_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_a7_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_a7_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_hk_ctr_a7_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_t_ctr_a7_ral8000_f: SPS_hk416_14_5_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 88.296999;
        };
    };
    class SPS_hk416_14_5_sl_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_vfg_sf_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_sf_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_sf_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_sf_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_vfg_a7_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_a7_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_a7_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_a7_black_f: SPS_hk416_14_5_sl_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_afg_sf_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_sf_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_sf_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_sf_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_afg_a7_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_a7_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_a7_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_a7_black_f: SPS_hk416_14_5_sl_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_sf_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_sf_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_sf_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_sf_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_a7_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_a7_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_a7_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_a7_black_f: SPS_hk416_14_5_sl_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_vfg_sf_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_sf_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_sf_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_sf_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_vfg_a7_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_a7_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_a7_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_a7_fde_f: SPS_hk416_14_5_sl_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_afg_sf_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_sf_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_sf_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_sf_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_afg_a7_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_a7_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_a7_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_a7_fde_f: SPS_hk416_14_5_sl_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_sf_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_sf_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_sf_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_sf_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_a7_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_a7_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_a7_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_a7_fde_f: SPS_hk416_14_5_sl_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_vfg_sf_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_sf_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_vfg_a7_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_vfg_a7_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_sl_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_afg_sf_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_sf_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_afg_a7_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_afg_a7_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_sl_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.157823;
        };
    };
    class SPS_hk416_14_5_sl_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_sf_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_sf_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_sf_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_sf_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_a7_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_a7_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_hk_ctr_a7_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_sl_t_ctr_a7_ral8000_f: SPS_hk416_14_5_sl_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.282823;
        };
    };
    class SPS_hk416_14_5_smr_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_vfg_sf_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_sf_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_sf_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_sf_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_vfg_a7_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_a7_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_a7_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_a7_black_f: SPS_hk416_14_5_smr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_afg_sf_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_sf_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_sf_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_sf_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_afg_a7_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_a7_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_a7_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_a7_black_f: SPS_hk416_14_5_smr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_sf_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_sf_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_sf_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_sf_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_a7_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_a7_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_a7_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_a7_black_f: SPS_hk416_14_5_smr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_vfg_sf_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_sf_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_sf_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_sf_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_vfg_a7_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_a7_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_a7_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_a7_fde_f: SPS_hk416_14_5_smr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_afg_sf_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_sf_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_sf_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_sf_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_afg_a7_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_a7_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_a7_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_a7_fde_f: SPS_hk416_14_5_smr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_sf_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_sf_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_sf_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_sf_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_a7_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_a7_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_a7_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_a7_fde_f: SPS_hk416_14_5_smr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_vfg_sf_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_sf_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_vfg_a7_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_vfg_a7_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_smr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_afg_sf_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_sf_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_afg_a7_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_afg_a7_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_smr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.646814;
        };
    };
    class SPS_hk416_14_5_smr_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_sf_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_sf_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_sf_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_sf_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_a7_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_a7_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_hk_ctr_a7_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_smr_t_ctr_a7_ral8000_f: SPS_hk416_14_5_smr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 86.771814;
        };
    };
    class SPS_hk416_14_5_exsmr_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_vfg_sf_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_sf_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_sf_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_sf_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_vfg_a7_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_a7_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_a7_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_a7_black_f: SPS_hk416_14_5_exsmr_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_afg_sf_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_sf_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_sf_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_sf_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_afg_a7_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_a7_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_a7_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_a7_black_f: SPS_hk416_14_5_exsmr_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_sf_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_sf_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_sf_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_sf_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_a7_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_a7_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_a7_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_a7_black_f: SPS_hk416_14_5_exsmr_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_vfg_sf_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_sf_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_sf_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_sf_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_vfg_a7_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_a7_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_a7_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_a7_fde_f: SPS_hk416_14_5_exsmr_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_afg_sf_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_sf_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_sf_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_sf_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_afg_a7_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_a7_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_a7_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_a7_fde_f: SPS_hk416_14_5_exsmr_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_sf_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_sf_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_sf_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_sf_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_a7_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_a7_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_a7_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_a7_fde_f: SPS_hk416_14_5_exsmr_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_vfg_sf_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_sf_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_vfg_a7_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_vfg_a7_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_exsmr_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_afg_sf_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_sf_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_afg_a7_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_afg_a7_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_exsmr_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.536729;
        };
    };
    class SPS_hk416_14_5_exsmr_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_sf_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_sf_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_sf_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_sf_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_a7_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_a7_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_hk_ctr_a7_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_exsmr_t_ctr_a7_ral8000_f: SPS_hk416_14_5_exsmr_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.661729;
        };
    };
    class SPS_hk416_14_5_g95_vfg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_vfg_sf_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_sf_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_sf_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_sf_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_vfg_a7_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_a7_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_a7_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_a7_black_f: SPS_hk416_14_5_g95_vfg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_afg_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_afg_sf_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_sf_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_sf_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_sf_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_afg_a7_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_a7_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_a7_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_a7_black_f: SPS_hk416_14_5_g95_afg_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_sf_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_sf_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_sf_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_sf_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_a7_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_a7_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_a7_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_a7_black_f: SPS_hk416_14_5_g95_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_vfg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_vfg_sf_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_sf_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_sf_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_sf_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_vfg_a7_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_a7_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_a7_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_a7_fde_f: SPS_hk416_14_5_g95_vfg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_afg_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_afg_sf_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_sf_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_sf_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_sf_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_afg_a7_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_a7_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_a7_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_a7_fde_f: SPS_hk416_14_5_g95_afg_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_sf_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_sf_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_sf_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_sf_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_a7_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_a7_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_a7_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_a7_fde_f: SPS_hk416_14_5_g95_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_vfg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_vfg_sf_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_sf_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_sf_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_vfg_a7_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_vfg_a7_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_vfg_a7_ral8000_f: SPS_hk416_14_5_g95_vfg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_afg_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_afg_sf_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_sf_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_sf_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_afg_a7_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_afg_a7_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_afg_a7_ral8000_f: SPS_hk416_14_5_g95_afg_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 92.20801;
        };
    };
    class SPS_hk416_14_5_g95_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_sf_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_sf_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_sf_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_sf_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_a7_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_a7_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_hk_ctr_a7_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_14_5_g95_t_ctr_a7_ral8000_f: SPS_hk416_14_5_g95_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 89.33301;
        };
    };
    class SPS_hk416_11_glm_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_sf_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_sf_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_sf_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_sf_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_a7_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_a7_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_a7_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_a7_black_f: SPS_hk416_11_glm_black_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_sf_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_sf_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_sf_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_sf_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_a7_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_a7_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_a7_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_a7_fde_f: SPS_hk416_11_glm_fde_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_sf_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_sf_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_sf_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_sf_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_a7_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_a7_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_hk_ctr_a7_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_11_glm_t_ctr_a7_ral8000_f: SPS_hk416_11_glm_ral8000_f {
        ace_overheating_barrelMass = 2.0999;
        class WeaponSlotsInfo {
            mass = 102.510999;
        };
    };
    class SPS_hk416_14_5_glm_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_sf_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_sf_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_sf_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_sf_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_a7_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_a7_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_a7_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_a7_black_f: SPS_hk416_14_5_glm_black_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_sf_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_sf_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_sf_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_sf_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_a7_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_a7_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_a7_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_a7_fde_f: SPS_hk416_14_5_glm_fde_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_sf_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_sf_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_sf_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_sf_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_a7_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_a7_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_hk_ctr_a7_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_14_5_glm_t_ctr_a7_ral8000_f: SPS_hk416_14_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.30345;
        class WeaponSlotsInfo {
            mass = 111.871999;
        };
    };
    class SPS_hk416_16_5_glm_black_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_sf_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_sf_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_sf_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_sf_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_a7_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_a7_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_a7_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_a7_black_f: SPS_hk416_16_5_glm_black_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_fde_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_sf_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_sf_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_sf_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_sf_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_a7_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_a7_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_a7_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_a7_fde_f: SPS_hk416_16_5_glm_fde_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_ral8000_f: SPS_hk416_base_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_sf_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_sf_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_sf_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_sf_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_a7_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_a7_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_hk_ctr_a7_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };
    class SPS_hk416_16_5_glm_t_ctr_a7_ral8000_f: SPS_hk416_16_5_glm_ral8000_f {
        ace_overheating_barrelMass = 2.4196;
        class WeaponSlotsInfo {
            mass = 113.643;
        };
    };

    // ===== HK417 (7.62x51)  |  barrelMass x1.24, weight x1.24, dispersion x1.1 =====
    class SPS_hk417_base_f: EBR_base_F {
        ACE_Overheating_Dispersion[] = {0, 0.00088, 0.00132, 0.00264};
    };
    class SPS_hk417_13_vfg_black_f: SPS_hk417_base_f {
        ace_overheating_barrelMass = 3.10868;
        class WeaponSlotsInfo {
            mass = 115.32;
        };
    };
    class SPS_hk417_16_vfg_black_f: SPS_hk417_base_f {
        ace_overheating_barrelMass = 3.288976;
        class WeaponSlotsInfo {
            mass = 120.28;
        };
    };
    class SPS_hk417_20_vfg_black_f: SPS_hk417_base_f {
        ace_overheating_barrelMass = 3.467536;
        class WeaponSlotsInfo {
            mass = 128.96;
        };
    };
    class SPS_hk417_13_glm_black_f: SPS_hk417_base_f {
        ace_overheating_barrelMass = 3.10868;
        class WeaponSlotsInfo {
            mass = 140.12;
        };
    };
    class SPS_hk417_16_glm_black_f: SPS_hk417_base_f {
        ace_overheating_barrelMass = 3.288976;
        class WeaponSlotsInfo {
            mass = 145.08;
        };
    };

    // ===== KAC LAMG (5.56x45)  |  barrelMass x1.15, weight x1.15, dispersion x1.1 =====
    class SPS_KAC_LAMG_black_F: LMG_Mk200_F {
        ACE_Overheating_Dispersion[] = {0, 0.00088, 0.00132, 0.00264};
        ace_overheating_barrelMass = 2.86304;
        class WeaponSlotsInfo {
            mass = 104.65;
        };
    };
    class SPS_KAC_LAMG_NHG_black_F: SPS_KAC_LAMG_black_F {
        ace_overheating_barrelMass = 2.86304;
        class WeaponSlotsInfo {
            mass = 104.65;
        };
    };

    // ===== KAC LWAMG (7.62x51)  |  barrelMass x1.24, weight x1.24, dispersion x1.1 =====
    class SPS_KAC_LWAMG_Tan_F: MMG_01_base_F {
        ACE_Overheating_Dispersion[] = {0, 0.00088, 0.00132, 0.00264};
        ace_overheating_barrelMass = 4.13168;
        class WeaponSlotsInfo {
            mass = 172.36;
        };
    };
};
