/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize) {
    int cur = 1;
    *returnSize = n;

    int *ans = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
    {
        ans[i] = cur;
        if(cur * 10 <= n)
            cur *= 10;
        else if(cur % 10 != 9 && cur + 1 <= n)
            ++cur;
        else
        {
            if(cur == n)
                cur /= 10;
            
            while(cur % 10 == 9)
                cur /= 10;

            ++cur;
        }
    }

    return ans;
}