# proj.struct.md – DDS-Controller Project Structure Specification

> 📁 This document defines the entire folder and file hierarchy for the DDS-Controller project.  
> 🧠 Intended to be parsed and executed by a structure-building agent (e.g. `structure_agent`).  
> 📦 Comments begin with `#` and describe purpose and constraints.

---

/DDS-Controller/                     # Root project folder
├── AGENTS.md                        # Root agent coordination and metadata
├── TODO.md                          # Project-wide task list
├── MILESTONES.md                   # Development milestones
├── README.md                        # Project overview and developer info

├── /firmware/                       # Device-level microcontroller code
│   ├── /due/                        # Arduino Due firmware
│   │   ├── main.ino
│   │   ├── DDSDriver.cpp
│   │   ├── MenuSystem.cpp
│   │   ├── EEPROMManager.cpp
│   │   └── CommandParser.cpp
│   ├── /esp/                        # ESP8266 firmware and bridge logic
│   │   ├── main.ino
│   │   └── /web_ui/                 # Optional web-based UI for ESP
│   └── /shared/                     # Shared headers between Due and ESP
│       └── commands.h

├── /protocol/                       # Communication protocols
│   ├── /ascii/                      # Serial ASCII command definitions
│   │   ├── command_format.md
│   │   ├── examples.txt
│   │   └── validator.py
│   ├── /rest/                       # REST interface over ESP
│   │   ├── endpoints.md
│   │   └── examples.http
│   └── /json/                       # JSON message formats (if applicable)

├── /pc/                             # PC-side control interfaces
│   ├── /gui/                        # GUI application (e.g. Go/Fyne or Python/PyQt)
│   │   ├── MainWindow.go
│   │   ├── SerialBridge.go
│   │   └── Views/
│   ├── /cli/                        # Command-line interface
│   │   └── ddsctl.py
│   ├── /config/                     # Saved presets and settings
│   │   └── presets.json
│   ├── /test_tools/                 # Diagnostic tools and local emulators
│   └── /docs/                       # PC-side help and user guide
│       └── user_manual.md

├── /docs/                           # Project documentation (centralized)
│   ├── AGENTS.md                    # Agent index and coordination rules
│   ├── progress/                    # Timestamped logs per agent
│   ├── versions/                    # Changelog entries
│   ├── dev_protocols/              # Developer-facing conventions and rules
│   │   ├── prompt_generation.md
│   │   └── command_spec.md
│   ├── design/                     # Design specifications
│   │   ├── proj.struct.md          # This structure file
│   │   ├── architecture_overview.md
│   │   ├── protocol_layers.md
│   │   ├── storage_map.md
│   │   ├── pc_ui_mockups.md
│   │   └── menu_navigation.md
│   └── prompts/                    # Generated prompts per agent
│       ├── firmware_agent/
│       ├── pc_agent/
│       ├── esp_agent/
│       ├── storage_agent/
│       └── ...

