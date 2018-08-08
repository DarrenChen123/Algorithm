// Subscription
// Google
/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/

void wiggleSort(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return;
    }
    for (int i = 1; i < numsSize; i++) {
        if ((i % 2 == 0 && nums[i] > nums[i - 1]) || (i % 2 == 1 && nums[i] < nums[i - 1])) {
            int temp = nums[i - 1];
            nums[i - 1] = nums[i];
            nums[i] = temp;
        }
    }
}
