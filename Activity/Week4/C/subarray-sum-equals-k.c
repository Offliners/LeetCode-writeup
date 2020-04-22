#define MAXSIZE 1000000

struct Entry
{
    int sum;
    int count;
};

int hashTable(int key)
{
    int keyValue = key % MAXSIZE;
    
    return keyValue < 0 ? keyValue + MAXSIZE : keyValue; 
}

void insert(struct Entry **counter, int key)
{
    int index = hashTable(key);
    
    while(counter[index] != NULL)
    {
        if(counter[index]->sum == key)
        {
            counter[index]->count++;
            return;
        }
        
        index = hashTable(index + 1);
    }
    
    struct Entry *entry = malloc(sizeof(struct Entry));
    
    entry->sum = key;
    entry->count = 1;
    counter[index] = entry;
}

int search(struct Entry **counter, int key)
{
    int index = hashTable(key);
    
    while(counter[index] != NULL)
    {
        if(counter[index]->sum == key)
            return counter[index]->count;
        
        index = hashTable(index + 1);
    }
    
    return 0;
}

int subarraySum(int* nums, int numsSize, int k){
    struct Entry **counter = calloc(MAXSIZE, sizeof(struct Entry*));
    int sum = 0;
    int total = 0;
    int target;
    
    for(int i = 0; i < numsSize; i++)
    {
        insert(counter, sum);
        sum += nums[i];
        target = sum - k;
        total += search(counter, target);
    }
    
    free(counter);
    
    return total;
}
