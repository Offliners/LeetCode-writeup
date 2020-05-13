# Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

#### Example 1
```
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
```

#### Example 2
```
Input: [3,3,7,7,10,11,11]
Output: 10
```

### Python 3
```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums)
        
        while right - left != 1:
            mid = left + (right - left) // 2
            
            if (nums[mid - 1] < nums[mid]) and (nums[mid] < nums[mid + 1]):
                return nums[mid]
            
            if (mid % 2 == 1) and (nums[mid - 1] < nums[mid]) and (nums[mid] == nums[mid + 1]):
                right = mid
            elif (mid % 2 == 0) and (nums[mid - 1] == nums[mid]) and (nums[mid] < nums[mid + 1]):
                right = mid - 1
            elif (mid % 2 == 0) and (nums[mid - 1] < nums[mid]) and (nums[mid] == nums[mid + 1]):
                left = mid + 2
            elif (mid % 2 == 1) and (nums[mid - 1] == nums[mid]) and (nums[mid] < nums[mid + 1]):
                left = mid + 1
    
        return nums[left]
```
[code](Python%203/540.py)

#### Result
```
Runtime: 68 ms, faster than 88.51% of Python3 online submissions for Single Element in a Sorted Array.
Memory Usage: 16.1 MB, less than 7.69% of Python3 online submissions for Single Element in a Sorted Array.
```

### C
```C

```
[code](C/540.c)

#### Result
```

```
