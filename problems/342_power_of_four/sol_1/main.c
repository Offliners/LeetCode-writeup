bool isPowerOfFour(int n) {
    if(n < 0)
        return false;

    int count = 0;
    for(int i = 0; n != 0; ++i)
    {
        if(n & 1 == 1)
        {
            if(i % 2 == 0)
                ++count;
            else
                return false;
        }

        n >>= 1;
    }

    return count == 1;
}