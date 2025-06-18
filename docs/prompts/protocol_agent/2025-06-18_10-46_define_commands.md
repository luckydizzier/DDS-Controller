### Prompt Metadata
Agent: protocol_agent
Task: Define shared command constants
Target File(s): firmware/shared/commands.h
Related Docs: docs/dev_protocols/command_spec.md

### Prompt Body
Populate `firmware/shared/commands.h` with constant strings for all supported ASCII commands as specified in `command_spec.md`. Include at least frequency set, waveform set, output enable/disable, and configuration load/save commands. Use uppercase names with `CMD_` prefix. Log the update to `docs/progress/YYYY-MM-DD_HH-MM_protocol_agent.md`.
