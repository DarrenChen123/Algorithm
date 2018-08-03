// Subscription
// Hash Table
/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

struct kv
{
    struct kv* next;
    char* key;
    char* value;
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
    kv->value = NULL;
}
/* destructor of struct kv */
static void free_kv(struct kv* kv)
{
    if (kv) {
        free(kv->key);
        kv->key = NULL;
        kv->value = NULL;
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
int hash_table_put2(HashTable* ht, char* key, char* value)
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
char* hash_table_get(HashTable* ht, char* key)
{
    int i = hash_33(key) % (1024 * 1024);
    struct kv* p = ht->table[i];
    while (p) {
        if (strcmp(key, p->key) == 0) {
            return p->value;
        }
        p = p->next;
    }
    return NULL;
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
    HashTable *hash;
    char** dictionary;
    int size;
} ValidWordAbbr;

char* abbreviate(char* str) {
    int length = strlen(str);
    char* current = (char*) malloc (sizeof(char) * sizeof(char) * (length + 1));
    sprintf(current, "%c%d%c\0", str[0], length, str[length - 1]);
    return current;
}

ValidWordAbbr* validWordAbbrCreate(char** dictionary, int dictionarySize) {
    ValidWordAbbr* obj = (ValidWordAbbr*) malloc (sizeof(ValidWordAbbr));
    obj->hash = hash_table_new();
    obj->dictionary = dictionary;
    obj->size = dictionarySize;
    for (int i = 0; i < obj->size; i++) {
        char* key = abbreviate(dictionary[i]);
        if (!hash_table_get(obj->hash, key)) {
            hash_table_put2(obj->hash, key, dictionary[i]);
        } else {
            hash_table_put2(obj->hash, key, "");
        }
    }
    return obj;
}

bool validWordAbbrIsUnique(ValidWordAbbr* obj, char* word) {
    if (strlen(word) == 1) {
        return true;
    }
    char* x = abbreviate(word);
    char* current = hash_table_get(obj->hash, x);
    if (current) {
        if (strcmp(current, word) == 0) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}

void validWordAbbrFree(ValidWordAbbr* obj) {
    hash_table_delete(obj->hash);
    free(obj);
}

/**
 * Your ValidWordAbbr struct will be instantiated and called as such:
 * struct ValidWordAbbr* obj = validWordAbbrCreate(dictionary, dictionarySize);
 * bool param_1 = validWordAbbrIsUnique(obj, word);
 * validWordAbbrFree(obj);
 */
