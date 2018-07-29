// Subscription
// Google
/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

typedef struct {
    int** matrix;
    int rowSize;
    int colSize;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    NumMatrix* obj = (NumMatrix*) malloc (sizeof(NumMatrix));
    obj->matrix = (int**) malloc (sizeof(int*) * matrixRowSize);
    obj->rowSize = matrixRowSize;
    obj->colSize = matrixColSize;
    for (int i = 0; i < matrixRowSize; i++) {
        obj->matrix[i] = (int*) malloc (sizeof(int) * matrixColSize);
        memcpy(obj->matrix[i], matrix[i], sizeof(int) * matrixColSize);
    }
    return obj;
}

void numMatrixUpdate(NumMatrix* obj, int row, int col, int val) {
    if (row < obj->rowSize && col < obj->colSize) {
        obj->matrix[row][col] = val;
    }
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = (row1 > 0 ? row1 : 0); i <= (row2 < obj->rowSize ? row2 : (obj->rowSize - 1)); i++) {
        for (int j = (col1 > 0 ? col1 : 0); j <= (col2 < obj->colSize ? col2 : (obj->colSize - 1)); j++) {
            sum += obj->matrix[i][j];
        }
    }
    return sum;
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->rowSize; i++) {
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * numMatrixUpdate(obj, row, col, val);
 * int param_2 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */
