// Subscription
// Google
/*
Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6]

Output: [1,3,2,4,5,6]

Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,3,2,4,5,6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].
*/

struct ZigzagIterator {
    int* arr;
    int arrSize;
    int currentIndex;
};

struct ZigzagIterator *zigzagIteratorCreate(int* v1, int v1Size, int* v2, int v2Size) {
    struct ZigzagIterator *iter = (struct ZigzagIterator*) malloc (sizeof(struct ZigzagIterator));
    iter->arr = (int*) malloc (sizeof(int) * (v1Size + v2Size));
    iter->arrSize = v1Size + v2Size;
    iter->currentIndex = -1;
    int index = 0;
    for (int i = 0; i < (v1Size > v2Size ? v1Size : v2Size); i++) {
        if (i < v1Size) {
            iter->arr[index++] = v1[i];
        }
        if (i < v2Size) {
            iter->arr[index++] = v2[i];
        }
    }
    return iter;
}

bool zigzagIteratorHasNext(struct ZigzagIterator *iter) {
    return iter->currentIndex < iter->arrSize - 1;
}

int zigzagIteratorNext(struct ZigzagIterator *iter) {
    return iter->arr[++(iter->currentIndex)];
}

/** Deallocates memory previously allocated for the iterator */
void zigzagIteratorFree(struct ZigzagIterator *iter) {
    free(iter->arr);
    free(iter);
}

/**
 * Your ZigzagIterator will be called like this:
 * struct ZigzagIterator *i = zigzagIteratorCreate(v1, v1Size, v2, v2Size);
 * while (zigzagIteratorHasNext(i)) printf("%d\n", zigzagIteratorNext(i));
 * zigzagIteratorFree(i);
 */
