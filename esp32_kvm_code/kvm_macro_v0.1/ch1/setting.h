#define MY_ID 0

#define ACTIVE_KEY_NO 8
#define UNACTIVE_KEY_NO 8

char active_key[ACTIVE_KEY_NO][8] =
{
  { 0x1, 0, 0x3A, 0, 0, 0, 0, 0 } , // CTRL + F1
  { 0x1, 0, 0x3B, 0, 0, 0, 0, 0 } , // CTRL + F2
  { 0x1, 0, 0x3C, 0, 0, 0, 0, 0 } , // CTRL + F3
  { 0x1, 0, 0x3D, 0, 0, 0, 0, 0 } , // CTRL + F4
  { 0x1, 0, 0x3E, 0, 0, 0, 0, 0 } , // CTRL + F5
  { 0x1, 0, 0x3F, 0, 0, 0, 0, 0 } , // CTRL + F6
  { 0x1, 0, 0x40, 0, 0, 0, 0, 0 } , // CTRL + F7
  { 0x1, 0, 0x41, 0, 0, 0, 0, 0 } , // CTRL + F7
};

char all_off_key[8]  = 
// 모든 채널 끄기 단축키
{
  0x01, 0, 0x29,  0, 0, 0, 0, 0 // CTRL + ESC
};

char all_macro_off_key[8]  = 
// 모든 채널 매크로 끄기 단축키
{
  0x01, 0, 0x45,  0, 0, 0, 0, 0 // CTRL + F12
};

/*
const char* ssid = "taeyoung";
const char* password = "87654321ab";
*/
const char* ssid = "taeyoung";
const char* password = "87654321ab";

const char* keyboard_manufact = "Holtek";
const char* keyboard_product = "USB Keyboard";

const char* mouse_manufact = "SIGMACHIP";
const char* mouse_product = "Usb Mouse";

uint16_t ch9329_vid = 0x04D9;
uint16_t ch9329_pid = 0x1603;
uint16_t mouse_vid = 0x1C4F;
uint16_t mouse_pid = 0x0034;

// 공통 변수
// 시작시 세팅
volatile int mouse_flag = false; // 마우스 작동
volatile int keyboard_flag = false; // 키보드 작동
volatile int macro_flag = false; // 매크로 작동

volatile int green_btn = false;
volatile int red_btn = false;
