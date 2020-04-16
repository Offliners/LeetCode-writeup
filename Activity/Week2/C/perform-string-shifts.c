char * stringShift(char * s, int** shift, int shiftSize, int* shiftColSize){
    int len = strlen(s);
    int total = 0;
    
    for(int i = 0; i < shiftSize; i++)
    {
        int direction = shift[i][0];
        int amount = shift[i][1];
        
        amount =  amount % len;
        if(direction == 1)
            amount = len - amount;
        
        total += amount;
    }
    
    total %= len;
    
    for(int i = 0; i < total; i++)
    {
        char temp = s[0];
        for(int j = 0; j < len - 1; j++)
            s[j] = s[j + 1];
        
        s[len - 1] = temp;
    }
    
    return s;
}
