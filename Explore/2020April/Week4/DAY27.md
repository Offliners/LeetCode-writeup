# Day 27 - Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

#### Example
```
Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
```

### C
```C
int min2(int a, int b)
{
    if(a < b)
        return a;
    
    return b;
}

int min3(int a, int b, int c)
{
    return min2(min2(a, b), c);
}

int max2(int a, int b)
{
    if(a < b)
        return b;
    
    return a;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0)
        return 0;
    
    int **cache = malloc(sizeof(int*) * (matrixSize + 1));
    
    for(int i = 0; i <= matrixSize; i++)
        cache[i] = calloc(matrixColSize[0] + 1, sizeof(int));
    
    int result = 0;
    
    for(int row = 0; row < matrixSize; row++)
    {
        for(int col = 0; col < matrixColSize[0]; col++)
        {
            if(matrix[row][col] == '1')
                cache[row + 1][col + 1] = min3(cache[row][col + 1], cache[row + 1][col], cache[row][col]) + 1;
            
            result = max2(result, cache[row + 1][col + 1]);
        }
    }
    
    for(int i = 0; i < matrixSize; i++)
        free(cache[i]);
    
    free(cache);
    
    return result * result;
}


```
[code](C/maximalSquare.c)

#### Result
```
Runtime: 12 ms, faster than 100.00% of C online submissions for Maximal Square.
Memory Usage: 7.8 MB, less than 100.00% of C online submissions for Maximal Square.
```

### Python
```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
            
        row, col = len(matrix), len(matrix[0])
        result = 0
        side = [0] * col
        
        for i in range(row):
            newSide = [int(matrix[i][0])] + [0 for _ in range(col - 1)]
            
            for j in range(1, col):
                if matrix[i][j] == '1':
                    newSide[j] = 1 + min(newSide[j - 1], side[j], side[j - 1])
                    
            result = max(result, max(newSide))
            side = newSide
            
        return result**2
```
[code](Python/maximalSquare.py)

#### Result
```
Runtime: 180 ms, faster than 98.54% of Python3 online submissions for Maximal Square.
Memory Usage: 14.7 MB, less than 9.09% of Python3 online submissions for Maximal Square.
```
