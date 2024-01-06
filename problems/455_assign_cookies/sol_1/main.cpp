class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int g_index = 0;
        int s_index = 0;
        while(g_index < g.size() && s_index < s.size())
        {
            if(g[g_index] <= s[s_index])
            {
                ++g_index;
                ++count;
            }

            ++s_index;
        }

        return count;
    }
};