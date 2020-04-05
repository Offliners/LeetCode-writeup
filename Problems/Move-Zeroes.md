# Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

#### Example
```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
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
[code](Python%203/283.py)

#### Result : 
```
Runtime: 44 ms, faster than 90.64% of Python3 online submissions for Move Zeroes.
Memory Usage: 15.2 MB, less than 5.97% of Python3 online submissions for Move Zeroes.
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
[code](C/283.c)

#### Result
```
Runtime: 24 ms, faster than 18.43% of C online submissions for Move Zeroes.
Memory Usage: 7.4 MB, less than 100.00% of C online submissions for Move Zeroes.
```
