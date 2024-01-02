int is_letter(char c)
{
    if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
        return true;
    else
        return false;
}

char* reverseOnlyLetters(char* s) {
    int left = 0;
    int right = 0;
    while(s[right] != '\0')
        ++right;

    while(left <= right)
    {
        if(is_letter(s[left]) && is_letter(s[right]))
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
        else if(is_letter(s[right]))
            ++left;
        else
            --right;
    }

    return s;
}