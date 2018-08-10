// Easy Collection
// Bloomberg
// Amazon
// Microsoft
// Binary Tree
// Facebook
// LinkedIn
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    int** ret = (int **) malloc (sizeof(int *) * 1024);
    *returnSize = 0;
    traverse(root, 0, &ret, columnSizes, returnSize);

    return ret;
}
