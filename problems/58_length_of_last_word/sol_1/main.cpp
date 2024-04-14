class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_word_length = 0;
        bool is_word = false;
        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(s[i] == ' ')
            {
                if(!is_word)
                    continue;
                else
                    break;
            }
            
            is_word = true;
            ++last_word_length;
        }

        return last_word_length;
    }
};