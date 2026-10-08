// Vehicle turret weapons don't use CBA magazine wells in vanilla Arma 3 — the
// magazine list lives directly on the CfgWeapons turret weapon class. These
// classes are shared across NATO/AAF/CSAT vehicles, so every append below is
// `+=`, never `=` (the exact repo-wide bug fixed earlier for infantry magwells
// applies here too — a plain `=` would let whichever addon's PBO merges last
// wipe out every other addon's magazines on these shared weapons).
#define FA_MAGS_30MM \
    "FA_60Rnd_30mm_APFSDS", \
    "FA_60Rnd_30mm_APFSDS_Red", \
    "FA_60Rnd_30mm_APFSDS_T_Red", \
    "FA_60Rnd_30mm_APFSDS_T_Yellow", \
    "FA_60Rnd_30mm_APFSDS_T_Green", \
    "FA_60Rnd_30mm_APFSDS_T_White", \
    "FA_60Rnd_30mm_APFSDS_T_Blue", \
    "FA_60Rnd_30mm_APFSDS_T_Orange", \
    "FA_60Rnd_30mm_APFSDS_T_IR", \
    "FA_140Rnd_30mm_API", \
    "FA_140Rnd_30mm_API_T_Red", \
    "FA_140Rnd_30mm_API_T_Yellow", \
    "FA_140Rnd_30mm_API_T_Green", \
    "FA_140Rnd_30mm_API_T_White", \
    "FA_140Rnd_30mm_API_T_Blue", \
    "FA_140Rnd_30mm_API_T_Orange", \
    "FA_140Rnd_30mm_API_T_IR", \
    "FA_250Rnd_30mm_HEI", \
    "FA_250Rnd_30mm_HEI_T_Red", \
    "FA_250Rnd_30mm_HEI_T_Yellow", \
    "FA_250Rnd_30mm_HEI_T_Green", \
    "FA_250Rnd_30mm_HEI_T_White", \
    "FA_250Rnd_30mm_HEI_T_Blue", \
    "FA_250Rnd_30mm_HEI_T_Orange", \
    "FA_250Rnd_30mm_HEI_T_IR", \
    "FA_250Rnd_30mm_ABM", \
    "FA_250Rnd_30mm_ABM_T_Red", \
    "FA_250Rnd_30mm_ABM_T_Yellow", \
    "FA_250Rnd_30mm_ABM_T_Green", \
    "FA_250Rnd_30mm_ABM_T_White", \
    "FA_250Rnd_30mm_ABM_T_Blue", \
    "FA_250Rnd_30mm_ABM_T_Orange", \
    "FA_250Rnd_30mm_ABM_T_IR", \
    "FA_250Rnd_30mm_PROX", \
    "FA_250Rnd_30mm_PROX_T_Red", \
    "FA_250Rnd_30mm_PROX_T_Yellow", \
    "FA_250Rnd_30mm_PROX_T_Green", \
    "FA_250Rnd_30mm_PROX_T_White", \
    "FA_250Rnd_30mm_PROX_T_Blue", \
    "FA_250Rnd_30mm_PROX_T_Orange", \
    "FA_250Rnd_30mm_PROX_T_IR"

// Reopen each weapon WITH its real parent named (parents forward-declared) so a
// parentless reopen can't strip the vanilla inheritance under cross-mod load
// order. Vanilla: autocannon_30mm:autocannon_30mm_CTWS, autocannon_30mm_CTWS/
// RCWS:autocannon_Base_F, autocannon_35mm:CannonCore.
class CfgWeapons {
    class autocannon_Base_F;
    class CannonCore;
    class autocannon_30mm_CTWS: autocannon_Base_F {
        magazines[] += {
            FA_MAGS_30MM
        };
    };
    class autocannon_30mm: autocannon_30mm_CTWS {
        magazines[] += {
            FA_MAGS_30MM
        };
    };
    class autocannon_30mm_RCWS: autocannon_Base_F {
        magazines[] += {
            FA_MAGS_30MM
        };
    };
    class autocannon_35mm: CannonCore {
        magazines[] += {
            "FA_680Rnd_35mm_AHEAD",
            "FA_680Rnd_35mm_AHEAD_T_Red",
            "FA_680Rnd_35mm_AHEAD_T_Yellow",
            "FA_680Rnd_35mm_AHEAD_T_Green",
            "FA_680Rnd_35mm_AHEAD_T_White",
            "FA_680Rnd_35mm_AHEAD_T_Blue",
            "FA_680Rnd_35mm_AHEAD_T_Orange",
            "FA_680Rnd_35mm_AHEAD_T_IR"
        };
    };
};
