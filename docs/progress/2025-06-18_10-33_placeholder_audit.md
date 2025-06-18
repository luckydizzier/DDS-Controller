# Placeholder Implementation Audit – 2025-06-18 10:33 CEST

The following stub or incomplete sections were identified across the repository.

## Source Files

- **firmware/due/main.ino**: line 1 contains only a placeholder comment.
- **firmware/shared/commands.h**: line 1 placeholder for command constants.
- **firmware/due/MenuSystem.cpp**: lines 247 and 250 include placeholder comments for enabling and disabling the output.
- **firmware/due/mocks/** (`Arduino.h`, `Wire.h`, `Serial.h`): contain minimal stub functions returning default values.

## Documentation

- **docs/impl/main.md**: lines 3–6 describe the main sketch as a placeholder.
- **docs/impl/commands.md**: lines 3–6 note that command definitions are missing.
- **docs/design/project_structure.md**: lines 24 and 47 mark optional directories as placeholders.

## Priorities

| File | Description | Priority |
| --- | --- | --- |
| firmware/due/main.ino | Replace placeholder sketch with initialization and loop logic | High |
| firmware/shared/commands.h | Define shared command constants matching ASCII protocol | High |
| MenuSystem.cpp (lines 247,250) | Implement output control logic | Medium |
| docs/impl/main.md | Expand with implementation details | Medium |
| docs/impl/commands.md | Add actual command list | Medium |
| project_structure.md placeholders | Decide on web_ui and test_tools directories | Low |
| mocks headers | Stubs for PC build; leave as is or document | Low |

