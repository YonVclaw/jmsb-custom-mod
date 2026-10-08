# TAC//MSG — Arma 3 threaded messaging + tacpad suite

Everything produced in this session, in one place. Three designs, two developer handoffs, one
shared visual system.

## What this is
A **diegetic (in-fiction) comms suite** for an Arma 3 milsim unit ("1st Joint Multi-Functional Strike Battalion"), designed as
in-game tablet/tacpad software rather than as a website. Structured military traffic — 9-line
MEDEVAC, CASEVAC, SITREP, FRAGO, contact report, fire mission, patrol/AAR, plus unit-authored
custom templates — is created from **templates** and read in **Slack-style threads** grouped by
**net** (radio channel). A submitted template renders inside its thread as a filled, read-only
structured form, never as prose.

## Visual system — Modernist
Flat and architectural, set entirely in **Archivo**, near-mono **red (#ec3013) on light grey
(#f3f2f2)**, visible modular grid, **zero corner radius anywhere**, strong **2px dividers** between
regions and 1px between rows, everything flush left. Small labels are uppercase Archivo 800 at
9.5px / 0.16em tracking; every number is tabular. Accent is reserved for: selection, FLASH
priority, the primary or destructive action, small numeric emphasis, and alert states — the rest is
ink on ground. No icons were used anywhere; where iconography is wanted the system specifies Lucide.

**Theming is deliberate**: accent, ground and ink are runtime variables (plus a night/NVG ground —
bg #141514, ink #e6e5e2, accent #ff563c), because players will set their own colors. Nothing
hard-codes a hex.

Two colours break the mono rule, and only for squad health, where hue *is* the data: green OK,
yellow WIA, grey unconscious, black KIA/no-link, red for critical traffic. They stay square, not
round, like everything else in the system.

## The three designs

### 1. `designs/Arma3 Comms.dc.html` — the comms client
Four options on one canvas, at 1280×800 (landscape tacpad):
- **1a Standard density** — three panes: nets/roster rail · thread list · thread detail, with the
  9-line rendered as a filled form and a six-up **quick-reply** row (ROGER, WAIT ONE, SMOKE OUT,
  LZ SECURE, NEGATIVE, DICTATE) above the composer. **This is the chosen direction.**
- **1b High density** — every thread as a row in one scanning ops-log table (PRI / TYPE / SUBJECT /
  FROM / GRID / TIME / RPL / ACK) with the detail docked right. For a TOC working volume.
- **1c Glove mode** — one thread at a time, 56px+ targets, template quick-fire tiles. For a
  rifleman holding the tacpad prone.
- **1d The template system** — picker, 9-line fill-out with voice preview, map-attached message +
  FLASH alert banner, and the admin template builder (drag-ordered fields, per-net visibility,
  requires-ack).

### 2. `designs/Admin Panel.dc.html` — TAC//ADMIN console
A redesign of the unit's existing admin panel into the same system, 1440×1000: scrolling player
roster (16-man capable, square scrollbar) with utilities / moderation / mission blocks, an
abstracted map with teleport affordances and a player-layer switcher, a script console
(SERVER / LOCAL / REMOTE scopes, RETURN log), and a player detail column — camera feed, read-only
player info, **skills** (rank, medical, engineering, and EOD / ISR / JFO as independent quals with
an UNSAVED flag and one APPLY), vehicle service, and medical vitals.

### 3. `designs/Live Tiles.dc.html` — how the apps are actually reached in game
The map screen is the shell; apps launch from **live tiles** docked in the bands the vanilla map
leaves free.
- **1a Map screen** — top tile band (DRONES alert · JAM · WEATHER · RADIO), the **threaded message
  reader** docked right with a **net selector** (CMD / PLT / MED / FSC / ALL) and unread counts,
  a restyled **MAP TOOLS** strip along the bottom, and a persistent **squad list** in the left rail
  (16-man, scrolling, one health swatch per man). Reserved zones the design must never cover are
  marked: the vanilla game menu, the **chat overlay** (8 grid cells wide × 2.5 tall, bottom-left),
  and the scale/contour legend (bottom-right).
- **1d Settings — colour scheme** — one gear, in a bar directly under the reader. Four presets
  (Field Grey · Olive · Sand · Night/NVG) shown as three-swatch strips, plus custom: a scheme is
  only ever **ground, ink, accent** — dividers, tints and pressed states derive from those three.
  Squad-health colours (green OK · yellow WIA · grey UNCON · black KIA) are explicitly never themed.
- **1b Tile anatomy and states** — the 176×98 module: kicker + qualifier, one big live value, one
  detail line; rest · alert (accent invert) · warn · stale (50%) · pressed. Values must not resize
  the tile on refresh.
- **1c Tile → full-size app** — SQUAD STATUS opened over the map: full roster table with status,
  grid, ammo, radio and last ping; strength/dispersion summary; related traffic; and the
  originating tile kept in the header as the way back. Grids are **10-digit**; each man carries an
  **ACE** column (A ammunition · C casualties · E equipment, as green / amber / red / black
  swatches), and the right column is a **self-report ACE box** — three segmented pickers, optional
  remarks, and SEND ACE REPORT, which posts to the platoon net and updates that man's ACE column
  for everyone. Actions the game cannot support (ping all, pin squad to map) were cut, and the
  message reader is deliberately absent here — it lives on the map screen.

## Developer handoffs
Two self-sufficient packages, each with a README precise enough to build from without this
conversation (layout, exact px and hex, type, copy, interactions, state model, tokens, theming),
a standalone HTML reference, the token sheet, and 2× screenshots:
- `design_handoff_tacmsg_thread_view/` — the comms client, option 1a.
- `design_handoff_tacadmin_console/` — the TAC//ADMIN console.

## Screenshots
`screenshots/` — every screen at 2×:
- `comms-1a-standard-density.png` · `comms-1b-high-density.png` · `comms-1c-glove-mode.png` ·
  `comms-1d-template-system.png`
- `admin-console.png`
- `live-tiles-1a-map-screen.png` · `live-tiles-1b-tile-anatomy.png` ·
  `live-tiles-1c-squad-status-full.png` · `live-tiles-1d-settings.png`

Each screen is captured twice — `*.png` on the light (Field Grey) scheme and `*-dark.png` on the
Night/NVG scheme — since the whole suite repaints from three tokens and both grounds ship.

A few wide button labels wrap onto two lines in the captures — a rendering artifact of the capture,
not the design: those labels are single-line and flush left.

## Reference pages
Standalone HTML, opens in a browser, light and dark of each:
- `reference/live-tiles.html` / `live-tiles-dark.html`
- `reference/comms-1a.html` / `comms-1a-dark.html`
- `reference/admin-console.html` / `admin-console-dark.html`

The `-dark` pages are the same markup with only the three tokens overridden — proof the whole
suite repaints from ground, ink and accent alone.

## Files
```
README.md                        this file
designs/                         editable source (open the .dc.html files directly)
  Arma3 Comms.dc.html            comms client — 4 options
  Admin Panel.dc.html            TAC//ADMIN console
  Live Tiles.dc.html             live tiles + map screen + full-size app
  support.js, ds/styles.css      runtime + Modernist token sheet the designs load
reference/live-tiles.html        standalone live-tiles reference + styles.css
design_handoff_tacmsg_thread_view/   handoff: comms client 1a (+ screenshots/)
design_handoff_tacadmin_console/     handoff: admin console (+ screenshots/)
```

## Open items
- Drone-detection, jamming, weather and radio apps have tile states but no full-size screens yet.
- Tile behaviour at 21:9 and when the map is zoomed in (collapse to one strip?) is undecided.
- A tile edit/arrange mode is described in copy but not designed.
- CASEVAC and fire-mission fill-out forms are specified but only the 9-line is drawn.
