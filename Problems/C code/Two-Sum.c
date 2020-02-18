/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 50000

int hashTable(int key)
{
    int keyValue = key % MAXSIZE;
    
    return keyValue < 0 ? keyValue + MAXSIZE : keyValue;
}

void insert(int *keyArr, int *valueArr, int key, int value)
{
    int index = hashTable(key);
    
    while(valueArr[index])
        index = (index + 1) % MAXSIZE;
    
    keyArr[index] = key;
    valueArr[index] = value;
}

int search(int *keyArr, int *valueArr, int key)
{
    int index = hashTable(key);
    
    while(valueArr[index])
    {
        if(keyArr[index] == key)
            return valueArr[index];
        
        index = (index + 1) % MAXSIZE;
    }
    
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int keyArr[MAXSIZE];
    int valueArr[MAXSIZE] = {0};
    int element;
    int index;
    int *indice = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    for(int i = 0; i <numsSize;i++)
    {
        element = target - nums[i];
        index = search(keyArr,valueArr,element);
        if(index)
        {
            indice[0] = index - 1;
            indice[1] = i;
            return indice;
        }
        insert(keyArr,valueArr,nums[i], i + 1);
    }
    
    return NULL;
}
