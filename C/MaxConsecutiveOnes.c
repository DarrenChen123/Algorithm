// Google
// Array and String
/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int ret = 0;
    int current = 0;
    for (int i = 0;i < numsSize;i++) {
        if (nums[i] == 1) {
            current++;
        } else {
            if (ret < current) {
                ret = current;
            }
            current = 0;
        }
    }
    if (ret < current) {
        ret = current;
    }
    
    return ret;
}