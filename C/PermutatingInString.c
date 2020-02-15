/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

bool checkInclusion(char * s1, char * s2){
	int length1 = strlen(s1);
	int length2 = strlen(s2);
	if (length1 > length2) {
		return false;
	}
	bool ret = false;
	int *hashes1 = (int *)malloc((sizeof(int) * 26));
	memset(hashes1, 0, sizeof(int) * 26);
	for (int i = 0;i < length1;i++) {
		hashes1[s1[i] - 'a']++;
	}
	int *hashes2 = (int *)malloc((sizeof(int) * 26));
	memset(hashes2, 0, sizeof(int) * 26);
	for (int i = 0;i <= length2 - length1;i++) {
		for (int j = 0;j < length1;j++) {
			hashes2[s2[i + j] - 'a']++;
		}
		for (int k = 0;k < 26;k++) {
			ret = true;
			if (hashes1[k] != hashes2[k]) {
				ret = false;
				break;
			}
		}
		if (ret == true) {
			break;
		} else {
			memset(hashes2, 0, sizeof(int) * 26);
		}
	}
	return ret;
}