#!/usr/bin/python
import sys
from datetime import datetime

def PrintOrders(ordbk):
	for ord in ordbk:
		#print "Order price : %d Time : %d" % ord.price, ord.time
		print("Order price {0}, time {1}.".format(ord.price, ord.time))

class Order:
	def __init__(self, prc, tm):
		self.price = prc
		self.time = tm	# In Microseconds.	

class OrderBook:
	# class constructor.
	def __init__(self):
		self._buybook = []
		self._sellbook = []

	# Function to insert new buy Order
	def InsertBuyOrder(self, ordPrc):
		
		# If list is empty, push it and return.
		if len(self._buybook) == 0:
			self._buybook.append(ordPrc)
			return

		# Find the insert position for the new order.
		index=0;
		for oldOrdPrc in self._buybook:
			if ordPrc.price < oldOrdPrc.price:
				index += 1
				continue
			elif ordPrc.price == oldOrdPrc.price:
				if ordPrc.time > oldOrdPrc.time:
					index +=1
		
		# Insert new order.
		self._buybook.insert(index, ordPrc)

	# Function to insert new sell Order
	def InsertSellOrder(self, newOrd):

		# If list is empty, push it and return.
		if len(self._sellbook) == 0:
			self._sellbook.append(newOrd)
			return

		# Find the insert position for the new order.
		ind=0;
		for oldOrdPrc in self._sellbook:
			if newOrd.price > oldOrdPrc.price:
				ind += 1
				continue
			elif newOrd.price == oldOrdPrc.price:
				if newOrd.time > oldOrdPrc.time:
					ind +=1

		# Insert new order.
		self._sellbook.insert(ind, newOrd)
 

	# Print buy order book
	def PrintBuyOrders(self):
		print "\nBuy orders :"
		PrintOrders(self._buybook)

	# Print sell order book
	def PrintSellOrders(self):
		print "\nSell orders :"
		PrintOrders(self._sellbook)



#print "Current time in Microseconds : %d "% dt.microsecond
 
ordBk = OrderBook()
dt = datetime.now()
ordBk.InsertBuyOrder(Order(24, dt.microsecond))

dt = datetime.now()
ordBk.InsertBuyOrder(Order(15, dt.microsecond))

dt = datetime.now()
ordBk.InsertBuyOrder(Order(15, dt.microsecond))

dt = datetime.now()
ordBk.InsertSellOrder(Order(18, dt.microsecond))

dt = datetime.now()
ordBk.InsertSellOrder(Order(7, dt.microsecond))

dt = datetime.now()
ordBk.InsertSellOrder(Order(18, dt.microsecond))

ordBk.PrintBuyOrders()
ordBk.PrintSellOrders()
