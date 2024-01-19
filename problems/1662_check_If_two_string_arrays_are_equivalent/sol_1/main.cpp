class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1_str = "";
        for(int i = 0; i < word1.size(); ++i)
            word1_str += word1[i];

        string word2_str = "";
        for(int i = 0; i < word2.size(); ++i)
            word2_str += word2[i];
        
        return word1_str == word2_str;
    }
};