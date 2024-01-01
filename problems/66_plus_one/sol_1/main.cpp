class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size() + 1);
        int carry = 1;

        for(int i = digits.size() - 1; i >= 0; --i)
        {
            ans[i + 1] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }

        if(carry)
            ans[0] = carry;
        else
            ans.erase(ans.begin());

        return ans;
    }
};