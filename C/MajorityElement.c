/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

int majorityElement(int* nums, int numsSize) {
    int ret = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            ret = nums[i];
        }
        if (nums[i] == ret) {
            count++;
        } else {
            count--;
        }
    }
    return ret;
}
