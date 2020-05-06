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
        mask = num
        i = 1
        
        while i <= 16:
            mask |= mask>>i
            i *= 2
        
        return num ^ mask
```
[code](Python%203/476.py)

#### Result
```
Runtime: 32 ms, faster than 35.53% of Python3 online submissions for Number Complement.
Memory Usage: 13.8 MB, less than 10.00% of Python3 online submissions for Number Complement.
```

### C
```C
int findComplement(int num){
    int mask = num;
    
    for(int i = 1; i <= 16; i *= 2)
        mask |= mask>>i;
    
    return num ^ mask;
}
```
[code](C/476.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Number Complement.
Memory Usage: 5.2 MB, less than 100.00% of C online submissions for Number Complement.
```
