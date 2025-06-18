# Command Protocol Specification – DDS-Controller

This document defines the structure and constraints of the ASCII-based command protocol used for communication between the system layers (PC ⇄ Arduino ⇄ ESP8266).

---

## 🧾 Command Format (General)

Each command is transmitted as a single ASCII line, terminated with a newline character (`\n`).

### 🔤 Syntax

```
<COMMAND>[ <ARG1>[ <ARG2>...]]\n
```

* Commands and arguments are separated by **single spaces**
* Maximum length: 32 characters per line (excluding `\n`)
* All commands are **case-sensitive**

---

## 🎛️ Command Categories

### 🔹 Control Commands

| Command   | Args                | Description                                   |
| --------- | ------------------- | --------------------------------------------- |
| `SETFREQ` | `<Hz>`              | Set output frequency (e.g. `SETFREQ 1000000`) |
| `GETFREQ` | –                   | Query current frequency setting               |
| `SETWAVE` | `SIN`\|`TRI`\|`SQR` | Set waveform shape                            |
| `GETWAVE` | –                   | Return current waveform                       |
| `RESET`   | –                   | Reset DDS to default state                    |

### 🔹 Storage Commands

| Command | Args | Description                     |
| ------- | ---- | ------------------------------- |
| `SAVE`  | –    | Save current settings to EEPROM |
| `LOAD`  | –    | Load saved settings from EEPROM |

### 🔹 Metadata Commands

| Command   | Args | Description                   |
| --------- | ---- | ----------------------------- |
| `VERSION` | –    | Report firmware version       |
| `STATUS`  | –    | Return current config as text |

---

## 🧪 Response Format

All responses follow this convention:

* Prefix: `OK:` for successful command
* Prefix: `ERR:` for failed command
* For `GET*` and `STATUS`, the return line includes the requested values.

### ✅ Example

```
SETFREQ 5000000\n
→ OK:SETFREQ

GETFREQ\n
→ OK:FREQ 5000000

GETWAVE\n
→ OK:WAVE SIN
```

---

## ⛔ Error Responses

Errors must respond with `ERR:` prefix and reason if available.

```
→ ERR:INVALID_COMMAND
→ ERR:ARG_OUT_OF_RANGE
→ ERR:UNKNOWN_WAVEFORM
```

