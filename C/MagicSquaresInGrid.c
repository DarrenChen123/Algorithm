// Weekly Contest 86
/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).



Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/

int numMagicSquaresInside(int** grid, int gridRowSize, int *gridColSizes) {
    if (gridRowSize < 3 || gridColSizes[0] < 3) {
        return 0;
    }
    int ret = 0;
    int* flags = (int *) malloc (sizeof(int) * 9);
    for (int i = 1; i <= gridRowSize - 2; i++) {
        for (int j = 1; j <= gridColSizes[j] - 2; j++) {
            if (grid[i][j] != 5) {
                continue;
            }
            int breakFlag = 0;
            memset(flags, 0, sizeof(int) * 9);
            for (int m = i - 1; m <= i + 1; m++) {
                for (int n = j - 1; n <= j + 1; n++) {
                    if (grid[m][n] <= 0 || grid[m][n] > 9) {
                        breakFlag = 1;
                        break;
                    } else {
                        if (flags[grid[m][n] - 1] == 0) {
                            flags[grid[m][n] - 1] = 1;
                        } else {
                            breakFlag = 1;
                            break;
                        }
                    }
                }
                if (breakFlag) {
                    break;
                }
            }
            if (!breakFlag) {
                if (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] == 15 &&
                    grid[i][j - 1] + grid[i][j] + grid[i][j + 1] == 15 &&
                    grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] == 15 &&
                    grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] == 15 &&
                    grid[i - 1][j] + grid[i][j] + grid[i + 1][j] == 15 &&
                    grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] == 15 &&
                    grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1] == 15 &&
                    grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1] == 15) {
                    ret++;
                }
            }
        }
    }
    return ret;
}
