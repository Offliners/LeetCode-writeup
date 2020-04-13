class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        maxLength = 0
        Diff = 0
        Diffs = {0: -1}
        
        for i, num in enumerate(nums):
            if num == 0:
                Diff += 1
            else:
                Diff -= 1
                
            if Diff in Diffs:
                maxLength = max(maxLength, i - Diffs[Diff])
            else:
                Diffs[Diff] = i
                
        return maxLength
