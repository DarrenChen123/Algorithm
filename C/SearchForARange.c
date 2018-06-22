// Medium Collection
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int searchLeft (int* nums, int begin, int end, int target) {
    if (begin == end) {
        if (nums[begin] != target) {
            return -1;
        } else {
            return begin;
        }
    }
    if (begin + 1 == end) {
        if (nums[begin] == target) {
            return begin;
        } else if (nums[end] == target) {
            return end;
        } else {
            return -1;
        }
    }
    if (target == nums[(begin + end) / 2] && target > nums[(begin + end) / 2 - 1]) {
        return (begin + end) / 2;
    }
    if (target <= nums[(begin + end) / 2]) {
        return searchLeft(nums, begin, (begin + end) / 2 - 1, target);
    }
    if (target > nums[(begin + end) / 2]) {
        return searchLeft(nums, (begin + end) / 2 + 1, end, target);
    }
    return -1;
}

int searchRight (int* nums, int begin, int end, int target) {
    if (begin == end) {
        if (nums[begin] != target) {
            return -1;
        } else {
            return begin;
        }
    }
    if (begin + 1 == end) {
        if (nums[end] == target) {
            return end;
        } else if (nums[begin] == target) {
            return begin;
        } else {
            return -1;
        }
    }
    if (target == nums[(begin + end) / 2] && target < nums[(begin + end) / 2 + 1]) {
        return (begin + end) / 2;
    }
    if (target < nums[(begin + end) / 2]) {
        return searchRight(nums, begin, (begin + end) / 2 - 1, target);
    }
    if (target >= nums[(begin + end) / 2]) {
        return searchRight(nums, (begin + end) / 2 + 1, end, target);
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ret = (int *) malloc (sizeof(int) * *returnSize);
    if (numsSize <= 0 || target < nums[0] || target > nums[numsSize - 1]) {
        ret[0] = ret[1] = -1;
        return ret;
    }
    ret[0] = searchLeft(nums, 0, numsSize - 1, target);
    if (ret[0] == -1) {
        ret[1] = -1;
    } else {
        ret[1] = searchRight(nums, 0, numsSize - 1, target);
    }
    return ret;
}
