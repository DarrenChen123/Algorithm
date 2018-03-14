/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (nums1Size == 0 || nums2Size == 0) {
        return NULL;
    }
    sort(nums1, nums1Size, 0, nums1Size - 1);
    sort(nums2, nums2Size, 0, nums2Size - 1);
    int i = 0;
    int j = 0;
    int * ret = (int *) malloc (sizeof(int) * (nums1Size >= nums2Size ? nums2Size : nums1Size));
    int count = 0;
    while (i <= nums1Size - 1 && j <= nums2Size - 1) {
        if (nums1[i] > nums2[j]) {
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            *(ret + count) = nums1[i];
            i++;
            j++;
            count++;
        }
    }
    *returnSize = count;
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
