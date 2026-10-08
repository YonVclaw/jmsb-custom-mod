// Vanilla vehicle missile weapons don't use CBA magazine wells — the magazine
// list lives directly on the CfgWeapons turret weapon class, so every append
// below is `+=`, never `=` (same shared-class rule as the mediumcaliber
// autocannon patches). Pylon* magazines are NOT appended here: the dynamic
// loadout system pairs them with their pylonWeapon via hardpoints[].
// Each weapon is reopened WITH its real parent named (parents forward-declared).
// A parentless reopen (`class missiles_titan { ... };`) makes HEMTT emit the
// class with no base; with undefined load order against other mods that also
// touch these launchers, the parentless one can win the bind and strip the
// vanilla parent link, collapsing the weapon to an empty stub — which is why the
// appended missiles can silently fail to appear. Vanilla parents: missiles_titan:
// MissileLauncher, missiles_titan_AA:missiles_titan, missiles_SCALPEL/DAGR/
// rockets_Skyfire:RocketPods, Missile_AGM_02_Plane_CAS_01_F:MissileLauncher.
class CfgWeapons {
    class MissileLauncher;
    class RocketPods;

    // Ground Titan tubes (Kamysh / Gorgon / Nyx AT / static)
    class missiles_titan: MissileLauncher {
        magazines[] += {
            "FA_2Rnd_BGM185_Broadsword",
            "FA_4Rnd_BGM185_Broadsword",
            "FA_2Rnd_XM1200_Copperhead",
            "FA_4Rnd_MIM165_Sentry",
            "FA_4Rnd_MIM166_Roadrunner"
        };
    };
    // Static Titan launcher (1-tube). Overrides magazines[] with the 1Rnd bodies,
    // so a parentless merge feeds it our count=1 FA variants (same per-tube
    // granularity as the VVE Titan rack).
    class missiles_titan_static: missiles_titan {
        magazines[] += {
            "FA_1Rnd_BGM185_Broadsword",
            "FA_1Rnd_XM1200_Copperhead",
            "FA_1Rnd_MIM165_Sentry",
            "FA_1Rnd_MIM166_Roadrunner"
        };
    };
    // AA Titan tubes (Cheetah / Tigris — community classname guide lists this
    // as a separate weapon; if a given A3 build keeps everything on
    // missiles_titan above, this class is inert and the mags still flow)
    class missiles_titan_AA: missiles_titan {
        magazines[] += {
            "FA_4Rnd_MIM165_Sentry",
            "FA_4Rnd_MIM166_Roadrunner"
        };
    };
    // Scalpel rails (Kajman / Blackfoot)
    class missiles_SCALPEL: RocketPods {
        magazines[] += {
            "FA_8Rnd_AGM190_Wraith"
        };
    };
    // DAGR pods (Pawnee / Orca / Blackfoot)
    class missiles_DAGR: RocketPods {
        magazines[] += {
            "FA_12Rnd_AGR40_HydraP",
            "FA_24Rnd_AGR40_HydraP"
        };
    };
    // Skyfire pods (Kajman) — Hydra-P is the guided retrofit of the rocket pod
    class rockets_Skyfire: RocketPods {
        magazines[] += {
            "FA_12Rnd_AGR40_HydraP",
            "FA_24Rnd_AGR40_HydraP"
        };
    };
    // Macer launcher (Wipeout / Neophron CAS)
    class Missile_AGM_02_Plane_CAS_01_F: MissileLauncher {
        magazines[] += {
            "FA_2Rnd_AGM205_Warhammer"
        };
    };

    // -------------------------------------------------------------------
    // Man-portable Titan MPRL. Reopen the two base launchers with NO parent:
    // their CfgWeapons definition isn't in the available a3 dump, so naming a
    // parent risks reparenting them to the wrong base (which strips the launcher
    // and drops all its rounds). A bodied, parentless reopen MERGES into the
    // existing launcher instead - it keeps the real parent/optic and just adds
    // our magazines (the mediumcaliber autocannon_30mm pattern). Faction/camo
    // variants inherit these two bases and don't override magazines[], so the
    // rounds flow to them. AT -> full MPRL, AA -> the short (AA) MPRL.
    // -------------------------------------------------------------------
    // Man-portable Titan MPRL: the FA missiles are added ADDITIVELY via the vanilla
    // magazineWells Titan_Short (AT launcher + the rest) and Titan_Long (AA launcher)
    // in CfgMagazinewells.hpp - no launcher reopen, and vehicle tubes untouched.
};
