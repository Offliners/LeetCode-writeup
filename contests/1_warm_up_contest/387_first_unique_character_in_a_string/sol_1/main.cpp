class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(26, 0);

        for(int i = 0; i < s.length(); ++i)
            dict[s[i] - 'a']++;

        for(int i = 0; i < s.length(); ++i)
            if(dict[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};