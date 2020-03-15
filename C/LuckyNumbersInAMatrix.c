/*
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sort(int* nums, int left, int right) {
	int i, j, key;
	if (left >= right) {
		return;
	}
	i = left;
	j = right;
	key = nums[left];

	while (i < j) {
		while (nums[j] >= key && i < j) {
			j--;
		}
		nums[i] = nums[j];
		while (nums[i] <= key && i < j) {
			i++;
		}
		nums[j] = nums[i];
	}

	nums[i] = key;

	sort(nums, left, i - 1);
	sort(nums, i + 1, right);
}

int *column(int** matrix, int matrixSize, int* matrixColSize, int index) {
	int *ret = (int *)malloc(sizeof(int) * matrixSize);
	for (int i = 0; i < matrixSize; i++) {
		ret[i] = matrix[i][index];
	}
	return ret;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	 if (nums1Size == 0 || nums2Size == 0) {
		 return NULL;
	 }
	 sort(nums1, 0, nums1Size - 1);
	 sort(nums2, 0, nums2Size - 1);
	 int i = 0;
	 int j = 0;
	 int * ret = (int *) malloc (sizeof(int) * (nums1Size >= nums2Size ? nums2Size : nums1Size));
	 int count = 0;
	 while (i <= nums1Size - 1 && j <= nums2Size - 1) {
		 if (nums1[i] > nums2[j]) {
			 j++;
		 } else if (nums1[i] < nums2[j]) {
			 i++;
		 } else {
			 *(ret + count) = nums1[i];
			 i++;
			 j++;
			 count++;
		 }
	 }
	 *returnSize = count;
	 return ret;
 }

int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	if (matrixSize == 0 || matrixColSize[0] == 0) {
		return NULL;
	}
	*returnSize = matrixSize < matrixColSize[0] ? matrixSize : matrixColSize[0];
	int *colArr = (int *)malloc(sizeof(int) * matrixSize);
	int *rowArr = (int *)malloc(sizeof(int) * matrixColSize[0]);
	for (int i = 0; i < matrixSize; i++) {
		memcpy(rowArr, matrix[i], sizeof(int) * matrixColSize[0]);
		sort(rowArr, 0, matrixColSize[i] - 1);
		colArr[i] = rowArr[0];
	}
	for (int i = 0; i < matrixColSize[0]; i++) {
		int *col = column(matrix, matrixSize, matrixColSize, i);
		sort(col, 0, matrixSize - 1);
		rowArr[i] = col[matrixSize - 1];
		free(col);
	}
	int *ret = intersect(colArr, matrixSize, rowArr, matrixColSize[0], returnSize);
	free(rowArr);
	free(colArr);
	return ret;
}

