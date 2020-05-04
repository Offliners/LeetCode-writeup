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
int rangeBitwiseAnd(int m, int n){
    int count = 0;
    
    while(m != n)
    {
        m = m >> 1;
        n = n >> 1;
        count++;
    }
    
    return m << count;
}
```
[code](C/bitwise-and-of-numbers-range.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Bitwise AND of Numbers Range.
Memory Usage: 5.4 MB, less than 100.00% of C online submissions for Bitwise AND of Numbers Range.
```

### Python
```python
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        count = 0
        
        while m != n:
            m = m >> 1
            n = n >> 1
            count += 1
            
        return m << count
```
[code](Python/bitwise-and-of-numbers-range.py)

#### Result
```
Runtime: 52 ms, faster than 82.23% of Python3 online submissions for Bitwise AND of Numbers Range.
Memory Usage: 13.7 MB, less than 100.00% of Python3 online submissions for Bitwise AND of Numbers Range.
```
