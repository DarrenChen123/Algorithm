// Weekly Contest 87
/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.



Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.


Note:

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/


bool isNStraightHand(int* hand, int handSize, int W) {
    if (handSize % W != 0) {
        return false;
    }
    int* map = (int*) malloc (sizeof(int) * 65536);
    memset(map, 0, sizeof(int) * 65536);
    for (int i = 0; i < handSize; i++) {
        map[hand[i] % 65536]++;
    }
    for (int i = 0; i < 65536 - W; i++) {
        while (map[i] > 0) {
            for (int j = 0; j < W; j++) {
                if (map[i + j] > 0) {
                    map[i + j]--;
                } else {
                    free(map);
                    return false;
                }
            }
        }
    }
    free(map);
    return true;
}
