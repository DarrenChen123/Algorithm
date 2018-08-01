// Hash Table
/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/


struct HE {
	int val;
	int count;
	struct HE *next;
};

typedef struct {
    int size;
	struct HE **list;
} TwoSum;

/** Initialize your data structure here. */
TwoSum* twoSumCreate() {
	TwoSum *ts = malloc(sizeof(TwoSum));
	ts->size = 1000;
	ts->list = calloc(ts->size, sizeof(struct HE *));
	return ts;
}

/** Add the number to an internal data structure.. */
void twoSumAdd(TwoSum* obj, int number) {
    int ind = number % obj->size;
	if (ind < 0) ind = -ind;
	struct HE *p = obj->list[ind];
	while (p) {
		if (p->val == number) {
			p->count++;
			return;
		}
		p = p->next;
	}
	struct HE *he = malloc(sizeof(struct HE));
	he->val = number;
	he->count = 1;
	he->next = obj->list[ind];
	obj->list[ind] = he;
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
bool twoSumFind(TwoSum* obj, int value) {
    int i;
	for (i = 0; i < obj->size; i++) {
		struct HE *p = obj->list[i];
		while (p) {
			int tgt = value - p->val;
			if (tgt == p->val) {
				if (p->count > 1) return true;
			}
			else {
				int ind = tgt % obj->size;
				if (ind < 0) ind = -ind;
				struct HE *q = obj->list[ind];
				while (q) {
					if (q->val == tgt) return true;
					q = q->next;
				}
			}
			p = p->next;
		}
	}
	return false;
}

void twoSumFree(TwoSum* obj) {
	int i;
	for (i = 0; i < obj->size; i++) {
		struct HE *p = obj->list[i], *q;
		while (p) {
			q = p->next;
			free(p);
			p = q;
		}
	}
    free(obj->list);
	free(obj);
}

/**
 * Your TwoSum struct will be instantiated and called as such:
 * struct TwoSum* obj = twoSumCreate();
 * twoSumAdd(obj, number);
 * bool param_2 = twoSumFind(obj, value);
 * twoSumFree(obj);
 */
