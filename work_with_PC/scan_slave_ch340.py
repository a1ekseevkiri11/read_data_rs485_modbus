import time
import sys
from find_ch340 import getModbusClient



client = getModbusClient()

array_slave = []

for slave in range(0, 247):
    print(slave)
    response = client.read_holding_registers(address=16, count=1, slave=slave)
    if not response.isError():
        print("Найден: ",slave)
        array_slave.append(slave)

print("Найденные slave:")

for address_slave in array_slave:
    print(address_slave)


for slave in array_slave:
    print("slave:", slave)
    array_address = []
    for address in range(0, 256):
        response = client.read_holding_registers(address=address, count=1, slave=slave)
        if not response.isError():
            array_address.append(address)
            print(address, "|", response.registers[0])
    print("---------")


client.close()