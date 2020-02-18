class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numSet = {}
        for i, num in enumerate(nums):
            if target - num in numSet:
                return [numSet[target - num], i]
            numSet[num] = i
            
        return []
