class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int max_you = 0;
        int left = 0;
        int right = piles.size() - 1;
        while(left < right)
        {
            if(left < right)
                max_you += piles[right - 1];
            
            ++left;
            right -= 2;
        }

        return max_you;
    }
};