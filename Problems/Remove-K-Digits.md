# Remove K Digits
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

#### Example 1
```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

#### Example 2
```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

#### Example 3
```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

### Python 3
```python
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        result = []
        
        for i in num:
            while k and result and result[-1] > i:
                result.pop()
                k -= 1
            
            result.append(i)
            
        while k:
            result.pop()
            k -= 1
        
        return ''.join(result).lstrip('0') or '0'
```
[code](Python%203/402.py)

#### Result
```
Runtime: 24 ms, faster than 99.43% of Python3 online submissions for Remove K Digits.
Memory Usage: 13.9 MB, less than 22.22% of Python3 online submissions for Remove K Digits.
```

### C
```C

```
[code](C/402.c)

#### Result
```

```
