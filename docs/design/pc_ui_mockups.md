# pc\_ui\_mockups.md

## 🖥️ PC Interface Mockups – DDS-Controller Project

This document provides visual and structural mockups for the PC-based components of the DDS-Controller system. It includes both CLI (command-line interface) and GUI (graphical user interface) perspectives, mapped to the serial protocol layer and firmware commands.

---

## CLI: `ddsctl.py`

### Overview:

A minimal terminal application for low-level testing, scripting, and serial command transmission. This tool communicates directly with the Arduino Due via USB serial port.

### Example Commands:

```
> ddsctl list-ports
/dev/ttyACM0
/dev/ttyUSB0

> ddsctl send "SETFREQ 14500000"
✅ Acknowledged

> ddsctl read-state
FREQ=14500000Hz
WAVE=SINE

> ddsctl set-waveform SQUARE
✅ Done
```

### CLI Features:

* Serial port enumeration
* Command validation before send
* Interactive and scripted modes
* Response decoding and highlighting

---

## GUI: `MainWindow.go` (Fyne-based)

### General Layout

```
+-----------------------------------------------------------+
| DDS Controller (via USB or WiFi)                          |
+---------------------+-------------------------------------+
| Frequency: [14500000   ] Hz     | [Set] [Read]           |
| Waveform:  ( SINE | SQUARE | TRIANGLE | SAW )           |
|-----------------------------------------------------------|
|  Output Enable: [☑]                                       |
|  EEPROM Sync:   [Write Settings]  [Load Settings]         |
|-----------------------------------------------------------|
|  Connection:   [ Port: /dev/ttyACM0 ] [Connect]           |
|  Status:       Connected, Last Ack OK                    |
+-----------------------------------------------------------+
|                    [ Exit ]                               |
+-----------------------------------------------------------+
```

### GUI Interactions:

* Dropdowns for waveform selection
* Numeric input for frequency
* Port selection from scanned devices
* EEPROM sync buttons (mirroring firmware state)
* Status updates based on serial responses

---

## Synchronization with Protocols

Each button/action in the UI corresponds to a predefined command in `protocol/ascii/command_format.md`, and is validated by `protocol/ascii/validator.py` before being sent.

* `Set` → `SETFREQ <value>`
* `Waveform dropdown` → `SETWAVE <type>`
* `Write Settings` → `SAVE`
* `Load Settings` → `LOAD`
* `Connect` → port open + ping (`PING`)

---

## Notes

* GUI uses Go’s Fyne framework for native cross-platform feel
* CLI is written in Python for rapid testing and scripting support
* Both use shared ASCII protocol defined in `protocol/ascii/`
* Future mobile apps may mimic GUI flow and command mapping
