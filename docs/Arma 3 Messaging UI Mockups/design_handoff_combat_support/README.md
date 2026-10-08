# Handoff: TAC//SUPPORT — combat support & tasking tacpad

## Overview
TAC//SUPPORT is the request/tasking tacpad for an Arma 3 mission ("1st Joint Multi-Functional Strike Battalion"): the screen a
squad leader opens to call in an air asset, retask it, or author a task for the group. It replaces
the stock ALiVE tablet dialog — dark, low-contrast, inconsistent list styling, guidance copy buried
inside the lists — with the same visual system as the TAC//MSG comms client and the TAC//ADMIN
console. Three screens ship in this bundle: **CAS request**, **transport tasking**, **add task**.

## About the Design Files
The files in this bundle are **design references created in HTML** — prototypes showing intended
look, structure and behaviour. They are **not production code to copy**. The task is to **recreate
this design in the target environment** (for Arma 3 that means an in-game dialog: a display/control
config or a UI framework layer, not HTML/CSS), following that codebase's existing patterns for
dialogs, control classes and event handlers. `styles.css` is the design system's token sheet — port
the **values and the component contracts**, don't ship the file.

## Fidelity
**High fidelity.** Colors, type, spacing, rules, control sizes and copy are final. Target canvas is
**1480 × 900** per screen (scale uniformly to the game's safe area). Static states are drawn;
hover / active / disabled / focus are specified in words below.

## Design system
"Modernist" — flat and architectural, **Archivo** only, near-mono **red on light grey**, zero corner
radius anywhere, strong **2px dividers** between regions and 1px between rows, everything flush
left. No gradients, glows or rounded controls. Micro-labels are uppercase Archivo 800 at 9.5px with
0.16em tracking (`.k`); every number uses `font-variant-numeric: tabular-nums` (`.num`).

## Shared skeleton (all three screens)
A single panel (`.pad`, 2px `--color-text` border, `--color-bg` fill) split into two columns:

| Region | Width | Contents |
|---|---|---|
| Form column | 720px fixed, 2px right divider | title bar, then a vertical stack of labelled groups |
| Right column | flex (≈756px) | map canvas (flex), 2px bottom divider, then the action stack |

**Title bar** — 14px/16px padding, 2px `--color-text` bottom border: screen title in Archivo 800
15px / 0.12em tracking, right-aligned `.k` status in `--color-neutral-700`, and on the support
screens a `SITREP` action cell.

**Group label** (`.glab`) — the organising element and the main fix over the original: 7px/12px
padding, `--color-neutral-200` fill, 2px top divider / 1px bottom divider, `.k` label flush left,
and the asset's **guidance sentence flush right** in 11.5px body, `--color-neutral-700`, max 330px.
Guidance never sits inside a list row, and never centres.

**List row** (`.row`) — 9px/14px padding, 1px bottom divider, 13px/600 body flush left, optional
`.k .num` meta right-aligned. States:
- default `--color-bg`; **hover** `--color-neutral-100`;
- **pressed** `--color-accent-600` fill, `--color-bg` label;
- **selected** (`.on`) full `--color-text` fill, `--color-bg` label;
- **committed / active tasking** (`.acc`) full `--color-accent` fill, `--color-bg` label — one per
  screen at most;
- **disabled** (`.dis`) `--color-neutral-600`, no pointer.
Long lists scroll in place (`overflow-y:auto`) with the square scrollbar: 10px wide,
`--color-neutral-300` track, `--color-text` thumb with a 2px track-coloured inset border.

**Stepper** (`.stepper`) — replaces every slider: 38px tall, 2px `--color-text` border, a 34px
`−` cell, the value bar (Archivo 800 12px / 0.1em, flush left, with an 8px ink fill bar showing the
position within range), a 34px `+` cell. Step cells go `--color-accent` fill / `--color-bg` glyph
on hover.

**Text field** (`.inp`) — 11px/12px padding, 2px `--color-text` border, 14px/600 body. The
description field is a fixed 120px box, top-aligned, `--color-neutral-800`.

**Action stack** — bottom-right, 16px padding, 10px gap, full-width cells (`.act`): 12px/14px
padding, 2px `--color-text` border, Archivo 800 11.5px / 0.14em uppercase **flush left**.
Hover `--color-neutral-100`; pressed = full ink fill. Variants: **primary/destructive** (`.pri`,
`--color-accent` fill + border) reserved for CLOSE; **unavailable** (`.off`, divider-coloured
border, `--color-neutral-600` label, no pointer) e.g. ORDER UNIT RTB when the unit is idle.

**Map canvas** — fills the right column above the action stack. Abstracted in the prototype: a 64px
`--color-text` @13% grid, low-opacity ink shapes for roads/coast, `.k` place names in
`--color-neutral-800`, and a bottom-left grid readout box (`--color-bg`, 2px ink border, `.k .num`).
**In production this is the real in-game map** — keep only the overlay language:
- task point = 18×18px `--color-accent` square with a 7px accent @22% halo;
- effect radius = 2px `--color-accent` square outline with a `.k` caption above it
  (`SAD · 500 M`) that reflects the current stepper value;
- transport / destination markers = ink type label + 2px stem + 26px square, or an accent square
  beside a 20px/800 label.

## Screens

### 2a — Combat support: CAS (`screenshots/combat-support-2a-cas.png`)
Groups top to bottom: **ASSET** (TRANSPORT / CAS, meta = airframe count; CAS selected) ·
**UNIT** (EAGLE ONE, meta `A-164 · 2× GBU`; guidance "Unit is available and waiting for task") ·
**TASK** (SAD committed in accent with a `SEEK & DESTROY` meta, LOITER, ATTACK RUN; guidance
describes the selected task) · **PARAMETERS** (two steppers side by side, 22px gap — CAS Radius
500 M, Altitude MED) · **RULES OF ENGAGEMENT** (scrolling list, "Fire at will, engage at will"
selected). Actions: ORDER UNIT RTB *(unavailable — unit idle)*, CONFIRM TASKING, CLOSE.

### 2b — Combat support: transport (`screenshots/combat-support-2b-transport.png`)
Same skeleton, TRANSPORT selected. **UNIT** RAPS ONE `UH-80 · 8 PAX`, guidance "Unit is on a
mission — you may abort or change the current task". **TASK** is a scrolling list capped at 200px
(PICKUP / LAND *(committed)* / LAND (ENG OFF) / MOVE / EXTRACT). **BEHAVIOUR** replaces PARAMETERS:
Height and Speed steppers side by side, ROE stepper full width beneath. **PASSENGERS** lists the
assigned fireteams with a seat count, group label meta "8 of 8 seats assigned". ORDER UNIT RTB is
**enabled** here because the unit is tasked.

### 2c — Add task (`screenshots/combat-support-2c-add-task.png`)
Authoring screen. **Task title** field, **Task description** box, then the same pick-list pattern
for **TASK STATE** (Created / Assigned *(selected)* / Succeeded / Failed / Cancelled) ·
**APPLIED TO** (assigned individuals / all current and JIP members of assigned group *(selected)* /
all players on my side) · **SET CURRENT** (YES | NO as a two-up split row, 1px divider between) ·
**PARENT TASK** (scrolling, None selected). Actions: ASSIGN PLAYERS, CREATE TASK, BACK, CLOSE
*(accent)*. Map shows the destination marker and the objective grid.

## Interactions & Behavior
- **Asset → unit → task** is a dependent chain: changing ASSET reloads the UNIT list and clears the
  task selection; changing UNIT reloads the tasks that unit supports. Every list is single-select.
- The **guidance sentence** in each group label is bound to the current selection in that group and
  rewrites on change — it is the only place explanatory copy appears.
- **Steppers** clamp at range ends (step cell dims at `opacity:.45`); the value bar and any linked
  map overlay (CAS radius square, altitude readout) update live on each step.
- **CONFIRM TASKING** is enabled only when asset, unit and task are all set; it commits the order,
  turns the chosen task row accent, and switches ORDER UNIT RTB to enabled. **ORDER UNIT RTB**
  double-confirms (label swaps to `CONFIRM RTB`, second press within 3 s commits, blur disarms).
- **Map click** while a task requiring a location is selected sets the task point and updates the
  grid readout; the effect-radius square follows the radius stepper.
- **CREATE TASK** validates that title is non-empty; ASSIGN PLAYERS opens the roster picker over the
  same panel and returns to this screen with the assignment reflected in APPLIED TO.
- **CLOSE** is the only accent action on each screen and always closes the tacpad without committing.
  BACK returns to the previous tacpad screen.
- **States** — hover 7% ink tint, pressed full ink (`--color-accent-600` for accent fills), disabled
  `opacity:.45` / `--color-neutral-600`, keyboard focus `2px solid var(--color-accent)` at 2px
  offset. Never a browser default ring.
- **Responsive** — fixed 1480×900; the form column stays 720px and the map column absorbs any change
  in width.

## State Management
- `assets[]` — { id, type: transport|cas, available, airframes }.
- `units[]` — { id, callsign, assetId, platform, payload, status: idle|tasked, currentTask }.
- `tasks[]` — per asset type, { id, label, meta, requiresLocation, guidance }.
- `selection` — { assetId, unitId, taskId, point: grid|null }.
- `params` — { casRadius, altitude } or { height, speed, roe }, each { value, index, range[] }.
- `manifest[]` — transport only: { teamId, label, members[], seats }.
- `taskDraft` — { title, description, state, appliedTo, setCurrent, parentTaskId, assignees[] }.
- `armed` — which destructive/confirming control is currently armed.
- Unit availability and status poll live (~1 Hz); every commit is a server call whose result flips
  the row to its accent committed state or raises an error in the group label line.

## Design Tokens
Colors: `--color-bg` #f3f2f2 · `--color-surface` #eae9e9 · `--color-text` #201e1d ·
`--color-accent` #ec3013 · `--color-divider` `color-mix(in srgb, #201e1d 40%, transparent)`.
Accent ramp 100 #fff2ef · 200 #ffe0d9 · 300 #ffc4b8 · 400 #ff9783 · 500 #ff563c · 600 #dd2b0f ·
700 #ae1800 · 800 #7c1405 · 900 #4d170e. Neutral ramp 100 #f8f4f4 · 200 #eae7e7 · 300 #d7d3d3 ·
400 #bab6b6 · 500 #9b9797 · 600 #7d7979 · 700 #605d5d · 800 #444141 · 900 #2d2b2b.
Accent is reserved for: the committed task row, the map task point and its radius caption, and the
CLOSE action. Body-size accent text uses `--color-accent-700`, never `--color-accent`.

Spacing: 4 / 8 / 12 / 16 / 24 / 32. In use: 7px/12px group labels, 9px/14px rows, 14px/16px title
bar, 16px/14px parameter blocks, 16px action stack with 10px gaps, 22px between paired steppers.

Radius: **0 everywhere** — including steppers, fields and the scrollbar thumb.

Shadows: none inside the panel.

Type: **Archivo** 400 / 600 / 800. 15px/800/0.12em screen title · 14px/600 field text ·
13px/600 list rows · 12px/800/0.1em stepper values · 11.5px/800/0.14em action labels ·
11.5px/400 guidance copy · 9.5px/800/0.16em micro-labels (`.k`). Tabular numerals on every grid,
count and quantity.

Borders: 2px `--color-text` around the panel, under the title bar, between columns, and around
every cell/stepper/field; 2px `--color-divider` above each group label; 1px between rows.

## Theming
Colors are user-configurable in the shipped product. Keep `--color-accent`, `--color-bg` and
`--color-text` (plus the derived divider and ramp steps) as runtime variables — no component
hard-codes a hex. The suite's night / NVG ground (bg #141514, ink #e6e5e2, accent #ff563c) inverts
these screens from those three values alone.

## Assets
None required. Every mark is type or a plain square — no icons or images. Placeholders standing in
for real content: the **abstracted map** in each right column (replace with the in-game map) and the
square marker glyphs. If iconography is wanted, the design system specifies **Lucide**, ink or
accent only, at interface sizes.

## Files
- `combat-support.html` — all three screens, standalone, opens in a browser. **The primary reference.**
- `screenshots/combat-support-2a-cas.png`, `-2b-transport.png`, `-2c-add-task.png` — each panel at 1×.
- `styles.css` — the Modernist token + component sheet the screens are built on.
- `Combat Support.dc.html` — editable source of the design.
- Related: `design_handoff_tacmsg_thread_view` (comms client) and `design_handoff_tacadmin_console`
  (admin console) share this system.
