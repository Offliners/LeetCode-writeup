class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        trustNum = [0] * (N + 1)
        
        for trustee, trusted in trust:
            trustNum[trusted] += 1
            trustNum[trustee] -= 1
            
        for people in range(1, N + 1):
            if trustNum[people] == N - 1:
                return people
        
        return -1
