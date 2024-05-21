from pymodbus.client import ModbusSerialClient as ModbusClient
import serial.tools.list_ports

# Функция поиска COM порта для CH340 адаптера
def findCh340Port():
    port_found = False
    ports = serial.tools.list_ports.comports()
    for port, desc, hwid in sorted(ports):
        if "CH340" in desc:
            port_found = True
            break
    return port if port_found else None


def getModbusClient():
    port = findCh340Port()
    if not port:
        print("CH340 адаптер не найден.")
        return None
    
    client = ModbusClient(
        method='rtu', 
        port=port, 
        baudrate=9600, 
        timeout=0.05,
        )

    if not client.connect():
        print("Не удалось открыть соединение.")
        return None
    
    return client