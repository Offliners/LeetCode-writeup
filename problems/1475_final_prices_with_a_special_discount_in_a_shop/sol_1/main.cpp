class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i = 0; i < prices.size() - 1; ++i)
        {
            int cur_price = prices[i];
            int j;
            for(j = i + 1; j < prices.size(); ++j)
            {
                if(prices[j] <= cur_price)
                {
                    ans.push_back(cur_price - prices[j]);
                    break;
                }
            }
            
            if(j == prices.size())
                ans.push_back(cur_price);
        }

        ans.push_back(prices.back());

        return ans;
    }
};