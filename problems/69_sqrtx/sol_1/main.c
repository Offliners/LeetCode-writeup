int mySqrt(int x) {
    if(x <= 1)
        return x;

    for(int i = 2; i <= x; ++i)
    {
        if(i == x / i)
            return i;
        else if(i > x / i)
            return i - 1;
    }

    return -1;
}