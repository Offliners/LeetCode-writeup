/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int **common = (int**)malloc(wordsSize * sizeof(int*));
    for(int i = 0; i < wordsSize; ++i)
        common[i] = (int*)malloc(26 * sizeof(int));
    
    for(int i = 0; i < wordsSize; ++i)
        for(int j = 0; j < 26; ++j)
            common[i][j] = 0;
    
    for(int i = 0; i < wordsSize; ++i)
        for(int j = 0; words[i][j] != '\0'; ++j)
            common[i][words[i][j] - 'a'] += 1;
    
    char **ans = (char**)malloc(101 * sizeof(char*));
    int index = 0;
    for(int k = 0; k < 101; ++k)
        ans[k] = (char*)malloc(2 * sizeof(char));

    for(int j = 0; j < 26; ++j)
    {
        int min_num = common[0][j];
        for(int i = 1; i < wordsSize; ++i)
            if(common[i][j] < min_num)
                min_num = common[i][j];
        
        for(int k = min_num; k > 0; --k)
        {
            ans[index][0] = 'a' + j;
            ans[index][1] = '\0';
            ++index;
        }
    }

    for(int i = 0; i < wordsSize; ++i)
        free(common[i]);
    free(common);
    
    *returnSize = index;
    return ans;
}