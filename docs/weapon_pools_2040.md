# Weapon Pools — 2040 Faction Builder

Structure: family → side/flavor, tier, caliber → role buckets (rifle / gl / carbine / ar / mg / dmr / shot / crew).
Selection: role picks bucket, tier filters families, weighted roll 60/30/10 toward own tier, caliber discipline none/squad/faction at tiers 0-1/2/3+.
Fallbacks: mg→ar→rifle · dmr→rifle(+optic) · shot→rifle · crew(smg)→carbine→rifle.
⚑ = unresolved, needs arsenal check.

## Caliber registry
| Caliber | Access | Notes |
|---|---|---|
| 6.5 (cased) | WEST only, tier 2+ | MX, XMS?, Promet |
| 6.5 caseless | WEST only, tier 3+ | same rifles, next-gen ammo line — the US edge |
| 6.2 | EAST/GUER, tier 2+ | conversion ledger below |
| 5.56 / 5.45 / 7.62x39 / 7.62x51 / 7.62x54R | free | legacy |
| .300 BLK, 12.7x55, .338, .50, .408, 9.3 | specialist | own supply lines, exempt from discipline |

## 6.2 conversion ledger (jmfsbfa config work)
1. FORT 651/652 — east tier 3
2. Katiba family — east tier 2
3. CMR-76 (DMR_07) — east tier 2
4. CAR-95 / CTAR — east tier 2 (or leave 5.8 legacy — decide)
5. Type 115 (ARX) — east specialist (primary barrel only)
6. G36 + G433 — ⚑ pending canon call: convert to 6.5 (true tier 3 blue) or stay 5.56 (high-tech ally, legacy caliber)

---

# WEST

## Tier 0
```
SLR:  7.62x51
  rifle:   [arifle_SLR_lxWS, arifle_SLR_V_lxWS, arifle_SLR_D_lxWS, arifle_SLR_V_camo_lxWS]
  gl:      [arifle_SLR_GL_lxWS, arifle_SLR_V_GL_lxWS]
  carbine: [arifle_SLR_Para_lxWS, arifle_SLR_Para_snake_lxWS]

CETME:  7.62x51
  rifle: [AddGis_arifle_CETME_F, AddGis_arifle_CETME_blk_F, AddGis_arifle_CETME_oli_F]

G3A3:  7.62x51
  rifle: [AddGis_arifle_G3A3_F, AddGis_arifle_G3A3_blk_F, AddGis_arifle_G3A3_ris_F,
          AddGis_arifle_G3A3_ris_blk_F, AddGis_arifle_G3A3_ris_fg_F, AddGis_arifle_G3A3_ris_fg_blk_F]

M16A2:  5.56
  rifle:   [AddGis_arifle_M16_A2_F]
  carbine: [AddGis_arifle_M16_Carbine_F]

FNMAG_old:  7.62x51
  mg: [Aegis_MMG_FNMAG_old_F]

Mk14:  7.62x51        // DMR_06
  dmr: [srifle_DMR_06_black_F, srifle_DMR_06_camo_F, srifle_DMR_06_olive_F, srifle_DMR_06_hunter_F]
```

## Tier 1
```
AUG:  5.56
  rifle:   [arifle_AUG_F, arifle_AUG_black_F]
  gl:      [arifle_AUG_GL_F, arifle_AUG_GL_black_F]
  carbine: [arifle_AUG_C_F, arifle_AUG_C_black_F]

C7A2:  5.56
  rifle: [AddGis_arifle_C7A2_F, AddGis_arifle_C7A2_blk_F, AddGis_arifle_C7A2_snd_F,
          AddGis_arifle_C7A2_grip_F, AddGis_arifle_C7A2_grip_blk_F, AddGis_arifle_C7A2_grip_snd_F]

Mk20:  5.56
  rifle:   [arifle_Mk20_F, arifle_Mk20_plain_F, arifle_Mk20_black_F, arifle_Mk20_hex_F]
  gl:      [arifle_Mk20_GL_F, arifle_Mk20_GL_plain_F, arifle_Mk20_GL_black_F, arifle_Mk20_GL_hex_F]
  carbine: [arifle_Mk20C_F, arifle_Mk20C_plain_F, arifle_Mk20C_black_F, arifle_Mk20C_hex_F]

FAMAS:  5.56          // F1 oldest → G4 newest; roll mixes generations
  rifle: [atlas_arifle_famasF1_F, atlas_arifle_famasF1_RIS_F, atlas_arifle_famasF1_Grip_F,
          Atlas_Arifle_famasG2_F, Atlas_Arifle_famasG2_Grip_F, atlas_arifle_famasG4_Grip_F]
  gl:    [Atlas_arifle_famasF1_GL_F, Atlas_Arifle_famasG2_GL_F, Atlas_Arifle_famasG4_GL_F]

SCAR_L:  5.56         // also specialist:true — SOF access at higher tiers
  rifle:   [JCA_arifle_SCAR_L_black_F, JCA_arifle_SCAR_L_olive_F, JCA_arifle_SCAR_L_sand_F,
            arifle_SCAR_L_F, arifle_SCAR_L_black_F, arifle_SCAR_L_khaki_F,
            arifle_SCAR_L_grip_F, arifle_SCAR_L_grip_black_F, arifle_SCAR_L_grip_khaki_F]
  gl:      [JCA_arifle_SCAR_L_GL_black_F, JCA_arifle_SCAR_L_GL_olive_F, JCA_arifle_SCAR_L_GL_sand_F,
            arifle_SCAR_L_GL_F, arifle_SCAR_L_GL_black_F, arifle_SCAR_L_GL_khaki_F]
  carbine: [JCA_arifle_SCAR_L_short_black_F, JCA_arifle_SCAR_L_short_olive_F, JCA_arifle_SCAR_L_short_sand_F,
            arifle_SCAR_L_short_F, arifle_SCAR_L_short_black_F, arifle_SCAR_L_short_khaki_F]

SCAR_H:  7.62x51      // also specialist:true; base rifle doubles as dmr with optic
  rifle:   [JCA_arifle_SCAR_H_black_F, JCA_arifle_SCAR_H_olive_F, JCA_arifle_SCAR_H_sand_F,
            arifle_SCAR_F, arifle_SCAR_black_F, arifle_SCAR_khaki_F,
            arifle_SCAR_grip_F, arifle_SCAR_grip_black_F, arifle_SCAR_grip_khaki_F]
  gl:      [JCA_arifle_SCAR_H_GL_black_F, JCA_arifle_SCAR_H_GL_olive_F, JCA_arifle_SCAR_H_GL_sand_F,
            arifle_SCAR_GL_F, arifle_SCAR_GL_black_F, arifle_SCAR_GL_khaki_F]
  carbine: [JCA_arifle_SCAR_H_short_black_F, JCA_arifle_SCAR_H_short_olive_F, JCA_arifle_SCAR_H_short_sand_F,
            arifle_SCAR_short_F, arifle_SCAR_short_black_F, arifle_SCAR_short_khaki_F]

M4A1:  5.56
  rifle:   [JCA_arifle_M4A1_black_F, JCA_arifle_M4A1_olive_F, JCA_arifle_M4A1_sand_F,
            Aegis_arifle_M4A1_F, Aegis_arifle_M4A1_khaki_F, Aegis_arifle_M4A1_sand_F,
            Aegis_arifle_M4A1_grip_F, Aegis_arifle_M4A1_grip_khaki_F, Aegis_arifle_M4A1_grip_sand_F]
  gl:      [JCA_arifle_M4A1_GL_black_F, JCA_arifle_M4A1_GL_olive_F, JCA_arifle_M4A1_GL_sand_F,
            Aegis_arifle_M4A1_GL_F, Aegis_arifle_M4A1_GL_khaki_F, Aegis_arifle_M4A1_GL_sand_F]
  carbine: [JCA_arifle_M4A1_short_black_F, JCA_arifle_M4A1_short_olive_F, JCA_arifle_M4A1_short_sand_F,
            Aegis_arifle_M4A1_short_F, Aegis_arifle_M4A1_short_khaki_F, Aegis_arifle_M4A1_short_sand_F]

M16A4:  5.56
  rifle: [JCA_arifle_M16A4_black_F, JCA_arifle_M16A4_olive_F, JCA_arifle_M16A4_sand_F,
          JCA_arifle_M16A4_FG_black_F, JCA_arifle_M16A4_FG_olive_F, JCA_arifle_M16A4_FG_sand_F,
          Aegis_arifle_M16A4_F, Aegis_arifle_M16A4_FG_F]
  gl:    [JCA_arifle_M16A4_GL_black_F, JCA_arifle_M16A4_GL_olive_F, JCA_arifle_M16A4_GL_sand_F,
          Aegis_arifle_M16A4_GL_F]

SA80:  5.56
  rifle:   [arifle_SA80_blk_F, arifle_SA80_khk_F, arifle_SA80_snd_F]
  gl:      [arifle_SA80_GL_blk_F, arifle_SA80_GL_khk_F, arifle_SA80_GL_snd_F]
  carbine: [arifle_SA80_C_blk_F, arifle_SA80_C_khk_F, arifle_SA80_C_snd_F]

TRG:  5.56
  rifle:   [arifle_TRG21_F, arifle_TRG21_black_F]
  gl:      [arifle_TRG21_GL_F, arifle_TRG21_GL_black_F]
  carbine: [arifle_TRG20_F, arifle_TRG20_black_F]

NCAR15: ⚑ 5.56?       // RF — verify what this is; MG/GL/B variants exist
  rifle: [arifle_NCAR15_F, arifle_NCAR15B_F]
  gl:    [arifle_NCAR15_GL_F]
  ar:    [arifle_NCAR15_MG_F]

SR10: ⚑ 5.56?         // JCA — AR-pattern, verify role (carbine vs rifle)
  carbine: [JCA_arifle_SR10_AFG_black_F, JCA_arifle_SR10_AFG_olive_F, JCA_arifle_SR10_AFG_sand_F,
            JCA_arifle_SR10_VFG_black_F, JCA_arifle_SR10_VFG_olive_F, JCA_arifle_SR10_VFG_sand_F]

LIM85:  5.56
  mg: [LMG_03_F, LMG_03_snd_F, LMG_03_khk_F]

Negev:  5.56
  mg: [Atlas_LMG_Negev_black_F]

FNMAG_240:  7.62x51
  mg: [Aegis_MMG_FNMAG_240_F, Aegis_MMG_FNMAG_F]

SR25:  7.62x51
  dmr: [JCA_arifle_SR25_black_F, JCA_arifle_SR25_olive_F, JCA_arifle_SR25_sand_F,
        Aegis_arifle_SR25_blk_F, Aegis_arifle_SR25_khk_F, Aegis_arifle_SR25_snd_F]

EBR:  7.62x51         // Mk18 ABR
  dmr: [srifle_EBR_F, srifle_EBR_blk_F, srifle_EBR_khk_F, srifle_EBR_cbr_F,
        srifle_EBR_blk_lxWS, srifle_EBR_snake_lxWS]

M32:  standalone GL
  gl_standalone: [GL_M32_F]
```

## Tier 2
```
MX:  6.5 (cased t2 / caseless t3)
  rifle:   [arifle_MX_F, arifle_MX_Black_F, arifle_MX_khk_F, ef_arifle_mx_coy,
            ef_arifle_mx_grip, ef_arifle_mx_grip_black, ef_arifle_mx_grip_coy, ef_arifle_mx_grip_khk]
  gl:      [arifle_MX_GL_F, arifle_MX_GL_Black_F, arifle_MX_GL_khk_F, ef_arifle_mx_gl_coy]
  ar:      [arifle_MX_SW_F, arifle_MX_SW_Black_F, arifle_MX_SW_khk_F, ef_arifle_mx_sw_coy]
  ar_alt: ⚑ [ef_arifle_mxar, ef_arifle_mxar_black, ef_arifle_mxar_coy, ef_arifle_mxar_khk,
            ef_arifle_mxar_gl, ef_arifle_mxar_gl_black, ef_arifle_mxar_gl_coy, ef_arifle_mxar_gl_khk]
  carbine: [arifle_MXC_F, arifle_MXC_Black_F, arifle_MXC_khk_F, ef_arifle_mxc_coy]
  dmr:     [arifle_MXM_F, arifle_MXM_Black_F, arifle_MXM_khk_F, ef_arifle_mxm_coy]
  mg:      [LMG_Mk200_F, LMG_Mk200_black_F, LMG_Mk200_khk_F, LMG_Mk200_plain_F]

XMS:  5.56
  rifle: [arifle_XMS_lxWS, arifle_XMS_Gray_lxWS, arifle_XMS_khk_lxWS, arifle_XMS_Sand_lxWS, arifle_XMS_Camo_lxWS]
  gl:    [arifle_XMS_GL_lxWS, arifle_XMS_GL_Gray_lxWS, arifle_XMS_GL_khk_lxWS,
          arifle_XMS_GL_Sand_lxWS, arifle_XMS_GL_Camo_lxWS]
  shot:  [arifle_XMS_Shot_lxWS, arifle_XMS_Shot_Gray_lxWS, arifle_XMS_Shot_khk_lxWS,
          arifle_XMS_Shot_Sand_lxWS, arifle_XMS_Shot_Camo_lxWS]
  dmr:   [arifle_XMS_M_lxWS, arifle_XMS_M_Gray_lxWS, arifle_XMS_M_khk_lxWS,
          arifle_XMS_M_Sand_lxWS, arifle_XMS_M_Camo_lxWS]
  mg:    [LMG_S77_lxWS, LMG_S77_Compact_lxWS, LMG_S77_Compact_Snakeskin_lxWS, LMG_S77_Hex_lxWS,
          LMG_S77_GHex_lxWS, LMG_S77_Desert_lxWS, LMG_S77_AAF_lxWS]      // the Stoner

SPAR:  5.56 / 7.62x51
  rifle: [arifle_SPAR_01_blk_F, arifle_SPAR_01_khk_F, arifle_SPAR_01_snd_F]
  gl:    [arifle_SPAR_01_GL_blk_F, arifle_SPAR_01_GL_khk_F, arifle_SPAR_01_GL_snd_F]
  ar:    [arifle_SPAR_02_blk_F, arifle_SPAR_02_khk_F, arifle_SPAR_02_snd_F,
          Aegis_arifle_SPAR_02_inf_blk_F, Aegis_arifle_SPAR_02_inf_khk_F, Aegis_arifle_SPAR_02_inf_snd_F]
  dmr:   [arifle_SPAR_03_blk_F, arifle_SPAR_03_khk_F, arifle_SPAR_03_snd_F]   // 7.62

HK433:  5.56
  rifle:   [JCA_arifle_HK433_black_F, JCA_arifle_HK433_olive_F, JCA_arifle_HK433_sand_F]
  carbine: [JCA_arifle_HK433_short_black_F, JCA_arifle_HK433_short_olive_F, JCA_arifle_HK433_short_sand_F]

M4A4:  5.56
  rifle: [JCA_arifle_M4A4_AFG_black_F, JCA_arifle_M4A4_AFG_olive_F, JCA_arifle_M4A4_AFG_sand_F,
          JCA_arifle_M4A4_VFG_black_F, JCA_arifle_M4A4_VFG_olive_F, JCA_arifle_M4A4_VFG_sand_F]
  gl:    [JCA_arifle_M4A4_GL_black_F, JCA_arifle_M4A4_GL_olive_F, JCA_arifle_M4A4_GL_sand_F]

Promet:  6.5          // MSBS65
  rifle: [arifle_MSBS65_F, arifle_MSBS65_black_F, arifle_MSBS65_camo_F, arifle_MSBS65_sand_F]
  gl:    [arifle_MSBS65_GL_F, arifle_MSBS65_GL_black_F, arifle_MSBS65_GL_camo_F, arifle_MSBS65_GL_sand_F]
  shot:  [arifle_MSBS65_UBS_F, arifle_MSBS65_UBS_black_F, arifle_MSBS65_UBS_camo_F, arifle_MSBS65_UBS_sand_F]
  dmr:   [arifle_MSBS65_Mark_F, arifle_MSBS65_Mark_black_F, arifle_MSBS65_Mark_camo_F, arifle_MSBS65_Mark_sand_F]

MkI_EMR:  7.62x51     // DMR_03
  dmr: [srifle_DMR_03_F, srifle_DMR_03_tan_F, srifle_DMR_03_khaki_F, srifle_DMR_03_multicam_F, srifle_DMR_03_woodland_F]

SR25_MR:  7.62x51
  dmr: [Aegis_arifle_SR25_MR_blk_F, Aegis_arifle_SR25_MR_khk_F, Aegis_arifle_SR25_MR_snd_F]

GLX:  standalone GL
  gl_standalone: [glaunch_GLX_lxWS, glaunch_GLX_tan_lxWS, glaunch_GLX_olive_lxWS, glaunch_GLX_camo_lxWS,
                  glaunch_GLX_hex_lxWS, glaunch_GLX_ghex_lxWS, glaunch_GLX_snake_lxWS]
```

## Tier 3
```
G36:  5.56 → ⚑ 6.5 canon call
  rifle:   [arifle_G36_F, arifle_G36_Sand_F]
  gl:      [arifle_G36_GL_F, arifle_G36_GL_Sand_F]
  carbine: [arifle_G36C_F, arifle_G36C_Sand_F]

G433:  5.56 → ⚑ 6.5 canon call   // AddGis, paired with G36 as the German t3 lane
  rifle: [AddGis_arifle_G433_F, AddGis_arifle_G433_khk_F, AddGis_arifle_G433_snd_F,
          AddGis_arifle_G433_FG_F, AddGis_arifle_G433_FG_khk_F, AddGis_arifle_G433_FG_snd_F]
  gl:    [AddGis_arifle_G433_GL_F, AddGis_arifle_G433_GL_khk_F, AddGis_arifle_G433_GL_snd_F]

SPMG:  .338
  mg: [MMG_02_black_F, MMG_02_camo_F, MMG_02_khaki_F, MMG_02_sand_F]

XM25:  airburst GL — specialist, hooks jmfsbfa airburst engine
  gl_standalone: [GL_XM25_F]
```

## West specialist (elite shape / template request only)
```
HK437:  .300 BLK      // suppressed CQB lane — ties to config_338LM_300BLK work
  carbine: [JCA_arifle_HK437_AFG_black_F, JCA_arifle_HK437_AFG_olive_F, JCA_arifle_HK437_AFG_sand_F,
            JCA_arifle_HK437_VFG_black_F, JCA_arifle_HK437_VFG_olive_F, JCA_arifle_HK437_VFG_sand_F]

MAR10:  .338
  sniper: [srifle_DMR_02_F, srifle_DMR_02_camo_F, srifle_DMR_02_sniper_F, srifle_DMR_02_tna_F]

AWM:
  sniper: [JCA_srifle_AWM_black_F, JCA_srifle_AWM_olive_F, JCA_srifle_AWM_sand_F]

M107:  .50 AM
  sniper: [JCA_srifle_M107_black_F, JCA_srifle_M107_olive_F, JCA_srifle_M107_sand_F]

LRR:  .408
  sniper: [srifle_LRR_F, srifle_LRR_camo_F, srifle_LRR_tna_F, Aegis_srifle_LRR_sand_F, Aegis_srifle_LRR_olive_F]

M4_Benelli:
  shot: [sgun_M4_F]
```

---

# EAST

## Tier 0
```
AKM:  7.62x39
  rifle: [arifle_AKM_F, arifle_AKSM_F, arifle_AKSM_alt_F, arifle_AKS_F, arifle_AKS_alt_F]
  ar:    [arifle_RPK_F]

AK74:  5.45
  rifle: [Aegis_arifle_AK74_F, Aegis_arifle_AK74_gold_F, Aegis_arifle_AK74_oak_F,
          Aegis_arifle_AKS74_F, Aegis_arifle_AKS74_gold_F, Aegis_arifle_AKS74_oak_F,
          Aegis_arifle_AKM74_F, Aegis_arifle_AKM74_olive_F, Aegis_arifle_AKM74_plum_F, Aegis_arifle_AKM74_sand_F]
  gl:    [Aegis_arifle_AK74_GL_F, Aegis_arifle_AK74_GL_oak_F, Aegis_arifle_AKM74_GL_F,
          Aegis_arifle_AKM74_olive_GL_F, Aegis_arifle_AKM74_GL_plum_F, Aegis_arifle_AKM74_sand_GL_F]
  ar:    [Aegis_arifle_RPK74M_F]
  dmr:   [Aegis_srifle_SVD_f, Aegis_srifle_SVD_blk_f, Aegis_srifle_SVD_plum_f]

SKS:  7.62x39
  rifle: [Opf_arifle_SKS_F, Opf_arifle_SKS_oak_F]
```

## Tier 1
```
AK103:  7.62x39
  rifle: [Aegis_arifle_AK103_F, Aegis_arifle_AK103_plum_F]
  gl:    [Aegis_arifle_AK103_GL_F, Aegis_arifle_AK103_GL_plum_F]
  dmr:   share SVD (AK74)

KH2002:  5.56         // KHBAR
  rifle:   [AddGis_arifle_KHBAR_F]
  gl:      [AddGis_arifle_KHBAR_GL_F]
  carbine: [AddGis_arifle_KHBAR_C_F]

Rahim:  7.62x54R      // DMR_01
  dmr: [srifle_DMR_01_F, srifle_DMR_01_black_F, srifle_DMR_01_black_RF, srifle_DMR_01_tan_RF]
```

## Tier 2
```
AK12:  7.62x39 + 5.45 lines (per-squad caliber lock applies)
  rifle:   [arifle_AK12_F, arifle_AK12_arid_F, arifle_AK12_lush_F,
            arifle_AK12_545_F, arifle_AK12_545_arid_F, arifle_AK12_545_lush_F, arifle_AK12_545_tan_F]
  gl:      [arifle_AK12_GL_F, arifle_AK12_GL_arid_F, arifle_AK12_GL_lush_F,
            arifle_AK12_GL_545_F, arifle_AK12_GL_545_arid_F, arifle_AK12_GL_545_lush_F, arifle_AK12_GL_545_tan_F]
  carbine: [arifle_AK12U_F, arifle_AK12U_arid_F, arifle_AK12U_lush_F,
            arifle_AK12U_545_F, arifle_AK12U_545_arid_F, arifle_AK12U_545_lush_F, arifle_AK12U_545_tan_F]
  ar:      [arifle_RPK12_F, arifle_RPK12_arid_F, arifle_RPK12_lush_F,
            Aegis_arifle_RPK12_545_F, Aegis_arifle_RPK12_545_arid_F, Aegis_arifle_RPK12_545_lush_F,
            Aegis_arifle_RPK12_545_tan_F]
  dmr:     share SVD until modern east dmr added

Katiba:  6.2 (converted)
  rifle:   [arifle_Katiba_F]
  gl:      [arifle_Katiba_GL_F]
  carbine: [arifle_Katiba_C_F]

CAR95:  5.8 or 6.2 — decide   // CTAR
  rifle: [arifle_CTAR_blk_F, arifle_CTAR_hex_F, arifle_CTAR_ghex_F, Aegis_arifle_CTAR_tan_f]
  gl:    [arifle_CTAR_GL_blk_F, arifle_CTAR_GL_hex_F, arifle_CTAR_GL_ghex_F, Aegis_arifle_CTAR_GL_tan_f]
  ar:    [arifle_CTARS_blk_F, arifle_CTARS_hex_F, arifle_CTARS_ghex_F, Aegis_arifle_CTARS_tan_f]

Zafir:  7.62x54R
  mg: [LMG_Zafir_F, LMG_Zafir_black_F, LMG_Zafir_ghex_F]

Cyrus:  9.3           // DMR_05
  dmr: [srifle_DMR_05_blk_F, srifle_DMR_05_hex_F, srifle_DMR_05_ghex_F, srifle_DMR_05_tan_f]

CMR76:  6.2 (converted)   // DMR_07
  dmr: [srifle_DMR_07_blk_F, srifle_DMR_07_hex_F, srifle_DMR_07_ghex_F]
```

## Tier 3
```
FORT:  6.2 (converted)
  rifle: [arifle_FORT652_F, arifle_FORT651_F]   // ⚑ verify 651 = carbine?
  gl:    [arifle_FORT652_GL_F]

Navid:  9.3
  mg: [MMG_01_black_F, MMG_01_tan_F, MMG_01_hex_F, MMG_01_ghex_F]
```

## East specialist
```
ASh12:  12.7x55
  rifle: [arifle_ash12_blk_RF, arifle_ash12_desert_RF, arifle_ash12_urban_RF, arifle_ash12_wood_RF]
  gl:    [arifle_ash12_GL_blk_RF, arifle_ash12_GL_desert_RF, arifle_ash12_GL_urban_RF, arifle_ash12_GL_wood_RF]
  lr:    [arifle_ash12_LR_blk_RF, arifle_ash12_LR_desert_RF, arifle_ash12_LR_urban_RF, arifle_ash12_LR_wood_RF]

Type115:  6.2 + .50 secondary   // ARX
  rifle: [arifle_ARX_blk_F, arifle_ARX_hex_F, arifle_ARX_ghex_F]

GM6:  12.7 AM
  sniper: [srifle_GM6_F, srifle_GM6_camo_F, srifle_GM6_ghex_F, srifle_GM6_snake_lxWS,
           Aegis_srifle_GM6B_F, Aegis_srifle_GM6B_khaki_F, Aegis_srifle_GM6B_sand_F]

ASP1_Kir:  12.7x54 subsonic     // DMR_04
  sniper: [srifle_DMR_04_F, srifle_DMR_04_Tan_F]

SDAR:  underwater
  rifle: [arifle_SDAR_F]
```

---

# GUER / IRREGULAR

```
Galat:  5.56          // worn = t0, clean = t1
  rifle: [arifle_Galat_worn_lxWS(t0), arifle_Galat_lxWS(t1)]

Velko:  5.56          // R4 rifle t0, R5 t1
  rifle: [Aegis_arifle_Velko_oak, Aegis_arifle_Velko_sand, arifle_Velko_lxWS,
          Aegis_arifle_VelkoR5_oak(t1), Aegis_arifle_VelkoR5_sand(t1), arifle_VelkoR5_lxWS(t1),
          arifle_VelkoR5_snake_lxWS(t1)]
  gl:    [arifle_VelkoR5_GL_lxWS(t1), arifle_VelkoR5_GL_snake_lxWS(t1)]

RFB: ⚑ 7.62x51 t1
  rifle: [Opf_arifle_RFB_F]

H6: ⚑⚑ unknown — identify in arsenal (gold variant = warlord bling potential)
  ?: [srifle_h6_blk_rf, srifle_h6_digi_rf, srifle_h6_gold_rf, srifle_h6_oli_rf, srifle_h6_tan_rf]
```

---

# SHARED POOLS

## Shotguns (`shot` role; tier-tagged)
```
t0: [sgun_HunterShotgun_01_F, sgun_HunterShotgun_01_sawedoff_F, sgun_Mp153_classic_F, sgun_Mp153_black_F]
t1: [sgun_KSG_F, Aegis_sgun_KSG_black_F, sgun_M4_F(west)]
t2: [sgun_aa40_lxWS, sgun_aa40_tan_lxWS, sgun_aa40_snake_lxWS, Aegis_sgun_AA40_khk_lxWS]
```

## SMG / PDW (`crew` role — vehicle crews, rear echelon; fallback carbine → rifle)
```
t0: [SMG_05_F]                                        // Protector
t1: [SMG_01_F, SMG_01_black_F, SMG_01_khk_F,          // Vermin (west)
     SMG_02_F,                                        // Sting (east)
     hgun_PDW2000_F,
     JCA_smg_MP5_AFG_black_F, JCA_smg_MP5_AFG_olive_F, JCA_smg_MP5_AFG_sand_F,
     JCA_smg_MP5_VFG_black_F, JCA_smg_MP5_VFG_olive_F, JCA_smg_MP5_VFG_sand_F,
     JCA_smg_MP5_FL_black_F, JCA_smg_MP5_FL_olive_F, JCA_smg_MP5_FL_sand_F,
     JCA_smg_UMP_AFG_black_F, JCA_smg_UMP_AFG_olive_F, JCA_smg_UMP_AFG_sand_F,
     JCA_smg_UMP_VFG_black_F, JCA_smg_UMP_VFG_olive_F, JCA_smg_UMP_VFG_sand_F,
     JCA_smg_UMP_black_F, JCA_smg_UMP_olive_F, JCA_smg_UMP_sand_F]
t2: [SMG_03_black_F, SMG_03_camo_F, SMG_03_hex_F, SMG_03_khaki_F,      // ADR-97
     SMG_03_TR_black, SMG_03_TR_camo, SMG_03_TR_hex, SMG_03_TR_khaki,
     SMG_03C_black_F? ⚑ verify suffix, SMG_03C_camo, SMG_03C_hex, SMG_03C_khaki,
     SMG_03C_TR_black, SMG_03C_TR_camo, SMG_03C_TR_hex, SMG_03C_TR_khaki,
     EF_smg_Diplomat, EF_smg_Diplomat_Coy, EF_smg_Diplomat_Ghex, EF_smg_Diplomat_Hex]
⚑ untier'd: [SMG_04_blk_F, SMG_04_khk_F, SMG_04_snd_F, Aegis_SMG_Gepard_blk_F]
```

---

## Sidearms (`pistol` role — exempt from caliber discipline)

Issuance by tier — a pistol is a luxury at the bottom, standard kit at the top:
- t0: never both. Most units primary-only; a share (say 10-20%) spawn pistol-only, no primary — the militia look. Every unit has at least one weapon.
- t1: primary-only for riflemen; leaders, crews, and specialists get a sidearm.
- t2+: everyone carries primary + sidearm.

| Tier | WEST | EAST | GUER |
|---|---|---|---|
| 0 | M9A1, ACPC2 | PM, Zubr | PM, Zubr, ACPC2, DEagle classic |
| 1 | P07, P226, G17, M9A1 | Rook40 | DEagle, 4-five |
| 2 | P320, Glock19, 4-five | Rook40 — stand-in | — |
| 3 | P320 | Rook40 — stand-in | — |
| spec | Mk23, R57 Five-seveN, Glock19 auto | — | DEagle bling (gold/bronze/copper) |

```
M9A1:  west t0-1
  [JCA_hgun_M9A1_black_F, JCA_hgun_M9A1_olive_F, JCA_hgun_M9A1_sand_F]
ACPC2:  west/guer t0
  [hgun_ACPC2_F, hgun_ACPC2_black_F]
P07:  west t1
  [hgun_P07_F, hgun_P07_blk_F, hgun_P07_khk_F, ef_hgun_P07_coy]
P226:  west t1
  [JCA_hgun_P226_black_F, JCA_hgun_P226_olive_F, JCA_hgun_P226_sand_F]
G17:  west t1
  [hgun_G17_F, hgun_G17_black_F, hgun_G17_khaki_F,
   JCA_hgun_G17_black_F, JCA_hgun_G17_olive_F, JCA_hgun_G17_sand_F]
P320:  west t2-3        // M17/M18 lane — modern US service pistol
  [JCA_hgun_P320_black_F, JCA_hgun_P320_olive_F, JCA_hgun_P320_sand_F,
   Aegis_hgun_P320_black_F, Aegis_hgun_P320_khaki_F, Aegis_hgun_P320_sand_F]
Glock19:  west t2
  [hgun_Glock19_RF, hgun_Glock19_khk_RF, hgun_Glock19_Tan_RF]
Glock19_auto:  specialist (machine pistol)
  [hgun_Glock19_auto_RF, hgun_Glock19_auto_khk_RF, hgun_Glock19_auto_Tan_RF]
FourFive:  west t2 heavy   // Pistol_heavy_01
  [hgun_Pistol_heavy_01_F, hgun_Pistol_heavy_01_black_F, hgun_Pistol_heavy_01_green_F,
   ef_hgun_Pistol_heavy_01_coy]
Mk23:  west specialist (suppressed SOF)
  [JCA_hgun_Mk23_black_F, JCA_hgun_Mk23_olive_F, JCA_hgun_Mk23_sand_F]
R57:  west specialist   // Five-seveN; silver = bling
  [Aegis_hgun_Pistol_R57_F, Aegis_hgun_Pistol_R57_olive_F, Aegis_hgun_Pistol_R57_sand_F,
   Aegis_hgun_Pistol_R57_silver_F]

PM:  east/guer t0       // Pistol_01
  [hgun_Pistol_01_F]
Rook40:  east t1+ (stand-in above t1 — want modern east pistol)
  [hgun_Rook40_F]
Zubr:  east/guer t0 revolver   // Pistol_heavy_02
  [hgun_Pistol_heavy_02_F]

DEagle:  guer t1; bling variants = warlord identity option
  [hgun_DEagle_RF, hgun_DEagle_classic_RF, hgun_DEagle_camo_RF]
  bling: [hgun_DEagle_gold_RF, hgun_DEagle_bronze_RF, hgun_DEagle_copper_RF]

⚑ unidentified: [vtf_MK13, vtf_MK13_black]   // Mk13 flare? verify in arsenal
⚑ unidentified: [hgun_Mk26_F]
stray non-weapon in dump: ACE_Flashlight_Maglite_ML300L → belongs in kit lists, not weapon pools
```

## Launchers (`at` / `atgm` / `aa` roles)

Roles: `at` = unguided/rocket (squad AT slot), `atgm` = guided AT (dedicated/weapons team), `aa` = MANPADS (AA specialist, t1+ with density scaling). Disposables (M72, NLAW) can also be handed out as extra tubes at t2+ west.
Titans split by prefix: B_ = WEST, O_ = EAST (east's stand-in ATGM/AA "for now"), I_ = GUER/patron. Long Titan = AA, short = ATGM.

| Tier | WEST at | EAST at | GUER at |
|---|---|---|---|
| 0 | M72 | RPG7, RPG7M | RPG7, PSRL1 |
| 1 | Pzf3, PSRL1, M72 | RPG32 | RPG32, PSRL1 |
| 2 | MRAWS, Mk153, NLAW | RPG32, Vorona (atgm) | I_Titan (patron atgm) |
| 3 | Spike, B_Titan_short (atgm), NLAW | Vorona, O_Titan_short (atgm) | — |
| aa (t1+) | B_Titan long | O_Titan long | I_Titan long |

```
M72:  west t0-1 disposable
  [JCA_launch_M72_black_F, JCA_launch_M72_olive_F, JCA_launch_M72_sand_F]
RPG7:  east/guer t0
  [launch_RPG7_F, Aegis_launch_RPG7M_F]
PSRL1:  west/guer t0-1   // US-made RPG-7 clone — patron-supply flavor gold
  [launch_PSRL1_black_RF, launch_PSRL1_digi_RF, launch_PSRL1_geo_RF, launch_PSRL1_olive_RF,
   launch_PSRL1_sand_RF, launch_PSRL1_PWS_black_RF, launch_PSRL1_PWS_digi_RF,
   launch_PSRL1_PWS_geo_RF, launch_PSRL1_PWS_olive_RF, launch_PSRL1_PWS_sand_RF]
Pzf3:  west t1
  [Atlas_Launch_Pzf3_F]
RPG32:  east/guer t1-2
  [launch_RPG32_F, launch_RPG32_black_F, launch_RPG32_camo_F, launch_RPG32_green_F,
   launch_RPG32_ghex_F, launch_RPG32_tan_lxWS]
MRAWS:  west t2, SIDE-LOCKED   // Carl Gustaf — WEST only, never patron-supplied, no flavor override
  [launch_MRAWS_black_F, launch_MRAWS_coyote_F, launch_MRAWS_green_F, launch_MRAWS_olive_F,
   launch_MRAWS_sand_F, launch_MRAWS_black_rail_F, launch_MRAWS_coyote_rail_F,
   launch_MRAWS_green_rail_F, launch_MRAWS_olive_rail_F, launch_MRAWS_sand_rail_F]
Mk153:  west t2          // SMAW
  [JCA_launch_Mk153_black_F, JCA_launch_Mk153_olive_F, JCA_launch_Mk153_sand_F,
   JCA_launch_Mk153_PWS_black_F, JCA_launch_Mk153_PWS_olive_F, JCA_launch_Mk153_PWS_sand_F]
NLAW:  west t2-3 disposable top-attack
  [launch_NLAW_F]
Spike:  west t3 atgm
  [ace_spike_launcher, ace_spike_launcher_olive]
Vorona:  east t2-3 atgm
  [launch_O_Vorona_brown_F, launch_O_Vorona_green_F]

Titan_AT (short):
  WEST: [launch_B_Titan_short_F, launch_B_Titan_short_tna_F, launch_Titan_short_blk_F]
  EAST: [launch_O_Titan_short_F, launch_O_Titan_short_camo_F, launch_O_Titan_short_ghex_F]
  GUER: [launch_I_Titan_short_F]
Titan_AA (long):
  WEST: [launch_B_Titan_F, launch_B_Titan_olive_F, launch_B_Titan_coyote_F, launch_B_Titan_tna_F,
         EF_launch_B_Titan_Coy, launch_Titan_blk_F]
  EAST: [launch_O_Titan_F, launch_O_Titan_camo_F, launch_O_Titan_ghex_F]
  GUER: [launch_I_Titan_F, launch_I_Titan_eaf_F]
```

## Statics / crew-served (`csw` — ACE carry components; weapons-team templates)

These are ACE CSW carry items (tripod + tube per 2-man load), assembled in the field. NOTE: emplaced/defensive spawns also need the assembled static VEHICLE classnames (B_HMG_01_F etc.) — separate dump required; carry items go in weapons-team inventories, assembled classes in emplacement spawns.

| Tier | WEST | EAST | GUER |
|---|---|---|---|
| 0 | M2 bare, Dragon | SPG9 | SPG9, M2 bare |
| 1 | M2 sight/shield, TOW, Mk6 mortar | AGS30, Kord (stand-in — want DShK t0), mortar | mortar, patron csw |
| 2 | Mk30 HMG, Mk32 GMG, static Titan AT/AA | Kord, AGS30, static O-Titan | — |

```
M2:  west/guer t0-1     // bare = t0, sight/shield = t1; needs M3 tripod
  [ace_csw_staticM2BareCarry, ace_csw_staticM2SightCarry,
   ace_csw_staticM2ShieldCarry, ace_csw_staticM2ShieldSightCarry]
  tripods: [ace_csw_m3CarryTripod, ace_csw_m3CarryTripodLow]
Dragon:  west t0-1 atgm // M47, obsolete — great patron-surplus flavor
  [ace_dragon_super]
TOW:  west t1-2 atgm
  tripod: [ace_csw_m220CarryTripod]
Mk30_HMG:  west t2
  [ace_csw_staticHMGCarry]
Mk32_GMG:  west t2
  [ace_csw_staticGMGCarry]
Titan_static:  t2+ (side via warhead/faction, mirrors Titan split)
  [ace_csw_staticATCarry, ace_csw_staticAACarry]
Mortar_Mk6:  all sides t1+
  [ace_csw_staticMortarCarry, ace_csw_carryMortarBaseplate]

SPG9:  east/guer t0-1 recoilless
  [ace_csw_spg9CarryTripod]
AGS30:  east t1-2 GMG
  [ace_csw_sag30CarryTripod]
Kord:  east t1-2 HMG (stand-in at t0 — want DShKM)
  [ace_csw_kordCarryTripod, ace_csw_kordCarryTripodLow]
```

## Attachments (slot + compatibility matched, not per-family)

Tier rules:
- t0: irons; ~10% chance of scavenged collimator; flashlight only
- t1: collimator standard; magnified for leader/dmr; bipods on ar/mg/dmr/sniper (t1+); flashlight/visible laser
- t2: magnified standard; IR laser pointer on all primaries (pairs with NVG in kit layer); suppressors elite/specialist ONLY
- t3-4: suppressors DEFAULT on all primaries (caliber-matched below); thermal/fused optics are the signature — Nightstalker/NVS for leaders, tws for AR/rifle, tws_mg for MGs, tws_sniper for snipers; 65_TI thermal-insulated cans (reduced IR glow — EMCON flavor)
- Pistol attachments mirror at one tier lag (suppressed pistols t3 elite, MRD t2+)

Optic pools by band (roll within band, camo-filtered):
```
collimator t1+: ACO/ACO_grn (+AK/smg/desert/camo/wood vars), Holosight (+smg), MRD (pistol),
  Yorris (pistol), rds_RF, r1 high/low (lxWS), ef_microsight (+pistol), 1p87 (east),
  JCA: CRO, CRBS, MRO, MRPS, IHO(+magnifier), MROS(+magnifier), ROS
magnified t1(leader)/t2(standard): ACOG (JCA/Aegis), ARCO (+AK vars), Hamr, MRCO, ERCO, RCO-family,
  KHS (east), LRCO, dcl, ico_01, ICO/AICO/ARO/ARS/HPCS/AHO (JCA), ef_mbs (+remote), VRCO (RF)
dmr t1+: DMS (+weathered/ghex/snake), MRCS, HPPO (+RAD), MPO, PRO, ERCO
sniper t2+: SOS, LRPS (+ghex/tna), AMS (+khk/snd), KHS
thermal t3+: Nightstalker, NVS, tws, tws_mg, tws_sniper
```

Pointers/lights:
```
flashlight t0+: acc_flashlight (+smg/pistol/MP5/tactical JCA/esd_01), saber_light (lxWS, +camos)
visible laser t1+: Aegis compact green/red, ACE_acc_pointer_green, DBAL red/green
IR t2+: acc_pointer_IR (+lxWS camos, EF coy), saber_light_ir set, ACE_SPIR, DBAL,
  JCA LaserModule (+Mk23), DM pointers (Aegis), dual-mounts (JCA), acc_flashlight_ir,
  pistol IR (RF) t3 elite
```

Suppressors by caliber (attach when tier/shape rule says suppress):
| Caliber | Classfamilies |
|---|---|
| 5.56 | JCA snds_556 adv/enh, suppressor_m (lxWS), snds_M (+khk/snd), mxar (EF) |
| 5.45 | snds_545 (+arid/wdm/lush), pbs_545 (Aegis) |
| 6.5 | snds_H (+khk/snd), suppressor_65 (RF colors), snds_65_TI (t3 thermal-insulated) |
| 7.62x39/54 | pbs_762 (Aegis) |
| 7.62x51 | snds_B (+camos), JCA 762 tactical, SR25 cans (JCA/Aegis), suppressor_h (lxWS) |
| .300 BLK | JCA snds_300 enhanced |
| 9mm | JCA/Aegis 9MM enh/tactical, snds_L, MP5 cans, ef_snds_diplomat |
| .45 | snds_acp, JCA 45 tactical, snds_pistol_heavy_01 |
| 5.7 | snds_570, RP57 (Aegis) |
| .338 | snds_338 colors |
| .408 | snds_408 colors |
| .50 | JCA M107 cans |
| 12.7x55 | RF big/small (+desert/wood) — ASh-12 |
| 9.3 | snds_93mmg (+tan) — Cyrus/Navid |
| 12ga | snds_12Gauge (lxWS) |
| AWM | JCA AWM cans |
| generic lxWS | suppressor_l set |
Flash hiders (mzls_*) = non-suppressed muzzle default t1+ where available.

Bipods: bipod_01 (west), bipod_02 (east), bipod_03 (guer/AAF) + JCA (04/M107/AWM) — auto-attach ar/mg/dmr/sniper t1+, camo-filtered.

EW cosmetic: muzzle_antenna_01/02/03 — antenna attachments for EW/SIGINT units (JMSB-type flavor), not suppressors.
⚑ unidentified: ace_milr_base, acc_o_FMS
Stray: ACE_DBAL listed both laser sets — fine, dual-mode.

## NVGs (kit layer — availability is a tier promise: none t0, leaders t1, all t2+, advanced t3+)

| Tier | WEST | EAST | GUER |
|---|---|---|---|
| 0 | none | none | none |
| 1 (leaders only) | ACE Gen1 | ACE Gen1 | ACE Gen1 (patron scraps) |
| 2 (standard) | ACE Gen2, NVGoggles (+WP) | ACE Gen2, NVGoggles_OPFOR (+WP) | ACE Gen2, NVGoggles_INDEP (+WP) |
| 3 | ACE Gen4 (+WP), Compact NVG (B set), LPNVG | ACE Gen4, O_NVGoggles set | — |
| 4 / elite | LPNVG-T fusion, Ti goggles — the US sensor edge | O_NVGoggles (unchanged — their edge is elsewhere) | — |

```
Gen1_t1:  [ACE_NVG_Gen1, ACE_NVG_Gen1_Brown, ACE_NVG_Gen1_Green]
Gen2_t2:  [ACE_NVG_Gen2, ACE_NVG_Gen2_Black, ACE_NVG_Gen2_Brown]
Vanilla_t2:
  WEST: [NVGoggles, ACE_NVGoggles_WP]
  EAST: [NVGoggles_OPFOR, ACE_NVGoggles_OPFOR_WP]
  GUER: [NVGoggles_INDEP, ACE_NVGoggles_INDEP_WP]
Gen4_t3:  [ACE_NVG_Gen4, ACE_NVG_Gen4_Green, ACE_NVG_Gen4_Black,
           ACE_NVG_Gen4_WP, ACE_NVG_Gen4_Green_WP, ACE_NVG_Gen4_Black_WP]
West_t3:  // panoramic/compact image intensifiers
  [NVGogglesB_blk_F, NVGogglesB_grn_F, NVGogglesB_gry_F, EF_LPNVG, EF_LPNVG_Tan]
West_t4:  // thermal fusion — peer+ / elite shape only
  [EF_LPNVG_T, EF_LPNVG_T_Tan, TiGoggles_RF, TiGoggles_grn_RF, TiGoggles_tan_RF]
East_t3:  // peer+ integrated visor NVG, camo-filtered like weapons
  [O_NVGoggles_hex_F, O_NVGoggles_ghex_F, O_NVGoggles_grn_F, O_NVGoggles_urb_F, O_NVGoggles_blk_F]
```

## Binocular-slot kit (tiered; role-gated where noted)

| Tier | Item | Classnames |
|---|---|---|
| 0 | Binocular | [Binocular] |
| 0-1 | Yardage 450 (civ golf RF — broke-faction fire control) | [ACE_Yardage450] |
| 0-1 | Camera — GUER media-wing flavor, unarmed roles | [Camera_lxWS] |
| 2 | Rangefinder — leaders/dmr/sniper | [Rangefinder] |
| 2-3 | MX-2A thermal bino — recon/JFO roles | [ACE_MX2A] |
| 3-4 | Laser designator (east) — JFO-equivalent slot, pairs with guided fires | [Laserdesignator_02, Laserdesignator_02_ghex_F] |

Component, not tiered: [ace_dragon_sight] → belongs to the Dragon ATGM in statics (weapons-team inventory).
Gap: west laser designator (Laserdesignator vanilla) for t3 west JFO — grab when dumping.

## Inventory drones (`seo` slot kit — backpack-deployable; feeds alive_drones behavior tiers)

Drone floor rule satisfied here: IED-quad variants ARE the t0-1 fires capability.

| Tier | WEST | EAST | GUER |
|---|---|---|---|
| 0-1 | Darter | UAV_02 (+IED) | UAV_02 IED, Rev IED — suicide FPV layer |
| 1-2 | RQ-11 Raven | — | — |
| 2 | Switchblade 300, Black Hornet, AL-6 (+medical) | — | — |
| 3 | Switchblade 600, Honeybadger UGV-AT | Honeybadger (hex), massed IED quads | — |

```
Darter_t1:      [GX_DEPLOYABLE_MAGAZINE_UAV_01]
Raven_t1_west:  [GX_DEPLOYABLE_MAGAZINE_RQ11B_UAV]
UAV02_t0_east/guer:  [GX_DEPLOYABLE_MAGAZINE_UAV_02_lxWS]
UAV02_IED_t0_east/guer:  [GX_DEPLOYABLE_MAGAZINE_UAV_02_IED_lxWS]
BlackHornet_t2_west:  [GX_DEPLOYABLE_MAGAZINE_BLACKHORNET_UAV]
AL6_t2_west:    [GX_DEPLOYABLE_MAGAZINE_UAV_06, GX_DEPLOYABLE_MAGAZINE_UAV_06_MEDICAL]
Switchblade300_t2_west:  [SwitchBlade_300_Tube_Woodland, SwitchBlade_300_Tube_Desert]
Switchblade600_t3_west:  [SwitchBlade_600_Tube_Woodland, SwitchBlade_600_Tube_Desert]
Honeybadger_UGV_AT_t3:
  WEST: [GX_DEPLOYABLE_MAGAZINE_HONEYBADGER_UGV_AT_BLACK, .._DESERT, .._GREEN]
  EAST: [GX_DEPLOYABLE_MAGAZINE_HONEYBADGER_UGV_AT_HEX]
Utility (engineer/support roles, any tier fitting):
  [GX_DEPLOYABLE_MAGAZINE_UGV_02_DEMINING, GX_DEPLOYABLE_MAGAZINE_UGV_02_SCIENCE]

⚑ Rev_* mod set — verify in arsenal, role guesses from names:
  [Rev_darter (recon), Rev_UAV_IED (suicide t0-1), Rev_Designator (lasing drone — t3 kill-chain item),
   Rev_Pelican, Rev_Bustard (cargo?), Rev_Pelter (attack?), Rev_Roller (UGV?), Rev_Demine (utility)]
```

Note: Switchblade tubes answer the open loitering-munition pick for the recon element SEO slot.

## Drone backpacks (side-prefixed; RULE: every squad carries 2-3 drones)

Squad drone load by tier — SEO carries the primary, other members carry the rest:
- t0-1: 2 bags — recon quad + IED/AP FPV
- t2: 2-3 — recon + AP FPV + AT FPV
- t3-4: 3 — recon + AT-TI (thermal seeker) + role pick (Kedr AA interceptor / designator / cargo-medical); elite shape +1

| System | Role | Tier |
|---|---|---|
| UAV_02 quad (lxWS) | recon / IED strike | t0-1 base FPV layer |
| Darter (UAV_01) | recon | t1+ |
| KVN AP / Crocus AP | FPV anti-personnel | t1-2 |
| KVN AT / Crocus AT | FPV anti-armor | t2 |
| KVN/Crocus TI variants | thermal-seeker FPV | t3+ — seeker tech is the tier jump |
| AL-6 Pelican (UAV_06) | cargo / medical | t2+ |
| Kedr AA | drone interceptor — man-portable C-UAS | t3+ |
| UGV_02 science/demining | utility | engineer roles |

```
UAV01 (Darter) — by prefix:
  WEST: [B_UAV_01_backpack_F, Atlas_B_A_UAV_01_backpack_F, EF_B_UAV_01_backpack_coy]
  EAST: [O_UAV_01_backpack_F, O_R_UAV_01_backpack_F]
  GUER: [I_UAV_01_backpack_F, I_E_UAV_01_backpack_F, I_Raven_UAV_01_backpack_F,
         Atlas_I_I_UAV_01_backpack_F, Atlas_I_UNO_UAV_01_backpack_F, ION_UAV_01_backpack_lxWS]
UAV02 quad:
  WEST: [B_UAV_02_backpack_lxWS, Aegis_B_E_UAV_02_backpack_lxWS, Aegis_B_CTRG_UAV_02_backpack_lxWS,
         Aegis_B_A_UAV_02_backpack_lxWS, Atlas_B_A_UAV_02_backpack_lxWS]
  EAST: [O_UAV_02_backpack_lxWS, Aegis_O_R_UAV_02_backpack_lxWS]
  GUER: [I_UAV_02_backpack_lxWS, Atlas_I_I_UAV_02_backpack_lxWS, Aegis_I_E_UAV_02_backpack_lxWS,
         Aegis_I_Raven_UAV_02_backpack_lxWS, ION_UAV_02_backpack_lxWS]
UAV02 IED (irregular suicide layer, t0-1):
  [B_Tura_UAV_02_IED_backpack_lxWS, B_G_UAV_02_IED_backpack_lxWS]
KVN FPV (MOD REMOVED 2026-08-27 - out of every faction; Crocus is the FPV line now):
  WEST: [B_KVN_AP_Bag, B_KVN_AT_Bag, B_KVN_AP_TI_Bag, B_KVN_AT_TI_Bag]
  EAST: [O_KVN_AP_Bag, O_KVN_AT_Bag, O_KVN_AP_TI_Bag, O_KVN_AT_TI_Bag]
  GUER: [I_KVN_AP_Bag, I_KVN_AT_Bag, I_KVN_AP_TI_Bag, I_KVN_AT_TI_Bag]
Crocus FPV:
  WEST: [B_Crocus_AP_Bag, B_Crocus_AT_Bag, B_Crocus_AP_TI_Bag, B_Crocus_AT_TI_Bag]
  EAST: [O_Crocus_AP_Bag, O_Crocus_AT_Bag, O_Crocus_AP_TI_Bag, O_Crocus_AT_TI_Bag]
  GUER: [I_Crocus_AP_Bag, I_Crocus_AT_Bag, I_Crocus_AP_TI_Bag, I_Crocus_AT_TI_Bag]
  ⚑ KVN vs Crocus difference unknown — verify which is bigger/longer-ranged, may split t1/t2
Kedr AA (C-UAS interceptor, t3+):
  [kedr_backpack_aa, kedr_backpack_aa_char]
AL6 (UAV_06) cargo/medical:
  WEST: [B_UAV_06_backpack_F, B_UAV_06_medical_backpack_F, Atlas_B_A_UAV_06_backpack_F,
         Atlas_B_A_UAV_06_medical_backpack_F]
  EAST: [O_UAV_06_backpack_F, O_UAV_06_medical_backpack_F, O_R_UAV_06_backpack_F,
         O_R_UAV_06_medical_backpack_F]
  GUER: [I_UAV_06_backpack_F, I_UAV_06_medical_backpack_F, I_E_UAV_06_backpack_F,
         I_E_UAV_06_medical_backpack_F, I_Raven_UAV_06_backpack_F, I_Raven_UAV_06_medical_backpack_F,
         Atlas_I_I_UAV_06_backpack_F, Atlas_I_I_UAV_06_medical_backpack_F,
         Atlas_I_UNO_UAV_06_backpack_F, Atlas_I_UNO_UAV_06_medical_backpack_F]
UGV utility (engineer roles):
  WEST: [B_UGV_02_Science_backpack_F, B_UGV_02_Demining_backpack_F]
  EAST: [O_UGV_02_Science_backpack_F, O_UGV_02_Demining_backpack_F, O_R_UGV_02_Demining_backpack_F]
  GUER: [I_UGV_02_Science_backpack_F, I_UGV_02_Demining_backpack_F, I_E_UGV_02_Science_backpack_F,
         I_E_UGV_02_Demining_backpack_F, Atlas_I_I_UGV_02_Demining_backpack_F,
         Atlas_I_UNO_UGV_02_Demining_backpack_F]
CIV pool (missions/humanitarian flavor, not faction kit):
  [C_UAV_06_backpack_F, C_UAV_06_medical_backpack_F, C_IDAP_UAV_01_backpack_F,
   C_IDAP_UAV_06_backpack_F, C_IDAP_UAV_06_medical_backpack_F, C_IDAP_UAV_06_antimine_backpack_F,
   C_IDAP_UGV_02_Demining_backpack_F, CIV_UAV_01_backpack_lxWS, Police_I_P_UGV_02_Demining_backpack_F]
```

# Support weapons matrix — every tier/side resolves mg, dmr, sniper

Rule: `mg` bucket = belt-fed only. Mag-fed squad automatics (RPKs, MX SW, CTARS, SPAR-02) live in `ar` and are never listed as mg. Where no belt-fed exists, the mg slot falls back to `ar` — noted below, not silently.
Stand-ins are official assignments (not silent fallbacks) until better classnames arrive.
Sniper role spawns only via sniper-team templates or elite shape.

| Tier/Side | mg (belt-fed) | dmr | sniper |
|---|---|---|---|
| W t0 | FNMAG_old | Mk14 | Mk14 (hunter, scoped) — stand-in |
| W t1 | LIM85 / Negev / FNMAG_240 | SR25, EBR | AWM |
| W t2 | Mk200 / S77 | MXM, XMS-M, SPAR-03, MkI_EMR, SR25_MR, Promet Mark | MAR10, M107 (AM) |
| W t3 | SPMG (+Mk200 caseless) | MXM (caseless) | LRR (+M107 AM) |
| E t0 | none — falls back to ar (RPK); PKM required | SVD | SVD (high optic) — stand-in |
| E t1 | none — falls back to ar (RPK74M); PKM required | Rahim, SVD | Rahim (scoped) — stand-in (want bolt gun) |
| E t2 | Zafir | CMR76, Cyrus | GM6 (AM) |
| E t3 | Navid | CMR76 (6.2) | GM6, ASP1_Kir |
| GUER t0-1 | FNMAG_old (west patron) / ar fallback RPK (east patron) | patron flavor: SVD / Mk14 | scoped hunting rifle (h6 candidate ⚑) |

# Still missing (next classname dumps)
1. East belt-fed — PKM/PKP now REQUIRED, not nice-to-have: mg rule leaves east t0-1 with no mg at all
2. East bolt-action sniper t0-1 (SVD/Rahim scoped as stand-ins)
3. Modern east dmr for t3 (CMR-76 stretched up as stand-in)
4. Modern east pistol t2+ (Rook-40 stretched up as stand-in)
5. Native east ATGM/AA to eventually replace the O_Titan stand-ins (Kornet/Verba-type)
