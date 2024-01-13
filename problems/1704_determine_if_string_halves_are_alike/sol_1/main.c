bool is_vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else
        return false;
}

bool halvesAreAlike(char* s) {
    int a_vowel_count = 0;
    int b_vowel_count = 0;
    int s_len = strlen(s);
    for(int i = 0; i < s_len / 2; ++i)
    {
        if(is_vowel(s[i]))
            ++a_vowel_count;
        
        if(is_vowel(s[i + s_len / 2]))
            ++b_vowel_count;
    }

    return a_vowel_count == b_vowel_count;
}