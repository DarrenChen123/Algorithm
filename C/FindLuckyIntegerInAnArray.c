/*
Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.

Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
Example 4:

Input: arr = [5]
Output: -1
Example 5:

Input: arr = [7,7,7,7,7,7,7]
Output: 7
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500
*/

int findLucky(int* arr, int arrSize){
	int *counts = (int *)malloc(sizeof(int) * 501);
	memset(counts, 0, sizeof(int) * 501);
	for (int i = 0; i < arrSize; i++) {
		counts[arr[i]]++;
	}
	int ret = -1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == counts[arr[i]] && arr[i] > ret) {
			ret = arr[i];
		}
	}
	free(counts);
	return ret;
}
