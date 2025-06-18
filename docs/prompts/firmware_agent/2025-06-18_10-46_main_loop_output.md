### Prompt Metadata
Agent: firmware_agent
Task: Implement main loop and output control
Target File(s): firmware/due/main.ino, firmware/due/MenuSystem.cpp
Related Docs: docs/design/architecture_overview.md

### Prompt Body
Implement the firmware control loop in `firmware/due/main.ino` based on the architecture overview. Instantiate all core modules, set up serial ports, and call `MenuSystem.update()` in `loop()`. In `MenuSystem.cpp`, replace the placeholders under `OUTPUT_ON` and `OUTPUT_OFF` cases with calls that enable or disable the AD9850 output via `DDSDriver`. Keep Hungarian messages for LCD interactions. Log progress to `docs/progress/YYYY-MM-DD_HH-MM_firmware_agent.md`.
