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
        if constants.CMD_SET_FREQ.encode() in self.last:
            return b"OK:SETFREQ\n"
        if constants.CMD_GET_FREQ.encode() in self.last:
            return b"OK:FREQ 1000000\n"
        if constants.CMD_SAVE.encode() in self.last or constants.CMD_LOAD.encode() in self.last:
            return b"OK\n"
        return b"OK\n"
    def __enter__(self):
        return self
    def __exit__(self, exc_type, exc, tb):
        pass

serial_stub = types.ModuleType("serial")
serial_stub.Serial = lambda *a, **k: FakeSerial()
sys.modules['serial'] = serial_stub

import pc.cli.ddsctl as ddsctl
from protocol.ascii import constants

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

def test_invalid_freq(capsys, monkeypatch):
    monkeypatch.setattr(sys, 'argv', ['ddsctl', '--port', '/dev/null', 'set-freq', '-1'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert 'ERR:BADFREQ' in out

def test_preset_save(capsys, monkeypatch):
    monkeypatch.setattr(sys, 'argv', ['ddsctl', '--port', '/dev/null', 'preset-save', '1'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert out == 'OK'

def test_preset_load(capsys, monkeypatch):
    monkeypatch.setattr(sys, 'argv', ['ddsctl', '--port', '/dev/null', 'preset-load', '1'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert out == 'OK'
