/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

// O(n2)
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    int* dp = (int *) malloc (sizeof(int) * numsSize);
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[i] > (dp[j] + 1) ? dp[i] : (dp[j] + 1);
            }
        }
        ret = ret > dp[i] ? ret : dp[i];
    }
    free(dp);
    return ret;
}

// O(nlogn)
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    int* dp = (int *) malloc (sizeof(int) * numsSize);
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = ret;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (right >= ret) {
            dp[ret++] = nums[i];
        } else {
            dp[right] = nums[i];
        }
    }
    free(dp);
    return ret;
}
