// Same rule as mediumcaliber/CfgWeapons.hpp: always `+=`, never `=`, since
// cannon_120mm/cannon_120mm_long/cannon_125mm are shared across NATO/CSAT MBT
// variants (the Slammer family and the CSAT MBT).
#define FA_MAGS_120MM \
    "FA_30Rnd_120mm_APFSDS", \
    "FA_30Rnd_120mm_APFSDS_Red", \
    "FA_30Rnd_120mm_APFSDS_T_Red", \
    "FA_30Rnd_120mm_APFSDS_T_Yellow", \
    "FA_30Rnd_120mm_APFSDS_T_Green", \
    "FA_30Rnd_120mm_APFSDS_T_White", \
    "FA_30Rnd_120mm_APFSDS_T_Blue", \
    "FA_30Rnd_120mm_APFSDS_T_Orange", \
    "FA_30Rnd_120mm_APFSDS_T_IR", \
    "FA_30Rnd_120mm_AMP", \
    "FA_30Rnd_120mm_AMP_T_Red", \
    "FA_30Rnd_120mm_AMP_T_Yellow", \
    "FA_30Rnd_120mm_AMP_T_Green", \
    "FA_30Rnd_120mm_AMP_T_White", \
    "FA_30Rnd_120mm_AMP_T_Blue", \
    "FA_30Rnd_120mm_AMP_T_Orange", \
    "FA_30Rnd_120mm_AMP_T_IR", \
    "FA_30Rnd_120mm_HEATMP", \
    "FA_30Rnd_120mm_HEATMP_T_Red", \
    "FA_30Rnd_120mm_HEATMP_T_Yellow", \
    "FA_30Rnd_120mm_HEATMP_T_Green", \
    "FA_30Rnd_120mm_HEATMP_T_White", \
    "FA_30Rnd_120mm_HEATMP_T_Blue", \
    "FA_30Rnd_120mm_HEATMP_T_Orange", \
    "FA_30Rnd_120mm_HEATMP_T_IR", \
    "FA_30Rnd_120mm_HEAB", \
    "FA_30Rnd_120mm_HEAB_T_Red", \
    "FA_30Rnd_120mm_HEAB_T_Yellow", \
    "FA_30Rnd_120mm_HEAB_T_Green", \
    "FA_30Rnd_120mm_HEAB_T_White", \
    "FA_30Rnd_120mm_HEAB_T_Blue", \
    "FA_30Rnd_120mm_HEAB_T_Orange", \
    "FA_30Rnd_120mm_HEAB_T_IR"

// Reopen each cannon WITH its real parent named (forward-declared) so a parentless
// reopen can't strip the vanilla inheritance under cross-mod load order — which
// would cascade into mod children like QAV's cannon_125mm_advanced. Vanilla:
// cannon_120mm:CannonCore, cannon_120mm_long:cannon_120mm, cannon_125mm:CannonCore.
class CfgWeapons {
    class CannonCore;
    class cannon_120mm: CannonCore {
        magazines[] += { FA_MAGS_120MM };
    };
    class cannon_120mm_long: cannon_120mm {
        magazines[] += { FA_MAGS_120MM };
    };
    class cannon_125mm: CannonCore {
        magazines[] += {
            "FA_24Rnd_125mm_APFSDS",
            "FA_24Rnd_125mm_APFSDS_T_Red",
            "FA_24Rnd_125mm_APFSDS_T_Yellow",
            "FA_24Rnd_125mm_APFSDS_T_Green",
            "FA_24Rnd_125mm_APFSDS_T_White",
            "FA_24Rnd_125mm_APFSDS_T_Blue",
            "FA_24Rnd_125mm_APFSDS_T_Orange",
            "FA_24Rnd_125mm_APFSDS_T_IR",
            "FA_12Rnd_125mm_AMP",
            "FA_12Rnd_125mm_AMP_T_Red",
            "FA_12Rnd_125mm_AMP_T_Yellow",
            "FA_12Rnd_125mm_AMP_T_Green",
            "FA_12Rnd_125mm_AMP_T_White",
            "FA_12Rnd_125mm_AMP_T_Blue",
            "FA_12Rnd_125mm_AMP_T_Orange",
            "FA_12Rnd_125mm_AMP_T_IR",
            // CSAT 125mm East natures
            "FA_24Rnd_125mm_3BM70",
            "FA_12Rnd_125mm_3BK31",
            "FA_12Rnd_125mm_3OF82",
            "FA_4Rnd_125mm_Refleks"
        };
    };
};
