// Easy Collection
// Microsoft
/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.



Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

int myAtoi(char* str) {
    if (str == NULL) {
        return 0;
    }
    int length = strlen(str);
    if (length == 0) {
        return 0;
    }
    int i = 0;
    while (isspace(str[i]) && i < length - 1) {
        i++;
        if (i == length - 1) {
            return 0;
        }
    }
    long ret = 0;
    int positive = 1;
    if (str[i] == '+') {
        positive = 1;
        i++;
    } else if (str[i] == '-') {
        positive = -1;
        i++;
    }
    while (isdigit(str[i]) && i < length) {
        ret = ret * 10 + str[i] - '0';
        i++;
        if (positive == 1 && ret >= INT_MAX) {
            return INT_MAX;
        } else if (positive == -1 && ret > INT_MAX) {
            return INT_MIN;
        }
    }
    return positive * ret;
}
