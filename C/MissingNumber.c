// Easy Collection
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

int missingNumber(int* nums, int numsSize) {
	char* key = (char *) malloc (sizeof(char) * numsSize);
	memset(key, 0, sizeof(char) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		key[nums[i] / 4] |= 1 << (nums[i] % 4);
	}
	for (int i = 0; i < numsSize; i++) {
		if ((key[i / 4] >> (i % 4) & 1) == 0) {
			return i;
		}
	}
	free(key);
	return numsSize;
}
