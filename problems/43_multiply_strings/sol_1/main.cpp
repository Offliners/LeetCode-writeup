class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        vector<int> ans(num1.length() + num2.length(), 0);
        for(int i = num1.length() - 1; i >= 0; --i)
        {
            for(int j = num2.length() - 1; j >= 0; --j)
            {
                ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }
        }

        int non_zero_index = 0;
        while(ans[non_zero_index] == 0)
            ++non_zero_index;
        
        string ans_str = "";
        for(int i = non_zero_index; i < ans.size(); ++i)
            ans_str += char(ans[i] + '0');
        
        return ans_str;
    }
};