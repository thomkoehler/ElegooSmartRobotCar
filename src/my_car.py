
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout
from car_control import CarControl

MAC = "88:3F:4A:D9:16:A8"

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

window = QWidget()
window.setLayout(layout)
window.show()

app.exec_()
