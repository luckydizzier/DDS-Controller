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
    monkeypatch.setenv('DDSCTL_QUIET', '1')
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert out == 'OK'

def test_preset_load(capsys, monkeypatch):
    monkeypatch.setattr(sys, 'argv', ['ddsctl', '--port', '/dev/null', 'preset-load', '1'])
    monkeypatch.setenv('DDSCTL_QUIET', '1')
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert out == 'OK'


def test_show_config(capsys, monkeypatch):
    monkeypatch.setenv('DDSCTL_QUIET', '1')
    monkeypatch.setattr(ddsctl, 'load_pins', lambda path='config/pins.conf': {'A': '1'})
    monkeypatch.setattr(sys, 'argv', ['ddsctl', 'show-config'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert 'A=1' in out


def test_edit_config(capsys, monkeypatch):
    pins = {'A': '1'}
    monkeypatch.setenv('DDSCTL_QUIET', '1')
    monkeypatch.setattr(ddsctl, 'load_pins', lambda path='config/pins.conf', p=pins: p.copy())
    saved = {}
    def fake_save(path, data):
        saved.update(data)
    monkeypatch.setattr(ddsctl, 'save_pins', fake_save)
    monkeypatch.setattr(sys, 'argv', ['ddsctl', 'edit-config', 'A', '2'])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert saved['A'] == '2'
    assert out == 'OK'


def test_ota_upload(capsys, monkeypatch, tmp_path):
    f = tmp_path / 'fw.bin'
    f.write_text('x')
    monkeypatch.setenv('DDSCTL_QUIET', '1')
    monkeypatch.setattr(sys, 'argv', ['ddsctl', 'ota-upload', str(f)])
    ddsctl.main()
    out = capsys.readouterr().out.strip()
    assert 'OK:OTA' in out
