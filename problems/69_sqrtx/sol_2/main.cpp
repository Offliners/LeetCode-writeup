class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;

        int front = 0;
        int end = x;

        while(front <= end)
        {
            int mid = front + (end - front) / 2;
            if(mid > x / mid)
                end = mid - 1;
            else if(mid < x / mid)
                front = mid + 1;
            else
                return mid;
        }

        return end;
    }
};