# architecture\_overview\.md – DDS-Controller System Architecture

> 📅 Last updated: 2025-06-18
> 🛠️ Maintainer: root\_agent
> 🌐 Scope: Entire DDS-Controller hardware-software stack

---

## 📊 Overview

DDS-Controller is a modular, multi-layered embedded control system designed to operate a Direct Digital Synthesizer (AD9850) using an Arduino Due platform. It supports:

* **Local control** via an LCD Keypad Shield
* **Remote control** via ESP8266-01 WiFi bridge
* **Persistent configuration** stored in external I2C EEPROM (24LC256)
* **PC-side monitoring and control** via USB CLI or GUI

The system is structured into three functional layers:

---

## ⚙️ 1. Device Layer

### Components:

* **Arduino Due** – Core controller running C++ firmware
* **AD9850 DDS Module** – Frequency generator (0–40 MHz)
* **24LC256 EEPROM** – I2C configuration storage
* **LCD Keypad Shield** – Menu navigation interface
* **ESP8266-01** – UART bridge + optional REST API
* **(optional)** DS18B20 – Temperature sensor for environment feedback

### Key Modules:

* `DDSDriver` – Serial control logic for AD9850
* `MenuSystem` – UI state machine using LCD and buttons
* `EEPROMManager` – Handles config struct I/O over I2C
* `CommandParser` – Unified input handler (USB/UART)

---

## 🚁 2. Protocol Layer

### Purpose:

Standardizes communication between subsystems.

### Channels:

* **USB (CDC)** – Direct CLI control from PC
* **UART** – Communication with ESP8266
* **WiFi/REST** – Remote control via HTTP API

### Protocols:

* **ASCII command protocol** (Due <-> ESP/PC)
* **JSON messages** (future-proofing for REST/UI)
* **EEPROM binary format** for config struct

---

## 💻 3. PC Layer

### Tools:

* **CLI Tool** (`ddsctl.py`) for command-line control
* **GUI App** (`MainWindow.go`) for frequency setting and monitoring
* **Presets Manager** – Load/save config profiles locally

### Functions:

* Send commands to Due over USB
* Display status and device info
* Manage EEPROM presets
* (Optional) upload firmware to ESP/Due

---

## 🔌 Inter-layer Communication Summary

| Source        | Target      | Method    | Protocol      |
| ------------- | ----------- | --------- | ------------- |
| PC CLI/GUI    | Arduino Due | USB (CDC) | ASCII         |
| PC Web Client | ESP8266     | WiFi      | HTTP REST     |
| ESP8266       | Arduino Due | UART      | ASCII         |
| Arduino Due   | EEPROM      | I2C       | Binary struct |

---

## 📖 Related Documents

* `docs/design/proj.struct.md` – Folder/file structure
* `docs/design/storage_map.md` – EEPROM layout
* `docs/design/protocol_layers.md` – Protocol specs and message format
* `docs/design/pc_ui_mockups.md` – GUI design and UX
* `docs/dev_protocols/prompt_generation.md` – Agent prompt format
