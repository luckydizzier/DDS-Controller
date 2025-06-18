package main

import (
    "github.com/tarm/serial"
    "sync"
)

type SerialBridge struct {
    port *serial.Port
    mu   sync.Mutex
}

func (s *SerialBridge) Open(name string, baud int) error {
    cfg := &serial.Config{Name: name, Baud: baud}
    p, err := serial.OpenPort(cfg)
    if err != nil {
        return err
    }
    s.port = p
    return nil
}

func (s *SerialBridge) Close() {
    if s.port != nil {
        s.port.Close()
        s.port = nil
    }
}

func (s *SerialBridge) Send(cmd string) (string, error) {
    s.mu.Lock()
    defer s.mu.Unlock()
    if s.port == nil {
        return "", serial.ErrPortClosed
    }
    if _, err := s.port.Write([]byte(cmd + "\n")); err != nil {
        return "", err
    }
    buf := make([]byte, 64)
    n, err := s.port.Read(buf)
    if err != nil {
        return "", err
    }
    return string(buf[:n]), nil
}
