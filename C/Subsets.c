/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    *returnSize = 1 << numsSize;
    int** ret = (int**) malloc (sizeof(int *) * *returnSize);
    *columnSizes = (int*) malloc (sizeof(int) * *returnSize);
    memset(*columnSizes, 0, sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        int* current = (int *) malloc (sizeof(int) * numsSize);
        int size = 0;
        for (int j = 0; j < numsSize;  j++) {
            if (i & (1 << j)) {
                current[size++] = nums[j];
            }
        }
        ret[i] = current;
        (*columnSizes)[i] = size;
    }
    return ret;
}
