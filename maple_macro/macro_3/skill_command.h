void attack();

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
