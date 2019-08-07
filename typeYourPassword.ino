void typeYourPassword ()
{
  char key0 = 0;
  typedPassword= "";
  for (int x = 0; x < 4; x++) {

    key0 = 0;
    while (key0 == 0) {
      key0 = keypad.getKey();
    }
    Serial.print("*");
    typedPassword += key0;
  }
  
    Serial.println();
}
