class Solution {
public:
    bool halvesAreAlike(string s) {
        int a_vowel_count = 0;
        int b_vowel_count = 0;
        for(int i = 0; i < s.length() / 2; ++i)
        {
            if(is_vowel(s[i]))
                ++a_vowel_count;
            
            if(is_vowel(s[i + s.length() / 2]))
                ++b_vowel_count;
        }

        return a_vowel_count == b_vowel_count;
    }

    bool is_vowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
};