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
