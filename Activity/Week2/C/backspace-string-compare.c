char *backspaceProcess(char *str)
{
    int len = strlen(str);
    int index = 0;
    
    for(int i = 0; i < len; i++)
    {
        if(str[i] != '#')
        {
            str[index] = str[i];
            index++;
        }
        else
            if(index > 0)
                index--;
    }
    
    str[index] = '\0';
    
    return str;
}

bool backspaceCompare(char * S, char * T){
    return strcmp(backspaceProcess(S), backspaceProcess(T)) == 0;
}
