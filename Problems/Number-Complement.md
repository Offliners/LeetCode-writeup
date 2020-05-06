# Number Complement
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

#### Example 1
```
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

#### Example 2
```
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

### Python 3
```python
class Solution:
    def findComplement(self, num: int) -> int:
        i = 1
        
        while i <= num:
            i <<= 1
            
        return (i - 1) ^ num
```
[code](Python%203/476.py)

#### Result
```
Runtime: 28 ms, faster than 69.30% of Python3 online submissions for Number Complement.
Memory Usage: 13.8 MB, less than 10.00% of Python3 online submissions for Number Complement.
```

### C
```C

```
[code](C/476.c)

#### Result
```

```
