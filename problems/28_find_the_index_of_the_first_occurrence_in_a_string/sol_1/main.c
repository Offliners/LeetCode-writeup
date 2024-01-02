int strStr(char* haystack, char* needle) {
    int flag = -1;
    for(int i = 0; haystack[i] != '\0'; ++i)
    {
        if(haystack[i] == needle[0])
        {
            int diff = -1;
            for(int j = 1; needle[j] != '\0'; ++j)
            {
                if(haystack[i + j] != needle[j])
                {
                    diff = 1;
                    break;
                }
            }

            if(diff == -1)
            {
                flag = i;
                break;
            }
        }
    }

    return flag;
}