// Easy Collection
// Google
/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

// Recursion
bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    if (n == 1) {
        return true;
    } else if (n % 3 != 0) {
        return false;
    } else {
        return isPowerOfThree(n / 3);
    }
}


// Non-recursion
bool isPowerOfThree(int n) {
    return n > 0 && ((int)pow(3, (int)(log (INT_MAX) / log(3)))) % n == 0;
}
