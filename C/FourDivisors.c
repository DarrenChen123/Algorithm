/*
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
 

Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5


*/

int sumFourDivisors(int* nums, int numsSize){
	int totalSum = 0;
	for (int i = 0; i < numsSize; i++) {
		int count = 0;
		int sum = 0;
		bool overFour = false;
		for (int j = 1; j <= nums[i] / 2; j++) {
			if (nums[i] % j == 0) {
				count++;
				sum += j;
				if (count == 4) {
					overFour = true;
					break;
				}
			}
		}
		if (!overFour && count == 3) {
			sum += nums[i];
			totalSum += sum;
		}
	}
	return totalSum;
}