class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int front = 0;
        int end = n * m - 1;
        while(front <= end)
        {
            int mid = front + (end - front) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                front = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }
};