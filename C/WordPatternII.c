// Subscription
// 291. Word Pattern II
/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true
Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true
Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

bool patmatch(int *seglen, char *pat, int patlen, char *str, int slen) {
    char *buckets[26] = { 0 };
    int i, j, k;

    i = j = 0;
    while (j < slen) { // parse entire str
        if (!buckets[pat[i]]) {
            for (k = 0; k < patlen; k ++) {
                if (buckets[pat[k]] &&
                    seglen[pat[i]] == seglen[pat[k]] &&
                    !strncmp(&str[j], buckets[pat[k]], seglen[pat[k]])) {
                    return false;
                }
            }
            buckets[pat[i]] = &str[j];
        } else if (strncmp(&str[j], buckets[pat[i]], seglen[pat[i]])) {
            return false;
        }
        j += seglen[pat[i]];
        i = (i + 1) % patlen;
    }
    if (i == 0 && j == slen) return true;
    return false;
}

bool rematch(int n, int *seglen, int *skip, int *dup, char *pat, int patlen, char *str, int slen) {
    int i;
    int plen = slen;
    int nn;

    for (i = 0; i < patlen; i ++) {
        if (pat[i] != pat[n]) {
            plen -= seglen[pat[i]];
        }
    }

    if (n == 0) {
        for (i = 1; i <= plen/(dup[pat[n]] + 1); i ++) {
            seglen[pat[n]] = i;
            if (patmatch(seglen, pat, patlen, str, slen)) return true;
        }
        seglen[pat[n]] = 1;
        return false;
    }

    nn = n - 1;
    while (nn && skip[nn]) {
        nn --;
    }

    for (i = 1; nn >= 0 && i <= plen/(dup[pat[n]] + 1); i ++) {
        seglen[pat[n]] = i;
        if (rematch(nn, seglen, skip, dup, pat, patlen, str, slen)) return true;
    }
    seglen[pat[n]] = 1;

    return false;
}

bool wordPatternMatch(char* pattern, char* str) {
    int bits = 0;
    char pat[100] = { 0 };
    int skip[100] = { 0 };
    int patlen = 0, slen;
    int i, j, n;
    char x;
    int seglen[26];
    int dup[26] = { 0 };

    if ((!pattern || !*pattern) && (!str || !*str)) return true;
    if (!pattern || !*pattern || !str || !*str) return false;

    n = 0;
    for (i = 0; pattern[i]; i ++) {
        x = pattern[i] - 'a';
        pat[i] = x;
        if (!(bits & (1 << x))) {
            bits |= (1 << x);
            n ++;
        } else {
            dup[x] ++;
            skip[i] = 1;
        }
    }
    patlen = i;

    slen = strlen(str);
    if (slen < patlen) return false;

    for (i = 0; i < sizeof(seglen)/sizeof(seglen[0]); i ++) {
        seglen[i] = 1;
    }

    for (i = 0; i < patlen; i ++) {
        if (!skip[i] && rematch(i, seglen, skip, dup, pat, patlen, str, slen)) return true;
    }

    return false;
}
