/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;
    int *gray_code = (int*)malloc(*returnSize * sizeof(int));

    for(int i = 0; i < *returnSize; ++i)
        gray_code[i] = i ^ (i >> 1);

    return gray_code;
}