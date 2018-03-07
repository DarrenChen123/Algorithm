//Remove Duplicates from Sorted Array
/*
给定一个有序数组，你需要原地删除其中的重复内容，使每个元素只出现一次,并返回新的长度。

不要另外定义一个数组，您必须通过用 O(1) 额外内存原地修改输入的数组来做到这一点。
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
