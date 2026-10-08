// Mk6 82mm mortar — TURRET LOADOUT (what the mortar spawns carrying).
//
// This is a different lever from CfgWeapons.hpp. There, mortar_82mm's magazines[]
// is the COMPATIBILITY list (which shells the tube will accept at all); here,
// Mortar_01_base_F >> Turrets >> MainTurret >> magazines[] is the LOADOUT (which
// shells are actually in the mortar when it is placed). Both are needed: without
// the weapon entry the round cannot be fired, without the turret entry nobody has
// any unless they rearm.
//
// Vanilla base loadout (per derapified static_f.pbo, Mortar_01\config.bin) is
// 4x 8Rnd_82mm_Mo_shells + flare + illum + smoke, and none of the six side
// variants override it — so a += on any one variant inherits those seven and
// appends to them.
//
// The FA 82mm shells are placed PER SIDE rather than on Mortar_01_base_F itself.
// The _B/_O/_I magazines sit on identical vanilla bodies and differ only in
// national displayName, so putting all 19 on the shared base would give every
// mortar three near-identical copies of each shell type. Class chain and turret
// reopen idiom follow ACE (addons/mk6mortar/CfgVehicles.hpp).
//
// Guerrilla variants: B_G_Mortar_01_F and O_G_Mortar_01_F inherit from
// I_G_Mortar_01_F (not from their same-side regulars), so all three G mortars ride
// the _I set added to I_G_Mortar_01_F. Overriding that would need a hard
// magazines[] = on B_G/O_G, restating the vanilla seven — not worth stomping the
// loadout for a reskin.
class CfgVehicles {
    class All {};
    class AllVehicles: All {};
    class Land: AllVehicles {};
    class LandVehicle: Land {};
    class StaticWeapon: LandVehicle {
        class Turrets {
            class MainTurret;
        };
    };
    class StaticMortar: StaticWeapon {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };
    class Mortar_01_base_F: StaticMortar {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };

    // NATO — the only side with the IR illum round (no _O/_I body exists)
    class B_Mortar_01_F: Mortar_01_base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] += {
                    "FA_8Rnd_82mm_heer_B",
                    "FA_8Rnd_82mm_apmi_B",
                    "FA_8Rnd_82mm_lgm_B",
                    "FA_8Rnd_82mm_strix_B",
                    "FA_8Rnd_82mm_smk_B",
                    "FA_8Rnd_82mm_tb_B",
                    "FA_8Rnd_82mm_ir_B"
                };
            };
        };
    };

    // CSAT
    class O_Mortar_01_F: Mortar_01_base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] += {
                    "FA_8Rnd_82mm_heer_O",
                    "FA_8Rnd_82mm_apmi_O",
                    "FA_8Rnd_82mm_lgm_O",
                    "FA_8Rnd_82mm_strix_O",
                    "FA_8Rnd_82mm_smk_O",
                    "FA_8Rnd_82mm_tb_O"
                };
            };
        };
    };

    // AAF
    class I_Mortar_01_F: Mortar_01_base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] += {
                    "FA_8Rnd_82mm_heer_I",
                    "FA_8Rnd_82mm_apmi_I",
                    "FA_8Rnd_82mm_lgm_I",
                    "FA_8Rnd_82mm_strix_I",
                    "FA_8Rnd_82mm_smk_I",
                    "FA_8Rnd_82mm_tb_I"
                };
            };
        };
    };

    // Guerrilla — B_G / O_G inherit this one, so all three G mortars get the _I set
    class I_G_Mortar_01_F: Mortar_01_base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] += {
                    "FA_8Rnd_82mm_heer_I",
                    "FA_8Rnd_82mm_apmi_I",
                    "FA_8Rnd_82mm_lgm_I",
                    "FA_8Rnd_82mm_strix_I",
                    "FA_8Rnd_82mm_smk_I",
                    "FA_8Rnd_82mm_tb_I"
                };
            };
        };
    };
};
