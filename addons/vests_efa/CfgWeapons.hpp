#define JMFSB_STANDARD_VEST_ITEMINFO \
    class ItemInfo: ItemInfo { \
        class HitpointsProtectionInfo { \
            class Neck { \
                hitpointName = "HitNeck"; \
                armor = 8; \
                passThrough = 0.3; \
            }; \
            class Chest { \
                hitpointName = "HitChest"; \
                armor = 29; \
                passThrough = 0.085; \
            }; \
            class Body { \
                hitpointName = "HitBody"; \
                passThrough = 0.085; \
            }; \
            class Diaphragm { \
                hitpointName = "HitDiaphragm"; \
                armor = 29; \
                passThrough = 0.085; \
            }; \
            class Abdomen { \
                hitpointName = "HitAbdomen"; \
                armor = 19; \
                passThrough = 0.255; \
            }; \
            class Pelvis { \
                hitpointName = "HitPelvis"; \
                armor = 19; \
                passThrough = 0.255; \
            }; \
            class Arms { \
                hitpointName = "HitArms"; \
                armor = 12; \
                passThrough = 0.55; \
            }; \
            class Legs { \
                hitpointName = "HitLegs"; \
                armor = 12; \
                passThrough = 0.55; \
            }; \
        }; \
    };

#define JMFSB_HEAVY_VEST_ITEMINFO \
    class ItemInfo: ItemInfo { \
        class HitpointsProtectionInfo { \
            class Neck { \
                hitpointName = "HitNeck"; \
                armor = 10; \
                passThrough = 0.25; \
            }; \
            class Chest { \
                hitpointName = "HitChest"; \
                armor = 34; \
                passThrough = 0.06; \
            }; \
            class Body { \
                hitpointName = "HitBody"; \
                passThrough = 0.06; \
            }; \
            class Diaphragm { \
                hitpointName = "HitDiaphragm"; \
                armor = 34; \
                passThrough = 0.06; \
            }; \
            class Abdomen { \
                hitpointName = "HitAbdomen"; \
                armor = 24; \
                passThrough = 0.21; \
            }; \
            class Pelvis { \
                hitpointName = "HitPelvis"; \
                armor = 24; \
                passThrough = 0.21; \
            }; \
            class Arms { \
                hitpointName = "HitArms"; \
                armor = 14; \
                passThrough = 0.5; \
            }; \
            class Legs { \
                hitpointName = "HitLegs"; \
                armor = 14; \
                passThrough = 0.5; \
            }; \
        }; \
    };

class CfgWeapons {
    class ItemInfo; // defined for real in jmfsb_main (see its CfgWeapons.hpp)
    class EF_V_AAV_Black;
    class EF_V_AAV_Diver_Black;
    class EF_V_AAV_Diver_Alt_Black;
    class EF_V_AAV_Diver_NoReb_Black;
    class EF_V_AAV_Diver_NoReb_Alt_Black;
    class EF_V_AAV_Rifleman_Black;
    class EF_V_AAV_Rifleman_Alt_Black;
    class EF_V_AAV_Sailor_Black;
    class EF_V_AAV_Sailor_Alt_Black;
    class EF_V_AAV_Scout_Black;
    class EF_V_AAV_Scout_Alt_Black;
    class EF_V_AAV_Support_Black;
    class EF_V_AAV_TL_Black;
    class EF_V_AAV_TL_Alt_Black;
    class EF_V_AAV_Coy;
    class EF_V_AAV_Diver_Coy;
    class EF_V_AAV_Diver_NoReb_Coy;
    class EF_V_AAV_Diver_NoReb_Alt_Coy;
    class EF_V_AAV_Rifleman_Coy;
    class EF_V_AAV_Rifleman_Alt_Coy;
    class EF_V_AAV_Sailor_Coy;
    class EF_V_AAV_Sailor_Alt_Coy;
    class EF_V_AAV_Scout_Coy;
    class EF_V_AAV_Scout_Alt_Coy;
    class EF_V_AAV_Support_Coy;
    class EF_V_AAV_TL_Coy;
    class EF_V_AAV_TL_Alt_Coy;
    class EFA_V_AAV_des;
    class EFA_V_AAV_Diver_des;
    class EFA_V_AAV_Diver_Alt_des;
    class EFA_V_AAV_Diver_NoReb_des;
    class EFA_V_AAV_Diver_NoReb_Alt_des;
    class EFA_V_AAV_Rifleman_des;
    class EFA_V_AAV_Rifleman_Alt_des;
    class EFA_V_AAV_Sailor_des;
    class EFA_V_AAV_Sailor_Alt_des;
    class EFA_V_AAV_Scout_DES;
    class EFA_V_AAV_Scout_Alt_DES;
    class EFA_V_AAV_Support_des;
    class EFA_V_AAV_TL_des;
    class EFA_V_AAV_TL_Alt_des;
    class EFA_V_AAV_tna;
    class EFA_V_AAV_Diver_tna;
    class EFA_V_AAV_Diver_Alt_tna;
    class EFA_V_AAV_Diver_NoReb_Alt_tna;
    class EFA_V_AAV_Rifleman_tna;
    class EFA_V_AAV_Rifleman_Alt_tna;
    class EFA_V_AAV_Sailor_tna;
    class EFA_V_AAV_Sailor_Alt_tna;
    class EFA_V_AAV_Scout_tna;
    class EFA_V_AAV_Scout_Alt_tna;
    class EFA_V_AAV_Support_tna;
    class EFA_V_AAV_TL_tna;
    class EFA_V_AAV_TL_Alt_tna;
    class EFA_V_AAV_wdl;
    class EFA_V_AAV_Diver_wdl;
    class EFA_V_AAV_Diver_Alt_wdl;
    class EFA_V_AAV_Diver_NoReb_wdl;
    class EFA_V_AAV_Diver_NoReb_Alt_wdl;
    class EFA_V_AAV_Rifleman_wdl;
    class EFA_V_AAV_Rifleman_Alt_wdl;
    class EFA_V_AAV_Sailor_wdl;
    class EFA_V_AAV_Sailor_Alt_wdl;
    class EFA_V_AAV_Scout_wdl;
    class EFA_V_AAV_Scout_Alt_wdl;
    class EFA_V_AAV_Support_wdl;
    class EFA_V_AAV_TL_wdl;
    class EFA_V_AAV_Diver_Alt_MTP;
    class EFA_V_AAV_Diver_NoReb_MTP;
    class EFA_V_AAV_Diver_NoReb_Alt_MTP;
    class EFA_V_AAV_Rifleman_Alt_MTP;
    class EFA_V_AAV_Sailor_Alt_MTP;
    class EFA_V_AAV_Scout_Alt_MTP;
    class EFA_V_AAV_TL_Alt_MTP;
    class EFA_V_AAV_MTP;
    class EFA_V_AAV_Diver_MTP;
    class EFA_V_AAV_Rifleman_MTP;
    class EFA_V_AAV_Sailor_MTP;
    class EFA_V_AAV_Scout_MTP;
    class EFA_V_AAV_Support_MTP;
    class EFA_V_AAV_TL_MTP;
    class EF_V_AAV_Olive;
    class EF_V_AAV_Diver_Olive;
    class EF_V_AAV_Diver_Alt_Olive;
    class EF_V_AAV_Diver_NoReb_Olive;
    class EF_V_AAV_Diver_NoReb_Alt_Olive;
    class EF_V_AAV_Rifleman_Olive;
    class EF_V_AAV_Rifleman_Alt_Olive;
    class EF_V_AAV_Sailor_Olive;
    class EF_V_AAV_Sailor_Alt_Olive;
    class EF_V_AAV_Scout_Alt_Olive;
    class EF_V_AAV_Support_Olive;
    class EF_V_AAV_TL_Olive;
    class EF_V_AAV_TL_Alt_Olive;
    class EF_V_CCR_Rifleman_Black;
    class EF_V_CCR_Rifleman_Alt_Black;
    class EF_V_CCR_Scout_Black;
    class EF_V_CCR_Scout_Alt_Black;
    class EF_V_CCR_Support_Black;
    class EF_V_CCR_TL_Black;
    class EF_V_CCR_TL_Alt_Black;
    class EF_V_CCR_Rifleman_Coy;
    class EF_V_CCR_Rifleman_Alt_Coy;
    class EF_V_CCR_Scout_Coy;
    class EF_V_CCR_Scout_Alt_Coy;
    class EF_V_CCR_Support_Coy;
    class EF_V_CCR_TL_Coy;
    class EF_V_CCR_TL_Alt_Coy;
    class EFA_V_CCR_Rifleman_des;
    class EFA_V_CCR_Rifleman_Alt_des;
    class EFA_V_CCR_Scout_des;
    class EFA_V_CCR_Scout_Alt_des;
    class EFA_V_CCR_Support_des;
    class EFA_V_CCR_TL_Alt_des;
    class EFA_V_CCR_Rifleman_tna;
    class EFA_V_CCR_Rifleman_Alt_tna;
    class EFA_V_CCR_Scout_tna;
    class EFA_V_CCR_Scout_Alt_tna;
    class EFA_V_CCR_Support_tna;
    class EFA_V_CCR_TL_tna;
    class EFA_V_CCR_TL_Alt_tna;
    class EFA_V_CCR_Rifleman_wdl;
    class EFA_V_CCR_Rifleman_Alt_wdl;
    class EFA_V_CCR_Scout_wdl;
    class EFA_V_CCR_Scout_Alt_wdl;
    class EFA_V_CCR_Support_wdl;
    class EFA_V_CCR_TL_wdl;
    class EFA_V_CCR_TL_Alt_wdl;
    class EFA_V_CCR_Rifleman_Alt_MTP;
    class EFA_V_CCR_Scout_Alt_MTP;
    class EFA_V_CCR_TL_Alt_MTP;
    class EFA_V_CCR_Rifleman_MTP;
    class EFA_V_CCR_Scout_MTP;
    class EFA_V_CCR_Support_MTP;
    class EFA_V_CCR_TL_MTP;
    class EF_V_CCR_Rifleman_Olive;
    class EF_V_CCR_Scout_Olive;
    class EF_V_CCR_Scout_Alt_Olive;
    class EF_V_CCR_Support_Olive;
    class EF_V_CCR_TL_Olive;
    class EF_V_CCR_TL_Alt_Olive;
    class EF_V_CCR_Rifleman_Alt_Olive;
    class EFA_V_CCR_TL_des;
    class EF_V_AAV_Scout_Olive;
    class EFA_V_AAV_TL_Alt_wdl;
    class EFA_V_AAV_Diver_NoReb_tna;
    class EF_V_AAV_Diver_Alt_Coy;

    class GVAR(EF_V_AAV_Black): EF_V_AAV_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_Black): EF_V_AAV_Diver_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_Alt_Black): EF_V_AAV_Diver_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_NoReb_Black): EF_V_AAV_Diver_NoReb_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_NoReb_Alt_Black): EF_V_AAV_Diver_NoReb_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Rifleman_Black): EF_V_AAV_Rifleman_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Rifleman_Alt_Black): EF_V_AAV_Rifleman_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Sailor_Black): EF_V_AAV_Sailor_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Sailor_Alt_Black): EF_V_AAV_Sailor_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Scout_Black): EF_V_AAV_Scout_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Scout_Alt_Black): EF_V_AAV_Scout_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Support_Black): EF_V_AAV_Support_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_TL_Black): EF_V_AAV_TL_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_TL_Alt_Black): EF_V_AAV_TL_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Black/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Coy): EF_V_AAV_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_Coy): EF_V_AAV_Diver_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_NoReb_Coy): EF_V_AAV_Diver_NoReb_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_NoReb_Alt_Coy): EF_V_AAV_Diver_NoReb_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote Brown/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Rifleman_Coy): EF_V_AAV_Rifleman_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Rifleman_Alt_Coy): EF_V_AAV_Rifleman_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote Brown/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Sailor_Coy): EF_V_AAV_Sailor_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Sailor_Alt_Coy): EF_V_AAV_Sailor_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote Brown/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Scout_Coy): EF_V_AAV_Scout_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Scout_Alt_Coy): EF_V_AAV_Scout_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote Brown/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Support_Coy): EF_V_AAV_Support_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_TL_Coy): EF_V_AAV_TL_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_TL_Alt_Coy): EF_V_AAV_TL_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote Brown/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_des): EFA_V_AAV_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_des): EFA_V_AAV_Diver_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_Alt_des): EFA_V_AAV_Diver_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_des): EFA_V_AAV_Diver_NoReb_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_Alt_des): EFA_V_AAV_Diver_NoReb_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_des): EFA_V_AAV_Rifleman_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_Alt_des): EFA_V_AAV_Rifleman_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_des): EFA_V_AAV_Sailor_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_Alt_des): EFA_V_AAV_Sailor_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_DES): EFA_V_AAV_Scout_DES {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_Alt_DES): EFA_V_AAV_Scout_Alt_DES {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Support_des): EFA_V_AAV_Support_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_des): EFA_V_AAV_TL_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_Alt_des): EFA_V_AAV_TL_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Desert/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_tna): EFA_V_AAV_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_tna): EFA_V_AAV_Diver_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_Alt_tna): EFA_V_AAV_Diver_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_Alt_tna): EFA_V_AAV_Diver_NoReb_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_tna): EFA_V_AAV_Rifleman_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_Alt_tna): EFA_V_AAV_Rifleman_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_tna): EFA_V_AAV_Sailor_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_Alt_tna): EFA_V_AAV_Sailor_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_tna): EFA_V_AAV_Scout_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_Alt_tna): EFA_V_AAV_Scout_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Support_tna): EFA_V_AAV_Support_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_tna): EFA_V_AAV_TL_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_Alt_tna): EFA_V_AAV_TL_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_wdl): EFA_V_AAV_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_wdl): EFA_V_AAV_Diver_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_Alt_wdl): EFA_V_AAV_Diver_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_wdl): EFA_V_AAV_Diver_NoReb_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_Alt_wdl): EFA_V_AAV_Diver_NoReb_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_wdl): EFA_V_AAV_Rifleman_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_Alt_wdl): EFA_V_AAV_Rifleman_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_wdl): EFA_V_AAV_Sailor_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_Alt_wdl): EFA_V_AAV_Sailor_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_wdl): EFA_V_AAV_Scout_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_Alt_wdl): EFA_V_AAV_Scout_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Support_wdl): EFA_V_AAV_Support_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_wdl): EFA_V_AAV_TL_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_Alt_MTP): EFA_V_AAV_Diver_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_MTP): EFA_V_AAV_Diver_NoReb_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_Alt_MTP): EFA_V_AAV_Diver_NoReb_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_Alt_MTP): EFA_V_AAV_Rifleman_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_Alt_MTP): EFA_V_AAV_Sailor_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_Alt_MTP): EFA_V_AAV_Scout_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_Alt_MTP): EFA_V_AAV_TL_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_MTP): EFA_V_AAV_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_MTP): EFA_V_AAV_Diver_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Rifleman_MTP): EFA_V_AAV_Rifleman_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Sailor_MTP): EFA_V_AAV_Sailor_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Scout_MTP): EFA_V_AAV_Scout_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Support_MTP): EFA_V_AAV_Support_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_MTP): EFA_V_AAV_TL_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (MTP/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Olive): EF_V_AAV_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_Olive): EF_V_AAV_Diver_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Diver)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_Alt_Olive): EF_V_AAV_Diver_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_NoReb_Olive): EF_V_AAV_Diver_NoReb_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_NoReb_Alt_Olive): EF_V_AAV_Diver_NoReb_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Diver/No Rebreather/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Rifleman_Olive): EF_V_AAV_Rifleman_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Rifleman_Alt_Olive): EF_V_AAV_Rifleman_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Sailor_Olive): EF_V_AAV_Sailor_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Sailor)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Sailor_Alt_Olive): EF_V_AAV_Sailor_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Sailor/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Scout_Alt_Olive): EF_V_AAV_Scout_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Support_Olive): EF_V_AAV_Support_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_TL_Olive): EF_V_AAV_TL_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_TL_Alt_Olive): EF_V_AAV_TL_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Rifleman_Black): EF_V_CCR_Rifleman_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Rifleman_Alt_Black): EF_V_CCR_Rifleman_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Scout_Black): EF_V_CCR_Scout_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Scout_Alt_Black): EF_V_CCR_Scout_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Support_Black): EF_V_CCR_Support_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_TL_Black): EF_V_CCR_TL_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_TL_Alt_Black): EF_V_CCR_TL_Alt_Black {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Black/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Rifleman_Coy): EF_V_CCR_Rifleman_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Rifleman_Alt_Coy): EF_V_CCR_Rifleman_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote Brown/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Scout_Coy): EF_V_CCR_Scout_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Scout_Alt_Coy): EF_V_CCR_Scout_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote Brown/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Support_Coy): EF_V_CCR_Support_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_TL_Coy): EF_V_CCR_TL_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_TL_Alt_Coy): EF_V_CCR_TL_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Coyote Brown/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_des): EFA_V_CCR_Rifleman_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_Alt_des): EFA_V_CCR_Rifleman_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_des): EFA_V_CCR_Scout_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_Alt_des): EFA_V_CCR_Scout_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Support_des): EFA_V_CCR_Support_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_Alt_des): EFA_V_CCR_TL_Alt_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_tna): EFA_V_CCR_Rifleman_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_Alt_tna): EFA_V_CCR_Rifleman_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_tna): EFA_V_CCR_Scout_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_Alt_tna): EFA_V_CCR_Scout_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Support_tna): EFA_V_CCR_Support_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_tna): EFA_V_CCR_TL_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_Alt_tna): EFA_V_CCR_TL_Alt_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Tropic/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_wdl): EFA_V_CCR_Rifleman_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_Alt_wdl): EFA_V_CCR_Rifleman_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_wdl): EFA_V_CCR_Scout_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_Alt_wdl): EFA_V_CCR_Scout_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Support_wdl): EFA_V_CCR_Support_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_wdl): EFA_V_CCR_TL_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_Alt_wdl): EFA_V_CCR_TL_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Woodland/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_Alt_MTP): EFA_V_CCR_Rifleman_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_Alt_MTP): EFA_V_CCR_Scout_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_Alt_MTP): EFA_V_CCR_TL_Alt_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Rifleman_MTP): EFA_V_CCR_Rifleman_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Scout_MTP): EFA_V_CCR_Scout_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_Support_MTP): EFA_V_CCR_Support_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_MTP): EFA_V_CCR_TL_MTP {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (MTP/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Rifleman_Olive): EF_V_CCR_Rifleman_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Rifleman)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Scout_Olive): EF_V_CCR_Scout_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Scout_Alt_Olive): EF_V_CCR_Scout_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Scout/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Support_Olive): EF_V_CCR_Support_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Support)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_TL_Olive): EF_V_CCR_TL_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_TL_Alt_Olive): EF_V_CCR_TL_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_CCR_Rifleman_Alt_Olive): EF_V_CCR_Rifleman_Alt_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Olive/Rifleman/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_CCR_TL_des): EFA_V_CCR_TL_des {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Commando Chest Rig (Desert/Team Leader)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Scout_Olive): EF_V_AAV_Scout_Olive {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Olive/Scout)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_TL_Alt_wdl): EFA_V_AAV_TL_Alt_wdl {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Woodland/Team Leader/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EFA_V_AAV_Diver_NoReb_tna): EFA_V_AAV_Diver_NoReb_tna {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Tropic/Diver/No Rebreather)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(EF_V_AAV_Diver_Alt_Coy): EF_V_AAV_Diver_Alt_Coy {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Amphibious Assault Vest (Coyote Brown/Diver/Alt)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
};

#undef JMFSB_STANDARD_VEST_ITEMINFO
#undef JMFSB_HEAVY_VEST_ITEMINFO
