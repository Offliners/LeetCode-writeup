# Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

#### Example 1
```
Input: [3,2,3]
Output: 3
```

#### Example 2
```
Input: [2,2,1,1,1,2,2]
Output: 2
```

### C
```C

```
[code](C/majorityElement.c)

#### Result
```

```

### Python
```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count, candidate = 0, None
        
        for i, num in enumerate(nums):
            if count == 0:
                candidate = num
            
            if candidate == num:
                count += 1
            else:
                count -= 1
        
        return candidate
```
[code](Python/majorityElement.py)

#### Result
```
Runtime: 176 ms, faster than 58.80% of Python3 online submissions for Majority Element.
Memory Usage: 15.2 MB, less than 7.14% of Python3 online submissions for Majority Element.
```
