// Medium Collection
// Bloomberg
// Google
// Binary Search
/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
*/

int mySqrt(int x) {
    float num = (float)x;
    float half = 0.5f * num;
    int i = *(int*)&num;
    i = 0x5f3759df - (i >> 1);
    num = *(float*)&i;
    num = num * (1.5f - (half * num * num));
    num = num * (1.5f - (half * num * num));
    num = num * (1.5f - (half * num * num));
    int ret = 1 / num;
    return ret * ret > x ? ret - 1 : ret;
}
