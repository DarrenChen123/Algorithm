/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* generateArr(int start, int end) {
	int size = end - start + 1;
	int* ret = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		ret[i] = start + i;
	}
	return ret;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
	if (target < 3) {
		return NULL;
	}
	int **ret = (int **)malloc(sizeof(int *) * target);
	*returnColumnSizes = (int *)malloc(sizeof(int) * target);
	int left = 1;
	int right = 2;
	*returnSize = 0;
	while (left < right && left <= target / 2) {
		int sum = (left + right) * (right - left + 1) / 2;
		if (sum < target) {
			right++;
		} else if (sum > target) {
			left++;
		} else {
			(*returnColumnSizes)[*returnSize] = right - left + 1;
			ret[*returnSize] = generateArr(left, right);
			(*returnSize)++;
			left++;
			right = left + 1;
		}
	}
	return ret;
}