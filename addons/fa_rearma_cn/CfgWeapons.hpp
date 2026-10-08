// Weapon patches and the FA disposable-launcher variants. A single-use tube
// can't take a different round, so each FA round gets its own launcher:
// a _Loaded class holding the round, the arsenal class CBA shows until it
// is fired, and rearma's own _Used tube (CBA_DisposableLaunchers.hpp).
class CfgWeapons {
    class launch_RPG32_F;
    // The PF-89A is built on the vanilla RPG-32 and sets no magazineWell, so it
    // inherited the "RPG32" well and listed every RPG-32 rocket (vanilla and FA)
    // as loadable into a single-use tube. Clear it; the WPF-89 inherits the fix.
    class launch_PF89_Loaded: launch_RPG32_F {
        // CBA's disposable launchers want the loaded tube to weigh what the used
        // tube does, with the rocket making up the arsenal weight. rearma gives
        // it 50 against a 20 used tube, so a carried PF-89 weighed 50 + 30 = 80
        // against the arsenal's 50 and CBA warned at every start. 20 + 30 = 50.
        // The WPF-89 inherits it. Parentless, as rearma writes it.
        class WeaponSlotsInfo {
            mass = 20;
        };
        magazineWell[] = {};
    };
    class launch_WPF89_Loaded: launch_PF89_Loaded {
        class WeaponSlotsInfo;
    };

    // ===== PF-89A 80mm - PF-89C TNDM =====
    class FA_rearma_launch_PF89C_TNDM_Loaded: launch_PF89_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] PF-89C TNDM";
        descriptionShort = "80mm PF-89C TNDM (2040)<br/>Tandem HEAT - ~675 mm RHA, 300 m";
        baseWeapon = "FA_rearma_launch_PF89C_TNDM";
        magazines[] = {"FA_rearma_PF89C_TNDM"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_PF89C_TNDM: FA_rearma_launch_PF89C_TNDM_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_PF89C_TNDM";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 50;
        };
    };

    // ===== PF-89A 80mm - PF-89K PROX =====
    class FA_rearma_launch_PF89K_PROX_Loaded: launch_PF89_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] PF-89K PROX";
        descriptionShort = "80mm PF-89K PROX (2040)<br/>C-UAS proximity airburst - scripted fuze, 250 m";
        baseWeapon = "FA_rearma_launch_PF89K_PROX";
        magazines[] = {"FA_rearma_PF89K_PROX"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_PF89K_PROX: FA_rearma_launch_PF89K_PROX_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_PF89K_PROX";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 50;
        };
    };

    // ===== WPF-89 80mm - WPF-89C TBX =====
    class FA_rearma_launch_WPF89C_TBX_Loaded: launch_WPF89_Loaded {
        author = QAUTHOR;
        displayName = "[JMSB] WPF-89C TBX";
        descriptionShort = "80mm WPF-89C TBX (2040)<br/>Thermobaric, anti-structure / anti-personnel - 300 m";
        baseWeapon = "FA_rearma_launch_WPF89C_TBX";
        magazines[] = {"FA_rearma_WPF89C_TBX"};
        magazineWell[] = {};
    };
    class FA_rearma_launch_WPF89C_TBX: FA_rearma_launch_WPF89C_TBX_Loaded {
        scope = 2;
        scopeArsenal = 2;
        baseWeapon = "FA_rearma_launch_WPF89C_TBX";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 65;
        };
    };
};
