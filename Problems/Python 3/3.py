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
