class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> mismatch(101, 0);
        for(int i = 0; i < seats.size(); ++i)
        {
            mismatch[seats[i]]++;
            mismatch[students[i]]--;
        }

        int move = 0;
        int diff = 0;
        for(int i = 0; i < mismatch.size(); ++i)
        {
            move += abs(diff);
            diff += mismatch[i];
        }

        return move;
    }
};