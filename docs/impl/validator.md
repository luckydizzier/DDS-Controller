# validator.py

`protocol/ascii/validator.py` offers a simple regex based validator for the ASCII
command protocol. The `VALID_COMMANDS` dictionary defines one pattern per
command as described in `docs/dev_protocols/command_spec.md`.

Use `validate_command(cmd: str) -> bool` to check if an input line matches any of
the allowed patterns. The script can also run interactively from the command line
for quick manual testing.
