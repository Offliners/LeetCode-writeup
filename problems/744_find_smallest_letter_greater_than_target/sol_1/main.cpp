class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int min_distance = 26;
        char ans = letters[0];
        for(int i = 0; i < letters.size(); ++i)
        {
            if(letters[i] - target < min_distance && letters[i] - target > 0)
            {
                min_distance = letters[i] - target;
                ans = letters[i];
            }
        }

        return ans;
    }
};