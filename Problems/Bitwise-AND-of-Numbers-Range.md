# Bitwise AND of Numbers Range
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

### Python 3
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
[code](Python%203/201.py)

#### Result
```
Runtime: 52 ms, faster than 82.23% of Python3 online submissions for Bitwise AND of Numbers Range.
Memory Usage: 13.9 MB, less than 100.00% of Python3 online submissions for Bitwise AND of Numbers Range.
```

### C
```C

```
[code](C/201.c)

#### Result
```

```
