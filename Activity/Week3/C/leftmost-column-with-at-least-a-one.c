/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * struct BinaryMatrix {
 *     int (*get)(struct BinaryMatrix*, int, int);
 *     int* (*dimensions)(struct BinaryMatrix*);
 * };
 */

int leftMostColumnWithOne(struct BinaryMatrix* matrix) {
    int row = matrix->dimensions(matrix)[0];
    int col = matrix->dimensions(matrix)[1];
    int leftMost = col;
    
    for(int i = 0; i < row;i++)
    {
        while(matrix->get(matrix, i, leftMost - 1) == 1)
        {
            leftMost--;
            
            if(leftMost == 0)
                return 0;
        }
    }
    
    if(leftMost == col)
        return -1;
    
    return leftMost;
}
