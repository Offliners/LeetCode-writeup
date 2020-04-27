# Maximal Square
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

### Python 3
```python

```
[code](Python%203/221.py)

#### Result
```

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
[code](C/221.c)

#### Result
```
Runtime: 12 ms, faster than 100.00% of C online submissions for Maximal Square.
Memory Usage: 7.8 MB, less than 100.00% of C online submissions for Maximal Square.
```
