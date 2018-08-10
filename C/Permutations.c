// Medium Collection
// Facebook
// LinkedIn
/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void generate(int** permute, int* nums, int numsSize, int* returnSize, int index) {
    if (index < numsSize) {
        for (int i = index; i < numsSize; i++) {
            swap(nums + index, nums + i);
            generate(permute, nums, numsSize, returnSize, index + 1);
            swap(nums + index, nums + i);
        }
    } else {
        permute[*returnSize] = (int*) malloc(sizeof(int) * numsSize);
        memcpy(permute[*returnSize], nums, sizeof(int) * numsSize);
        (*returnSize)++;
    }

}

int** permute(int* nums, int numsSize, int* returnSize) {
    int** ret = (int**) malloc (sizeof(int*) * 1024);
    *returnSize = 0;
    generate(ret, nums, numsSize, returnSize, 0);
    return ret;
}
