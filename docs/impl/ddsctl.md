# ddsctl Implementation

`ddsctl.py` is a very small CLI wrapper used for quick testing of the ASCII
command protocol from a PC. It currently supports only `setfreq` and `getfreq`
commands and prints simple text responses.

The tool is described in `docs/design/pc_ui_mockups.md` and shares the same
command set as the GUI. In a full implementation it would open the serial port,
validate the command via `protocol/ascii/validator.py` and display the firmware
response.
