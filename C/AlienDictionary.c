// Subscription
// Bloomberg
// Amazon
// Google
/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
]

Output: ""

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

typedef struct _edge_node_t {
    int from, to;
    struct _edge_node_t *next, *prev;
} edge_node_t;

void topsort(edge_node_t *elhead, edge_node_t *luhead, char *result) {
    edge_node_t *lu, *el, *tmp;
    int c;
    int letters_deleted_this_round = 0;
    char *res = result;

    lu = luhead;
    while (luhead != NULL && elhead != NULL) {
        c = lu->from;
        el = elhead;
        while (el != NULL) {
            if (c == el->to)
                goto next_letter;
            el = el->next;
        }
        // found a letter:
        ++letters_deleted_this_round;
        //printf("found a letter %c\n", lu->from + 'a');
        *(res++) = lu->from + 'a';
        // delete all edges that start from c
        el = elhead;
        while (el != NULL) {
            if (el->from == c) {
                if (el->next != NULL)
                    el->next->prev = el->prev;
                if (el->prev != NULL)
                    el->prev->next = el->next;
                else
                    elhead = el->next;

                tmp = el;
                el = el->next;
                free(tmp);
            } else {
                el = el->next;
            }
        }

        // delete the letter from letter_used list
        if (lu->next != NULL)
            lu->next->prev = lu->prev;
        if (lu->prev != NULL)
            lu->prev->next = lu->next;
        else
            luhead = lu->next;

        tmp = lu;
        if (lu->next == NULL)
            lu = luhead;
        else
            lu = lu->next;
        free(tmp);
        goto check_loop;

    next_letter:
        if (lu->next == NULL)
            lu = luhead;
        else
            lu = lu->next;

    check_loop:
        if (lu == luhead) {
            if (0 == letters_deleted_this_round) {
                // loop detected
                result[0] = 0;
                return;
            } else {
                letters_deleted_this_round = 0;
            }
        }
    }

    // added undetermined letters
    lu = luhead;
    while (lu != NULL) {
        *(res++) = lu->from + 'a';
        lu = lu->next;
    }
}

char* alienOrder(char** words, int wordsSize) {
    char *res;
    int am[26][26];
    int letters_used[26];
    char *pi, *pj;

    memset(am, 0, sizeof(am));
    memset(letters_used, 0, sizeof(letters_used));
    res = malloc(27);
    memset(res, 0, 27);

    if (0 == wordsSize) {
        return res;
    }

    for (int i = 0; i != wordsSize-1; ++i) {
        pi = words[i];
        pj = words[i+1];
        while (*pi != 0 && *pj != 0) {
            if (*pi != *pj) {
                // error check
                if (1 == am[(int)*pj-'a'][(int)*pi-'a']) {
                    res[0] = 0;
                    return res;
                }
                //printf("found an edge: %c to %c\n", *pi, *pj);
                am[(int)*pi-'a'][(int)*pj-'a'] = 1;
                break;
            } else {
                letters_used[(int)*pi-'a'] = 1;
            }
            ++pi;
            ++pj;
        }

        for (; *pi != 0; ++pi)
            letters_used[(int)*pi-'a'] = 1;
    }
    // scan the final word for letters_used
    for (pi = words[wordsSize-1]; *pi != 0; ++pi)
        letters_used[(int)*pi - 'a'] = 1;

    // convert letters_used to a list
    edge_node_t *luhead = NULL;
    edge_node_t *p;
    for (int i = 0; i != 26; ++i) {
        if (letters_used[i] == 1) {
            p = malloc(sizeof(edge_node_t));
            p->from = i;
            p->next = luhead;
            p->prev = NULL;
            if (NULL != luhead) {
                luhead->prev = p;
            }
            luhead = p;
        }
    }

    // convert the adjacency matrix to edge list
    edge_node_t *elhead = NULL;
    for (int i = 0; i != 26; ++i) {
        for (int j = 0; j != 26; ++j) {
            if (am[i][j] == 1) {
                p = malloc(sizeof(edge_node_t));
                p->from = i;
                p->to = j;
                p->next = elhead;
                p->prev = NULL;
                if (NULL != elhead) {
                    elhead->prev = p;
                }
                elhead = p;
            }
        }
    }

    // topology sort
    topsort(elhead, luhead, res);
    return res;
}
