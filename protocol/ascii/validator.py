import re
from .constants import (
    CMD_SET_FREQ,
    CMD_GET_FREQ,
    CMD_SET_WAVE,
    CMD_GET_WAVE,
    CMD_OUTPUT_ON,
    CMD_OUTPUT_OFF,
    CMD_SAVE,
    CMD_LOAD,
    CMD_DELETE,
)

VALID_COMMANDS = {
    CMD_SET_FREQ: rf"^{CMD_SET_FREQ}\s+\d{{1,10}}$",
    CMD_GET_FREQ: rf"^{CMD_GET_FREQ}$",
    CMD_SET_WAVE: rf"^{CMD_SET_WAVE}\s+[0-2]$",
    CMD_GET_WAVE: rf"^{CMD_GET_WAVE}$",
    CMD_OUTPUT_ON: rf"^{CMD_OUTPUT_ON}$",
    CMD_OUTPUT_OFF: rf"^{CMD_OUTPUT_OFF}$",
    CMD_SAVE: rf"^{CMD_SAVE}(\s+\d{{1,2}})?$",
    CMD_LOAD: rf"^{CMD_LOAD}(\s+\d{{1,2}})?$",
    CMD_DELETE: rf"^{CMD_DELETE}\s+\d{{1,2}}$",
}

def validate_command(cmd: str) -> bool:
    cmd = cmd.strip()
    for key, pattern in VALID_COMMANDS.items():
        if re.match(pattern, cmd):
            return True
    return False

if __name__ == "__main__":
    while True:
        user_input = input("Enter command: ")
        if user_input.lower() == 'exit':
            break
        if validate_command(user_input):
            print("✅ Valid command")
        else:
            print("❌ Invalid command")

