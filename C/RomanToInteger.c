// Easy Collection
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

int romanValue(char letter) {
    switch (letter) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
bool leftIsSmaller(char left, char right) {
    return romanValue(left) < romanValue(right);
}

int romanToInt(char* s) {
    if (s == NULL) {
        return 0;
    }
    int length = strlen(s);
    if (length == 0) {
        return 0;
    }
    int ret = 0;
    for (int i = 0; i < length; i++) {
        if (i == length - 1 || !leftIsSmaller(s[i], s[i + 1])) {
            ret += romanValue(s[i]);
        } else {
            ret -= romanValue(s[i]);
        }
    }
    return ret;
}
