bool checkValidString(char * s){
    int min = 0;
    int max = 0;
    
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '(')
        {
            min++;
            max++;
        }
        else if(s[i] == ')')
        {
            min--;
            max--;
        }
        else if(s[i] == '*')
        {
            min--;
            max++;
        }
        
        if(max < 0)
            return false;
        if(min < 0)
            min = 0;
    }
    
    return min == 0;
}

