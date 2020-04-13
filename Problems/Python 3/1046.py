class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-stone for stone in stones]
        
        heapq.heapify(stones)
        
        while len(stones) > 1:
            smash = heapq.heappop(stones) - heapq.heappop(stones)
            
            if smash != 0:
                heapq.heappush(stones, smash)
                
        return -stones[0] if stones else 0
