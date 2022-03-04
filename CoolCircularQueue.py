"""
A circular queue made in my way in one day
"""

class CoolCircularQueue:
	MAX_ELEMENTS = 100
	def __init__(self):
		self.__vals=[None]*CircularQueue.MAX_ELEMENTS
		self.__front=-1
		self.__rear=-1
		self.__outing = False
	def enqueue(self,v):
		if (not self.isFull()):
			if self.isEmpty():
				self.__front=0
				self.__rear=0
				self.__outing=False
			else:
				if self.__rear==CircularQueue.MAX_ELEMENTS-1:
					self.__outing=True
					self.__rear=-1
				self.__rear+=1
			self.__vals[self.__rear]=v
	def dequeue(self):
		if (not self.isEmpty()):
			if (self.__outing and self.__front==CircularQueue.MAX_ELEMENTS):
				self.__outing=False
				self.__front=-1
				self.__rear=-1
				self.__vals[self.__front]=None
			else:
				self.__vals[self.__front]=None
				self.__front+=1
	def getFront(self):return self.__vals[self.__front]
	def getRear(self):return self.__vals[self.__rear]
	def hasOne(self):return (self.__front!=-1 and self.__front==self.__rear)
	def isEmpty(self):
		return ((self.__front==-1 and self.__front==self.__rear) or (not self.__outing and self.__front==self.__rear+1 ))
	def isFull(self):
		return((self.__front==self.__rear+1 and self.__outing) or (self.__front==0 and self.__rear==len(self.__vals)-1))
	def __str__(self):
		if (self.__front==self.__rear):return str(self.__vals[self.__front])
		if (self.__outing):
			return str(self.__vals[self.__front:]+self.__vals[:self.__rear+1])
		else:return str(self.__vals[self.__front:self.__rear+1])

def main():
	c = CircularQueue()
	c.enqueue(1)
	c.enqueue(2)
	c.enqueue(3)
	c.enqueue(4)
	c.enqueue(5)
	print("Front ",c.getFront())
	print("Rear ",c.getRear())
	print(c)

if __name__=="__main__":main()
