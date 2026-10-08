class CfgWeapons {
    // base classes
    class ItemCore;
    class HeadgearItem;
    class UniformItem;
    class Uniform_Base;
    class HelmetBase: ItemCore {
        class ItemInfo: HeadgearItem {};
    };

    // ===== Headgear =====
    class GVAR(SOF_H_Opscore_rgr): HelmetBase {
        author = "OokamiJamie";
        // ACE electronic hearing protection (headset)
        ace_hearing_protection = 0.85;
        ace_hearing_lowerVolume = 0.05;
        ace_hearing_hasEHP = 1;
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_Opscore.p3d";
        displayName = "Hi-Cut Helmet (Green)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelections[] = {
            "camo",
            "camo1"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa)
        };
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\h_opscore.rvmat),
            QPATHTOF(data\h_headset.rvmat)
        };
        class ItemInfo: ItemInfo {
            mass = 30;
            hiddenSelections[] = {
                "camo",
                "camo1"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_opscore_rgr_co.paa),
                QPATHTOF(data\h_headset_rgr_co.paa)
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_Opscore.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 6;
                    passThrough = 0.5;
                };
            };
        };
    };
    class GVAR(SOF_H_Opscore_snd): GVAR(SOF_H_Opscore_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Sand)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_blk): GVAR(SOF_H_Opscore_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Black)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_blk_co.paa),
            QPATHTOF(data\h_headset_blk_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_oli): GVAR(SOF_H_Opscore_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Olive)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_oli_co.paa),
            QPATHTOF(data\h_headset_blk_co.paa)
        };
    };
    class GVAR(SOF_H_OpscoreSpec_rgr): HelmetBase {
        author = "OokamiJamie";
        // ACE electronic hearing protection (headset)
        ace_hearing_protection = 0.85;
        ace_hearing_lowerVolume = 0.05;
        ace_hearing_hasEHP = 1;
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_Opscore_Spec.p3d";
        displayName = "Enhanced Hi-Cut Helmet (Green)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo3"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_acc_rgr_co.paa)
        };
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\h_opscore.rvmat),
            QPATHTOF(data\h_headset.rvmat),
            QPATHTOF(data\h_opscore_acc.rvmat)
        };
        class ItemInfo: ItemInfo {
            mass = 30;
            hiddenSelections[] = {
                "camo",
                "camo1",
                "camo3"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_opscore_rgr_co.paa),
                QPATHTOF(data\h_headset_rgr_co.paa),
                QPATHTOF(data\h_opscore_acc_rgr_co.paa)
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_Opscore_Spec.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 6;
                    passThrough = 0.5;
                };
            };
        };
    };
    class GVAR(SOF_H_OpscoreSpec_snd): GVAR(SOF_H_OpscoreSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Sand)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_acc_snd_co.paa)
        };
    };
    class GVAR(SOF_H_OpscoreSpec_blk): GVAR(SOF_H_OpscoreSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Black)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_blk_co.paa),
            QPATHTOF(data\h_headset_blk_co.paa),
            QPATHTOF(data\h_opscore_acc_blk_co.paa)
        };
    };
    class GVAR(SOF_H_OpscoreSpec_oli): GVAR(SOF_H_OpscoreSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Olive)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_oli_co.paa),
            QPATHTOF(data\h_headset_blk_co.paa),
            QPATHTOF(data\h_opscore_acc_blk_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_rgr): HelmetBase {
        author = "OokamiJamie";
        // ACE electronic hearing protection (headset)
        ace_hearing_protection = 0.85;
        ace_hearing_lowerVolume = 0.05;
        ace_hearing_hasEHP = 1;
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_Opscore_Cover.p3d";
        displayName = "Hi-Cut Helmet (Cover, Green)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_rgr_co.paa)
        };
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\h_opscore.rvmat),
            QPATHTOF(data\h_headset.rvmat),
            QPATHTOF(data\h_opscore_cover.rvmat)
        };
        class ItemInfo: ItemInfo {
            mass = 30;
            hiddenSelections[] = {
                "camo",
                "camo1",
                "camo2"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_opscore_rgr_co.paa),
                QPATHTOF(data\h_headset_rgr_co.paa),
                QPATHTOF(data\h_opscore_cover_rgr_co.paa)
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_Opscore_Cover.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 6;
                    passThrough = 0.5;
                };
            };
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_rgr): HelmetBase {
        author = "OokamiJamie";
        // ACE electronic hearing protection (headset)
        ace_hearing_protection = 0.85;
        ace_hearing_lowerVolume = 0.05;
        ace_hearing_hasEHP = 1;
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_Opscore_Cover_Spec.p3d";
        displayName = "Enhanced Hi-Cut Helmet (Cover, Green)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2",
            "camo3"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_rgr_co.paa),
            QPATHTOF(data\h_opscore_acc_rgr_co.paa)
        };
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\h_opscore.rvmat),
            QPATHTOF(data\h_headset.rvmat),
            QPATHTOF(data\h_opscore_cover.rvmat),
            QPATHTOF(data\h_opscore_acc.rvmat)
        };
        class ItemInfo: ItemInfo {
            mass = 30;
            hiddenSelections[] = {
                "camo",
                "camo1",
                "camo2",
                "camo3"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_opscore_rgr_co.paa),
                QPATHTOF(data\h_headset_rgr_co.paa),
                QPATHTOF(data\h_opscore_cover_rgr_co.paa),
                QPATHTOF(data\h_opscore_acc_rgr_co.paa)
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_Opscore_Cover_Spec.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 6;
                    passThrough = 0.5;
                };
            };
        };
    };
    class GVAR(SOF_H_Opscore_CoverCamo_rgr): HelmetBase {
        author = "OokamiJamie";
        // ACE electronic hearing protection (headset)
        ace_hearing_protection = 0.85;
        ace_hearing_lowerVolume = 0.05;
        ace_hearing_hasEHP = 1;
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_Opscore_Cover_camo.p3d";
        displayName = "Hi-Cut Helmet (Cover, Green/Camo)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2",
            "camo3"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_rgr_co.paa),
            QPATHTOF(data\ghillie_leaves_rgr_ca.paa)
        };
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\h_opscore.rvmat),
            QPATHTOF(data\h_headset.rvmat),
            QPATHTOF(data\h_opscore_cover.rvmat),
            ""
        };
        class ItemInfo: ItemInfo {
            mass = 30;
            hiddenSelections[] = {
                "camo",
                "camo1",
                "camo2",
                "camo3"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_opscore_rgr_co.paa),
                QPATHTOF(data\h_headset_rgr_co.paa),
                QPATHTOF(data\h_opscore_cover_rgr_co.paa),
                QPATHTOF(data\ghillie_leaves_rgr_ca.paa)
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_Opscore_Cover_camo.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 6;
                    passThrough = 0.5;
                };
            };
        };
    };
    class GVAR(SOF_H_Opscore_Cover_mcam): GVAR(SOF_H_Opscore_Cover_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, MTP)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_mcam_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_mcam): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Cover, MTP)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_mcam_co.paa),
            QPATHTOF(data\h_opscore_acc_rgr_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverCamo_mcam): GVAR(SOF_H_Opscore_CoverCamo_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, MTP/Camo)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_mcam_co.paa),
            QPATHTOF(data\ghillie_leaves_mcam_ca.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_tna): GVAR(SOF_H_Opscore_Cover_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, Tropic)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_tna_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_tna): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Cover, Tropic)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_tna_co.paa),
            QPATHTOF(data\h_opscore_acc_rgr_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_wdl): GVAR(SOF_H_Opscore_Cover_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, Woodland)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_wdl_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_wdl): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Cover, Woodland)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_wdl_co.paa),
            QPATHTOF(data\h_opscore_acc_rgr_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_mrpt_wdl): GVAR(SOF_H_Opscore_Cover_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, USMC Woodland)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_mrpt_wdl_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_mrpt_wdl): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Cover, USMC Woodland)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_mrpt_wdl_co.paa),
            QPATHTOF(data\h_opscore_acc_snd_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_mrpt_des): GVAR(SOF_H_Opscore_Cover_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, USMC Desert)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_mrpt_des_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_mrpt_des): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Cover, USMC Desert)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_mrpt_des_co.paa),
            QPATHTOF(data\h_opscore_acc_snd_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_nwu): GVAR(SOF_H_Opscore_Cover_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Hi-Cut Helmet (Cover, USN Woodland)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_nwu_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_nwu): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Enhanced Hi-Cut Helmet (Cover, USN Woodland)";
        picture = QPATHTOF(data\h_opscore_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_nwu_co.paa),
            ""
        };
    };
    class GVAR(SOF_H_BaseballCap_rgr): HelmetBase {
        author = "OokamiJamie";
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_BaseballCap.p3d";
        displayName = "Baseball Cap (Green)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_rgr_co.paa)
        };
        class ItemInfo: ItemInfo {
            mass = 8;
            hiddenSelections[] = {
                "camo",
                "camo2"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_baseballcap_rgr_co.paa)
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_BaseballCap.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 0;
                    passThrough = 0;
                };
            };
        };
    };
    class GVAR(SOF_H_BaseballCapSpec_rgr): HelmetBase {
        author = "OokamiJamie";
        // ACE electronic hearing protection (headset)
        ace_hearing_protection = 0.85;
        ace_hearing_lowerVolume = 0.05;
        ace_hearing_hasEHP = 1;
        scope = 2;
        model = "\SOFGear\sof_characters\Headgear\H_BaseballCap_Spec.p3d";
        displayName = "Baseball Cap (Headset, Green)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            ""
        };
        class ItemInfo: ItemInfo {
            mass = 8;
            hiddenSelections[] = {
                "camo",
                "camo1",
                "camo2"
            };
            hiddenSelectionsTextures[] = {
                QPATHTOF(data\h_baseballcap_rgr_co.paa),
                QPATHTOF(data\h_headset_rgr_co.paa),
                ""
            };
            uniformModel = "\SOFGear\sof_characters\Headgear\H_BaseballCap_Spec.p3d";
            modelSides[] = {2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 0;
                    passThrough = 0;
                };
            };
        };
    };
    class GVAR(SOF_H_BaseballCap_khk): GVAR(SOF_H_BaseballCap_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Baseball Cap (Khaki)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_khk_co.paa),
            ""
        };
    };
    class GVAR(SOF_H_BaseballCapSpec_khk): GVAR(SOF_H_BaseballCapSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Baseball Cap (Headset, Khaki)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_khk_co.paa),
            QPATHTOF(data\h_headset_blk_co.paa),
            ""
        };
    };
    class GVAR(SOF_H_BaseballCap_mcam): GVAR(SOF_H_BaseballCap_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Baseball Cap (MTP)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_mcam_co.paa),
            ""
        };
    };
    class GVAR(SOF_H_BaseballCapSpec_mcam): GVAR(SOF_H_BaseballCapSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Baseball Cap (Headset, MTP)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_mcam_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            ""
        };
    };
    class GVAR(SOF_H_BaseballCapSpec_tna): GVAR(SOF_H_BaseballCapSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Baseball Cap (Headset, Tropic)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_tna_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            ""
        };
    };
    class GVAR(SOF_H_BaseballCapSpec_wdl): GVAR(SOF_H_BaseballCapSpec_rgr) {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Baseball Cap (Headset, Woodland)";
        picture = QPATHTOF(data\h_baseballcap_ico_ca.paa);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_baseballcap_wdl_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            ""
        };
    };

    // ===== Vests =====

    // ===== Uniforms =====
    class GVAR(SOF_U_B_SFFatigues_rgr): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (Green)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_rgr);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_rgr): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (Green, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_rgr);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_mcam): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (MTP)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_mcam);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_mcam): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (MTP, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_mcam);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_tna): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (Tropic)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_tna);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_tna): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (Tropic, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_tna);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_wdl): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (Woodland)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_wdl);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_wdl): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (Woodland, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_wdl);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_mrpt): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (USMC Woodland)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_mrpt);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_mrpt): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (USMC Woodland, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_mrpt);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_mrpt_des): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (USMC Desert)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_mrpt_des);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_mrpt_des): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (USMC Desert, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_mrpt_des);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_nwu): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (USN Woodland)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_nwu);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_nwu): Uniform_Base {        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Fatigues (USN Woodland, Rolled-up)";
        picture = QPATHTOF(data\u_fatiguessf_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_rgr_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_nwu);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    // ===== OCP retextures =====
    class GVAR(SOF_H_Opscore_Cover_ocp): GVAR(SOF_H_Opscore_Cover_rgr) {
        displayName = "Hi-Cut Helmet (Cover, OCP)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_ocp_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_ocp): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        displayName = "Enhanced Hi-Cut Helmet (Cover, OCP)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_ocp_co.paa),
            QPATHTOF(data\h_opscore_acc_rgr_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverCamo_ocp): GVAR(SOF_H_Opscore_CoverCamo_rgr) {
        displayName = "Hi-Cut Helmet (Cover, OCP/Camo)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_rgr_co.paa),
            QPATHTOF(data\h_headset_rgr_co.paa),
            QPATHTOF(data\h_opscore_cover_ocp_co.paa),
            QPATHTOF(data\ghillie_leaves_mcam_ca.paa)
        };
    };
    class GVAR(SOF_U_B_SFFatigues_ocp): GVAR(SOF_U_B_SFFatigues_rgr) {        
        displayName = "Special Fatigues (OCP)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_assaultuniform_pants_ocp_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFFatigues_ocp);
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_ocp): GVAR(SOF_U_B_SFFatigues_Shortsleeve_rgr) {        
        displayName = "Special Fatigues (OCP, Rolled-Up)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_assaultuniform_pants_ocp_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_ocp);
        };
    };

    // ===== Alpine and USMC Winter covers (JAM SOF, 31 August) =====
    // The mod added four cover paints and, like every other helmet it ships,
    // gave them no hearing protection at all - the whole sof_characters config
    // carries not one ace_ property, while 81 lines of it put a headset texture
    // on the model. Built here the way the rest of this family is: inheriting
    // the _rgr base, which is where the 0.85 / 0.05 / EHP lines live.
    //
    // The mod pairs both new covers with the SAND helmet and headset, not the
    // green - h_opscore_snd_co and h_headset_snd_co, both already vendored. Only
    // the two cover paints were new to data\.
    class GVAR(SOF_H_Opscore_Cover_alp): GVAR(SOF_H_Opscore_Cover_rgr) {
        displayName = "Hi-Cut Helmet (Cover, Alpine)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_alp_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_Cover_mrpt_win): GVAR(SOF_H_Opscore_Cover_rgr) {
        displayName = "Hi-Cut Helmet (Cover, USMC Winter)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_mrpt_win_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_alp): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        displayName = "Enhanced Hi-Cut Helmet (Cover, Alpine)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_alp_co.paa),
            QPATHTOF(data\h_opscore_acc_snd_us_co.paa)
        };
    };
    class GVAR(SOF_H_Opscore_CoverSpec_mrpt_win): GVAR(SOF_H_Opscore_CoverSpec_rgr) {
        displayName = "Enhanced Hi-Cut Helmet (Cover, USMC Winter)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\h_opscore_snd_co.paa),
            QPATHTOF(data\h_headset_snd_co.paa),
            QPATHTOF(data\h_opscore_cover_mrpt_win_co.paa),
            QPATHTOF(data\h_opscore_acc_snd_us_des_co.paa)
        };
    };

    // ===== Cold Fatigues and the desert pair (JAM SOF, 31 August) =====
    class GVAR(SOF_U_B_SFColdFatigues_mcam_gry): Uniform_Base {
        author = "OokamiJamie";
        scope = 2;
        displayName = "Special Cold Fatigues (MTP/Grey)";
        picture = QPATHTOF(data\u_uniformspeccold_ico_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {
            "camo"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_coldweatherjacket_gry_co.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(SOF_B_SFColdFatigues_mcam_gry);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(SOF_U_B_SFColdFatigues_mcam_alp): GVAR(SOF_U_B_SFColdFatigues_mcam_gry) {
        displayName = "Special Cold Fatigues (MTP/Alpine)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_coldweatherjacket_alp_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFColdFatigues_mcam_alp);
        };
    };
    class GVAR(SOF_U_B_SFColdFatigues_alp): GVAR(SOF_U_B_SFColdFatigues_mcam_gry) {
        displayName = "Special Cold Fatigues (Alpine)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_coldweatherjacket_alp_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFColdFatigues_alp);
        };
    };
    class GVAR(SOF_U_B_SFColdFatigues_alp_gry): GVAR(SOF_U_B_SFColdFatigues_mcam_gry) {
        displayName = "Special Cold Fatigues (Alpine/Grey)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_coldweatherjacket_gry_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFColdFatigues_alp_gry);
        };
    };
    class GVAR(SOF_U_B_SFColdFatigues_mrpt_win): GVAR(SOF_U_B_SFColdFatigues_mcam_gry) {
        displayName = "Special Cold Fatigues (USMC Winter)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_coldweatherjacket_mrpt_win_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFColdFatigues_mrpt_win);
        };
    };
    class GVAR(SOF_U_B_SFColdFatigues_mrpt_win_wdl): GVAR(SOF_U_B_SFColdFatigues_mcam_gry) {
        displayName = "Special Cold Fatigues (USMC Winter/Woodland)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_coldweatherjacket_mrpt_win_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFColdFatigues_mrpt_win_wdl);
        };
    };
    class GVAR(SOF_U_B_SFFatigues_desert): GVAR(SOF_U_B_SFFatigues_rgr) {
        displayName = "Special Fatigues (Desert)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_desert_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFFatigues_desert);
        };
    };
    class GVAR(SOF_U_B_SFFatigues_Shortsleeve_desert): GVAR(SOF_U_B_SFFatigues_Shortsleeve_rgr) {
        displayName = "Special Fatigues (Desert, Rolled-up)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\u_fatiguessf_desert_co.paa)
        };
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(SOF_B_SFFatigues_Shortsleeve_desert);
        };
    };
};
