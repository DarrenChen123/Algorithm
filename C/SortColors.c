// Medium Collection
// Microsoft
/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

// two-pass
void sortColors(int* nums, int numsSize) {
    int* colorsCount = (int *) malloc (sizeof(int) * 3);
    memset(colorsCount, 0, sizeof(int) * 3);
    for (int i = 0; i < numsSize; i++) {
        colorsCount[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (i < colorsCount[0]) {
            nums[i] = 0;
        } else if (i < colorsCount[0] + colorsCount[1]) {
            nums[i] = 1;
        } else {
            nums[i] = 2;
        }
    }
    free(colorsCount);
}


// one-pass
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int i = 0;
    int j = numsSize - 1;
    while (i < numsSize && nums[i] == 0) {
        i++;
    }
    while (j >= 0 && nums[j] == 2) {
        j--;
    }
    if (i >= numsSize || j < 0) {
        return;
    }
    int k = i;
    int temp;
    while (k <= j) {
        switch (nums[k]) {
            case 0: {
                swap(&nums[i], &nums[k]);
                i++;
                k++;
                break;
            }
            case 1: {
                k++;
                break;
            }
            case 2: {
                swap(&nums[j], &nums[k]);
                j--;
                break;
            }
            default:
                break;
        }
    }
}
