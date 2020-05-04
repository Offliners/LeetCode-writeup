class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        
        self.data = []
        self.mins = []

    def push(self, x: int) -> None:
        self.data.append(x)
        
        if not self.mins or self.mins[-1] >= x:
            self.mins.append(x)

    def pop(self) -> None:
        if self.data.pop() == self.mins[-1]:
            self.mins.pop()

    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        return self.mins[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
