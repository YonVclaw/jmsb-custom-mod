// THE BALACLAVAS ARE FACEWEAR. G_Balaclava_blk lives in CfgGlasses, and so
// must anything that inherits from it. These two sat in CfgWeapons with a
// "class G_Balaclava_blk;" forward declaration there, which conjured an
// empty WEAPON of that name: every unit wearing the vanilla balaclava then
// logged "creating weapon G_Balaclava_blk with scope=private" and three
// No-entry lines. Same classes, same names; only the root changed.
class CfgGlasses {
    class G_Balaclava_blk;
    class GVAR(G_Balaclava_US_OCP): G_Balaclava_blk {
        author = QAUTHOR;
        displayName = "[JMSB] Balaclava (OCP)";
        picture = QPATHTOF(data\ui\icon_G_Balaclava_US_OCP_ca.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\headgear_balaclava_US_OCP_co.paa)};
        MACRO_ITEM_COMMON
    };
    class GVAR(G_Balaclava_Multicam_Snow): G_Balaclava_blk {
        author = QAUTHOR;
        displayName = "[JMSB] Balaclava (Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_G_Balaclava_Multicam_Snow_ca.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\headgear_balaclava_Multicam_Snow_co.paa)};
        MACRO_ITEM_COMMON
    };
};
