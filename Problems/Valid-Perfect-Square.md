# Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.

#### Example 1
```
Input: 16
Output: true
```

#### Example 2
```
Input: 14
Output: false
```

### Python 3
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 1, num
        
        while left <= right:
            mid = (left + right) // 2
            square = mid * mid
            
            if square == num:
                return True
            
            if square < num:
                left = mid + 1
            else:
                right = mid - 1
        
        return False
```
[code](Python%203/367.py)

#### Result
```
Runtime: 32 ms, faster than 47.05% of Python3 online submissions for Valid Perfect Square.
Memory Usage: 13.8 MB, less than 10.00% of Python3 online submissions for Valid Perfect Square.
```

### C
```C

```
[code](C/367.c)

#### Result
```

```
