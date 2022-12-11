bool delay1(unsigned long val)
{
  unsigned long start_millis = millis();
  while ((millis() - start_millis ) < val )
  {
    process_periodic_key();
    yield();
    if ( macro_status == 2 ) // 재시작인 경우
    {
      return false;
    }
  }
  process_periodic_key();
  return true;
}

bool check_stop()
{
  if ( macro_status == 0 ) // 구동중이 아닌 경우
  {
    macro_flag = false;
    force_releaseall();
  }

  while ( macro_status != 1 ) // 구동중이 아닌 경우
  {
    yield();
    if ( macro_status == 2 ) // 재시작인 경우
    {
      return false;
    }
  }
  return true;
}

bool d_main() {
  return delay1(random(random(470, 500), random(500, 530)));
}
bool d_Main() {
  return delay1(random(random(130, 155), random(155, 180)));
}
bool d_10() {
  return delay1(random(random(10, 35), random(35, 60)));
}
bool d_20() {
  return delay1(random(random(20, 45), random(45, 70)));
}
bool d_30() {
  return delay1(random(random(30, 55), random(55, 80)));
}
bool d_40() {
  return delay1(random(random(40, 65), random(65, 90)));
}
bool d_50() {
  return delay1(random(random(50, 75), random(75, 100)));
}
bool d_60() {
  return delay1(random(random(60, 85), random(85, 110)));
}
bool d_70() {
  return delay1(random(random(70, 95), random(95, 120)));
}
bool d_80() {
  return delay1(random(random(80, 105), random(105, 130)));
}
bool d_90() {
  return delay1(random(random(90, 115), random(115, 140)));
}
bool d_100() {
  return delay1(random(random(100, 125), random(125, 150)));
}
bool d_110() {
  return delay1(random(random(110, 135), random(135, 160)));
}
bool d_120() {
  return delay1(random(random(120, 145), random(145, 170)));
}
bool d_130() {
  return delay1(random(random(130, 155), random(155, 180)));
}
bool d_140() {
  return delay1(random(random(140, 165), random(165, 190)));
}
bool d_150() {
  return delay1(random(random(150, 175), random(175, 200)));
}
bool d_160() {
  return delay1(random(random(160, 185), random(185, 210)));
}
bool d_170() {
  return delay1(random(random(170, 195), random(195, 220)));
}
bool d_180() {
  return delay1(random(random(180, 205), random(205, 230)));
}
bool d_190() {
  return delay1(random(random(190, 215), random(215, 240)));
}
bool d_200() {
  return delay1(random(random(200, 225), random(225, 250)));
}
bool d_210() {
  return delay1(random(random(210, 235), random(235, 260)));
}
bool d_220() {
  return delay1(random(random(220, 245), random(245, 270)));
}
bool d_230() {
  return delay1(random(random(230, 255), random(255, 280)));
}
bool d_240() {
  return delay1(random(random(240, 265), random(265, 290)));
}
bool d_250() {
  return delay1(random(random(250, 275), random(275, 300)));
}
bool d_260() {
  return delay1(random(random(260, 285), random(285, 310)));
}
bool d_270() {
  return delay1(random(random(270, 295), random(295, 320)));
}
bool d_280() {
  return delay1(random(random(280, 305), random(305, 330)));
}
bool d_290() {
  return delay1(random(random(290, 315), random(315, 340)));
}
bool d_300() {
  return delay1(random(random(300, 325), random(325, 350)));
}
bool d_310() {
  return delay1(random(random(310, 335), random(335, 360)));
}
bool d_320() {
  return delay1(random(random(320, 345), random(345, 370)));
}
bool d_330() {
  return delay1(random(random(330, 355), random(355, 380)));
}
bool d_340() {
  return delay1(random(random(340, 365), random(365, 390)));
}
bool d_350() {
  return delay1(random(random(350, 375), random(375, 400)));
}
bool d_360() {
  return delay1(random(random(360, 385), random(385, 410)));
}
bool d_370() {
  return delay1(random(random(370, 395), random(395, 420)));
}
bool d_380() {
  return delay1(random(random(380, 405), random(405, 430)));
}
bool d_390() {
  return delay1(random(random(390, 415), random(415, 440)));
}
bool d_400() {
  return delay1(random(random(400, 425), random(425, 450)));
}
bool d_410() {
  return delay1(random(random(410, 435), random(435, 460)));
}
bool d_420() {
  return delay1(random(random(420, 445), random(445, 470)));
}
bool d_430() {
  return delay1(random(random(430, 455), random(455, 480)));
}
bool d_440() {
  return delay1(random(random(440, 465), random(465, 490)));
}
bool d_450() {
  return delay1(random(random(450, 475), random(475, 500)));
}
bool d_460() {
  return delay1(random(random(460, 485), random(485, 510)));
}
bool d_470() {
  return delay1(random(random(470, 495), random(495, 520)));
}
bool d_480() {
  return delay1(random(random(480, 505), random(505, 530)));
}
bool d_490() {
  return delay1(random(random(490, 515), random(515, 540)));
}
bool d_500() {
  return delay1(random(random(500, 525), random(525, 550)));
}
bool d_510() {
  return delay1(random(random(510, 535), random(535, 560)));
}
bool d_520() {
  return delay1(random(random(520, 545), random(545, 570)));
}
bool d_530() {
  return delay1(random(random(530, 555), random(555, 580)));
}
bool d_540() {
  return delay1(random(random(540, 565), random(565, 590)));
}
bool d_550() {
  return delay1(random(random(550, 575), random(575, 600)));
}
bool d_560() {
  return delay1(random(random(560, 585), random(585, 610)));
}
bool d_570() {
  return delay1(random(random(570, 595), random(595, 620)));
}
bool d_580() {
  return delay1(random(random(580, 605), random(605, 630)));
}
bool d_590() {
  return delay1(random(random(590, 615), random(615, 640)));
}
bool d_600() {
  return delay1(random(random(600, 625), random(625, 650)));
}
bool d_610() {
  return delay1(random(random(610, 635), random(635, 660)));
}
bool d_620() {
  return delay1(random(random(620, 645), random(645, 670)));
}
bool d_630() {
  return delay1(random(random(630, 655), random(655, 680)));
}
bool d_640() {
  return delay1(random(random(640, 665), random(665, 690)));
}
bool d_650() {
  return delay1(random(random(650, 675), random(675, 700)));
}
bool d_750() {
  return delay1(random(random(750, 775), random(775, 800)));
}
bool d_1000() {
  return delay1(random(random(1000, 1025), random(1025, 1050)));
}
bool d_1250() {
  return delay1(random(random(1250, 1275), random(1275, 1300)));
}
bool d_1500() {
  return delay1(random(random(1500, 1525), random(1525, 1550)));
}
bool d_1700() {
  return delay1(random(random(1700, 1725), random(1725, 1750)));
}
