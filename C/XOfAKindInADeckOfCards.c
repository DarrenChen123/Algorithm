/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
 

Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false´
Explanation: No possible partition.
Example 3:

Input: deck = [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: deck = [1,1]
Output: true
Explanation: Possible partition [1,1].
Example 5:

Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].
 

Constraints:

1 <= deck.length <= 10^4
0 <= deck[i] < 10^4
*/

int gcd(int num1, int num2) {
	int mod = num1 % num2;
	if (mod == 0) {
		return num2;
	} else {
		return gcd(num2, mod);
	}
}

bool hasGroupsSizeX(int* deck, int deckSize){
	int *counts = (int *)malloc(sizeof(int) * 10000);
	memset(counts, 0, sizeof(int) * 10000);
	for (int i = 0; i < deckSize; i++) {
		counts[deck[i]]++;
	}
	int currentGCD = 0;
	for (int i = 0; i < 10000; i++) {
		if (counts[i] > 0) {
			if (currentGCD == 0) {
				currentGCD = counts[i];
			} else {
				currentGCD = gcd(currentGCD, counts[i]);
			}
		}
	}
	free(counts);
	return currentGCD >= 2;
}