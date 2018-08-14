// Subscription
// LinkedIn
/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int n, int f, int d, int *sz, int ***result, int **col, int *num) {
    int i, j, k;
    int *buf;

    j = *num;
    for (i = f; i < n; i ++) {
        if (!(n % i)) {
            dfs(n / i, i, d + 1, sz, result, col, num);
            while (j < *num) {
                buf = (*result)[j];
                buf[d] = i;
                j ++;
            }
        }
    }

    if (n <= f || (n % f)) {
        if (d > 0) {
            // found one
            buf = malloc((d + 1) * sizeof(int));
            //assert(buf);
            buf[d] = n;
            if(*num == *sz) {
                *sz = (*sz) * 2;
                *result = realloc(*result, (*sz) * sizeof(int *));
                *col = realloc(*col, (*sz) * sizeof(int));
                //assert(*result && *col);
            }
            (*result)[*num] = buf;
            (*col)[*num] = d + 1;
            (*num) ++;
        }
    }
}

int** getFactors(int n, int** columnSizes, int* returnSize) {
    int **result;
    int sz = 100;
    int i, j, k, x, y, z, *tmp;

    result = malloc(sz * sizeof(int *));
    *columnSizes = malloc(sz * sizeof(int));
    //assert(result && *columnSizes);

    *returnSize = 0;

    dfs(n, 2, 0, &sz, &result, columnSizes, returnSize);

    //remove duplicated ones
    for (i = 0; i < *returnSize; i ++) {
        do {
            z = 0;
            for (j = i + 1; j < *returnSize; j ++) {
                if ((*columnSizes)[i] == (*columnSizes)[j]) {
                    x = y = 0;
                    for (k = 0; k < (*columnSizes)[i]; k ++) {
                        x += result[i][k];
                        y += result[j][k];
                    }
                    if (x == y) {
                        //found a dup
                        (*returnSize) --;
                        tmp = result[j];
                        result[j] = result[*returnSize];
                        (*columnSizes)[j] = (*columnSizes)[*returnSize];
                        free(tmp);
                        z = 1;
                    }
                }
            }
        } while (z);
    }

    if (*returnSize == 0) {
        free(result);
        free(*columnSizes);
        result = NULL;
        *columnSizes = NULL;
    }

    return result;
}
