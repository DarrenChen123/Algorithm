// Subscription
// Google
/*
Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortTransformedArray(int* nums, int numsSize, int a, int b, int c, int* returnSize) {
    int i = 0;
    int j = numsSize - 1;
    *returnSize = numsSize;
    int* res = (int*) malloc (sizeof(int) * (*returnSize));
    int index = a >= 0 ? numsSize - 1 : 0;
    while (i <= j) {
        int res1 = cal(nums[i], a, b, c);
        int res2 = cal(nums[j], a, b, c);
        if (a >= 0) {
            if (res1 >= res2) {
                res[index--] = res1;
                i++;
            } else {
                res[index--] = res2;
                j--;
            }
        } else {
            if (res1 >= res2) {
                res[index++] = res2;
                j--;
            } else {
                res[index++] = res1;
                i++;
            }
        }
    }
    return res;
}

int cal(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
}
