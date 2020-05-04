class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = 0
        
        for i, num in enumerate(nums):
            if i > target:
                return False
            print(i, num, target)
            target = max(target, i + num)
            
        return True
