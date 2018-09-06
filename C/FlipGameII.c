// Subscription
// 294. Flip Game II
/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Follow up:
Derive your algorithm's runtime complexity.
*/

bool helper(char *s, int player) {
    if (!s) {
        return false;
    }
    int length = strlen(s);
    if (!length) {
        return false;
    }
    if (player == 1) {
        for (int i = 0; i < length - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool res = helper(s, 2);
                s[i] = s[i + 1] = '+';
                if (res) {
                    return true;
                }
            }
        }
        return false;
    } else {
        for (int i = 0; i < length - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool res = !helper(s, 1);
                s[i] = s[i + 1] = '+';
                if (res) {
                    return false;
                }
            }
        }
        return true;
    }
}

bool canWin(char* s) {
    return helper(s, 1);
}
