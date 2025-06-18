package main

import "fyne.io/fyne/v2/app"
import "fyne.io/fyne/v2/widget"

func main() {
    a := app.New()
    w := a.NewWindow("DDS Controller")
    w.SetContent(widget.NewLabel("Hello, DDS"))
    w.ShowAndRun()
}
