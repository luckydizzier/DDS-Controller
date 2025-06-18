# DDSDriver Implementation

`DDSDriver` controls the AD9850 module over four GPIO pins. The driver now
implements the full 40‑bit serial sequence required by the chip and keeps track
of the last programmed frequency and waveform.

## Key Methods

- `begin()` – sets pin modes and performs a reset pulse with safe delays.
- `setFrequency(uint32_t)` / `setFrequency(double)` – computes the tuning word
  for the 125&nbsp;MHz reference clock and shifts out five bytes.
- `setWaveform(uint8_t)` – stores the selected waveform (0..2). Actual shaping
  is handled externally.
- `getFrequency()` / `getWaveform()` – return the last programmed values.

Usage examples are provided in `dev_tools/ddsdriver_example.cpp`.
