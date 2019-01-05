
from ble_serial import BLESerial


class CarControl:
    def __init__(self, mac):
        self._bleSerial = BLESerial(mac)

    def forward(self):
        self._bleSerial.write(bytes("f\n", "utf-8"))

    def backward(self):
        self._bleSerial.write(bytes("b\n", "utf-8"))

    def left(self):
        self._bleSerial.write(bytes("l\n", "utf-8"))

    def right(self):
        self._bleSerial.write(bytes("r\n", "utf-8"))

    def stop(self):
        self._bleSerial.write(bytes("s\n", "utf-8"))
