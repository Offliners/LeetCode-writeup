class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left <= right)
        {
            if(is_letter(s[left]) && is_letter(s[right]))
            {
                char temp = s[right];
                s[right] = s[left];
                s[left] = temp;

                ++left;
                --right;
            }
            else if(is_letter(s[right]))
                ++left;
            else
                --right;
        }

        return s;
    }

    bool is_letter(char c)
    {
        if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
            return true;
        else
            return false;
    }
};