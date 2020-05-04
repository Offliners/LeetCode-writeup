class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tempMax = float('-inf')
        maxNum = 0
        
        for num in nums:
            if maxNum > 0:
                maxNum += num
            else:
                maxNum = num
            
            tempMax = max(tempMax, maxNum)
        
        return tempMax
