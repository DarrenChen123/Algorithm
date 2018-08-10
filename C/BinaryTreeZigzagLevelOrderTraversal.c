// Medium Collection
// Microsoft
// LinkedIn
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode* root, int depth, int ***arr, int **columnSizes, int *returnSize) {
    if (!root) {
        return;
    }
    if (*returnSize < depth + 1) {
        *returnSize = depth + 1;
        *arr = realloc(*arr, (depth + 1) * sizeof(int *));
        (*arr)[depth] = NULL;
        *columnSizes = realloc(*columnSizes, (depth + 1) * sizeof(int));
        (*columnSizes)[depth] = 0;
    }
    (*arr)[depth] = realloc((*arr)[depth], ((*columnSizes)[depth] + 1) * sizeof(int));
    (*arr)[depth][(*columnSizes)[depth]] = root->val;
    ++(*columnSizes)[depth];

    traverse(root->left, depth + 1, arr, columnSizes, returnSize);
    traverse(root->right, depth + 1, arr, columnSizes, returnSize);
}

void reverse (int * arr, int count) {
    for (int i = 0; i < count / 2; i++) {
        arr[i] = arr[i] ^ arr[count - 1 - i];
        arr[count - 1 - i] = arr[i] ^ arr[count - 1 - i];
        arr[i] = arr[i] ^ arr[count - 1 - i];
    }
}

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    int** ret = (int **) malloc (sizeof(int *) * 1024);
    *returnSize = 0;
    traverse(root, 0, &ret, columnSizes, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        if (i % 2 == 1) {
            reverse(ret[i], (*columnSizes)[i]);
        }
    }
    return ret;
}
