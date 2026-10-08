// Weapon patches and the FA disposable-launcher variants. A single-use tube
// can't take a different round, so each FA round gets its own launcher:
// a _Loaded class holding the round, the arsenal class CBA shows until it
// is fired, and rearma's own _Used tube (CBA_DisposableLaunchers.hpp).
class CfgWeapons {
    class Launcher_Base_F;
    class launch_RPG26_Loaded: Launcher_Base_F {
        class WeaponSlotsInfo;
    };
    class launch_RShG2_Loaded: Launcher_Base_F {
        class WeaponSlotsInfo;
    };

    // ===== RPG-26 72.5mm - RPG-26M2 TNDM =====
    class FA_rearma_launch_RPG26M2_TNDM_Loaded: launch_RPG26_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] RPG-26M2 TNDM";
        descriptionShort = "72.5mm RPG-26M2 TNDM (2040)<br/>Tandem HEAT - ~600 mm RHA, 250 m";
        baseWeapon = "FA_rearma_launch_RPG26M2_TNDM";
        magazines[] = {"FA_rearma_RPG26M2_TNDM"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_RPG26M2_TNDM: FA_rearma_launch_RPG26M2_TNDM_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_RPG26M2_TNDM";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 64;
        };
    };

    // ===== RPG-26 72.5mm - RPG-26 AB PROX =====
    class FA_rearma_launch_RPG26_AB26_Loaded: launch_RPG26_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] RPG-26 AB PROX";
        descriptionShort = "72.5mm AB-26 PROX (2040)<br/>C-UAS proximity airburst - scripted fuze, 200 m";
        baseWeapon = "FA_rearma_launch_RPG26_AB26";
        magazines[] = {"FA_rearma_RPG26_AB26"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_RPG26_AB26: FA_rearma_launch_RPG26_AB26_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_RPG26_AB26";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 64;
        };
    };

    // ===== RShG-2 72.5mm - RShG-2M2 TBX =====
    class FA_rearma_launch_RShG2M2_TBX_Loaded: launch_RShG2_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] RShG-2M2 TBX";
        descriptionShort = "72.5mm RShG-2M2 TBX (2040)<br/>Thermobaric, anti-structure / anti-personnel - 250 m";
        baseWeapon = "FA_rearma_launch_RShG2M2_TBX";
        magazines[] = {"FA_rearma_RShG2M2_TBX"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_RShG2M2_TBX: FA_rearma_launch_RShG2M2_TBX_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_RShG2M2_TBX";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 88.2;
        };
    };
};
