// Subscription
// 248. Strobogrammatic Number III
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

Example:

Input: low = "50", high = "100"
Output: 3
Explanation: 69, 88, and 96 are three strobogrammatic numbers.
Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/

void find(char* low, char* high, char* w, int *returnSize) {
    int wSize = strlen(w);
    int lowSize = strlen(low);
    int highSize = strlen(high);
    if (wSize >= lowSize && wSize <= highSize) {
        if ((wSize == lowSize && atoi(w) < atoi(low)) || (wSize == highSize && atoi(w) > atoi(high))) {
            return;
        }
        if (!(wSize > 1 && w[0] == '0')) {
            (*returnSize)++;
        }
    }
    if (wSize + 2 > highSize) {
        return;
    }
    char* current = (char*) malloc (sizeof(wSize + 3));
    memset(current, 0, sizeof(wSize + 3));
    strcat(current, "0");
    strcat(current, w);
    strcat(current, "0");
    find (low, high, strdup(current), returnSize);
    memset(current, 0, sizeof(wSize + 3));
    strcat(current, "1");
    strcat(current, w);
    strcat(current, "1");
    find (low, high, strdup(current), returnSize);
    memset(current, 0, sizeof(wSize + 3));
    strcat(current, "6");
    strcat(current, w);
    strcat(current, "9");
    find (low, high, strdup(current), returnSize);
    memset(current, 0, sizeof(wSize + 3));
    strcat(current, "8");
    strcat(current, w);
    strcat(current, "8");
    find (low, high, strdup(current), returnSize);
    memset(current, 0, sizeof(wSize + 3));
    strcat(current, "9");
    strcat(current, w);
    strcat(current, "6");
    find (low, high, strdup(current), returnSize);
    free(current);
}

int strobogrammaticInRange(char* low, char* high) {
    int *res = (int *) malloc (sizeof(int));
    *res = 0;
    find(low, high, "", res);
    find(low, high, "0", res);
    find(low, high, "1", res);
    find(low, high, "8", res);
    int ret = *res;
    free(res);
    return ret;
}
