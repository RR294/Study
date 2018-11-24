#!/usr/bin/python
import sys

class parent:
	parentAttr = 100
	def __init__(self):
		print "Calling parent class constructor"
	def parentMethod(self):
		print "Calling parent method."
	def setAttr(self, attr):
		parent.parentAttr = attr
	def getAttr(self):
		print "parent attribute :", parent.parentAttr

class Child(parent):	#define child class
	def __init__(self):
		print "Calling child class constructor."
	def childMethod(self):
		print "Calling child method"

ch = Child()	# Create a instance of child class.
ch.childMethod()

class Employee:
	empCount = 0	# shared variable between all instances.

	def __init__(self, name, salary):
		self._name=name
		self._salary=salary
		Employee.empCount += 1

	def displayCount(self):
		print "Total Emp %d" % Employee.empCount

emp = Employee('Ra',1000)
emp.displayCount()
