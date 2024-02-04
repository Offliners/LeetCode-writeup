class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string n_str = int_to_str(n);
        int index;
        for(int i = n_str.length() - 1; i >= 1; --i)
        {
            if(n_str[i] >= n_str[i - 1])
                continue;
            
            --n_str[i - 1];
            index = i;
        }

        for(int i = index; i < n_str.length(); ++i)
            n_str[i] = '9';
        
        return str_to_int(n_str);
    }

    string int_to_str(int n)
    {
        string str = "";
        while(n > 0)
        {
            str = (char)(n % 10 + '0') + str;
            n /= 10;
        }

        return str;
    }

    int str_to_int(string str)
    {
        int n = 0;
        for(int i = 0; i < str.length(); ++i)
            n = n * 10 + (str[i] - '0');         

        return n; 
    }
};