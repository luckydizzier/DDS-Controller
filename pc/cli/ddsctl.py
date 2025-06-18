#!/usr/bin/env python3
import argparse


def main():
    parser = argparse.ArgumentParser(description="DDS Controller CLI")
    parser.add_argument("command", choices=["setfreq", "getfreq"], help="Command")
    parser.add_argument("value", nargs="?", help="Value for command")
    args = parser.parse_args()

    if args.command == "setfreq" and args.value:
        print(f"Setting frequency to {args.value} Hz")
    elif args.command == "getfreq":
        print("Current frequency: 0 Hz")
    else:
        parser.print_help()

if __name__ == "__main__":
    main()
