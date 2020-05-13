/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int color = image[sr][sc];
    *returnSize = imageSize;
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * (*returnSize));
    
    for(int i = 0;i < *returnSize; i++)
        returnColumnSizes[0][i] = *imageColSize;
    
    const int ROWS = imageSize;
    const int COLS = imageColSize[0];

    if(color == newColor)
        return image;
    
    depthFirstSearch(image, ROWS, COLS, sr, sc, color, newColor);
    
    return image;
}

void depthFirstSearch(int **image, int ROWS, int COLS, int i, int j, int color, int newColor)
{   
    if((i < 0)||(j < 0)||(i >= ROWS)||(j >= COLS))
        return;
    
    if(image[i][j] != color)
        return;

    image[i][j] = newColor;
    depthFirstSearch(image, ROWS, COLS, i + 1, j, color, newColor);
    depthFirstSearch(image, ROWS, COLS, i - 1, j, color, newColor);
    depthFirstSearch(image, ROWS, COLS, i, j + 1, color, newColor);
    depthFirstSearch(image, ROWS, COLS, i, j - 1, color, newColor);
}
