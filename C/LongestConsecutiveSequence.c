// Yelp
// Facebook
// Google
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

int findLengthOfLCIS(int* nums, int numsSize){
	if (numsSize <= 1) {
		return numsSize;
	}
	int ret = 1;
	int current = 1;
	for (int i = 1;i < numsSize;i++) {
		if (nums[i] > nums[i - 1]) {
			current++;
		} else {
			current = 1;
		}
		ret = ret > current ? ret : current;
	}
	return ret;
	
}
