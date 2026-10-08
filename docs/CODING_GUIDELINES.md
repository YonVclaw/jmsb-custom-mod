# Coding guidelines

This mod follows the **ACE3 coding guidelines**: <https://ace3.acemod.org/wiki/development/coding-guidelines>.
They are written out here because they are binding for every addon in `addons/`, hand-written or generated.
The generators in `tools/` must emit code that already obeys them.

Not a generated file. Edit it by hand when the rules change.

## Macros: never write by hand what a macro builds

Every addon includes `script_component.hpp`, which pulls in CBA's macros through `addons/main/script_macros.hpp`.
The prefix is `jmfsb`, the component is the addon folder name.

| Macro | Expands to | Use it for |
|---|---|---|
| `GVAR(x)` | `jmfsb_<component>_x` | a global variable or a class this addon owns |
| `QGVAR(x)` | `"jmfsb_<component>_x"` | the same, quoted |
| `EGVAR(c,x)` / `QEGVAR(c,x)` | another component's global | reaching into component `c` |
| `FUNC(x)` / `QFUNC(x)` | `jmfsb_<component>_fnc_x` | a function of this addon |
| `EFUNC(c,x)` / `QEFUNC(c,x)` | another component's function | |
| `PATHTOF(p)` / `QPATHTOF(p)` | `\z\jmfsb\addons\<component>\p` | this addon's own file |
| `PATHTOEF(c,p)` / `QPATHTOEF(c,p)` | `\z\jmfsb\addons\c\p` | another addon's file |
| `LSTRING(k)` / `CSTRING(k)` | `STR_jmfsb_<component>_k` | localised text |
| `QUOTE(...)` | the argument, quoted | any macro that must appear as a string in config |
| `QAUTHOR` | the mod's author string | every `author =` |

**A literal `\z\jmfsb\addons\...` path in a config is a defect.** The only exception is `#include`, which the
preprocessor resolves before macros exist.

**Class names are the one place the prefix is written out.** A faction's vehicles are named after the faction
(`jmfsb_EUDF_B_MRAP_01_F`), not after the component, so `GVAR` cannot produce them; renaming them would break every
mission, group and camo entry that refers to them. Inside an addon that owns its classes outright, use `GVAR`.

## SQF

- One function per `.sqf` file. `PREP` it; never define functions inline.
- Every file-based function carries the ACE header: author, description, `Arguments:` with numbered
  `<TYPE>` entries, `Return Value:`, `Example:`, `Public: Yes|No`.
- Types are uppercase in angle brackets: `<OBJECT>`, `<ARRAY of STRINGs>`, `<STRING or CODE>`.
- `private` on every local variable at its first assignment; `params` for arguments.
- 4 spaces per level, no tabs, no trailing whitespace. Opening brace on the same line, closing brace on its own.
- One space after a comma in arrays: `[_unit, _vehicle]`.
- Conditions always in brackets: `if (_x) then {...}`.
- No magic numbers: `#define` them in the file header or in `script_component.hpp`.
- No globals to pass data between functions; pass arguments. No constant globals; use `#define`.
- `getVariable` always with a default, or the result's type is checked.
- Avoid `spawn`, `execVM`, infinite `while`, and `waitUntil` (use `CBA_fnc_waitUntilAndExecute`).
- No commented-out code, no unreachable code. Functions stay under 250 lines excluding the header.

## Config

- `config.cpp` holds `CfgPatches`; everything else lives in its own `.hpp` and is `#include`d.
- Declare an external class before you inherit from it, including nested ones you extend
  (`class Turrets { class MainTurret; };`), or HEMTT reports L-C04.
- `author = QAUTHOR;` everywhere.
- User-facing text goes in `stringtable.xml`, referenced with `CSTRING`. The exception the user has asked for
  repeatedly: **appearance-menu names are written as plain text, never `$STR_` keys**.
- Only name an editor subcategory the game or this mod defines. Inventing one logs
  `No entry 'bin\config.bin/CfgEditorSubcategories...'` at every start.

## Before you say it is done

`python tools/check_all.py` is the gate: `hemtt check` plus nine project checks (SQF validation, config style,
stringtables, generated art, addon READMEs, architectural invariants, plumbing, externals, CfgPatches). `hemtt
check` alone is not the gate. Regenerate what it says is stale rather than hand-editing generated files.
