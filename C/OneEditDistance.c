// Subscription
// Google
/*
Given two strings s and t, determine if they are both one edit distance apart.

Note:

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/

bool isOneEditDistance(char* s, char* t) {
    if (!s && !t) {
        return false;
    }
    if (!s) {
        if (strlen(t) == 1) {
            return true;
        } else {
            return false;
        }
    }
    if (!t) {
        if (strlen(s) == 1) {
            return true;
        } else {
            return false;
        }
    }
    int lengthS = strlen(s);
    int lengthT = strlen(t);
    if (lengthS - lengthT < -1 || lengthS - lengthT > 1) {
        return false;
    }
    int distance = 0;
    if (lengthS == lengthT) {
        for (int i = 0; i < lengthS; i++) {
            if (s[i] != t[i]) {
                distance++;
                if (distance > 1) {
                    return false;
                }
            }
        }
        if (distance == 1) {
            return true;
        } else {
            return false;
        }
    } else {
        char* shortStr;
        char* longStr;
        int length;
        if (lengthS > lengthT) {
            longStr = s;
            shortStr = t;
            length = lengthT;
        } else {
            longStr = t;
            shortStr = s;
            length = lengthS;
        }
        if (length == 0) {
            return true;
        }
        for (int i = 0, j = 0; i < length; i++, j++) {
            if (shortStr[i] != longStr[j]) {
                j++;
                if (shortStr[i] == longStr[j]) {
                    distance++;
                    if (distance > 1) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (distance <= 1) {
            return true;
        } else {
            return false;
        }
    }
}
