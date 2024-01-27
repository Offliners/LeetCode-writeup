/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **ans = (char**)malloc(2 * n * sizeof(char*));
    
    int data = 1;
    int count = 0;
    for(int i = 0; i < targetSize; ++i)
    {
        while(data < target[i])
        {
            ans[count++] = "Push";
            ans[count++] = "Pop";
            ++data;
        }

        ans[count++] = "Push";
        ++data;
    }

    *returnSize = count;
    return ans;
}