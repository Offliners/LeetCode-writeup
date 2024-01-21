char* convertToTitle(int columnNumber) {
    int temp = columnNumber;
    int ans_len = 0;
    while(temp > 0)
    {
        --temp;
        temp /= 26;
        ++ans_len;
    }

    char *ans = (char*)malloc((ans_len + 1) * sizeof(char));

    int index = ans_len - 1;
    while(columnNumber > 0)
    {
        --columnNumber;
        ans[index] = ((columnNumber % 26) + 'A');
        --index;
        columnNumber /= 26;
    }
    ans[ans_len] = '\0';

    return ans;
}