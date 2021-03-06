// Medium Collection
// Binary Search
// Facebook
// Google
// LinkedIn
/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

double myPow(double x, int n) {
    if (x == 0 && n == 0) {
        return INT_MAX;
    }
    if (n == 0 && x != 0) {
        return 1;
    }
    if (x == 1) {
        return 1;
    }
    if (n == INT_MIN) {
        if (x == -1) {
            return 1;
        } else if (x * x > 1) {
            return 0;
        } else {
            return INT_MAX;
        }
    }
    double answer = 1;
    double lastPow = x;
    int exp = n > 0 ? n : -n;
    while (exp > 0) {
        if ((exp & 1) != 0) {
            answer *= lastPow;
        }
        exp >>= 1;
        lastPow *= lastPow;
    }
    return n > 0 ? answer : 1 / answer;
}
