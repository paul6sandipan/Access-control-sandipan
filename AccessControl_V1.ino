#include <EEPROM.h>
#include <Keypad.h>
#include <SD.h>
#include <SPI.h>

const int numberOfUsers = 5;
String password[] = {"0000", "1111", "2222", "3333", "4444"};
String userName[] = {"Arnab", "Sakib", "Daddy Shamim", "Hirok", "Jakia"};
String typedPassword = "";
int eeAddress = 0;
String s;
int user;
int CS_PIN = 10;
File passwordFile;

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {3, 4, 5, 6};
byte colPins[COLS] = {7, 8, 9};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  EEPROM.put(eeAddress, password);
}

void loop() {

  Serial.println("Door closed. Press '*' to type password");
  char key = keypad.getKey();

  do {
    key = keypad.getKey();
  } while (key != '*');
  Serial.println("Now input your four digit password");

  typeYourPassword();
  user = matchPassword(typedPassword, password);
  if ( user > -1)
  {
    Serial.println("Entry granted to " + userName[user]);
    NEW_PASSWORD();
  }
  else
  {
    Serial.println("Access Denied. Try Again");
  }

// Getting data from EEPROM ***

String password1[5]= EEPROM.get(eeAddress, password);
Serial.println(password1[0]);
Serial.println(password1[1]);
Serial.println(password1[2]);
Serial.println(password1[3]);
Serial.println(password1[4]);
}
