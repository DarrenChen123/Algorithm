/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

bool isAnagram(char* s, char* t) {
    int lengthS = strlen(s);
    int lengthT = strlen(t);
    if (lengthS != lengthT) {
        return false;
    }
    int* alphabetS = (int *) malloc (sizeof(int) * 26);
    memset(alphabetS, 0, sizeof(int) * 26);
    int* alphabetT = (int *) malloc (sizeof(int) * 26);
    memset(alphabetT, 0, sizeof(int) * 26);
    for (int i = 0; i <  lengthS; i++) {
        alphabetS[s[i] - 'a']++;
        alphabetT[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabetS[i] != alphabetT[i]) {
            return false;
        }
    }
    return true;
}
