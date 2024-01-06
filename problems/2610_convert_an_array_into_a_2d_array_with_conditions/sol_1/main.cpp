class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int max_count = 1;
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(umap.find(nums[i]) != umap.end())
            {
                umap[nums[i]]++;
                if(umap[nums[i]] >= max_count)
                    max_count = umap[nums[i]];
            }
            else
                umap.insert({nums[i], 1});
        }

        vector<vector<int>> ans;
        for(int i = 0; i < max_count; ++i)
        {
            vector<int> row;
            for(auto v : umap)
            {
                if(v.second != 0)
                {
                    row.push_back(v.first);
                    umap[v.first]--;
                }
            }
            ans.push_back(row);
        }

        return ans;
    }
};