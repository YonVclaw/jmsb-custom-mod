# Handoff: TAC//MSG — smart-card report forms

## Overview
The full report-template registry of the TAC//MSG comms tacpad (Arma 3, "1st Joint Multi-Functional Strike Battalion"),
rendered as compose forms — one card per registered template. 12 root reports (6-LINE CASEVAC,
MIST, CONTACT REPORT (TIC), CONTACTREP, SITREP, CALL FOR FIRE, CAS REQUEST, AIRFRAME CHECK-IN,
HLZ BRIEF, AIRDROP BRIEF, DEFREP, REACT/QRF LINK-UP) plus the reply set (ROGER / WILCO / ON TASK
one-tap tiles, CANTCO, MESSAGE, CLOSE THREAD forms).

## About the Design Files
Design references created in HTML — **not production code**. Recreate in the target environment
(an Arma 3 dialog/UI layer), following that codebase's patterns. `styles.css` is the design
system's token sheet — port the values and contracts, don't ship the file.

## Contracts carried over from the template registry
- **Line titles are field keys.** The engine builds each field key from the line title, and the
  ALiVE forwarder reads a CONTACTREP's S/A/L/U/T/E/R and a SITREP's Callsign/Location/Enemy/
  Friendly/Civ/Status/Remarks by those keys. Renaming a line title renames a field.
- **The routing line.** DEFREP carries a ROUTING line whose CMD tick also mails the command
  group; it is named by the template's routing option, so it can move.
- Every root report ends with a REMARKS textarea (before ROUTING where one exists).

## Design system
"Modernist" — flat, architectural, Archivo only, red on light grey, zero corner radius, strong
2px borders, 1px row dividers, everything flush left. Micro-labels: uppercase Archivo 800 9.5px /
0.16em (`.k`). Tabular numerals on all numbers.

## Card anatomy
- **Header** — tag box (Archivo 800 10px on ink; **accent fill = high-priority template**:
  CASEVAC, TIC, CFF, CAS, CANTCO) + full template title, 2px bottom border.
- **Badge strip** — `.k` facts on `--color-neutral-200`: task transition (OPENS TASK → ISSUED),
  map anchor line, broadcast/forwarder/routing notes, sender constraints.
- **Lines** — key box (2px ink border, verbatim key: "Line 1", "S", "Warno 3A") + line title,
  then the line's fields, 1px divider between lines.
- **Footer** — SUBJ + the thread-subject pattern verbatim ("CASEVAC {Line2.A} pax — {Line1.A}")
  and the SEND cell (ink fill; hover `--color-accent-600`, press `--color-accent-700`).

## Field types
- **text / callsign / time** — 32px bordered input; optional bold pre-label (EKIA, ALT) at
  min-width 52px. Autofilled fields (own callsign, mission time) show the value + AUTO meta.
- **textarea** — 60px min-height, top-aligned placeholder.
- **number** — same input, tabular, range meta right ("0–99").
- **grid** — input plus attached cells: **CUR LOC** (own position) and **MARKER** (pick a map
  marker). Ingress/egress lines suppress CUR LOC and carry MARKER only.
- **choice** — bordered segmented row; selected cell = ink fill.
- **bool** — 14px square selector (+ colour swatch on GREEN/YELLOW/RED/BLACK lines: green
  oklch(0.55 0.13 145), yellow oklch(0.78 0.14 85), red = accent, black = ink) + bold key +
  dim description. Exclusive groups behave as radios.
- **Field meta** — flush right inside the field, Archivo 800 9px: REQ (accent-700), ranges,
  AUTO, MARKER. Required is never an asterisk.

## Interactions
- Exclusive bool lines: picking one clears the others in the same group.
- CUR LOC stamps the sender's grid; MARKER opens the map-marker picker; grid fields also accept
  a map click.
- SEND validates REQ fields (empty required field: 2px accent border + REQ stays accent), builds
  the subject from the pattern, and opens/updates the thread per the template's transition.
- One-tap replies send immediately and move the thread state (ROGER → RECEIPT, WILCO → ACCEPTED,
  ON TASK → IN PROGRESS); WILCO / ON TASK / CANTCO are assignee-only, CLOSE is issuer-only.
- States: hover 7% ink tint, press full ink / accent-600, focus 2px accent outline at 2px offset.

## Tokens
Same sheet as the rest of the suite: bg #f3f2f2 · ink #201e1d · accent #ec3013 · divider =
ink@40%. Accent reserved for: high-priority tags, REQ meta, RED swatches, SEND hover/press.
Radius 0 everywhere. Cards are 460px wide; masonry columns, 28px gutters.

## Files
- `report-forms.html` — all cards, standalone, opens in a browser. **The primary reference.**
- `screenshots/report-forms-1a-root-reports.png` — the 12 root report forms.
- `screenshots/report-forms-1b-replies.png` — reply tiles + reply forms.
- `styles.css` — the Modernist token + component sheet.
- `Report Forms.dc.html` — editable source (template data lives in the logic class).
- Related: `design_handoff_tacmsg_thread_view`, `design_handoff_tacadmin_console`,
  `design_handoff_combat_support` share this system.
