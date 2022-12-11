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
