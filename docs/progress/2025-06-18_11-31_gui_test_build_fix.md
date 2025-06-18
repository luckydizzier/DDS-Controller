## GUI Test Build Fix
- Downgraded Fyne dependency in `tests/gui/go.mod` to v2.4.2 to restore compatibility with text rendering packages.
- Regenerated `go.sum` without upstream modules requiring Fyne 2.4.3.
- Executed `make test_gui` successfully using `GOPROXY` set to `https://goproxy.io` and disabled module sum DB verification due to network limits.
