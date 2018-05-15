/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
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

int findKthLargest(int* nums, int numsSize, int k) {
    if (k <= 0 || nums <= 0 || k >= nums) {
        return INT_MAX;
    }
    sort(nums, 0, numsSize - 1);
    return nums[numsSize - k];
}
