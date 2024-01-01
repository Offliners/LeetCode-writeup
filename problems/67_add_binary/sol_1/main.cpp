class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();
        int max_len = max(len_a, len_b);

        string ans(max_len, '0');

        int carry = 0;
        while(len_a > 0 && len_b > 0)
        {
            int sum = (a[len_a - 1] - '0') + (b[len_b - 1] - '0') + carry;
            char digit = (char)(sum % 2 + int('0'));
            carry = sum / 2;
            ans[max_len - 1] = digit;

            --len_a;
            --len_b;
            --max_len;
        }

        while(len_a > 0)
        {
            int sum = (a[len_a - 1] - '0') + carry;
            char digit = (char)(sum % 2 + int('0'));
            carry = sum / 2;
            ans[max_len - 1] = digit;

            --len_a;
            --max_len;
        }

        while(len_b > 0)
        {
            int sum = (b[len_b - 1] - '0') + carry;
            char digit = (char)(sum % 2 + int('0'));
            carry = sum / 2;
            ans[max_len - 1] = digit;

            --len_b;
            --max_len;
        }

        if(carry)
            ans = '1' + ans;
        
        return ans;
    }
};