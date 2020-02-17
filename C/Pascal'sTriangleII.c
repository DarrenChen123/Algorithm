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
	int *colSizes = (int *)malloc(sizeof(int) * )
	int **triangle = generate(rowIndex, int **columnSizes);
	*returnSize = rowIndex;
	int *ret = (int *)malloc(sizeof(*returnSize));
	
}