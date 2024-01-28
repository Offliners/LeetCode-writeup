class Solution {
public:
    int countKeyChanges(string s) {
        int change = 0;

        for(int i = 1; i < s.length(); ++i)
            if(s[i] != s[i - 1] && to_lower(s[i]) != to_lower(s[i - 1]))
                ++change;
        
        return change;
    }

    char to_lower(char c)
    {
        if(c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        
        return c;
    }
};