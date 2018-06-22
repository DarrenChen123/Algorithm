// Easy Collection
//Remove Duplicates from Sorted Array
/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1)
        return numsSize;
    int i = 0;
    int j = 0;
    while (i < numsSize && j < numsSize) {
        if (nums[i] == nums[j]) {
            j++;
        } else {
            nums[++i] = nums[j++];
        }
    }
    return i + 1;
}
