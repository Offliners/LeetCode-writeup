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
[code](code/1.py)

#### Result : 
```
Runtime: 48 ms, faster than 79.16% of Python3 online submissions for Two Sum.
Memory Usage: 14.2 MB, less than 56.04% of Python3 online submissions for Two Sum.
```
