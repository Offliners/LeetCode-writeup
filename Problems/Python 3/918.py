class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        if all(num <= 0 for num in A):
            return max(A)
        
        overallMax, overallMin = float('-inf'), float('inf')
        localMax, localMin = 0, 0
        
        for num in A:
            localMax = max(localMax, 0) + num
            localMin = min(localMin, 0) + num
            overallMax = max(overallMax, localMax)
            overallMin = min(overallMin, localMin)
        
        return max(overallMax, sum(A) - overallMin)
