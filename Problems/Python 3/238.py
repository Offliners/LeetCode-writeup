class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1]
        
        for i in range(1, len(nums)):
            result.append(nums[i - 1] * result[-1])
            
        right = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= right
            right *= nums[i]
            
        return result
