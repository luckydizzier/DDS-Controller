# ESP command finalization
Date: 2025-06-18 20:45 CEST

- added diagnostic macros `CMD_STATUS` and `CMD_VERSION`
- shortened ESP command tokens and introduced `CMD_ESP_VERSION`
- updated `CommandParser` to handle the new constants
- documented all ESP commands in `docs/impl/commands.md`

Affected files:
- `firmware/shared/commands.h`
- `protocol/ascii/constants.py`
- `firmware/due/CommandParser.cpp`
- `docs/impl/commands.md`
