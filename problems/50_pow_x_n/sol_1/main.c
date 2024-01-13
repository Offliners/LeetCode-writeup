double myPow(double x, int n) {
    if(n < 0)
        x = 1 / x;
    
    long int num = labs(n);
    double ans = 1;

    while(num)
    {
        if(num & 1)
            ans *= x;
        
        x *= x;
        num >>= 1;
    }

    return ans;
}