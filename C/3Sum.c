// Medium Collection
// Yelp
// Facebook
/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
	[-1, 0, 1],
	[-1, -1, 2]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	if (numsSize == 0) {
		return NULL;
	}
	int ** ret = (int **) malloc (sizeof(int *) * (numsSize * numsSize / 2));
	int i = 0, j = numsSize - 1;
	*returnSize = 0;
	while (i < j) {
		if (nums[i] + nums[j] < target) {
			i++;
		} else if (nums[i] + nums[j] > target) {
			j--;
		} else {
			int* item = (int *) malloc(sizeof(int) * 2);
			item[0] = nums[i];
			item[1] = nums[j];
			ret[(*returnSize)++] = item;
			while (i < j && nums[i] == nums[i + 1]) {
				i++;
			}
			i++;
			while (i < j && nums[j] == nums[j - 1]) {
				j--;
			}
			j--;
		}
	}
	return ret;
}

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

int** threeSum(int* nums, int numsSize, int* returnSize) {
	if (numsSize < 3) {
		return NULL;
	}
	int** ret = (int **) malloc (sizeof(int *) * (numsSize * numsSize / 2));
	*returnSize = 0;
	sort(nums, 0, numsSize - 1);
	for (int i = 0; i < numsSize - 2; i++) {
		if (i >= 1 && nums[i] == nums[i - 1]) {
			continue;
		}
		int **sum;
		int count = 0;
		if (sum = twoSum(nums + i + 1, numsSize - i - 1, -nums[i], &count)) {
			for (int j = 0; j < count; j++) {
				int* item = (int *) malloc(sizeof(int) * 3);
				item[0] = nums[i];
				item[1] = sum[j][0];
				item[2] = sum[j][1];
				ret[(*returnSize)++] = item;
			}
		}
	}

	return ret;
}
