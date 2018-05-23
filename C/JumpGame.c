/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

bool canJump(int* nums, int numsSize) {
    int* indexesOfZeroes = (int*) malloc (sizeof(int) * numsSize);
    int numOfZeroes = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            indexesOfZeroes[numOfZeroes++] = i;
        }
    }
    for (int i = 0; i < numOfZeroes; i++) {
        int flag = 0;
        for (int j = indexesOfZeroes[i] - 1; j >= (indexesOfZeroes[i] == 0 ? 0 : nums[indexesOfZeroes[i]]); j--) {
            if (nums[j] > indexesOfZeroes[i] - j) {
                flag = 1;
                break;
            }
        }
        if (!flag && indexesOfZeroes[i] != numsSize - 1) {
            return false;
        }
    }
    return true;
}
