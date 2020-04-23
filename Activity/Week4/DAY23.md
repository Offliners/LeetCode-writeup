# Day 23 - Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

#### Example 1
```
Input: [5,7]
Output: 4
```

#### Example 2
```
Input: [0,1]
Output: 0
```

### C
```C

```
[code](C/bitwise-and-of-numbers-range.c)

#### Result
```

```

### Python
```python
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if m == 0:
            return 0
        
        result = 0
        bit = int(log(n, 2))
        
        while bit >= 0 and ((m &  (1 << bit)) == (n & (1 << bit))):
            if (m & (1 << bit)):
                result += 2**bit
                
            bit -= 1
        
        return result
```
[code](Python/bitwise-and-of-numbers-range.py)

#### Result
```
Runtime: 56 ms, faster than 66.92% of Python3 online submissions for Bitwise AND of Numbers Range.
Memory Usage: 14.1 MB, less than 100.00% of Python3 online submissions for Bitwise AND of Numbers Range.
```
