
void NEW_PASSWORD() {
  Serial.println("Press '*' to change password. Press '#' to exit.");
  char key1 = keypad.getKey();
  do {
    key1 = keypad.getKey();
  } while (key1 != '*' && key1 != '#');
  if (key1 == '*')
  {
    Serial.println("Type new four letter password");
    char key2 = 0;
    typedPassword = "";
    for (int r = 0; r < 4; r++) {

      key2 = 0;
      while (key2 == 0) {

        key2 = keypad.getKey();

      }
      Serial.println("*");
       typedPassword += key2;

    }
    password[user] = typedPassword;
    Serial.println("Your new password is "+ typedPassword);
  }
  else
  {
    Serial.println("Have a nice day");
  }
  EEPROM.put(eeAddress, password);
}
