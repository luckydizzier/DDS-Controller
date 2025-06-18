//go:build fyne_stub

package main

import (
	"gui_test/fyne_stub/test"
	"gui_test/fyne_stub/widget"
	"testing"
)

type mockBridge struct{}

func (m *mockBridge) Open(name string, baud int) error { return nil }
func (m *mockBridge) Close()                           {}
func (m *mockBridge) Send(cmd string) (string, error)  { return "OK", nil }

func TestConnectButton(t *testing.T) {
	a := test.NewApp()
	defer a.Quit()
	w := a.NewWindow("")

	bridge := &mockBridge{}
	portEntry := widget.NewEntry()
	status := widget.NewLabel("Disconnected")

	connectBtn := widget.NewButton("Connect", func() {
		if err := bridge.Open(portEntry.Text, 115200); err == nil {
			status.SetText("Connected")
		} else {
			status.SetText("Error")
		}
	})

	portEntry.SetText("/dev/null")
	test.Tap(connectBtn)
	if status.Text != "Connected" {
		t.Fatalf("expected Connected, got %s", status.Text)
	}

	w.SetContent(widget.NewLabel(""))
}
