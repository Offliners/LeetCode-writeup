class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_sum = 0;
        int t_sum = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            s_sum += s[i];
            t_sum += t[i];
        }
        t_sum += t[t.length() - 1];
        
        return char(t_sum - s_sum);
    }
};