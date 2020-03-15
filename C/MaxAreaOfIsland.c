/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

*/

int dfs(int **grid, int gridSize, int* gridColSize, int i, int j) {
	if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[0] || grid[i][j] != 1) {
		return 0;
	}
	grid[i][j] = 0;
	int di[4] = {0, 0, 1, -1};
	int dj[4] = {1, -1, 0, 0};
	int ret = 1;
	for (int index = 0; index < 4; index++) {
		int nextI = i + di[index];
		int nextJ = j + dj[index];
		ret += dfs(grid, gridSize, gridColSize, nextI, nextJ);
	}
	return ret;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int ret = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			int cur = dfs(grid, gridSize, gridColSize, i, j);
			ret = ret > cur ? ret : cur;
		}
	}
	return ret;
}
