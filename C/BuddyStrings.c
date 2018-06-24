// Weekly Contest 90
/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/

bool buddyStrings(char* A, char* B) {
    int lengthA = strlen(A);
    int lengthB = strlen(B);
    if (lengthA != lengthB) {
        return false;
    }
    if (lengthA < 2) {
        return false;
    }
    int differCount = 0;
    int* differIndexes = (int*) malloc(sizeof(int) * 2);
    char* map = (char*) malloc (sizeof(char) * 26);
    memset(map, 0, sizeof(char) * 26);
    int hasSameChar = 0;
    for (int i = 0; i < lengthA; i++) {
        if (map[A[i] - 'a'] == 1) {
            hasSameChar = 1;
        } else {
            map[A[i] - 'a'] = 1;
        }
        if (A[i] != B[i]) {
            if (differCount < 2) {
                differIndexes[differCount++] = i;
            } else {
                return false;
            }
        }
        if (differCount > 2) {
            return false;
        }
    }
    switch (differCount) {
        case 0:
            return hasSameChar;
        case 1:
            return false;
        case 2:
            return A[differIndexes[0]] == B[differIndexes[1]] && A[differIndexes[1]] == B[differIndexes[0]];
        default:
            return false;
    }
}
