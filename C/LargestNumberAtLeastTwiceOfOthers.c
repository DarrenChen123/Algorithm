// Array and String
/*
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.


Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.


Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
*/

int dominantIndex(int* nums, int numsSize){
	if (numsSize < 1) {
		return -1;
	} else if (numsSize == 1) {
		if (nums[0] >= 0) {
			return 0;
		} else {
			return -1;
		}
	}
	int indexOfMax = 0;
	int indexOfSecondMax = -1;
	for (int i = 1;i < numsSize;i++) {
		if (nums[i] > nums[indexOfMax]) {
			indexOfSecondMax = indexOfMax;
			indexOfMax = i;
		} else if (indexOfSecondMax == -1 || nums[i] >= nums[indexOfSecondMax]) {
			indexOfSecondMax = i;
		}
	}
	if (indexOfSecondMax == -1) {
		return indexOfMax;
	}
	if (nums[indexOfMax] >= nums[indexOfSecondMax] * 2) {
		return indexOfMax;
	} else {
		return -1;
	}
}