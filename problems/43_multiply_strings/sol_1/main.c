char* multiply(char* num1, char* num2) {
    if(!strcmp(num1, "0") || !strcmp(num2, "0"))
        return "0";

    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    int *ans = (int*)malloc((len_num1 + len_num2) * sizeof(int));
    for(int i = 0; i < len_num1 + len_num2; ++i)
        ans[i] = 0;
    
    for(int i = len_num1 - 1; i >= 0; --i)
    {
        for(int j = len_num2 - 1; j >= 0; --j)
        {
            ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            ans[i + j] += ans[i + j + 1] / 10;
            ans[i + j + 1] %= 10;
        }
    }

    int non_zero_index = 0;
    while(ans[non_zero_index] == 0)
        ++non_zero_index;

    char *ans_str = (char*)malloc((len_num1 + len_num2 + 1 - non_zero_index) * sizeof(char));

    int i;
    for(i = non_zero_index; i < len_num1 + len_num2; ++i)
        ans_str[i - non_zero_index] = ans[i] + '0';

    free(ans);
    ans_str[i - non_zero_index] = '\0';
    return ans_str;
}