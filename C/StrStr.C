/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

int strStr(char* haystack, char* needle) {
    if (needle == NULL) {
        return 0;
    }
    if (haystack == NULL) {
        return -1;
    }
    int length1 = strlen(haystack);
    int length2 = strlen(needle);
    if (length2 == 0) {
        return 0;
    }
    if (length1 == 0) {
        return -1;
    }
    if (length1 < length2) {
        return -1;
    }
    int i = 0, j = 0;
    while (i <= length1) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            if (j == length2) {
                return i - j;
            }
        } else if (j != 0) {
            i = i - j + 1;
            j = 0;
        } else {
            i++;
            if (i >= length1 - length2) {
                return -1;
            }
        }
    }
    return -1;
}
