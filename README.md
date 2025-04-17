# 📡 DDS Web + Local Controller – Arduino Due

Ez a projekt egy **menüvezérelt AD9850 DDS jelgenerátor** vezérlőrendszer, amely egyszerre kínál **lokális kezelőfelületet (LCD + gombok)** és **távoli elérést WiFi-n keresztül (ESP8266-01)**.

---

## ⚙️ Fő jellemzők

- **Arduino Due** alapú, ARM-alapú nagy teljesítményű platform
- **AD9850 DDS** modul precíz frekvenciageneráláshoz (0–40 MHz)
- **LCD Keypad Shield** a helyi beállításhoz és kijelzéshez
- **ESP8266-01** Web UI parancsvezérléssel (kétirányú UART)
- **EEPROM-alapú** beállításmentés (belső vagy 24LC256 külső)
- **Objektumalapú C++ struktúra**, jól skálázható és átlátható

---

## 🔩 Hardverkomponensek

| Modul         | Csatlakozás  | Funkció                    |
|---------------|--------------|----------------------------|
| Arduino Due   | -            | Fő vezérlő                 |
| AD9850 DDS    | D10–D13      | Jelgenerálás (40 bit GPIO) |
| LCD Keypad    | D4–D9 + A0   | Menü és gombkezelés        |
| ESP8266-01    | UART (Serial1) | Webes interfész          |
| EEPROM (opcionális) | I2C     | Beállításmentés            |

---

## 🖱️ Lokális vezérlés

- **Alapállapot:** frekvencia és jelalak kijelzés
- **SELECT gomb:** menürendszer belépés
- **UP/DOWN:** érték vagy menü léptetés
- **SELECT:** megerősítés / mentés EEPROM-ba

---

## 🌐 Webes interfész (ESP8266 UART-on keresztül)

**Parancsok (ASCII, `\\n` végződéssel):**

| Parancs         | Válasz              |
|------------------|---------------------|
| `SETFREQ=1250000`| `OK` / `ERR`        |
| `GETFREQ`        | `FREQ=1250000`      |
| `SETWAVE=SINE`   | `OK`                |
| `GETWAVE`        | `WAVE=SINE`         |

---

## 💾 EEPROM címkiosztás

```cpp
#define EEPROM_ADDR_FREQ       0   // int32_t
#define EEPROM_ADDR_WAVEFORM   4   // uint8_t (0=SINE, 1=SQUARE)
#define EEPROM_ADDR_RESERVED   8
📂 Kódbázis felépítése
plaintext
Másolás
Szerkesztés
DDS_Controller/
├── DDS_Controller.ino
├── ConfigAddresses.h
├── ConfigStore.{h/cpp}
├── AD9850Driver.{h/cpp}
├── ButtonManager.{h/cpp}
├── DisplayManager.{h/cpp}
├── ESPHandler.{h/cpp}
└── MenuSystem/
    ├── MenuItem.h
    ├── MenuManager.{h/cpp}
    ├── SetFreqMenu.cpp
    └── SetWaveformMenu.cpp
🔧 Fejlesztési állapot
 Rendszerterv

 EEPROM és DDS kezelő

 Menüstruktúra

 Web UART parser

 Teljes integráció + teszt

📜 Licenc
MIT

Készült a Frankie’s Craftlab projekt részeként.
Tervező: Frankie Solid (HA3FJF)


🛠️ Javaslat (opcionális finomhangolás):
UART parancskezelésnél érdemes lehet \r\n támogatás is, mert egyes ESP AT firmware-k ezt használják (kompatibilitási tartalék).

ConfigStore modulnál tehetsz egy bool flaget, hogy a memóriából vagy EEPROM-ból dolgozzon (debug vs prod mód).

Az ESPHandler később bővíthető lehet websocketre vagy akár JSON-üzenet kezelésre – érdemes már most úgy strukturálni, hogy ez ne fájjon.

