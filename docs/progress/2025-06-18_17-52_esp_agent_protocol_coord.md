# esp_agent Log – Protocol Coordination
Date: 2025-06-19 10:55 CEST

- Agreed with protocol_agent on UART frame: `<CMD> [ARG]\n` ASCII lines.
- Heartbeat message `PING\n` expects `PONG\n` within 1s.
- Updated `protocol_layers.md` with message and heartbeat details.
