char findTheDifference(char* s, char* t) {
    int ans = 0;
    int i;
    for(i = 0; s[i] != '\0'; ++i)
        ans ^= s[i] ^ t[i];

    ans ^= t[i];

    return ans;
}