#include <Wire.h> 
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

String getTime() {
  String time_str;
  int time = millis() / 1000;
  if (time / 60 / 60 < 10) { 
    time_str +="0"; 
  }
  time_str += time / 60 / 60;
  time_str += ":";
  if (time / 60 % 60 < 10) { time_str += "0"; }
  time_str += (time / 60) % 60;
  time_str += ":";
  if (time % 60 < 10) { time_str += "0"; }
  time_str += time % 60;
  return time_str;
}

byte SendData[8] = { 0x01, 0x03, 0x00, 0x04, 0x00, 0x01, 0xC5, 0xCB };

void setup()
{
  lcd.init(); 
  lcd.backlight();

  if(!SD.begin(10)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("sd not found!");
    delay(1500);
  }

  
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  
}

void loop()
{
  digitalWrite(7, HIGH);
  for (byte i = 0; i < 8; i++) {
    Serial.write(SendData[i]);
    delay(1);
  }
  delay(1);
  digitalWrite(7, LOW);
  delay(100);
  byte response[8];
  int bytesRead = 0;
  while (Serial.available() && bytesRead < sizeof(response)) {
    response[bytesRead++] = Serial.read();
  }
  String data;
  for (int i = 4; i <= 5; i++) {
    String s = String(response[i], HEX);
    while (s.length() < 2) {
      s = "0" + s;
    }
    data += s;
  }
  
  char charArray[data.length() + 1];
  data.toCharArray(charArray, data.length() + 1);
  long decValue = strtol(charArray, NULL, 16);
  lcd.clear();
  lcd.print(decValue);

  lcd.setCursor(2,1);
  lcd.print(getTime());
  lcd.setCursor(15,0);
  File sd = SD.open("data.txt", FILE_WRITE);
  if (sd) {
    String log_data = getTime();
    log_data += " --> ";
    log_data += decValue;
    sd.println(log_data);
    sd.close();
    lcd.write(232);
  } else {
    lcd.print("X");
  }
  delay(1000);
}