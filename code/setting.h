#define MY_ID 0 // 0~7

#define MODULE_NO 8

char reset_key[MODULE_NO][8] = 
{
  { 0x00, 0, 0x29, 0x3A, 0, 0, 0, 0 } ,  // ESC + F1
  { 0x00, 0, 0x29, 0x3B, 0, 0, 0, 0 } ,  // ESC + F2
  { 0x00, 0, 0x29, 0x3C, 0, 0, 0, 0 } ,  // ESC + F3
  { 0x00, 0, 0x29, 0x3D, 0, 0, 0, 0 } ,  // ESC + F4
  { 0x00, 0, 0x29, 0x3E, 0, 0, 0, 0 } ,  // ESC + F5
  { 0x00, 0, 0x29, 0x3F, 0, 0, 0, 0 } ,  // ESC + F6
  { 0x00, 0, 0x29, 0x40, 0, 0, 0, 0 } ,  // ESC + F7
  { 0x00, 0, 0x29, 0x41, 0, 0, 0, 0 } ,  // ESC + F8
};

char active_key[MODULE_NO][8] =
{
  { 0x1, 0, 0x3A, 0, 0, 0, 0, 0 } , // CTRL + F1
  { 0x1, 0, 0x3B, 0, 0, 0, 0, 0 } , // CTRL + F2
  { 0x1, 0, 0x3C, 0, 0, 0, 0, 0 } , // CTRL + F3
  { 0x1, 0, 0x3D, 0, 0, 0, 0, 0 } , // CTRL + F4
  { 0x1, 0, 0x3E, 0, 0, 0, 0, 0 } , // CTRL + F5
  { 0x1, 0, 0x3F, 0, 0, 0, 0, 0 } , // CTRL + F6
  { 0x1, 0, 0x40, 0, 0, 0, 0, 0 } , // CTRL + F7
  { 0x1, 0, 0x41, 0, 0, 0, 0, 0 } , // CTRL + F8
};

char macro_restart_key[MODULE_NO][8] =
{
  { 0x1, 0, 0x1E, 0, 0, 0, 0, 0 } , // CTRL + 1
  { 0x1, 0, 0x1F, 0, 0, 0, 0, 0 } , // CTRL + 2
  { 0x1, 0, 0x20, 0, 0, 0, 0, 0 } , // CTRL + 3
  { 0x1, 0, 0x21, 0, 0, 0, 0, 0 } , // CTRL + 4
  { 0x1, 0, 0x22, 0, 0, 0, 0, 0 } , // CTRL + 5
  { 0x1, 0, 0x23, 0, 0, 0, 0, 0 } , // CTRL + 6
  { 0x1, 0, 0x24, 0, 0, 0, 0, 0 } , // CTRL + 7
  { 0x1, 0, 0x25, 0, 0, 0, 0, 0 } , // CTRL + 8
};

char macro_resume_key[MODULE_NO][8] =
{
  { 0x2, 0, 0x3A, 0, 0, 0, 0, 0 } , // SHIFT + F1
  { 0x2, 0, 0x3B, 0, 0, 0, 0, 0 } , // SHIFT + F2
  { 0x2, 0, 0x3C, 0, 0, 0, 0, 0 } , // SHIFT + F3
  { 0x2, 0, 0x3D, 0, 0, 0, 0, 0 } , // SHIFT + F4
  { 0x2, 0, 0x3E, 0, 0, 0, 0, 0 } , // SHIFT + F5
  { 0x2, 0, 0x3F, 0, 0, 0, 0, 0 } , // SHIFT + F6
  { 0x2, 0, 0x40, 0, 0, 0, 0, 0 } , // SHIFT + F7
  { 0x2, 0, 0x41, 0, 0, 0, 0, 0 } , // SHIFT + F8
};

char periodic_reset_key[MODULE_NO][8] =
{
  { 0x3, 0, 0x3A, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F1
  { 0x3, 0, 0x3B, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F2
  { 0x3, 0, 0x3C, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F3
  { 0x3, 0, 0x3D, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F4
  { 0x3, 0, 0x3E, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F5
  { 0x3, 0, 0x3F, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F6
  { 0x3, 0, 0x40, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F7
  { 0x3, 0, 0x41, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + F8
};

// 불가한 사항인데 매뉴얼에 갑자기 들어가 있음.
char active_key2[MODULE_NO][8] =
{
  { 0x3, 0, 0x1E, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 1
  { 0x3, 0, 0x1F, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 2
  { 0x3, 0, 0x20, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 3
  { 0x3, 0, 0x21, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 4
  { 0x3, 0, 0x22, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 5
  { 0x3, 0, 0x23, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 6
  { 0x3, 0, 0x24, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 7
  { 0x3, 0, 0x25, 0, 0, 0, 0, 0 } , // CTRL + SHIFT + 8
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
volatile int echo_flag = false; // 마우스 키보드 입력값 출력

volatile int green_btn = false;
volatile int red_btn = false;
