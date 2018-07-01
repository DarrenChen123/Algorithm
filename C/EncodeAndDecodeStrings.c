// Subscription
// Bloomberg
/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

/** Encodes a list of strings to a single string */
char* encode(char** strs, int strsSize) {
    char* ret = (char*) malloc (sizeof(char) * 65536);
    int index = 0;
    for (int i = 0; i < strsSize; i++) {
        int length = strlen(strs[i]) + 1;
        for (int j = 0; j < length; j++) {
            sprintf(ret + index, "%03d", strs[i][j]);
            index += 3;
        }
    }
    ret[index] = '\0';
    return ret;
}

/**
 * Decodes a single string to a list of strings.
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** decode(char* s, int* returnSize) {
    int length = strlen(s);
    *returnSize = 0;
    char** ret = (char**) malloc (sizeof(char*) * 65536);
    int currentIndex = 0;
    ret[*returnSize] = (char*) malloc (sizeof(char) * length);
    for (int i = 0; i < length; i += 3) {
        char* current = (char*) malloc (sizeof(char) * 3);
        strncpy(current, s + i, 3);
        char temp = atoi(current);
        free(current);
        if (temp != '\0') {
            ret[*returnSize][currentIndex++] = temp;
        } else {
            ret[*returnSize][currentIndex] = '\0';
            (*returnSize)++;
            ret[*returnSize] = (char*) malloc (sizeof(char) * length);
            currentIndex = 0;
        }
    }
    return ret;
}

// Your functions will be called as such:
// char* s = encode(strs, strsSize);
// decode(s, &returnSize);
