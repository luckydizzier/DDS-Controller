import sys
import os
import types
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

class FakeSerial:
    def __init__(self, *a, **kw):
        self.last = b""
    def write(self, data):
        self.last = data
    def readline(self):
        if b"SF" in self.last:
            return b"OK:SETFREQ\n"
        return b"OK:FREQ 1000000\n"
    def __enter__(self):
        return self
    def __exit__(self, exc_type, exc, tb):
        pass

serial_stub = types.ModuleType("serial")
serial_stub.Serial = lambda *a, **k: FakeSerial()
sys.modules['serial'] = serial_stub

import pc.cli.ddsctl as ddsctl

def test_set_freq(capsys, monkeypatch):
    monkeypatch.setattr(sys, 'argv', ['ddsctl', '--port', '/dev/null', 'set-freq', '100'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert 'OK:SETFREQ' in out

def test_get_freq(capsys, monkeypatch):
    monkeypatch.setattr(sys, 'argv', ['ddsctl', '--port', '/dev/null', 'get-freq'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert 'OK:FREQ' in out
