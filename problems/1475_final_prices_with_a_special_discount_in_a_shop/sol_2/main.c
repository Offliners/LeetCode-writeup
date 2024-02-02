/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int *stack = (int*)malloc(pricesSize * sizeof(int));
    int top = 0;
    for(int i = 0; i < pricesSize; ++i)
    {
        while(top != 0 && prices[stack[top - 1]] >= prices[i])
        {
            prices[stack[top - 1]] -= prices[i];
            --top;
        }

        stack[top++] = i;
    }

    return prices;
}