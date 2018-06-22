// Easy Collection

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

int reverse(int x) {
    long ret = 0;
    int positive = x > 0 ? 1 : 0;
    int temp = positive ? x : -x;
    while (temp > 0) {
        ret = ret * 10 + temp % 10;
        temp /= 10;
    }
    if (ret >= ((long)1 << 31)) {
        return 0;
    } else {
        return positive ? (int)ret : (int)(-ret);
    }
}
