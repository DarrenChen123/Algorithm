/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digitsSize == 0) {
        return NULL;
    }
    int * ret = (int *) malloc(sizeof(int) * (digitsSize + 1));
    int temp = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        * (ret + i + 1) = (digits[i] + temp) % 10;
        temp = (digits[i] + temp) / 10;
    }
    if (temp == 0) {
        *returnSize = digitsSize;
        return ret + 1;
    } else {
        *ret = 1;
        *returnSize = digitsSize + 1;
        return ret;
    }
}
