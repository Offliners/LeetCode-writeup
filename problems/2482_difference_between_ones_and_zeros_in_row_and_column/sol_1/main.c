/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int row = gridSize;
    int col = *gridColSize;

    *returnSize = row;
    *returnColumnSizes = (int*)malloc(row * sizeof(int));
    for(int i = 0; i < row; ++i)
        (*returnColumnSizes)[i] = col;

    int **diff = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; ++i)
        diff[i] = (int*)malloc(col * sizeof(int));
    
    for(int i = 0; i < row; ++i)
    {
        int onesRow = 0;
        int zerosRow = 0;
        for(int j = 0; j < col; ++j)
        {
            if(grid[i][j] == 0)
                ++zerosRow;
            else
                ++onesRow;
        }

        for(int j = 0; j < col; ++j)
            diff[i][j] = onesRow - zerosRow;
    }

    for(int j = 0; j < col; ++j)
    {
        int onesCol = 0;
        int zerosCol = 0;
        for(int i = 0; i < row; ++i)
        {
            if(grid[i][j] == 0)
                ++zerosCol;
            else
                ++onesCol;
        }

        for(int i = 0; i < row; ++i)
            diff[i][j] += onesCol - zerosCol;
    }

    return diff;
}