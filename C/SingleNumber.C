/*
给定一个整数数组，除了某个元素外其余元素均出现两次。请找出这个只出现一次的元素。



备注：

你的算法应该是一个线性时间复杂度。 你可以不用额外空间来实现它吗？
*/
int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        ret ^= nums[i];
    }
    return ret;
}
