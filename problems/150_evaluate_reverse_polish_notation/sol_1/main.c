bool is_number(char *number)
{
    if(!strcmp(number, "+") || !strcmp(number, "-") || !strcmp(number, "*") || !strcmp(number, "/"))
        return false;
    else
        return true;
}

int str_to_number(char *str)
{
    int index = 0;
    int sign = 1;
    if(str[0] == '-')
    {
        sign = -1;
        ++index;
    }

    int number = 0;
    for(int i = index; i < strlen(str); ++i)
        number = number * 10 + (str[i] - '0');
    
    return sign * number;
}

int cal(int a, int b, char *op)
{
    if(!strcmp(op, "+"))
        return b + a;
    else if(!strcmp(op, "-"))
        return b - a;
    else if(!strcmp(op, "*"))
        return b * a;
    else
        return b / a;
}

int evalRPN(char** tokens, int tokensSize) {
    int *stack = (int*)malloc(tokensSize * sizeof(int));
    int top = 0;

    for(int i = 0; i < tokensSize; ++i)
    {
        if(is_number(tokens[i]))
            stack[top++] = str_to_number(tokens[i]);
        else
        {
            int a = stack[--top];
            int b = stack[--top];
            stack[top++] = cal(a, b, tokens[i]);
        }
    }

    return stack[--top];
}