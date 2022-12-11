// default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
// Board : ESP-12H KIT Module

#include "kproject_hid_device.h"

//수정X

const byte start = 3;    //핀
const byte power_on = 2;      //핀
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

void setup() {
  Serial.begin(115200);
  usb_hid_init();
  
  delay(10000);
  randomSeed(analogRead(A0));
  //pinMode(start, INPUT_PULLUP);
  //pinMode(power_on, INPUT_PULLUP);
  Keyboard.releaseAll();
}

void loop() 
{
//  if (digitalRead(power_on) == LOW) 
  {
//    if (digitalRead(start) == LOW) 
    {
      doPattern();
    }
  }
}

void doPattern() {
  test1();
}

void test1() {
  anum = random(0, 7);
  jnum = random(0, 2);
  jjnum = random(0, 3);
  mapnum = random(0, 2);
  maptnum = random(0, 2);


  //    3번툴
  //1번툴 1,2,3,4,5,6
  //2번툴 1,3,2,4,5,6
  //3번툴 1,2,3,4,5,6

  Jumpdivideright();    //패턴 1
  JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
  d_130();        //수정 110(130)_110,120,130
  Jumpdividedouble();
  Jumpdividedouble();
  d_200();        //수정 150[200]_150,200,200
  Jump();
  S();
  d_1700();
  Jumpdivideleft();
  Jumpdividedouble();
  JumpC();
  d_750();
  Jumpdividedouble();
  d_620();        //수정 650[620]_650,630,620

  Jumpdivideright();    //패턴 2
  JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
  d_100();        //수정 130[100]_130,110,100
  Jumpdividedouble();
  Jumpdividedouble();
  d_150();        //수정 200[150]_200,150,150
  Jump();
  S();
  d_1700();
  Jumpdivideleft();
  Jumpdividedouble();
  JumpC();
  d_750();
  Jumpdivide2();
  d_650();        //수정 620[650]_620,650,650

  Jumpdivideright();    //패턴 3
  Jumpdivide2();        //수정 원본(수정)_1번툴,2번툴,3번툴...
  d_150();
  Jump();
  S();
  d_1700();
  Jumpdivideleft();
  Jumpdividedouble();
  d_750();
  Jumpdivide();
  d_650();

  Jumpdivideright();    //패턴 4
  JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
  d_110();        //수정 120[110]_120,100,110
  Jumpdividedouble();
  Jumpdividedouble();
  d_150();        //수정 200[150]_200,150,150
  Jump();
  S();
  d_1700();
  Jumpdivideleft();
  Jumpdividedouble();
  JumpC();
  d_750();
  Jumpdividedouble();
  d_650();        //수정 630[650]_630,650.650

  Jumpdivideright();    //패턴  5
  JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
  d_120();        //수정 130[120]_130,130,120
  Jumpdividedouble();
  Jumpdividedouble();
  d_200();        //수정 150[200]_150,150,200
  Jump();
  S();
  d_1700();
  Jumpdivideleft();
  Jumpdividedouble();
  JumpC();
  d_750();
  Jumpdivide();
  d_630();

  Jumpdivideright();    //패턴  6
  JumpX();        //수정 원본(수정)_1번툴,2번툴,3번툴...
  d_130();        //수정 100[130]_100,130,130
  Jumpdividedouble();
  Jumpdividedouble();
  d_150();        //수정 150[150]_150,200,150
  Jump();
  S();
  d_1700();
  Jumpdivideleft();
  Jumpdividedouble();
  JumpC();
  d_750();
  Jumpdividedouble();
  d_630();        //수정 650[630]_650,620,630

  Reset();
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
  Keyboard.releaseAll();
}
void pressKey_280(int key) {
  Keyboard.press(key);
  d_280();
  Keyboard.releaseAll();
}
void pressTwoKey(int key1, int key2) {
  Keyboard.press(key1);
  d_130();
  pressKey_100(key2);
  Keyboard.releaseAll();
}
void pressTwoKey_50(int key1, int key2) {
  Keyboard.press(key1);
  d_50();
  pressKey_280(key2);
  Keyboard.releaseAll();
}



//기본
void Reset() {
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
