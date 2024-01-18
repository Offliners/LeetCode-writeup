/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for(int i = 0; i < numRows; ++i)
        (*returnColumnSizes)[i] = i + 1;

    int **ans = (int**)malloc(*returnSize * sizeof(int*));
    for(int i = 0; i < numRows; ++i)
        ans[i] = (int*)malloc((i + 1) * sizeof(int));

    ans[0][0] = 1;
    if(numRows == 1) 
        return ans;

    ans[1][0] = 1;
    ans[1][1] = 1;
    if(numRows == 2)
        return ans;

    for(int i = 2; i < numRows; ++i)
    {
        ans[i][0] = 1;

        int j;
        for(j = 1; j < i; ++j)
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        
        ans[i][j] = 1;
    }

    return ans;
}