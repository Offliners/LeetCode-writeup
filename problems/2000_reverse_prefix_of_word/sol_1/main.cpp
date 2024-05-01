class Solution {
public:
    string reversePrefix(string word, char ch) {
        int found_index = 0;
        for(int i = 0; i < word.length(); ++i)
        {
            if(word[i] == ch)
            {
                found_index = i;
                break;
            }
        }

        int index = found_index;
        for(int i = 0; i < found_index / 2 + 1; ++i)
        {
            char temp = word[i];
            word[i] = word[index];
            word[index] = temp;
            --index;
        }
        
        return word;
    }
};