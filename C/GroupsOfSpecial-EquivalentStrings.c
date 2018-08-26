// Weekly Contest 99
/*
You are given an array A of strings.

Two strings S and T are special-equivalent if after any number of moves, S == T.

A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].

Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.

Return the number of groups of special-equivalent strings from A.



Example 1:

Input: ["a","b","c","a","c","c"]
Output: 3
Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
Example 2:

Input: ["aa","bb","ab","ba"]
Output: 4
Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
Example 3:

Input: ["abc","acb","bac","bca","cab","cba"]
Output: 3
Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
Example 4:

Input: ["abcd","cdab","adcb","cbad"]
Output: 1
Explanation: 1 group ["abcd","cdab","adcb","cbad"]


Note:

1 <= A.length <= 1000
1 <= A[i].length <= 20
All A[i] have the same length.
All A[i] consist of only lowercase letters.
*/

bool isEquivGroup(char* s, char* t) {
    int lengthS = strlen(s);
    int lengthT = strlen(t);
    if (lengthS != lengthT) {
        return false;
    }
    int* alphabetSOdd = (int*) malloc (sizeof(int) * 26);
    memset(alphabetSOdd, 0, sizeof(int) * 26);
    int* alphabetSEven = (int*) malloc (sizeof(int) * 26);
    memset(alphabetSEven, 0, sizeof(int) * 26);
    int* alphabetTOdd = (int*) malloc (sizeof(int) * 26);
    memset(alphabetTOdd, 0, sizeof(int) * 26);
    int* alphabetTEven = (int*) malloc (sizeof(int) * 26);
    memset(alphabetTEven, 0, sizeof(int) * 26);
    for (int i = 0; i < lengthS; i++) {
        if (i % 2 == 0) {
            alphabetSOdd[s[i] - 'a']++;
            alphabetTOdd[t[i] - 'a']++;
        } else {
            alphabetSEven[s[i] - 'a']++;
            alphabetTEven[t[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (alphabetSOdd[i] != alphabetTOdd[i] || alphabetSEven[i] != alphabetTEven[i]) {
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

int numSpecialEquivGroups(char** A, int ASize) {
    if (ASize <= 0) {
        return 0;
    }
    char*** groups = (char ***) malloc (sizeof(char**) * ASize);
    int* groupSizes = (int*) malloc (sizeof(int) * ASize);
    memset(groupSizes, 0, sizeof(int) * ASize);
    int ret = 0;
    int* hashArr = (int*) malloc (sizeof(int) * ASize);
    memset(hashArr, 0, sizeof(int) * ASize);
    int index = 0;
    int find = 0;
    for (int i = 0; i < ASize; i++) {
        int currentHash = hash(A[i]);
        while (index < ret) {
            if (currentHash == hashArr[index] && isEquivGroup(A[i], groups[index][0])) {
                groups[index][groupSizes[index]++] = A[i];
                find = 1;
                break;
            }
            index++;
        }
        if (find == 0) {
            groups[index] = (char **) malloc (sizeof(char*) * ASize);
            groupSizes[index] = 1;
            groups[index][0] = A[i];
            ret++;
            hashArr[index] = hash(A[i]);
        }
        index = 0;
        find = 0;
    }
    free(hashArr);
    free(groupSizes);
    return ret;
}
