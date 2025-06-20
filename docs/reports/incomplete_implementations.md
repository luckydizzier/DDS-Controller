## TODO.md
- [x] `Line 1`: "- [DONE] (storage_agent) Implement EEPROMManager class" (TODO)
- [ ] `Line 2`: "- [IN_PROGRESS] (docs_agent) Maintain style guide and agent docs" (TODO)
- [ ] `Line 3`: "- [TODO] (root_agent) Keep structure spec in sync with repository" (TODO)
- [x] `Line 4`: "- [DONE] (Stage 21, firmware_agent) Implement main loop in firmware/due/main.ino" (TODO)
- [x] `Line 5`: "- [DONE] (Stage 21, protocol_agent) Define shared command constants in firmware/shared/commands.h" (TODO)
- [x] `Line 6`: "- [DONE] (Stage 21, firmware_agent) Handle OUTPUT_ON and OUTPUT_OFF in MenuSystem.cpp" (TODO)
- [x] `Line 7`: "- [DONE] (Stage 21, docs_agent) Expand docs/impl/main.md and docs/impl/commands.md" (TODO)
- [ ] `Line 8`: "- [TEST] (pc_agent) Add test for invalid frequency input in ddsctl" (TEST)
- [ ] `Line 9`: "- [TEST] (pc_agent) Add tests for preset-save and preset-load commands" (TEST)
- [ ] `Line 10`: "- [TEST] (firmware_agent) Test EEPROMManager read/write and preset functions" (TEST)
- [ ] `Line 11`: "- [TEST] (firmware_agent) Expand CommandParser coverage for all commands" (TEST)
- [ ] `Line 12`: "- [TEST] (firmware_agent) Verify MenuSystem actions for OUTPUT_ON and OUTPUT_OFF" (TEST)
- [ ] `Line 13`: "- [TEST] (pc_agent) Add GUI tests for Set and Read button callbacks" (TEST)

## MILESTONES.md
- `Line 6`: "- [ ] Windows packaging for Qt GUI" (incomplete)
- `Line 8`: "- [ ] ESP protocol implementation" (incomplete)
- `Line 9`: "- [ ] Web UI" (incomplete)
- `Line 10`: "- [ ] EEPROM preset handling" (incomplete)

## docs/progress/2025-06-18_08-02-34_timeline_agent_cleanup.md
- `Line 6`: "- Kept `ButtonManager.*` pending migration since required for current build." (pending)

## docs/progress/2025-06-18_10-16_root_agent_full_audit.md
- `Line 6`: "Structure mostly follows `project_structure.md`, but extra directories (`dev_tools/`, `tests/`, `logs/`) are undocumented." (follow-up)
- `Line 7`: "Some placeholder files (e.g. `firmware/due/main.ino`) remain." resolved
- `Line 29`: "`TODO.md` still lists tasks already completed (e.g. ESP bridge skeleton, firmware implementations)." (cleanup)
- `Line 30`: "`MILESTONES.md` lacks updates beyond basic stubs." (follow-up)

## docs/progress/2025-06-18_10-33_placeholder_audit.md
- `Line 7`: "- **firmware/due/main.ino** implemented" (resolved)
- `Line 8`: "- **firmware/shared/commands.h** implemented" (resolved)
- `Line 9`: "- **firmware/due/MenuSystem.cpp** output control implemented" (resolved)
- `Line 10`: "- **firmware/due/mocks/** (`Arduino.h`, `Wire.h`, `Serial.h`): contain minimal stub functions returning default values." (stub)
- `Line 14`: "- **docs/impl/main.md** updated" (resolved)
- `Line 15`: "- **docs/impl/commands.md** completed" (resolved)
- `Line 16`: "- **docs/design/project_structure.md**: lines 24 and 47 mark optional directories as placeholders." resolved

## docs/design/project_structure.md
- `Line 24`: "│   │   └── /web_ui/                 # Optional web-based UI for ESP resolved" resolved
- `Line 47`: "│   ├── /test_tools/                 # Diagnostic tools and local emulators resolved" resolved

## docs/impl/main.md
- `Line 3`: "The `firmware/due/main.ino` sketch will initialise all firmware modules and run" (updated)
- `Line 4`: "the main loop. At the moment it is only a placeholder." (updated)

## pc/test_tools/README.md
- `Line 1`: "# Test Tools" (stub documentation)

## firmware/due/mocks/Serial.h
- `Line 10`: "void begin(unsigned long) {}" (stub)
- `Line 11`: "bool available() { return false; }" (stub)
- `Line 12`: "char read() { return 0; }" (stub)
- `Line 13`: "std::string readStringUntil(char) { return {}; }" (stub)

## firmware/due/mocks/Wire.h
- `Line 8`: "void begin() {}" (stub)
- `Line 13`: "int available() { return 0; }" (stub)

## firmware/due/mocks/Arduino.h
- `Line 15`: "inline void pinMode(int, int) {}" (stub)
- `Line 17`: "inline int analogRead(int) { return 0; }" (stub)
- `Line 18`: "inline unsigned long millis() { return 0; }" (stub)

## firmware/due/mocks/LiquidCrystal.h
- `Line 6`: "LiquidCrystal(int,int,int,int,int,int) {}" (stub)
- `Line 8`: "void clear() {}" (stub)

