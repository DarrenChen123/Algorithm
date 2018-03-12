bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return false;
    }
    sort(nums, numsSize, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
