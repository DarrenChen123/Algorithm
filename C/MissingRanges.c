// Subscription
// Medium Collection
/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize) {
    char** ret = (char**) malloc (sizeof(char*) * 1024);
    int index = 0;
    if (numsSize == 0) {
        char* current = (char *) malloc (sizeof(char) * 25);
        if (lower == upper) {
            sprintf(current, "%d", lower);
        } else {
            sprintf(current, "%d->%d", lower, upper);
        }
        ret[0] = (char*) realloc(current, strlen(current));
        *returnSize = 1;
        return ret;
    }
    int* arr = (int *) malloc (sizeof(int) * 1024);
    int count = 1;
    arr[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != arr[count - 1]) {
            arr[count++] = nums[i];
        }
    }
    if (arr[0] > lower) {
        char* current = (char *) malloc (sizeof(char) * 25);
        if (arr[0] == lower + 1) {
            sprintf(current, "%d", lower);
        } else {
            sprintf(current, "%d->%d", lower, arr[0] - 1);
        }
        ret[index++] = (char *)realloc(current, strlen(current));
    }
    for (int i = 0; i < count - 1; i++) {
        if (arr[i + 1] != arr[i] + 1) {
            char* current = (char *) malloc (sizeof(char) * 25);
            if (arr[i + 1] == arr[i] + 2) {
                sprintf(current, "%d", arr[i] + 1);
            } else {
                sprintf(current, "%d->%d", arr[i] + 1, arr[i + 1] - 1);
            }
            ret[index++] = (char *)realloc(current, strlen(current));
        }
    }
    if (arr[count - 1] < upper) {
        char* current = (char *) malloc (sizeof(char) * 25);
        if (upper == arr[count - 1] + 1) {
            sprintf(current, "%d", arr[count - 1] + 1);
        } else {
            sprintf(current, "%d->%d", arr[count - 1] + 1, upper);
        }
        ret[index++] = (char *)realloc(current, strlen(current));
    }
    *returnSize = index;
    return ret;
}
