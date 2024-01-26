void string_to_int(int *real, int *imaginary, char *num)
{
    int real_part = 0;
    int i;
    int sign = 1;
    for(i = 0; num[i] != '+'; ++i)
    {
        if(num[i] == '-')
        {
            sign = -1;
            continue;
        }

        real_part = real_part * 10 + (num[i] - '0');
    }
    *real = sign * real_part;

    ++i;
    int imaginary_part = 0;
    sign = 1;
    for(; num[i] != 'i'; ++i)
    {
        if(num[i] == '-')
        {
            sign = -1;
            continue;
        }

        imaginary_part = imaginary_part * 10 + (num[i] - '0');
    }
    *imaginary = sign * imaginary_part;
}

char *int_to_string(int num)
{
    if(num == 0)
    {
        char *num_str = (char*)malloc(2 * sizeof(char));
        num_str[0] = '0';
        num_str[1] = '\0';
        return num_str;
    }

    int temp = num < 0 ? -num : num;
    int count = 0;
    while(temp > 0)
    {
        ++count;
        temp /= 10;
    }

    count = num < 0 ? count + 1 : count;
    char *num_str = (char*)malloc((count + 1) * sizeof(char));

    int index = count - 1;
    temp = num < 0 ? -num : num;;
    while(temp > 0)
    {
        num_str[index] = ((temp % 10) + '0');
        temp /= 10;
        --index;
    }
    num_str[count] = '\0';

    if(num < 0)
        num_str[0] = '-';

    return num_str;
}

char* complexNumberMultiply(char* num1, char* num2) {
    int real_num1;
    int real_num2;
    int imaginary_num1;
    int imaginary_num2;

    string_to_int(&real_num1, &imaginary_num1, num1);
    string_to_int(&real_num2, &imaginary_num2, num2);

    int real = real_num1 * real_num2 - imaginary_num1 * imaginary_num2;
    int imaginary = real_num1 * imaginary_num2 + real_num2 * imaginary_num1;

    char *real_str = int_to_string(real);
    char *imaginary_str = int_to_string(imaginary);

    int ans_len = strlen(real_str) + 1 + strlen(imaginary_str) + 1;
    char *ans = (char*)malloc((ans_len + 1) * sizeof(char));
    int i;
    for(i = 0; i < strlen(real_str); ++i)
        ans[i] = real_str[i];

    ans[i] = '+';
    ++i;
    for(; i - strlen(real_str) - 1 < strlen(imaginary_str); ++i)
        ans[i] = imaginary_str[i - strlen(real_str) - 1];

    ans[i] = 'i';
    ++i;
    ans[i] = '\0';
    
    free(real_str);
    free(imaginary_str);

    return ans;
}