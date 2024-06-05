int appendCharacters(char* s, char* t) {
    int s_index = 0;
    int t_index = 0;

    int s_len = strlen(s);
    int t_len = strlen(t);
    while(s_index < s_len && t_index < t_len)
    {
        if(s[s_index] == t[t_index])
            ++t_index;
        
        ++s_index;
    }

    return t_len - t_index;
}