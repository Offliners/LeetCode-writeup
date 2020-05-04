# Day 4 - Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

#### Example
```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### C
```C
void moveZeroes(int* nums, int numsSize){
    int count = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[count] = nums[i];
            count++;
        }
    }
    
    for(;count < numsSize; count++)
        nums[count] = 0;   
}
```
[code](C/moveZeroes.c)

#### Result
```
Runtime: 12 ms, faster than 89.09% of C online submissions for Move Zeroes.
Memory Usage: 7.5 MB, less than 100.00% of C online submissions for Move Zeroes.
```

### Python 3
```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        count = 0
        
        for num in nums:
            if num != 0:
                nums[count] = num
                count += 1
                
        nums[count:] = [0] * (len(nums) - count)
```
[code](Python/moveZeroes.py)

#### Result
```
Runtime: 36 ms, faster than 71.29% of Python online submissions for Move Zeroes.
Memory Usage: 13.8 MB, less than 5.06% of Python online submissions for Move Zeroes.
```
