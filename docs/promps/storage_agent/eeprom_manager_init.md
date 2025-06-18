# Prompt for storage_agent – EEPROM Manager Initialization

## 🧑‍💻 Task Summary
Create the EEPROMManager class in C++ to read and write persistent configuration to a 24LC256 I²C EEPROM chip connected to the Arduino Due.

## 🔹 Requirements
- [ ] Implement `init()`, `readConfig()`, and `writeConfig()` methods
- [ ] Use I²C address `0x50`, page size `64 bytes`
- [ ] Define a `struct Config` with fields:
    - `float outputFrequency`
    - `uint8_t waveformType`
    - `char deviceLabel[16]`
- [ ] Store data at EEPROM offset `0x00`, serialized as binary
- [ ] Use `Wire.h` for I²C communication
- [ ] Add basic error checking (I²C ACK failure, out-of-range reads)

## 📄 Documentation
- Reference: `docs/design/storage_map.md`
- Log output to: `docs/progress/2025-06-18_1630_storage_agent.md`

## 🔁 Status Update
- Update `TODO.md`: “EEPROMManager class for I2C EEPROM (24LC256)” → `IN_PROGRESS`
