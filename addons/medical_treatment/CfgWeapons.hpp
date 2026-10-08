class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;
    class JMFSB_apap: ACE_ItemCore {
        scope = 2;
        scopeCurator = 2;
        author = "ArmaForces";
        displayName = "Apap pastille";
        descriptionShort = "Used to combat light pain experiences. No side effects.";
        descriptionUse = "Take orally to combat light pain. No side effects.";
        picture = QPATHTOF(ui\icons\apap.paa);

        model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";

        ACE_isMedicalItem = 1;

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        };
    };
    class ACE_fieldDressing : ACE_ItemCore {
        scope=2;
        picture="\z\jmfsb\addons\media\images\Icons\IB.paa";
        displayName="Trauma Dressing";
        descriptionShort="Quickly stanches haemorrhaging from injuries";
        descriptionUse="Quickly stanches haemorrhaging from injuries";
    };
    class ACE_quikclot : ACE_ItemCore {
        scope=2;
        displayName="Quikclot Combat Gauze";
        picture="\z\jmfsb\addons\media\images\Icons\Quikclot.paa";
    };
    class ACE_morphine : ACE_ItemCore {
        scope=2;
        displayName="Morphine autoinjector 10mg/1mL";
        descriptionShort="Analgesic, used for moderate pain";
        descriptionUse="Analgesic, used for moderate pain";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
    class ACE_epinephrine : ACE_ItemCore {
        scope=2;
        displayName="Adrenaline autoinjector 1mg/1mL";
        descriptionShort="Sympathomimetic, increases HR, bronchodilation and vasoconstriction";
        descriptionUse="Sympathomimetic, increases HR, bronchodilation and vasoconstriction";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
};
