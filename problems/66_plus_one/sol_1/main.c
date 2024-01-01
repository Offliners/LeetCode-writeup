/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ans = (int*)malloc((digitsSize + 1) * sizeof(int));
    *returnSize = digitsSize + 1;

    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; --i)
    {
        ans[i + 1] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
    }

    if(carry)
    {
        ans[0] = carry;
        return ans;
    }
        
    *returnSize = digitsSize;
    int *new_ans = (int*)malloc(digitsSize * sizeof(int));
    for(int i = 0; i < digitsSize; ++i)
        new_ans[i] = ans[i + 1];
    
    free(ans);
    return new_ans;
}