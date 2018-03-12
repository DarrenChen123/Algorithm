/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数应该返回 true。如果每个元素都不相同，则返回 false。
*/

bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return false;
    }
    sort(nums, numsSize, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
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
