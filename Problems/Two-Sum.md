# Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

#### Example
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]
```

### Python 3
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numSet = {}
        for i, num in enumerate(nums):
            if target - num in numSet:
                return [numSet[target - num], i]
            numSet[num] = i
            
        return []
```
[code](Python%203/1.py)

#### Result : 
```
Runtime: 48 ms, faster than 79.16% of Python3 online submissions for Two Sum.
Memory Usage: 14.2 MB, less than 56.04% of Python3 online submissions for Two Sum.
```

### C
```C
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
```
[code](C/1.c)
#### Result
```
Runtime: 4 ms, faster than 99.68% of C online submissions for Two Sum.
Memory Usage: 7.8 MB, less than 7.81% of C online submissions for Two Sum.
```
