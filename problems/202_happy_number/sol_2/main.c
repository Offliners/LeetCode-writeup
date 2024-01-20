long long int cal(long long int n)
{
    long long int res = 0;
    while(n > 0)
    {
        res += (n % 10) * (n % 10);
        n /= 10;
    }

    return res;
}

bool isHappy(int n) {
    if(n < 10)
        return n == 1 || n == 7 ? true : false;
    
    n = cal(n);
    return isHappy(n);
}