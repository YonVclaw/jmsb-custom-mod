// The protection blocks live in jmfsb_main's script_macros.hpp, shared with every
// other carrier jmfsb ports (vests_mig); only the mass is this addon's own.
#define JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO \
    class ItemInfo: ItemInfo { \
        mass = 60; \
        JMFSB_PLATE_CARRIER_STANDARD_PROTECTION \
    };

#define JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO \
    class ItemInfo: ItemInfo { \
        mass = 85; \
        JMFSB_PLATE_CARRIER_HEAVY_PROTECTION \
    };

// Vanilla-defined plate carriers only. The Aegis and Western Sahara carriers are
// not patched since vests_aegis and vests_ws were retired (2026-10-07).
// Every class MUST restate its original parent: a parentless patch strips
// the base class ("Updating base class X->") and breaks the vest.
class CfgWeapons {
#include "imported_CfgWeapons_decl.hpp"
    class Vest_Camo_Base;
    class ItemInfo; // defined for real in jmfsb_main (see its CfgWeapons.hpp)

    class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier1_blk: Vest_Camo_Base {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier1_rgr_noflag_F: V_PlateCarrier1_rgr {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier1_tna_F: V_PlateCarrier1_blk {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier1_wdl: V_PlateCarrier1_blk {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier2_blk: V_PlateCarrier2_rgr {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier2_rgr_noflag_F: V_PlateCarrier2_rgr {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier2_tna_F: V_PlateCarrier2_blk {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrier2_wdl: V_PlateCarrier2_blk {
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierGL_rgr: Vest_NoCamo_Base {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierGL_blk: V_PlateCarrierGL_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierGL_mtp: V_PlateCarrierGL_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierGL_tna_F: V_PlateCarrierGL_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierGL_wdl: V_PlateCarrierGL_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierSpec_rgr: Vest_NoCamo_Base {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierSpec_blk: V_PlateCarrierSpec_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierSpec_mtp: V_PlateCarrierSpec_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierSpec_tna_F: V_PlateCarrierSpec_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };
    class V_PlateCarrierSpec_wdl: V_PlateCarrierSpec_rgr {
        JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
    };

    // ===== ACP retextures (textures from Ample Camo Pack, author Seb) =====
    class GVAR(V_PlateCarrier1_ocp): V_PlateCarrier1_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_ocp_co.paa)};
    };
    class GVAR(V_PlateCarrier1_mtp): V_PlateCarrier1_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Rig (MTP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mtp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mtp_co.paa)};
    };
    class GVAR(V_PlateCarrier1_mcam): V_PlateCarrier1_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Rig (Multicam)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mcam.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_co.paa)};
    };
    class GVAR(V_PlateCarrier1_mcam_wdl): V_PlateCarrier1_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Rig (Multicam Woodland)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mcam_wdl.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_wdl_co.paa)};
    };
    class GVAR(V_PlateCarrier1_mcam_snow): V_PlateCarrier1_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Rig (Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mcam_snow.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_snow_co.paa)};
    };
    class GVAR(V_PlateCarrier2_ocp): V_PlateCarrier2_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Lite (OCP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_ocp_co.paa)};
    };
    class GVAR(V_PlateCarrier2_mtp): V_PlateCarrier2_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Lite (MTP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mtp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mtp_co.paa)};
    };
    class GVAR(V_PlateCarrier2_mcam): V_PlateCarrier2_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Lite (Multicam)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mcam.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_co.paa)};
    };
    class GVAR(V_PlateCarrier2_mcam_wdl): V_PlateCarrier2_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Lite (Multicam Woodland)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mcam_wdl.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_wdl_co.paa)};
    };
    class GVAR(V_PlateCarrier2_mcam_snow): V_PlateCarrier2_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Lite (Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mcam_snow.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_snow_co.paa)};
    };
    class GVAR(V_PlateCarrierGL_ocp): V_PlateCarrierGL_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier GL Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrier_gl_rig_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_ocp.paa)};
    };
    class GVAR(V_PlateCarrierGL_mtp): V_PlateCarrierGL_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier GL Rig (MTP)";
        picture = QPATHTOF(data\ui\icon_carrier_gl_rig_mtp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mtp.paa)};
    };
    class GVAR(V_PlateCarrierGL_mcam): V_PlateCarrierGL_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier GL Rig (Multicam)";
        picture = QPATHTOF(data\ui\icon_carrier_gl_rig_mcam.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mcam.paa)};
    };
    class GVAR(V_PlateCarrierGL_mcam_wdl): V_PlateCarrierGL_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier GL Rig (Multicam Woodland)";
        picture = QPATHTOF(data\ui\icon_carrier_gl_rig_mcam_wdl.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mcam_wdl.paa)};
    };
    class GVAR(V_PlateCarrierGL_mcam_snow): V_PlateCarrierGL_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier GL Rig (Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_carrier_gl_rig_mcam_snow.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mcam_snow.paa)};
    };
    class GVAR(V_PlateCarrierSpec_ocp): V_PlateCarrierSpec_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Special Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrier_spec_rig_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_ocp.paa)};
    };
    class GVAR(V_PlateCarrierSpec_mtp): V_PlateCarrierSpec_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Special Rig (MTP)";
        picture = QPATHTOF(data\ui\icon_carrier_spec_rig_mtp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mtp.paa)};
    };
    class GVAR(V_PlateCarrierSpec_mcam): V_PlateCarrierSpec_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Special Rig (Multicam)";
        picture = QPATHTOF(data\ui\icon_carrier_spec_rig_mcam.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mcam.paa)};
    };
    class GVAR(V_PlateCarrierSpec_mcam_wdl): V_PlateCarrierSpec_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Special Rig (Multicam Woodland)";
        picture = QPATHTOF(data\ui\icon_carrier_spec_rig_mcam_wdl.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mcam_wdl.paa)};
    };
    class GVAR(V_PlateCarrierSpec_mcam_snow): V_PlateCarrierSpec_blk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] Carrier Special Rig (Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_carrier_spec_rig_mcam_snow.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrier_gl_rig_mcam_snow.paa)};
    };

    // ===== CTRG plate carriers (share PlateCarrier1/2 UV; ACP vests texture) =====
    class V_PlateCarrierL_CTRG;
    class V_PlateCarrierH_CTRG;
    class GVAR(V_PlateCarrierL_CTRG_ocp): V_PlateCarrierL_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Light, OCP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_ocp_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierL_CTRG_mtp): V_PlateCarrierL_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Light, MTP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mtp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mtp_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierL_CTRG_mcam): V_PlateCarrierL_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Light, Multicam)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mcam.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierL_CTRG_mcam_wdl): V_PlateCarrierL_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Light, Multicam Woodland)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mcam_wdl.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_wdl_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierL_CTRG_mcam_snow): V_PlateCarrierL_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Light, Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_1_mcam_snow.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_snow_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierL_CTRG_tna): V_PlateCarrierL_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Light, Tropic)";
        // vanilla Apex tropic carrier art -- there is no jmfsb tropic vest
        // texture, and the CTRG rigs share the PlateCarrier1 UV
        picture = "\A3\Characters_F_Exp\Vests\Data\UI\icon_V_PlateCarrier1_tna_F_ca.paa";
        hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Vests\Data\V_PlateCarrier1_tna_F_co.paa"};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierH_CTRG_ocp): V_PlateCarrierH_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Heavy, OCP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_ocp_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierH_CTRG_mtp): V_PlateCarrierH_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Heavy, MTP)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mtp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mtp_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierH_CTRG_mcam): V_PlateCarrierH_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Heavy, Multicam)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mcam.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierH_CTRG_mcam_wdl): V_PlateCarrierH_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Heavy, Multicam Woodland)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mcam_wdl.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_wdl_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierH_CTRG_mcam_snow): V_PlateCarrierH_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Heavy, Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_v_plate_carrier_2_mcam_snow.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\vests_mcam_snow_co.paa)};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
    class GVAR(V_PlateCarrierH_CTRG_tna): V_PlateCarrierH_CTRG {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[JMSB] CTRG Plate Carrier Rig (Heavy, Tropic)";
        // vanilla Apex tropic carrier art -- there is no jmfsb tropic vest
        // texture, and the CTRG rigs share the PlateCarrier1 UV
        picture = "\A3\Characters_F_Exp\Vests\Data\UI\icon_V_PlateCarrier1_tna_F_ca.paa";
        hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Vests\Data\V_PlateCarrier1_tna_F_co.paa"};
        JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
    };
#include "imported_CfgWeapons.hpp"
};

#undef JMFSB_STANDARD_PLATE_CARRIER_ITEMINFO
#undef JMFSB_HEAVY_PLATE_CARRIER_ITEMINFO
