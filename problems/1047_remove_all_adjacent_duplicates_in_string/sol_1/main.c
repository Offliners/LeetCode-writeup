char* removeDuplicates(char* s) {
    int s_len = strlen(s);
    char *ans = (char*)malloc((s_len + 1) * sizeof(char));

    ans[0] = s[0];
    int i = 1;
    int top = 1;
    while(i < s_len)
    {
        if(top == 0 || s[i] != ans[top - 1])
        {
            ans[top] = s[i];
            ++top;
        }
        else
            --top;

        ++i;
    }

    ans[top] = '\0';
    return ans;
}