# menu\_navigation.md – DDS-Controller Menu System Overview

## 🎛️ Menu Architecture

The menu system on the Arduino Due enables local control of the AD9850 DDS module via an LCD + keypad interface. It follows a hierarchical, state-driven model, allowing users to configure frequency, waveform type, and EEPROM settings.

### Navigation Controls

* `UP` / `DOWN` → Move between menu items
* `SELECT` → Enter submenu or confirm selection
* `ESC` → Go back / cancel action
* `LEFT` / `RIGHT` → Adjust numeric values (where applicable)

### Root Menu Structure

```text
Main Menu
├── Set Frequency
│   └── [xxx.xxx kHz/MHz]
├── Select Waveform
│   ├── Sine
│   ├── Square
│   └── Triangle
├── EEPROM Options
│   ├── Save Current Config
│   ├── Load Last Saved
│   └── Reset to Defaults
├── Communication
│   ├── USB Status: [CONNECTED/DISCONNECTED]
│   ├── WiFi Status: [CONNECTED/DISCONNECTED]
│   └── Ping Test
└── System Info
    ├── Firmware Version
    ├── Device ID
    └── Uptime
```

## 🧠 Internal Logic

* Implemented via a `MenuState` class with state transitions handled through button interrupts.
* Each screen refreshes on value change to minimize flicker.
* Long-press `SELECT` resets the menu to the root.

## 🗂️ EEPROM Integration

* Menu selections can be loaded from/saved to the 24LC256 EEPROM.
* Default presets are stored in flash and can be restored manually.

## 🔌 Remote Triggers

* Menu state may change remotely via serial/WiFi commands (see: `command_spec.md`).
* The LCD will reflect changes initiated externally, ensuring UI consistency.

## 🚧 Under Development

* Advanced diagnostics screen
* Real-time waveform preview (LCD pattern based)
* Menu-based firmware update trigger

## 🔗 Related Docs

* `storage_map.md`
* `command_spec.md`
* `architecture_overview.md`
