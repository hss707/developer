#define PAUSE_POINT() if ( check_stop() == false ) return;

const char periodic_key1 = 'q';
unsigned long periodic_millis1;
unsigned long periodic_min1 = 20000;
unsigned long periodic_max1 = 25000;
unsigned long delay_1 = ( periodic_min1 + periodic_max1) / 2;

const char periodic_key2 = 'w';
unsigned long periodic_millis2;
unsigned long periodic_min2 = 260000;
unsigned long periodic_max2 = 300000;
unsigned long delay_2 = ( periodic_min2 + periodic_max2) / 2;

const char periodic_key3 = 0; // 0일 경우 사용안함
unsigned long periodic_millis3;
unsigned long periodic_min3 = 31000;
unsigned long periodic_max3 = 35000;
unsigned long delay_3 = ( periodic_min3 + periodic_max3) / 2;

const char periodic_key4 = 0; // 0일 경우 사용안함
unsigned long periodic_millis4;
unsigned long periodic_min4 = 46000;
unsigned long periodic_max4 = 50000;
unsigned long delay_4 = ( periodic_min4 + periodic_max4) / 2;

const char periodic_key5 = 0; // 0일 경우 사용안함
unsigned long periodic_millis5;
unsigned long periodic_min5 = 45000;
unsigned long periodic_max5 = 50000;
unsigned long delay_5 = ( periodic_min5 + periodic_max5) / 2;

const char periodic_key6 = 0; // 0일 경우 사용안함
unsigned long periodic_millis6;
unsigned long periodic_min6 = 260000;
unsigned long periodic_max6 = 280000;
unsigned long delay_6 = ( periodic_min6 + periodic_max6) / 2;

const char periodic_key7 = 0; // 0일 경우 사용안함
unsigned long periodic_millis7;
unsigned long periodic_min7 = 260000;
unsigned long periodic_max7 = 280000;
unsigned long delay_7 = ( periodic_min7 + periodic_max7) / 2;

const char periodic_key8 = 0; // 0일 경우 사용안함
unsigned long periodic_millis8;
unsigned long periodic_min8 = 260000;
unsigned long periodic_max8 = 280000;
unsigned long delay_8 = ( periodic_min8 + periodic_max8) / 2;

const char periodic_key9 = 0; // 0일 경우 사용안함
unsigned long periodic_millis9;
unsigned long periodic_min9 = 260000;
unsigned long periodic_max9 = 280000;
unsigned long delay_9 = ( periodic_min9 + periodic_max9) / 2;

const char periodic_key10 = 0; // 0일 경우 사용안함
unsigned long periodic_millis10;
unsigned long periodic_min10 = 260000;
unsigned long periodic_max10 = 280000;
unsigned long delay_10 = ( periodic_min10 + periodic_max10) / 2;

// default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
// Board : ESP-12H KIT Module

volatile int macro_status = 0; // 0 : 일시정지, 1 : 구동중, 2 : 재시작

#include "kproject_hid_device.h"

//수정X
// const byte start = 3;    //핀
// const byte power_on = 2;      //핀
boolean state = true;
int t = 150;
int n = 6;
int acheck = 1;
int archeck = 1;
int anum = 0;            // 공격함수
int jnum = 0;             // 점프함수
int jjnum = 0;            // 점프함수2
int area = 0;             // 범위기함수
int mapnum = 0;        // 맵패턴함수
int maptnum = 0;        // 맵패턴함수2
int ordernum = 0;       // 오더함수
int iprj = 0;               //임페일, 레조넌스 함수
int iprjcheck = 1;
int dnum = 4000;
boolean isRihgt = true;

struct KEYSET {
  int up = 0xDA;
  int down = 0xD9;
  int left = 0xD8;
  int right = 0xD7;     // 방향키
  int lalt = 0x82;
  int ralt = 0x86;        // 점프
  int lctrl = 0x80;
  int rctrl = 0x84;        // 컨트롤
  int lshift = 0x81;
  int rshift = 0x85;        // 쉬프트
  int space = 0xB2;
  int insert = 0xD1;
  int pgdn = 0xD6;
  int pgup = 0xD3;
  int home = 0xD2;
  int Delete = 0xD4;
  int end = 0xD5;
  int backspace = 0xB2;
  int capslock = 0xC1;
  int tab = 0xB3;
  int f1 = 0xC2;
  int f2 = 0xC3;
  int f3 = 0xC4;
  int f4 = 0xC5;
  int f5 = 0xC6;
  int f6 = 0xC7;
  int f7 = 0xC8;
  int f8 = 0xC9;
  int f9 = 0xCA;
  int f10 = 0xCB;
  int f11 = 0xCC;
  int f12 = 0xCD;
};

KEYSET keys;

int arr[7] = {keys.lshift, keys.rshift, keys.lctrl, 'm', 'n', ',', '.'};       // 주력기배치
int at[2] = {keys.lalt, keys.ralt};           // 1단점프
int jp[3] = {keys.lalt, keys.ralt, 'v'};        // 2단점프

void setup()
{
  Serial.begin(115200);
  usb_hid_init();

  //  delay(10000);
  randomSeed(analogRead(A0));
  //pinMode(start, INPUT_PULLUP);
  //pinMode(power_on, INPUT_PULLUP);
  Keyboard.releaseAll();

  echo_flag = true;
}

void loop()
{
  Serial.println("STARTED");
  if ( macro_status == 2 )
    // 재시작한 것이므로 매크로 재시작 을 구동중으로 변경
  {
    macro_status = 1;
  }

  int no = random(0, 1);
  Serial.println(no);
  switch (no)
  {
    case 0:
      test1();
      break;
    case 1:
      test2();
      break;
    case 2:
      test3();
      break;
  }
}

//딜레이 정리
void pressKey(int key) {
  Keyboard.press(key);
  d_Main();
  Keyboard.releaseAll();
}
void pressKey_100(int key) {
  Keyboard.press(key);
  d_100();
  Keyboard.release(key);
}
void pressKey_280(int key) {
  Keyboard.press(key);
  d_280();
  Keyboard.release(key);
}
void pressTwoKey(int key1, int key2)
{
  Keyboard.press(key1);
  d_130();
  Keyboard.press(key2);
  d_80();
  Keyboard.release(key1);
  d_30();
  Keyboard.releaseAll();
}
void pressTwoKey_50(int key1, int key2)
{
  Keyboard.press(key1);
  d_50();
  Keyboard.press(key2);
  d_150();
  Keyboard.release(key1);
  d_50();
  Keyboard.releaseAll();
}



//기본
void Reset()
{
  Keyboard.releaseAll();
}

void Jump() {
  pressKey(at[jnum]);
  jnum = random(0, 2);
}
void Jump2() {
  pressKey(jp[jjnum]);
  jjnum = random(0, 3);
}
void Attack() {
  anum = random(0, 7);
  while (acheck == anum) {
    anum = random(0, 7);
  }
  pressKey(arr[anum]);
  acheck = anum;
}
void pAttack() {
  anum = random(0, 7);
  while (acheck == anum) {
    anum = random(0, 7);
  }
  Keyboard.press(arr[anum]);
  acheck = anum;
}

//방향키별
void Ujump() {
  pressTwoKey(keys.up, at[jnum]);
  jnum = random(0, 2);
}
void Ujump2() {
  pressTwoKey(keys.up, jp[jjnum]);
  jjnum = random(0, 3);
}
void Djump() {
  pressTwoKey(keys.down, at[jnum]);
  jnum = random(0, 2);
}
void Djump2() {
  pressTwoKey(keys.down, jp[jjnum]);
  jjnum = random(0, 3);
}
void Ljump() {
  pressTwoKey(keys.left, at[jnum]);
  jnum = random(0, 2);
}
void Ljump2() {
  pressTwoKey(keys.left, jp[jjnum]);
  jjnum = random(0, 3);
}
void Rjump() {
  pressTwoKey(keys.right, at[jnum]);
  jnum = random(0, 2);
}
void Rjump2() {
  pressTwoKey(keys.right, jp[jjnum]);
  jjnum = random(0, 3);
}

//응용 스킬
void Upjump() {
  Jump();
  Ujump();
  d_130();
}
void Downjump() {
  Djump();
  d_280();
}
void Doublejump() {
  Jump();
  Jump2();
  d_300();
}
void Doublejump2() {
  Jump();
  d_100();
  Jump2();
  d_300();
}
void Jumpdivide() {
  Jump();
  d_30();
  Jump2();
  rAlt();
  Attack();
  d_main();
}
void Jumpdividedouble() {
  Jump();
  d_30();
  Jump2();
  d_30();
  Jump();
  rAlt();
  Attack();
  d_main();
}
void JumpX() {
  Jump();
  d_30();
  Jump2();
  rAlt();
  X();
  d_main();
}
void JumpC() {
  Jump();
  d_30();
  Jump2();
  rAlt();
  C();
  d_main();
}
void Jumpdivide2() {
  for (int i = 0; i < 2; i++) {
    Jumpdivide();
  }
}
void Jumpdivide3() {
  for (int i = 0; i < 3; i++) {
    Jumpdivide();
  }
}
void Jumpdivide4() {
  for (int i = 0; i < 4; i++) {
    Jumpdivide();
  }
}
void Jumpdivide5() {
  for (int i = 0; i < 5; i++) {
    Jumpdivide();
  }
}
void Jumpdivide6() {
  for (int i = 0; i < 6; i++) {
    Jumpdivide();
  }
}
void Jumpdivide7() {
  for (int i = 0; i < 7; i++) {
    Jumpdivide();
  }
}
void Jumpdivide8() {
  for (int i = 0; i < 8; i++) {
    Jumpdivide();
  }
}
void Downjumpattack() {
  Djump();
  d_150();
  Attack();
  d_main();
}
void Downjumptread() {
  Djump();
  d_50();
  S2();
  d_350();
}
void Jumpdivideleft() {
  Jump();
  d_30();
  Ljump();
  Control();
  d_main();
}
void Jumpdivideright() {
  Jump();
  d_30();
  Rjump();
  Control();
  d_main();
}

void Area() {
  if (area == 0) {
    area = random(0, 5);
    while (archeck == area) {
      area = random(0, 5);
    }
    S1();
    S10();
    S7();
    S6();
    S11();
    archeck = area;
  }
  else if (area == 1) {
    area = random(0, 5);
    while (archeck == area) {
      area = random(0, 5);
    }
    S10();
    S1();
    S6();
    S7();
    S11();
    archeck = area;
  }
  else if (area == 2) {
    area = random(0, 5);
    while (archeck == area) {
      area = random(0, 5);
    }
    S11();
    S7();
    S10();
    S6();
    S1();
    archeck = area;
  }
  else if (area == 3) {
    area = random(0, 5);
    while (archeck == area) {
      area = random(0, 5);
    }
    S7();
    S11();
    S1();
    S6();
    S10();
    archeck = area;
  }
  else if (area == 4) {
    area = random(0, 5);
    while (archeck == area) {
      area = random(0, 5);
    }
    S10();
    S11();
    S6();
    S1();
    S7();
    archeck = area;
  }
  d_750();
}

void test1()
{
  // 1을 30회 출력
  /*
  for ( int i = 0; i < 30; i++)
  {
    if ( d_150() == false ) return;
    Keyboard.print("1");
  }
  PAUSE_POINT(); // 일시정지가 가능한 지점 설정
  if ( delay1(1000) == false ) return;
  PAUSE_POINT(); // 일시정지가 가능한 지점 설정
  */
    anum = random(0, 7);
    jnum = random(0, 2);
    jjnum = random(0, 3);
    mapnum = random(0, 2);
    maptnum = random(0, 2);
    iprj = random(0,3);


    //    3번툴
    //1번툴 1,2,3,4,5,6
    //2번툴 1,3,2,4,5,6
    //3번툴 1,2,3,4,5,6

    Rjump();
    PAUSE_POINT();
    d_50();
    PAUSE_POINT();
    pressTwoKey(keys.up, keys.right);
    PAUSE_POINT();
    dfff();
    PAUSE_POINT();
    d_250();
    PAUSE_POINT();
    Jumpdivideright();
    PAUSE_POINT();
    Jumpdivide3();
    PAUSE_POINT();
    Q();
    PAUSE_POINT();
    d_1000();
    PAUSE_POINT();
    Jump();
    PAUSE_POINT();
    Jumpdivideleft();
    PAUSE_POINT();
    Jumpdivide();
    PAUSE_POINT();
    Area();
    PAUSE_POINT();
    Jumpdivide3();
    PAUSE_POINT();
    d_100();
    PAUSE_POINT();
    k_3();
    PAUSE_POINT();
    d_550();
    PAUSE_POINT();

    Rjump();
    PAUSE_POINT();
    d_60();
    PAUSE_POINT();
    pressTwoKey(keys.up, keys.right);
    PAUSE_POINT();
    dfff();
    PAUSE_POINT();
    d_300();
    PAUSE_POINT();
    Jumpdivideright();
    PAUSE_POINT();
    Jumpdivide3();
    PAUSE_POINT();
    Q();
    PAUSE_POINT();
    d_1000();
    PAUSE_POINT();
    Jump();
    PAUSE_POINT();
    Jumpdivideleft();
    PAUSE_POINT();
    Jumpdivide4();
    PAUSE_POINT();
    d_550();
    PAUSE_POINT();

    Jumpdivideright();
    PAUSE_POINT();
    Jumpdivide2();
    PAUSE_POINT();
    Area();
    PAUSE_POINT();
    Jumpdivide2(); 
    PAUSE_POINT();
    d_150();
    PAUSE_POINT();
    Jumpdivideleft();
    PAUSE_POINT();
    Jumpdivide4();
    PAUSE_POINT();
    d_550();
    PAUSE_POINT();

    Rjump();
    PAUSE_POINT();
    d_70();
    PAUSE_POINT();
    pressTwoKey_50(keys.up, keys.right);
    PAUSE_POINT();
    dfff();
    PAUSE_POINT();
    d_300();
    PAUSE_POINT();
    Jumpdivideright();
    PAUSE_POINT();
    Jumpdivide3();
    PAUSE_POINT();
    Q();
    PAUSE_POINT();
    d_1000();
    PAUSE_POINT();
    Jump();
    PAUSE_POINT();
    Jumpdivideleft();
    PAUSE_POINT();
    Jumpdivide4();
    PAUSE_POINT();
    d_550();
    PAUSE_POINT();

    Jumpdivideright();
    PAUSE_POINT();
    Jumpdivide4();
    PAUSE_POINT();
    d_150();
    PAUSE_POINT();
    Jumpdivideleft();
    PAUSE_POINT();
    Jumpdivide2();
    PAUSE_POINT();
    Area();
    PAUSE_POINT();
    Jumpdivide2();
    PAUSE_POINT();
    d_600();
    PAUSE_POINT();

    Rjump();
    PAUSE_POINT();
    d_70();
    PAUSE_POINT();
    pressTwoKey_50(keys.up, keys.right);
    PAUSE_POINT();
    dfff();
    PAUSE_POINT();
    Jumpdivideright();
    PAUSE_POINT();
    Jumpdivide3();
    PAUSE_POINT();
    Q();
    PAUSE_POINT();
    d_1000();
    PAUSE_POINT();
    Jump();
    PAUSE_POINT();
    Jumpdivideleft();
    PAUSE_POINT();
    Jumpdivide3();
    PAUSE_POINT();
    Area();
    PAUSE_POINT();
    Jumpdivide();
    PAUSE_POINT();
    d_600();
    PAUSE_POINT();


    /*
    Jumpdivideright();    //패턴 1
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_130() == false ) return; //수정 110(130)_110,120,130
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_200() == false ) return;        //수정 150[200]_150,200,200
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jump();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    S();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_1700() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivideleft();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpC();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_750() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_620() == false ) return;        //수정 650[620]_650,630,620
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정

    Jumpdivideright();    //패턴 2
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_100() == false ) return;        //수정 130[100]_130,110,100
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_150() == false ) return;        //수정 200[150]_200,150,150
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jump();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    S();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_1700() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivideleft();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpC();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_750() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivide2();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_650() == false ) return;        //수정 620[650]_620,650,650
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정

    Jumpdivideright();    //패턴 3
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivide2();        //수정 원본(수정)_1번툴,2번툴,3번툴...
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_150() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jump();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    S();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_1700() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivideleft();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_750() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivide();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_650() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정

    Jumpdivideright();    //패턴 4
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_110() == false ) return;        //수정 120[110]_120,100,110
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_150() == false ) return;        //수정 200[150]_200,150,150
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jump();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    S();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_1700() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivideleft();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpC();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_750() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_650() == false ) return;        //수정 630[650]_630,650.650
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정

    Jumpdivideright();    //패턴  5
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_120() == false ) return;        //수정 130[120]_130,130,120
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_200() == false ) return;        //수정 150[200]_150,150,200
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jump();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    S();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_1700() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivideleft();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpC();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_750() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivide();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_630() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정

    Jumpdivideright();    //패턴  6
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_130() == false ) return;        //수정 100[130]_100,130,130
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_150() == false ) return;        //수정 150[150]_150,200,150
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jump();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    S();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_1700() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdivideleft();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    JumpC();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_750() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Jumpdividedouble();
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    if ( d_630() == false ) return;        //수정 650[630]_650,620,630
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정

    Reset();
  */
}

void test2()
{
  // 2를 30회 출력
  for ( int i = 0; i < 30; i++)
  {
    if ( d_150() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Keyboard.print("2");
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
  }
  if ( delay1(1000) == false ) return;
  PAUSE_POINT(); // 일시정지가 가능한 지점 설정
}

void test3()
{
  // 3를 30회 출력
  for ( int i = 0; i < 30; i++)
  {
    if ( d_150() == false ) return;
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
    Keyboard.print("3");
    PAUSE_POINT(); // 일시정지가 가능한 지점 설정
  }
  if ( delay1(1000) == false ) return;
  PAUSE_POINT(); // 일시정지가 가능한 지점 설정
}
