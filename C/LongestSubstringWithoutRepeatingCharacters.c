// Medium Collection
// Yelp
// Hash Table
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
int lengthOfLongestSubstring(char* s) {
    int ret = 0;
    int currentLen = 0;
    int length = strlen(s);
    int* keys = (int *) malloc (sizeof(int) * 128);
    memset(keys, -1, sizeof(int) * 128);
    int start = 0;
    for (int i = 0; i < length; i++) {
        if (keys[s[i]] < start) {
            currentLen++;
        } else {
            start = keys[s[i]] + 1;
            ret = ret > currentLen ? ret : currentLen;
            currentLen = i - start + 1;
        }
        keys[s[i]] = i;
    }
    ret = ret > currentLen ? ret : currentLen;
    return ret;
}
