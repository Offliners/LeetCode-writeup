class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0;
        int t_index = 0;

        while(s_index < s.length() && t_index < t.length())
        {
            if(s[s_index] == t[t_index])
                ++t_index;
            
            ++s_index;
        }

        return t.length() - t_index;
    }
};