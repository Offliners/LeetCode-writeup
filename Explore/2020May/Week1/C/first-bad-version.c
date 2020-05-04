// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long first = 1, last = (long long)n + 1;
    long long mid = first + (last - first) / 2;
    
    while(!((isBadVersion(mid))&&(!isBadVersion(mid-1))))
    {
        if(!isBadVersion(mid))
            first = mid + 1;
        else
            last = mid;
        
        mid = first + (last - first) / 2;
    }
    
    return mid;
}
