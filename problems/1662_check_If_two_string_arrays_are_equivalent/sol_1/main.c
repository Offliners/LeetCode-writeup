bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    char *word1_str = (char*)malloc(1001 * sizeof(char));
    int index = 0;
    for(int i = 0; i < word1Size; ++i)
    {
        for(int j = 0; j < strlen(word1[i]); ++j)
            word1_str[index + j] = word1[i][j];
        
        index += strlen(word1[i]);
    }
    word1_str[index] = '\0';
    
    index = 0;
    char *word2_str = (char*)malloc(1001 * sizeof(char));
    for(int i = 0; i < word2Size; ++i)
    {
        for(int j = 0; j < strlen(word2[i]); ++j)
            word2_str[index + j] = word2[i][j];
        
        index += strlen(word2[i]);
    }
    word2_str[index] = '\0';

    bool ans = !strcmp(word1_str, word2_str);
    free(word1_str);
    free(word2_str);
    
    return ans;
}