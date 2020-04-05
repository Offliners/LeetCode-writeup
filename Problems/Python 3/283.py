class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        count = 0
        
        for num in nums:
            if num != 0:
                nums[count] = num
                count += 1
                
        nums[count:] = [0] * (len(nums) - count)
