/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

int firstUniqChar(char* s) {
    int len = strlen(s);
    int* alphabet = (int *) malloc (sizeof(int) * 26);
    memset(alphabet, 0, sizeof(int) * 26);
    for (int i = 0; i < len; i++) {
        alphabet[s[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (alphabet[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
