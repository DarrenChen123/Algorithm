// Subscription
// Amazon
// Google
/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int closestValue(struct TreeNode* root, double target) {
    if (!root) {
        return INT_MIN;
    }
    int val = root->val;
    while (root) {
        if (target < root->val) {
            val = fabs(val - target) < fabs(root->val - target) ? val : root->val;
            root = root->left;
        } else if (target > root->val) {
            val = fabs(val - target) < fabs(root->val - target) ? val : root->val;
            root = root->right;
        } else {
            return root->val;
        }
    }
    return val;
}
