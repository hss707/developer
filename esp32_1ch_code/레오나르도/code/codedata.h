const char pre_code[] PROGMEM = R"rawliteral(
#include "Keyboard.h"

void setup()
{
  Serial.begin(9600);
  Keyboard.begin();
}

void loop()
{
  macro();
  while(1);
}

void send_keyboard2(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7, uint8_t data8)
{
  KeyReport keys;
  keys.modifiers = data1;
  keys.reserved = data2;
  keys.keys[0] = data3;
  keys.keys[1] = data4;
  keys.keys[2] = data5;
  keys.keys[3] = data6;
  keys.keys[4] = data7;
  keys.keys[5] = data8;
  HID().SendReport(2, &keys, sizeof(KeyReport));
}

void macro()
{
)rawliteral";
