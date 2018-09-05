// Subscription
// 293. Flip Game
/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

Example:

Input: s = "++++"
Output:
[
  "--++",
  "+--+",
  "++--"
]
Note: If there is no valid move, return an empty list [].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generatePossibleNextMoves(char* s, int* returnSize) {
    if (!s) {
        return NULL;
    }
    int length = strlen(s);
    if (length < 2) {
        return NULL;
    }
    char** ret = (char**) malloc (sizeof(char*) * (length - 1));
    *returnSize = 0;
    for (int i = 0; i < length - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == '+') {
            ret[*returnSize] = strdup(s);
            ret[*returnSize][i] = ret[*returnSize][i + 1] = '-';
            (*returnSize)++;
        }
    }
    return ret;
}
