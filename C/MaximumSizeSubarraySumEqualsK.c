// Subscription
// Amazon
// Facebook
/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
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
    return -1;
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

int maxSubArrayLen(int* nums, int numsSize, int k) {
    if (numsSize <= 0) {
        return 0;
    }
    int sum = 0, max = 0;
    HashTable *hash = hash_table_new();
    hash_table_put2(hash, "0", 0);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        char* key = (char*) malloc (sizeof(char) * 10);
        sprintf(key, "%d", sum - k);
        if (hash_table_get(hash, key) != -1) {
            max = max > (i - hash_table_get(hash, key) + 1) ? max : (i - hash_table_get(hash, key) + 1);
        }
        sprintf(key, "%d", sum);
        if (hash_table_get(hash, key) == -1) {
            hash_table_put2(hash, key, i + 1);
        }
        free(key);
    }
    hash_table_delete(hash);
    return max;
}
