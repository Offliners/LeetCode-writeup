class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0)
            return false;

        vector<int> stack;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push_back(s[i]);
            else
            {
                if((stack.size() != 0) && ((s[i] == ')' && stack.back() == '(') || (s[i] == ']' && stack.back() == '[') || (s[i] == '}' && stack.back() == '{')))
                    stack.pop_back();
                else
                    return false;
            }
        }

        return stack.size() == 0;
    }
};