/*
MOSI - pin 11
MISO - pin 12
CLK - pin 13
CS - pin 10
*/

#include <SPI.h>
#include <SD.h>

File myFile;

//файлы можно именовать до 8 символов + 3 символа расширения!!!

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");


  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening test.txt");
  }

  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
}

void loop() {
}