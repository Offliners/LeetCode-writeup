int abs(int n)
{
    return n >= 0 ? n : -n;
}

int scoreOfString(char* s) {
    int ans = 0;
    for(int i = 1; s[i] != '\0'; ++i)
        ans += abs(s[i] - s[i - 1]);
    
    return ans;
}