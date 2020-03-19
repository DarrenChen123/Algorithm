/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/
int longestPalindrome(char * s){
	int* chars = (int *)malloc(sizeof(int) * 52);
	memset(chars, 0, sizeof(int) * 52);
	int length = strlen(s);
	if (length == 0) {
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			chars[s[i] - 'a']++;
		} else if (s[i] >= 'A' && s[i] <= 'Z') {
			chars[s[i] - 'A' + 26]++;
		}
	}
	int count = 0;
	int singleUsed = false;
	for (int i = 0; i < 52; i++) {
		if (chars[i] % 2 == 0) {
			count += chars[i];
		} else if (!singleUsed) {
			count += chars[i];
			singleUsed = true;
		} else {
			count += chars[i] - 1;
		}
	}
	free(chars);
	return count;
}