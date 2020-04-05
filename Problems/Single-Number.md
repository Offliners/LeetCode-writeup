# Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

#### Example 1
```
Input: [2,2,1]
Output: 1
```

#### Example 2
```
Input: [4,1,2,1,2]
Output: 4
```

### Python 3
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n = 0
        for i in nums:
            n ^= i
            
        return n
```
[code](Python%203/136.py)

#### Result : 
```
Runtime: 84 ms, faster than 83.14% of Python3 online submissions for Single Number.
Memory Usage: 16.5 MB, less than 6.56% of Python3 online submissions for Single Number.
```

### C
```C
int singleNumber(int* nums, int numsSize){
    int n = nums[0];
    
    for(int i = 1; i < numsSize; i++)
        n ^= nums[i];
    return n;
}
```
[code](C/136.c)

#### Result
```
Runtime: 8 ms, faster than 94.76% of C online submissions for Single Number.
Memory Usage: 6.6 MB, less than 100.00% of C online submissions for Single Number.
```
