# MainWindow Implementation

`pc/gui/MainWindow.go` contains the entry point for the planned Go/Fyne based
GUI. The current version only opens a window with a static label, but the design
in `docs/design/pc_ui_mockups.md` shows the intended layout with frequency
controls, waveform selection and serial port management.

Future work will connect to `SerialBridge.go` for USB communication and mirror
the same commands defined for the CLI tool. The window is created via
`fyne.io/fyne/v2/app` and uses standard Fyne widgets.
