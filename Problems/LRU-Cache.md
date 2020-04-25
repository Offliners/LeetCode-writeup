# LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: `get` and `put`.

`get(key)` - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

`put(key, value)` - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

#### Example
```
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

### Python 3
```python
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
```
[code](Python%203/146.py)

#### Result
```
Runtime: 212 ms, faster than 62.28% of Python3 online submissions for LRU Cache.
Memory Usage: 23.4 MB, less than 6.06% of Python3 online submissions for LRU Cache.
```

### C
```C
typedef struct {
    struct Entry* entries;
    int capacity;
    int currentPrior;
} LRUCache;

struct Entry
{
    int key;
    int value;
    int prior;
};


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = malloc(sizeof(LRUCache));
    
    obj->entries = calloc(capacity, sizeof(struct Entry));
    obj->capacity = capacity;
    obj->currentPrior = 0;
    
    for(int i = 0; i < capacity; i++)
        obj->entries[i].key = -1;
    
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    for(int i = 0; i < obj->capacity; i++)
    {
        if(obj->entries[i].key == key)
        {
            obj->currentPrior++;
            obj->entries[i].prior = obj->currentPrior;
            return obj->entries[i].value;
        }
    }
    
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    for(int i = 0; i < obj->capacity; i++)
    {
        if(obj->entries[i].key == key)
        {
            obj->entries[i].value = value;
            obj->currentPrior++;
            obj->entries[i].prior = obj->currentPrior;
            return;
        }
    }
    
    for(int i = 0; i < obj->capacity; i++)
    {
        if(obj->entries[i].key == -1)
        {
            obj->entries[i].key = key;
            obj->entries[i].value = value;
            obj->currentPrior++;
            obj->entries[i].prior = obj->currentPrior;
            return;
        }
    }
    
    int min = 0;
    
    for(int i = 1; i < obj->capacity; i++)
        if(obj->entries[i].prior < obj->entries[min].prior)
            min = i;
    
    obj->entries[min].key = key;
    obj->entries[min].value = value;
    obj->currentPrior++;
    obj->entries[min].prior = obj->currentPrior;
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->entries);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
```
[code](C/146.c)

#### Result
```
Runtime: 176 ms, faster than 5.67% of C online submissions for LRU Cache.
Memory Usage: 23.7 MB, less than 100.00% of C online submissions for LRU Cache.
```
