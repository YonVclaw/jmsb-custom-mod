# Handoff: TAC//MSG — threaded comms tacpad, option 1a (standard density)

## Overview
TAC//MSG is a **diegetic (in-fiction) military messaging app** for an Arma 3 scenario: a rugged
tablet / "tacpad" client where players send and reply to structured radio traffic. Messages are
organised into **nets** (radio channels) and **threads** (Slack-style reply-to-message chains).
Most traffic is created from **templates** — 9-line MEDEVAC, CASEVAC, SITREP, FRAGO, contact
report, fire mission, patrol/AAR, plus unit-authored custom templates — and a submitted template
renders inside its thread as a filled, read-only structured form rather than as prose.

This handoff covers **option 1a only**: the standard-density three-pane thread view (the screen
the user selected). Sibling options in the source file (1b high-density ops log, 1c glove mode,
1d template picker / fill-out / map / builder) are context, not scope.

## About the Design Files
The files in this bundle are **design references created in HTML** — prototypes that show the
intended look, structure and behaviour. They are **not production code to copy**. The task is to
**recreate this design in the target codebase's own environment** (React/Vue/Svelte, a game-UI
layer, SwiftUI, whatever the project uses), following that codebase's established component
patterns, state management and styling approach. If no environment exists yet, pick the most
appropriate framework for the project and implement there.

`styles.css` is the design system's token + component sheet. Port the **tokens and the component
contracts**, don't necessarily ship this file: map `.btn`, `.input`, `.seg`, `.tag`, `.table` onto
the codebase's equivalents if they exist.

## Fidelity
**High fidelity.** Colors, type, spacing, rules and copy are final. Recreate the UI faithfully at
1280×800 (landscape tablet). Static states are drawn; interaction states are specified in words
below and should come from the design system's own hover/active/focus rules, not from browser
defaults.

## Design system
"Modernist" — flat and architectural, set entirely in **Archivo**, near-mono **red on light grey**,
a visible modular grid, **zero corner radius anywhere**, strong **2px dividers**, everything flush
left (including labels inside wide buttons). No rounded corners, no soft hairlines, no floating
cards, no gradients, no icon decoration. Small labels are uppercase Archivo 800 with wide tracking
(the `.k` utility). All numeric readouts (grids, times, frequencies, counts) use
`font-variant-numeric: tabular-nums` (the `.num` utility).

## Screens / Views

### Screen: Thread view — standard density (1a)
**Purpose.** An RTO (radio operator) monitors nets, scans open threads, reads the structured
template at the head of a thread, and replies — by tapping a canned quick reply or typing.

**Frame.** Device shell (`.pad`): `--color-neutral-900` (#2d2b2b) body, 16px 16px 22px padding,
`--shadow-lg`. Above the screen sits a 9px/800/0.18em uppercase status strip (`.padlabel`,
`--color-neutral-500`): `TACPAD MK4` · 6×6px accent square · `TAC//MSG 2.4` · right-aligned
`CH 42.500 · ENCRYPT ON · BATT 84%`.

**Screen canvas.** 1280×800, `display:flex`, row, `overflow:hidden`, background `--color-bg`.
Three columns:

| Column | Width | Notes |
|---|---|---|
| Nets / roster rail | 206px fixed | `--color-surface` fill, 2px right divider |
| Thread list | 346px fixed | 2px right divider |
| Thread detail | flex:1 (728px) | `min-width:0` |

#### 1. Nets / roster rail (206px)
Vertical flex, `--color-surface` (#eae9e9), 2px right divider (`--color-divider`).
- **Brand block** — 14px padding, 2px bottom divider. `TAC//MSG` in Archivo 800 19px/1,
  letter-spacing −0.02em. Beneath it, 7px gap, `.k` in `--color-neutral-700`:
  `TF ALTIS · OP GRAVEL LINE`.
- **NETS group** — 12px vertical padding. `.k` section label "NETS" (`--color-neutral-600`,
  14px side padding, 9px bottom). Rows are 8px/14px padding, flex, 9px gap:
  a 26px-wide `.k` net code, the net name at 13.5px, an optional unread count (`.k .num`).
  Rows: **CMD / Command / 4** — selected: full `--color-accent` fill, `--color-bg` text, name at
  weight 600; PLT / 2nd Platoon; MED / Medical / CCP with count `1` in `--color-accent`;
  FSC / Fires; LOG / Logistics. Unselected codes are `--color-neutral-600`.
- **ON NET · 11 group** — separated by a 2px top divider, same label treatment. Rows 5px/14px,
  13px text, 1px gap: a 7×7px square status marker (filled `--color-text` = online; 1px outline
  + row `opacity:.45` = offline), name, then a `.k` role in `--color-neutral-600`.
  CPT Hale/CO, Doc Riley/MED, ROTARY 1-1/AIR, GUNSLINGER/FSC (offline).
- **Self block** — pinned to the bottom (`margin-top:auto`), 2px top divider, 12px/14px padding.
  30×30px `--color-text` square with `--color-bg` Archivo 800 11px initials "R6", then
  `SGT Vasquez` (13px/600) over `.k` `RTO · 2 PLT` (`--color-neutral-600`).

#### 2. Thread list (346px)
- **Search bar** — 12px padding, 2px bottom divider, flex, 8px gap: `.input` (flex:1,
  placeholder "Filter traffic — type, grid, callsign") + `.btn.btn-primary` "NEW".
- **Tab strip** — 2px bottom divider; four `.k` tabs at 10px/12px padding.
  Active "ALL · 12" is `--color-accent` with a 2px accent underline (`margin-bottom:-2px` so it
  sits on the divider); "OPEN · 5", "MINE · 3", "ACK ✓" are `--color-neutral-600`.
- **Thread rows** — 12px padding, 1px bottom divider. Anatomy, top to bottom:
  1. Meta line (6px bottom): priority chip, `.k` template type, right-aligned `.k .num` timestamp.
     Priority chips — **FLASH**: `--color-accent` fill / `--color-bg` text, 3px/6px padding.
     **PRIORITY** and **ROUTINE**: 1px `--color-divider` outline, `--color-neutral-700` text
     (PRIORITY additionally colours its type label `--color-accent-700` in the dense variant).
  2. Subject — Archivo 800 16px/1.15, uppercase copy.
  3. Preview — 13px/1.4, `--color-neutral-700`, 5px top margin.
  4. Reply meta — `.k`, 9px top margin, `--color-neutral-600`: e.g. "6 REPLIES · 3 UNREAD".
  - **Selected row** (the FLASH MEDEVAC): background `--color-accent-100` (#fff2ef), a **4px left
    border** in `--color-accent`, body copy stepped to `--color-neutral-800`, reply meta and type
    label `--color-accent-800`.
  - **Closed row**: whole row `opacity:.62`.
  - Rows, in order (exact copy): FLASH / 9-LINE MEDEVAC / 04:12 — "MEDEVAC — GRID 043 118" /
    "Doc Riley · 1× URGENT, litter · bird inbound" / "6 REPLIES · 3 UNREAD" · PRIORITY / FRAGO /
    03:41 — "FRAGO 03 — SEIZE KAVALA BRIDGE" / "Effective 0500. 1 PLT support by fire from PL RED."
    / "4 REPLIES · 2 ACK PENDING" · ROUTINE / SITREP / 04:00 — "SITREP 0400 — 2 PLT" / "Holding OBJ
    CEDAR. 2× WIA evac'd. Ammo amber." / "2 REPLIES" · ROUTINE / FIRE MISSION / 03:52 — "FM 04 —
    SUPPRESS TREELINE 061 104" / "GUNSLINGER: shot, over. 4 rds HE in effect." / "7 REPLIES ·
    CLOSED" · ROUTINE / CONTACT / 03:18 (dimmed) — "CONTACT — TECHNICAL, MSR ALPHA" / "Destroyed.
    No friendly casualties. Route clear." / "CLOSED 03:29".

#### 3. Thread detail (flex)
- **Header** — 14px/18px padding, 2px bottom divider, flex row, 14px gap, items flex-start.
  Left: FLASH chip (4px/7px padding) + title in Archivo 800 21px/1.1 — "MEDEVAC — GRID 043 118"
  (the grid uses `.num`). Below, 9px gap, `.k .num` in `--color-neutral-700`:
  "THREAD 0412-M · CMD NET · OPENED 04:12:38 BY DOC RILEY · 6 REPLIES".
  Right: `.btn.btn-secondary` "PIN TO MAP" + `.btn.btn-primary` "ACK", 8px gap.
- **Body** — 18px padding, column, 16px gap.
  - **Template card** — the submitted 9-line, rendered as a form, **2px solid `--color-text`**
    border. Card header: `--color-text` fill, `--color-bg` text, 9px/12px padding, `.k`
    "TEMPLATE · 9-LINE MEDEVAC" and right-aligned `.k .num` "DOC RILEY · 04:12:38" at
    `opacity:.7`. Body: two equal columns split by a 2px divider; each column is a
    `grid-template-columns: 20px 104px 1fr` list of rows at 13px: line number (`.k .num`,
    `--color-neutral-600`), field label (`.k`, `--color-neutral-700`), value (8px vertical
    padding). Critical values are weight 600 in `--color-accent-700` (line 1 grid "043 118",
    line 3 "1 × A — URGENT"). Left column lines 1–5, right column 6–9 plus a "— / RELAYED /
    BDE 04:14 · ACK" row. Values as drawn: 1 LOCATION 043 118 · 2 FREQ / CALL 42.500 · DOC RILEY ·
    3 PATIENTS 1 × A — URGENT · 4 EQUIPMENT D — litter · 5 LITTER / AMB 1 L · 0 A ·
    6 SECURITY N — no enemy · 7 MARKING Green smoke · 8 NATIONALITY A — mil, own force ·
    9 TERRAIN Open field W of road.
  - **Replies** — a single column, 14px gap, **2px left divider** with 14px left padding (the
    thread spine). Each reply: author in Archivo 800 14.5px (uppercase), an optional `.tag`
    (`.tag-accent` for command, `.tag-neutral` otherwise), `.k .num` timestamp in
    `--color-neutral-600`; body 14px/1.5, 4px top margin. Numbers inside body copy get `.num` +
    weight 600 + `--color-accent-700` (e.g. "ETA 08 MIN").
    Replies: CPT HALE / CO / 04:13 — "Copy 9-line. Passing to BDE. Hold marking until bird is two
    out." · ROTARY 1-1 / AIR / 04:16 — "Wheels up. ETA 08 MIN to 043 118. Request LZ brief on
    final." · DOC RILEY / MED / 04:17 — "LZ flat and dry, no wires. Wind light from 270. Green
    smoke on your call."
  - **Attachment chip** (inside the ROTARY 1-1 reply, 9px top margin) — inline-flex, 12px gap,
    1px `--color-divider` border, `--color-surface` fill, 8px/12px padding: `.k`
    "ATTACHED · MAP MARKER" (`--color-neutral-700`), "LZ overlay — 043 118" at 13.5px/600, and a
    `.k` accent link "VIEW ON MAP".
- **Composer** — pinned to the bottom (`margin-top:auto`), 2px top divider, 12px top padding.
  1. `.k` label "QUICK REPLY" (`--color-neutral-600`, 8px bottom margin).
  2. **Quick-reply tiles** — `grid-template-columns: repeat(6, 1fr)`, 8px gap, 12px bottom margin.
     Each tile: 44px tall, **2px solid `--color-text`** border, no fill, flex row, items centred,
     0/10px padding, label Archivo 800 13px flush left. Labels: ROGER · WAIT ONE · SMOKE OUT ·
     LZ SECURE · NEGATIVE. The sixth tile, **DICTATE**, inverts — `--color-text` fill,
     `--color-bg` label, no border, with a 10×10px `--color-accent` square pushed right
     (`margin-left:auto`) as the mic/record indicator.
  3. **Action row** — flex, 8px gap, 10px bottom margin: `.btn.btn-secondary` "+ TEMPLATE",
     "+ GRID", "+ MARKER", then a right-aligned `.k` "REPLY IN THREAD 0412-M"
     (`--color-neutral-600`).
  4. **Input row** — flex, 8px gap: `.input` (flex:1, `min-height:42px`, placeholder
     "Reply to thread…") + `.btn.btn-primary` "SEND" (`min-width:96px`).

## Interactions & Behavior
- **Net select** (rail) — sets the active net, refilters the thread list; selected net is a solid
  accent row. Unread counts per net; MED-style counts render in `--color-accent`.
- **Thread select** (list) — loads the thread in the detail pane, clears that thread's unread
  count, applies the accent-100 + 4px accent left-border selected treatment.
- **Tabs** — ALL / OPEN / MINE / ACK are filters over the same list; active tab takes the accent
  underline. "MINE" = threads the user authored or was addressed in; "ACK" = threads awaiting the
  user's acknowledgement.
- **ACK button** — acknowledges the thread for the current user, decrements the thread's
  "n/m ACK PENDING" counter, and posts a system line into the thread. Becomes disabled
  (`opacity:.45`) once acked.
- **PIN TO MAP** — pins the thread's grid to the shared map overlay.
- **Quick-reply tile tap** — sends that phrase as a reply immediately (single tap, no confirm) and
  appends it to the reply spine. **DICTATE** starts voice capture: while recording, the accent
  square should pulse or hold steady-on; releasing sends the transcript into the input for review.
- **+ TEMPLATE** — opens the template picker (design 1d) scoped to the current net; choosing a
  template opens its fill-out form; submitting posts a template card into the thread.
  **+ GRID** / **+ MARKER** insert a grid reference / map marker attachment.
- **Attachment chip → VIEW ON MAP** — opens the map view centred on the marker.
- **Incoming FLASH traffic** — banner alert over the current view (design 1d, panel 03) with
  primary action, "open thread", and a 60s snooze.
- **Interaction states** — take hover/active from the accent ramp per the design system
  (`.btn-primary` hover `--color-accent-600`, active `--color-accent-700`; `.btn-secondary`
  hover a 7% ink tint, active 14%). Quick-reply tiles should hover to a 7% ink tint and invert on
  press. Keyboard focus is always `2px solid var(--color-accent)` with 2px offset — never a
  browser default ring.
- **Responsive** — designed for a fixed 1280×800 landscape tablet; no reflow required. Below
  ~1100px, collapse the rail to net codes only; below ~800px, drop to list-or-detail (see design
  1c for the low-density single-thread treatment).

## State Management
- `activeNetId` — selected net; drives the thread query.
- `threads[]` — { id, netId, priority: FLASH|PRIORITY|ROUTINE, templateType, subject, preview,
  authorId, gridRef, createdAt, replyCount, unreadCount, ackRequired, ackReceived, ackTotal,
  status: open|closed }.
- `activeThreadId` — selected thread; null shows an empty detail state.
- `activeThread.templateSubmission` — { templateId, fields: [{ line, label, value, emphasis }],
  submittedBy, submittedAt, relayedTo, relayStatus }.
- `activeThread.replies[]` — { id, authorId, authorRole, body, sentAt, attachments[] }.
- `roster[]` — { id, callsign, role, online }.
- `draftReply` — the composer's text; quick-reply taps bypass it and send directly.
- `dictationState` — idle | recording | transcribing.
- Data: threads and replies arrive over the mission's live channel (poll or socket); optimistically
  append the user's own reply, reconcile on server ack. Line 1 (grid), line 2 (freq/callsign) and
  the timestamp are auto-filled from the player's position and radio state.

## Design Tokens
Colors (from `styles.css`, `:root`):
- `--color-bg` #f3f2f2 · `--color-surface` #eae9e9 · `--color-text` #201e1d
- `--color-accent` #ec3013 · `--color-divider` `color-mix(in srgb, #201e1d 40%, transparent)`
- Accent ramp: 100 #fff2ef · 200 #ffe0d9 · 300 #ffc4b8 · 400 #ff9783 · 500 #ff563c · 600 #dd2b0f ·
  700 #ae1800 · 800 #7c1405 · 900 #4d170e
- Neutral ramp: 100 #f8f4f4 · 200 #eae7e7 · 300 #d7d3d3 · 400 #bab6b6 · 500 #9b9797 · 600 #7d7979 ·
  700 #605d5d · 800 #444141 · 900 #2d2b2b
- Accent used only for: the selected net, priority FLASH chips, the primary button, small numeric
  emphasis, the 4px selected-row border, and the DICTATE indicator. Body-size text in the accent
  uses `--color-accent-700`, never `--color-accent` (contrast).

Spacing: `--space-1` 4px · `--space-2` 8px · `--space-3` 12px · `--space-4` 16px ·
`--space-6` 24px · `--space-8` 32px. Screen-level paddings used: 12px (list rows, rail groups),
14px (rail blocks, header), 18px (detail body, header inline).

Radius: **0 everywhere** (`--radius-sm/md/lg` all 0px).

Shadows: `--shadow-sm` `0 1px 2px #2d2b2b@14%` · `--shadow-md` `0 3px 10px #2d2b2b@16%` ·
`--shadow-lg` `0 12px 32px #2d2b2b@22%` (used only on the device shell — nothing inside the
screen is elevated).

Type: **Archivo** 400/600/800 for everything (`--font-heading` = `--font-body`); headings 800,
letter-spacing −0.015em. Sizes in use: 21px/800 thread title · 19px/800 brand · 16px/800 list
subject · 14.5px/800 reply author · 14px/1.5 reply body · 13.5px body · 13px table + roster ·
12.5px meta · 9.5px/800/0.16em uppercase micro-labels (`.k`). Line-height 1.12 for headings,
1.4–1.55 for body. Tabular numerals on every grid, time, frequency and count.

Borders: 2px `--color-divider` between major regions; 1px `--color-divider` between list rows and
inside cards; 2px `--color-text` around the template card and quick-reply tiles; 4px
`--color-accent` on the selected thread row.

## Theming
Colors are user-configurable in the final product. Keep `--color-accent`, `--color-bg`,
`--color-text` (and the derived divider + ramp steps) as runtime variables rather than hard-coded
values; the prototype swaps them at runtime, including an inverted **night / NVG** ground
(bg #141514, ink #e6e5e2, accent #ff563c). Build the screen so no component hard-codes a hex.

## Assets
None. Every mark in the design is type or a plain square — no icons, images or logos were used, and
none are required. If the target codebase wants iconography, the design system specifies **Lucide**,
at interface sizes, in ink or accent only. Placeholder marks that stand in for real UI: the 7×7px
roster status square, the 6×6px status-strip square, the 10×10px DICTATE indicator, and the 30×30px
"R6" initials tile (replace with the player's unit patch or avatar if one exists).

## Files
- `screenshots/1a-standard-density.png` — the screen at 2×, no device shell.
- `screenshots/1a-in-device-shell.png` — the same screen inside the tacpad shell and status strip.
  (In both captures a few wide button labels wrap onto two lines — a rendering artifact of the
  capture, not the design: `.btn` labels are single-line and flush left.)
- `1a-standard-density.html` — the 1a screen, standalone, opens in a browser. **The primary
  reference.**
- `styles.css` — the Modernist design-system token + component sheet the screen is built on.
- `Arma3 Comms.dc.html` — the full source design doc, including the out-of-scope sibling options
  1b (high-density ops log), 1c (glove mode) and 1d (template picker, 9-line fill-out,
  map-attached + FLASH alert, admin template builder). Useful for the interactions referenced
  above and for the eventual next screens.
