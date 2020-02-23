// Array and String
// Binary Search
// Amazon
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	*returnSize = 2;
	int *ret = (int *) malloc(sizeof(int) * (*returnSize));
	int start = 0;
	int end = numbersSize - 1;
	while (start < end) {
		int sum = numbers[start] + numbers[end];
		if (sum == target) {
			ret[0] = start + 1;
			ret[1] = end + 1;
			return ret;
		} else if (sum < target) {
			start++;
		} else {
			end--;
		}
	}
	return NULL;
}