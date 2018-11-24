#!/usr/bin/python
import sys
from PyQt4 import QtGui

def window():
	# Create application instance.
	app = QtGui.QApplication(sys.argv)

	#Create window instance.
	wnd = QtGui.QWidget()

	bar = QtGui.QLabel(wnd)
	bar.setText("Hello PyQt World!")

	wnd.setGeometry(200,200,400,200)

	bar.move(100,100)

	wnd.setWindowTitle("PyQt Sample")

	# Show window.
	wnd.show()

	sys.exit(app.exec_())

if __name__ == '__main__':
	window()

