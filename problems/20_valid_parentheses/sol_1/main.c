bool isValid(char* s) {
    int s_len = 0;
    while(s[s_len] != '\0')
        ++s_len;
    
    char *stack = (char*)malloc((s_len + 1) * sizeof(char));
    int top = 0;
    for(int i = 0; s[i] != '\0'; ++i)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[top] = s[i];
            ++top;
        }
        else
        {
            if((top != 0) && ((s[i] == ')' && stack[top - 1] == '(') || (s[i] == ']' && stack[top - 1] == '[') || (s[i] == '}' && stack[top - 1] == '{')))
                --top;
            else
                return false;
        }
    }

    free(stack);
    return top == 0;
}