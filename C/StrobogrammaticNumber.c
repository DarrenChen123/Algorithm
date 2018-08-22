// Subscription
// 246. Strobogrammatic Number

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false
*/

bool isStrobogrammatic(char* num) {
    if(!num) {
        return true;
    }
    int length = strlen(num);
    if (length == 0) {
        return true;
    }
    int i = 0;
    int j = length - 1;
    while (i < j) {
        if (num[i] == '0' && num[j] == '0' || num[i] == '1' && num[j] == '1' || num[i] == '6' && num[j] == '9' || num[i] == '8' && num[j] == '8' || num[i] == '9' && num[j] == '6') {
            i++;
            j--;
        } else {
            return false;
        }
    }
    if (i == j) {
        if (num[i] == '0' || num[i] == '1' || num[i] == '8') {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}
