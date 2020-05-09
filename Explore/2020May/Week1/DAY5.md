# Day 5 - First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

#### Example 
```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

### C
```C
int firstUniqChar(char * s){
    int sLen = strlen(s);
    int count['z' - 'a' + 1] = {0};
    
    for(int i = 0; i < sLen; i++)
        count[s[i] - 'a']++;
    
    for(int i = 0; i < sLen; i++)
        if(count[s[i] - 'a'] == 1)
            return i;
    
    return -1;
}
```
[code](C/first-unique-character-in-a-string.c)

#### Result
```
Runtime: 8 ms, faster than 88.75% of C online submissions for First Unique Character in a String.
Memory Usage: 6.8 MB, less than 100.00% of C online submissions for First Unique Character in a String.
```

### Python
```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = [0] * 26
        
        for i in s:
            count[ord(i) - ord('a')] += 1
            
        for i, c in enumerate(s):
            if count[ord(c) - ord('a')] == 1:
                return i;
            
        return -1
```
[code](Python/first-unique-character-in-a-string.py)

#### Result
```
Runtime: 196 ms, faster than 17.65% of Python3 online submissions for First Unique Character in a String.
Memory Usage: 14 MB, less than 6.52% of Python3 online submissions for First Unique Character in a String.
```
