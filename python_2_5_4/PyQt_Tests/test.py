from PyQt4.QtGui import *
from PyQt4.QtCore import * 

import sys

class MainWindow(QMainWindow):
    def __init__(self, parent = None):
        QMainWindow.__init__(self, parent)
        button = QPushButton(self)
        button.setText('Click Me')
        self.connect(button, SIGNAL('clicked()'), self.showMessage)
        
    def showMessage(self):
        QMessageBox.warning(self, 'Title', 'Content')
    
app = QApplication(sys.argv)

main = MainWindow()
main.show()

app.exec_()