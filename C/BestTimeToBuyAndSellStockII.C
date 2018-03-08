/*
假设有一个数组，它的第 i 个元素是一个给定的股票在第 i 天的价格。

设计一个算法来找到最大的利润。你可以完成尽可能多的交易（多次买卖股票）。然而，你不能同时参与多个交易（你必须在再次购买前出售股票）。
*/

int maxProfit(int* prices, int pricesSize) {
    if (prices == NULL || pricesSize < 1) {
        return 0;
    }

    int bought = prices[0];
    int profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (bought < prices[i]) {
            profit += prices[i] - bought;
            bought = prices[i];
        } else {
            bought = prices[i];
        }
    }
    return profit;
}
