// Subscription
// 267. Panlindrome Permutation II
/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(int* map, int mapSize, char* cur, char* s, char** res, int* returnSize) {
    if (strlen(cur) == strlen(s)) {
        res[(*returnSize)++] = cur;
    }
    for (int i = 0; i < mapSize; i++) {
        if (map[i] > 0) {
            map[i] -= 2;
            char *new = (char*) malloc (sizeof(char) * (strlen(cur) + 3));
            sprintf(new, "%c%s%c\0", i, cur, i);
            dfs(map, mapSize, new, s, res, returnSize);
            map[i] += 2;
        }
    }
}

char** generatePalindromes(char* s, int* returnSize) {
    char** res = (char**) malloc (sizeof(char*) * 1024);
    int* map = (int*) malloc (sizeof(int) * 256);
    memset(map, 0, sizeof(int) * 256);
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < strlen(s); i++) {
        map[s[i]]++;
        min = min < s[i] ? min : s[i];
        max = max > s[i] ? max : s[i];
    }
    int count = 0;
    int oddIndex = 0;
    for (int i = min; i <= max; i++) {
        if (count == 0 && map[i] % 2 == 1) {
            oddIndex = i;
            count++;
        } else if (map[i] % 2 == 1) {
            return res;
        }
    }
    char* cur = (char*) malloc (sizeof(char) * 1024);
    memset(cur, 0, sizeof(char) * 1024);
    if (count == 1) {
        sprintf(cur, "%s%c\0", cur, oddIndex);
        map[oddIndex]--;
    }
    dfs(map, 256, cur, s, res, returnSize);
    free(cur);
    free(map);
    return res;
}
