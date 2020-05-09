int firstUniqChar(char * s){
    int sLen = strlen(s);
    int count['z' - 'a' + 1] = {0};
    
    for(int i = 0; i < sLen; i++)
        count[s[i] - 'a']++;
    
    for(int i = 0; i < sLen; i++)
        if(count[s[i] - 'a'] == 1)
            return i;
    
    return -1;
}
