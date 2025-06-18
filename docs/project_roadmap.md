# Project Roadmap – DDS-Controller

## 🎯 Vision

Build a modular, object-oriented system that allows precise and intuitive frequency control of the AD9850 DDS module from both local (buttons + LCD) and remote (ESP8266 WebUI/API) sources. Ensure data persistence, USB access, and future scalability.

---

## 📍 Milestones Overview

### MS-001 – Project Initialization

* ✅ Repository setup with agent-based structure
* ✅ AGENTS.md, TODO.md, and structure layout finalized

### MS-002 – Firmware Foundations

* [ ] Arduino Due firmware bootstrapped
* [ ] Menu system operational with LCD + buttons
* [ ] EEPROM read/write tested and mapped

### MS-003 – Communication Protocols

* [ ] ASCII-based command format implemented and validated
* [ ] Serial bridge established between PC ⇄ Arduino ⇄ ESP8266
* [ ] REST endpoints defined and accessible via ESP WebUI

### MS-004 – PC Tools

* [ ] CLI tool (`ddsctl.py`) for manual control
* [ ] GUI prototype (`MainWindow.go`) with serial bridge
* [ ] Config presets and validation routines integrated

### MS-005 – Packaging & Distribution

* [ ] jpackage-based native Windows installer
* [ ] macOS/Linux scripts for CLI/GUI tools
* [ ] Cross-platform USB driver documentation

### MS-006 – UX & Finalization

* [ ] Full menu navigation polished
* [ ] Hungarian UI finalized for LCD + PC GUI
* [ ] Codebase audit, refactor, freeze for 1.0.0 release

---

## 🔮 Future Extensions (Post 1.0)

* OTA firmware updates via ESP
* Mobile UI (React Native or Flutter)
* Graphical frequency visualization
* Multi-device DDS coordination (master-slave)
* Signal modulation modes (sweep, AM/FM)
* WebSocket live preview + control
* Preset export/import via QR or file

---

## 📦 Versioning Strategy

* **v0.x**: Active development, unstable API
* **v1.0.0**: First stable release with full DDS + PC toolchain
* **v1.x**: Minor improvements, UI polish
* **v2.x**: Feature expansions (e.g. modulation, OTA, mobile)

---

## 🔗 Timeline Agent Logging

All roadmap changes must be:

* Logged under `docs/progress/` with timestamp
* Referenced in `MILESTONES.md`
* Confirmed by `root_agent` and acknowledged by `timeline_agent`

---

## Maintainers

* Tankó Ferenc
* ChatGPT Codex
* root\_agent (strategic coordination)
