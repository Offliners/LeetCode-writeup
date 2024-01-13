/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        (*returnColumnSizes)[i] = n;

    int** ans = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; ++i)
        ans[i] = (int*)malloc(n * sizeof(int));

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int count = 1;
    int index = 0;
    while(left <= right && top <= bottom)
    {
        for(int i = left; i <= right; ++i)
        {
            ans[top][i] = count;
            ++count;
        }
        ++top;

        for(int j = top; j <= bottom; ++j)
        {
            ans[j][right] = count;
            ++count;
        }
        --right;

        if(top <= bottom)
        {
            for(int i = right; i >= left; --i)
            {
                ans[bottom][i] = count;
                ++count;
            }
            --bottom;
        }

        if(left <= right)
        {
            for(int j = bottom; j >= top; --j)
            {
                ans[j][left] = count;
                ++count;
            }
            ++left;
        }
    }

    return ans;
}