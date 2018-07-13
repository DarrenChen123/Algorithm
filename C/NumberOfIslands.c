// Medium Collection
// Bloomberg
// Amazon
// Microsoft
// Facebook
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

void visit (char** grid, int gridRowSize, int gridColSize, int** visited, int x, int y) {
    if (x < 0 || x > gridRowSize - 1 || y < 0 || y > gridColSize - 1 || grid[x][y] == '0' || visited[x][y]) {
        return;
    }
    visited[x][y] = 1;
    visit(grid, gridRowSize, gridColSize, visited, x - 1, y);
    visit(grid, gridRowSize, gridColSize, visited, x + 1, y);
    visit(grid, gridRowSize, gridColSize, visited, x, y - 1);
    visit(grid, gridRowSize, gridColSize, visited, x, y + 1);
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize == 0 || gridColSize == 0) {
        return 0;
    }

    int** visited = (int**) malloc (sizeof(int *) * gridRowSize);
    for (int i = 0; i < gridRowSize; i++) {
        int* column = (int *) malloc (sizeof(int) * gridColSize);
        for (int j = 0; j < gridColSize; j++) {
            column[j] = 0;
        }
        visited[i] = column;
    }
    int ret = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                visit(grid, gridRowSize, gridColSize, visited, i, j);
                ret++;
            }
        }
    }
    for (int i = 0; i < gridRowSize; i++) {
        free(visited[i]);
    }
    free(visited);
    return ret;
}
