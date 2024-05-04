class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i = 0;
        int count = 0;
        int people_size = people.size() - 1;
        while(i <= people_size)
        {
            if(people[i] + people[people_size] <= limit)
                ++i;
            
            --people_size;
            ++count;
        }

        return count;
    }
};
