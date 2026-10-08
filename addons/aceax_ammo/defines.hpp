// Constants read out of ACE3's own ace_arsenal\defines.hpp and
// ui\RscAttributes.hpp (3.21.2) and copied here, because ACE ships binarised:
// there is no \z\ace\addons\arsenal\defines.hpp to #include at build time.
// Anything ACE renumbers or moves has to be updated here.
//
// Verified against the shipped PBO rather than guessed - the four ammo panels
// below sit at 30/32/34/36 and the two per-weapon magazine panels at 3002/3004,
// which is not a range anyone would arrive at by pattern-matching the
// attachment slots at 22/24/26/28.

// ---- the two right-panel list controls ------------------------------------
// ACE fills ONE of these depending on the LEFT panel, not the right one:
// fnc_fillRightPanel builds into _ctrlPanel (the plain listbox) and then does
// `if (_isContainer) then { _ctrlPanel = _listnBox }`, where _isContainer means
// the left panel is a uniform, vest or backpack. So which control holds the
// ammo rows is decided by the left side. Getting this wrong means reading an
// empty control and silently doing nothing.
#define IDC_rightTabContent 14
#define IDC_rightTabContentListnBox 15

// ---- left panel: the three that put the right panel in "container" mode ----
#define IDC_buttonUniform 2010
#define IDC_buttonVest 2012
#define IDC_buttonBackpack 2014
#define CONTAINER_PANEL_IDCS IDC_buttonUniform, IDC_buttonVest, IDC_buttonBackpack

// ---- right panel: everything that lists ammunition ------------------------
// CurrentMag/CurrentMag2 are the magazines compatible with the selected
// weapon's first and second muzzle. Mag and MagALL are the container-mode
// lists. Throw and Put are grenades and explosives - they are CfgMagazines
// too, and they are where the smoke and flare colour families live, which is
// most of what there is to fold outside rifle ammunition.
#define IDC_buttonCurrentMag 3002
#define IDC_buttonCurrentMag2 3004
#define IDC_buttonMag 30
#define IDC_buttonMagALL 32
#define IDC_buttonThrow 34
#define IDC_buttonPut 36

// WE NOW COLLAPSE ONLY THE TWO PANELS @aceaxatt DECLINES (2026-09-01).
//
// @aceaxatt 1.1.0.0 (2026-08-30) learned magazines. Its fnc_currentPanelRoot
// answers "CfgMagazines" for 3002, 3004, 30 and 32, and its collapsePanel then
// serves those four exactly as this addon does - off the same XtdGearModels /
// XtdGearInfos data, through the same root-parameterised aceax_gearinfo API.
// Two addons folding the same list in the same frame is one too many, and it is
// their panel by right: they own the right-hand panel machinery.
//
// THROW AND PUT STAY OURS. @aceaxatt's own defines.hpp calls 34 and 36
// "deliberately NOT handled ... the toolchain does not generate data for them".
// Ours does - the smoke, chemlight, hand flare and UGL flare families are all
// in XtdGearModels.hpp - so these two panels collapse here or nowhere.
//
// The data is NOT narrowed with the runtime. gen_aceax_ammo.py still maps every
// magazine it can, because @aceaxatt reads that same data for the four panels it
// took over; this addon is now the only source of XtdGearInfos >> CfgMagazines
// in the load order, so trimming it would switch their feature off as well.
#define AMMO_PANEL_IDCS IDC_buttonThrow, IDC_buttonPut

// ---- ACE's grid --------------------------------------------------------------
// pixelScale is a macro ACE defines, not an engine variable; without it the
// literal word ships into the config and evaluates as undefined.
#define pixelScale 0.25
#define GRID_W (pixelW * pixelGridNoUIScale * pixelScale)
#define GRID_H (pixelH * pixelGridNoUIScale * pixelScale)

// The two list controls' FULL heights, from ui\RscAttributes.hpp: the listbox
// ends 28 grid units above the bottom of the safe zone, the listnbox 34. A
// constant rather than a read-back, because @aceaxatt animates the listbox
// back to full height the frame before this runs and a mid-animation
// ctrlPosition is neither height.
#define LIST_FULL_H(isLnb) (safeZoneH - ([28, 34] select (isLnb)) * GRID_H)
// the gap @aceaxatt leaves between the list and its option panel, in grid units
#define OPTIONS_GAP 4

// ---- our own controls ------------------------------------------------------
// One block, well clear of ACE's own IDCs, of @aceaxatt's (9600000..9730002)
// and of ACEAX's (9900000..10030002). Value buttons are
// IDC_VALUE_BASE + axis * 100 + value: three axes of a few values each.
#define IDC_optionsGroup 9740000
#define IDC_optionsTitle 9740001
#define IDC_optionsSub 9740002
#define IDC_AXIS_TITLE_BASE 9740100
#define IDC_VALUE_BASE 9741000

// ---- colours, ACEAX's own, so the three option panels read as one feature --
#define INVISIBLE_COLOR 0, 0, 0, 0
#define ACTIVE_BG_COLOR 0.5, 0.5, 0.5, 0.2
#define SELECTED_BG_COLOR 1, 1, 1, 0.3
#define WEAK_MATCH_BG_COLOR 0.4, 0.4, 0.4, 0.4
#define EXACT_MATCH_TEXT_COLOR 1, 1, 1, 1
#define WEAK_MATCH_TEXT_COLOR 0.9, 0.9, 0.9, 0.9
#define DISABLED_TEXT_COLOR 0.8, 0.8, 0.8, 0.8
