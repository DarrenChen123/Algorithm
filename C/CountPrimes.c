/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }
    if (n == 3) {
        return 1;
    }
    if (n == 4 || n == 5) {
        return 2;
    }
    int * flag = (int *) malloc (sizeof(int) * n);
    memset(flag, 0, sizeof(int) * n);
    int count = n - 2;
    for (int i = 2; i < sqrt(n); i++) {
        if (flag[i]) {
            continue;
        }
        long current = i + i;
        while (current < n) {
            if (flag[current]) {
                current += i;
                continue;
            }
            flag[current] = 1;
            count--;
            current += i;
        }
    }
    return count;
}
