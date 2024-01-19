int myAtoi(char* s) {
    int index = 0;
    int s_len = strlen(s);

    while(index < s_len && s[index] == ' ')
        ++index;
    
    int sign = 1;
    if(s[index] == '-')
    {
        sign = -1;
        ++index;
    }
    else if(s[index] == '+')
        ++index;
    
    long int ans = 0;
    while(index < s_len)
    {
        if(s[index] >= '0' && s[index] <= '9')
        {
            ans *= 10;
            ans += (sign == 1) ? (s[index] - '0') : -(s[index] - '0');

            if(ans > INT_MAX)
                return INT_MAX;
            
            if(ans < INT_MIN)
                return INT_MIN;
            
            ++index;
        }
        else
            return ans;
    }

    return ans;
}