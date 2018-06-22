// Medium Collection
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

char* palindrome(char* s, int left, int right) {
    if (s == NULL) {
        return s;
    }
    int length = strlen(s);
    if (length == 0) {
        return s;
    }
    while (left > 0 && right < length - 1 && s[left] == s[right]) {
        left--;
        right++;
    }
    char *ret = (char *) malloc(sizeof(char) * (right - left + 2));;
    if (s[left] == s[right]) {
        memcpy(ret, &s[left], sizeof(char) * (right - left + 1));
        ret[right - left + 1] = '\0';
    } else {
        memcpy(ret, &s[left + 1], sizeof(char) * (right - left));
        ret[right - left - 1] = '\0';
    }
    return ret;
}

char* longestPalindrome(char* s) {
    if (s == NULL) {
        return s;
    }
    int totalLength = strlen(s);
    int longest = 1;
    char* ret = (char *) malloc (sizeof(char) * totalLength);
    ret[0] = s[0];
    for (int i = 0; i < 2 * totalLength - 1; i++) {
        int left = i / 2;
        int right = i % 2 == 1 ? i / 2 : i / 2 + 1;
        char * cur = palindrome(s, left, right);
        int current = strlen(cur);
        if (longest < current) {
            longest = current;
            ret = cur;
        }
    }
    return ret;
}
