# Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 

You may assume all four edges of the grid are all surrounded by water.

#### Example 1
```
Input:
11110
11010
11000
00000

Output: 1
```

#### Example 2
```
Input:
11000
11000
00100
00011

Output: 3
```

### Python 3
```python
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
```
[code](Python%203/200.py)

#### Result
```
Runtime: 148 ms, faster than 59.15% of Python3 online submissions for Number of Islands.
Memory Usage: 14.9 MB, less than 9.40% of Python3 online submissions for Number of Islands.
```

### C
```C
const char WATER = '0';
const char LAND = '1';
const char NEW = 'X';
const char USED = 'O';

void floodFill(char **grid, int ROWS, int COLS, int i, int j)
{
    if((i < 0)||(j < 0)||(i >= ROWS)||(j >= COLS)||(grid[i][j] != LAND))
        return;
    
    grid[i][j] = NEW;
    floodFill(grid, ROWS, COLS, i + 1, j);
    floodFill(grid, ROWS, COLS, i - 1, j);
    floodFill(grid, ROWS, COLS, i, j + 1);
    floodFill(grid, ROWS, COLS, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize == 0)
        return 0;
    
    const int ROWS = gridSize;
    const int COLS = gridColSize[0];
    int numIsland = 0;
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(grid[i][j] == LAND)
            {
                floodFill(grid, ROWS, COLS, i, j);
                
                for(int x = 0; x < ROWS; x++)
                    for(int y = 0; y < COLS; y++)
                        if(grid[x][y] == NEW)
                            grid[x][y] == USED;
                
                numIsland++;
            }
        }
    }
    
    return numIsland;
}
```
[code](C/200.c)

#### Result
```
Runtime: 24 ms, faster than 6.37% of C online submissions for Number of Islands.
Memory Usage: 7.5 MB, less than 100.00% of C online submissions for Number of Islands.
```
