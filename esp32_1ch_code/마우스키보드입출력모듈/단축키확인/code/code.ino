// ESP32 2.0.4
// default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)

void macro0();
void macro1();
void macro2();
void macro3();
void macro4();
void macro5();
void macro6();
void macro7();
void macro8();
void macro9();
void macro10();
void macro11();
void macro12();


#define LED1 18
#define LED2 19
#define BTN1 15
#define BTN2 4

#include "hid_device.h"

unsigned long prev_print_millis;
char *msg = "hello arduino hello macro hello keyboard hello mouse ";
int count = 0;

void setup()
{
  Serial.begin(11500);
  
  // LED 및 버튼 초기화
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  // 마우스, 키보드 초기화
  usb_hid_init();

  keyboard_flag = true; // 키보드 전송 모드 ON
  mouse_flag = true; // 마우스 전송 모드 ON
  macro_flag = true; // 매크로 모드 OFF
  echo_mode = true; // 시리얼 모니터에 마우스, 키보드 신호 출력
}

void loop()
{
}

void macro0()
{
  Keyboard.println("MACRO F1");
}

void macro1()
{
  Keyboard.println("MACRO F2");
}

void macro2()
{
  Keyboard.println("MACRO F3");
}

void macro3()
{
  Keyboard.println("MACRO F4");
}

void macro4()
{
  Keyboard.println("MACRO F5");
}

void macro5()
{
  Keyboard.println("MACRO F6");
}

void macro6()
{
  Keyboard.println("MACRO F7");
}

void macro7()
{
  Keyboard.println("MACRO F8");
}

void macro8()
{
  Keyboard.println("MACRO F9");
}

void macro9()
{
  Keyboard.println("MACRO F10");
}

void macro10()
{
  Keyboard.println("MACRO F11");
}

void macro11()
{
  Keyboard.println("MACRO F12");
}
