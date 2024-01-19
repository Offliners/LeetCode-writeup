class Solution {
public:
    int myAtoi(string s) {
        int index = 0;

        while(index < s.length() && s[index] == ' ')
            ++index;
        
        int sign = 1;
        if(s[index] == '-')
        {
            sign = -1;
            ++index;
        }
        else if(s[index] == '+')
            ++index;
        
        long int ans = 0;
        while(index < s.length())
        {
            if(s[index] >= '0' && s[index] <= '9')
            {
                ans *= 10;
                ans += (sign == 1) ? (s[index] - '0') : -(s[index] - '0');

                if(ans > INT_MAX)
                    return INT_MAX;
                
                if(ans < INT_MIN)
                    return INT_MIN;
                
                ++index;
            }
            else
                return ans;
        }

        return ans;
    }
};