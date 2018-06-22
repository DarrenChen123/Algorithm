// Easy Collection
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
