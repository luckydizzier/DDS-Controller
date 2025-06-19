package main

import (
	"fmt"
	"path/filepath"

	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/widget"
)

const (
	cmdSetFreq = "SF"
	cmdGetFreq = "GF"
	cmdSetWave = "SW"
	cmdGetWave = "GW"
)

func main() {
	a := app.New()
	w := a.NewWindow("DDS Controller")

	bridge := &SerialBridge{}

	cfgPath := filepath.Join("..", "..", "config", "pins.conf")
	pins := LoadPinsConfig(cfgPath)
	espLabel := widget.NewLabel("ESP: disabled")
	if pins["USE_ESP"] == "1" {
		status := "no OTA"
		if pins["USE_ESP_OTA"] == "1" {
			status = "OTA"
		}
		espLabel.SetText(fmt.Sprintf("ESP: OK (%s)", status))
	}

	portEntry := widget.NewEntry()
	portEntry.SetText("/dev/ttyACM0")
	status := widget.NewLabel("Disconnected")

	connectBtn := widget.NewButton("Connect", func() {
		if err := bridge.Open(portEntry.Text, 115200); err == nil {
			status.SetText("Connected")
		} else {
			status.SetText("Error")
		}
	})

	freqEntry := widget.NewEntry()
	freqEntry.SetText("1000000")
	waveSelect := widget.NewSelect([]string{"0", "1", "2"}, func(string) {})
	waveSelect.SetSelected("0")

	currentFreq := widget.NewLabel("Freq: -")
	currentWave := widget.NewLabel("Wave: -")

	setBtn := widget.NewButton("Set", func() {
		bridge.Send(cmdSetFreq + " " + freqEntry.Text)
		bridge.Send(cmdSetWave + " " + waveSelect.Selected)
	})

	readBtn := widget.NewButton("Read", func() {
		if resp, err := bridge.Send(cmdGetFreq); err == nil {
			currentFreq.SetText(resp)
		}
		if resp, err := bridge.Send(cmdGetWave); err == nil {
			currentWave.SetText(resp)
		}
	})

	w.SetContent(container.NewVBox(
		container.NewHBox(portEntry, connectBtn),
		status,
		espLabel,
		container.NewHBox(widget.NewLabel("Freq"), freqEntry),
		container.NewHBox(widget.NewLabel("Wave"), waveSelect),
		container.NewHBox(setBtn, readBtn),
		currentFreq,
		currentWave,
	))

	w.ShowAndRun()
}
