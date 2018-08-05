// Easy Collection
// Bloomberg
// Amazon
// Microsoft
// Facebook
// Google
// Binary Search Tree
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool BST(struct TreeNode* root, int min, int max, bool minSet, bool maxSet) {
    if (root == NULL) {
        return true;
    }
    if ((maxSet && root->val >= max) || (minSet && root->val <= min)) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (root->left && !root->right && !(root->left->val < root->val)) {
        return false;
    }
    if (root->right && !root->left && !(root->right->val > root->val)) {
        return false;
    }
    if (root->left && root->right && !(root->left->val < root->val && root->right->val > root->val)) {
        return false;
    }
    return BST(root->left, min, root->val, minSet, true) && BST(root->right, root->val, max, true, maxSet);
}
bool isValidBST(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return BST(root, INT_MIN, INT_MAX, false, false);
}
