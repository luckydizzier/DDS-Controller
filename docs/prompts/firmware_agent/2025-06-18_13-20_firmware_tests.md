### Prompt Metadata
Agent: firmware_agent
Task: Expand firmware unit tests
Target File(s): tests/firmware/test_eeprommanager.cpp, tests/firmware/test_commandparser.cpp, tests/firmware/test_menusystem.cpp
Related Docs: docs/design/architecture_overview.md, docs/dev_protocols/command_spec.md

### Prompt Body
Implement Catch2-based tests covering EEPROMManager save/load operations, CommandParser dispatch for all supported commands, and MenuSystem actions for OUTPUT_ON and OUTPUT_OFF. Reuse existing mocks and helper functions. Log results to `docs/progress/YYYY-MM-DD_HH-MM-SS_firmware_agent.md`.
