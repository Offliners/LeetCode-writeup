class Solution {
public:
    int lengthLongestPath(string input) {
        int max_len = 0;
        int stack[input.length() + 1];
        
        stringstream ss(input);
        string temp;
        while(getline(ss, temp, '\n'))
        {
            int level = 0;
            for(int i = 0; i < temp.length(); ++i)
            {
                if(temp[i] != '\t')
                {
                    level = i;
                    break;
                }
            }

            int cur_len = temp.length() - level;
            int pre_len = level == 0 ? 0 : stack[level - 1];
            if(temp.find(".") != string::npos)
                max_len = max(pre_len + cur_len, max_len); 
            else
                stack[level] = pre_len + cur_len + 1;
        }
        
        return max_len;
    }
};