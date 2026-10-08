class XtdGearModels {
    class CfgWeapons {
        class GVAR(AVSCarrier) {
            label = "SOF AVS";
            // "cut" separates the original V_CarrierAVS_Lite p3d our six
            // retextures wear from the three the mod added on 31 August.
            // Without it the reworked Lite would land on the same
            // camo/flag coordinate as ours and shadow it.
            options[] = {"cut", "camo", "type"};
            class cut {
                alwaysSelectable = 1;
                values[] = {"Orig", "Lite", "Rifle", "Gunner"};
                class Orig {
                    label = "Orig";
                };
                class Lite {
                    label = "Lite";
                };
                class Rifle {
                    label = "Rifle";
                };
                class Gunner {
                    label = "Gunner";
                };
            };
            class camo {
                alwaysSelectable = 1;
                values[] = {"RGR", "MTP", "TNA", "WDL", "OCP", "BLK", "CBR", "SND"};
                class RGR {
                    label = "RGR";
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
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class BLK {
                    label = "BLK";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                // Coyote and sand both borrow the khaki swatch - aceax
                class CBR {
                    label = "CBR";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                // gearinfo ships no closer pair, and the labels carry it.
                class SND {
                    label = "SND";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Flag", "NoFlag"};
                class Flag {
                    label = "Flag";
                };
                class NoFlag {
                    label = "NoFlag";
                };
            };
        };
        class GVAR(CHPCCarrier) {
            label = "SOF CHPC";
            options[] = {"cut", "camo"};
            class cut {
                alwaysSelectable = 1;
                values[] = {"Lite", "Gunner", "Rig", "SMG"};
                class Lite {
                    label = "Lite";
                };
                class Gunner {
                    label = "Gunner";
                };
                class Rig {
                    label = "Rig";
                };
                class SMG {
                    label = "SMG";
                };
            };
            class camo {
                alwaysSelectable = 1;
                values[] = {"KHK", "BLK", "OLI", "HEX", "GHEX"};
                class KHK {
                    label = "Khaki";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class BLK {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class OLI {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class HEX {
                    label = "Hex";
                    image = "z\aceax\addons\gearinfo\data\camo\csat.paa";
                };
                class GHEX {
                    label = "Green Hex";
                    image = "z\aceax\addons\gearinfo\data\camo\csat_tna.paa";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        class GVAR(SOF_V_AVSCarrier_Lite_rgr) {
            model = QGVAR(AVSCarrier);
            cut = "Orig";
            camo = "RGR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_rgr_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Orig";
            camo = "RGR";
            type = "NoFlag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_mcam) {
            model = QGVAR(AVSCarrier);
            cut = "Orig";
            camo = "MTP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_tna) {
            model = QGVAR(AVSCarrier);
            cut = "Orig";
            camo = "TNA";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_wdl) {
            model = QGVAR(AVSCarrier);
            cut = "Orig";
            camo = "WDL";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_ocp) {
            model = QGVAR(AVSCarrier);
            cut = "Orig";
            camo = "OCP";
            type = "Flag";
        };
        /* ---- JAM SOF's reworked AVS, added by the mod on 31 August ----
           The mod's own classes, not ours: three new p3ds, and no
           XtdGear of their own. 25 vests, one arsenal entry. */
        class GVAR(SOF_V_AVSCarrier_Lite_new_rgr) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "RGR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_mcam) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "MTP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_ocp) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "OCP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_tna) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "TNA";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_wdl) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "WDL";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_blk) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "BLK";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_cbr) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "CBR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Lite_new_snd) {
            model = QGVAR(AVSCarrier);
            cut = "Lite";
            camo = "SND";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_rgr) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "RGR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_mcam) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "MTP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_ocp) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "OCP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_tna) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "TNA";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_wdl) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "WDL";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_blk) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "BLK";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_cbr) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "CBR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_snd) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "SND";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_rgr_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "RGR";
            type = "NoFlag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_mcam_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "MTP";
            type = "NoFlag";
        };
        class GVAR(SOF_V_AVSCarrier_Rifle_new_ocp_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Rifle";
            camo = "OCP";
            type = "NoFlag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_rgr) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "RGR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_mcam) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "MTP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_ocp) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "OCP";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_tna) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "TNA";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_wdl) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "WDL";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_blk) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "BLK";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_cbr) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "CBR";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_snd) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "SND";
            type = "Flag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_rgr_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "RGR";
            type = "NoFlag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_mcam_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "MTP";
            type = "NoFlag";
        };
        class GVAR(SOF_V_AVSCarrier_Gunner_new_ocp_noflag) {
            model = QGVAR(AVSCarrier);
            cut = "Gunner";
            camo = "OCP";
            type = "NoFlag";
        };
        class GVAR(SOF_V_CHPCCarrier_Lite_khk) {
            model = QGVAR(CHPCCarrier);
            cut = "Lite";
            camo = "KHK";
        };
        class GVAR(SOF_V_CHPCCarrier_Lite_blk) {
            model = QGVAR(CHPCCarrier);
            cut = "Lite";
            camo = "BLK";
        };
        class GVAR(SOF_V_CHPCCarrier_Lite_oli) {
            model = QGVAR(CHPCCarrier);
            cut = "Lite";
            camo = "OLI";
        };
        class GVAR(SOF_V_CHPCCarrier_Lite_hex) {
            model = QGVAR(CHPCCarrier);
            cut = "Lite";
            camo = "HEX";
        };
        class GVAR(SOF_V_CHPCCarrier_Lite_ghex) {
            model = QGVAR(CHPCCarrier);
            cut = "Lite";
            camo = "GHEX";
        };
        class GVAR(SOF_V_CHPCCarrier_SMG_khk) {
            model = QGVAR(CHPCCarrier);
            cut = "SMG";
            camo = "KHK";
        };
        class GVAR(SOF_V_CHPCCarrier_SMG_blk) {
            model = QGVAR(CHPCCarrier);
            cut = "SMG";
            camo = "BLK";
        };
        class GVAR(SOF_V_CHPCCarrier_SMG_oli) {
            model = QGVAR(CHPCCarrier);
            cut = "SMG";
            camo = "OLI";
        };
        class GVAR(SOF_V_CHPCCarrier_SMG_hex) {
            model = QGVAR(CHPCCarrier);
            cut = "SMG";
            camo = "HEX";
        };
        class GVAR(SOF_V_CHPCCarrier_SMG_ghex) {
            model = QGVAR(CHPCCarrier);
            cut = "SMG";
            camo = "GHEX";
        };
        class GVAR(SOF_V_CHPCCarrier_Rig_khk) {
            model = QGVAR(CHPCCarrier);
            cut = "Rig";
            camo = "KHK";
        };
        class GVAR(SOF_V_CHPCCarrier_Rig_blk) {
            model = QGVAR(CHPCCarrier);
            cut = "Rig";
            camo = "BLK";
        };
        class GVAR(SOF_V_CHPCCarrier_Rig_oli) {
            model = QGVAR(CHPCCarrier);
            cut = "Rig";
            camo = "OLI";
        };
        class GVAR(SOF_V_CHPCCarrier_Rig_hex) {
            model = QGVAR(CHPCCarrier);
            cut = "Rig";
            camo = "HEX";
        };
        class GVAR(SOF_V_CHPCCarrier_Rig_ghex) {
            model = QGVAR(CHPCCarrier);
            cut = "Rig";
            camo = "GHEX";
        };
        class GVAR(SOF_V_CHPCCarrier_Gunner_khk) {
            model = QGVAR(CHPCCarrier);
            cut = "Gunner";
            camo = "KHK";
        };
        class GVAR(SOF_V_CHPCCarrier_Gunner_blk) {
            model = QGVAR(CHPCCarrier);
            cut = "Gunner";
            camo = "BLK";
        };
        class GVAR(SOF_V_CHPCCarrier_Gunner_oli) {
            model = QGVAR(CHPCCarrier);
            cut = "Gunner";
            camo = "OLI";
        };
        class GVAR(SOF_V_CHPCCarrier_Gunner_hex) {
            model = QGVAR(CHPCCarrier);
            cut = "Gunner";
            camo = "HEX";
        };
        class GVAR(SOF_V_CHPCCarrier_Gunner_ghex) {
            model = QGVAR(CHPCCarrier);
            cut = "Gunner";
            camo = "GHEX";
        };
    };
};
