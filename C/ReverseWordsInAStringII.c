// Subscription
// Bloomberg
// Amazon
/*
Given an input string , reverse the string word by word.

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note:

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/


//先翻转每个单词，再反转字符串
void reverse(char* str, int size) {
    for (int i = 0; i < size / 2; i++) {
        char temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
}
void reverseWords(char* str, int strSize) {
    if (strSize <= 1) {
        return;
    }
    reverse(str, strSize);
    int start = 0;
    int length = 0;
    for (int i = 0; i < strSize; i++) {
        if (str[i] == ' ' && length > 0) {
            reverse(str + start, length);
            if (i + 1 < strSize) {
                start = i + 1;
            }
            length = 0;
        } else if (str[i] != ' ') {
            length++;
        } else if (str[i] == ' ') {
            if (i + 1 < strSize) {
                start = i + 1;
            }
        }
        if (i == strSize - 1) {
            reverse(str + start, length);
        }
    }

}
