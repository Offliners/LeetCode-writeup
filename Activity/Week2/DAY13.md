# Day 13 - Contiguous Array
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

#### Example 1
```
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

#### Example 2
```
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

### C
```C
int findMaxLength(int* nums, int numsSize){
    int countDiff[numsSize + 1];
    int findMax[2 * numsSize + 1];
    int maxLength = 0;
    
    countDiff[0] = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
            countDiff[i + 1] = countDiff[i] + 1;
        else
            countDiff[i + 1] = countDiff[i] - 1;
    }
    
    for(int i = 0; i < 2 * numsSize + 1; i++)
        findMax[i] = -1;
    
    for(int i = 0; i < numsSize; i++)
        findMax[(countDiff[i + 1] + numsSize)] = i;
    
    for(int i = 0; i < numsSize; i++)
    {
        int target = countDiff[i];
        int length = findMax[target + numsSize] - i + 1;
        
        if(length > maxLength)
            maxLength = length;
    }
    
    return maxLength;
}
```
[code](C/contiguousArray.c)

#### Result
```
Runtime: 92 ms, faster than 37.50% of C online submissions for Contiguous Array.
Memory Usage: 9.7 MB, less than 100.00% of C online submissions for Contiguous Array.
```

### Python 
```python

```
[code](Python/contiguousArray.py)

#### Result
```

```
