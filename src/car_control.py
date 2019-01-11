
from ble_serial import BLESerial, QueueDelegate
from time import sleep


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
        self._inQueue.clear()
        self._bleSerial.write(bytes("gd\n", "utf-8"))
        for _ in range(3):
            item = self._inQueue.read()
                if item is not None:
                    return item

                sleep(0.1)
                self._bleSerial.write(bytes("\n"))

        return None
