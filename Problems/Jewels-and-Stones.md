# Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

#### Example 1
```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

#### Example 2
```
Input: J = "z", S = "ZZ"
Output: 0
```

### Python 3
```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum(1 for s  in S if s in set(J))
```
[code](Python%203/771.py)

#### Result
```
Runtime: 32 ms, faster than 53.75% of Python3 online submissions for Jewels and Stones.
Memory Usage: 13.9 MB, less than 5.39% of Python3 online submissions for Jewels and Stones.
```

### C
```C

```
[code](C/771.c)

#### Result
```

```
