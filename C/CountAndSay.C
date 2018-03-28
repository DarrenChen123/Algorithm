/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/

char* countAndSay(int n) {
    if (n <= 0) {
        return "";
    }
    if (n == 1) {
        return "1";
    }
    char* last = countAndSay(n - 1);
    int length = strlen(last);
    char * ret = (char *)malloc(sizeof(char) * length * 2);
    char * digits = (char *)malloc(sizeof(char) * length);
    char * counts = (char *)malloc(sizeof(char) * length);
    memset(ret, 0, sizeof(char) * length * 2);
    memset(digits, 0, sizeof(char) * length);
    memset(counts, 0, sizeof(char) * length);
    int j = 0;
    counts[j] = 1;
    digits[j] = last[0];
    for (int i = 1; i < length; i++) {
        if (last[i] == last[i - 1]) {
            counts[j]++;
        } else {
            j++;
            digits[j] = last[i];
            counts[j] = 1;
        }
    }
    int index = 0;
    for (int i = 0; i <= j; i++) {
        ret[index++] = counts[i] + '0';
        ret[index++] = digits[i];
    }
    ret[index] = '\0';
    return ret;
}
