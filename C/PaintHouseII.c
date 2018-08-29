// Subscription
// 265. Paint House II
/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
Follow up:
Could you solve it in O(nk) runtime?
*/

int minCostII(int** costs, int costsRowSize, int costsColSize) {
    if (!costs || costsRowSize == 0 || !costs[0] || costsColSize == 0) {
        return 0;
    }
    int min1 = 0;
    int min2 = 0;
    int index1 = -1;
    for (int i = 0; i < costsRowSize; i++) {
        int m1 = INT_MAX;
        int m2 = m1;
        int id1 = -1;
        for (int j = 0; j < costsColSize; j++) {
            int cost = costs[i][j] + (j == index1 ? min2 : min1);
            if (cost < m1) {
                m2 = m1;
                m1 = cost;
                id1 = j;
            } else if (cost < m2) {
                m2 = cost;
            }
        }
        min1 = m1;
        min2 = m2;
        index1 = id1;
    }
    return min1;
}
