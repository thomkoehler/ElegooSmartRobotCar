
import bluepy.btle as btle
from time import sleep
 
peripheral = btle.Peripheral("88:3F:4A:D9:16:A8")

for uuid, service in peripheral.discoverServices().items():
  print(f'{uuid} {service}')

service = peripheral.getServiceByUUID("0000ffe0-0000-1000-8000-00805f9b34fb")
characteristic = service.getCharacteristics()[0]


characteristic.write(bytes("2", "utf-8"))
sleep(1.0)
characteristic.write(bytes("8", "utf-8"))
sleep(1.0)
characteristic.write(bytes("5", "utf-8"))

for i in range(100):
  print(characteristic.read())

peripheral.disconnect()