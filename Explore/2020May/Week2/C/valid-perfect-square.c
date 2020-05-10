bool isPerfectSquare(int num){
    int left = 0;
    int right = num;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long square = mid * mid;
        
        if(square == num)
            return true;
        
        if(square < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}
