class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        vector<int> complex_number1 = string_to_complex(num1);
        vector<int> complex_number2 = string_to_complex(num2);

        int real_part = complex_number1[0] * complex_number2[0] - complex_number1[1] * complex_number2[1];
        int imaginary_part = complex_number1[0] * complex_number2[1] + complex_number1[1] * complex_number2[0];

        cout << real_part << " " << imaginary_part << endl;
        string ans = int_to_string(real_part) + "+" + int_to_string(imaginary_part) + "i";
        return ans;
    }

    vector<int> string_to_complex(string num)
    {
        vector<int> complex_number;

        int real_part = 0;
        int sign = 1;
        int i;
        for(i = 0; num[i] != '+'; ++i)
        {            
            if(num[i] == '-')
            {
                sign = -1;
                continue;
            }

            real_part = real_part * 10 + (num[i] - '0');
        }
        complex_number.push_back(sign * real_part);

        ++i;
        sign = 1;
        int imaginary_part = 0;
        for(; num[i] != 'i'; ++i)
        {
            if(num[i] == '-')
            {
                sign = -1;
                continue;
            }
            
            imaginary_part = imaginary_part * 10 + (num[i] - '0');
        }

        complex_number.push_back(sign * imaginary_part);
        return complex_number;
    }

    string int_to_string(int num)
    {
        if(num == 0)
            return "0"; 

        string num_str = "";
        int temp = num < 0 ? -num : num;
        while(temp > 0)
        {
            num_str = (char)((temp % 10) + '0') + num_str;
            temp /= 10;
        }

        return num < 0 ? "-" + num_str : num_str;
    }
};