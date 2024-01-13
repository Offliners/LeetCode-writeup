/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * (*matrixColSize);
    int *ans = (int*)malloc(*returnSize * sizeof(int));

    int top = 0;
    int bottom = matrixSize - 1;
    int left = 0;
    int right = *matrixColSize - 1;

    int index = 0;
    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; ++i)
        {
            ans[index] = matrix[top][i];
            ++index;
        }
        ++top;

        for(int j = top; j <= bottom; ++j)
        {
            ans[index] = matrix[j][right];
            ++index;
        }
        --right;

        if(top <= bottom)
        {
            for(int i = right; i >= left; --i)
            {
                ans[index] = matrix[bottom][i];
                ++index;
            }
            --bottom;
        }

        if(left <= right)
        {
            for(int j = bottom; j >= top; --j)
            {
                ans[index] = matrix[j][left];
                ++index;
            }
            ++left;
        }
            
    }

    return ans;
}