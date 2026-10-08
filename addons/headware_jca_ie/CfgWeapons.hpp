#define JMFSB_HELMET_ITEMINFO \
    class ItemInfo: ItemInfo { \
        class HitpointsProtectionInfo { \
            class Head { \
                hitpointName = "HitHead"; \
                armor = 12; \
                passThrough = 0.35; \
            }; \
        }; \
    };

#define JMFSB_HELMET_CHOPS_ITEMINFO \
    class ItemInfo: ItemInfo { \
        class HitpointsProtectionInfo { \
            class Head { \
                hitpointName = "HitHead"; \
                armor = 12; \
                passThrough = 0.35; \
            }; \
            class Face { \
                hitpointName = "HitFace"; \
                armor = 6; \
                passThrough = 0.1; \
            }; \
        }; \
    };

class CfgWeapons {
    class ItemInfo; // defined for real in jmfsb_main (see its CfgWeapons.hpp)
    class HelmetBase;

    // ACE electronic hearing protection for all JCA HBK helmets: every variant
    // (and our jmfsb ones) inherits from this base, so one patch covers them.
    // Parent restated to avoid severing the inheritance chain.
    class JCA_H_HelmetHBK_base_F: HelmetBase {
        MACRO_ACE_HEARING
    };

    class JCA_H_HelmetHBK_black_F;
    class JCA_H_HelmetHBK_chops_black_F;
    class JCA_H_HelmetHBK_ear_black_F;
    class JCA_H_HelmetHBK_headset_black_F;
    class JCA_H_HelmetHBK_olive_F;
    class JCA_H_HelmetHBK_chops_olive_F;
    class JCA_H_HelmetHBK_headset_olive_F;
    class JCA_H_HelmetHBK_sand_F;
    class JCA_H_HelmetHBK_chops_sand_F;
    class JCA_H_HelmetHBK_ear_sand_F;
    class JCA_H_HelmetHBK_headset_sand_F;
    class JCA_H_HelmetHBK_ear_olive_F;

    class GVAR(JCA_H_HelmetHBK_black_F): JCA_H_HelmetHBK_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Black)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_chops_black_F): JCA_H_HelmetHBK_chops_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Black, Chops)";
        JMFSB_HELMET_CHOPS_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_ear_black_F): JCA_H_HelmetHBK_ear_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Black, Ear Protectors)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_headset_black_F): JCA_H_HelmetHBK_headset_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Black, Headset)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_olive_F): JCA_H_HelmetHBK_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Olive)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_chops_olive_F): JCA_H_HelmetHBK_chops_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Olive, Chops)";
        JMFSB_HELMET_CHOPS_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_headset_olive_F): JCA_H_HelmetHBK_headset_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Olive, Headset)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_sand_F): JCA_H_HelmetHBK_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Sand)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_chops_sand_F): JCA_H_HelmetHBK_chops_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Sand, Chops)";
        JMFSB_HELMET_CHOPS_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_ear_sand_F): JCA_H_HelmetHBK_ear_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Sand, Ear Protectors)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_headset_sand_F): JCA_H_HelmetHBK_headset_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Sand, Headset)";
        JMFSB_HELMET_ITEMINFO
    };
    class GVAR(JCA_H_HelmetHBK_ear_olive_F): JCA_H_HelmetHBK_ear_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Advanced Modular Helmet (Olive, Ear Protectors)";
        JMFSB_HELMET_ITEMINFO
    };
};

#undef JMFSB_HELMET_ITEMINFO
#undef JMFSB_HELMET_CHOPS_ITEMINFO
