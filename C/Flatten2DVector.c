/*
Implement an iterator to flatten a 2d vector.

Example:

Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,2,3,4,5,6].
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

struct Vector2D {
    int **vec;
    int *arr;
    int size;
    int index;
};

struct Vector2D *vector2DCreate(int** vec2d, int vec2dRowSize, int* vec2dColSizes) {
    struct Vector2D* vector = (struct Vector2D *) malloc (sizeof(struct Vector2D));
    vector->arr = vec2d;
    int size = 0;
    for (int i = 0; i < vec2dRowSize; i++) {
        size += vec2dColSizes[i];
    }
    vector->size = size;
    int* arr = (int*) malloc (sizeof(int) * size);
    int index = 0;
    for (int i = 0; i < vec2dRowSize; i++) {
        for (int j = 0; j < vec2dColSizes[i]; j++) {
            arr[index++] = vec2d[i][j];
        }
    }
    vector->arr = arr;
    vector->index = 0;
    return vector;
}

bool vector2DHasNext(struct Vector2D *iter) {
    return iter->index < iter->size;
}

int vector2DNext(struct Vector2D *iter) {
    if (vector2DHasNext(iter)) {
        return iter->arr[iter->index++];
    } else {
        return INT_MIN;
    }
}

/** Deallocates memory previously allocated for the iterator */
void vector2DFree(struct Vector2D *iter) {
    free(iter->arr);
    free(iter);
}

/**
 * Your Vector2D will be called like this:
 * struct Vector2D *i = vector2DCreate(vec2d, rowSize, colSizes);
 * while (vector2DHasNext(i)) printf("%d\n", vector2DNext(i));
 * vector2DFree(i);
 */
