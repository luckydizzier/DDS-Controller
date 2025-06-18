#include "MenuSystem.h"

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
        {ID::SHOW_VERSION, ID::RESET_DEFAULTS, ID::EXIT_MENU, ID::MAIN_MENU}, 3, false},
    // SHOW_VERSION
    {ID::SHOW_VERSION, "Firmware", ID::SYSTEM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // RESET_DEFAULTS
    {ID::RESET_DEFAULTS, "Alap\xE9rt\xE9k", ID::SYSTEM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
    // EXIT_MENU
    {ID::EXIT_MENU, "Kil\xE9p\xE9s", ID::SYSTEM_MENU,
        {ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU, ID::MAIN_MENU}, 0, false},
};
// clang-format on

constexpr size_t MENU_COUNT = sizeof(MENU) / sizeof(MENU[0]);

bool editing = false;
uint32_t editValue = 0;
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
  freq = eeprom.readFreq();
  dds.setFrequency(freq);
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
  if (editing) {
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
      editing = false;
      freq = editValue;
      dds.setFrequency(freq);
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
      editing = true;
      editValue = freq;
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
    eeprom.writeFreq(freq);
    break;
  case FREQ_LOAD:
    freq = eeprom.readFreq();
    dds.setFrequency(freq);
    break;
  case WAVE_SINE:
    dds.setWaveform(0);
    break;
  case WAVE_SQUARE:
    dds.setWaveform(1);
    break;
  case WAVE_TRIANGLE:
    dds.setWaveform(2);
    break;
  case OUTPUT_ON:
    // placeholder for output enable
    break;
  case OUTPUT_OFF:
    // placeholder for output disable
    break;
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
  if (editing) {
    lcd.print(editValue);
    lcd.print(" Hz");
  } else if (item.editable) {
    lcd.print(freq);
    lcd.print(" Hz");
  } else {
    lcd.print(item.label);
  }
}
