// Easy Collection
// Bloomberg
// Amazon
// Microsoft
/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
char* reverseString(char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    char * ret = (char *) malloc (sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        ret[length - 1 - i] = s[i];
    }
    ret[length] = '\0';
    return ret;
}
