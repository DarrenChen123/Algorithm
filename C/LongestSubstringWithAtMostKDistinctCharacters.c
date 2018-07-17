// Google
/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

int lengthOfLongestSubstringKDistinct(char* s, int k) {
    char* t = s;
    int ctr[256] = {}, distinct = 0, maxlen = 0;
    while (*s) {
        distinct += ctr[*s++]++ == 0;
        while (distinct > k)
            distinct -= --ctr[*t++] == 0;
        if (maxlen < s - t)
            maxlen = s - t;
    }
    return maxlen;
}
