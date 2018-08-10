// Easy Collection
// Binary Tree
// LinkedIn
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int depth = 1;
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    return depth + (leftMax > rightMax ? leftMax : rightMax);
}
