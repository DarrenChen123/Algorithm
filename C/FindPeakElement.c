/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
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
    } else if (nums[(begin + end) / 2] < nums[(begin + end) / 2 - 1]) {
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
    } else if (nums[numsSize / 2] < nums[numsSize / 2 - 1]) {
        return find (nums, 0, numsSize / 2 - 1);
    } else {
        return find (nums, numsSize / 2 + 1, numsSize - 1);
    }
}
