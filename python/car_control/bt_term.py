
from time import sleep
import signal
import sys
import ble_serial

MAC = "88:3F:4A:D9:16:A8"

if __name__ == "__main__":
    bleSerial = ble_serial.BLESerial(MAC, ble_serial.PrintDelegate())

    def signalHandler(sig, frame):
        print()
        bleSerial.disconnect()
        sys.exit(0)

    signal.signal(signal.SIGINT, signalHandler)

    while True:
        line = input(">")
        bleSerial.write(bytes(line + "\n", "utf-8"))
