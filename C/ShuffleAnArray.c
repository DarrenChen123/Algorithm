// Easy Collection
/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

typedef struct {
    int* origin;
    int* current;
    int size;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution * solution = (Solution *) malloc(sizeof(Solution));
    int * origin = (int *) malloc (sizeof(int) * size);
    int * current = (int *) malloc (sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        current[i] = origin[i] = nums[i];
    }
    solution->size = size;
    solution->origin = origin;
    solution->current = current;
    return solution;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    *returnSize = obj->size;
    for (int i = 0; i < obj->size; i++) {
        obj->current[i] = obj->origin[i];
    }
    return obj->current;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    *returnSize = obj->size;
    if (obj->size == 0) {
        obj->current = NULL;
        return obj->current;
    }
    for (int i = 0; i < obj->size; i++) {
        int t = i + rand() % (obj->size - i);
        int temp = obj->current[t];
        obj->current[t] = obj->current[i];
        obj->current[i] = temp;
    }
    return obj->current;
}

void solutionFree(Solution* obj) {
    free(obj->origin);
    free(obj->current);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */
