// Bloomberg
/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

int thirdMax(int* nums, int numsSize) {
    long* largest = (long*) malloc (sizeof(long) * 3);
    for (int i = 0; i < 3; i++) {
        largest[i] = LONG_MIN;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > largest[0]) {
            largest[2] = largest[1];
            largest[1] = largest[0];
            largest[0] = nums[i];
        } else if (nums[i] > largest[1] && nums[i] < largest[0]) {
            largest[2] = largest[1];
            largest[1] = nums[i];
        } else if (nums[i] > largest[2] && nums[i] < largest[1]) {
            largest[2] = nums[i];
        }
    }
    int ret = largest[2] == LONG_MIN ? largest[0] : largest[2];
    free(largest);
    return ret;
}
