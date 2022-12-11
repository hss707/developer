void random_delay(int boundary_1, int boundary_2)
{
  int randNumber = random(boundary_1, boundary_2);
  delay(randNumber);
}

void process_periodic_key()
{
  if ( periodic_key1 != 0 )
    if ( ( millis() - periodic_millis1 ) > delay_1 )
    {
      Serial.print("PERIODIC 1 - ");
      Serial.println(( millis() - periodic_millis1 ));
      Keyboard.press(periodic_key1);
      random_delay(100, 150);
      Keyboard.release(periodic_key1);
      random_delay(13, 30);

      delay_1 = random(periodic_min1, periodic_max1);
      periodic_millis1 = millis();
      return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
    }

  if ( periodic_key2 != 0 )
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

  if ( periodic_key3 != 0 )
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

  if ( periodic_key4 != 0 )
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

  if ( periodic_key5 != 0 )
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

  if ( periodic_key6 != 0 )
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

  if ( periodic_key7 != 0 )
    if ( ( millis() - periodic_millis7 ) > delay_7 )
    {
      Serial.print("PERIODIC 7 - ");
      Serial.println(( millis() - periodic_millis7 ));
      Keyboard.press(periodic_key7);
      random_delay(100, 150);
      Keyboard.release(periodic_key7);
      random_delay(13, 30);

      delay_7 = random(periodic_min7, periodic_max7);
      periodic_millis7 = millis();
      return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
    }

  if ( periodic_key8 != 0 )
    if ( ( millis() - periodic_millis8 ) > delay_8 )
    {
      Serial.print("PERIODIC 8 - ");
      Serial.println(( millis() - periodic_millis8 ));
      Keyboard.press(periodic_key8);
      random_delay(100, 150);
      Keyboard.release(periodic_key8);
      random_delay(13, 30);

      delay_8 = random(periodic_min8, periodic_max8);
      periodic_millis8 = millis();
      return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
    }

  if ( periodic_key9 != 0 )
    if ( ( millis() - periodic_millis9 ) > delay_9 )
    {
      Serial.print("PERIODIC 9 - ");
      Serial.println(( millis() - periodic_millis9 ));
      Keyboard.press(periodic_key9);
      random_delay(100, 150);
      Keyboard.release(periodic_key9);
      random_delay(13, 30);

      delay_9 = random(periodic_min9, periodic_max9);
      periodic_millis9 = millis();
      return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
    }

  if ( periodic_key10 != 0 )
    if ( ( millis() - periodic_millis10 ) > delay_10 )
    {
      Serial.print("PERIODIC 10 - ");
      Serial.println(( millis() - periodic_millis10 ));
      Keyboard.press(periodic_key10);
      random_delay(100, 150);
      Keyboard.release(periodic_key10);
      random_delay(13, 30);

      delay_10 = random(periodic_min10, periodic_max10);
      periodic_millis10 = millis();
      return; // 동시에 2개 이상의 주기적키가 입력되지 않도록 한다
    }
}

void S1() { // 테리토리
  End();
}
void S2() { // 트레드
  Q();
}
void S3() { // 임페일
  D();
}
void S4() { // 레조넌스
  FF();
}
void S5() { // 오더
  A();
}
void S6() { // 루인
  R();
}
void S7() { // 마커
  G();
}
void S8() { // 페더
  Z();
}
void S9() { // 게더링
  T();
}
void S10() { // 블로섬
  k_4();
}
void S11() { // 스톰
  k_5();
  d_150();
}
void S12() { // 인피니티
  C();
  d_150();
}
void S13() { // 리스토어
  X();
  d_150();
}
void S14() { // 스인미
  k_3();
}
void S15() { // 로프
  S();
}
void S16() { // 에르다파운틴
 d_350();
 pressTwoKey(keys.down, 'd');
 rD();
 d_750();
}
void dfff() {  // 임페일 
    pD();
    d_140();
    Reset();
    pF();
    delay1(random(60, 91));
    Reset();
    pF();
    delay1(random(60, 91));
    Reset();
    pF();
    delay1(random(60, 91));
    Reset();
  }
  
  /*
  if (iprj == 0) {
    iprj = random(0, 3);
    while (iprjcheck == iprj) {
      iprj = random(0, 3);
    }
    pD();
    d_140();
    Reset();
    pF();
    delay1(94);
    Reset();
    pF();
    delay1(62);
    Reset();
    pF();
    delay1(64);
    Reset();
    iprjheck = iprj;
  }
  else if (iprj == 1) {
    iprj = random(0, 3);
    while (iprjcheck == iprj) {
      iprj = random(0, 3);
    }
    pD();
    d_140();
    Reset();
    pF();
    delay1(100);
    Reset();
    pF();
    delay1(64);
    Reset();
    pF();
    delay1(96);
    Reset();
    iprjheck = iprj;
  }
  else if (area == 2) {
    area = random(0, 5);
    while (archeck == area) {
      area = random(0, 5);
    }
    pD();
    d_140();
    Reset();
    pF();
    delay1(94);
    Reset();
    pF();
    delay1(96);
    Reset();
    pF();
    delay1(126);
    Reset();
    iprjheck = iprj;
  }
  d_250();
}
}
*/
