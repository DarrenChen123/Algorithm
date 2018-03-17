/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return NULL;
    }
    int * copy = (int *) malloc (sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        *(copy + i) = nums[i];
    }
    sort(nums, numsSize, 0, numsSize - 1);
    int * ret = (int *) malloc (sizeof(int) * 2);
    int i = 0, j = numsSize - 1, flag = 1;
    int answer1 = 0, answer2 = 0;
    while (i < j) {
        if (nums[i] + nums[j] < target) {
            i++;
        } else if (nums[i] + nums[j] > target) {
            j--;
        } else {
            answer1 = nums[i];
            answer2 = nums[j];
            break;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (copy[i] == answer1 && flag == 1) {
            *ret = i;
            flag = 0;
        }
        if (copy[i] == answer2) {
            *(ret + 1) = i;
        }
    }
    free(copy);
    return ret;
}

void sort(int* nums, int numsSize, int left, int right) {
    int i, j, t, temp;
    if (left > right) {
        return;
    }
    temp = nums[left];
    i = left;
    j = right;
    while (i != j) {
        while (nums[j] >= temp && i < j) {
            j--;
        }
        while (nums[i] <= temp && i < j) {
            i++;
        }
        if (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }

    nums[left] = nums[i];
    nums[i] = temp;

    sort(nums, numsSize, left, i - 1);
    sort(nums, numsSize, i + 1, right);
}
