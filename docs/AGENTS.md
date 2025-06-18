# Documentation Agents

This project uses several specialized agents that collaborate through files and prompts. Below is a brief summary of their roles.

- **root_agent** – enforces documentation presence and alignment with project structure. Triggers updates for every undocumented source file and version gap.
- **firmware_agent** – maintains Arduino Due firmware under `firmware/due/`.
- **esp_agent** – handles ESP8266 firmware in `firmware/esp/`.
- **protocol_agent** – defines communication formats within `protocol/`.
- **pc_agent** – develops CLI and GUI tools inside `pc/`.
- **storage_agent** – manages EEPROM layout and persistence logic.
- **validation_agent** – enforces value ranges and command correctness.
- **config_agent** – supplies default system presets.
- **docs_agent** – responsible for real-time documentation of all modules and logic. Audits progress and updates logs. Documents all newly created code components automatically.
- **structure_agent** – applies `docs/design/project_structure.md`.
- **timeline_agent** – logs progress to `docs/progress/` and maintains `docs/versions/`.

Each agent should keep its logs in `docs/progress/` and follow the formatting rules in the style guide.
