class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0;
        
        rows, cols = len(grid), len(grid[0])
        numIsland = 0
        
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == '1':
                    self.floodFill(grid, row, col)
                    numIsland += 1
                    
        return numIsland
    
    def floodFill(self, grid, row, col):
        if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]) or grid[row][col] != '1':
            return 
        
        grid[row][col] = '0'
        
        self.floodFill(grid, row + 1, col)
        self.floodFill(grid, row - 1, col)
        self.floodFill(grid, row, col + 1)
        self.floodFill(grid, row, col - 1)
