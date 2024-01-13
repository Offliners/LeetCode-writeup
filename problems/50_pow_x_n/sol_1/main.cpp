class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
            x = 1 / x;

        long num = labs(n);
        double ans = 1;

        while(num != 0)
        {
            if((num & 1) != 0)
                ans *= x;
            
            x *= x;
            num >>= 1;
        }

        return ans;
    }
};