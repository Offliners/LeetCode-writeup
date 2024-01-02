bool isPalindrome(int x) {
    if(x < 0 || (x != 0 && x % 10 == 0))
        return false;

    long int res = 0;
    int temp = x;
    while(temp > 0)
    {
        res = res * 10 + temp % 10;
        temp /= 10;
    }

    return res == x;
}