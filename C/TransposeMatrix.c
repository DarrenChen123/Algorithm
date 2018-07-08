// Weekly Contest 92
/*
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.



Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]


Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int** ret = (int**) malloc (sizeof(int*) * AColSizes[0]);
    if (ARowSize <= 0) {
        return NULL;
    }
    *returnSize = AColSizes[0];
    *columnSizes = (int*) malloc (sizeof(int) * ARowSize);
    for (int i = 0; i < AColSizes[0]; i++) {
        (*columnSizes)[i] = ARowSize;
        ret[i] = (int*) malloc (sizeof(int) * ARowSize);
        for (int j = 0; j < ARowSize; j++) {
            ret[i][j] = A[j][i];
        }
    }
    return ret;
}
