#!/usr/bin/python
import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

def mainfunc():
	#Create application instance.	
	app = QApplication(sys.argv)
   
	# Create a dialog instance.
	dlg = QDialog()

	# Create message text widget.
	msgCtrl = QLabel(dlg)
	msgCtrl.setText("Do you want to play a Game ?")
	msgCtrl.setGeometry(50,20,200,30)

	# Create a first push button.
	b1 = QPushButton(dlg)
   	b1.setText("Yes")
   	b1.move(50,50)
   	b1.clicked.connect(b1_clicked)

	# Create a second push button.
	b2 = QPushButton(dlg)
   	b2.setText("No")
   	b2.move(50,80)
   	QObject.connect(b2,SIGNAL("clicked()"),b2_clicked)

	# Set dialog attribute
   	dlg.setGeometry(100,100,350,250)
   	dlg.setWindowTitle("PyQt")
   	dlg.show()
   
	# bind application exit with system exit. 
	sys.exit(app.exec_())

def b1_clicked():
   print "You pressed Yes button."

def b2_clicked():
   print "You pressed No button."

if __name__ == '__main__':
   mainfunc()
