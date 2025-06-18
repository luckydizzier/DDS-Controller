# Go Test Coverage

This report summarizes the latest attempt to measure unit test coverage for the Go components of the project.

## Coverage Attempt

`go test ./... -coverprofile=coverage.out`

Execution failed because the module dependencies (for the Fyne GUI) could not be downloaded in the current environment. The proxy blocked requests to `storage.googleapis.com` which hosts the modules.

No coverage data was produced. A placeholder `coverage.out` file is kept for reference.

## Next Steps

- Provide offline vendored copies of third party packages so tests can run without internet access.
- Increase test coverage by adding unit tests for the GUI logic and any future Go packages.
- Integrate coverage generation into CI once dependencies are resolved.
