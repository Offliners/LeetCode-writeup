class Solution {
public:
    char findTheDifference(string s, string t) {
        s += t;

        int ans = 0;
        for(int i = 0; i < s.length(); ++i)
            ans ^= s[i];

        return ans;
    }
};