char *int_to_str(int n)
{
    int temp = n;
    int count = 0;
    while(temp)
    {
        temp /= 10;
        ++count;
    }

    char *str = (char*)malloc((count + 1) * sizeof(char));
    for(int i = count - 1; i >= 0; --i)
    {
        str[i] = n % 10 + '0';
        n /= 10;
    }
    
    str[count] = '\0';
    return str;
}

int str_to_int(char *str)
{
    int n = 0;
    for(int i = 0; i < strlen(str); ++i)
        n = n * 10 + (str[i] - '0');

    return n;
}

int monotoneIncreasingDigits(int n) {
    char *n_str = int_to_str(n);
    int index;
    for(int i = strlen(n_str) - 1; i >= 1; --i)
    {
        if(n_str[i] >= n_str[i - 1])
            continue;
        
        --n_str[i - 1];
        index = i;
    }

    for(int i = index; i < strlen(n_str); ++i)
        n_str[i] = '9';

    int ans = str_to_int(n_str);
    free(n_str);

    return ans;
}