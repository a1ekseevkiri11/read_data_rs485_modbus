#include <iarduino_Modbus.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27,16,2);

SoftwareSerial rs485(9,8);
ModbusClient modbus(rs485, 7);


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

void setup() {
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  rs485.begin(9600); 
  while(!rs485){
    ;
  }
  if(!SD.begin(10)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("sd not found!");
    delay(1500);
  }
  modbus.begin();
  modbus.setDelay( 5 );
  modbus.setTimeout( 20 );
  
  modbus.setTypeMB(MODBUS_RTU);
}

void loop() {
  //holdingRegisterRead(slave, address)
  int32_t data = modbus.holdingRegisterRead(11, 4); 
  lcd.clear();
  lcd.setCursor(0,0);
  if (data >= 0) {
    lcd.print(data);
  }
  else {
    lcd.print("error");
  }
  lcd.setCursor(2,1);
  lcd.print(getTime());
  lcd.setCursor(15,0);
  File sd = SD.open("data.txt", FILE_WRITE);
  if (sd && data >= 0) {
    String log_data = getTime();
    log_data += " --> ";
    log_data += data;
    sd.println(log_data);
    sd.close();
    lcd.write(232);
  } else {
    lcd.print("X");
  }
  delay(1000);
}
