class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag = -1;
        for(int i = 0; i < haystack.length(); ++i)
        {
            if(haystack[i] == needle[0])
            {
                int diff = 1;
                for(int j = 1; j < needle.length(); ++j)
                {
                    if(haystack[i + j] != needle[j])
                    {
                        diff = -1;
                        break;
                    }
                }

                if(diff == 1)
                {
                    flag = i;
                    break;
                }
            }
        }

        return flag;
    }
};