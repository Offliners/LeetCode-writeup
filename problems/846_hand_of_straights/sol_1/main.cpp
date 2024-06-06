class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        
        sort(hand.begin(), hand.end());
        for(int i = 0; i < hand.size(); ++i)
            if(hand[i] >= 0 && !find_successor(hand, groupSize, i))
                return false;

        return true;
    }

    bool find_successor(vector<int>& hand, int groupSize, int index)
    {
        int next = hand[index] + 1;
        hand[index] = -1;
        int count = 1;
        ++index;

        while(index < hand.size() && count < groupSize)
        {
            if(hand[index] == next)
            {
                next = hand[index] + 1;
                hand[index] = -1;
                ++count;
            }

            ++index;
        }

        return count == groupSize;
    }
};