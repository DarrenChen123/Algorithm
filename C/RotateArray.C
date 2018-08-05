// Easy Collection
// Array and String
// Amazon
/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

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
