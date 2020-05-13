char * removeKdigits(char * num, int k){
    int n = strlen(num);

    while (k > 0 && *num) 
    {
        while(*num == '0') 
        {
            num++;
            n--;
        }
        
        int i = 0;
        while((i < n - 1 )&&(num[i] <= num[i + 1])) 
            i++;

        for(int j = i; j < n - 1; j++)
            num[j] = num[j + 1];
            
        num[n - 1] = 0;
        n--;
        k--;
    }
    
    while(*num == '0')
        num++;

    if(!(*num)) 
        num = "0";
    
    return num;
}
