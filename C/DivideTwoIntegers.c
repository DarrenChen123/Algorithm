// Medium Collection
/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        return INT_MAX;
    }
    if (dividend == 0) {
        return 0;
    }
    if (divisor == 1) {
        return dividend;
    }
    int positive = (dividend ^ divisor) >> 31 == 0;
    int index = 0;
    long dividendLong = (long)dividend;
    long divisorLong = (long)divisor;
    if (dividend < 0) {
        dividendLong = -(long)dividend;
    }
    if (divisor < 0) {
        divisorLong = -(long)divisor;
    }
    if (dividendLong < divisorLong) {
        return 0;
    }
    while (dividendLong >= (1 << (index + 1)) && (index + 1) <= 32 && (index + 1) < 32) {
        index++;
    }
    long ret = 0;
    while (index >= 0) {
        if (dividendLong >= (divisorLong << index)) {
            ret += ((long)1 << index);
            dividendLong -= (divisorLong << index);
        }
        index--;
    }
    if (ret >= INT_MAX) {
        if (positive) {
            return INT_MAX;
        } else {
            return INT_MIN;
        }
    }
    return positive ? (int)ret : -(int)ret;
}
