// Join each FA magazine to the caliber's CBA magazineWell so it appears on every
// mod weapon in that caliber (VSS/Val, P90/Five-seveN, PTRD/PTRS AM rifles) with
// no per-weapon patching.
class CfgMagazineWells {
    // 9x39 — VSS Vintorez / AS Val
    class CBA_9x39_VSS {
        ADDON[] += { "FA_o_20Rnd_9x39_7U15", "FA_20Rnd_9x39_7U15", "FA_o_20Rnd_9x39_7U16", "FA_20Rnd_9x39_7U16" };
    };

    // 5.7x28 — P90 (50-round)
    class CBA_57x28_P90 {
        ADDON[] += { "FA_b_50Rnd_57x28_Mk430", "FA_50Rnd_57x28_Mk430", "FA_b_50Rnd_57x28_Mk431", "FA_50Rnd_57x28_Mk431" };
    };
    // 5.7x28 — Five-seveN (20-round)
    class CBA_57x28_FN57 {
        ADDON[] += { "FA_b_20Rnd_57x28_Mk430", "FA_20Rnd_57x28_Mk430", "FA_b_20Rnd_57x28_Mk431", "FA_20Rnd_57x28_Mk431" };
    };

    // 14.5x114 — PTRS mag-fed AM rifle (5-round). NOTE: the belt-fed KPV on the
    // BTR is a vehicle weapon with no CBA well; it needs a direct weapon patch
    // once its classname is known.
    class CBA_145x114_PTRS {
        ADDON[] += { "FA_o_5Rnd_145_7N60", "FA_5Rnd_145_7N60", "FA_o_5Rnd_145_7N61", "FA_5Rnd_145_7N61", "FA_o_5Rnd_145_7N62", "FA_5Rnd_145_7N62" };
    };

    // 6.5x39 caseless well registration now lives in jmfsbfa_ammo (full matrix).
};
