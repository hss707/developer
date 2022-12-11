#include "kkeyboard.h"
#include "setting.h"
void force_releaseall();

#include <Adafruit_NeoPixel.h>
#define PIN        38
#define NUMPIXELS  1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define RED_LED 11
#define GREEN_LED 9
#define BLUE_LED 12

#define GREEN_BTN 33
#define RED_BTN 34

#define USE_OTA
#include "kproject_ota.h";

#include <Arduino.h>
#include <Ticker.h>
#include "USB.h"
#include "USBHIDMouse.h"
USBHIDMouse Mouse;

unsigned char default_reset[6] =
{
  0x57, 0xAB, 0x0, 0x0C, 0x0, 0x0E
};

unsigned char set_mode_data[56] =
{

  0x57, 0xAB, 0x0, 0x9, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x25, 0x80, 0x0, 0x0, 0x0, 0x3, 0x86, 0x1A, 0x29, 0xE1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0D, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xBB
};

// 마우스 키보드 제조사 설정 데이타
unsigned char set_manufact[100] =
{
  0x57, 0xAB, 0x0, 0x0B, 0x8, 0x0, 0x6, 0x6A, 0x79, 0x73, 0x6F, 0x66, 0x74, 0xBA
};

unsigned char set_product[100] =
{
  0x57, 0xAB, 0x0, 0x0B, 0x13, 0x1, 0x11, 0x6B, 0x70, 0x72, 0x6F, 0x6A, 0x65, 0x63, 0x74, 0x20, 0x75, 0x73, 0x62, 0x20, 0x68, 0x69, 0x64, 0x20, 0x73
};

// 칩 초기화 하기
void ch9329_initalize()
{
  // 초기화 ( 최초 한번만 실행하면 됨)
  ///////////////////////////////////////////////////////////
  //  Serial1.begin(9600, SERIAL_8N1, 7, 10);
  delay(100);
  for ( int i = 0; i < 6; i++)
  {
    Serial1.write(default_reset[i]);
  }
  delay(1000);
  Serial1.begin(115200, SERIAL_8N1, 7, 10);
  delay(100);
  for ( int i = 0; i < 6; i++)
  {
    Serial1.write(default_reset[i]);
  }
}

void ch9329_set_mode(int mode)
// 통신 속도 및 모드 설정 함수
{
  set_mode_data[5] = mode; // 0 ~ 3 : 0 : 키보드 마우스 CUSTOM , 1 : 키보드 , 2 : 키보드 + 마우스 , 3 : CUSTOM
  /*
    IPAddress ip = WiFi.localIP();
    ch9329_vid = ip[3];
    ch9329_pid = ip[3] * ip[2];;
  */
  set_mode_data[16] = ch9329_vid;
  set_mode_data[17] = ch9329_vid >> 8;
  set_mode_data[18] = ch9329_pid;
  set_mode_data[19] = ch9329_pid >> 8;

  delay(100);
  {
    uint8_t check_sum = 0;
    for ( int i = 0; i < 55; i++)
    {
      Serial1.write(set_mode_data[i]);
      check_sum += set_mode_data[i];
    }
    Serial1.write(check_sum);
  }
}

void ch9329_set_manufact(char *manufact)
// 제조사 설정
{
  int manufact_len = strlen(manufact);
  set_manufact[4] = manufact_len + 2;
  set_manufact[6] = manufact_len;
  strcpy((char*)(set_manufact + 7), manufact);

  delay(100);
  {
    uint8_t check_sum = 0;
    for ( int i = 0; i < manufact_len + 7 ; i++)
    {
      Serial1.write(set_manufact[i]);
      check_sum += set_manufact[i];
    }
    Serial1.write(check_sum);
  }
}

void ch9329_set_product(char *product)
// 제품명 설정
{
  int product_len = strlen(product);
  set_product[4] = product_len + 2;
  set_product[6] = product_len;
  strcpy((char*)(set_product + 7), product);

  delay(100);
  {
    uint8_t check_sum = 0;
    for ( int i = 0; i < product_len + 7 ; i++)
    {
      Serial1.write(set_product[i]);
      check_sum += set_product[i];
    }
    Serial1.write(check_sum);
  }
}

Ticker blinker;

void usb_hid_process();

void led_green()
{
  // 녹색
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
}

void led_blue()
{
  // 파랑색
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
}

void led_red()
{
  // 빨간색
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void led_off()
{
  // 꺼짐
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void led_purple()
{
  // 보라색
  pixels.setPixelColor(0, pixels.Color(255, 0, 255));
  pixels.show();
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
}

void onTimer()
{
  ota_loop(); // WIFI 업로드 LOOP
  usb_hid_process();

  if ( macro_flag == true )
    // 매크로 사용중이면
  {
    led_blue();
  }
  if ( keyboard_flag == true )
  {
    led_red();
  }
  if ( ( macro_flag == false ) && ( keyboard_flag == false ) )
  {
    led_off();
  }
}

volatile unsigned long prev_green_key_changed;
volatile unsigned long prev_red_key_changed;
int prev_green_btn_status;
int prev_red_btn_status;

void IRAM_ATTR green_toggle()
{
  int green_btn_status = digitalRead(GREEN_BTN);
  int red_btn_status = digitalRead(RED_BTN);

  if ( green_btn_status == LOW ) // 녹색 버튼 누른 경우
  {
    // debouncing을 위하여
    if ( ( millis() - prev_green_key_changed ) < 200 ) return;

    prev_green_btn_status = green_btn_status;
    prev_green_key_changed = millis();

    // 구동 내용 ( CTRL + ESC )
    {
      // 키보드 마우스 끄기
      if ( macro_flag == false )
        // 매크로가 구동중이 아니었던 경우
      {
        //        function_key = true;
        Serial.println("ALL MOUSE KEYBOARD OFF");
        green_btn = false;
        red_btn = false;
        macro_flag = false;
        keyboard_flag = false;
        mouse_flag = false;

        force_releaseall();
      }
      else
        // 매크로가 구동중이었던 경우
      {
        green_btn = false;
        red_btn = false;
        keyboard_flag = false;
        mouse_flag = false;

        // 매크로 반영도 하지 않고, 진행도 하지 않음
        macro_status = 0; // 일시 정지
        // releaseall은 check_stop함수에서 실행
        // macro_flag은 check_stop함수에서 변경
        //        function_key = true;
      }
    }
  }
}

void IRAM_ATTR red_toggle()
{
  int green_btn_status = digitalRead(GREEN_BTN);
  int red_btn_status = digitalRead(RED_BTN);

  if ( red_btn_status == LOW ) // 빨간 버튼 누른 경우
  {
    // debouncing을 위하여
    if ( ( millis() - prev_red_key_changed ) < 200 ) return;

    prev_red_btn_status = red_btn_status;
    prev_red_key_changed = millis();

    // 활성화
    // function_key = true;
    Serial.println("ACTIVATE");
    green_btn = true;
    red_btn = false;
    keyboard_flag = true;
    mouse_flag = true;

    // 정지
    macro_status = 0; // 일시 정지
    macro_flag = false;
    force_releaseall();
  }
}

bool check_ch9329()
{
  Serial1.write(0x57);
  Serial1.write(0xAB);
  Serial1.write(0x00);
  Serial1.write(0x01);
  Serial1.write(0x00);
  Serial1.write(0x03);
  delay(1000);
  if ( Serial1.available() < 14 ) return false;

  while (Serial1.available() )
  {
    Serial.println(Serial1.read(), HEX);
  }
  Serial.println("######################");
  return true;
}

void usb_hid_init()
{
  pixels.begin();
  pixels.clear();
  Serial.begin(115200, SERIAL_8N1, 8, 1);
  Serial1.begin(9600, SERIAL_8N1, 7, 10);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  ota_init(); // WIFI 업로드 초기화

  ch9329_set_mode(1);
  delay(100);
  ch9329_set_manufact((char*)keyboard_manufact);
  delay(100);
  ch9329_set_product((char*)keyboard_product);
  delay(100);

  Mouse.begin();
  USB.productName(mouse_product);
  USB.manufacturerName(mouse_manufact);
  USB.VID(mouse_vid);
  USB.PID(mouse_pid);
  USB.begin();

  pinMode(GREEN_BTN, INPUT_PULLUP);
  pinMode(RED_BTN, INPUT_PULLUP);
  /*
    keyboard_flag = true;
    mouse_flag = true;
    macro_flag = false;
  */
  // 빨강버튼을 누르고 리셋을 하면 CH9329초기화함
  if ( digitalRead(RED_BTN) == LOW )
  {
    ch9329_initalize();
    // ch9329 설정
    ch9329_set_mode(1);
    delay(1000);
    ch9329_set_manufact((char*)keyboard_manufact);
    delay(1000);
    ch9329_set_product((char*)keyboard_product);
    delay(1000);
    for ( int i = 0; i < 10; i++)
    {
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      pixels.show();
      digitalWrite(BLUE_LED, HIGH);
      delay(100);
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.show();
      digitalWrite(BLUE_LED, LOW);
      delay(100);
    }
  }

  if ( check_ch9329() == false )
  {
    for ( int i = 0; i < 10; i++)
    {
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.show();
      digitalWrite(GREEN_LED, HIGH);
      delay(100);
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.show();
      digitalWrite(GREEN_LED, LOW);
      delay(100);
    }
  }

  attachInterrupt(GREEN_BTN, green_toggle, FALLING);
  attachInterrupt(RED_BTN, red_toggle, FALLING);

  blinker.attach(0.001, onTimer);
}

void send_keyboard(uint8_t *buf)
{
  uint8_t buffer[14];
  buffer[0] = 0x57;
  buffer[1] = 0xAB;
  buffer[2] = 0x00;
  buffer[3] = 0x02;
  buffer[4] = 0x08;

  memcpy(buffer + 5, buf, 8);

  if ( echo_flag == true )
  {
    Serial.print("SEND ");
    Serial.print(buf[0]);
    Serial.print(",");
    Serial.print(buf[1]);
    Serial.print(",");
    Serial.print(buf[2]);
    Serial.print(",");
    Serial.print(buf[3]);
    Serial.print(",");
    Serial.print(buf[4]);
    Serial.print(",");
    Serial.print(buf[5]);
    Serial.print(",");
    Serial.print(buf[6]);
    Serial.print(",");
    Serial.print(buf[7]);
    Serial.println("");
  }

  uint16_t sum = 0;
  for ( int i = 0; i < 13; i++)
  {
    sum = sum + buffer[i];
  }
  buffer[13] = sum;

  // 디버그인경우 키보드 타이핑시 빨파 LED를 깜빡임
#ifdef _DEBUG
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
#endif

  Serial1.write(buffer, 14);
}

void usb_hid_process()
{
  if ( Serial.available() >= 6 )
  {
    int val = Serial.read();
    if ( val == 20 )
    {
      int cmd = Serial.read();

      if ( cmd == 2 ) // 마우스 신호의 경우
      {
        int8_t buf[4];
        Serial.read((char*)buf, 4);
        //        Serial.println("MOUSE");
        if ( echo_flag == true )
        {
          Serial.print("MOUSE DATA = ");
          Serial.print((int)buf[0]);
          Serial.print(",");
          Serial.print((int)buf[1]);
          Serial.print(",");
          Serial.print((int)buf[2]);
          Serial.print(",");
          Serial.print((int)buf[3]);
          Serial.println("");
        }
        if ( mouse_flag == true )
        {
          Mouse.send_report(buf[0], buf[1], buf[2], buf[3], 0);
        }
      }

      if ( cmd == 6 ) // 키보드 신호의 경우
      {
        unsigned long start_millis = millis();
        if ( Serial.available() < 8 )
        {
          if ( millis() > start_millis + 100 ) return;
        }

        uint8_t buf[8];
        Serial.read((char*)buf, 8);
        if ( echo_flag == true )
        {
          Serial.print("KEYBOARD DATA = ");
          Serial.print((int)buf[0], HEX);
          Serial.print(",");
          Serial.print((int)buf[1], HEX);
          Serial.print(",");
          Serial.print((int)buf[2], HEX);
          Serial.print(",");
          Serial.print((int)buf[3], HEX);
          Serial.print(",");
          Serial.print((int)buf[4], HEX);
          Serial.print(",");
          Serial.print((int)buf[5], HEX);
          Serial.print(",");
          Serial.print((int)buf[6], HEX);
          Serial.print(",");
          Serial.print((int)buf[7], HEX);
          Serial.println("");
        }
        int function_key = false;

        ////////////////////////////////////////////////////////////////////////
        // 모듈 리셋 키 체크 ( ESC + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////
        int i = MY_ID;
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != reset_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            ESP.restart();
          }
        }

        // 내가 아닌 다른 모듈의 reset 키인경우
        for ( int i = 0; i < MODULE_NO; i++)
        {
          if ( i == MY_ID ) continue;
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != reset_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            function_key = true;
          }
        }        

        ////////////////////////////////////////////////////////////////////////
        // 키보드 활성화 키 체크 ( CTRL + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////
        //        for ( int i = 0; i < ACTIVE_KEY_NO; i++)
        i = MY_ID;
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != active_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 활성화
            function_key = true;
            Serial.println("ACTIVATE");
            green_btn = true;
            red_btn = false;
            keyboard_flag = true;
            mouse_flag = true;

            // 정지
            macro_status = 0; // 일시 정지
            // releaseall은 check_stop함수에서 실행
            // macro_flag은 check_stop함수에서 변경
          }
        }

        for ( int i = 0; i < MODULE_NO; i++)
        {
          if ( i == MY_ID ) continue;
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != active_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 비활성화 , 만약 매크로 구동 중이었으면 기존 모드 그대로 둠
            if ( macro_flag == false )
              // 매크로가 구동중이 아니었던 경우
            {
              function_key = true;
              Serial.println("DEACTIVATE");
              green_btn = false;
              red_btn = false;
              macro_flag = false;
              keyboard_flag = false;
              mouse_flag = false;

              force_releaseall(); // 9.18

              break;
            }
            else
              // 매크로가 구동중이었던 경우
            {
              function_key = true;
              break;
            }
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 키보드 활성화 키 체크 ( CTRL + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // 키보드 활성화 키 체크 2 ( CTRL + SHIFT + 1 ~ 8 )
        ////////////////////////////////////////////////////////////////////////
        //        for ( int i = 0; i < ACTIVE_KEY_NO; i++)
        i = MY_ID;
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != active_key2[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 활성화
            function_key = true;
            Serial.println("ACTIVATE");
            green_btn = true;
            red_btn = false;
            keyboard_flag = true;
            mouse_flag = true;

            // 매크로 반영도 하지 않고, 진행도 하지 않음
            macro_status = 0; // 일시 정지
            macro_flag = false;
            force_releaseall();
          }
        }

        for ( int i = 0; i < MODULE_NO; i++)
        {
          if ( i == MY_ID ) continue;
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != active_key2[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 비활성화 , 만약 매크로 구동 중이었으면 기존 모드 그대로 둠
            if ( macro_flag == false )
              // 매크로가 구동중이 아니었던 경우
            {
              function_key = true;
              Serial.println("DEACTIVATE");
              green_btn = false;
              red_btn = false;
              macro_flag = false;
              keyboard_flag = false;
              mouse_flag = false;

              force_releaseall(); // 9.18

              break;
            }
            else
              // 매크로가 구동중이었던 경우
            {
              function_key = true;
              break;
            }
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 키보드 활성화 키 체크 2 ( CTRL + SHIFT + 1 ~ 8 )
        ////////////////////////////////////////////////////////////////////////


        ////////////////////////////////////////////////////////////////////////
        // 모든 키보드 마우스 끄기 단축키 체크 ( CTRL + ESC )
        ////////////////////////////////////////////////////////////////////////
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != all_off_key[j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 키보드 마우스 끄기
            if ( macro_flag == false )
              // 매크로가 구동중이 아니었던 경우
            {
              function_key = true;
              Serial.println("ALL MOUSE KEYBOARD OFF");
              green_btn = false;
              red_btn = false;
              macro_flag = false;
              keyboard_flag = false;
              mouse_flag = false;

              force_releaseall(); // 9.18
            }
            else
              // 매크로가 구동중이었던 경우
            {
              function_key = true;
            }
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 모든 키보드 마우스 끄기 단축키 체크 ( CTRL + ESC )
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // 모든 매크로 끄기 단축키 체크 ( CTRL + F12 )
        ////////////////////////////////////////////////////////////////////////
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != all_macro_off_key[j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 키보드 마우스 끄기
            if ( macro_flag == false )
              // 매크로가 구동중이 아니었던 경우
            {
              function_key = true;

              force_releaseall(); // 9.18
            }
            else
              // 매크로가 구동중이었던 경우
            {
              function_key = true;
              Serial.println("ALL MACRO OFF");
              green_btn = false;
              red_btn = false;
              keyboard_flag = false;
              mouse_flag = false;

              // 매크로 반영도 하지 않고, 진행도 하지 않음
              macro_status = 0; // 일시 정지
              // releaseall은 check_stop함수에서 실행
              // macro_flag은 check_stop함수에서 변경
            }
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 모든 매크로 끄기 단축키 체크 ( CTRL + F12 )
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // 매크로 처음부터 시작 키 체크 ( CTRL + 1 ~ 8 )
        ////////////////////////////////////////////////////////////////////////
        i = MY_ID;
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != macro_restart_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 매크로 재시작
            function_key = true;
            Serial.println("RESTART");
            green_btn = false;
            red_btn = true;
            keyboard_flag = false;
            mouse_flag = false;

            // 매크로 반영하고 , 매크로 재시작
            macro_flag = true;
            macro_status = 2; // 재시작

            force_releaseall(); // 9.18
          }
        }

        // 내가 아닌 다른 모듈의 재시작 키인경우
        for ( int i = 0; i < MODULE_NO; i++)
        {
          if ( i == MY_ID ) continue;
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != macro_restart_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            function_key = true;
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 매크로 처음부터 시작 키 체크 ( CTRL + 1 ~ 8 )
        ////////////////////////////////////////////////////////////////////////


        ////////////////////////////////////////////////////////////////////////
        // 매크로 이어서 재생 키 체크 ( SHIFT + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////
        i = MY_ID;
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != macro_resume_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 매크로 이어서 진행
            function_key = true;
            Serial.println("RESUME");
            green_btn = false;
            red_btn = true;
            keyboard_flag = false;
            mouse_flag = false;

            // 매크로 이어서 진행
            macro_flag = true;
            macro_status = 1; // 구동중

            force_releaseall(); // 9.18
          }
        }

        // 내가 아닌 다른 모듈의 이어서 진행 키인경우
        for ( int i = 0; i < MODULE_NO; i++)
        {
          if ( i == MY_ID ) continue;
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != macro_resume_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            function_key = true;
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 매크로 이어서 재생 키 체크 ( SHIFT + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // 주기적 실행키 리셋 ( CTRL + SHIFT + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////
        i = MY_ID;
        {
          int j = 0;
          for (j = 0; j < 8; j++)
          {
            if ( buf[j] != periodic_reset_key[i][j] )
            {
              break;
            }
          }
          if ( j == 8 )
          {
            // 매크로 이어서 진행
            function_key = true;
            Serial.println("PERIODIC KEY RESET");

            Serial.print("PERIODIC 1 - ");
            Serial.println();
            delay_1 = random(periodic_min1, periodic_max1);
            periodic_millis1 = millis();

            Serial.print("PERIODIC 2 - ");
            Serial.println();
            delay_2 = random(periodic_min2, periodic_max2);
            periodic_millis2 = millis();

            Serial.print("PERIODIC 3 - ");
            Serial.println();
            delay_3 = random(periodic_min3, periodic_max3);
            periodic_millis3 = millis();

            Serial.print("PERIODIC 4 - ");
            Serial.println();
            delay_4 = random(periodic_min4, periodic_max4);
            periodic_millis4 = millis();

            Serial.print("PERIODIC 5 - ");
            Serial.println();
            delay_5 = random(periodic_min5, periodic_max5);
            periodic_millis5 = millis();

            Serial.print("PERIODIC 6 - ");
            Serial.println();
            delay_6 = random(periodic_min6, periodic_max6);
            periodic_millis6 = millis();

            Serial.print("PERIODIC 7 - ");
            Serial.println();
            delay_7 = random(periodic_min7, periodic_max7);
            periodic_millis7 = millis();

            Serial.print("PERIODIC 8 - ");
            Serial.println();
            delay_8 = random(periodic_min8, periodic_max8);
            periodic_millis8 = millis();

            Serial.print("PERIODIC 9 - ");
            Serial.println();
            delay_9 = random(periodic_min9, periodic_max9);
            periodic_millis9 = millis();

            Serial.print("PERIODIC 10 - ");
            Serial.println();
            delay_10 = random(periodic_min10, periodic_max10);
            periodic_millis10 = millis();
          }
        }
        ////////////////////////////////////////////////////////////////////////
        // 주기적 실행키 리셋 ( CTRL + SHIFT + F1 ~ F8 )
        ////////////////////////////////////////////////////////////////////////

        if ( function_key == true ) return;
        if ( keyboard_flag == true )
        {
          send_keyboard(buf);
        }
      }
    }
  }
}

// 모드에 상관없이 강제로 keyboard releaseAll
void force_releaseall()
{
  uint8_t buf[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  send_keyboard(buf);
}
