
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QGridLayout, QSlider

# from car_control import CarControl
from car_control_mock import CarControl

MAC = "88:3F:4A:D9:16:A8"
INIT_SPEED = 0

carControl = CarControl(MAC)

app = QApplication([])

layout = QGridLayout()

forwardButton = QPushButton('Forward')
forwardButton.clicked.connect(lambda: carControl.forward())
layout.addWidget(forwardButton, 0, 1)

backButton = QPushButton('Back')
backButton.clicked.connect(lambda: carControl.backward())
layout.addWidget(backButton, 2, 1)

leftButton = QPushButton('Left')
leftButton.clicked.connect(lambda: carControl.left())
layout.addWidget(leftButton, 1, 0)

rightButton = QPushButton('Right')
rightButton.clicked.connect(lambda: carControl.right())
layout.addWidget(rightButton, 1, 2)

stopButton = QPushButton('Stop')
stopButton.clicked.connect(lambda: carControl.stop())
layout.addWidget(stopButton, 1, 1)

speedSlider = QSlider(Qt.Vertical)
speedSlider.setFocusPolicy(Qt.StrongFocus)
speedSlider.setTickPosition(QSlider.TicksBothSides)
speedSlider.setTickInterval(20)
speedSlider.setSingleStep(1)
speedSlider.setMinimum(0)
speedSlider.setMaximum(255)
speedSlider.valueChanged.connect(lambda: carControl.setSpeed(speedSlider.value()))
speedSlider.setValue(INIT_SPEED)
carControl.setSpeed(INIT_SPEED)
layout.addWidget(speedSlider, 3, 0)

window = QWidget()
window.setLayout(layout)
window.show()

app.exec_()
