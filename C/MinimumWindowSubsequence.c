// Subscription
// Facebook
/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input:
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/

char* minWindow(char* S, char* T) {
    int lengthS = strlen(S);
    int lengthT = strlen(T);
    int start = -1;
    int minLen = INT_MAX;
    int i = 0;
    int j = 0;
    while (i < lengthS) {
        if (S[i] == T[j]) {
            if (++j == lengthT) {
                int end = i + 1;
                while (--j >= 0) {
                    while (S[i--] != T[j]);
                }
                i++;
                j++;
                if (end - i < minLen) {
                    minLen = end - i;
                    start = i;
                }
            }
        }
        i++;
    }
    if (start == -1) {
        return "";
    }
    char* ret = (char*) malloc (sizeof(char) * (minLen + 1));
    for (int i = 0; i < minLen; i++) {
        ret[i] = S[start + i];
    }
    ret[minLen] = '\0';
    return ret;
}
