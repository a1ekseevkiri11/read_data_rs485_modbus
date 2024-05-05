#include <iarduino_Modbus.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h>
#include <microDS3231.h>


MicroDS3231 rtc(0x68);
LiquidCrystal_I2C lcd(0x27,20,4);

ModbusClient modbus(Serial, 3);

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
  
  //
  lcd.init();
  lcd.backlight();
  
  if (!rtc.begin()){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("clokc not found!");
    delay(1500);
  }
  rtc.setTime(COMPILE_TIME);  
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  if (!SD.begin(4)) {
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
  int32_t data = modbus.holdingRegisterRead(11, 4);  // Читаем из модуля с адресом 9, значение регистра "Holding Register" с адресом 0.
  lcd.clear();
  lcd.setCursor(0,0);
  if (data >= 0) {
    lcd.print(data);
  }
  else {
    lcd.print("error");
  }
  lcd.setCursor(0,1);
  String time = rtc.getTimeString();
  lcd.print(time);
  lcd.setCursor(15,0);
  File sd = SD.open("data.txt", FILE_WRITE);
  if (sd && data >= 0) {
    //String log_data = getTime();
    String log_data = time;
    log_data += " --> ";
    log_data += data;
    log_data += " mm";
    sd.println(log_data);
    sd.close();
    lcd.write(232);
  } else {
    lcd.print("X");
  }
  delay(1000);
}
