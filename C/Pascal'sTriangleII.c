// Array and String
// Amazon
/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
	int *last = (int *)malloc(sizeof(int) * (*returnSize));
	int *current = (int *)malloc(sizeof(int) * (*returnSize));
    memset(last, 0, sizeof(int) * (*returnSize));
    memset(current, 0, sizeof(int) * (*returnSize));
	if (rowIndex < 0) {
		return NULL;
	}
	for (int i = 0;i <= rowIndex;i++) {
		if (i == 0) {
			last[0] = 1;
			current[0] = 1;
		} else {
            memcpy(last, current, sizeof(int) * i);
			for (int j = 0;j <= i;j++) {
				if (j == 0) {
					current[j] = 1;
				} else {
					current[j] = last[j - 1] + last[j];
				}
			}
		}
	}
    free(last);
	return current;
}