import time
import sys
from find_ch340 import getModbusClient

client = getModbusClient()

while True:
    # для других датчиков изменять address, count, slave
    response = client.read_holding_registers(address=4, count=1, slave=11)
    if not response.isError():
        data = str(response.registers[0])
    else:
        data = response
        
    sys.stdout.write("\r\033[K")  # Очистка строки
    sys.stdout.write("\rДанные: {}".format(data))
    sys.stdout.flush()  # Принудительный сброс буфера вывода
    time.sleep(0.5)
    

client.close()