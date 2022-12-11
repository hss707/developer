// ESP32 2.0.4
// 업로드 옵션 : default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
#include "hid_device.h"

#define CHECK_STOP() if ( check_stop() == false ) return;

volatile int play_flag = 0; // 0 : 정지 , 1 : 재생
volatile unsigned long prev_btn1_change_millis;
volatile int pause_flag = 0; // 1 : 일시정지
volatile unsigned long prev_btn2_change_millis;

void send_keyboard2(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7, uint8_t data8)
{
  uint8_t buffer[8];
  buffer[0] = data1;
  buffer[1] = data2;
  buffer[2] = data3;
  buffer[3] = data4;
  buffer[4] = data5;
  buffer[5] = data6;
  buffer[6] = data7;
  buffer[7] = data8;
  send_keyboard(buffer);
}

void stop_isr()
{
  if ( ( millis() - prev_btn1_change_millis ) < 200 ) return; // debouncing
  play_flag = !play_flag;
  prev_btn1_change_millis = millis();
}

void pause_isr()
{
  if ( ( millis() - prev_btn2_change_millis ) < 200 ) return; // debouncing
  pause_flag = !pause_flag;
  prev_btn2_change_millis = millis();
}

bool check_stop()
{
  while (1)
  {
    if ( play_flag == 0 )
    // 재생 정지된 경우 구동 정지
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      pause_flag = 0;
      return false; // 구동 정지
    }
    else
    {
      digitalWrite(LED1, HIGH);
    }

    if ( pause_flag == 0 )
    // 일시 정지가 아닌 경우 구동
    {
      digitalWrite(LED2, LOW);
      return true;
    }
    digitalWrite(LED2, HIGH);
  }
  return true;
}

void setup()
{
  Serial.begin(11500);
  // 마우스, 키보드 초기화
  usb_hid_init();
  keyboard_flag = true; // 키보드 전송 모드 ON
  mouse_flag = true; // 마우스 전송 모드 ON
  macro_flag = true; // 매크로 모드 OFF
  echo_mode = true; // 시리얼 모니터에 마우스, 키보드 신호 출력
  attachInterrupt(BTN1, stop_isr, RISING);
  attachInterrupt(BTN2, pause_isr, RISING);
  ///////////////////////////////////////////////////////////
  // 레오나르도의 setup의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
}

void loop()
{
  ///////////////////////////////////////////////////////////
  // 레오나르도의 loop의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
  CHECK_STOP();
  macro_code();
  Keyboard.releaseAll();
  play_flag = false;
}

//###########################################
//###    MACRO START    #####################
//###########################################
//###########################################
void macro_code()
{
delay(3421);
send_keyboard2(0,0,4,0,0,0,0,0);
delay(121);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(204);
send_keyboard2(0,0,5,0,0,0,0,0);
delay(121);
send_keyboard2(0,0,6,0,0,0,0,0);
delay(27);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(215);
send_keyboard2(0,0,6,0,0,0,0,0);
delay(152);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(147);
send_keyboard2(0,0,7,0,0,0,0,0);
delay(105);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(153);
send_keyboard2(0,0,8,0,0,0,0,0);
delay(157);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(69);
send_keyboard2(0,0,9,0,0,0,0,0);
delay(110);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(137);
send_keyboard2(0,0,10,0,0,0,0,0);
delay(105);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(168);
send_keyboard2(0,0,11,0,0,0,0,0);
delay(105);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(132);
send_keyboard2(0,0,12,0,0,0,0,0);
delay(84);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(152);
send_keyboard2(0,0,14,0,0,0,0,0);
delay(121);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(142);
send_keyboard2(0,0,13,0,0,0,0,0);
delay(136);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(158);
send_keyboard2(0,0,15,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(873);
send_keyboard2(0,0,16,0,0,0,0,0);
delay(68);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(111);
send_keyboard2(0,0,17,0,0,0,0,0);
delay(95);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(183);
send_keyboard2(0,0,18,0,0,0,0,0);
delay(111);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(68);
send_keyboard2(0,0,19,0,0,0,0,0);
delay(132);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(152);
send_keyboard2(0,0,20,0,0,0,0,0);
delay(163);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(658);
send_keyboard2(0,0,21,0,0,0,0,0);
delay(101);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(68);
send_keyboard2(0,0,22,0,0,0,0,0);
delay(111);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(95);
send_keyboard2(0,0,23,0,0,0,0,0);
delay(131);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(110);
send_keyboard2(0,0,24,0,0,0,0,0);
delay(85);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(116);
send_keyboard2(0,0,25,0,0,0,0,0);
delay(126);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(84);
send_keyboard2(0,0,26,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(262);
send_keyboard2(0,0,27,0,0,0,0,0);
delay(100);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(205);
send_keyboard2(0,0,28,0,0,0,0,0);
delay(79);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(158);
send_keyboard2(0,0,29,0,0,0,0,0);
delay(110);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(173);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(105);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(59);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(105);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(79);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(106);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(73);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(111);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(58);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(2018);
send_keyboard2(0,0,89,0,0,0,0,0);
delay(68);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(111);
send_keyboard2(0,0,90,0,0,0,0,0);
delay(58);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(105);
send_keyboard2(0,0,91,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(283);
send_keyboard2(0,0,92,0,0,0,0,0);
delay(64);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(110);
send_keyboard2(0,0,93,0,0,0,0,0);
delay(69);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(131);
send_keyboard2(0,0,94,0,0,0,0,0);
delay(64);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(324);
send_keyboard2(0,0,95,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(142);
send_keyboard2(0,0,96,0,0,0,0,0);
delay(48);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(142);
send_keyboard2(0,0,97,0,0,0,0,0);
delay(84);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(283);
send_keyboard2(0,0,98,0,0,0,0,0);
delay(73);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(325);
send_keyboard2(0,0,88,0,0,0,0,0);
delay(79);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(623);
send_keyboard2(0,0,89,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,89,90,0,0,0,0);
delay(74);
send_keyboard2(0,0,90,0,0,0,0,0);
delay(11);
send_keyboard2(0,0,90,91,0,0,0,0);
delay(43);
send_keyboard2(0,0,91,0,0,0,0,0);
delay(68);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(132);
send_keyboard2(0,0,92,0,0,0,0,0);
delay(53);
send_keyboard2(0,0,92,93,0,0,0,0);
delay(63);
send_keyboard2(0,0,93,0,0,0,0,0);
delay(33);
send_keyboard2(0,0,93,94,0,0,0,0);
delay(53);
send_keyboard2(0,0,94,0,0,0,0,0);
delay(53);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(116);
send_keyboard2(0,0,95,0,0,0,0,0);
delay(68);
send_keyboard2(0,0,95,96,0,0,0,0);
delay(90);
send_keyboard2(0,0,95,96,97,0,0,0);
delay(22);
send_keyboard2(0,0,96,97,0,0,0,0);
delay(37);
send_keyboard2(0,0,97,0,0,0,0,0);
delay(69);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(68);
send_keyboard2(0,0,98,0,0,0,0,0);
delay(85);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(231);
send_keyboard2(0,0,88,0,0,0,0,0);
delay(95);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
}
//###########################################
//###    MACRO END      #####################
//###########################################
//###########################################
