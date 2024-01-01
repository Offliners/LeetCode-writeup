class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        int cur = 1;
        for(int i = 0; i < n; ++i)
        {
            ans.push_back(cur);

            if(cur * 10 <= n)
                cur *= 10;
            else if(cur % 10 != 9 && cur + 1 <= n)
                ++cur;
            else
            {
                if(cur == n)
                    cur /= 10;
                
                while(cur % 10 == 9)
                    cur /= 10;
                
                ++cur;
            }
        }

        return ans;
    }
};