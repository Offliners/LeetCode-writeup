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
