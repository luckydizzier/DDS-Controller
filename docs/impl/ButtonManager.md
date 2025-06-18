# ButtonManager Implementation

`ButtonManager` abstracts the analog keypad of the LCD shield. It reads the
shared analog pin and resolves it to one of the `ButtonCode` values defined in
`ButtonManager.h`.

## Key Methods
- `begin()` – sets up the button pin for input and resets internal state.
- `update()` – should be called periodically; reads the analog value and applies
  simple debounce filtering.
- `isPressed(code)` – returns `true` while the given button is held down.
- `wasReleased(code)` – detects button release events used for menu navigation.

The analog thresholds and debounce delay (50 ms) are hard coded. The module is
used by `MenuSystem` to drive the UI state machine as shown in
`docs/design/menu_navigation.md` and referenced in progress logs such as
`2025-06-18_0436_firmware_agent_menu.md`.
