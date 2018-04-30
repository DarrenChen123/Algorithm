/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // Recursive
void inorder(struct TreeNode* root, int* returnSize, int* arr) {
    if (!root) {
        return;
    }
    inorder(root->left, returnSize, arr);
    arr[(*returnSize)++] = root->val;
    inorder(root->right, returnSize, arr);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*) malloc (sizeof(int) * 1024);
    *returnSize = 0;
    inorder(root, returnSize, ret);
    return ret;
}
