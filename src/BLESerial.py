
import bluepy.btle as btle
import threading
from collections import deque


class PrintDelegate(btle.DefaultDelegate):
    def __init__(self):
        btle.DefaultDelegate.__init__(self)

    def handleNotification(self, cHandle, data):
        print(data)


class QueueDelegate(btle.DefaultDelegate):
    def __init__(self):
        self._queue = deque()
        self._lock = threading.Lock()
        btle.DefaultDelegate.__init__(self)

    def handleNotification(self, cHandle, data):
        with self._lock:
            self._queue.appendleft(data)

    def read(self):
        with self._lock:
            if len(self._queue) > 0:
                return self._queue.pop()
            else:
                return None

    def __len__(self):
        with self._lock:
            return len(self._queue)

    def clear(self):
        with self._lock:
            return self._queue.clear()


class BLESerial:
    def __init__(self, mac, delegate=None):
        self._peripheral = btle.Peripheral(mac)

        if delegate is not None:
            self._peripheral.setDelegate(delegate)

        service = self._peripheral.getServiceByUUID(
            "0000ffe0-0000-1000-8000-00805f9b34fb")

        self._characteristic = service.getCharacteristics()[0]

    def write(self, val):
        self._characteristic.write(val)

    def disconnect(self):
        self._peripheral.disconnect()
