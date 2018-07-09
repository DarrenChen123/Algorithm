// Subscription
// Yelp
/*
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true
*/
bool canPermutePalindrome(char* s) {
    int* map = (int*) malloc (sizeof(int) * 128);
    memset(map, 0, sizeof(int) * 128);
    if (!s) {
        return true;
    }
    int length = strlen(s);
    if (length <= 0) {
        return true;
    }
    for (int i = 0; i < length; i++) {
        map[s[i]]++;
    }
    int countOfOdd = 0;
    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 == 1) {
            countOfOdd++;
            if (countOfOdd > 1) {
                return false;
            }
        }
    }
    return true;
}
