# Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

#### Example
```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

### Python 3
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        tempMax = float('-inf')
        maxNum = 0
        
        for num in nums:
            if maxNum > 0:
                maxNum += num
            else:
                maxNum = num
            
            tempMax = max(tempMax, maxNum)
        
        return tempMax
```
[code](Python%203/53.py)

#### Result : 
```
Runtime: 68 ms, faster than 57.20% of Python3 online submissions for Maximum Subarray.
Memory Usage: 14.4 MB, less than 5.69% of Python3 online submissions for Maximum Subarray.
```

### C
```C
int compare(int num1, int num2)
{
    if(num1 > num2)
        return num1;
    else
        return num2;
}

int maxSubArray(int* nums, int numsSize){
    int tempMax = nums[0];
    int max = nums[0];
        
    for(int i = 1 ; i < numsSize ; i++){
        tempMax = compare(nums[i], tempMax + nums[i]);
        max = compare(tempMax, max);
    }
        
    return max;
}
```
[code](C/53.c)

#### Result
```
Runtime: 4 ms, faster than 96.83% of C online submissions for Maximum Subarray.
Memory Usage: 6 MB, less than 100.00% of C online submissions for Maximum Subarray.
```
