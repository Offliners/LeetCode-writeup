class Solution {
public:
    int hammingDistance(int x, int y) {
        int ham_dis = x ^ y;
        int count = 0;
        while(ham_dis > 0)
        {
            ham_dis &= ham_dis - 1;
            ++count;
        }

        return count;
    }
};