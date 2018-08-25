class MyStack:
	def __init__(self):
		self.stack = []

	def push(self, dataval):
		# Use list append method to add element.
		if dataval not in self.stack:
			self.stack.append(dataval)
			return True
		else:
			return False

	#Use peek to look at the top of the stack
	def peek(self):
		return self.stack[0]

	# USe list pop method to remove element
	def pop(self):
		if len(self.stack) <= 0:
			retirn ("Stack is empty.")
		else:
			return self.stack.pop()

	def display(self):
		print self.stack


AStack = MyStack()
AStack.push("Mon")
AStack.push("Tue")
print(AStack.peek())
AStack.push("Wed")
AStack.push("Thu")
print(AStack.pop())
AStack.display()
