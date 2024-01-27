class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        int data = 1;
        for(int i = 0; i < target.size(); ++i)
        {
            while(data < target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++data;
            }

            ans.push_back("Push");
            ++data;
        }

        return ans;
    }
};