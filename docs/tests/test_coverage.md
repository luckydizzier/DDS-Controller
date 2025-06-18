# Go Test Coverage

This report summarizes the latest attempt to measure unit test coverage for the Go components of the project.

## Coverage Attempt

`go test ./... -coverprofile=coverage.out`

Both the original attempt and a second run on **2025‑06‑18 12:02 CEST** failed because the required modules (for the Fyne GUI) could not be downloaded. The proxy blocked requests to `storage.googleapis.com`.

As a result, `coverage.out` only contains the header line and the overall coverage reported by `go tool cover` is **0%**.

## Next Steps

- Provide offline vendored copies of third party packages so tests can run without internet access.
- Increase test coverage by adding unit tests for the GUI logic and any future Go packages.
- Integrate coverage generation into CI once dependencies are resolved.
