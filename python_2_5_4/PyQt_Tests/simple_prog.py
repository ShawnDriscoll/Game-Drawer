# simple prog.py

import sys
from PyQt4 import QtGui

app = QtGui.QApplication(sys.argv)

widget = QtGui.QWidget()
widget.resize(250, 150)
widget.setWindowTitle('Simple Prog!')
widget.show()

sys.exit(app.exec_())
