class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";

        bool is_nagetive = false;
        if(num < 0)
        {
            is_nagetive = true;
            num = -num;
        }

        string ans = "";
        while(num > 0)
        {
            ans = (char)((num % 7) + '0') + ans;
            num /= 7;
        }

        return is_nagetive ? '-' + ans : ans;
    }
};