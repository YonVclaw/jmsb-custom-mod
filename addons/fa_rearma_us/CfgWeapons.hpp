// Weapon patches and the FA disposable-launcher variants. A single-use tube
// can't take a different round, so each FA round gets its own launcher:
// a _Loaded class holding the round, the arsenal class CBA shows until it
// is fired, and rearma's own _Used tube (CBA_DisposableLaunchers.hpp).
class CfgWeapons {
    class Launcher_Base_F;
    class launch_M72_Loaded: Launcher_Base_F {
        class WeaponSlotsInfo;
    };
    class MMG_02_base_F;
    class LMG_Mk200_F;
    class arifle_SPAR_03_base_F;

    // The M250 and KAC AMG set no magazineWell, and neither do their vanilla
    // parents (SPMG, Mk200), so FA belts had no well to join. Give each its own.
    // Their stock rearma belts still load through magazines[].
    class M250_F: MMG_02_base_F {
        magazineWell[] = {"FA_rearma_M250_680x51"};
    };
    class KAC_AMG_F: LMG_Mk200_F {
        magazineWell[] = {"FA_rearma_KACAMG_6x38"};
    };
    // The M28A5 sets no magazineWell and the vanilla SPAR-17 it inherits has
    // none either. M14_762x51 is the vanilla 20Rnd 7.62x51 well, which FA's
    // 7.62 20Rnd mags already join; rearma's own TVCM mags stay in magazines[].
    class M28A5_base_F: arifle_SPAR_03_base_F {
        magazineWell[] = {"M14_762x51"};
    };

    // ===== M72A7 66mm - M72A10 TNDM =====
    class FA_rearma_launch_M72A10_TNDM_Loaded: launch_M72_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] M72A10 TNDM";
        descriptionShort = "66mm M72A10 TNDM (2040)<br/>Tandem HEAT - ~350 mm RHA, 300 m";
        baseWeapon = "FA_rearma_launch_M72A10_TNDM";
        magazines[] = {"FA_rearma_M72A10_TNDM"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_M72A10_TNDM: FA_rearma_launch_M72A10_TNDM_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_M72A10_TNDM";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 67;
        };
    };

    // ===== M72A7 66mm - M72A11 TBX =====
    class FA_rearma_launch_M72A11_TBX_Loaded: launch_M72_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] M72A11 TBX";
        descriptionShort = "66mm M72A11 TBX (2040)<br/>Thermobaric, room / bunker clearing - 250 m";
        baseWeapon = "FA_rearma_launch_M72A11_TBX";
        magazines[] = {"FA_rearma_M72A11_TBX"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_M72A11_TBX: FA_rearma_launch_M72A11_TBX_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_M72A11_TBX";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 67;
        };
    };

    // ===== M72A7 66mm - M72A12 PROX =====
    class FA_rearma_launch_M72A12_PROX_Loaded: launch_M72_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] M72A12 PROX";
        descriptionShort = "66mm M72A12 PROX (2040)<br/>C-UAS proximity airburst - scripted fuze, 200 m";
        baseWeapon = "FA_rearma_launch_M72A12_PROX";
        magazines[] = {"FA_rearma_M72A12_PROX"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_M72A12_PROX: FA_rearma_launch_M72A12_PROX_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_M72A12_PROX";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 67;
        };
    };
};
