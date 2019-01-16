
class CarControl:
    def __init__(self, mac):
        pass

    def forward(self):
        print("fw\n")

    def backward(self):
        print("bw\n")

    def left(self):
        print("ccw\n")

    def right(self):
        print("cw\n")

    def stop(self):
        print("st\n")

    def setSpeed(self, speed):
        print(f"ss {speed}\n")

    def setDistanceDetectionPos(self, pos):
        print(f"sdp {pos}\n\n")

    def getDistance(self):
        print("gd\n")
        return 0
