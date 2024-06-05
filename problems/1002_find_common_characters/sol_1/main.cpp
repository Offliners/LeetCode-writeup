class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> common(words.size(), vector<int>(26, 0));
        for(int i = 0; i < words.size(); ++i)
            for(int j = 0; j < words[i].size(); ++j)
                common[i][words[i][j] - 'a'] += 1;

        vector<string> ans;
        for(int j = 0; j < 26; ++j)
        {
            int min_num = common[0][j];
            for(int i = 1; i < words.size(); ++i)
                if(common[i][j] < min_num)
                    min_num = common[i][j];

            for(int k = min_num; k > 0; --k)
            {
                string str(1, 'a' + j);
                ans.push_back(str);
            }
        }

        return ans;
    }
};