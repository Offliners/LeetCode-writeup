bool is_alpha(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else
        return false;
}

char to_lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        return c - ('A' - 'a');
    else
        return c;
}

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while(left <= right)
    {
        if(!is_alpha(s[left]))
        {
            ++left;
            continue;
        }

        if(!is_alpha(s[right]))
        {
            --right;
            continue;
        }

        if(to_lower(s[left]) == to_lower(s[right]))
        {
            ++left;
            --right;
        }
        else
            return false;
    }

    return true;
}