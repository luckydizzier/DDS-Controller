#!/usr/bin/env python3
import argparse
import serial

from protocol.ascii.constants import (
    CMD_SET_FREQ,
    CMD_GET_FREQ,
    CMD_SAVE,
    CMD_LOAD,
)


def send(port, cmd):
    port.write((cmd + "\n").encode())
    line = port.readline().decode().strip()
    return line


def main():
    parser = argparse.ArgumentParser(description="DDS Controller CLI")
    parser.add_argument("--port", default="/dev/ttyACM0", help="Serial port")
    sub = parser.add_subparsers(dest="cmd", required=True)

    s_freq = sub.add_parser("set-freq")
    s_freq.add_argument("freq", type=int)

    sub.add_parser("get-freq")

    p_save = sub.add_parser("preset-save")
    p_save.add_argument("slot", type=int)

    p_load = sub.add_parser("preset-load")
    p_load.add_argument("slot", type=int)

    args = parser.parse_args()

    with serial.Serial(args.port, 115200, timeout=2) as ser:
        if args.cmd == "set-freq":
            if args.freq <= 0:
                print("ERR:BADFREQ")
                return
            resp = send(ser, f"{CMD_SET_FREQ} {args.freq}")
        elif args.cmd == "get-freq":
            resp = send(ser, CMD_GET_FREQ)
        elif args.cmd == "preset-save":
            resp = send(ser, f"{CMD_SAVE} {args.slot}")
        else:  # preset-load
            resp = send(ser, f"{CMD_LOAD} {args.slot}")

        print(resp)

if __name__ == "__main__":
    main()
