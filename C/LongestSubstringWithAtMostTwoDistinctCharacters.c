// Subscription
// 159. Longest Substring with At Most Two Distinct Characters
/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

int lengthOfLongestSubstringTwoDistinct(char* s) {
    char* t = s;
    int ctr[256] = {}, distinct = 0, maxlen = 0;
    while (*s) {
        distinct += ctr[*s++]++ == 0;
        while (distinct > 2)
            distinct -= --ctr[*t++] == 0;
        if (maxlen < s - t)
            maxlen = s - t;
    }
    return maxlen;
}
