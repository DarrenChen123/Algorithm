// Medium Collection
// Yelp
// Hash Table
/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
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

typedef struct {
    int count;
    HashTable* hash;
    int* arr;
} RandomizedSet;

/** Initialize your data structure here. */
RandomizedSet* randomizedSetCreate() {
    RandomizedSet *set = (RandomizedSet*) malloc (sizeof(RandomizedSet));
    set->count = 0;
    set->hash = hash_table_new();
    set->arr = (int*) malloc (sizeof(int) * 65536);
    return set;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    char* valStr = (char*) malloc (sizeof(char) * 10);
    sprintf(valStr, "%d", val);
    if (obj && obj->count < INT_MAX) {
        if (hash_table_get(obj->hash, valStr) != -1) {
            free(valStr);
            return false;
        } else {
            int res = hash_table_put2(obj->hash, valStr, obj->count);
            obj->arr[obj->count++] = val;
            if (res == 0) {
                free(valStr);
                return true;
            } else {
                free(valStr);
                return false;
            }
        }
    } else {
        free(valStr);
        return false;
    }
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    char* valStr = (char*) malloc (sizeof(char) * 10);
    sprintf(valStr, "%d", val);
    if (obj && obj->count > 0) {
        if (hash_table_get(obj->hash, valStr) == -1) {
            free(valStr);
            return false;
        } else {
            char* newDest = (char*) malloc(sizeof(char) * 10);
            sprintf(newDest, "%d", obj->arr[obj->count - 1]);
            int temp = hash_table_get(obj->hash, valStr);
            hash_table_put2(obj->hash, newDest, temp);
            obj->arr[temp] = obj->arr[obj->count - 1];
            obj->count--;
            hash_table_put2(obj->hash, valStr, -1);
            free(newDest);
            free(valStr);
            return true;
        }
    } else {
        free(valStr);
        return false;
    }
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    if (obj->count > 0) {
        return obj->arr[rand() % (obj->count)];
    } else {
        return INT_MIN;
    }
}

void randomizedSetFree(RandomizedSet* obj) {
    hash_table_delete(obj->hash);
    free(obj->arr);
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * struct RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 * bool param_2 = randomizedSetRemove(obj, val);
 * int param_3 = randomizedSetGetRandom(obj);
 * randomizedSetFree(obj);
 */
