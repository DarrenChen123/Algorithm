// Subscription
// Google
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** find(int m, int n, int *returnSize) {
    if (m == 0) {
        *returnSize = 0;
        return "";
    }
    if (m == 1) {
        *returnSize = 3;
        char** ret = (char**) malloc(sizeof(char*) * 3);
        ret[0] = "0";
        ret[1] = "1";
        ret[2] = "8";
        return ret;
    }
    if (m == 2) {
        if (m == n) {
            *returnSize = 4;
            char** ret = (char**) malloc(sizeof(char*) * 4);
            ret[0] = "11";
            ret[1] = "69";
            ret[2] = "88";
            ret[3] = "96";
            return ret;
        } else {
            *returnSize = 5;
            char** ret = (char**) malloc(sizeof(char*) * 5);
            ret[0] = "00";
            ret[1] = "11";
            ret[2] = "69";
            ret[3] = "88";
            ret[4] = "96";
            return ret;
        }
    }
    int* tReturnSize = (int*) malloc (sizeof(int));
    char** t = find(m - 2, n, tReturnSize);
    char** res = (char**) malloc (sizeof(char*) * (*tReturnSize * 5));
    *returnSize = 0;
    for (int i = 0; i < *tReturnSize; i++) {
        char* a = t[i];
        int lengA = strlen(a);
        char* current = (char*) malloc (sizeof(lengA + 3));
        memset(current, 0, sizeof(lengA + 3));
        if (m != n) {
            strcat(current, "0");
            strcat(current, a);
            strcat(current, "0");
            res[(*returnSize)++] = strdup(current);
            memset(current, 0, sizeof(lengA + 3));
        }
        strcat(current, "1");
        strcat(current, a);
        strcat(current, "1");
        res[(*returnSize)++] = strdup(current);
        memset(current, 0, sizeof(lengA + 3));
        strcat(current, "6");
        strcat(current, a);
        strcat(current, "9");
        res[(*returnSize)++] = strdup(current);
        memset(current, 0, sizeof(lengA + 3));
        strcat(current, "8");
        strcat(current, a);
        strcat(current, "8");
        res[(*returnSize)++] = strdup(current);
        memset(current, 0, sizeof(lengA + 3));
        strcat(current, "9");
        strcat(current, a);
        strcat(current, "6");
        res[(*returnSize)++] = strdup(current);
        memset(current, 0, sizeof(lengA + 3));
        free(current);
    }
    free(tReturnSize);
    return res;
}
char** findStrobogrammatic(int n, int* returnSize) {
    *returnSize = 0;
    return find(n, n, returnSize);
}
