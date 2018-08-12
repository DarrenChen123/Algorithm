// Weekly Contest 97
/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words.

You may return the list in any order.



Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]


Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct kv
{
    struct kv* next;
    char* key;
    int value;
};

/* HashTable */
typedef struct
{
    struct kv ** table;
} HashTable;

/* constructor of struct kv */
static void init_kv(struct kv* kv)
{
    kv->next = NULL;
    kv->key = NULL;
    kv->value = -1;
}
/* destructor of struct kv */
static void free_kv(struct kv* kv)
{
    if (kv) {
        free(kv->key);
        kv->key = NULL;
        free(kv);
    }
}
/* the classic Times33 hash function */
static unsigned int hash_33(char* key)
{
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + hash + *key++;
    }
    return hash;
}

/* new a HashTable instance */
HashTable* hash_table_new()
{
    HashTable* ht = malloc(sizeof(HashTable));
    if (NULL == ht) {
        hash_table_delete(ht);
        return NULL;
    }
    ht->table = malloc(sizeof(struct kv*) * 1024 * 1024);
    if (NULL == ht->table) {
        hash_table_delete(ht);
        return NULL;
    }
    memset(ht->table, 0, sizeof(struct kv*) * 1024 * 1024);

    return ht;
}
/* delete a HashTable instance */
void hash_table_delete(HashTable* ht)
{
    if (ht) {
        if (ht->table) {
            int i = 0;
            for (i = 0; i < 1024 * 1024; i++) {
                struct kv* p = ht->table[i];
                struct kv* q = NULL;
                while (p) {
                    q = p->next;
                    free_kv(p);
                    p = q;
                }
            }
            free(ht->table);
            ht->table = NULL;
        }
        free(ht);
    }
}

/* insert or update a value indexed by key */
int hash_table_put2(HashTable* ht, char* key, int value)
{
    int i = hash_33(key) % (1024 * 1024);
    struct kv* p = ht->table[i];
    struct kv* prep = p;

    while (p) { /* if key is already stroed, update its value */
        if (strcmp(p->key, key) == 0) {
            p->value = value;
            break;
        }
        prep = p;
        p = p->next;
    }

    if (p == NULL) {/* if key has not been stored, then add it */
        char* kstr = malloc(strlen(key) + 1);
        if (kstr == NULL) {
            return -1;
        }
        struct kv * kv = malloc(sizeof(struct kv));
        if (NULL == kv) {
            free(kstr);
            kstr = NULL;
            return -1;
        }
        init_kv(kv);
        kv->next = NULL;
        strcpy(kstr, key);
        kv->key = kstr;
        kv->value = value;

        if (prep == NULL) {
            ht->table[i] = kv;
        }
        else {
            prep->next = kv;
        }
    }
    return 0;
}

/* get a value indexed by key */
int hash_table_get(HashTable* ht, char* key)
{
    int i = hash_33(key) % (1024 * 1024);
    struct kv* p = ht->table[i];
    while (p) {
        if (strcmp(key, p->key) == 0) {
            return p->value;
        }
        p = p->next;
    }
    return 0;
}

/* remove a value indexed by key */
void hash_table_rm(HashTable* ht, char* key)
{
    int i = hash_33(key) % (1024 * 1024);

    struct kv* p = ht->table[i];
    struct kv* prep = p;
    while (p) {
        if (strcmp(key, p->key) == 0) {
            free_kv(p);
            if (p == prep) {
                ht->table[i] = NULL;
            }
            else {
                prep->next = p->next;
            }
        }
        prep = p;
        p = p->next;
    }
}

char** uncommonFromSentences(char* A, char* B, int* returnSize) {
    HashTable* hash = hash_table_new();
    int lengA = strlen(A);
    int lengB = strlen(B);
    char** arrA = (char**) malloc (sizeof(char*) * lengA);
    char** arrB = (char**) malloc (sizeof(char*) * lengB);
    int arrASize = 0;
    int arrBSize = 0;

    char* current = strtok(A, " ");
    while (current != NULL) {
        arrA[arrASize++] = strdup(current);
        hash_table_put2(hash, current, hash_table_get(hash, current) + 1);
        current = strtok(NULL, " ");
    }
    current = strtok(B, " ");
    while (current != NULL) {
        arrB[arrBSize++] = strdup(current);
        hash_table_put2(hash, current, hash_table_get(hash, current) + 1);
        current = strtok(NULL, " ");
    }
    char** ret = (char**) malloc (sizeof(char*) * (arrASize + arrBSize));
    *returnSize = 0;
    for (int i = 0; i < arrASize; i++) {
        if (hash_table_get(hash, arrA[i]) == 1) {
            ret[(*returnSize)++] = arrA[i];
        }
    }
    for (int i = 0; i < arrBSize; i++) {
        if (hash_table_get(hash, arrB[i]) == 1) {
            ret[(*returnSize)++] = arrB[i];
        }
    }
    free(arrA);
    free(arrB);
    hash_table_delete(hash);
    return realloc(ret, sizeof(char*) * (*returnSize));
}
