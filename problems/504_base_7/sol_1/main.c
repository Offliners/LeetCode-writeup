char* convertToBase7(int num) {
    if(num == 0)
        return "0";

    bool is_negative = false;
    if(num < 0)
    {
        is_negative = true;
        num = -num;
    }
    
    int temp = num;
    int ans_len = 0;
    while(temp > 0)
    {
        ++ans_len;
        temp /= 7;
    }

    char *ans = (char*)malloc((ans_len + 2) * sizeof(char));
    int index = ans_len;
    while(num > 0)
    {
        ans[index] = (num % 7 + '0');
        --index;
        num /= 7;
    }
    ans[ans_len + 1] = '\0';

    if(!is_negative)
        ans = ans + 1;
    else
        ans[0] = '-';

    return ans;
}