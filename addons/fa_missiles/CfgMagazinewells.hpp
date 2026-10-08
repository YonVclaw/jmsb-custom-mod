// Man-portable Titan MPRL wiring — ADDITIVE via the vanilla magazineWells
// defined in A3_Weapons_F (Titan_Short / Titan_Long). ADDON[] += only, so the
// BI mags (Titan_AT / Titan_AP) stay and our FA rounds are added alongside.
// Vehicle turret Titan tubes are wired separately (CfgWeapons) and untouched.
class CfgMagazineWells {
    // AT MPRL (and the rest of the man-portable Titan launchers)
    class Titan_Short {
        ADDON[] += {
            "FA_Titan_AT_BGM185_Broadsword",
            "FA_Titan_AT_XM1200_Copperhead"
        };
    };
    // AA MPRL (short / compact launcher)
    class Titan_Long {
        ADDON[] += {
            "FA_Titan_AA_MIM165_Sentry",
            "FA_Titan_AA_MIM166_Roadrunner"
        };
    };
};
