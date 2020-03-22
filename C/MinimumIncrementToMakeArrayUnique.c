/*
Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.

 

Example 1:

Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
Example 2:

Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 

Note:

0 <= A.length <= 40000
0 <= A[i] < 40000
*/

int minIncrementForUnique(int* A, int ASize){
	int* hash = (int *)malloc(sizeof(int) * 80000);
	memset(hash, 0, sizeof(int) * 80000);
	for (int i = 0;i < ASize; i++) {
		hash[A[i]]++;
	}
	int ret = 0;
	int taken = 0;
	for (int i = 0; i < 80000; i++) {
		if (hash[i] >= 2) {
			int current = hash[i] - 1;
			taken += current;
			ret -= i * current;
		} else if (taken > 0 && hash[i] == 0) {
			taken--;
			ret += i;
		}
	}
	free(hash);
	return ret;
}
