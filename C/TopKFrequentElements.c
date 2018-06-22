// Medium Collection
/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quicksort(int *nums, int low, int high) {
    if(low < high) {
        int key = nums[low];
        int left = low;
        int right = high;

        while(left < right) {
            while(left < right && key <= nums[right])
                right--;
            nums[left] = nums[right];

            while(left < right && key >= nums[left])
                left++;
            nums[right] = nums[left];
        }
        nums[left] = key;
        quicksort(nums, low, left-1);
        quicksort(nums, left+1, high);
    }
}

void reverseSort(int* nums1, int* nums2, int numsSize) {
    int i, j;
    int sorted = 1;
    for(i = 0; i < numsSize; i++) {
        sorted = 1;
        for(j = 0; j < numsSize-1; j++) {
            if(nums1[j] < nums1[j + 1]) {
                int temp = nums1[j];
                nums1[j] = nums1[j + 1];
                nums1[j + 1] = temp;
                sorted = 0;
                temp = nums2[j];
                nums2[j] = nums2[j + 1];
                nums2[j + 1] = temp;
            }
        }
        if(sorted)
            break;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    quicksort(nums, 0, numsSize-1);
    int* statistics = (int *)malloc(sizeof(int) * numsSize);
    int i = 0;
    int sIndex = 0;
    statistics[sIndex] = 1;
    int* uniqueNums = (int *)malloc(sizeof(int) * numsSize);
    uniqueNums[sIndex] = nums[0];
    for(i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i-1])
            statistics[sIndex]++;
        else {
            statistics[++sIndex] = 1;
            uniqueNums[sIndex] = nums[i];
        }
    }
    reverseSort(statistics, uniqueNums, sIndex+1);
    *returnSize = k;
    return uniqueNums;
}
