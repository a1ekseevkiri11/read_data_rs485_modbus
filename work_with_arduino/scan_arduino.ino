// ПРИМЕР ПОЛУЧЕНИЯ СПИСКА АДРЕСОВ ВСЕХ УСТРОЙСТВ НА ШИНЕ:                         //
                                                                                   //
#include <SoftwareSerial.h>                                                        //   Подключаем библиотеку для работы с программной шиной UART.
#include <iarduino_Modbus.h>                                                       //   Подключаем библиотеку для работы по протоколу Modbus.
#include <LiquidCrystal_I2C.h>                                                                                  //
SoftwareSerial     rs485(9,8);                                                     //   Создаём объект для работы с программной шиной UART-RS485 указывая выводы RX, TX.
ModbusClient       modbus(rs485, 7);                                               //   Создаём объект для работы по протоколу Modbus указывая объект программной шины UART-RS485 и вывод DE конвертера UART-RS485.
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){                                                                      //
     Serial.begin(9600); while(!Serial);                                           //   Инициируем передачу данных в монитор последовательного порта, указав его скорость.
     rs485.begin(9600); while(!rs485);                                             //   Инициируем работу с программной шиной UATR-RS485 указав её скорость.
     lcd.init();
     lcd.backlight();
     modbus.begin();                                                               //   Инициируем работу по протоколу Modbus.
     modbus.setTimeout(20);                                                        //   Указываем максимальное время ожидания ответа по протоколу Modbus.
     modbus.setDelay(5);                                                           //   Указываем минимальный интервал между отправляемыми сообщениями по протоколу Modbus.
     modbus.setTypeMB( MODBUS_RTU );                                               //   Указываем тип протокола Modbus: MODBUS_RTU (по умолчанию), или MODBUS_ASCII.
     Serial.println("Поиск устройств...");                                         //
//   Выполняем поиск всех устройств на шине (занимает несколько секунд):           //
     modbus.findID();                                                              //   Ищем адреса всех устройств на шине. Если указать идентификатор, то будут найдены адреса устройств iarduino указанной модели.
     if( modbus.available() >= 0 ){                                                     //   Вместо двух строк, можно так: if( modbus.findID() ){
     //  Устройства найдены:                                                       //
         Serial.print("Найдено ");                                                 //
         Serial.print( modbus.available() );                                       //
         Serial.print(" устройств с адресами: ");
         lcd.setCursor(0,0);
         lcd.print("Find: ");
         lcd.print(modbus.available());
     //  Выводим адреса устройств:                                                 //
         while( modbus.available() ){                                              //
             int address = modbus.read();
             Serial.print( address );                                        //
             Serial.print(", ");
             lcd.setCursor(0,1);
             lcd.print(address);
             lcd.print(";");
         }   Serial.println();                                                     //
     }                                                                             //
}                                                                                  //   Если адрес не указан socket.begin(), то он будет найден, но это займёт некоторое время.
                                                                                   //
void loop(){                                                                       //
}                                                                                  //