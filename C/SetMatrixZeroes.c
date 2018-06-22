// Medium Collection
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
	[1,1,1],
	[1,0,1],
	[1,1,1]
]
Output:
[
	[1,0,1],
	[0,0,0],
	[1,0,1]
]
Example 2:

Input:
[
	[0,1,2,0],
	[3,4,5,2],
	[1,3,1,5]
]
Output:
[
	[0,0,0,0],
	[0,4,5,0],
	[0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

// O(m + n) space:
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	int* rowsFlag = (int *) malloc (sizeof(int) * matrixRowSize);
	memset(rowsFlag, 0, sizeof(int) * matrixRowSize);
	int* colsFlag = (int *) malloc (sizeof(int) * matrixColSize);
	memset(colsFlag, 0, sizeof(int) * matrixColSize);
	for (int i = 0; i < matrixRowSize; i++) {
		for (int j = 0; j < matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				rowsFlag[i] = 1;
				colsFlag[j] = 1;
			}
		}
	}

	for (int i = 0; i < matrixRowSize; i++) {
		for (int j = 0; j < matrixColSize; j++) {
			if (rowsFlag[i] == 1 || colsFlag[j] == 1) {
				matrix[i][j] = 0;
			}
		}
	}
}

// O(1) space:
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	int firstRowFlag = 0;
	int firstColFlag = 0;
	for (int i = 0; i < matrixRowSize; i++) {
		for (int j = 0; j < matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				if (i == 0) {
					firstRowFlag = 1;
				} else {
					matrix[i][0] = 0;
				}
				if (j == 0) {
					firstColFlag = 1;
				} else {
					matrix[0][j] = 0;
				}
			}
		}
	}
	for (int i = 1; i < matrixRowSize; i++) {
		for (int j = 1; j < matrixColSize; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if (firstRowFlag == 1) {
		for (int j = 0; j < matrixColSize; j++) {
			matrix[0][j] = 0;
		}
	}
	if (firstColFlag == 1) {
		for (int i = 0; i < matrixRowSize; i++) {
			matrix[i][0] = 0;
		}
	}
}
