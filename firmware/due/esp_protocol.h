#ifndef ESP_PROTOCOL_H
#define ESP_PROTOCOL_H

#include "../shared/config/config.h"

#ifdef USE_ESP

#ifdef ARDUINO
#include <Arduino.h>
#include <SoftwareSerial.h>
using SerialPort = SoftwareSerial;
#else
#include "mocks/Arduino.h"
#include "mocks/SoftwareSerial.h"
using SerialPort = SoftwareSerialMock;
#endif

class CommandParser;

void esp_begin(SerialPort& serial, CommandParser& parser);
void esp_handle();
void esp_send(const String& cmd);

#endif // USE_ESP

#endif // ESP_PROTOCOL_H
