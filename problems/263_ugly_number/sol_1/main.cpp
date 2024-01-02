class Solution {
public:
    bool isUgly(int n) {
        int i = 2;
        while(i <= 5 && n > 1)
        {
            if(n % i == 0)
            {
                n /= i;
                if(i != 2 && i != 3 && i != 5)
                    return false;
            }
            else
                ++i;
        }

        return n == 1;
    }
};