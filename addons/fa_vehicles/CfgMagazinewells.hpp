// Heavy fires — 155mm SPG shells wired through the CBA magazine well instead of
// a magazines[] += on the weapon.
//
// ACE_155mm_artillery is defined by ace_missile_clgp (ACE3 addons/missile_clgp),
// which is also what puts it on the gun:
//     class mortar_155mm_AMOS: CannonCore { magazineWell[] += {"ACE_155mm_artillery"}; };
// Vanilla mortar_155mm_AMOS carries NO magazineWell[] of its own (verified against
// a derapified weapons_f.pbo — AMOS lives in A3_Weapons_F, not armor_f_gamma), so
// this wiring is entirely dependent on ace_missile_clgp being loaded; it is listed
// in requiredAddons.
//
// Feeding the well rather than reopening the weapon means we no longer touch
// mortar_155mm_AMOS at all, which removes the parentless-reopen hazard that
// previously collapsed the destroyer gun and the RF twin mortar (both inherit AMOS).
//
// NOTE: weapon_ShipCannon_120mm inherits AMOS and declares no magazineWell[] of its
// own, so it inherits this well too — the 155mm shells also show on the Mk45 Hammer.
// That is pre-existing ACE behaviour (their M712 rounds already ride along); the
// gun's own FA 120N shells stay on magazines[] += in CfgWeapons.hpp.
class CfgMagazineWells {
    class ACE_155mm_artillery {
        ADDON[] += {
            "FA_32Rnd_155mm_heer_B", "FA_32Rnd_155mm_heer_O", "FA_32Rnd_155mm_heer_I",
            "FA_4Rnd_155mm_apmi_B", "FA_4Rnd_155mm_apmi_O", "FA_4Rnd_155mm_apmi_I",
            "FA_4Rnd_155mm_lgm_B", "FA_4Rnd_155mm_lgm_O", "FA_4Rnd_155mm_lgm_I",
            "FA_6Rnd_155mm_smk_B", "FA_6Rnd_155mm_smk_O", "FA_6Rnd_155mm_smk_I",
            "FA_6Rnd_155mm_apmine_B", "FA_6Rnd_155mm_apmine_O", "FA_6Rnd_155mm_apmine_I",
            "FA_6Rnd_155mm_atmine_B", "FA_6Rnd_155mm_atmine_O", "FA_6Rnd_155mm_atmine_I",
            "FA_2Rnd_155mm_sfm_B", "FA_2Rnd_155mm_sfm_O", "FA_2Rnd_155mm_sfm_I",
            "FA_32Rnd_155mm_tb_B", "FA_32Rnd_155mm_tb_O", "FA_32Rnd_155mm_tb_I",
            "FA_8Rnd_155mm_ir_B"
        };
    };
};
