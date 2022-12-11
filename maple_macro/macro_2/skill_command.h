int factor = 3.0;

void attack();

void right_jump_explosion()
{
  // 오른쪽으로
  Keyboard.press(KEY_RIGHT_ARROW);
  random_delay(20, 40);
  {
    // 점프후
    Keyboard.press(jump_command);
    random_delay(100, 150);
    Keyboard.press('x');
    random_delay(100, 150);
    Keyboard.release('x');
    random_delay(80, 110);
    Keyboard.release(jump_command);
    random_delay(80, 110);
  }
  // 오른쪽 키 해제
  Keyboard.release(KEY_RIGHT_ARROW);
  random_delay(20 * factor, 30 * factor);

  // 크루얼스텝
  attack();

  // 익스플로전
  Keyboard.press(meso_explosion_command);
  random_delay(20, 35);
  Keyboard.release(meso_explosion_command);
  random_delay(80 * 3.5, 110 * 3.5);
}

void left_jump_explosion()
{
  // 왼쪽으로
  Keyboard.press(KEY_LEFT_ARROW);
  random_delay(20, 40);
  {
    // 점프후
    Keyboard.press(jump_command);
    random_delay(100, 150);
    Keyboard.press('x');
    random_delay(100, 150);
    Keyboard.release('x');
    random_delay(80, 110);
    Keyboard.release(jump_command);
    random_delay(80 , 110 );
  }
  // 왼쪽 키 해제
  Keyboard.release(KEY_LEFT_ARROW);
  random_delay(20 * factor, 30 * factor);

  // 크루얼스텝
  attack();

  // 익스플로전
  Keyboard.press(meso_explosion_command);
  random_delay(20, 35);
  Keyboard.release(meso_explosion_command);
  random_delay(80 * 3.5, 110 * 3.5);
}

void attack()
{
  int randNum = random(0, 3);
  int randNumber = 0;
  switch (randNum)
  {
    case 0:
      Keyboard.press(attack_command_1);
      random_delay(13, 30);
      Keyboard.release(attack_command_1);
      break;
    case 1:
      Keyboard.press(attack_command_2);
      random_delay(13, 30);
      Keyboard.release(attack_command_2);
      break;
    case 2:
      Keyboard.press(attack_command_3);
      random_delay(13, 30);
      Keyboard.release(attack_command_3);
      break;
  }
  random_delay(200, 250);
}

void sinmi()
{
#ifdef _DEBUG
  Serial.print(millis());
  Serial.print("-");
  Serial.println("sinmi");
#endif
  Keyboard.press(sinmi_command);              // PRESS sinmi
  random_delay(100, 150);
  Keyboard.release(sinmi_command);            // RELEASE sinmi
  random_delay(13, 30);
}
