class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        tempMax = float('-inf')
        maxNum = 0
        
        for num in nums:
            if maxNum > 0:
                maxNum += num
            else:
                maxNum = num
            
            tempMax = max(tempMax, maxNum)
        
        return tempMax
