// Easy Collection
// LinkedIn
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/

int rob(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int *dp = (int *) malloc (sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; i++) {
        dp[i] = nums[i] + dp[i - 2] > dp[i - 1] ? (nums[i] + dp[i - 2]) :  dp[i - 1];
    }
    return dp[numsSize - 1];
}
