#!/usr/bin/env python3
import argparse
import os
import serial

from protocol.ascii.constants import (
    CMD_SET_FREQ,
    CMD_GET_FREQ,
    CMD_SAVE,
    CMD_LOAD,
)


def load_pins(path="config/pins.conf"):
  pins = {}
  if not os.path.exists(path):
    print("Warning: pins.conf missing")
    return pins
  with open(path) as f:
    for line in f:
      line = line.strip()
      if not line or line.startswith("#"):
        continue
      if "=" in line:
        k, v = line.split("=", 1)
        pins[k.strip()] = v.strip()
  return pins


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

  pins = load_pins()
  quiet = os.getenv("DDSCTL_QUIET") == "1"
  if not quiet:
    if pins.get("USE_ESP") == "1":
      ota = "enabled" if pins.get("USE_ESP_OTA") == "1" else "disabled"
      print(f"ESP detected, OTA {ota}")
      for key in ["PIN_ESP_RX", "PIN_ESP_TX"]:
        if key not in pins:
          print(f"Warning: {key} undefined")
    print(f"Pin config: {pins}")
    values = [v for k, v in pins.items() if k.startswith("PIN_")]
    if len(values) != len(set(values)):
      print("Warning: pin conflicts detected")

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
