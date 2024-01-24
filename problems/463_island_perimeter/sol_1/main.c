int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = *gridColSize;

    int count = 0;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if(grid[i][j] == 1)
            {
                if(i == 0)
                    ++count;
                else if(grid[i - 1][j] == 0)
                    ++count;

                if(i == row - 1)
                    ++count;
                else if(grid[i + 1][j] == 0)
                    ++count;

                if(j == 0)
                    ++count;
                else if(grid[i][j - 1] == 0)
                    ++count;

                if(j == col - 1)
                    ++count;
                else if(grid[i][j + 1] == 0)
                    ++count;
            }
        }
    }

    return count;
}