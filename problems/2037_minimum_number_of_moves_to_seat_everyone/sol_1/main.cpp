class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int move = 0;
        for(int i = 0; i < seats.size(); ++i)
            move += abs(students[i] - seats[i]);
        
        return move;
    }
};