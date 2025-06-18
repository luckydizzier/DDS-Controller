# storage\_map.md – EEPROM and Configuration Allocation

This document defines the structured storage layout for non-volatile memory used in the DDS-Controller project.

## 📦 EEPROM Overview

* Type: 24LC256 (I²C, 32KB)
* Connected via TinyRTC module
* Shared between Arduino Due and ESP8266
* Read/write access coordinated via command protocol

## 🧩 Memory Regions

The table below reflects the finalized layout for the 24LC256. Ranges are given in hexadecimal and use little endian encoding.

| Range (hex)    | Size (bytes) | Type          | Description                          |
| -------------- | ------------ | ------------- | ------------------------------------ |
| 0x0000-0x0003  | 4            | `uint32_t`    | Output frequency (Hz)                |
| 0x0004         | 1            | `uint8_t`     | Waveform ID                          |
| 0x0005         | 1            | `uint8_t`     | Settings version ID                  |
| 0x0006-0x00FF  | 250          | —             | Reserved for future config fields    |
| 0x0100-0x017F  | 128          | `Preset`      | Preset slot 1                        |
| 0x0180-0x01FF  | 128          | `Preset`      | Preset slot 2                        |
| 0x0200-0x027F  | 128          | `Preset`      | Preset slot 3                        |
| 0x0280-0x02FF  | 128          | `Preset`      | Preset slot 4                        |
| 0x0300-0x037F  | 128          | `Preset`      | Preset slot 5                        |
| 0x0380-0x7FFF  | 31,872       | —             | Reserved for additional presets/profiles |

## 📖 Encoding Format

* Strings: UTF-8, null-terminated
* Numbers: Little endian
* Frequencies in Hz (uint32), waveforms as ASCII strings

## 🔐 Access Control

* Arduino Due handles boot-time validation and recovery
* ESP8266 allowed only indirect EEPROM updates through Due
* Write-lock mechanism via control flag in config region

## ✅ Initialization Rules

* Upon first boot or reset, EEPROM is initialized with factory values:

  * Project ID: `DDSCTRLv1\0`
  * Presets: Sine, 1kHz default
  * Boot config: Preset 1
  * Menu: Contrast 5, Invert off
  * Ring buffer: empty

## 🔁 Maintenance

* EEPROM integrity check every 5 minutes or on config save
* Checksum per block (CRC8)
* Ring buffer rotates after 512 entries (8 bytes each)

## 📌 Notes

* RTC timekeeping not stored in EEPROM
* EEPROM can be dumped via PC or ESP using ASCII commands
