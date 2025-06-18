package test

import "gui_test/fyne_stub/widget"

type App struct{}

func NewApp() *App                            { return &App{} }
func (a *App) NewWindow(title string) *Window { return &Window{} }
func (a *App) Quit()                          {}

type Window struct{}

func (w *Window) SetContent(obj interface{}) {}

func Tap(b *widget.Button) {
	if b.OnTapped != nil {
		b.OnTapped()
	}
}
