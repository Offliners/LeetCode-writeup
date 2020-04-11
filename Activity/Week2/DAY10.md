# Day 10 - Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.

#### Example
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

### C
```C
typedef struct {
    int* data;
    int* mins;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->data = NULL;
    stack->mins = NULL;
    stack->size = 0;
    
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    obj->data = realloc(obj->data, sizeof(int) * (obj->size + 1));
    obj->mins = realloc(obj->mins, sizeof(int) * (obj->size + 1));
    obj->data[obj->size] = x;
    
    if((obj->size == 0)||(obj->mins[obj->size - 1] > x))
        obj->mins[obj->size] = x;
    else
        obj->mins[obj->size] = obj->mins[obj->size - 1];
    
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->size - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
[code](C/minStack.c)

#### Result
```
Runtime: 48 ms, faster than 36.07% of C online submissions for Min Stack.
Memory Usage: 294.6 MB, less than 100.00% of C online submissions for Min Stack.
```

### Python
```python
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
```
[code](Python/minStack.py)

#### Result
```
Runtime: 56 ms, faster than 92.08% of Python3 online submissions for Min Stack.
Memory Usage: 17.7 MB, less than 5.36% of Python3 online submissions for Min Stack.
```
