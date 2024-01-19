class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray_code(1 << n);

        for(int i = 0; i < gray_code.size(); ++i)
            gray_code[i] = i ^ (i >> 1);

        return gray_code;
    }
};