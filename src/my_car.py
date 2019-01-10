
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QSlider

# from car_control import CarControl
from car_control_mock import CarControl

MAC = "88:3F:4A:D9:16:A8"
INIT_SPEED = 0

carControl = CarControl(MAC)

app = QApplication([])

layout = QVBoxLayout()

forwardButton = QPushButton('Forward')
forwardButton.clicked.connect(lambda: carControl.forward())
layout.addWidget(forwardButton)

backButton = QPushButton('Back')
backButton.clicked.connect(lambda: carControl.backward())
layout.addWidget(backButton)

leftButton = QPushButton('Left')
leftButton.clicked.connect(lambda: carControl.left())
layout.addWidget(leftButton)

rightButton = QPushButton('Right')
rightButton.clicked.connect(lambda: carControl.right())
layout.addWidget(rightButton)

stopButton = QPushButton('Stop')
stopButton.clicked.connect(lambda: carControl.stop())
layout.addWidget(stopButton)

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
layout.addWidget(speedSlider)

window = QWidget()
window.setLayout(layout)
window.show()

app.exec_()
