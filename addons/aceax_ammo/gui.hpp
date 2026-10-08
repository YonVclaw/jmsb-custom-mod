// THE OPTION PANEL'S CONTROLS, created at runtime by fnc_buildOptions. Root
// classes, because ctrlCreate resolves its class name at the root of
// configFile. Styled after ACEAX's aceax_arsenal_* and @aceaxatt's copies of
// them - the same grid, the same type sizes, the same colours - so the three
// option panels in the arsenal read as one feature. Nothing here needs ACEAX
// loaded: the selected value is shown by the button's own background rather
// than ACEAX's checkbox art.
class RscControlsGroupNoScrollbars;
class RscText;
class RscButton;

class GVAR(group): RscControlsGroupNoScrollbars {
    idc = IDC_optionsGroup;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
};

// the magazine's name - ACEAX's 7-unit title
class GVAR(title): RscText {
    idc = -1;
    sizeEx = QUOTE(7 * GRID_H);
    shadow = 0;
    text = "";
    x = 0;
    y = 0;
    w = QUOTE(80 * GRID_W);
    h = QUOTE(7 * GRID_H);
};

// under it, the count - ACEAX's 4-unit author line
class GVAR(sub): GVAR(title) {
    sizeEx = QUOTE(4 * GRID_H);
    h = QUOTE(4 * GRID_H);
};

// an axis - Tracer, Finish - ACEAX's 5-unit option title
class GVAR(axisTitle): GVAR(title) {
    sizeEx = QUOTE(5 * GRID_H);
    h = QUOTE(5 * GRID_H);
};

// a value - Red, Black - ACEAX's value button, four to a row
class GVAR(valueButton): RscButton {
    idc = -1;
    text = "";
    sizeEx = QUOTE(5 * GRID_H);
    x = 0;
    y = 0;
    w = QUOTE(19.5 * GRID_W);
    h = QUOTE(10 * GRID_H);
    colorText[] = {EXACT_MATCH_TEXT_COLOR};
    colorBackground[] = {INVISIBLE_COLOR};
    colorFocused[] = {INVISIBLE_COLOR};
    colorShadow[] = {INVISIBLE_COLOR};
    colorBorder[] = {INVISIBLE_COLOR};
    colorBackgroundActive[] = {ACTIVE_BG_COLOR};
    colorDisabled[] = {DISABLED_TEXT_COLOR};
    colorBackgroundDisabled[] = {INVISIBLE_COLOR};
};
