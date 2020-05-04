int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int **cache = malloc((len1 + 1) * sizeof(int*));
    
    for(int i = 0; i <= len1; i++)
        cache[i] = calloc((len2 + 1), sizeof(int));
    
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            if(text1[i] == text2[j])
                cache[i + 1][j + 1] = cache[i][j] + 1;
            else if(cache[i][j + 1] >= cache[i + 1][j])
                cache[i + 1][j + 1] = cache[i][j + 1];
            else
                cache[i + 1][j + 1] = cache[i + 1][j];
        }
    }
    
    int result = cache[len1][len2];
    
    for(int i = 0; i <= len1; i++)
        free(cache[i]);
    
    free(cache);
    
    return result;
}
