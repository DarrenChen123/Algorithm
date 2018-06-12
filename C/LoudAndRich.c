/*
In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.

For convenience, we'll call the person with label x, simply "person x".

We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.

Also, we'll say quiet[x] = q if person x has quietness q.

Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.



Example 1:

Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation:
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but
it isn't clear if they have more money than person 0.

answer[7] = 7.
There isn't anyone who definitely has more money than person 7, so the person who definitely has
equal to or more money than person 7 is just person 7.

The other answers can be filled out with similar reasoning.
Note:

1 <= quiet.length = N <= 500
0 <= quiet[i] < N, all quiet[i] are different.
0 <= richer.length <= N * (N-1) / 2
0 <= richer[i][j] < N
richer[i][0] != richer[i][1]
richer[i]'s are all different.
The observations in richer are all logically consistent.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int searchLoudAndRich(int** richer, int richerRowSize, int* quiet, int current, int res, int* ret) {
    if (ret[current] != -1) {
        return ret[current];
    }
    int currentResult = res;
    for (int i = 0; i < richerRowSize; i++) {
        if (richer[i][1] == current) {
            currentResult = quiet[currentResult] < quiet[richer[i][0]] ? currentResult : richer[i][0];
            int newRes = searchLoudAndRich(richer, richerRowSize, quiet, richer[i][0], currentResult, ret);
            currentResult = quiet[currentResult] < quiet[newRes] ? currentResult : newRes;
        }
    }
    return currentResult;
}

int* loudAndRich(int** richer, int richerRowSize, int *richerColSizes, int* quiet, int quietSize, int* returnSize) {
    *returnSize = quietSize;
    int* ret = (int*) malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = -1;
    }
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = searchLoudAndRich(richer, richerRowSize, quiet, i, i, ret);
    }
    return ret;
}
