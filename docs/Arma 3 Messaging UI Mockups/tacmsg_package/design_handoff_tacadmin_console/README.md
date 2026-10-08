# Handoff: TAC//ADMIN — server admin console

## Overview
TAC//ADMIN is the admin/Zeus console for an Arma 3 mission ("1st Joint Multi-Functional Strike Battalion"), redesigned to sit
in the same visual system as the TAC//MSG comms tacpad. It is a single full-screen in-game panel:
an admin selects a player from a roster, acts on them (utilities, moderation, skills, medical,
vehicle service), watches them on a map and a live camera, runs scripted commands, and controls the
mission. It replaces a dark, mixed-metaphor panel whose controls were inconsistently sized and
whose type had no hierarchy.

## About the Design Files
The files in this bundle are **design references created in HTML** — prototypes showing intended
look, structure and behaviour. They are **not production code to copy**. The task is to **recreate
this design in the target environment** (for Arma 3 that means an in-game dialog: a display/control
config or a UI framework layer, not HTML/CSS), following that codebase's existing patterns for
dialogs, control classes and event handlers. If the panel will also exist outside the game (a web
admin), implement it in that project's framework of choice. `styles.css` is the design system's
token sheet — port the **values and the component contracts**, don't ship the file.

## Fidelity
**High fidelity.** Colors, type, spacing, rules, control sizes and copy are final. Target canvas is
**1440 × 1000** (16:11-ish game dialog, scale to safe area). Static states are drawn; hover /
active / disabled / focus are specified in words below.

## Design system
"Modernist" — flat and architectural, **Archivo** only, near-mono **red on light grey**, a visible
modular grid, **zero corner radius anywhere**, strong **2px dividers** between regions and 1px
between rows, everything flush left. No gradients, no glows, no icons, no rounded controls. Small
labels are uppercase Archivo 800 at 9.5px with 0.16em tracking (`.k`); every number uses
`font-variant-numeric: tabular-nums` (`.num`).

## Screens / Views

### Screen: Admin console (single screen, 1440×1000)
**Frame.** Optional device shell (`.pad`) around the panel: `--color-neutral-900` fill, 16px
16px 22px padding, `--shadow-lg`, with a 9px/800/0.18em status strip above —
`TAC//MSG SUITE` · 6×6px accent square · `ADMIN CONSOLE 2.4` · right-aligned
`SERVER: GOB-01 · TICK 50 · ADMIN SESSION 00:14:07`. In game the shell can be dropped; the panel
itself is the deliverable.

**Title bar** (full width, 12px/16px padding, **2px `--color-text` bottom border`**):
`TAC//ADMIN` in Archivo 800 20px (letter-spacing −0.02em), then `.k` subtitle
"1ST JOINT MULTI-FUNCTIONAL STRIKE BATTALION · ADMIN PANEL" in `--color-neutral-700`. Right-aligned telemetry as `.k` label +
`.num` value pairs — SFPS 78 · AI 0 · PLAYERS 2 — then an accent-filled chip
`ADMIN · YONV` (`--color-accent` bg, `--color-bg` text, 4px/7px).

**Three columns** below the title bar:

| Column | Width | Fill |
|---|---|---|
| Roster + actions rail | 268px fixed | `--color-surface`, 2px right divider |
| Map + script console | flex (≈740px) | `--color-bg`, 2px right divider |
| Player detail | 432px fixed | `--color-surface` |

#### Column 1 — roster + actions rail (268px)
Section headers everywhere in this rail are the `.sec` pattern: `.k` label, 10px/14px padding,
2px bottom divider, `--color-neutral-700`.
- **PLAYER LIST** header with the live count right-aligned in `.num` `--color-text` (10).
- **Filter field** — `.input`, 30px min-height, 13px, `--color-bg` fill, placeholder
  "Filter players"; pinned above the list, 1px bottom divider.
- **Roster list** — takes the rail's remaining height (`flex:1; min-height:0`) and scrolls
  (`overflow-y: scroll`, always-visible bar). Rows: 9px/14px padding, 9px gap, 1px top divider —
  a 7×7px square presence marker (filled `--color-text` = connected; 1px outline + row
  `opacity:.45` = loading/disconnected), the name at 13.5px, then a `.k` "SIDE · ROLE" in
  `--color-neutral-700`. **Selected row** = full `--color-accent` fill, `--color-bg` text, name
  weight 600, marker inverted to `--color-bg`. Roster drawn: YonV WEST·SL (selected), SGT Wobba
  WEST·MED, CPT Hale WEST·CO, Doc Riley WEST·MED, CPL Okonkwo WEST·RTO, SGT Brennan WEST·SL,
  ROTARY 1-1 WEST·AIR, GUNSLINGER WEST·FSC, LT Adams WEST·LOG, PVT Sandoval LOADING (dimmed).
- **Scrollbar** — 12px wide, `--color-neutral-300` track with a 1px divider left edge, **square**
  `--color-text` thumb with a 2px track-coloured inset border; thumb goes `--color-accent` on
  hover. Never a native rounded bar.
- **UTILITIES** — 2×2 grid, 8px gap, 10px/14px padding: GODMODE · INF AMMO · JMFSB · ARSENAL.
- **ADMIN ACTIONS** — 2×2 grid + a full-width row: SPECTATE · ZEUS · KICK · **BAN** (accent fill,
  the one destructive primary) · LOCK SERVER (full width, with a right-aligned `.k` state "OPEN").
- **MISSION** — `.field` label "LOADED MISSION" + `select.input` (CPEndTotalVictory), then
  **END MISSION** as an accent-outlined cell (2px `--color-accent` border, `--color-accent-700`
  label) with a right-aligned `.k` "CONFIRM ×2".
- **Footer** (pinned, `margin-top:auto`, 2px top divider): ADMIN MESSAGE (default cell) and
  **REVOKE ADMIN** (inverted — `--color-text` fill, `--color-bg` label).
- **The action cell** (`.cell`) is the rail's atomic control: 34px tall, **2px solid
  `--color-text`** border, no fill, label Archivo 800 12.5px **flush left**, 0/11px padding.
  Hover = 7% ink tint; active = full ink fill with `--color-bg` label; disabled = `opacity:.45`
  (e.g. DISMOUNT). Variants: accent fill (BAN, HEAL FULL), accent outline (END MISSION), ink fill
  (REVOKE ADMIN).

#### Column 2 — map + script console (flex)
- **Map toolbar** — 9px/14px padding, 2px bottom divider: `.k` "MAP · ALTIS 1:50K", then a
  `--color-neutral-700` `.k` hint "TELEPORT: HOLD ALT + CLICK · SHIFT = BRING SELECTION", and a
  right-aligned `.k .num` live cursor grid "CURSOR 151 173".
- **Map canvas** — fills remaining height. In the prototype terrain is abstracted: a 64px
  `--color-text` @12% grid, a few low-opacity ink shapes for the runway/road/coast, and `.k`
  place names in `--color-neutral-800` (ATHIRA, GRAVIA, TELOS, AIRFIELD, GULF OF ANTHRAKIA).
  **In production this is the real in-game map**; keep only the overlay language:
  - selected player = 18×18px `--color-accent` square with a 7px accent @22% halo;
  - other players = 12×12px 3px ink outline square;
  - callout = `--color-bg` box, 2px `--color-text` border, 7px/10px: `.k` accent
    "YONV · SELECTED" over the grid in Archivo 800 14px `.num`;
  - **layer switcher**, top-left, `--color-bg` box with a 2px ink border, segmented `.k` cells at
    8px/10px, active cell = ink fill / `--color-bg` label: PLAYERS · VEHICLES · AI · MARKERS.
- **Script console** — 214px tall, 2px top divider.
  - Bar: `.k` "EXECUTE", a 1px-bordered segmented control (SERVER active as ink fill / LOCAL /
    REMOTE · YONV), right-aligned `.k` "HISTORY < >".
  - Left pane (flex): `textarea.input` in `.num`, 13px/1.5, `resize:none`, seeded
    `hint str (getPos player);`; below it `.btn.btn-primary` "RUN", `.btn.btn-secondary` "CLEAR",
    right-aligned `.k` shortcut "CTRL + ENTER".
  - Right pane (392px, 1px left divider): `.k` "RETURN" then a `.num` 12.5px/1.6 log —
    ok lines in `--color-text`, secondary in `--color-neutral-700`, errors prefixed `!` in
    `--color-accent-700`.

#### Column 3 — player detail (432px)
- **PLAYER VIEW** header (`.sec` on `--color-bg`) with right-aligned `.k` "3RD PERSON".
- **Camera feed** — 168px tall, 2px bottom divider. **Placeholder in the prototype**: 135°
  10px/10px `--color-neutral-300`/`--color-neutral-200` stripes with a centred bordered `.k`
  chip "LIVE CAMERA FEED · YONV" and a bottom-left `.k .num` readout "151 173 · 12 M ASL · HDG
  284". In production this is the real render target; keep the readout overlay.
- **Two-up cell row** — TOGGLE VIEW | NVG MODE, each 42px, borderless, split by a 1px divider,
  hover/active as `.cell`.
- **PLAYER INFO** (left half) — the `.rowv` pattern: `grid-template-columns: 104px 1fr`, 1px
  bottom divider, `.k` label in `--color-neutral-700` left, value at 13px right. Rows: NAME YonV
  (600) · SIDE WEST · GRID **151 173** (`.num`, 600, `--color-accent-700`) · FPS 80 ·
  IN VEHICLE No. Read-only.
- **PLAYER SKILLS** (right half) — header carries a right-aligned `.k` dirty-state flag "UNSAVED"
  in `--color-accent-700`. Fields, 8px gap, 10px/14px padding: **RANK** `select.input`
  (Private → Colonel; Sergeant shown), **MEDICAL** select (Doctor / Medic / None), **ENGINEERING**
  select (Adv. Engineer / Engineer / None), then three **multi-select** qualification toggles in a
  wrapping 8px/14px flex row — **EOD · ISR · JFO** — drawn with the design system's
  `.radio` + `.dot` markup but with `border-radius: 0` (square 16px box, accent fill + 4px
  `--color-bg` inset when checked; these are independent quals, not exclusive). Closes with
  `.btn.btn-primary.btn-block` "APPLY SKILLS" (flush-left label).
- **VEHICLE** (left half, bottom) — DISMOUNT (disabled when not mounted, `opacity:.45`), UNSTUCK,
  then `.k` "SERVICE" over a 3-up grid of 36px cells REP · REF · REA, and a `.k`
  `--color-neutral-700` note "NO VEHICLE ASSIGNED — SERVICE ACTS ON NEAREST WITHIN 15 M".
- **MEDICAL** (right half, bottom) — `.rowv` rows: STATUS Conscious (600) · HEART RATE 76 ·
  BLOOD PRES 76 / 114 · BLOOD VOL 6.00 L · PAIN 0.00 (all `.num`). Pinned to the bottom
  (`margin-top:auto`): WAKE UP cell and **HEAL FULL** (accent fill).

## Interactions & Behavior
- **Select a player** (roster row or map marker) — sets `selectedPlayerId`; every panel in
  columns 2–3 rebinds to that player (camera, info, skills, vehicle, medical), and the map recentres
  on them. Roster selection is single-select; the map callout follows it.
- **Utilities** are per-player toggles (GODMODE / INF AMMO / JMFSB). A toggle that is ON reads as
  the `.cell` active state (ink fill) rather than a separate switch. ARSENAL opens the game's
  arsenal for the target.
- **Moderation** — KICK asks for a reason then disconnects. **BAN** and **END MISSION** are
  double-confirm (the "CONFIRM ×2" hint): first press arms the control (label swaps to
  "CONFIRM BAN" / "CONFIRM END"), second press within 3s commits, and blur or timeout disarms.
  LOCK SERVER toggles its state label OPEN ⟷ LOCKED. REVOKE ADMIN drops the caller's own admin and
  closes the panel.
- **SPECTATE / ZEUS** attach the admin to the target / open Zeus at the target's position.
- **Map** — Alt+click teleports the selected player to the cursor grid; Shift+Alt+click brings the
  whole current selection. Cursor grid updates live in the toolbar. Layer chips filter what the
  overlay draws.
- **Script console** — scope segmented control picks SERVER / LOCAL / REMOTE (remote targets the
  selected player and is disabled without admin on the target — the denial reads in the RETURN pane
  in `--color-accent-700`). RUN or Ctrl+Enter executes and appends to RETURN; HISTORY < > walks
  previous commands into the field.
- **Skills** — changing RANK / MEDICAL / ENGINEERING / EOD / ISR / JFO marks the section
  **UNSAVED**; APPLY SKILLS commits all of them in one call and clears the flag. Nothing applies
  on change.
- **Medical / vehicle** — values poll live (~1 Hz). WAKE UP is enabled only when status is
  Unconscious; HEAL FULL restores and clears pain. DISMOUNT enables only when IN VEHICLE is Yes;
  REP / REF / REA act on the assigned vehicle, else the nearest within 15 m.
- **States** — hover 7% ink tint, active/pressed full ink (or `--color-accent-600` for accent
  fills, `--color-accent-700` deeper press), disabled `opacity:.45`, keyboard focus
  `2px solid var(--color-accent)` at 2px offset. Never a browser default ring.
- **Responsive** — fixed 1440×1000; scale uniformly to the game's safe area. If width is
  constrained, the map column absorbs the loss; the 268px and 432px columns are fixed.

## State Management
- `admin` — { name, hasAdmin, sessionStartedAt } (drives the ADMIN chip and REVOKE).
- `players[]` — { id, name, side, role, connected, loading, grid, fps, inVehicle, rank, skills:
  { medical, engineering, eod, isr, jfo }, medical: { status, heartRate, bpSys, bpDia, bloodVolume,
  pain }, vehicleId }.
- `selectedPlayerId`, `playerFilter`.
- `skillsDraft` + `skillsDirty` — the unsaved edit buffer behind the UNSAVED flag; APPLY commits.
- `server` — { sfps, aiCount, playerCount, locked, loadedMission, missions[] }.
- `mapState` — { layer: players|vehicles|ai|markers, cursorGrid, center }.
- `console` — { scope: server|local|remote, source, history[], returns[] }.
- `armed` — which destructive control is currently armed for its second confirm.
- Data: server telemetry and medical/vehicle values poll on a timer; roster updates on connect /
  disconnect events; every write is a server call with the result echoed into the RETURN log.

## Design Tokens
Colors: `--color-bg` #f3f2f2 · `--color-surface` #eae9e9 · `--color-text` #201e1d ·
`--color-accent` #ec3013 · `--color-divider` `color-mix(in srgb, #201e1d 40%, transparent)`.
Accent ramp 100 #fff2ef · 200 #ffe0d9 · 300 #ffc4b8 · 400 #ff9783 · 500 #ff563c · 600 #dd2b0f ·
700 #ae1800 · 800 #7c1405 · 900 #4d170e. Neutral ramp 100 #f8f4f4 · 200 #eae7e7 · 300 #d7d3d3 ·
400 #bab6b6 · 500 #9b9797 · 600 #7d7979 · 700 #605d5d · 800 #444141 · 900 #2d2b2b.
Accent is reserved for: the selected roster row, the map marker + callout label, the ADMIN chip,
destructive/primary actions (BAN, HEAL FULL, RUN, APPLY SKILLS), the UNSAVED flag, error log lines,
and the scrollbar hover. Body-size accent text uses `--color-accent-700`, never `--color-accent`.

Spacing: 4 / 8 / 12 / 16 / 24 / 32. In use: 7–9px gaps inside grids, 10px/14px section padding,
12px/16px title bar, 11px/14px detail blocks.

Radius: **0 everywhere** — including the qualification checkboxes and the scrollbar thumb.

Shadows: only `--shadow-lg` on the outer shell. Nothing inside the panel is elevated.

Type: **Archivo** 400 / 600 / 800. 20px/800 wordmark · 14px/800 `.cell` and `.btn` labels ·
13.5px roster names · 13px values and rows · 12.5px log + cell labels · 9.5px/800/0.16em uppercase
micro-labels (`.k`). Tabular numerals on every grid, count, vital and timing.

Borders: 2px `--color-text` under the title bar and around `.cell` controls; 2px
`--color-divider` between columns and major blocks; 1px `--color-divider` between rows.

## Theming
Colors are user-configurable in the shipped product. Keep `--color-accent`, `--color-bg`,
`--color-text` and the derived divider/ramp steps as runtime variables — no component hard-codes a
hex. A **night / NVG** ground is included in the prototype (bg #141514, ink #e6e5e2, accent
#ff563c) and the whole panel inverts from those three values alone.

## Assets
None required. Every mark is type or a plain square — no icons or images. Placeholders that stand in
for real content: the striped **camera feed** panel (replace with the render target), the
**abstracted map** (replace with the in-game map), and the square presence/marker glyphs. If
iconography is wanted, the design system specifies **Lucide**, ink or accent only, at interface
sizes.

## Files
- `tacadmin-console.html` — the console, standalone, opens in a browser. **The primary reference.**
- `screenshots/tacadmin-console.png` — the panel at 2×.
- `screenshots/tacadmin-console-in-shell.png` — the panel inside the device shell and status strip.
  (A couple of wide labels wrap onto two lines in the captures — a rendering artifact of the
  capture, not the design: `.cell` and `.btn` labels are single-line, flush left.)
- `styles.css` — the Modernist token + component sheet the panel is built on.
- `Admin Panel.dc.html` — editable source of the design.
- Related: the comms client this console shares its system with ships as its own handoff
  (`design_handoff_tacmsg_thread_view`).
