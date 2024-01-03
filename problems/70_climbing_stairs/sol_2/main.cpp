class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        
        int prev = 1;
        int cur = 1;
        for(int i = 2; i <= n; ++i)
        {
            int temp = cur;
            cur += prev;
            prev = temp;
        }

        return cur;
    }
};