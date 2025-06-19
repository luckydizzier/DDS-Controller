#include "MenuSystem.h"
#include "../shared/config/config.h"
#include "../shared/commands.h"
#ifdef USE_ESP
#include "esp_protocol.h"
#endif

// ---------------------------------------------------------------------------
// Local state
// ---------------------------------------------------------------------------

namespace {

using ID = MenuSystem::MenuID;
using Item = MenuSystem::MenuItem;

// clang-format off
const Item MENU[] = {
    // MAIN_MENU
    {ID::MAIN_MENU, "F\xF5men\xFC", ID::MAIN_MENU,
        {ID::FREQ_SETTINGS, ID::WAVEFORM_MENU, ID::OUTPUT_CTRL, ID::SYSTEM_MENU}, 4, false},
    // FREQ_SETTINGS
    {ID::FREQ_SETTINGS, "Frekv. Be\xE1ll.", ID::MAIN_MENU,
        {ID::FREQ_EDIT, ID::FREQ_SAVE, ID::FREQ_LOAD, ID::MAIN_MENU}, 3, false},
    // FREQ_EDIT
    {ID::FREQ_EDIT, "Frekvencia [Hz]", ID::FREQ_SETTINGS,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, true},
    // FREQ_SAVE
    {ID::FREQ_SAVE, "Ment\xE9s EEPROM-ba", ID::FREQ_SETTINGS,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // FREQ_LOAD
    {ID::FREQ_LOAD, "Bet\xF6lt\xE9s EEPROM", ID::FREQ_SETTINGS,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // WAVEFORM_MENU
    {ID::WAVEFORM_MENU, "Hull\xE1mforma", ID::MAIN_MENU,
        {ID::WAVE_SINE, ID::WAVE_SQUARE, ID::WAVE_TRIANGLE, ID::MAIN_MENU}, 3, false},
    // WAVE_SINE
    {ID::WAVE_SINE, "Sz\xEDnusz", ID::WAVEFORM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // WAVE_SQUARE
    {ID::WAVE_SQUARE, "N\xE9gysz\xF6g", ID::WAVEFORM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // WAVE_TRIANGLE
    {ID::WAVE_TRIANGLE, "H\xE1romsz\xF6g", ID::WAVEFORM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // OUTPUT_CTRL
    {ID::OUTPUT_CTRL, "Kimenet", ID::MAIN_MENU,
        {ID::OUTPUT_ON, ID::OUTPUT_OFF, ID::MAIN_MENU, ID::MAIN_MENU}, 2, false},
    // OUTPUT_ON
    {ID::OUTPUT_ON, "Bekapcs", ID::OUTPUT_CTRL,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // OUTPUT_OFF
    {ID::OUTPUT_OFF, "Kikapcs", ID::OUTPUT_CTRL,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // SYSTEM_MENU
    {ID::SYSTEM_MENU, "Rendszer", ID::MAIN_MENU,
        {ID::SHOW_VERSION, ID::RESET_DEFAULTS, ID::PRESET_MENU, ID::ESP_MENU}, 4, false},
    // SHOW_VERSION
    {ID::SHOW_VERSION, "Firmware", ID::SYSTEM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // RESET_DEFAULTS
    {ID::RESET_DEFAULTS, "Alap\xE9rt\xE9k", ID::SYSTEM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // PRESET_MENU
    {ID::PRESET_MENU, "Presetek", ID::SYSTEM_MENU,
        {ID::PRESET_SAVE, ID::PRESET_LOAD, ID::PRESET_DELETE, ID::SYSTEM_MENU}, 3, false},
    // PRESET_SAVE
    {ID::PRESET_SAVE, "Ment\xE9s Presetbe", ID::PRESET_MENU,
        {ID::PRESET_MENU, ID::PRESET_MENU, ID::PRESET_MENU, ID::PRESET_MENU}, 0, true},
    // PRESET_LOAD
    {ID::PRESET_LOAD, "Bet\xF6lt\xE9s Preset", ID::PRESET_MENU,
        {ID::PRESET_MENU, ID::PRESET_MENU, ID::PRESET_MENU, ID::PRESET_MENU}, 0, true},
    // PRESET_DELETE
    {ID::PRESET_DELETE, "T\xF6rl\xE9s Preset", ID::PRESET_MENU,
        {ID::PRESET_MENU, ID::PRESET_MENU, ID::PRESET_MENU, ID::PRESET_MENU}, 0, true},
    // ESP_MENU
    {ID::ESP_MENU, "WiFi", ID::SYSTEM_MENU,
        {ID::ESP_ON, ID::ESP_OFF, ID::ESP_STATUS, ID::SYSTEM_MENU}, 3, false},
    // ESP_ON
    {ID::ESP_ON, "ESP bekapcs", ID::ESP_MENU,
        {ID::SYSTEM_MENU, ID::SYSTEM_MENU, ID::SYSTEM_MENU, ID::SYSTEM_MENU}, 0, false},
    // ESP_OFF
    {ID::ESP_OFF, "ESP kikapcs", ID::ESP_MENU,
        {ID::SYSTEM_MENU, ID::SYSTEM_MENU, ID::SYSTEM_MENU, ID::SYSTEM_MENU}, 0, false},
    // ESP_STATUS
    {ID::ESP_STATUS, "ESP info", ID::ESP_MENU,
        {ID::SYSTEM_MENU, ID::SYSTEM_MENU, ID::SYSTEM_MENU, ID::SYSTEM_MENU}, 0, false},
    // EXIT_MENU
    {ID::EXIT_MENU, "Kil\xE9p\xE9s", ID::SYSTEM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
};
// clang-format on

constexpr size_t MENU_COUNT = sizeof(MENU) / sizeof(MENU[0]);

constexpr uint32_t FREQ_MIN = 1;
constexpr uint32_t FREQ_MAX = 40000000UL;
constexpr uint32_t FREQ_STEP = 1000;

inline const Item &getItem(ID id) { return MENU[static_cast<int>(id)]; }

} // namespace

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

MenuSystem::MenuSystem(LiquidCrystal &lcdRef, ButtonManager &btns,
                       EEPROMManager &eep, DDSDriver &drv)
    : lcd(lcdRef), buttons(btns), eeprom(eep), dds(drv) {
  freq = eeprom.loadFrequency();
  waveform = eeprom.loadWaveform();
  dds.setFrequency(freq);
  dds.setWaveform(waveform);
  current = ID::FREQ_SETTINGS; // start at first submenu
  lcd.begin(16, 2);
  display();
}

// ---------------------------------------------------------------------------
// Public Update Entry
// ---------------------------------------------------------------------------

void MenuSystem::update() {
  buttons.update();
  navigate();
  display();
}

// ---------------------------------------------------------------------------
// Navigation State Machine
// ---------------------------------------------------------------------------

void MenuSystem::navigate() {
  if (editContext != EditContext::NONE) {
    if (editContext == EditContext::FREQ) {
      if (buttons.isPressed(BUTTON_LEFT)) {
        if (editValue >= FREQ_MIN + FREQ_STEP)
          editValue -= FREQ_STEP;
        else
          editValue = FREQ_MIN;
      }
      if (buttons.isPressed(BUTTON_RIGHT)) {
        if (editValue <= FREQ_MAX - FREQ_STEP)
          editValue += FREQ_STEP;
        else
          editValue = FREQ_MAX;
      }
      if (buttons.wasReleased(BUTTON_SELECT)) {
        freq = editValue;
        dds.setFrequency(freq);
        editContext = EditContext::NONE;
      }
    } else {
      if (buttons.wasReleased(BUTTON_UP)) {
        editPresetId = (editPresetId >= EEPROM_PRESET_COUNT) ? 1 : editPresetId + 1;
      }
      if (buttons.wasReleased(BUTTON_DOWN)) {
        editPresetId = (editPresetId <= 1) ? EEPROM_PRESET_COUNT : editPresetId - 1;
      }
      if (buttons.wasReleased(BUTTON_SELECT)) {
        if (editContext == EditContext::PRESET_SAVE) {
          eeprom.savePreset(editPresetId, freq, waveform);
        } else if (editContext == EditContext::PRESET_LOAD) {
          uint32_t f = freq;
          uint8_t w = waveform;
          eeprom.loadPreset(editPresetId, f, w);
          freq = f;
          waveform = w;
          dds.setFrequency(freq);
          dds.setWaveform(waveform);
        } else if (editContext == EditContext::PRESET_DELETE) {
          eeprom.deletePreset(editPresetId);
        }
        editContext = EditContext::NONE;
        current = ID::PRESET_MENU;
      }
    }
    return;
  }

  const Item &item = getItem(current);

  // Navigate within siblings --------------------------------------------
  if (buttons.wasReleased(BUTTON_UP) || buttons.wasReleased(BUTTON_DOWN)) {
    ID parent = item.parent;
    const Item &p = getItem(parent);
    if (p.childCount > 0) {
      int index = 0;
      for (; index < p.childCount; ++index) {
        if (p.children[index] == item.id)
          break;
      }
      if (buttons.wasReleased(BUTTON_UP)) {
        index = (index == 0) ? p.childCount - 1 : index - 1;
      } else {
        index = (index >= p.childCount - 1) ? 0 : index + 1;
      }
      current = p.children[index];
      return;
    }
  }

  // Go to parent ---------------------------------------------------------
  if (buttons.wasReleased(BUTTON_LEFT)) {
    if (item.parent != item.id) {
      current = item.parent;
    }
    return;
  }

  // Enter child or run action -------------------------------------------
  if (buttons.wasReleased(BUTTON_SELECT)) {
    if (item.editable) {
      if (item.id == ID::FREQ_EDIT) {
        editContext = EditContext::FREQ;
        editValue = freq;
      } else if (item.id == ID::PRESET_SAVE) {
        editContext = EditContext::PRESET_SAVE;
        editPresetId = 1;
      } else if (item.id == ID::PRESET_LOAD) {
        editContext = EditContext::PRESET_LOAD;
        editPresetId = 1;
      } else if (item.id == ID::PRESET_DELETE) {
        editContext = EditContext::PRESET_DELETE;
        editPresetId = 1;
      }
      return;
    }
    if (item.childCount > 0) {
      current = item.children[0];
      return;
    }
    applyAction(item.id);
  }
}

// ---------------------------------------------------------------------------
// Action Handler
// ---------------------------------------------------------------------------

void MenuSystem::applyAction(MenuID action) {
  switch (action) {
  case FREQ_SAVE:
    eeprom.saveFrequency(freq);
    break;
  case FREQ_LOAD:
    freq = eeprom.loadFrequency();
    dds.setFrequency(freq);
    break;
  case WAVE_SINE:
    waveform = 0;
    dds.setWaveform(waveform);
    break;
  case WAVE_SQUARE:
    waveform = 1;
    dds.setWaveform(waveform);
    break;
  case WAVE_TRIANGLE:
    waveform = 2;
    dds.setWaveform(waveform);
    break;
  case OUTPUT_ON:
    digitalWrite(OUTPUT_CONTROL_PIN, HIGH);
    break;
  case OUTPUT_OFF:
    digitalWrite(OUTPUT_CONTROL_PIN, LOW);
    break;
#ifdef USE_ESP
  case ESP_ON:
    esp_send(CMD_ESP_ON);
    break;
  case ESP_OFF:
    esp_send(CMD_ESP_OFF);
    break;
  case ESP_STATUS:
    esp_send(CMD_ESP_STATUS);
    break;
#endif
  case RESET_DEFAULTS:
    freq = 1000000;
    dds.setFrequency(freq);
    break;
  case EXIT_MENU:
    current = MAIN_MENU;
    break;
  default:
    break;
  }
}

// ---------------------------------------------------------------------------
// LCD Rendering
// ---------------------------------------------------------------------------

void MenuSystem::display() {
  lcd.clear();
  const Item &item = getItem(current);
  const Item &parent = getItem(item.parent);

  lcd.setCursor(0, 0);
  if (item.id == MAIN_MENU) {
    lcd.print(item.label);
  } else {
    lcd.print(parent.label);
  }

  lcd.setCursor(0, 1);
  lcd.print("> ");
  if (editContext != EditContext::NONE) {
    if (editContext == EditContext::FREQ) {
      lcd.print(editValue);
      lcd.print(" Hz");
    } else {
      lcd.print("ID: ");
      lcd.print(editPresetId);
    }
  } else if (item.editable) {
    if (item.id == ID::FREQ_EDIT) {
      lcd.print(freq);
      lcd.print(" Hz");
    } else {
      lcd.print(item.label);
    }
  } else {
    lcd.print(item.label);
  }
}
