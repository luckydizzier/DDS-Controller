package widget

type Entry struct{ Text string }

func NewEntry() *Entry            { return &Entry{} }
func (e *Entry) SetText(s string) { e.Text = s }

func NewLabel(s string) *Label { return &Label{Text: s} }

type Label struct{ Text string }

func (l *Label) SetText(s string) { l.Text = s }

func NewButton(label string, tapped func()) *Button {
	return &Button{OnTapped: tapped}
}

type Button struct {
	OnTapped func()
}
