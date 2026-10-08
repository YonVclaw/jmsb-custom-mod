class CfgWeapons {
#include "acp_full_externs.hpp"
    // real root ItemInfo lives in jmfsb_main; extern so nested
    // `class ItemInfo: ItemInfo` resolves (HEMTT L-C04)
#include "imported_CfgWeapons_decl.hpp"
    class ItemInfo;

    /* JSOC Stealth - Plain */
    class GVAR(U_B_JSOC_StealthUniform_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_JSOC_StealthUniform_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_JSOC_StealthUniform_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_B_JSOC_StealthUniform_RolledUp_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Rolled Up)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_JSOC_StealthUniform_RolledUp_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_JSOC_StealthUniform_RolledUp_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    /* JSOC Stealth - Desert */
    class GVAR(U_B_D_JSOC_StealthUniform_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Desert)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_D_JSOC_StealthUniform_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_des_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_D_JSOC_StealthUniform_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_B_D_JSOC_StealthUniform_RolledUp_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Desert, Rolled Up)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_D_JSOC_StealthUniform_RolledUp_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_des_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_D_JSOC_StealthUniform_RolledUp_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    /* JSOC Stealth - Tropic */
    class GVAR(U_B_T_JSOC_StealthUniform_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Tropic)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_T_JSOC_StealthUniform_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_tna_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_T_JSOC_StealthUniform_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_B_T_JSOC_StealthUniform_RolledUp_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Tropic, Rolled Up)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_T_JSOC_StealthUniform_RolledUp_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_tna_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_T_JSOC_StealthUniform_RolledUp_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    /* JSOC Stealth - Woodland */
    class GVAR(U_B_W_JSOC_StealthUniform_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Woodland)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_W_JSOC_StealthUniform_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_wdl_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_W_JSOC_StealthUniform_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_B_W_JSOC_StealthUniform_RolledUp_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Woodland, Rolled Up)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_W_JSOC_StealthUniform_RolledUp_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_wdl_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_W_JSOC_StealthUniform_RolledUp_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    /* JSOC Stealth - OCP */
    class GVAR(U_B_OCP_JSOC_StealthUniform_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (OCP)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_D_JSOC_StealthUniform_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_ocp_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_OCP_JSOC_StealthUniform_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_B_OCP_JSOC_StealthUniform_RolledUp_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (OCP, Rolled Up)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_D_JSOC_StealthUniform_RolledUp_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_ocp_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_OCP_JSOC_StealthUniform_RolledUp_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    /* JSOC Stealth - Snow */
    class GVAR(U_B_Snow_JSOC_StealthUniform_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Snow)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_JSOC_StealthUniform_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_snow_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_Snow_JSOC_StealthUniform_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_B_Snow_JSOC_StealthUniform_RolledUp_F): Uniform_Base {        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Snow, Rolled Up)";
        picture = QPATHTOF(data\ui\icon_Atlas_U_B_JSOC_StealthUniform_RolledUp_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_snow_co.paa)};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(B_Snow_JSOC_StealthUniform_RolledUp_soldier_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };

#include "acp_ocp_weapons.hpp"
#include "acp_snow_weapons.hpp"
#include "imported_CfgWeapons.hpp"
};
