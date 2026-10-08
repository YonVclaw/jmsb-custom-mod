class CfgWeapons {
    class CBA_MiscItem;
    class CBA_MiscItem_ItemInfo;
    class ACE_ItemCore: CBA_MiscItem {};
    class GVAR(vs17): ACE_ItemCore {
        author = QAUTHOR;
        scope=2;
        displayName = "VS-17 Marker Panel";
        displayNameShort = "VS-17";
        picture = QPATHTOF(data\vs_yellow.paa);
        model = "\A3\Structures_F\Civ\Camping\Ground_sheet_folded_yellow_F.p3d";
        editorPreview = QPATHTOF(data\vs_yellow.paa);
        icon = "iconObject_1x1";
        mapSize = 0.015;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        };
    };
    
};
