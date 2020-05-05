# Ransom Note
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

#### Example
```
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
```

### C
```C

```
[code](C/ransomNote.c)

#### Result
```

```

### Python
```python
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazineCount = Counter(magazine)
        ransomNoteCount = Counter(ransomNote)
        
        for c in ransomNoteCount:
            if c not in ransomNoteCount or magazineCount[c] < ransomNoteCount[c]:
                return False
            
        return True
```
[code](Python/ransomNote.py)

#### Result
```
Runtime: 48 ms, faster than 75.50% of Python3 online submissions for Ransom Note.
Memory Usage: 14 MB, less than 25.00% of Python3 online submissions for Ransom Note.
```
