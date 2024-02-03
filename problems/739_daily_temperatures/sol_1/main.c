/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;

    int *stack = (int*)malloc(*returnSize * sizeof(int));
    int top = 0;
    for(int i = 0; i < temperaturesSize; ++i)
    {
        while(top != 0 && temperatures[stack[top - 1]] < temperatures[i])
        {
            temperatures[stack[top - 1]] = i - stack[top - 1];
            --top;
        }

        stack[top++] = i;
    }

    while(top != 0)
    {
        temperatures[stack[top - 1]] = 0;
        --top;
    }

    free(stack);
    return temperatures;
}