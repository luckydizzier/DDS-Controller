package main

import (
	"bufio"
	"os"
	"strings"
)

type PinConfig map[string]string

func LoadPinsConfig(path string) PinConfig {
	cfg := make(PinConfig)
	f, err := os.Open(path)
	if err != nil {
		return cfg
	}
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		line := strings.TrimSpace(scanner.Text())
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}
		if parts := strings.SplitN(line, "=", 2); len(parts) == 2 {
			cfg[strings.TrimSpace(parts[0])] = strings.TrimSpace(parts[1])
		}
	}
	return cfg
}
