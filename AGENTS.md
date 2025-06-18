# AGENTS.md – DDS-Controller Project (Root Agent – Strategic Coordinator)

## 🧭 Project Summary

**DDS-Controller** is a multi-layered, modular system for controlling an AD9850-based Direct Digital Synthesizer (DDS).  
It is based on an **Arduino Due** with local (button+LCD) control, and remote access via **ESP8266-01 WiFi bridge**.  
The system supports EEPROM-stored configuration, USB serial commands, and optional PC-side and web-based control.

This project follows a **file-driven agent-based development model**, coordinated by this document and executed via Codex prompt agents.

---

## 📋 Root Agent Responsibilities

- Defines and evolves the overall system architecture and agent role separation
- Issues prompts to agents based on `TODO.md` entries and milestone progression
- Maintains traceability through `docs/progress/`, `MILESTONES.md`, and `versions/`
- Coordinates prompt standardization via `docs/dev_protocols/prompt_generation.md`
- Oversees agent discipline: single-responsibility, layered structure, clear output location
- Validates and approves version increments and architectural decisions
- Delegates structural generation tasks (e.g. `proj.struct.md` execution)

---

## 🌐 Language & Style Policy

- All **source code, documentation, and agent prompts** must be written in **English**
- End-user interfaces (LCD, web, PC GUI) must use **Hungarian language**
- File structure and logs follow **snake_case** naming conventions
- Time format: `YYYY-MM-DD_HH-MM-SS` in Central European Time (CET/CEST)

---

## 🧩 Active Agents

### ⚙️ `firmware_agent`
- Implements the Arduino Due firmware:
  - `DDSDriver`, `MenuSystem`, `EEPROMManager`, `CommandParser`
- Location: `/firmware/due/`
- Design: `docs/design/architecture_overview.md`

### 🌐 `esp_agent`
- Builds ESP8266 UART bridge + web interface (optional)
- Location: `/firmware/esp/`
- Design: `docs/design/protocol_layers.md`

### 🔄 `protocol_agent`
- Maintains communication protocols: ASCII, REST, JSON
- Location: `/protocol/`
- Spec: `docs/dev_protocols/command_spec.md`

### 🖥️ `pc_agent`
- Develops PC-side control interface (GUI/CLI)
- Location: `/pc/`
- Spec: `docs/design/pc_ui_mockups.md`

### 🧾 `storage_agent`
- Manages EEPROM memory layout and read/write logic (24LC256)
- Location: `/firmware/due/EEPROMManager.cpp`
- Map: `docs/design/storage_map.md`

### 🧪 `validation_agent`
- Defines input constraints, frequency range limits, value safety
- Shared across UI, firmware and protocol agents

### 🧰 `config_agent`
- Handles default boot config, fallback values, and system presets

### 🧱 `docs_agent`
- Generates Markdown documentation for structure, usage, and internal APIs
- Builds `docs/dev_protocols/`, `docs/design/`, `docs/prompts/`

### ⌨️ `structure_agent`
- Executes the project file layout defined in `docs/design/proj.struct.md`

### 🗓️ `timeline_agent`
- Validates and logs progress to `docs/progress/`
- Manages versioning via `docs/versions/`

---

## 🛠️ Supporting Files

- `TODO.md` – Global task list, linked to milestones and agent assignments
- `MILESTONES.md` – Development targets, bound to prompts and logs
- `docs/design/proj.struct.md` – Executable structure specification
- `docs/dev_protocols/prompt_generation.md` – Prompt syntax and dispatch rules
- `docs/prompts/` – Directory for per-agent prompt requests
- `docs/progress/` – All timestamped execution logs
- `docs/versions/` – Version history based on milestone results

---

## 🔄 Prompt Execution Protocol

- Prompts are created by `root_agent` in `docs/prompts/{agent_name}/`
- Each prompt must:
  - Reference its related design doc
  - Define expected output files
  - Be logged by `timeline_agent` after execution
- Prompts follow the format in `prompt_generation.md`

---

## ✅ Project Status

- status: INITIATED  
- mode: layered, file-driven  
- primary language: C++ / Go / Markdown  
- integration-awareness: enabled  
- version: 0.0.1

---

**Maintainer**: `Tankó Ferenc`  
**AI Partner**: `ChatGPT Codex`  
**Last Updated**: 2025-06-18
