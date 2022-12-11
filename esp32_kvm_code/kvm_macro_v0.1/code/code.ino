// default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
// Board : ESP-12H KIT Module

#include "kproject_hid_device.h"

void setup()
{
  usb_hid_init();
}

char *msg = "hello arduino hello macro hello keyboard hello mouse ";

int count = 0;
void loop()
{
  int str_len = strlen(msg);
  int val = count % str_len;
  count++;
  Keyboard.press(msg[val]);
  Keyboard.release(msg[val]);
  delay(100);
}
