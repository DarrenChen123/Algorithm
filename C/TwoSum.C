// Easy Collection
// Amazon
// Microsoft
// Yelp
// Hash Table
// Facebook
// LinkedIn
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
     sort(nums, 0, numsSize - 1);
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

 void sort(int* nums, int left, int right) {
     int i, j, key;
     if (left >= right) {
         return;
     }
     i = left;
     j = right;
     key = nums[left];

     while (i < j) {
         while (nums[j] >= key && i < j) {
             j--;
         }
         nums[i] = nums[j];
         while (nums[i] <= key && i < j) {
             i++;
         }
         nums[j] = nums[i];
     }

     nums[i] = key;

     sort(nums, left, i - 1);
     sort(nums, i + 1, right);
 }
