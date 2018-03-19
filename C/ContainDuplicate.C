/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数应该返回 true。如果每个元素都不相同，则返回 false。
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
