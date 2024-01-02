bool is_vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else
        return false;
}

char* reverseVowels(char* s) {
    int left = 0;
    int right = 0;
    for(int i = 0; s[i] != '\0'; ++i)
        ++right;

    while(left < right)
    {
        if(is_vowel(s[left]) && is_vowel(s[right]))
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            ++left;
            --right;
        }
        else if(is_vowel(s[right]))
            ++left;
        else
            --right;
    }

    return s;
}