# Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

#### Example 1
```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

#### Example 2
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

#### Example 3
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

### Python 3
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = {}
        start = 0
        longest = 0
        
        for i, char in enumerate(s):
            if char in last and last[char] >= start:
                start = last[char] + 1
            else:
                longest = max(longest, i - start + 1)
                
            last[char] = i
        
        return longest
```
[code](code/3.py)

#### Result : 
```
Runtime: 48 ms, faster than 93.02% of Python3 online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 12.9 MB, less than 100.00% of Python3 online submissions for Longest Substring Without Repeating Characters.
```
