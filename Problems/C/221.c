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
