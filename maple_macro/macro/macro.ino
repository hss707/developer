#define _DEBUG

#include "Keyboard.h" // Keyboard library

const int button = 7;

int flag = 1;

unsigned long order_count;   // 오더 쿨타임 계산 변수
long order_RandSec;           // 버프 02 쿨타임 랜덤 배정

unsigned long sinmi_count;  // 스인미 쿨타임 계산 변수
long sinmi_RandSec;         // 스인미 쿨타임 랜덤 배정 변수

unsigned long mileage_count;  // 마일리지 쿨타임 계산 변수
long mileage_RandSec;         // 마일리지 쿨타임 랜덤 배정 변수

//const char worldSkill_command = 'q';            // 인피니티 키
//const char buff_01_command = '2';               // 첫번째 버프 단축키
//const char buff_02_command = '3';               // 두번째 버프 단축키
const char divide_command_01 = KEY_LEFT_CTRL;   // 디바이드 01 키
const char divide_command_02 = 'a';             // 디바이드 02 키
const char divide_command_03 = 'z';             // 디바이드 03 키
const char imperial_command = 'd';              // 임페일 커맨드키
const char rezonence_command = 'f';             // 레조넌스 커맨드 키
const char order_command = 's';                 // 오더 커맨드 키
const char jump = KEY_LEFT_ALT;                 // 점프키
const char sinmi_command = KEY_F7;              // 스인미
const char mileage_command = 'q';                 // 마일리지

const long order_CoolTime_Min = 10000;
const long order_CoolTime_Max = 15000;

const long sinmi_CoolTime_Min = 260000;
const long sinmi_CoolTime_Max = 300000;

const long mileage_CoolTime_Min = 3600000;
const long mileage_CoolTime_Max = 3700000;

void frontJumpDash();
void backendJumpDash();
void upSideSkill();
void attack();
void isr();

volatile unsigned long button_millis;

void setup()
{
  Keyboard.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  button_millis = millis();

  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), isr, FALLING);

  order_count = millis();
  order_RandSec = random(order_CoolTime_Min, order_CoolTime_Max);

  sinmi_count = millis();
  sinmi_RandSec = random(sinmi_CoolTime_Min, sinmi_CoolTime_Max);

  mileage_count = millis();
  mileage_RandSec = random(mileage_CoolTime_Min, mileage_CoolTime_Max);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

// 오른쪽방향으로 점프 대쉬
void frontJumpDash()
{
  Keyboard.press(KEY_RIGHT_ARROW);
  int randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(80, 110);
  delay(randNumber);

  Keyboard.press('x');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('x');
  randNumber = random(40, 60);

  Keyboard.release(KEY_RIGHT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
  attack();
}

// 왼쪽방향으로 점프 대쉬
void backendJumpDash()
{
  Keyboard.press(KEY_LEFT_ARROW);
  int randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(105, 115);
  delay(randNumber);

  Keyboard.press('x');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('x');
  randNumber = random(40, 60);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);

  attack();
}

void upSideSkill()
{
  Keyboard.press(KEY_LEFT_ARROW);
  int randNumber = random(10, 25);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(105, 115);
  delay(randNumber);

  Keyboard.press(KEY_UP_ARROW);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.press(imperial_command);
  randNumber = random(180, 230);
  delay(randNumber);

  Keyboard.release(imperial_command);
  randNumber = random(150, 180);
  delay(randNumber);

  Keyboard.press(rezonence_command);
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(rezonence_command);
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.press(rezonence_command);
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(rezonence_command);
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(KEY_UP_ARROW);
  randNumber = random(13, 30);
  delay(randNumber);

}

void downSideSkill()
{
  Keyboard.press(KEY_LEFT_ARROW);
  int randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(25, 30);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(25, 35);
  delay(randNumber);

  Keyboard.press('x');
  randNumber = random(150, 200);
  delay(randNumber);
  Keyboard.release('x');
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(100, 150);
  delay(randNumber);

  Keyboard.press('c');
  randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(13, 30);
  delay(randNumber);
}

void attack()
{
  int randNum = random(0, 3);
  int randNumber = 0;

  switch (randNum)
  {
    case 0:
      Keyboard.press(divide_command_01);
      randNumber = random(13, 30);
      delay(randNumber);

      Keyboard.release(divide_command_01);
      break;
    case 1:
      Keyboard.press(divide_command_02);
      randNumber = random(13, 30);
      delay(randNumber);

      Keyboard.release(divide_command_02);
      break;
    case 2:
      Keyboard.press(divide_command_03);
      randNumber = random(13, 30);
      delay(randNumber);

      Keyboard.release(divide_command_03);
      break;
  }

  if (millis() - order_count > order_RandSec)
  {
#ifdef _DEBUG
    Serial.print(millis());
    Serial.print("-");
    Serial.print("order(");
    Serial.print(millis() - order_count);
    Serial.println(")");
#endif

    randNumber = random(13, 30);
    delay(randNumber);

    Keyboard.press(order_command);
    randNumber = random(13, 30);
    delay(randNumber);

    Keyboard.release(order_command);

    order_count = millis();
    order_RandSec = random(order_CoolTime_Min, order_CoolTime_Max);
  }

  randNumber = random(200, 250);
  delay(randNumber);
}

void isr()
{
  Keyboard.releaseAll();
  if ( ( millis() - button_millis ) < 500 ) return; // debouncing
  if (flag)
  {
    flag = 0;
  }
  else
  {
    flag = 1;
  }
  Serial.println("BUTTON");
  digitalWrite(13, flag);
  button_millis = millis();
}

void loop()
{
Serial_read:
  if (flag) // 버튼 누르지 않은 경우만 실행
  {
    // 반복 루틴
    // 왼쪽으로 점디 5번
    for (int i = 0; i < 5; i++)
    {
      if ( i == 2 )
      {
        // 2칸에서 스인미 실행 체크
        if ( ( millis() - sinmi_count ) > sinmi_RandSec )
        {
#ifdef _DEBUG
          Serial.print(millis());
          Serial.print("-");
          Serial.print("sinmi(");
          Serial.print(millis() - sinmi_count);
          Serial.println(")");
#endif
          sinmi();
          if (Serial.available() > 0 || !flag) goto Serial_read;
          sinmi_RandSec = random(sinmi_CoolTime_Min, sinmi_CoolTime_Max);
          if (Serial.available() > 0 || !flag) goto Serial_read;
          sinmi_count = millis();
          if ( ( millis() - mileage_count ) > mileage_RandSec )
          {
#ifdef _DEBUG
            Serial.print(millis());
            Serial.print("-");
            Serial.print("mileage(");
            Serial.print(millis() - mileage_count);
            Serial.println(")");
#endif
            mileage();
            if (Serial.available() > 0 || !flag) goto Serial_read;
            mileage_RandSec = random(mileage_CoolTime_Min, mileage_CoolTime_Max);
            if (Serial.available() > 0 || !flag) goto Serial_read;
            mileage_count = millis();
          }
        }
      }
      if (Serial.available() > 0 || !flag) goto Serial_read;
      left_jump_divide();
      if (Serial.available() > 0 || !flag) goto Serial_read;
      int randNumber = random(360, 410);
      delay(randNumber);
      if (Serial.available() > 0 || !flag) goto Serial_read;
    }

    // 임페레조
    impe_rezo();
    if (Serial.available() > 0 || !flag) goto Serial_read;
    int randNumber01 = random(640, 700);
    delay(randNumber01);

    // 오른쪽으로 점디 4번
    for (int i = 0; i < 4; i++)
    {
      if (Serial.available() > 0 || !flag) goto Serial_read;
      right_jump_divide();
      if (Serial.available() > 0 || !flag) goto Serial_read;
      int randNumber = random(360, 410);
      delay(randNumber);
      if (Serial.available() > 0 || !flag) goto Serial_read;
    }
    if (Serial.available() > 0 || !flag) goto Serial_read;
    //Serial.println("back");

    int randNumber = random(100, 150);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;
    trade();
    if (Serial.available() > 0 || !flag) goto Serial_read;
    randNumber = random(640, 700);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;
  }
}


void left_jump_divide()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("left_jump_divide");
#endif

  // 왼쪽키 누름
  Keyboard.press(KEY_LEFT_ARROW);       // PRESS LEFT
  int randNumber = random(20, 40);
  delay(randNumber);

  // 점프
  Keyboard.press(jump);                 // PRESS jump
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);               // RELEASE jump
  randNumber = random(105, 115);
  delay(randNumber);

  // 더블점프(볼트)
  Keyboard.press('x');                  // PRESS x
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('x');                // RELEASE x
  randNumber = random(40, 60);

  Keyboard.release(KEY_LEFT_ARROW);     // RELEASE LEFT
  randNumber = random(20, 30);
  delay(randNumber);

  attack();

}

void right_jump_divide()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("right_jump_divide");
#endif

  // 우측키 누름
  Keyboard.press(KEY_RIGHT_ARROW);       // PRESS RIGHT
  int randNumber = random(20, 40);
  delay(randNumber);

  // 점프
  Keyboard.press(jump);                 // PRESS jump
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);               // RELEASE jump
  randNumber = random(105, 115);
  delay(randNumber);

  // 더블점프(볼트)
  Keyboard.press('x');                  // PRESS x
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('x');                // RELEASE x
  randNumber = random(40, 60);

  Keyboard.release(KEY_RIGHT_ARROW);     // RELEASE RIGHT
  randNumber = random(20, 30);
  delay(randNumber);

  attack();
}

// 임페레조
void impe_rezo()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("impe_rezo");
#endif

  Keyboard.press(jump);               // PRESS jump
  int randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(jump);             // RELEASE jump
  randNumber = random(205, 235);
  delay(randNumber);

  Keyboard.press(KEY_RIGHT_ARROW);    // PRESS RIGHT
  randNumber = random(10, 25);
  delay(randNumber);

  Keyboard.press(KEY_UP_ARROW);       // PRESS UP
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.press(imperial_command);   // PRESS imperial
  randNumber = random(180, 230);
  delay(randNumber);

  Keyboard.release(imperial_command); // RELEASE imperial
  randNumber = random(150, 180);
  delay(randNumber);

  Keyboard.press(rezonence_command);  // PRESS rezonence
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(rezonence_command);  // RELEASE rezonence
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(KEY_RIGHT_ARROW);  // RELEASE RIGHT
  randNumber = random(13, 30);
  delay(randNumber);

  Keyboard.release(KEY_UP_ARROW);     // RELEASE UP
  randNumber = random(13, 30);
  delay(randNumber);
}

void trade()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("trade");
#endif

  Keyboard.press('c');              // PRESS trade
  int randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release('c');            // RELEASE trade
  randNumber = random(13, 30);
  delay(randNumber);
}

void sinmi()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("sinmi");
#endif

  Keyboard.press(sinmi_command);              // PRESS sinmi
  int randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release(sinmi_command);            // RELEASE sinmi
  randNumber = random(13, 30);
  delay(randNumber);
}

void mileage()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("mileage");
#endif

  Keyboard.press(mileage_command);              // PRESS mileage
  int randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release(mileage_command);            // RELEASE mileage
  randNumber = random(13, 30);
  delay(randNumber);
}
