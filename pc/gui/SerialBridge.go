package main

import "github.com/tarm/serial"

func openPort(name string, baud int) (*serial.Port, error) {
    config := &serial.Config{Name: name, Baud: baud}
    return serial.OpenPort(config)
}
