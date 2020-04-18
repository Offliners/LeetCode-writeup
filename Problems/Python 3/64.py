class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        
        minPath = [float('inf') for _ in range(col + 1)]
        minPath[1] = 0
        
        for i in range(1, row + 1):
            newPath = [float('inf') for _ in range(col + 1)]
            for j in range(1, col + 1):
                newPath[j] = grid[i - 1][j - 1] + min(minPath[j], newPath[j - 1])
                
            minPath = newPath
            
        return minPath[-1]
