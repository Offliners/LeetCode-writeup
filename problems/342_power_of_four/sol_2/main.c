bool isPowerOfFour(int n) {
    return (n > 0) && (n & 0x55555555) && (!(n & (n - 1)));
}