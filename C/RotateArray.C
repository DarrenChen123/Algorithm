/*
将包含 n 个元素的数组向右旋转 k 步。

例如，如果  n = 7 ,  k = 3，给定数组  [1,2,3,4,5,6,7]  ，向右旋转后的结果为 [5,6,7,1,2,3,4]。

注意:

尽可能找到更多的解决方案，这里最少有三种不同的方法解决这个问题。

[显示提示]

提示:

要求空间复杂度为 O(1)

关联的问题: 反转字符串中的单词 II
*/

//解法1：

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (numsSize > 0 && k <= numsSize && k > 0) {
        reverse(nums, numsSize - k);
        reverse(nums + numsSize - k, k);
        reverse(nums, numsSize);
    }
}

void reverse(int * nums, int numsSize) {
    for (int i = 0; i < numsSize / 2; i++) {
        nums[i] = nums[i] ^ nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = nums[i] ^ nums[numsSize - 1 - i];
        nums[i] = nums[i] ^ nums[numsSize - 1 - i];
    }
}

//解法2：

void rotate(int* nums, int numsSize, int k) {
    int temp[numsSize];
    for (int y = 0; y < numsSize; y++){
        temp[(y + k + numsSize) % numsSize] = nums[y];
    }
    for (int i = 0; i < numsSize; i++){
        nums[i] = temp[i];
      }
}

//解法3

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    for(int i = 0; i < k; i++){
        int tmp = nums[numsSize - 1];
        for(int j = numsSize - 1; j > 0; j--){
            nums[j] = nums[j-1];
        }
        nums[0] = tmp;
    }
}
