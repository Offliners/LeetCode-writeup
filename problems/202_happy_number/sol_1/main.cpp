class Solution {
public:
    bool isHappy(int n) {
        long long int slow = n;
        long long int fast = cal(n);

        while(slow != fast)
        {
            slow = cal(slow);
            fast = cal(cal(fast));

            if(slow == 1 || fast == 1)
                return true;
        }

        return slow == 1;
    }

    long long int cal(long long int n)
    {
        long long int res = 0;
        while(n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }

        return res;
    }
};