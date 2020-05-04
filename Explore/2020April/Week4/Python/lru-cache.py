class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class DLL:
    def __init__(self):
        self.head = Node(None, None)
        self.tail = Node(None, None)
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def insert(self, node):
        node.prev, self.tail.prev.next = self.tail.prev, node
        node.next, self.tail.prev = self.tail, node
        
    def remove(self):
        node = self.head.next
        node.next.prev = self.head
        self.head.next = self.head.next.next
        key = node.key
        del node
        
        return key
    
    def update(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.insert(node)
        
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.queue = DLL()
        self.map = {}

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        
        node = self.map[key]
        self.queue.update(node)
        
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            node = self.map[key]
            node.value = value
            self.queue.update(node)
            return
        
        node = Node(key, value)
        self.map[key] = node
        self.queue.insert(node)
        
        if self.capacity == 0:
            del self.map[self.queue.remove()]
        else:
            self.capacity -= 1


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
