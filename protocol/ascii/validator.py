import re

VALID_COMMANDS = {
    "SETFREQ": r"^SETFREQ\s+\d{1,10}$",
    "GETFREQ": r"^GETFREQ$",
    "SETPRESET": r"^SETPRESET\s+[a-zA-Z0-9_]{1,20}$",
    "GETPRESETS": r"^GETPRESETS$",
    "DELETEPRESET": r"^DELETEPRESET\s+[a-zA-Z0-9_]{1,20}$",
    "SAVE": r"^SAVE$"
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
