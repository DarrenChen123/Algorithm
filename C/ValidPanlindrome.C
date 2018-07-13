// Easy Collection
// Microsoft
// Yelp
// Facebook
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

bool isPalindrome(char* s) {
    if (s == NULL) {
        return true;
    }
    int length = strlen(s);
    if (length == 0) {
        return true;
    }
    int i = 0, j = length - 1;
    while (i <= j) {
        if (!isalnum(s[i])) {
            i++;
        } else if (!isalnum(s[j])) {
            j--;
        } else if (tolower(s[i]) == tolower(s[j])) {
            i++;
            j--;
        } else if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
    }
    return true;
}
