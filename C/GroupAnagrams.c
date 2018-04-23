/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
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

int hash(char* s) {
    int length = strlen(s);
    int hash = 0;
    for (int i = 0; i < length; i++) {
        hash += s[i];
    }
    return hash;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    if (strsSize <= 0) {
        return NULL;
    }
    char*** ret = (char ***) malloc (sizeof(char **) * strsSize);
    *columnSizes = (int *) malloc (sizeof(int) * strsSize);
    memset(*columnSizes, 0, sizeof(int) * strsSize);
    *returnSize = 0;
    int* hashArr = (int *) malloc (sizeof(int) * strsSize);
    memset(hashArr, 0, sizeof(int) * strsSize);
    int index = 0;
    int find = 0;
    for (int i = 0; i < strsSize; i++) {
        int currentHash = hash(strs[i]);
        while(index < *returnSize) {
            if (currentHash == hashArr[index] && isAnagram(strs[i], ret[index][0])) {
                ret[index][(*columnSizes)[index]++] = strs[i];
                find = 1;
                break;
            }
            index++;
        }
        if (find == 0) {
            ret[index] = (char **) malloc(sizeof(char *) * strsSize);
            (*columnSizes)[index] = 1;
            ret[index][0] = strs[i];
            (*returnSize)++;
            hashArr[index] = hash(strs[i]);
        }
        index = 0;
        find = 0;
    }
    return ret;
}
