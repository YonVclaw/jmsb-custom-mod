class XtdGearModels {
    class CfgWeapons {
        class GVAR(Opscore) {
            label = "SOF Hi-Cut";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"RGR", "SND", "BLK", "OLV", "MTP", "TNA", "WDL", "ALP", "MRPT_W", "MRPT_D", "MRPT_WIN", "NWU", "OCP"};
                class RGR {
                    label = "RGR";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class SND {
                    label = "SND";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class BLK {
                    label = "BLK";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class OLV {
                    label = "OLV";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
                class TNA {
                    label = "TNA";
                    image = "z\aceax\addons\gearinfo\data\camo\tropic.paa";
                };
                class WDL {
                    label = "WDL";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class ALP {
                    label = "ALP";
                    image = "z\aceax\addons\gearinfo\data\camo\alp.paa";
                };
                class MRPT_W {
                    label = "MRP-W";
                    image = "z\aceax\addons\gearinfo\data\camo\mrpt_wd.paa";
                };
                class MRPT_D {
                    label = "MRP-D";
                    image = "z\aceax\addons\gearinfo\data\camo\mrpt_d.paa";
                };
                // aceax gearinfo has no winter MARPAT swatch - white stands in.
                class MRPT_WIN {
                    label = "MRP-Win";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
                class NWU {
                    label = "NWU";
                    image = "z\aceax\addons\gearinfo\data\camo\aor2.paa";
                };
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Plain", "Enhanced", "Cover", "CoverEnh", "CoverCamo"};
                class Plain {
                    label = "Plain";
                };
                class Enhanced {
                    label = "Enh";
                };
                class Cover {
                    label = "Cover";
                };
                class CoverEnh {
                    label = "Cover+";
                };
                class CoverCamo {
                    label = "Ghillie";
                };
            };
        };
        class GVAR(BaseballCap) {
            label = "SOF Baseball cap";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"RGR", "KHK", "MTP", "TNA", "WDL"};
                class RGR {
                    label = "RGR";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class KHK {
                    label = "KHK";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
                class TNA {
                    label = "TNA";
                    image = "z\aceax\addons\gearinfo\data\camo\tropic.paa";
                };
                class WDL {
                    label = "WDL";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Plain", "Headset"};
                class Plain {
                    label = "Plain";
                };
                class Headset {
                    label = "Hdset";
                };
            };
        };
        class GVAR(SFFatigues) {
            label = "SOF Fatigues";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"RGR", "DES", "MTP", "TNA", "WDL", "MRPT_W", "MRPT_D", "NWU", "OCP"};
                class RGR {
                    label = "RGR";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                // Solid tan, the way RGR is solid green - not a pattern.
                class DES {
                    label = "DES";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
                class TNA {
                    label = "TNA";
                    image = "z\aceax\addons\gearinfo\data\camo\tropic.paa";
                };
                class WDL {
                    label = "WDL";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MRPT_W {
                    label = "MRP-W";
                    image = "z\aceax\addons\gearinfo\data\camo\mrpt_wd.paa";
                };
                class MRPT_D {
                    label = "MRP-D";
                    image = "z\aceax\addons\gearinfo\data\camo\mrpt_d.paa";
                };
                class NWU {
                    label = "NWU";
                    image = "z\aceax\addons\gearinfo\data\camo\aor2.paa";
                };
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Full", "RolledUp"};
                class Full {
                    label = "Full";
                };
                class RolledUp {
                    label = "Rolled";
                };
            };
        };
        // JAM SOF's cold-weather set, added by the mod on 31 August. It is
        // a PAIRING, not a camo: SOF_B_SFColdFatigues_mcam_gry wears
        // U_ColdWeatherJacket_gry over U_FatiguesSF_Pants_mcam, so jacket
        // and trousers are separate axes. Six of the twelve combinations
        // exist; the rest grey out, as they already do on the Hi-Cut above.
        class GVAR(SFColdFatigues) {
            label = "SOF Cold Fatigues";
            options[] = {"jacket", "trousers"};
            class jacket {
                alwaysSelectable = 1;
                values[] = {"GRY", "ALP", "MRPT_WIN"};
                class GRY {
                    label = "GRY";
                    image = "z\aceax\addons\gearinfo\data\camo\gry.paa";
                };
                class ALP {
                    label = "ALP";
                    image = "z\aceax\addons\gearinfo\data\camo\alp.paa";
                };
                class MRPT_WIN {
                    label = "MRP-Win";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
            };
            class trousers {
                alwaysSelectable = 1;
                values[] = {"MTP", "ALP", "MRPT_W", "MRPT_WIN"};
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
                class ALP {
                    label = "ALP";
                    image = "z\aceax\addons\gearinfo\data\camo\alp.paa";
                };
                class MRPT_W {
                    label = "MRP-W";
                    image = "z\aceax\addons\gearinfo\data\camo\mrpt_wd.paa";
                };
                class MRPT_WIN {
                    label = "MRP-Win";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        /* Hi-Cut */
        class GVAR(SOF_H_Opscore_rgr) {
            model = QGVAR(Opscore);
            camo = "RGR";
            type = "Plain";
        };
        class GVAR(SOF_H_Opscore_snd) {
            model = QGVAR(Opscore);
            camo = "SND";
            type = "Plain";
        };
        class GVAR(SOF_H_Opscore_blk) {
            model = QGVAR(Opscore);
            camo = "BLK";
            type = "Plain";
        };
        class GVAR(SOF_H_Opscore_oli) {
            model = QGVAR(Opscore);
            camo = "OLV";
            type = "Plain";
        };
        class GVAR(SOF_H_OpscoreSpec_rgr) {
            model = QGVAR(Opscore);
            camo = "RGR";
            type = "Enhanced";
        };
        class GVAR(SOF_H_OpscoreSpec_snd) {
            model = QGVAR(Opscore);
            camo = "SND";
            type = "Enhanced";
        };
        class GVAR(SOF_H_OpscoreSpec_blk) {
            model = QGVAR(Opscore);
            camo = "BLK";
            type = "Enhanced";
        };
        class GVAR(SOF_H_OpscoreSpec_oli) {
            model = QGVAR(Opscore);
            camo = "OLV";
            type = "Enhanced";
        };
        class GVAR(SOF_H_Opscore_Cover_rgr) {
            model = QGVAR(Opscore);
            camo = "RGR";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_mcam) {
            model = QGVAR(Opscore);
            camo = "MTP";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_tna) {
            model = QGVAR(Opscore);
            camo = "TNA";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_wdl) {
            model = QGVAR(Opscore);
            camo = "WDL";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_mrpt_wdl) {
            model = QGVAR(Opscore);
            camo = "MRPT_W";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_mrpt_des) {
            model = QGVAR(Opscore);
            camo = "MRPT_D";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_nwu) {
            model = QGVAR(Opscore);
            camo = "NWU";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_ocp) {
            model = QGVAR(Opscore);
            camo = "OCP";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_rgr) {
            model = QGVAR(Opscore);
            camo = "RGR";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_mcam) {
            model = QGVAR(Opscore);
            camo = "MTP";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_tna) {
            model = QGVAR(Opscore);
            camo = "TNA";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_wdl) {
            model = QGVAR(Opscore);
            camo = "WDL";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_mrpt_wdl) {
            model = QGVAR(Opscore);
            camo = "MRPT_W";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_mrpt_des) {
            model = QGVAR(Opscore);
            camo = "MRPT_D";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_nwu) {
            model = QGVAR(Opscore);
            camo = "NWU";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_ocp) {
            model = QGVAR(Opscore);
            camo = "OCP";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverCamo_rgr) {
            model = QGVAR(Opscore);
            camo = "RGR";
            type = "CoverCamo";
        };
        class GVAR(SOF_H_Opscore_CoverCamo_mcam) {
            model = QGVAR(Opscore);
            camo = "MTP";
            type = "CoverCamo";
        };
        class GVAR(SOF_H_Opscore_CoverCamo_ocp) {
            model = QGVAR(Opscore);
            camo = "OCP";
            type = "CoverCamo";
        };
        /* Cap */
        class GVAR(SOF_H_BaseballCap_rgr) {
            model = QGVAR(BaseballCap);
            camo = "RGR";
            type = "Plain";
        };
        class GVAR(SOF_H_BaseballCap_khk) {
            model = QGVAR(BaseballCap);
            camo = "KHK";
            type = "Plain";
        };
        class GVAR(SOF_H_BaseballCap_mcam) {
            model = QGVAR(BaseballCap);
            camo = "MTP";
            type = "Plain";
        };
        class GVAR(SOF_H_BaseballCapSpec_rgr) {
            model = QGVAR(BaseballCap);
            camo = "RGR";
            type = "Headset";
        };
        class GVAR(SOF_H_BaseballCapSpec_khk) {
            model = QGVAR(BaseballCap);
            camo = "KHK";
            type = "Headset";
        };
        class GVAR(SOF_H_BaseballCapSpec_mcam) {
            model = QGVAR(BaseballCap);
            camo = "MTP";
            type = "Headset";
        };
        class GVAR(SOF_H_BaseballCapSpec_tna) {
            model = QGVAR(BaseballCap);
            camo = "TNA";
            type = "Headset";
        };
        class GVAR(SOF_H_BaseballCapSpec_wdl) {
            model = QGVAR(BaseballCap);
            camo = "WDL";
            type = "Headset";
        };
        /* AVS */
        /* SF Fatigues */
        class GVAR(SOF_U_B_SFFatigues_rgr) {
            model = QGVAR(SFFatigues);
            camo = "RGR";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_rgr) {
            model = QGVAR(SFFatigues);
            camo = "RGR";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_mcam) {
            model = QGVAR(SFFatigues);
            camo = "MTP";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_mcam) {
            model = QGVAR(SFFatigues);
            camo = "MTP";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_tna) {
            model = QGVAR(SFFatigues);
            camo = "TNA";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_tna) {
            model = QGVAR(SFFatigues);
            camo = "TNA";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_wdl) {
            model = QGVAR(SFFatigues);
            camo = "WDL";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_wdl) {
            model = QGVAR(SFFatigues);
            camo = "WDL";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_mrpt) {
            model = QGVAR(SFFatigues);
            camo = "MRPT_W";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_mrpt) {
            model = QGVAR(SFFatigues);
            camo = "MRPT_W";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_mrpt_des) {
            model = QGVAR(SFFatigues);
            camo = "MRPT_D";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_mrpt_des) {
            model = QGVAR(SFFatigues);
            camo = "MRPT_D";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_nwu) {
            model = QGVAR(SFFatigues);
            camo = "NWU";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_nwu) {
            model = QGVAR(SFFatigues);
            camo = "NWU";
            type = "RolledUp";
        };
        class GVAR(SOF_U_B_SFFatigues_ocp) {
            model = QGVAR(SFFatigues);
            camo = "OCP";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_ocp) {
            model = QGVAR(SFFatigues);
            camo = "OCP";
            type = "RolledUp";
        };
        /* ---- JAM SOF's own, added by the mod on 31 August ----
           Everything above is one of our retextures; everything below is
           the mod's, filed on the same models so the arsenal shows one
           entry per garment rather than two. Only coordinates our copies
           do not already hold are used - a shared one shadows the other. */
        /* Hi-Cut - two new cover camos. OURS: the covers are remade in
           CfgWeapons on the _rgr base, for the hearing protection JAM SOF
           does not ship, so these are GVAR like the rest of the family. */
        class GVAR(SOF_H_Opscore_Cover_alp) {
            model = QGVAR(Opscore);
            camo = "ALP";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_Cover_mrpt_win) {
            model = QGVAR(Opscore);
            camo = "MRPT_WIN";
            type = "Cover";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_alp) {
            model = QGVAR(Opscore);
            camo = "ALP";
            type = "CoverEnh";
        };
        class GVAR(SOF_H_Opscore_CoverSpec_mrpt_win) {
            model = QGVAR(Opscore);
            camo = "MRPT_WIN";
            type = "CoverEnh";
        };
        /* SF Fatigues - the desert pair */
        class GVAR(SOF_U_B_SFFatigues_desert) {
            model = QGVAR(SFFatigues);
            camo = "DES";
            type = "Full";
        };
        class GVAR(SOF_U_B_SFFatigues_Shortsleeve_desert) {
            model = QGVAR(SFFatigues);
            camo = "DES";
            type = "RolledUp";
        };
        /* Cold Fatigues - jacket over trousers, read off the mod's textures */
        class GVAR(SOF_U_B_SFColdFatigues_alp) {
            model = QGVAR(SFColdFatigues);
            jacket = "ALP";
            trousers = "ALP";
        };
        class GVAR(SOF_U_B_SFColdFatigues_alp_gry) {
            model = QGVAR(SFColdFatigues);
            jacket = "GRY";
            trousers = "ALP";
        };
        class GVAR(SOF_U_B_SFColdFatigues_mcam_alp) {
            model = QGVAR(SFColdFatigues);
            jacket = "ALP";
            trousers = "MTP";
        };
        class GVAR(SOF_U_B_SFColdFatigues_mcam_gry) {
            model = QGVAR(SFColdFatigues);
            jacket = "GRY";
            trousers = "MTP";
        };
        class GVAR(SOF_U_B_SFColdFatigues_mrpt_win) {
            model = QGVAR(SFColdFatigues);
            jacket = "MRPT_WIN";
            trousers = "MRPT_WIN";
        };
        class GVAR(SOF_U_B_SFColdFatigues_mrpt_win_wdl) {
            model = QGVAR(SFColdFatigues);
            jacket = "MRPT_WIN";
            trousers = "MRPT_W";
        };
    };
};
