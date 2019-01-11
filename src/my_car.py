
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QDialog, QPushButton, QGridLayout, QSlider, QLabel, QVBoxLayout, QWidget

# from car_control import CarControl
from car_control_mock import CarControl

MAC = "88:3F:4A:D9:16:A8"
INIT_SPEED = 0
INIT_DD_POS = 90


class MyCarWindow(QDialog):
    def __init__(self, carControl):
        super(QDialog, self).__init__()

        self._carControl = carControl

        layout = QGridLayout()

        forwardButton = QPushButton('Forward')
        forwardButton.clicked.connect(lambda: self._carControl.forward())
        layout.addWidget(forwardButton, 0, 1)

        backButton = QPushButton('Back')
        backButton.clicked.connect(lambda: self._carControl.backward())
        layout.addWidget(backButton, 2, 1)

        leftButton = QPushButton('Left')
        leftButton.clicked.connect(lambda: self._carControl.left())
        layout.addWidget(leftButton, 1, 0)

        rightButton = QPushButton('Right')
        rightButton.clicked.connect(lambda: self._carControl.right())
        layout.addWidget(rightButton, 1, 2)

        stopButton = QPushButton('Stop')
        stopButton.clicked.connect(lambda: self._carControl.stop())
        layout.addWidget(stopButton, 1, 1)

        layout.addWidget(self._createSpeedSlider(), 3, 0)
        layout.addWidget(self._createDDPosSlider(), 3, 1)


        self.setWindowTitle('My Car')
        self.setLayout(layout)

    def _createSpeedSlider(self):
        self._speedLabel = QLabel(str(INIT_SPEED))

        speedSlider = QSlider(Qt.Vertical)
        speedSlider.setFocusPolicy(Qt.StrongFocus)
        speedSlider.setTickPosition(QSlider.TicksBothSides)
        speedSlider.setTickInterval(20)
        speedSlider.setSingleStep(1)
        speedSlider.setMinimum(0)
        speedSlider.setMaximum(255)
        speedSlider.valueChanged.connect(lambda: self._onSpeedChanged(speedSlider))
        speedSlider.setValue(INIT_SPEED)

        self._carControl.setSpeed(INIT_SPEED)

        layout = QVBoxLayout()
        layout.addWidget(self._speedLabel)
        layout.addWidget(speedSlider)
        widget = QWidget()
        widget.setLayout(layout)
        return widget

    def _onSpeedChanged(self, speedSlider):
        val = speedSlider.value()
        self._carControl.setSpeed(val)
        self._speedLabel.setText(str(val))

    def _createDDPosSlider(self):
        self._ddPosLabel = QLabel(str(INIT_DD_POS))

        ddPosSlider = QSlider(Qt.Horizontal)
        ddPosSlider.setFocusPolicy(Qt.StrongFocus)
        ddPosSlider.setTickPosition(QSlider.TicksBothSides)
        ddPosSlider.setTickInterval(5)
        ddPosSlider.setSingleStep(5)
        ddPosSlider.setMinimum(45)
        ddPosSlider.setMaximum(135)
        ddPosSlider.valueChanged.connect(lambda: self._onDDPosChanged(ddPosSlider))
        ddPosSlider.setValue(INIT_DD_POS)

        self._carControl.setDistanceDetectionPos(INIT_DD_POS)

        layout = QVBoxLayout()
        layout.addWidget(self._ddPosLabel)
        layout.addWidget(ddPosSlider)
        widget = QWidget()
        widget.setLayout(layout)
        return widget

    def _onDDPosChanged(self, ddPosSlider):
        val = 180 - ddPosSlider.value()
        self._carControl.setDistanceDetectionPos(val)
        self._ddPosLabel.setText(str(val))


app = QApplication([])
window = MyCarWindow(CarControl(MAC))
window.show()
app.exec_()
