// Easy Collection
/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    if (numRows == 0) {
        return NULL;
    }
    int** ret = (int **) malloc (sizeof(int *) * numRows);
    *columnSizes = (int *) malloc (sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        int columnSize = i + 1;
        (*columnSizes)[i] = columnSize;
        int *column = (int *) malloc (sizeof(int) * columnSize);
        if (i == 0) {
            column[0] = 1;
        } else {
            column[0] = column[i] = 1;
            for (int j = 1; j < i; j++) {
                column[j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        ret[i] = column;
    }
    return ret;
}
