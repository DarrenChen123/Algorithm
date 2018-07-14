// Subscription
// Facebook
/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** multiply(int** A, int ARowSize, int AColSize, int** B, int BRowSize, int BColSize) {
    int** ret = (int**)malloc(sizeof(int*) * ARowSize);
    for (int i = 0; i < ARowSize; i++) {
        ret[i] = (int*) malloc (sizeof(int) * BColSize);
        memset(ret[i], 0, sizeof(int) * BColSize);
        for (int j = 0; j < AColSize; j++) {
            if (A[i][j] != 0) {
                for (int k = 0; k < BColSize; k++) {
                    if (B[j][k] != 0) {
                        ret[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
    }
    return ret;
}
