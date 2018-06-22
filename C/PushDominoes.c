// Weekly Contest 85
/*
There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.



After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state.

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Note:

0 <= N <= 10^5
String dominoes contains only 'L', 'R' and '.'
*/

char* pushDominoes(char* dominoes) {
    int length = strlen(dominoes);
    int* start = (int*) malloc (sizeof(int) * length);
    char* ret = (char*) malloc (sizeof(char) * length);
    strcpy(ret, dominoes);
    int startCount = 0;
    for (int i = 0; i < length; i++) {
        if (dominoes[i] != '.') {
            start[startCount++] = i;
        }
    }
    if (!startCount) {
        return ret;
    }

    int count = startCount;
    while (count > 0) {
        for (int i = 0; i < startCount; i++) {
            if (start[i] >= 0 && ret[start[i]] == 'L') {
                if (start[i] > 1 && ret[start[i] - 1] == 'S') {
                    ret[start[i] - 1] = '.';
                    start[i] = -1;
                    count--;
                } else if (start[i] == 0 || ret[start[i] - 1] != '.') {
                    start[i] = -1;
                    count--;
                } else {
                    ret[start[i] - 1] = 'L';
                    start[i]--;
                }
            }
            if (start[i] >= 0 && ret[start[i]] == 'R') {
                if (start[i] < length - 2 && ret[start[i] + 1] == '.' && ret[start[i] + 2] == 'L') {
                    ret[start[i] + 1] = 'S';
                    start[i] = -1;
                    count--;
                } else if (start[i] == length - 1 || ret[start[i] + 1] != '.') {
                    start[i] = -1;
                    count--;
                } else {
                    ret[start[i] + 1] = 'R';
                    start[i]++;
                }
            }
        }
    }
    return ret;
}
