# ПО для работы с терминалом

перейдя по ссылке скачать [Terminal](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/blob/main/Terminal-v.1.9b.7z)

сайт [расчета CRC](https://www.lammertbies.nl/comm/info/crc-calculation)

## Инструкция по работе с Terminal

1) в окне "COM Port" выберите порт к которому подключен CH340

![1 терминал](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/9c8232c1-9748-4ecc-8e7c-fac03ad7a813)

2) выставите эти настройки 

![3 терминал](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/79a045af-86f6-458f-8378-ccfd22704b5e)

3) нажмите кнопку "Connect" 

![2 терминал](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/359db673-1872-492c-8411-ed4be9f4d4fe)

4) введите команду

![4 терминал](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/188a7fc6-f6e9-4581-a14f-224fab940bd6)

5) нажмите кнопку отправить 

![5 терминал](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/e056afd4-97b2-443a-9346-0c0c36ad4c5f)

6) в окне должен прийти ответ от датчика

![6 терминал](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/0e9b04f9-12a0-4a44-afcb-934725c19f8b)

# ПО для ардуино
перейдя по ссылке скачать [Arduino IDE](https://www.arduino.cc/en/software)

скачать архив с сайта [iarduino_Modbus](https://iarduino.ru/file/591.html), и установить библиотеку в Arduino IDE.

## Инструкция по установке библиотек из архива
1)  в Arduino IDE в верхнем меню выберите пункт "Sketch", в выпадающем меню выберите "Include Library", из списка выберите пункт "ADD .ZIP Library..."

![1 уст из архив](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/4796003d-414c-4c22-ad24-ba3506471857)

2) в появившемся окне выберите архив с нужной библиотекой

![image](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/c5cc174e-25e2-4a05-b400-dd06caecb7f8)

3) после этого в терминале вы должны увидеть надпись "Library installed"

![3 лаб из арх](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/3dd45ef1-0d60-4f17-bf46-33b31a22968e)


скачать из менеджера библиотек (Arduino IDE) LiquidCrystal I2C
  
## Инструкция по скачиванию библиотек из менеджера библиотек: 
1) в Arduino IDE в верхнем меню выберите пункт "Tools", в выпадающем меню выберите "Manage Libraries..."

![1 мен биб](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/80312919-de2a-406f-b35a-a2a3966ce1c4)

2) в строку поиска введите название нужной библиотеки

![image](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/ab53c722-76be-4f51-8876-adaed3cb1927)

3) нажмите кнопку "INSTALL"

![3 мен биб](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/5d13bb2f-deda-4c39-a372-e190c89c5da5)


# ПО для python
перейдя по ссылке скачать с официального сайта язык [python](https://www.python.org/)

установите библиотеку PyModbus ```pip install pymodbus``` с помощью утилиты Pip

## Инструкция по установке библиотек с помощью утилиты Pip

1) Откройте командную строку. Для этого в меню «Пуск» введите cmd и нажмите Enter.

![image](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/1b70782a-f579-4f3d-bb3d-1cc3dcc38a50)

2) Введите команду ```pip install package-name``` (package-name — имя пакета, который вы хотите установить)

![image](https://github.com/a1ekseevkiri11/read_data_rs485_modbus/assets/130764832/987032bb-4dda-4d59-af9d-2f43160ae9e2)

