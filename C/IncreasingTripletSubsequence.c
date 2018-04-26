/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }
    int leftFound = 0;
    int rightFound = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                leftFound = 1;
                break;
            }
        }
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] > nums[i]) {
                rightFound = 1;
                break;
            }
        }
        if (leftFound && rightFound) {
            return true;
        } else {
            leftFound = 0;
            rightFound = 0;
        }
    }
    return false;
}
