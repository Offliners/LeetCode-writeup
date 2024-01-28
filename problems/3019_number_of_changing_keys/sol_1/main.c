char to_lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    
    return c;
}

int countKeyChanges(char* s) {
    int change = 0;

    for(int i = 1; i < strlen(s); ++i)
        if(s[i] != s[i - 1] && to_lower(s[i]) != to_lower(s[i - 1]))
            ++change;
    
    return change;
}