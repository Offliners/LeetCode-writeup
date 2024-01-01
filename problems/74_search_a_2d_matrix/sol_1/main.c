bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int front = 0;
    int end = matrixSize * (*matrixColSize) - 1;

    while(front <= end)
    {
        int mid = front + (end - front) / 2;
        int row = mid / (*matrixColSize);
        int col = mid % (*matrixColSize);

        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] < target)
            front = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}