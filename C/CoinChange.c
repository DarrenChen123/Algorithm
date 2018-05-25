/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

int coinChange(int* coins, int coinsSize, int amount) {
    if (amount <= 0 || coinsSize <= 0) {
        return 0;
    }
    int* dp = (int *) malloc (sizeof(int*) * (amount + 1));
    memset(dp, -1, sizeof(int*) * (amount + 1));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j] && dp[i - coins[j]] >= 0) {
                if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }
    int ret = dp[amount];
    return ret;
}
