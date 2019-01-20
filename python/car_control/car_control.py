
from time import sleep
from .ble_serial import QueueDelegate, BLESerial


class CarControl:
    def __init__(self, mac):
        self._inQueue = QueueDelegate()
        self._bleSerial = BLESerial(mac, self._inQueue)

    def forward(self):
        self._bleSerial.write(bytes("fw\n", "utf-8"))

    def backward(self):
        self._bleSerial.write(bytes("bw\n", "utf-8"))

    def left(self):
        self._bleSerial.write(bytes("ccw\n", "utf-8"))

    def right(self):
        self._bleSerial.write(bytes("cw\n", "utf-8"))

    def stop(self):
        self._bleSerial.write(bytes("st\n", "utf-8"))

    def setSpeed(self, speed):
        self._bleSerial.write(bytes(f"ss {speed}\n", "utf-8"))

    def setDistanceDetectionPos(self, pos):
        self._bleSerial.write(bytes(f"sdp {pos}\n", "utf-8"))

    def getDistance(self):
        return self._getIntValue('gd', b'd:')

    def getSpeed(self):
        return self._getIntValue('gs', b'sp:')

    def _getIntValue(self, command, getToken):
        self._inQueue.clear()
        self._bleSerial.write(bytes(f"{command}\n", "utf-8"))
        for _ in range(4):
            item = self._inQueue.read()
            if item is not None:
                tokens = item.split()
                if len(tokens) > 1 and tokens[0] == getToken:
                    return int(tokens[1])

            sleep(0.2)
            self._bleSerial.write(bytes("\n", "utf-8"))

        return None
