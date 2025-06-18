# Protocol Layer Specification – DDS-Controller

## 🧩 Overview

This document defines the protocol layers used in the DDS-Controller project. The system features modular, deterministic communication between the UI (local and remote), the Arduino Due, and the ESP8266-01. Data and commands are exchanged via ASCII-based protocols and structured REST endpoints, backed by clearly separated logical layers.

---

## 📚 Layered Model

### 1. Physical Layer

* **Mediums**:

  * USB (UART bridge between PC ↔ Arduino Due)
  * UART (ESP8266-01 ↔ Arduino Due)
  * I²C (Arduino Due ↔ EEPROM on TinyRTC)
* **Baud Rate**: 115200 8N1 (for UART)

### 2. Transport Layer

* **Protocol**:

  * Serial (ASCII commands over UART)
  * HTTP (REST calls from PC/mobile)
* **Error Detection**: Optional CRC or command echo + timeout handling

### 3. Application Layer

#### ASCII Command Protocol

* Simple ASCII command format:

  ````
  SETFREQ 1000000\n
  GETFREQ\n
  STATUS\n
  SAVE\n  ```
  ````
* Commands are case-insensitive, line-terminated with `\n`
* Responses follow deterministic text structure

#### REST API (optional PC/mobile)

* Used for local network-based access via ESP8266-01
* Endpoints:

  * `/api/frequency` \[GET, POST]
  * `/api/status` \[GET]
  * `/api/save` \[POST]

---

## 🔀 Communication Flow

```text
  [PC UI / CLI] ↔ USB ↔ [Arduino Due] ↔ UART ↔ [ESP8266-01 Web UI]
                                       ↕
                                     I²C
                                       ↕
                                    [EEPROM]
```

### Control Flow Example:

1. `ddsctl.py` sends `SETFREQ 1000000` over USB
2. Arduino parses and updates DDS
3. Response `OK\n` sent back
4. ESP can also query status via UART proxy

---

## 🔒 Design Notes

* All commands are idempotent
* EEPROM save/load guarded by atomic commit
* Protocol decoders are separate from executors
* External commands are validated before execution

---

## 📘 Related Docs

* `docs/dev_protocols/command_spec.md`
* `docs/design/storage_map.md`
* `docs/design/architecture_overview.md`
