class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        total = 0
        hashTable = defaultdict(int)
        sum = 0
        
        for num in nums:
            sum += num
            
            if sum == k:
                total += 1
            
            if sum - k in hashTable:
                total += hashTable[sum - k]
                
            hashTable[sum] += 1
            
        return total
