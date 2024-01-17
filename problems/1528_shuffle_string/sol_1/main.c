char* restoreString(char* s, int* indices, int indicesSize) {
    char *ans = (char*)malloc((indicesSize + 1) * sizeof(char));
    strncpy(ans, s, indicesSize);
    for(int i = 0; i < indicesSize; ++i)
        ans[indices[i]] = s[i];
    
    ans[indicesSize] = '\0';
    return ans;
}