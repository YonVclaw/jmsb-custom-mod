// ACP OCP uniforms -- included from CfgWeapons.hpp

    class GVAR(U_B_CombatUniform_ocp_F): U_B_CombatUniform_mcam {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] Combat Fatigues (OCP)";
        picture = QPATHTOF(data\ui\icon_U_B_CombatUniform_US_OCP_ca.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\clothing1_US_OCP.paa)};
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(B_CombatUniform_ocp_soldier_F);
        };
    };
