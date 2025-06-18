# REST API – Endpoint Specification

## Overview

This document defines the RESTful API endpoints for the DDS-Controller project. These endpoints provide remote access and control over the system via HTTP, typically served by the ESP8266 module acting as a bridge between the network and the Arduino Due.

All endpoints respond with JSON and use standard HTTP status codes.

---

## Base URL

```
http://<device-ip>/api/v1/
```

---

## Endpoints

### GET /status

* **Description**: Retrieve current DDS status and configuration.
* **Response**:

```json
{
  "frequency": 1234567,
  "waveform": "sine",
  "output": true,
  "temperature_celsius": 24.3,
  "rtc": "2025-06-18T16:42:00"
}
```

### POST /frequency

* **Description**: Set output frequency.
* **Payload**:

```json
{ "value": 1000000 }
```

* **Response**: `{ "ok": true }`

### POST /waveform

* **Description**: Set waveform type.
* **Payload**:

```json
{ "type": "square" } // Options: sine, square, triangle
```

* **Response**: `{ "ok": true }`

### POST /output

* **Description**: Enable or disable DDS output.
* **Payload**:

```json
{ "enable": false }
```

* **Response**: `{ "ok": true }`

### GET /rtc

* **Description**: Get RTC date/time.
* **Response**:

```json
{ "rtc": "2025-06-18T16:42:00" }
```

### POST /rtc

* **Description**: Set RTC date/time.
* **Payload**:

```json
{ "rtc": "2025-06-18T16:45:00" }
```

* **Response**: `{ "ok": true }`

---

## Error Format

```json
{
  "error": "Invalid frequency value"
}
```

---

## Notes

* Ensure CORS headers if accessed from browsers.
* All parameters validated on the ESP8266 before forwarding commands to the Arduino Due.
* Designed for stateless interactions.
