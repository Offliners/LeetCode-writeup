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
