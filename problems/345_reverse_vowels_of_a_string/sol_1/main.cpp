class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right)
        {
            if(is_vowel(s[left]) && is_vowel(s[right]))
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                ++left;
                --right;
            }
            else if(is_vowel(s[right]))
                ++left;
            else
                --right;
        }

        return s;
    }

    bool is_vowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
};