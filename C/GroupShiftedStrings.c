// Subscription
// Hash Table
/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isShifted(char* s, char* t) {
    int lengthS = strlen(s);
    int lengthT = strlen(t);
    if (lengthS != lengthT) {
        return false;
    }
    int shifted = (t[0] + 26 - s[0]) % 26;
    for (int i = 0; i < lengthS; i++) {
        if ((t[i] + 26 - s[i]) % 26 != shifted) {
            return false;
        }
    }
    return true;
}

int hash(char* s) {
    int length = strlen(s);
    int hash = 0;
    for (int i = 0; i < length; i++) {
        hash += (s[i] + 26 - s[0]) % 26;
    }
    return hash;
}

char*** groupStrings(char** strings, int stringsSize, int** columnSizes, int* returnSize) {
    if (stringsSize <= 0) {
        return NULL;
    }
    char*** ret = (char ***) malloc (sizeof(char **) * stringsSize);
    *columnSizes = (int *) malloc (sizeof(int) * stringsSize);
    memset(*columnSizes, 0, sizeof(int) * stringsSize);
    *returnSize = 0;
    int* hashArr = (int *) malloc (sizeof(int) * stringsSize);
    memset(hashArr, 0, sizeof(int) * stringsSize);
    int index = 0;
    int find = 0;
    for (int i = 0; i < stringsSize; i++) {
        int currentHash = hash(strings[i]);
        while(index < *returnSize) {
            if (currentHash == hashArr[index] && isShifted(strings[i], ret[index][0])) {
                ret[index][(*columnSizes)[index]++] = strings[i];
                find = 1;
                break;
            }
            index++;
        }
        if (find == 0) {
            ret[index] = (char **) malloc(sizeof(char *) * stringsSize);
            (*columnSizes)[index] = 1;
            ret[index][0] = strings[i];
            (*returnSize)++;
            hashArr[index] = hash(strings[i]);
        }
        index = 0;
        find = 0;
    }
    return ret;
}
