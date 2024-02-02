class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(is_number(tokens[i]))
                s.push(str_to_number(tokens[i]));
            else
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int temp = cal(a, b, tokens[i]);
                s.push(temp);
            }
        }

        return s.top();
    }

    bool is_number(string str)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/")
            return false;
        else
            return true;
    }

    int str_to_number(string str)
    {
        int index = 0;
        int sign = 1;
        if(str[0] == '-')
        {
            sign = -1;
            ++index;
        }

        int number = 0;
        for(int i = index; i < str.length(); ++i)
            number = number * 10 + (str[i] - '0');
            
        return sign * number;
    }

    int cal(int a, int b, string op)
    {
        if(op == "+")
            return b + a;
        else if(op == "-")
            return b - a;
        else if(op == "*")
            return b * a;
        else
            return b / a;
    }
};