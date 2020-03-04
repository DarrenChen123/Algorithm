/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

int orangesRotting(int** grid, int gridSize, int* gridColSize){
	bool unchanged = true;
	bool hasFresh = false;
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridColSize[i]; j++){
			if(grid[i][j] == 1){
				if((i - 1 >= 0 && grid[i - 1][j] == 2)
				   || (i + 1 < gridSize && grid[i + 1][j] == 2)
				   || (j - 1 >= 0 && grid[i][j-1] == 2)
				   || (j + 1 < gridColSize[i] && grid[i][j + 1] == 2)){
					grid[i][j] = -2;
					unchanged = false;
				}else{
					hasFresh = true;
				}
			}
		}
	}
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridColSize[i]; j++){
			if(grid[i][j] == -2) {
				grid[i][j] = 2;
			}
		}
	}
	if(unchanged){
		if(hasFresh) {
			return -1;
		} else {
			return 0;
		}
	}
	int steps = orangesRotting(grid, gridSize, gridColSize);
	return steps == -1 ? -1 : steps + 1;
}