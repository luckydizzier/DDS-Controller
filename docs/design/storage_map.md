# storage\_map.md – EEPROM and Configuration Allocation

This document defines the structured storage layout for non-volatile memory used in the DDS-Controller project.

## 📦 EEPROM Overview

* Type: 24LC256 (I²C, 32KB)
* Connected via TinyRTC module
* Shared between Arduino Due and ESP8266
* Read/write access coordinated via command protocol

## 🧩 Memory Regions

| Offset (hex) | Size (bytes) | Description                  | Access      |
| ------------ | ------------ | ---------------------------- | ----------- |
| 0x0000       | 64           | Project identifier + version | R           |
| 0x0040       | 128          | Preset 1                     | R/W         |
| 0x00C0       | 128          | Preset 2                     | R/W         |
| 0x0140       | 128          | Preset 3                     | R/W         |
| 0x01C0       | 128          | Preset 4                     | R/W         |
| 0x0240       | 128          | Preset 5                     | R/W         |
| 0x02C0       | 64           | Default boot config          | R/W         |
| 0x0300       | 128          | Menu UI settings             | R/W         |
| 0x0380       | 256          | Reserved for expansion       | R/W         |
| 0x0480       | 4096         | EEPROM ring buffer (logging) | Append-Only |

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
