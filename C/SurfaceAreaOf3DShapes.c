// Weekly Contest 99
/*
On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.



Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46


Note:

1 <= N <= 50
0 <= grid[i][j] <= 50
*/

int min (int a, int b) {
    return a < b ? a : b;
}
int surfaceArea(int** grid, int gridRowSize, int *gridColSizes) {
    int ret = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSizes[i]; j++) {
            if (grid[i][j] > 0) {
                ret += 6 * grid[i][j] - (grid[i][j] - 1) * 2;
            }
        }
    }
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSizes[i]; j++) {
            if (i < gridRowSize - 1) {
                ret -= 2 * (min(grid[i][j], grid[i + 1][j]));
            }
            if (j < gridColSizes[i] - 1) {
                ret -= 2 * (min(grid[i][j], grid[i][j + 1]));
            }
        }
    }
    return ret;
}
