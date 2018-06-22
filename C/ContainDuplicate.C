// Easy Collection
/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return false;
    }
    sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
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
