# Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

#### Example 
```
Input:  [1,2,3,4]
Output: [24,12,8,6]
```

### Python 3
```python

```
[code](Python%203/238.py)

#### Result
```

```

### C
```C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *result = malloc(sizeof(int) * numsSize);
    
    result[numsSize - 1] = 1;
    for(int i = numsSize - 2; i >= 0; i--)
        result[i] = result[i + 1] * nums[i + 1];
    
    int left = 1;
    for(int i = 0; i < numsSize; i++)
    {
        result[i] = left * result[i];
        left *= nums[i];
    }
    
    return result;
}
```
[code](C/238.c)

#### Result
```
Runtime: 36 ms, faster than 100.00% of C online submissions for Product of Array Except Self.
Memory Usage: 13.7 MB, less than 100.00% of C online submissions for Product of Array Except Self.
```
