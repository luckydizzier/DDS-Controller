# MenuSystem Implementation

The `MenuSystem` class implements the LCD based user interface described in
`docs/design/menu_navigation.md`. It manages a hierarchy of `MenuItem` structs
and tracks the current state using the `MenuID` enum.

## Construction
`MenuSystem(LiquidCrystal&, ButtonManager&, EEPROMManager&, DDSDriver&)` sets up
references to the dependencies. On startup the last saved frequency and waveform
are loaded from EEPROM and applied via `DDSDriver`.

## Runtime Flow
`update()` should be called in the main loop. It polls the buttons,
processes navigation or editing states and finally updates the display.
Internal helpers:
- `navigate()` – handles button driven state transitions and edit contexts.
- `applyAction(MenuID)` – executes non-navigational actions like saving values.
- `display()` – renders the parent label and current menu item on the LCD.

Frequency editing is clamped between 1 Hz and 40 MHz with a 1 kHz step as noted
in progress log `2025-06-18_0459_firmware_agent_menusystem_review.md`.
Preset management actions rely on `EEPROMManager` and were added in
`2025-06-18_07-42-12_firmware_agent_presets.md`.
