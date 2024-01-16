class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(int i = 0; i < s.length(); ++i)
        {
            if(ans == "" || s[i] != ans.back())
                ans += s[i];
            else
                ans.pop_back();
        }

        return ans;
    }
};