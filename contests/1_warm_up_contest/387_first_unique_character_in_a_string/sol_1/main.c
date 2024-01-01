int firstUniqChar(char* s) {
    int *dict = (int*)malloc(26 * sizeof(int));
    for(int i = 0; i < 26; ++i)
        dict[i] = 0;

    for(int i = 0; s[i] != '\0'; ++i)
        dict[s[i] - 'a']++;
    
    for(int i = 0; s[i] != '\0'; ++i)
    {
        if(dict[s[i] - 'a'] == 1)
        {
            free(dict);
            return i;
        }
    }
            
    free(dict);
    return -1;
}