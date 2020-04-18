# Day 18 - Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

#### Example 
```
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```

### C
```C
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int col = gridColSize[0];
    int **cache = malloc(sizeof(int*) * 2);
    
    for(int i = 0; i < 2; i++)
        cache[i] = calloc(col, sizeof(int));
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 && j == 0)
            {
                cache[i % 2][j] = grid[0][0];
                continue;
            }
            
            int min = INT_MAX;
            
            if(i - 1 >= 0)
            {
                int upMin = cache[(i - 1) % 2][j];
                
                if(upMin < min)
                    min = upMin;
            }
            
            if(j - 1 >= 0)
            {
                int leftMin = cache[i % 2][j - 1];
                
                if(leftMin < min)
                    min = leftMin;
            }
            
            cache[i % 2][j] = min + grid[i][j];
        }
    }
    
    int result = cache[(row - 1) % 2][col - 1];
    
    for(int i = 0; i < 2; i++)
        free(cache[i]);
    
    free(cache);
    
    return result;
}
```
[code](C/minimum-path-sum.c)

#### Result
```
Runtime: 12 ms, faster than 66.67% of C online submissions for Minimum Path Sum.
Memory Usage: 7.2 MB, less than 100.00% of C online submissions for Minimum Path Sum.
```

### Python
```python
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
```
[code](Python/minimum-path-sum.py)

#### Result
```
Runtime: 104 ms, faster than 52.44% of Python3 online submissions for Minimum Path Sum.
Memory Usage: 14.2 MB, less than 78.95% of Python3 online submissions for Minimum Path Sum.
```
