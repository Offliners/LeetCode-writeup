class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(int i = 0; i < jewels.length(); ++i)
            for(int j = 0; j < stones.length(); ++j)
                if(stones[j] == jewels[i])
                    ++ans;

        return ans;
    }
};