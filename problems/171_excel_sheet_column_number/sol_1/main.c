int titleToNumber(char* columnTitle) {
    int ans = 0;
    for(int i = 0; i < strlen(columnTitle); ++i)
        ans =  ans * 26 + (columnTitle[i] - 'A' + 1);

    return ans;
}