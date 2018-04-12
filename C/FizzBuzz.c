/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    if (n == 0) {
        return NULL;
    }
    char** ret = (char **) malloc (sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 15 == 0) {
            ret[i] = "FizzBuzz";
        } else if ((i + 1) % 3 == 0) {
            ret[i] = "Fizz";
        } else if ((i + 1) % 5 == 0) {
            ret[i] = "Buzz";
        } else {
            char * item = (char *) malloc (sizeof(char) * 2);
            sprintf(item, "%d", i + 1);
            ret[i] = item;
        }
    }
    *returnSize = n;
    return ret;
}
