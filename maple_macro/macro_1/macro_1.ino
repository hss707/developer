//#define _DEBUG

#include "Keyboard.h" // Keyboard library

const int button = 7;

int flag = 0;

// 스인미 설정
const char sinmi_command = KEY_F7;              // 스인미
unsigned long sinmi_count;  // 스인미 쿨타임 계산 변수
long sinmi_RandSec;         // 스인미 쿨타임 랜덤 배정 변수
const long sinmi_CoolTime_Min = 260000;
const long sinmi_CoolTime_Max = 300000;

// 블레이드 토네이도 설정
const char blade_command = KEY_DELETE;              // 블레이드
unsigned long blade_count;  // 블레이드 쿨타임 계산 변수
long blade_RandSec;         // 블레이드 쿨타임 랜덤 배정 변수
const long blade_CoolTime_Min = 30000;
const long blade_CoolTime_Max = 50000;

// 카르마 퓨리 설정
const char karma_command = KEY_END;              // 카르마 퓨리
unsigned long karma_count;  // 카르마 쿨타임 계산 변수
long karma_RandSec;         // 카르마 쿨타임 랜덤 배정 변수
const long karma_CoolTime_Min = 30000;
const long karma_CoolTime_Max = 50000;

/*
  unsigned long order_count;   // 오더 쿨타임 계산 변수
  long order_RandSec;           // 버프 02 쿨타임 랜덤 배정

  unsigned long mileage_count;  // 마일리지 쿨타임 계산 변수
  long mileage_RandSec;         // 마일리지 쿨타임 랜덤 배정 변수
*/
const char divide_command_01 = KEY_LEFT_CTRL;   // 디바이드 01 키
const char divide_command_02 = 's';             // 디바이드 02 키
const char divide_command_03 = 'z';             // 디바이드 03 키
const char jump = KEY_LEFT_ALT;                 // 점프키
/*
  const char imperial_command = 'd';              // 임페일 커맨드키
  const char rezonence_command = 'f';             // 레조넌스 커맨드 키
  const char order_command = 's';                 // 오더 커맨드 키
  const char mileage_command = 'q';                 // 마일리지

  const long order_CoolTime_Min = 10000;
  const long order_CoolTime_Max = 15000;

  const long mileage_CoolTime_Min = 3600000;
  const long mileage_CoolTime_Max = 3700000;

  void frontJumpDash();
  void backendJumpDash();
  void upSideSkill();
  void attack();
  void isr();
*/
volatile unsigned long button_millis;

void setup()
{
  Keyboard.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  button_millis = millis();

  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), isr, FALLING);

  sinmi_count = millis();
  sinmi_RandSec = random(sinmi_CoolTime_Min, sinmi_CoolTime_Max);

  blade_count = millis();
  blade_RandSec = random(blade_CoolTime_Min, blade_CoolTime_Max);

  karma_count = millis();
  karma_RandSec = random(karma_CoolTime_Min, karma_CoolTime_Max);

  /*
    order_count = millis();
    order_RandSec = random(order_CoolTime_Min, order_CoolTime_Max);


    mileage_count = millis();
    mileage_RandSec = random(mileage_CoolTime_Min, mileage_CoolTime_Max);
  */
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

// 오른쪽방향으로 점프 attack
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

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);

  Keyboard.release(KEY_RIGHT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
  attack();
}

// 오른쪽방향으로 점프 attack
void frontJumpDash2()
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

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);

  Keyboard.press(KEY_LEFT_SHIFT);
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release(KEY_LEFT_SHIFT);
  randNumber = random(40, 60);

  Keyboard.release(KEY_RIGHT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
}

// 왼쪽방향으로 점프 attack
void frontJumpDash2_1()
{
  Keyboard.press(KEY_LEFT_ARROW);
  int randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(80, 110);
  delay(randNumber);

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);

  Keyboard.press(KEY_LEFT_SHIFT);
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release(KEY_LEFT_SHIFT);
  randNumber = random(40, 60);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
}

// 왼쪽방향으로 점프 attack
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

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);
  delay(randNumber);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
}

// 왼쪽방향으로 점프 attack
void backendJumpDash2()
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

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);
  delay(randNumber);

  Keyboard.press(KEY_DELETE);
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release(KEY_DELETE);
  randNumber = random(40, 60);
  delay(randNumber);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
}

// 왼쪽방향으로 점프 attack
void backendJumpDash2_1()
{
/*  
  Keyboard.press(KEY_LEFT_ARROW);
  int randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(105, 115);
  delay(randNumber);

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);
  delay(randNumber);
*/
  Keyboard.press(KEY_END);
  int randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release(KEY_END);
  randNumber = random(200, 400);
  delay(randNumber);
/*
  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
*/  
}

// 왼쪽방향으로 점프 attack
void backendJumpDash3()
{
  Keyboard.press(KEY_LEFT_ARROW);
  int randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(80, 110);
  delay(randNumber);

  Keyboard.press('c');
  randNumber = random(50, 140);
  delay(randNumber);
  Keyboard.release('c');
  randNumber = random(40, 60);
  delay(randNumber);

  Keyboard.release(KEY_LEFT_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
  attack();
}

// 아래방향으로 점프 attack
void downendJumpDash()
{
  int randNumber = random(200, 300);
  delay(randNumber);

  Keyboard.press(KEY_DOWN_ARROW);
  randNumber = random(20, 40);
  delay(randNumber);

  Keyboard.press(jump);
  randNumber = random(20, 35);
  delay(randNumber);

  Keyboard.release(jump);
  randNumber = random(80, 110);
  delay(randNumber);
  /*
    Keyboard.press('s');
    randNumber = random(50, 140);
    delay(randNumber);
    Keyboard.release('s');
    randNumber = random(40, 60);
    delay(randNumber);
  */
  Keyboard.release(KEY_DOWN_ARROW);
  randNumber = random(20, 30);
  delay(randNumber);
  /*
    random_function();
    randNumber = random(760, 810);

    Keyboard.press(KEY_RIGHT_ARROW);
    randNumber = random(20, 40);
    delay(randNumber);

    Keyboard.press('c');
    randNumber = random(50, 140);
    delay(randNumber);
    Keyboard.release('c');
    randNumber = random(40, 60);
    delay(randNumber);

    Keyboard.press('s');
    randNumber = random(50, 140);
    delay(randNumber);
    Keyboard.release('s');
    randNumber = random(40, 60);
    delay(randNumber);

    Keyboard.release(KEY_RIGHT_ARROW);
    randNumber = random(20, 30);
    delay(randNumber);
  */
  randNumber = random(200, 300);
  delay(randNumber);
}
/*
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
*/
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
  /*
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
  */
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
/*
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
*/
/*
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
*/
/*
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
*/
/*
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
*/

/*
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
*/
/*
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
*/

// 스인미 함수
void sinmi()
{
  Serial.print(millis());
  Serial.print("-");
  Serial.println("sinmi");

  Keyboard.press(sinmi_command);              // PRESS sinmi
  int randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release(sinmi_command);            // RELEASE sinmi
  randNumber = random(13, 30);
  delay(randNumber);
}

void random_sinmi()
{
  if ( ( millis() - sinmi_count ) > sinmi_RandSec )
  {
    sinmi_count = millis();
    sinmi_RandSec = random(sinmi_CoolTime_Min, sinmi_CoolTime_Max);
    sinmi();
  }
}

// 블레이드 함수
void blade()
{
  Serial.print(millis());
  Serial.print("-");
  Serial.println("blade");

  Keyboard.press(blade_command);              // PRESS blade
  int randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release(blade_command);            // RELEASE blade
  randNumber = random(13, 30);
  delay(randNumber);
}

void random_blade()
{
  if ( ( millis() - blade_count ) > blade_RandSec )
  {
    blade_count = millis();
    blade_RandSec = random(blade_CoolTime_Min, blade_CoolTime_Max);
    blade();
  }
}

// 카르마 퓨리 함수
void karma()
{
  Serial.print(millis());
  Serial.print("-");
  Serial.println("karma");

  Keyboard.press(karma_command);              // PRESS KARMA
  int randNumber = random(100, 150);
  delay(randNumber);
  Keyboard.release(karma_command);            // RELEASE KARMA
  randNumber = random(13, 30);
  delay(randNumber);
}

void random_karma()
{
  if ( ( millis() - karma_count ) > karma_RandSec )
  {
    karma_count = millis();
    karma_RandSec = random(karma_CoolTime_Min, karma_CoolTime_Max);
    karma();
  }
}

void random_function()
{
//  random_karma();
  random_sinmi();
//  random_blade();
}


int randNumber;

void loop()
{
Serial_read:
  if (flag) // 버튼 누르지 않은 경우만 실행
  {
    ///////////////////////////////////////
    ////////////// 1 CYCLE ////////////////
    ///////////////////////////////////////
    // 1. →(오른쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> s(눌렀다가 때기) -> →(오른쪽키 때기) * 5
    for (int i = 0; i < 5; i++)
    {
      frontJumpDash();
      random_function();
      randNumber = random(360, 410);
      delay(randNumber);
      if (Serial.available() > 0 || !flag) goto Serial_read;
    }

    // 2.→(오른쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> shift(눌렀다가 떄기)  -> →(오른쪽키 때기) front2
    frontJumpDash2();
    random_function();
    randNumber = random(640, 700);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;

    // 3.→(오른쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> shift(눌렀다가 떄기)  -> →(오른쪽키 때기) front2
    frontJumpDash2_1();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;


    // 4.←(왼쪽쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) ->  ←(왼쪽키 때기) back
    backendJumpDash();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;
    // 5.←(왼쪽쪽키누르기) -> alt(눌렀다가 때기) -> c(눌렀다가 때기)-> delete(눌렀다가 때기) back2
    backendJumpDash2();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;

    // 6. ←(왼쪽쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> s(눌렀다가 때기) -> ←(왼쪽키 때기) *2
    for (int i = 0; i < 4; i++)
    {
      backendJumpDash3();
      random_function();
      randNumber = random(360, 410);
      delay(randNumber);
      if (Serial.available() > 0 || !flag) goto Serial_read;
    }
    // 7.↓(아래쪽키누르기) -> alt(눌렀다가 떄기) -> s(눌렀다가 때기) -> ↓(아래쪽키때기) -> →(오른쪽키누르기) ->  c(눌렀다가 때기)  -> s(눌렀다가 때기) -> →(오른쪽키때기)
    downendJumpDash();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;

    ///////////////////////////////////////
    ////////////// 2 CYCLE ////////////////
    ///////////////////////////////////////

    // 1. →(오른쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> s(눌렀다가 때기) -> →(오른쪽키 때기) * 5
    for (int i = 0; i < 5; i++)
    {
      frontJumpDash();
      random_function();
      randNumber = random(360, 410);
      delay(randNumber);
      if (Serial.available() > 0 || !flag) goto Serial_read;
    }

    // 2.→(오른쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> shift(눌렀다가 떄기)  -> →(오른쪽키 때기) front2
    frontJumpDash2();
    random_function();
    randNumber = random(640, 700);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;

    // 3.→(오른쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> shift(눌렀다가 떄기)  -> →(오른쪽키 때기) front2
    frontJumpDash2_1();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;


    // 4.←(왼쪽쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) ->  ←(왼쪽키 때기) back
    backendJumpDash();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;
    // 5.←(왼쪽쪽키누르기) -> alt(눌렀다가 때기) -> c(눌렀다가 때기)-> delete(눌렀다가 때기) back2
    backendJumpDash2_1();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;

    // 6. ←(왼쪽쪽키누르기) -> alt(눌렀다가 때기) ->  c(눌렀다가 때기) -> s(눌렀다가 때기) -> ←(왼쪽키 때기) *2
    for (int i = 0; i < 5; i++)
    {
      backendJumpDash3();
      random_function();
      randNumber = random(360, 410);
      delay(randNumber);
      if (Serial.available() > 0 || !flag) goto Serial_read;
    }
    // 7.↓(아래쪽키누르기) -> alt(눌렀다가 떄기) -> s(눌렀다가 때기) -> ↓(아래쪽키때기) -> →(오른쪽키누르기) ->  c(눌렀다가 때기)  -> s(눌렀다가 때기) -> →(오른쪽키때기)
    downendJumpDash();
    random_function();
    randNumber = random(360, 410);
    delay(randNumber);
    if (Serial.available() > 0 || !flag) goto Serial_read;
  }
}
