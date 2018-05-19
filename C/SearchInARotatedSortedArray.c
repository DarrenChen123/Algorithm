/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

int find(int* nums, int begin, int end) {
    if (begin == end) {
        return begin;
    }
    if (begin + 1 == end) {
        return nums[begin] > nums[end] ? begin : end;
    }
    if (nums[(begin + end) / 2] > nums[(begin + end) / 2 - 1] && nums[(begin + end) / 2] > nums[(begin + end) / 2 + 1]) {
        return (begin + end) / 2;
    } else if (nums[(begin + end) / 2] < nums[0]) {
        return find (nums, begin, (begin + end) / 2 - 1);
    } else {
        return find (nums, (begin + end) / 2 + 1, end);
    }
}
int findPeakElement(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return -1;
    }
    if (numsSize == 1) {
        return 0;
    }
    if (numsSize == 2) {
        return nums[0] > nums[1] ? 0 : 1;
    }
    if (nums[numsSize / 2] > nums[numsSize / 2 - 1] && nums[numsSize / 2] > nums[numsSize / 2 + 1]) {
        return numsSize / 2;
    } else if (nums[numsSize / 2] < nums[0]) {
        return find (nums, 0, numsSize / 2 - 1);
    } else {
        return find (nums, numsSize / 2 + 1, numsSize - 1);
    }
}

int bSearch(int* nums, int begin, int end, int target) {
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
    if (target == nums[(begin + end) / 2]) {
        return (begin + end) / 2;
    } else if (target < nums[(begin + end) / 2]) {
        return bSearch(nums, begin, (begin + end) / 2 - 1, target);
    } else {
        return bSearch(nums, (begin + end) / 2 + 1, end, target);
    }
}

int search(int* nums, int numsSize, int target) {
    if (numsSize <= 0) {
        return -1;
    }
    if (numsSize == 1) {
        return nums[0] == target ? 0 : -1;
    }
    int peak = findPeakElement(nums, numsSize);
    if (target == nums[0]) {
        return 0;
    } else if (target == nums[peak]) {
        return peak;
    } else if (peak != numsSize - 1) {
        if (target < nums[peak + 1] || target > nums[peak]) {
            return -1;
        }
        if (target < nums[0]) {
            return bSearch(nums, peak + 1, numsSize - 1, target);
        } else {
            return bSearch(nums, 0, peak, target);
        }
    } else {
        if (target < nums[0] || target > nums[peak]) {
            return -1;
        } else {
            return bSearch(nums, 0, numsSize - 1, target);
        }
    }
}
