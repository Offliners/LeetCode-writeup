/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;

    int *ans = (int*)malloc(*returnSize * sizeof(int));
    int i;
    for(i = 0; i < pricesSize - 1; ++i)
    {
        int cur_price = prices[i];
        int j;
        for(j = i + 1; j < pricesSize; ++j)
        {
            if(prices[j] <= cur_price)
            {
                ans[i] = cur_price - prices[j];
                break;
            }
        }

        if(j == pricesSize)
            ans[i] = cur_price;
    }

    ans[i] = prices[i];

    return ans;
}