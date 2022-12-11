#define SPEED_FACTOR 5

#define _DEBUG

#include "Keyboard.h" // Keyboard library

const int button = 7;
int flag = 1; // 0 : 매크로 정지 상태 , 1 : 매크로 구동 상태

// 스킬 정의
// 기본 공격(크루얼스텝)
const char attack_command_1 = 'a'; // 기본공격
const char attack_command_2 = 'z'; // 기본공격
const char attack_command_3 = KEY_LEFT_CTRL; // 기본공격

const char jump_command = 'x'; // 위로점프

const char periodic_key1 = KEY_INSERT;
const char periodic_key1_1 = KEY_HOME;
unsigned long periodic_millis1;
unsigned long periodic_min1 = 20000;
unsigned long periodic_max1 = 60000;
unsigned long delay_1 = ( periodic_min1 + periodic_max1) / 2;

const char periodic_key2 = KEY_PAGE_DOWN;
unsigned long periodic_millis2;
unsigned long periodic_min2 = 31000;
unsigned long periodic_max2 = 35000;
unsigned long delay_2 = ( periodic_min2 + periodic_max2) / 2;

const char periodic_key3 = 'e';
unsigned long periodic_millis3;
unsigned long periodic_min3 = 31000;
unsigned long periodic_max3 = 35000;
unsigned long delay_3 = ( periodic_min3 + periodic_max3) / 2;

const char periodic_key4 = 'w';
unsigned long periodic_millis4;
unsigned long periodic_min4 = 46000;
unsigned long periodic_max4 = 50000;
unsigned long delay_4 = ( periodic_min4 + periodic_max4) / 2;

const char periodic_key5 = KEY_DELETE;
unsigned long periodic_millis5;
unsigned long periodic_min5 = 45000;
unsigned long periodic_max5 = 50000;
unsigned long delay_5 = ( periodic_min5 + periodic_max5) / 2;

const char periodic_key6 = 'h';
unsigned long periodic_millis6;
unsigned long periodic_min6 = 260000;
unsigned long periodic_max6 = 280000;
unsigned long delay_6 = ( periodic_min6 + periodic_max6) / 2;

void process_periodic_key()
{
  if ( ( millis() - periodic_millis1 ) > delay_1 )
  {
    Serial.print("PERIODIC 1 - ");
    Serial.println(( millis() - periodic_millis1 ));

    int rand_val = random(0, 2);
    if ( rand_val == 0 )
    {
      Keyboard.press(periodic_key1);
      random_delay(100, 150);
      Keyboard.release(periodic_key1);
      random_delay(13, 30);
    }
    else
    {
      Keyboard.press(periodic_key2);
      random_delay(100, 150);
      Keyboard.release(periodic_key2);
      random_delay(13, 30);
    }

    delay_1 = random(periodic_min1, periodic_max1);
    periodic_millis1 = millis();
    return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
  }

  if ( ( millis() - periodic_millis2 ) > delay_2 )
  {
    Serial.print("PERIODIC 2 - ");
    Serial.println(( millis() - periodic_millis2 ));
    Keyboard.press(periodic_key2);
    random_delay(100, 150);
    Keyboard.release(periodic_key2);
    random_delay(13, 30);

    delay_2 = random(periodic_min2, periodic_max2);
    periodic_millis2 = millis();
    return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
  }

  if ( ( millis() - periodic_millis3 ) > delay_3 )
  {
    Serial.print("PERIODIC 3 - ");
    Serial.println(( millis() - periodic_millis3 ));
    Keyboard.press(periodic_key3);
    random_delay(100, 150);
    Keyboard.release(periodic_key3);
    random_delay(13, 30);

    delay_3 = random(periodic_min3, periodic_max3);
    periodic_millis3 = millis();
    return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
  }

  if ( ( millis() - periodic_millis4 ) > delay_4 )
  {
    Serial.print("PERIODIC 4 - ");
    Serial.println(( millis() - periodic_millis4 ));
    Keyboard.press(periodic_key4);
    random_delay(100, 150);
    Keyboard.release(periodic_key4);
    random_delay(13, 30);

    delay_4 = random(periodic_min4, periodic_max4);
    periodic_millis4 = millis();
    return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
  }

  if ( ( millis() - periodic_millis5 ) > delay_5 )
  {
    Serial.print("PERIODIC 5 - ");
    Serial.println(( millis() - periodic_millis5 ));
    Keyboard.press(periodic_key5);
    random_delay(100, 150);
    Keyboard.release(periodic_key5);
    random_delay(13, 30);

    delay_5 = random(periodic_min5, periodic_max5);
    periodic_millis5 = millis();
    return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
  }

  if ( ( millis() - periodic_millis6 ) > delay_6 )
  {
    Serial.print("PERIODIC 6 - ");
    Serial.println(( millis() - periodic_millis6 ));
    Keyboard.press(periodic_key6);
    random_delay(100, 150);
    Keyboard.release(periodic_key6);
    random_delay(13, 30);

    delay_6 = random(periodic_min6, periodic_max6);
    periodic_millis6 = millis();
    return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
  }
}

void random_delay(int boundary_1, int boundary_2)
{
  int randNumber = random(boundary_1, boundary_2);
  delay(randNumber);
}

#include "skill_command.h"

void isr();
volatile unsigned long button_millis; // Debouncing 을 위하여 마지막으로 버튼 누른 시간을 저장

void setup()
{
  Keyboard.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  button_millis = millis();

  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), isr, FALLING);

  pinMode(13, OUTPUT); // 작동중을 알리기 위한 LED
  digitalWrite(13, LOW);
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
  Serial.println(millis());
  if (flag) // 버튼 누르지 않은 경우만 실행
  {
    ////////////////////////////////////////
    // 1번 동작
    ////////////////////////////////////////
    // -> 누름
    Keyboard.press(KEY_RIGHT_ARROW);
    random_delay(20, 40);
    process_periodic_key(); // 주기적 실행키 구동
    if ( flag == 0 ) return; // 실행 정지 체크

    // 4회 반복
    for ( int i = 0; i < 4; i++)
    {
      // 더블 점프
      Keyboard.press('d');
      random_delay(40, 60);
      Keyboard.release('d');
      random_delay(40, 60);
      Keyboard.press('d');
      random_delay(40, 60);
      Keyboard.release('d');
      random_delay(40, 60);

      attack();
      random_delay(100 * SPEED_FACTOR, 150 * SPEED_FACTOR);
      process_periodic_key(); // 주기적 실행키 구동
      if ( flag == 0 ) return; // 실행 정지 체크
    }

    // -> 뗌
    Keyboard.release(KEY_RIGHT_ARROW);
    random_delay(100, 150);
    process_periodic_key(); // 주기적 실행키 구동
    if ( flag == 0 ) return; // 실행 정지 체크


    ////////////////////////////////////////
    // 2번 동작
    ////////////////////////////////////////

    // 위로 점프
    Keyboard.press(jump_command);
    random_delay(20, 40);
    Keyboard.release(jump_command);
    random_delay(20, 40);
    random_delay(100 * SPEED_FACTOR, 150 * SPEED_FACTOR);
    process_periodic_key(); // 주기적 실행키 구동
    if ( flag == 0 ) return; // 실행 정지 체크

    // 기본 공격
    attack();
    random_delay(100 * SPEED_FACTOR, 150 * SPEED_FACTOR);
    process_periodic_key(); // 주기적 실행키 구동
    if ( flag == 0 ) return; // 실행 정지 체크

    ////////////////////////////////////////
    // 3번 동작
    ////////////////////////////////////////
    // <- 누름
    Keyboard.press(KEY_LEFT_ARROW);
    random_delay(20, 40);
    process_periodic_key(); // 주기적 실행키 구동
    if ( flag == 0 ) return; // 실행 정지 체크

    // 4회 반복
    for ( int i = 0; i < 4; i++)
    {
      // 점프
      // 더블 점프
      Keyboard.press('d');
      random_delay(40, 60);
      Keyboard.release('d');
      random_delay(40, 60);
      Keyboard.press('d');
      random_delay(40, 60);
      Keyboard.release('d');
      random_delay(40, 60);

      attack();
      random_delay(100 * SPEED_FACTOR, 150 * SPEED_FACTOR);
      process_periodic_key(); // 주기적 실행키 구동
      if ( flag == 0 ) return; // 실행 정지 체크
    }

    // -> 뗌
    Keyboard.release(KEY_LEFT_ARROW);
    random_delay(100, 150);
    process_periodic_key(); // 주기적 실행키 구동
    if ( flag == 0 ) return; // 실행 정지 체크
  }
}
