// Medium Collection
// Microsoft
// Facebook
/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/

int titleToNumber(char* s) {
    int length = strlen(s);
    int ret = 0;
    for (int i = 0; i < length; i++) {
        ret += (s[i] - 'A' + 1) * pow(26, length - 1 - i);
    }
    return ret;
}
