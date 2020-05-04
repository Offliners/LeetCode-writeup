# Day 15 - Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

#### Example 
```
Input:  [1,2,3,4]
Output: [24,12,8,6]
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
[code](C/product-of-array-except-self.c)

#### Result
```
Runtime: 36 ms, faster than 100.00% of C online submissions for Product of Array Except Self.
Memory Usage: 13.7 MB, less than 100.00% of C online submissions for Product of Array Except Self.
```

### Python
```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1]
        
        for i in range(1, len(nums)):
            result.append(nums[i - 1] * result[-1])
            
        right = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= right
            right *= nums[i]
            
        return result
```
[code](Python/product-of-array-except-self.py)

#### Result
```
Runtime: 124 ms, faster than 70.60% of Python3 online submissions for Product of Array Except Self.
Memory Usage: 20.2 MB, less than 92.00% of Python3 online submissions for Product of Array Except Self.
```
